import re
import shlex
import subprocess
from dataclasses import dataclass
from os import PathLike
from pathlib import Path
from typing import NoReturn, Self

from github import Auth, Github, UnknownObjectException
from github.Repository import Repository
from github.Tag import Tag
from rich import get_console, print, reconfigure
from rich.markup import escape as e

REPOS_FILE = Path(__file__).with_name("repos.yaml")


type Arg = str | bytes | PathLike[str] | PathLike[bytes]


def run(*args: Arg, cwd: Path | None = None) -> None:
    print(f"[bright_black]$ {e(' '.join(shlex.quote(str(arg)) for arg in args))}[/]")
    subprocess.run(args, check=True, cwd=cwd)


def run_stdout(*args: Arg, cwd: Path | None = None) -> str:
    print(f"[bright_black]$ {e(' '.join(shlex.quote(str(arg)) for arg in args))}[/]")
    return subprocess.run(
        args,
        check=True,
        stdout=subprocess.PIPE,
        text=True,
        cwd=cwd,
    ).stdout


def prompt(message: str, options: str = "Yn") -> str:
    default: str | None = None
    for c in options:
        if c.isupper():
            default = c.lower()
            break

    options = options.lower()
    options_display = "/".join(c.upper() if c == default else c for c in options)

    console = get_console()
    while True:
        response = (
            console.input(f"{message} [cyan]\\[{options_display}]:[/] ").strip().lower()
        )
        if not response and default:
            return default
        elif response in options.lower():
            return response
        else:
            print(f"Please enter {options_display}.")


@dataclass
class Version:
    major: int
    minor: int
    patch: int
    rc: int | None

    @classmethod
    def parse(cls, s: str) -> Self:
        m = re.fullmatch(r"v(\d+)\.(\d+)\.(\d+)(-rc(\d+))?", s)
        if m is None:
            raise ValueError(f"Invalid version string: {s!r}")
        return cls(
            major=int(m.group(1)),
            minor=int(m.group(2)),
            patch=int(m.group(3)),
            rc=int(m.group(5)) if m.group(4) else None,
        )

    @property
    def tag(self) -> str:
        main = f"v{self.major}.{self.minor}.{self.patch}"
        rc = "" if self.rc is None else f"-rc{self.rc}"
        return main + rc

    @property
    def base(self) -> Self:
        return Version(major=self.major, minor=self.minor, patch=0, rc=None)

    @property
    def next(self) -> Self:
        return Version(major=self.major, minor=self.minor + 1, patch=0, rc=None)

    @property
    def is_stable(self) -> bool:
        return self.rc is None

    def __str__(self) -> str:
        return self.tag


class Checklist:
    def __init__(self) -> None:
        self.failed = False

    def section(self, *message: str) -> None:
        print()
        print(f"[bold]{''.join(message)}[/]")

    def success(self, *message: str) -> None:
        print(f"[b green]\\[Y][/] {''.join(message)}")

    def warn(self, *message: str) -> None:
        print(f"[b yellow]\\[W][/] {''.join(message)}")

    def wait(self, *message: str) -> None:
        print(f"[b yellow]\\[B][/] {''.join(message)}")
        self.failed = True

    def blocked(self, *message: str) -> NoReturn:
        print(f"[b yellow]\\[B][/] {''.join(message)}")
        raise SystemExit(1)

    def fail(self, *message: str) -> None:
        print(f"[b red]\\[N][/] {''.join(message)}")
        self.failed = True

    def fatal(self, *message: str) -> NoReturn:
        print(f"[b red]\\[N][/] {''.join(message)}")
        raise SystemExit(1)

    def ensure_success(self) -> None:
        if self.failed:
            raise SystemExit(1)


def initialize_rich() -> None:
    reconfigure(highlight=False)


def get_github_instance() -> Github:
    try:
        token = run_stdout("gh", "auth", "token").strip()
        print("Using GitHub token from `gh auth token`")
        return Github(auth=Auth.Token(token))
    except Exception:
        Checklist().fatal("Failed to get GitHub token from `gh auth token`")


def get_bump_branch_name(version: Version) -> str:
    return f"bump_to_{version}"


def get_bump_toolchain_commit_message(version: Version) -> str:
    return f"chore: bump toolchain to {version}"


def get_toolchain_for_version(version: Version) -> str:
    return f"leanprover/lean4:{version.tag}"


def get_blocking_labels(version: Version) -> list[str]:
    return [f"backport releases/{version.base}", f"blocks-release-{version.base}"]


def get_file_contents(cl: Checklist, repo: Repository, ref: str, path: str) -> str:
    try:
        file = repo.get_contents(path, ref=ref)
    except UnknownObjectException:
        cl.fatal(
            f"Failed to read [b]{e(path)}[/b] from [b]{e(ref)}[/b] in [b]{e(repo.full_name)}[/b]"
        )
    if isinstance(file, list):
        cl.fatal(
            f"Failed to read [b]{e(path)}[/b] from [b]{e(ref)}[/b] in [b]{e(repo.full_name)}[/b]"
        )
    return file.decoded_content.decode("utf-8")


def get_toolchain(cl: Checklist, repo: Repository, ref: str) -> str:
    return get_file_contents(cl, repo, ref, "lean-toolchain").strip()


# Returns (tag, next) where `tag` is the latest release tag with the expected
# toolchain, and `next` is the next patch version after the latest release.
def get_proofwidgets_release_for(
    cl: Checklist,
    repo: Repository,
    version: Version,
) -> tuple[Tag | None, str]:
    expected_toolchain = get_toolchain_for_version(version)
    latest_patch: int | None = None
    for tag in repo.get_tags().get_page(0):
        if not (match := re.fullmatch(r"v0\.0\.(\d+)", tag.name)):
            continue

        patch = int(match.group(1))
        if latest_patch is None or patch > latest_patch:
            latest_patch = patch

        toolchain = get_file_contents(cl, repo, tag.commit.sha, "lean-toolchain")
        if toolchain.strip() == expected_toolchain:
            return tag, f"v0.0.{latest_patch + 1}"

    if latest_patch is None:
        cl.fatal("No releases found in tags")

    return None, f"v0.0.{latest_patch + 1}"
