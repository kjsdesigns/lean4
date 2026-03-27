import re
from pathlib import Path

import click
import repos
from github import Github

from util import (
    Version,
    get_bump_branch_name,
    get_bump_toolchain_commit_message,
    get_github_instance,
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

    def clone(self, repo: str) -> Path:
        if repo not in repos.BY_FULL_NAME:
            raise SystemExit(f"Unknown repo {repo}")

        # A "release" directory parallel to the lean4 directory
        path = Path(__file__).parent.parent.parent.parent / "release" / repo
        path = path.resolve()
        path = path.relative_to(Path().resolve(), walk_up=True)

        if path.exists():
            run("git", "diff", "--quiet", cwd=path)
            run("git", "clean", "-dfx", cwd=path)
            run("git", "fetch", "--all", "--prune", "--prune-tags", cwd=path)
        else:
            run("gh", "repo", "clone", repo, path)

        return path

    def bump_toolchain_deps(self, path: Path) -> None:
        lakefile = path / "lakefile.toml"

        text = lakefile.read_text()
        text = re.sub(
            r'rev = "v4\.[0-9]+(\.[0-9]+)?(-rc[0-9]+)?"',
            f'rev = "{self.version}"',
            text,
        )
        lakefile.write_text(text)

        run("lake", "update", cwd=path)

    def bump_toolchain_verso(self, path: Path) -> None:
        run("lake", "update", cwd=path)
        run("./update-subverso.sh", cwd=path)

    def bump_toolchain_reference_manual(self, path: Path) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def bump_toolchain_mathlib4(self, path: Path) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def bump_toolchain_cslib(self, path: Path) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def bump_toolchain_repl(self, path: Path) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def bump_toolchain_lean_fro_org(self, path: Path) -> None:
        if prompt("Special instructions executed?") == "n":
            raise SystemExit(1)

    def bump_toolchain_in_worktree(self, repo: str, path: Path) -> None:
        rrepo = repos.BY_FULL_NAME[repo]

        # Bump toolchain file
        toolchain_file = path / "lean-toolchain"
        toolchain = get_toolchain_for_version(self.version)
        toolchain_file.write_text(toolchain + "\n")

        # Special cases
        if repo == repos.VERSO.full_name:
            self.bump_toolchain_verso(path)
        elif repo == repos.REFERENCE_MANUAL.full_name:
            self.bump_toolchain_reference_manual(path)
        elif repo == repos.MATHLIB4.full_name:
            self.bump_toolchain_mathlib4(path)
        elif repo == repos.CSLIB.full_name:
            self.bump_toolchain_cslib(path)
        elif repo == repos.REPL.full_name:
            self.bump_toolchain_repl(path)
        elif repo == repos.LEAN_FRO_ORG.full_name:
            self.bump_toolchain_lean_fro_org(path)
        elif rrepo.dependencies:
            self.bump_toolchain_deps(path)

        message = get_bump_toolchain_commit_message(self.version)
        run("git", "add", ".", cwd=path)
        run("git", "commit", "-m", message, cwd=path)

    def create_release_pr(self, repo: str) -> int:
        path = self.clone(repo)
        rrepo = repos.BY_FULL_NAME[repo]

        branch = get_bump_branch_name(self.version)
        source = "origin"
        if rrepo.bump_branch and self.version.rc == 1:
            # If the repo has a bump branch, we should use its contents
            source = f"origin/bump/{self.version}"

        run("git", "checkout", "-B", branch, source, cwd=path)
        self.bump_toolchain_in_worktree(repo, path)
        if not prompt(f"Push branch {branch} to origin?") == "y":
            raise SystemExit(1)
        run("git", "push", "origin", branch, cwd=path)

        # Create PR on GitHub
        if not prompt(f"Create PR for branch {branch}?") == "y":
            raise SystemExit(1)
        grepo = self.github.get_repo(repo)
        pr = grepo.create_pull(
            title=get_bump_toolchain_commit_message(self.version),
            head=branch,
            base=grepo.default_branch,
        )
        return pr.number

    # Assumes the PR has been merged into master in some way
    # Assumes the commit message is predictable
    def find_release_commit_sha(self, path: Path) -> str:
        expected = get_bump_toolchain_commit_message(self.version)

        for line in run_stdout(
            "git",
            "log",
            "origin",
            "--pretty=format:%H %s",
            "--max-count=100",
            cwd=path,
        ).splitlines():
            sha, message = line.split(" ", 1)
            if message == expected or message.startswith(expected + " "):
                return sha

        raise SystemExit("Failed to find release commit in 100 latest commits")

    def create_release_tag(self, repo: str, tag: str | None = None) -> None:
        path = self.clone(repo)
        tag = tag or self.version.tag
        sha = self.find_release_commit_sha(path)
        run("git", "tag", "--force", tag, sha, cwd=path)
        if prompt(f"Push tag {tag} to origin?") == "y":
            run("git", "push", "origin", tag, cwd=path)

    def bump_stable_to_release_tag(self, repo: str) -> None:
        path = self.clone(repo)
        run("git", "switch", "stable", cwd=path)
        run("git", "reset", "--hard", "origin/stable", cwd=path)
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
def clone(version: Version, repo: str) -> None:
    init(version).clone(repo)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
def create_release_pr(version: Version, repo: str) -> None:
    init(version).create_release_pr(repo)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
@click.option("--tag", "-t", type=str)
def create_release_tag(version: Version, repo: str, tag: str | None = None) -> None:
    init(version).create_release_tag(repo, tag)


@all.command()
@click.argument("version", type=Version.parse)
@click.argument("repo", type=str)
def bump_stable_to_release_tag(version: Version, repo: str) -> None:
    init(version).bump_stable_to_release_tag(repo)


if __name__ == "__main__":
    all()
