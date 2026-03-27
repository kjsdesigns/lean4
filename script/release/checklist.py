from argparse import ArgumentParser, Namespace

import repos
from github import Github, UnknownObjectException
from github.Branch import Branch
from github.GitRef import GitRef
from github.PullRequest import PullRequest
from github.Repository import Repository
from repos import ReleaseRepo
from rich.markup import escape as e
from steps import Steps

from util import (
    Checklist,
    Version,
    get_blocking_labels,
    get_bump_branch_name,
    get_file_contents,
    get_github_instance,
    get_proofwidgets_release_for,
    initialize_rich,
    prompt,
    run,
)


class RepoChecker:
    def __init__(
        self,
        interactive: bool,
        version: Version,
        steps: Steps,
        completed: set[str],
        rrepo: ReleaseRepo,
        repo: Repository,
    ) -> None:
        self.interactive = interactive
        self.version = version
        self.steps = steps
        self.completed = completed
        self.rrepo = rrepo
        self.repo = repo

        self.cl = Checklist()

    def prompt(self, message: str) -> bool:
        if not self.interactive:
            return False
        return prompt(message) == "y"

    def check_dependencies_completed(self) -> None:
        for dep in self.rrepo.dependencies:
            if dep.full_name not in self.completed:
                self.cl.wait(
                    f"Awaiting completion of dependency [b]{e(dep.full_name)}[/b]"
                )
        self.cl.ensure_success()

    def check_repo_has_pr(self) -> PullRequest:
        base = self.repo.default_branch
        head = get_bump_branch_name(self.version)
        owner = self.rrepo.owner

        for pr in self.repo.get_pulls(
            state="all",
            head=f"{owner}:{head}",
            base=base,
            sort="created",
            direction="desc",
        ):
            self.cl.success(
                f"Found PR #{pr.number} [b u link={pr.html_url}]{e(pr.title)}[/]"
            )
            return pr

        if not self.prompt(f"No PR found from [b]{head}[/b] to [b]{base}[/b]. Create?"):
            self.cl.fatal(f"No PR found from [b]{e(head)}[/b] to [b]{e(base)}[/b]")

        number = self.steps.create_release_pr(self.rrepo.full_name)
        pr = self.repo.get_pull(number)
        self.cl.success(
            f"Created PR #{pr.number} [b u link={pr.html_url}]{e(pr.title)}[/]"
        )
        return pr

    def check_pr_is_merged(self, pr: PullRequest) -> None:
        if pr.merged:
            self.cl.success("PR is merged")
        elif pr.state == "closed":
            self.cl.success("PR is closed")
        else:
            self.cl.fatal("PR is not merged")
            return

        # Ideally, we clean up after ourselves
        try:
            pr.head.repo.get_git_ref(f"heads/{pr.head.ref}")
            self.cl.warn("PR branch has not been deleted")
        except UnknownObjectException:
            self.cl.success("PR branch has been deleted")

    def check_toolchain_tag_exists(self) -> GitRef | None:
        if not self.rrepo.toolchain_tag:
            return

        try:
            tag = self.repo.get_git_ref(f"tags/{self.version}")
            self.cl.success(f"Toolchain tag [b]{self.version}[/b] exists")
            return tag
        except UnknownObjectException:
            pass

        if not self.prompt(
            f"Toolchain tag [b]{self.version}[/b] does not exist. Create?"
        ):
            self.cl.fatal(f"Toolchain tag [b]{self.version}[/b] does not exist")
            return

        self.steps.create_release_tag(self.rrepo.full_name)
        self.cl.success(f"Toolchain tag [b]{self.version}[/b] created")
        return self.repo.get_git_ref(f"tags/{self.version}")

    def check_stable_branch_points_to_toolchain_tag(self, tag: GitRef | None) -> None:
        if not tag:
            return
        if not self.rrepo.stable_branch:
            return
        if not self.version.is_stable:
            return

        branch = self.repo.get_branch("stable")
        if branch.commit.sha == tag.object.sha:
            self.cl.success("Stable branch points to toolchain tag")
            return

        if not self.prompt("Stable branch does not point to toolchain tag. Update?"):
            self.cl.fatal("Stable branch does not point to toolchain tag")
            return

        self.steps.bump_stable_to_release_tag(self.rrepo.full_name)
        self.cl.success("Stable branch updated to point to toolchain tag")

    def check_next_bump_branch(self) -> None:
        if not self.rrepo.bump_branch:
            return

        repo = self.repo
        if self.rrepo.nightly:
            repo = self.steps.github.get_repo(self.rrepo.nightly)

        branch_name = f"bump/{self.version.next}"
        try:
            repo.get_branch(branch_name)
            self.cl.success(f"Bump branch [b]{e(branch_name)}[/b] exists")
        except UnknownObjectException:
            self.cl.fail(f"Bump branch [b]{e(branch_name)}[/b] does not exist")

    def check_proofwidgets_release(self) -> None:
        if self.rrepo.full_name != repos.PROOFWIDGETS4.full_name:
            return

        tag, next_release_tag = get_proofwidgets_release_for(
            self.cl, self.repo, self.version
        )

        if tag:
            self.cl.success(
                f"Found tag [b]{e(tag.name)}[/b] with toolchain {self.version}"
            )
            return

        if not self.prompt(
            f"No tag found with toolchain [b]{self.version}[/b]. Create [b]{next_release_tag}[/b]?"
        ):
            self.cl.fatal(f"No tag found with toolchain [b]{self.version}[/b]")

        self.steps.create_release_tag(self.rrepo.full_name, next_release_tag)
        self.repo.get_git_ref(f"tags/{next_release_tag}")
        self.cl.success(
            f"Created tag [b]{e(next_release_tag)}[/b] with toolchain {self.version}"
        )

    def check_mathlib4_version_tags(self) -> None:
        if self.rrepo.full_name != repos.MATHLIB4.full_name:
            return

        path = self.steps.clone(self.rrepo.full_name)
        script = path / "scripts" / "verify_version_tags.py"
        script = script.resolve()
        try:
            run("python", script, self.version.tag, cwd=path)
            self.cl.success(f"Version tags verified by [b]{e(script.name)}[/b]")
        except Exception:
            self.cl.fatal(f"Version tag verification by [b]{e(script.name)}[/b] failed")

    def check(self) -> None:
        self.check_dependencies_completed()

        pr = self.check_repo_has_pr()
        self.check_pr_is_merged(pr)

        tag = self.check_toolchain_tag_exists()
        self.check_stable_branch_points_to_toolchain_tag(tag)

        # TODO Think about using bump branch for rc1 PRs
        self.check_next_bump_branch()

        self.check_proofwidgets_release()
        self.check_mathlib4_version_tags()
        # TODO Check that reference manual has section for our release?

        self.cl.ensure_success()


class Checker:
    def __init__(
        self,
        interactive: bool,
        version: Version,
        steps: Steps,
    ) -> None:
        self.interactive = interactive
        self.version = version
        self.steps = steps

        self.cl = Checklist()
        self.lean4 = self.github.get_repo("leanprover/lean4")

    @property
    def github(self) -> Github:
        return self.steps.github

    def check_release_branch_exists(self, version: Version) -> Branch:
        branch_name = f"releases/{version.base}"

        try:
            branch = self.lean4.get_branch(branch_name)
            self.cl.success(f"Release branch [b]{e(branch_name)}[/] exists")
            return branch
        except UnknownObjectException:
            self.cl.fatal(f"Release branch [b]{e(branch_name)}[/] does not exist")

    def check_release_branch_exists_nonfatal(self, version: Version) -> None:
        branch_name = f"releases/{version.base}"

        try:
            self.lean4.get_branch(branch_name)
            self.cl.success(f"Release branch [b]{e(branch_name)}[/] exists")
        except UnknownObjectException:
            self.cl.fail(f"Release branch [b]{e(branch_name)}[/] does not exist")

    def check_blocking_labels_exist(self, version: Version) -> None:
        success = True
        for label in get_blocking_labels(version):
            try:
                self.lean4.get_label(label)
            except UnknownObjectException:
                self.cl.fail(f"Label [b]{e(label)}[/] does not exist")
                success = False
        if success:
            self.cl.success("Blocking labels exist")

    def check_cmake_version(self, branch: Branch) -> None:
        path = "src/CMakeLists.txt"
        contents = get_file_contents(self.cl, self.lean4, branch.name, path)
        lines = {line.strip() for line in contents.splitlines()}

        success = True
        for expected in [
            f"set(LEAN_VERSION_MAJOR {self.version.major})",
            f"set(LEAN_VERSION_MINOR {self.version.minor})",
            f"set(LEAN_VERSION_PATCH {self.version.patch})",
            "set(LEAN_VERSION_IS_RELEASE 1)",
        ]:
            if any(line.startswith(expected) for line in lines):
                continue
            self.cl.fatal(f"[b]{e(path)}[/b] must contain line [b]{e(expected)}[/b]")
            success = False

        if success:
            self.cl.success(
                f"CMake version settings on [b]{e(branch.name)}[/b] are correct"
            )

    def check_tag_exists(self) -> GitRef:
        try:
            ref = self.lean4.get_git_ref(f"tags/{self.version}")
            self.cl.success(f"Tag [b]{self.version}[/b] exists")
            return ref
        except UnknownObjectException:
            self.cl.fatal(f"Tag [b]{self.version}[/b] does not exist")

    def check_release_ci(self, release_tag: GitRef) -> None:
        runs = self.lean4.get_workflow_runs(
            event="push",
            head_sha=release_tag.object.sha,
        )
        runs = list(runs)
        if len(runs) == 0:
            self.cl.fatal("No release workflow runs found")

        run = runs[0]

        if not run.conclusion:
            self.cl.blocked(
                f"[b u link={run.html_url}]Release workflow run {run.id}[/] is still running"
            )

        if run.conclusion != "success":
            self.cl.fatal(
                f"[b u link={run.html_url}]Release workflow run {run.id}[/] failed"
            )

        self.cl.success(
            f"[b u link={run.html_url}]Release workflow run {run.id}[/] finished"
        )

    def check_release_page(self) -> None:
        try:
            self.lean4.get_release(self.version.tag)
            self.cl.success(f"Release page for [b]{self.version.tag}[/b] exists")
        except UnknownObjectException:
            self.cl.blocked(
                f"Release page for [b]{self.version.tag}[/b] does not exist"
            )

    def check(self) -> None:
        self.cl.section("Prepare release cycle")
        release_branch = self.check_release_branch_exists(self.version)
        self.check_blocking_labels_exist(self.version)
        self.cl.ensure_success()

        self.cl.section("Release")
        self.check_cmake_version(release_branch)
        release_tag = self.check_tag_exists()
        self.check_release_ci(release_tag)
        self.check_release_page()
        self.cl.ensure_success()

        completed: set[str] = set()
        for rrepo in repos.ALL:
            self.cl.section(f"[u link={rrepo.url}]{e(rrepo.full_name)}[/u link]")
            repo = self.github.get_repo(rrepo.full_name)
            try:
                RepoChecker(
                    interactive=self.interactive,
                    version=self.version,
                    steps=self.steps,
                    completed=completed,
                    rrepo=rrepo,
                    repo=repo,
                ).check()
                completed.add(rrepo.full_name)
            except SystemExit:
                self.cl.failed = True
        self.cl.ensure_success()

        # TODO master should have updated cmake versions - where to check? Here?
        # TODO Move these checks to "Prepare release cycle" or something? These things should maybe be available while the current release is still ongoing.
        # self.cl.section("Prepare next release cycle")
        # self.check_release_branch_exists_nonfatal(self.version.next)
        # self.check_blocking_labels_exist(self.version.next)
        # self.cl.ensure_success()


def main(version: Version, interactive: bool) -> None:
    initialize_rich()
    github = get_github_instance()
    steps = Steps(version=version, github=github)
    Checker(interactive=interactive, version=version, steps=steps).check()


class Args(Namespace):
    version: Version
    interactive: bool


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("version", type=Version.parse)
    parser.add_argument("--interactive", "-i", action="store_true")
    args = parser.parse_args(namespace=Args())
    main(version=args.version, interactive=args.interactive)
