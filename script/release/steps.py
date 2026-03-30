import re
from pathlib import Path

import click
import repos
from github import Github
from repos import ReleaseRepo

from util import (
    Version,
    get_bump_branch_name,
    get_bump_toolchain_commit_message,
    get_github_instance,
    get_proofwidgets_release_for,
    get_toolchain_for_version,
    initialize_rich,
    prompt,
    run,
    run_stdout,
)


class Steps:
    def __init__(self, version: Version, github: Github) -> None:
        self.version = version
        self.github = github

    def path(self, repo: ReleaseRepo) -> Path:
        return Path(__file__).parent.parent.parent.parent / "release" / repo.name

    def _ensure_cloned(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)

        if path.exists():
            return

        run("gh", "repo", "clone", repo.full_name, path)

    def _ensure_remotes(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)

        target = {"origin": f"git@github.com:{repo.full_name}.git"}
        if repo.nightly:
            target["nightly"] = f"git@github.com:{repo.nightly}.git"

        actual = {
            line.strip() for line in run_stdout("git", "remote", cwd=path).splitlines()
        }

        for remote in actual:
            if remote not in target:
                run("git", "remote", "remove", remote, cwd=path)

        for remote, url in target.items():
            if remote not in actual:
                run("git", "remote", "add", remote, url, cwd=path)
            else:
                run("git", "remote", "set-url", remote, url, cwd=path)

    def _ensure_ready(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)

        # There should be no staged but uncommitted changes
        run("git", "diff", "--quiet", cwd=path)

        # There should be no stray files lying around
        run("git", "clean", "-dfx", cwd=path)

        # The remote tracking branches should be up-to-date
        run("git", "fetch", "--all", "--prune", "--prune-tags", cwd=path)
        run("git", "fetch", "--all", "--prune", cwd=path)

    def ensure_repo(self, repo: ReleaseRepo) -> None:
        self._ensure_cloned(repo)
        self._ensure_remotes(repo)
        self._ensure_ready(repo)

    def _get_default_branch(self, repo: ReleaseRepo) -> str:
        path = self.path(repo)
        ref = run_stdout("git", "rev-parse", "--abbrev-ref", "origin/HEAD", cwd=path)
        return ref.strip().split("/", 1)[1]

    def ensure_branch(
        self,
        repo: ReleaseRepo,
        remote: str = "origin",
        branch: str | None = None,
    ) -> str:
        path = self.path(repo)

        if branch is None:
            branch = self._get_default_branch(repo)

        run("git", "switch", "-C", branch, f"{remote}/{branch}", cwd=path)
        return branch

    def _bump_toolchain_deps(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)

        lakefile = path / "lakefile.toml"
        if not lakefile.exists():
            lakefile = path / "lakefile.lean"

        text = lakefile.read_text()
        text = re.sub(
            r'rev = "v4\.[0-9]+(\.[0-9]+)?(-rc[0-9]+)?"',
            f'rev = "{self.version}"',
            text,
        )
        lakefile.write_text(text)

        run("lake", "update", cwd=path)

    def _bump_toolchain_mathlib4(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)
        lakefile = path / "lakefile.lean"

        pw = self.github.get_repo(repos.PROOFWIDGETS4.full_name)
        tag = get_proofwidgets_release_for(pw, self.version)
        if not tag:
            raise SystemExit(1)

        text = lakefile.read_text()
        text = re.sub(
            r'"proofwidgets" @ git "v0\.0\.\d+"',
            f'"proofwidgets" @ git "{tag.name}"',
            text,
        )
        lakefile.write_text(text)

        self._bump_toolchain_deps(repo)

    def _bump_toolchain_cslib(self, repo: ReleaseRepo) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def _bump_toolchain_repl(self, repo: ReleaseRepo) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def _bump_toolchain_verso(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)
        run("lake", "update", cwd=path)
        run("./update-subverso.sh", cwd=path)

    def _bump_toolchain_reference_manual(self, repo: ReleaseRepo) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def _bump_toolchain_lean_fro_org(self, repo: ReleaseRepo) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def _bump_toolchain_in_worktree(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)

        # Bump toolchain file
        toolchain_file = path / "lean-toolchain"
        toolchain = get_toolchain_for_version(self.version)
        toolchain_file.write_text(toolchain + "\n")

        # Special cases
        if repo.full_name == repos.MATHLIB4.full_name:
            self._bump_toolchain_mathlib4(repo)
        elif repo.full_name == repos.CSLIB.full_name:
            self._bump_toolchain_cslib(repo)
        elif repo.full_name == repos.REPL.full_name:
            self._bump_toolchain_repl(repo)
        elif repo.full_name == repos.VERSO.full_name:
            self._bump_toolchain_verso(repo)
        elif repo.full_name == repos.REFERENCE_MANUAL.full_name:
            self._bump_toolchain_reference_manual(repo)
        elif repo.full_name == repos.LEAN_FRO_ORG.full_name:
            self._bump_toolchain_lean_fro_org(repo)
        elif repo.dependencies:
            self._bump_toolchain_deps(repo)

        message = get_bump_toolchain_commit_message(self.version)
        run("git", "add", ".", cwd=path)
        run("git", "commit", "-m", message, cwd=path)

    def create_release_pr(self, repo: ReleaseRepo) -> int:
        path = self.path(repo)
        self.ensure_repo(repo)

        branch = get_bump_branch_name(self.version)

        # The remote name is expanded to the default branch by git
        source = "origin"
        if repo.bump_branch and self.version.rc == 1:
            # If the repo has a bump branch, we should use its contents instead
            source_remote = "nightly" if repo.nightly else "origin"
            source = f"{source_remote}/bump/{self.version}"

        run("git", "checkout", "-B", branch, source, cwd=path)
        self._bump_toolchain_in_worktree(repo)
        if not prompt(f"Push branch {branch} to origin?") == "y":
            raise SystemExit(1)
        run("git", "push", "origin", branch, cwd=path)

        # Create PR on GitHub
        if not prompt(f"Create PR for branch {branch}?") == "y":
            raise SystemExit(1)
        grepo = self.github.get_repo(repo.full_name)
        pr = grepo.create_pull(
            title=get_bump_toolchain_commit_message(self.version),
            head=branch,
            base=grepo.default_branch,
        )
        return pr.number

    # Assumes the PR has been merged into master in some way
    # Assumes the commit message is predictable
    def _find_release_commit_sha(self, repo: ReleaseRepo) -> str:
        path = self.path(repo)
        expected = get_bump_toolchain_commit_message(self.version)

        for line in run_stdout(
            *("git", "log", "origin"),
            "--pretty=format:%H %s",
            "--max-count=100",
            cwd=path,
        ).splitlines():
            sha, message = line.split(" ", 1)
            if message == expected or message.startswith(expected + " "):
                return sha

        raise SystemExit("Failed to find release commit in 100 latest commits")

    def create_release_tag(self, repo: ReleaseRepo, tag: str | None = None) -> None:
        path = self.path(repo)
        self.ensure_repo(repo)

        tag = tag or self.version.tag
        sha = self._find_release_commit_sha(repo)

        run("git", "tag", "--force", tag, sha, cwd=path)
        if prompt(f"Push tag {tag} to origin?") == "y":
            run("git", "push", "origin", tag, cwd=path)

    def bump_stable_to_release_tag(self, repo: ReleaseRepo) -> None:
        path = self.path(repo)
        self.ensure_repo(repo)
        self.ensure_branch(repo, branch="stable")

        run("git", "merge", "--ff-only", self.version.tag, cwd=path)
        if prompt("Push branch stable to origin?") == "y":
            run("git", "push", "origin", "stable", cwd=path)


def init(version: Version) -> Steps:
    initialize_rich()
    github = get_github_instance()
    return Steps(version=version, github=github)


@click.group()
def all() -> None:
    pass


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
def clone(version: Version, repo: str) -> None:
    rrepo = ReleaseRepo.by_full_name(repo)
    init(version).ensure_repo(rrepo)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
def create_release_pr(version: Version, repo: str) -> None:
    rrepo = ReleaseRepo.by_full_name(repo)
    init(version).create_release_pr(rrepo)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
@click.option("--tag", "-t", type=str)
def create_release_tag(version: Version, repo: str, tag: str | None = None) -> None:
    rrepo = ReleaseRepo.by_full_name(repo)
    init(version).create_release_tag(rrepo, tag)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
def bump_stable_to_release_tag(version: Version, repo: str) -> None:
    rrepo = ReleaseRepo.by_full_name(repo)
    init(version).bump_stable_to_release_tag(rrepo)


if __name__ == "__main__":
    all()
