-- Tests that `normalizeInstance` auxiliary definitions work correctly
-- when used inside a `meta` section, for both `inferInstanceAs` and `deriving`.

module

meta section

def Foo := List Nat

instance : EmptyCollection Foo := inferInstanceAs (EmptyCollection (List Nat))

def Bar := Unit
deriving Inhabited

end
