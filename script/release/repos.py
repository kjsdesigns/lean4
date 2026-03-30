from dataclasses import dataclass, field
from typing import Self

ALL: list["ReleaseRepo"] = []
BY_FULL_NAME: dict[str, "ReleaseRepo"] = {}


@dataclass
class ReleaseRepo:
    owner: str
    name: str
    nightly: str | None = None
    dependencies: list[Self] = field(default_factory=list)
    toolchain_tag: bool = False
    stable_branch: bool = False
    bump_branch: bool = False

    @property
    def full_name(self) -> str:
        return f"{self.owner}/{self.name}"

    @property
    def url(self) -> str:
        return f"https://github.com/{self.full_name}"

    def _register(self) -> Self:
        ALL.append(self)
        BY_FULL_NAME[self.full_name] = self
        return self

    @classmethod
    def by_full_name(cls, full_name: str) -> Self:
        if full_name not in BY_FULL_NAME:
            raise SystemExit(f"Unknown repo {full_name}")
        return BY_FULL_NAME[full_name]


##################
## Repositories ##
##################

BATTERIES = ReleaseRepo(
    owner="leanprover-community",
    name="batteries",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
)._register()

AESOP = ReleaseRepo(
    owner="leanprover-community",
    name="aesop",
    toolchain_tag=True,
    stable_branch=True,
    dependencies=[
        BATTERIES,
    ],
)._register()

LEAN4_CLI = ReleaseRepo(
    owner="leanprover",
    name="lean4-cli",
    toolchain_tag=True,
)._register()

IMPORT_GRAPH = ReleaseRepo(
    owner="leanprover-community",
    name="import-graph",
    toolchain_tag=True,
    dependencies=[
        LEAN4_CLI,
    ],
)._register()

PLAUSIBLE = ReleaseRepo(
    owner="leanprover-community",
    name="plausible",
    toolchain_tag=True,
)._register()

PROOFWIDGETS4 = ReleaseRepo(
    owner="leanprover-community",
    name="ProofWidgets4",
)._register()

MATHLIB4 = ReleaseRepo(
    owner="leanprover-community",
    name="mathlib4",
    nightly="leanprover-community/mathlib4-nightly-testing",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
    dependencies=[
        AESOP,
        BATTERIES,
        IMPORT_GRAPH,
        LEAN4_CLI,
        PLAUSIBLE,
        PROOFWIDGETS4,
    ],
)._register()

CSLIB = ReleaseRepo(
    owner="leanprover",
    name="cslib",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
    dependencies=[
        MATHLIB4,
    ],
)._register()

REPL = ReleaseRepo(
    owner="leanprover-community",
    name="repl",
    toolchain_tag=True,
    stable_branch=True,
    dependencies=[
        MATHLIB4,
    ],
)._register()

VERSO = ReleaseRepo(
    owner="leanprover",
    name="verso",
    toolchain_tag=True,
    dependencies=[
        MATHLIB4,  # Benchmarks
        PLAUSIBLE,
    ],
)._register()

REFERENCE_MANUAL = ReleaseRepo(
    owner="leanprover",
    name="reference-manual",
    toolchain_tag=True,
    dependencies=[
        VERSO,
    ],
)._register()

VERSO_WEB_COMPONENTS = ReleaseRepo(
    owner="leanprover",
    name="verso-web-components",
    toolchain_tag=True,
    dependencies=[
        VERSO,
    ],
)._register()

LEAN_FRO_ORG = ReleaseRepo(
    owner="leanprover",
    name="lean-fro.org",
    dependencies=[
        VERSO_WEB_COMPONENTS,
    ],
)._register()

LEAN4_UNICODE_BASIC = ReleaseRepo(
    owner="fgdorais",
    name="lean4-unicode-basic",
    toolchain_tag=True,
)._register()

BIBTEX_QUERY = ReleaseRepo(
    owner="dupuisf",
    name="BibtexQuery",
    toolchain_tag=True,
    dependencies=[
        LEAN4_UNICODE_BASIC,
    ],
)._register()

DOC_GEN4 = ReleaseRepo(
    owner="leanprover",
    name="doc-gen4",
    toolchain_tag=True,
    dependencies=[
        BIBTEX_QUERY,
        LEAN4_CLI,
        MATHLIB4,
    ],
)._register()

COMPARATOR = ReleaseRepo(
    owner="leanprover",
    name="comparator",
    toolchain_tag=True,
)._register()

LEAN4EXPORT = ReleaseRepo(
    owner="leanprover",
    name="lean4export",
    toolchain_tag=True,
)._register()

QUOTE4 = ReleaseRepo(
    owner="leanprover-community",
    name="quote4",
    toolchain_tag=True,
    stable_branch=True,
)._register()


###################
## Visualization ##
###################

def print_graphviz_dot() -> None:
    print("digraph G {")
    print("  rankdir=LR;")
    for repo in sorted(ALL, key=lambda r: r.full_name):
        print(f'  "{repo.full_name}"')
        for dep in repo.dependencies:
            print(f'  "{dep.full_name}" -> "{repo.full_name}"')
    print("}")


if __name__ == "__main__":
    print_graphviz_dot()
