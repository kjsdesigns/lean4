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


LEAN4_CLI = ReleaseRepo(
    owner="leanprover",
    name="lean4-cli",
    toolchain_tag=True,
)._register()

BATTERIES = ReleaseRepo(
    owner="leanprover-community",
    name="batteries",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
)._register()

QUOTE4 = ReleaseRepo(
    owner="leanprover-community",
    name="quote4",
    toolchain_tag=True,
    stable_branch=True,
)._register()

PLAUSIBLE = ReleaseRepo(
    owner="leanprover-community",
    name="plausible",
    toolchain_tag=True,
)._register()

VERSO = ReleaseRepo(
    owner="leanprover",
    name="verso",
    toolchain_tag=True,
    dependencies=[PLAUSIBLE],
)._register()

IMPORT_GRAPH = ReleaseRepo(
    owner="leanprover-community",
    name="import-graph",
    toolchain_tag=True,
    dependencies=[LEAN4_CLI],
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
    dependencies=[LEAN4_UNICODE_BASIC],
)._register()

REFERENCE_MANUAL = ReleaseRepo(
    owner="leanprover",
    name="reference-manual",
    toolchain_tag=True,
    dependencies=[VERSO],
)._register()

PROOFWIDGETS4 = ReleaseRepo(
    owner="leanprover-community",
    name="ProofWidgets4",
)._register()

AESOP = ReleaseRepo(
    owner="leanprover-community",
    name="aesop",
    toolchain_tag=True,
    stable_branch=True,
    dependencies=[BATTERIES],
)._register()

MATHLIB4 = ReleaseRepo(
    owner="leanprover-community",
    name="mathlib4",
    nightly="leanprover-community/mathlib4-nightly-testing",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
    dependencies=[PROOFWIDGETS4, AESOP, BATTERIES, IMPORT_GRAPH, PLAUSIBLE, LEAN4_CLI],
)._register()

DOC_GEN4 = ReleaseRepo(
    owner="leanprover",
    name="doc-gen4",
    toolchain_tag=True,
    dependencies=[BIBTEX_QUERY, MATHLIB4, LEAN4_CLI],
)._register()

CSLIB = ReleaseRepo(
    owner="leanprover",
    name="cslib",
    toolchain_tag=True,
    stable_branch=True,
    bump_branch=True,
    dependencies=[MATHLIB4],
)._register()

REPL = ReleaseRepo(
    owner="leanprover-community",
    name="repl",
    toolchain_tag=True,
    stable_branch=True,
    dependencies=[MATHLIB4],
)._register()

VERSO_WEB_COMPONENTS = ReleaseRepo(
    owner="leanprover",
    name="verso-web-components",
    toolchain_tag=True,
    dependencies=[VERSO],
)._register()

LEAN_FRO_ORG = ReleaseRepo(
    owner="leanprover",
    name="lean-fro.org",
    dependencies=[VERSO_WEB_COMPONENTS],
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
