import datetime
from argparse import ArgumentParser, Namespace

import repos
from github import Github, UnknownObjectException
from github.Branch import Branch
from github.GitRef import GitRef
from github.GitRelease import GitRelease
from github.PullRequest import PullRequest
from github.Repository import Repository
from repos import ReleaseRepo
from rich.markup import escape as e
from steps import Steps

from util import (
    Checklist,
    Version,
    get_backport_label,
    get_blocking_label,
    get_bump_branch_name,
    get_file_contents,
    get_github_instance,
    get_next_proofwidgets_release,
    get_proofwidgets_release_for,
    get_refman_release_notes_path,
    get_refman_release_notes_title,
    get_release_branch_name,
    get_toolchain,
    get_toolchain_for_version,
    initialize_rich,
    prompt,
    run,
)


class RepoChecker:
    def __init__(
        self,
        interactive: bool,
        fast: bool,
        version: Version,
        steps: Steps,
        completed: set[str],
        rrepo: ReleaseRepo,
        grepo: Repository,
    ) -> None:
        self.interactive = interactive
        self.fast = fast
        self.version = version
        self.steps = steps
        self.completed = completed
        self.rrepo = rrepo
        self.grepo = grepo

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

    def check_repo_has_correct_toolchain(self) -> bool:
        expected = get_toolchain_for_version(self.version)
        actual = get_toolchain(self.grepo, self.grepo.default_branch)

        if actual == expected:
            self.cl.success(f"Repo uses toolchain [b]{expected}[/b]")
            return True
        else:
            self.cl.fail(f"Repo uses toolchain [b]{actual}[/b]")
            return False

    def check_repo_has_bump_pr(self, fatal: bool = True) -> PullRequest | None:
        base = self.grepo.default_branch
        head = get_bump_branch_name(self.version)
        owner = self.rrepo.owner

        for pr in self.grepo.get_pulls(
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

        if not fatal:
            self.cl.success(f"No PR found from [b]{e(head)}[/b] to [b]{e(base)}[/b]")
            return

        if not self.prompt(f"No PR found from [b]{head}[/b] to [b]{base}[/b]. Create?"):
            self.cl.fatal(f"No PR found from [b]{e(head)}[/b] to [b]{e(base)}[/b]")

        number = self.steps.create_release_pr(self.rrepo)
        pr = self.grepo.get_pull(number)
        self.cl.success(
            f"Created PR #{pr.number} [b u link={pr.html_url}]{e(pr.title)}[/]"
        )
        return pr

    def check_bump_pr_is_merged(self, pr: PullRequest) -> None:
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
            tag = self.grepo.get_git_ref(f"tags/{self.version}")
            self.cl.success(f"Toolchain tag [b]{self.version}[/b] exists")
            return tag
        except UnknownObjectException:
            pass

        if not self.prompt(
            f"Toolchain tag [b]{self.version}[/b] does not exist. Create?"
        ):
            self.cl.fatal(f"Toolchain tag [b]{self.version}[/b] does not exist")
            return

        self.steps.create_release_tag(self.rrepo)
        self.cl.success(f"Toolchain tag [b]{self.version}[/b] created")
        return self.grepo.get_git_ref(f"tags/{self.version}")

    def check_stable_branch_points_to_toolchain_tag(self, tag: GitRef) -> None:
        if not self.rrepo.stable_branch:
            return
        if not self.version.is_stable:
            return

        branch = self.grepo.get_branch("stable")
        if branch.commit.sha == tag.object.sha:
            self.cl.success("Stable branch points to toolchain tag")
            return

        if not self.prompt("Stable branch does not point to toolchain tag. Update?"):
            self.cl.fatal("Stable branch does not point to toolchain tag")
            return

        self.steps.bump_stable_to_release_tag(self.rrepo)
        self.cl.success("Stable branch updated to point to toolchain tag")

    def check_next_bump_branch(self) -> None:
        if not self.rrepo.bump_branch:
            return

        repo = self.grepo
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

        tag = get_proofwidgets_release_for(self.grepo, self.version)
        if tag:
            self.cl.success(
                f"Found tag [b]{e(tag.name)}[/b] with toolchain {self.version}"
            )
            return

        next_release_tag = get_next_proofwidgets_release(self.grepo)
        if not self.prompt(
            f"No tag found with toolchain [b]{self.version}[/b]. Create [b]{next_release_tag}[/b]?"
        ):
            self.cl.fatal(f"No tag found with toolchain [b]{self.version}[/b]")

        self.steps.create_release_tag(self.rrepo, next_release_tag)
        self.grepo.get_git_ref(f"tags/{next_release_tag}")
        self.cl.success(
            f"Created tag [b]{e(next_release_tag)}[/b] with toolchain {self.version}"
        )

    def check_mathlib4_version_tags(self) -> None:
        if self.rrepo.full_name != repos.MATHLIB4.full_name:
            return
        if self.fast:
            return

        path = self.steps.path(self.rrepo)
        self.steps.ensure_repo(self.rrepo)
        self.steps.ensure_branch(self.rrepo)  # At this point, the PR has been merged

        script = path / "scripts" / "verify_version_tags.py"
        script = script.resolve()
        try:
            run("python", script, self.version.tag, cwd=path)
            self.cl.success(f"Version tags verified by [b]{e(script.name)}[/b]")
        except Exception:
            self.cl.fatal(f"Version tag verification by [b]{e(script.name)}[/b] failed")

    def check(self) -> None:
        self.check_dependencies_completed()

        has_toolchain = self.check_repo_has_correct_toolchain()

        # Special cases for repos outside the usual github organizations
        if not has_toolchain:
            if self.rrepo.full_name == repos.LEAN4_UNICODE_BASIC.full_name:
                self.cl.fatal("Repo must be updated manually")

        pr = self.check_repo_has_bump_pr(fatal=not has_toolchain)
        if pr:
            self.check_bump_pr_is_merged(pr)

        tag = self.check_toolchain_tag_exists()
        if tag:
            self.check_stable_branch_points_to_toolchain_tag(tag)

        # TODO Think about using bump branch for rc1 PRs
        self.check_next_bump_branch()

        self.check_proofwidgets_release()
        self.check_mathlib4_version_tags()

        self.cl.ensure_success()


class Checker:
    def __init__(
        self,
        interactive: bool,
        fast: bool,
        version: Version,
        steps: Steps,
    ) -> None:
        self.interactive = interactive
        self.fast = fast
        self.version = version
        self.steps = steps

        self.cl = Checklist()
        self.lean4 = self.github.get_repo("leanprover/lean4")

    @property
    def github(self) -> Github:
        return self.steps.github

    def check_release_branch_exists(self, version: Version) -> Branch | None:
        branch_name = get_release_branch_name(version)

        try:
            branch = self.lean4.get_branch(branch_name)
            self.cl.success(f"Release branch [b]{e(branch_name)}[/] exists")
            return branch
        except UnknownObjectException:
            self.cl.fail(f"Release branch [b]{e(branch_name)}[/] does not exist")

    def check_label_exists(self, label: str) -> None:
        try:
            self.lean4.get_label(label)
            self.cl.success(f"Label [b]{e(label)}[/b] exists")
        except UnknownObjectException:
            self.cl.fail(f"Label [b]{e(label)}[/] does not exist")

    def check_cmake_version(
        self,
        version: Version,
        branch: str,
        release: bool = True,
    ) -> None:
        path = "src/CMakeLists.txt"
        contents = get_file_contents(self.lean4, branch, path)
        lines = {line.strip() for line in contents.splitlines()}

        expected = {
            "LEAN_VERSION_MAJOR": version.major,
            "LEAN_VERSION_MINOR": version.minor,
            "LEAN_VERSION_PATCH": version.patch,
            "LEAN_VERSION_IS_RELEASE": int(release),
        }

        success = True
        for name, value in expected.items():
            prefixes = [f"set({name} {value})", f"set({name} {value} CACHE"]
            if any(line.startswith(prefix) for line in lines for prefix in prefixes):
                continue
            self.cl.fail(
                f"On [b]{e(branch)}[/b], [b]{e(name)}[/b] must be set to [b]{value}[/b]"
            )
            success = False

        if success:
            self.cl.success(f"CMake version settings on [b]{e(branch)}[/b] are correct")

    def check_no_open_issues_labeled(self, label: str) -> None:
        success = True
        for issue in self.lean4.get_issues(state="open", labels=[label]):
            kind = "PR" if issue.pull_request else "issue"
            self.cl.fail(
                f"Found {kind} #{issue.number} [b u link={issue.html_url}]{e(issue.title)}[/] labeled [b]{e(label)}[/b]"
            )
            success = False

        if success:
            self.cl.success(f"No open issues labeled [b]{e(label)}[/b] found")

    def check_no_open_backport_prs(self) -> None:
        release_branch = get_release_branch_name(self.version)

        success = True
        for pr in self.lean4.get_pulls(state="open", base=release_branch):
            if "backport" in pr.title.lower():
                self.cl.fail(
                    f"Found backport PR #{pr.number} [b u link={pr.html_url}]{e(pr.title)}[/]"
                )
                success = False

        if success:
            self.cl.success("No open backport PRs found")

    def check_tag_exists(self) -> GitRef | None:
        try:
            ref = self.lean4.get_git_ref(f"tags/{self.version}")
            self.cl.success(f"Tag [b]{self.version}[/b] exists")
            return ref
        except UnknownObjectException:
            self.cl.fail(f"Tag [b]{self.version}[/b] does not exist")

    def check_release_ci(self, release_tag: GitRef) -> None:
        runs = self.lean4.get_workflow_runs(
            event="push",
            head_sha=release_tag.object.sha,
        )
        runs = list(runs)
        if len(runs) == 0:
            self.cl.fail("No release workflow runs found")

        run = runs[0]

        if not run.conclusion:
            self.cl.blocked(
                f"[b u link={run.html_url}]Release workflow run {run.id}[/] is still running"
            )

        if run.conclusion != "success":
            self.cl.fail(
                f"[b u link={run.html_url}]Release workflow run {run.id}[/] failed"
            )

        self.cl.success(
            f"[b u link={run.html_url}]Release workflow run {run.id}[/] finished"
        )

    def check_release_page(self) -> GitRelease | None:
        try:
            release = self.lean4.get_release(self.version.tag)
            self.cl.success(f"Release page for [b]{self.version.tag}[/b] exists")
            return release
        except UnknownObjectException:
            self.cl.blocked(
                f"Release page for [b]{self.version.tag}[/b] does not exist"
            )

    def check_reference_manual_title(self, release: GitRelease) -> None:
        repo = self.github.get_repo(repos.REFERENCE_MANUAL.full_name)

        file = get_refman_release_notes_path(self.version)
        try:
            text = get_file_contents(repo, repo.default_branch, file)
        except SystemExit:
            self.cl.fail(f"Refman has no release log at [b]{e(file)}[/b]")
            return

        title = get_refman_release_notes_title(self.version, release.created_at)
        title_line = f'#doc (Manual) "{title}" =>'
        for line in text.splitlines():
            if line.strip() == title_line:
                self.cl.success(f"Release log has title [b]{e(title)}[/b]")
                return

        self.cl.fail(f"Release log does not have title [b]{e(title)}[/b]")

    def check(self) -> None:
        self.cl.section("Prepare release cycle")
        self.check_label_exists(get_backport_label(self.version))
        self.check_label_exists(get_blocking_label(self.version))
        self.check_label_exists(get_blocking_label(self.version.next))
        release_branch = self.check_release_branch_exists(self.version)
        if release_branch:
            self.check_cmake_version(self.version, release_branch.name)
        self.check_cmake_version(
            self.version.next,
            self.lean4.default_branch,
            release=False,
        )

        self.cl.section("Release")
        self.check_no_open_issues_labeled(get_backport_label(self.version))
        self.check_no_open_issues_labeled(get_blocking_label(self.version))
        self.check_no_open_backport_prs()
        release_tag = self.check_tag_exists()
        if release_tag:
            self.check_release_ci(release_tag)
        release = self.check_release_page()
        if release:
            self.check_reference_manual_title(release)

        completed: set[str] = set()
        for rrepo in repos.ALL:
            self.cl.section(f"[u link={rrepo.url}]{e(rrepo.full_name)}[/u link]")
            grepo = self.github.get_repo(rrepo.full_name)
            try:
                RepoChecker(
                    interactive=self.interactive,
                    fast=self.fast,
                    version=self.version,
                    steps=self.steps,
                    completed=completed,
                    rrepo=rrepo,
                    grepo=grepo,
                ).check()
                completed.add(rrepo.full_name)
            except SystemExit:
                self.cl.failed = True

        self.cl.ensure_success()


def main(version: Version, interactive: bool = False, fast: bool = False) -> None:
    initialize_rich()
    github = get_github_instance()
    steps = Steps(version=version, github=github)
    Checker(interactive=interactive, fast=fast, version=version, steps=steps).check()


class Args(Namespace):
    version: Version
    interactive: bool


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("version", type=Version.parse)
    parser.add_argument("--interactive", "-i", action="store_true")
    parser.add_argument("--fast", "-f", action="store_true")
    args = parser.parse_args(namespace=Args())
    main(version=args.version, interactive=args.interactive, fast=args.fast)
