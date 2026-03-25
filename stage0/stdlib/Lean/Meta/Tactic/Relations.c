// Lean compiler output
// Module: Lean.Meta.Tactic.Relations
// Imports: public import Lean.Meta.WHNF public import Lean.Meta.CollectFVars
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_Lean_Name_str___override(lean_object*, lean_object*);
lean_object* l_Lean_Name_num___override(lean_object*, lean_object*);
lean_object* l_Lean_stringToMessageData(lean_object*);
lean_object* l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_object*, lean_object*);
uint8_t l_Lean_Name_isAnonymous(lean_object*);
lean_object* l_Lean_Environment_setExporting(lean_object*, uint8_t);
uint8_t l_Lean_Environment_contains(lean_object*, lean_object*, uint8_t);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
extern lean_object* l_Lean_Options_empty;
lean_object* l_Lean_MessageData_ofConstName(lean_object*, uint8_t);
lean_object* l_Lean_Environment_getModuleIdxFor_x3f(lean_object*, lean_object*);
lean_object* l_Lean_MessageData_note(lean_object*);
lean_object* l_Lean_Environment_header(lean_object*);
lean_object* l_Lean_EnvironmentHeader_moduleNames(lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_isPrivateName(lean_object*);
lean_object* l_Lean_MessageData_ofName(lean_object*);
extern lean_object* l_Lean_unknownIdentifierMessageTag;
lean_object* l_Lean_replaceRef(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_registerTraceClass(lean_object*, uint8_t, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* l_Lean_Expr_fvarId_x21(lean_object*);
uint8_t l___private_Lean_Data_Name_0__Lean_Name_quickCmpImpl(lean_object*, lean_object*);
lean_object* l_Lean_addBuiltinDocString(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
size_t lean_usize_of_nat(lean_object*);
uint8_t lean_usize_dec_eq(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Std_DTreeMap_Internal_Impl_insert___at___00Lean_NameMap_insert_spec__0___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_getAppNumArgs(lean_object*);
lean_object* l_Lean_Expr_getAppPrefix(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Lean_Expr_getRevArg_x21(lean_object*, lean_object*);
uint64_t l___private_Lean_Meta_Basic_0__Lean_Meta_Config_toKey(lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* l_Lean_registerSimpleScopedEnvExtension___redArg(lean_object*);
lean_object* l_Lean_ScopedEnvExtension_getState___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getArgs(lean_object*);
lean_object* l_Lean_Environment_findConstVal_x3f(lean_object*, lean_object*, uint8_t);
lean_object* l_Array_toSubarray___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* l_Lean_Name_append(lean_object*, lean_object*);
uint8_t l___private_Lean_Util_Trace_0__Lean_checkTraceOption_go(lean_object*, lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* l_Lean_MessageData_ofFormat(lean_object*);
lean_object* lean_st_ref_take(lean_object*);
double lean_float_of_nat(lean_object*);
lean_object* l_Lean_PersistentArray_push___redArg(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
extern lean_object* l_Lean_instInhabitedExpr;
lean_object* lean_array_get_borrowed(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_collectFVars(lean_object*, lean_object*);
lean_object* l_Lean_CollectFVars_State_addDependencies(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_mkPanicMessageWithDecl(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_instInhabitedMetaM___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_panic_fn(lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
lean_object* l_Lean_FVarId_getUserName___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_FVarId_getBinderInfo___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_isNatLit_x3f(lean_object*);
lean_object* l_Lean_Syntax_getId(lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
uint8_t lean_name_eq(lean_object*, lean_object*);
lean_object* l_Array_zipIdx___redArg(lean_object*, lean_object*);
uint8_t l_Lean_BinderInfo_isExplicit(uint8_t);
lean_object* l_Lean_inlineExpr(lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasFVar(lean_object*);
uint8_t l_Lean_Expr_hasMVar(lean_object*);
lean_object* l___private_Lean_MetavarContext_0__Lean_DependsOn_dep_visit(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_forallTelescopeReducingImp(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l___private_Lean_Meta_Basic_0__Lean_Meta_withLocalContextImp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_ScopedEnvExtension_addCore___redArg(lean_object*, lean_object*, lean_object*, uint8_t, lean_object*);
lean_object* l_Lean_ScopedEnvExtension_add___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
lean_object* l_Lean_Meta_saveState___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Meta_SavedState_restore___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_getAppFn(lean_object*);
lean_object* l_Lean_Meta_whnfCore(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Exception_isInterrupt(lean_object*);
uint8_t l_Lean_Exception_isRuntime(lean_object*);
lean_object* l_Lean_registerBuiltinAttribute(lean_object*);
static const lean_ctor_object l_Lean_Meta_instInhabitedRelationInfo_default___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*4 + 0, .m_other = 4, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_Lean_Meta_instInhabitedRelationInfo_default___closed__0 = (const lean_object*)&l_Lean_Meta_instInhabitedRelationInfo_default___closed__0_value;
LEAN_EXPORT const lean_object* l_Lean_Meta_instInhabitedRelationInfo_default = (const lean_object*)&l_Lean_Meta_instInhabitedRelationInfo_default___closed__0_value;
LEAN_EXPORT const lean_object* l_Lean_Meta_instInhabitedRelationInfo = (const lean_object*)&l_Lean_Meta_instInhabitedRelationInfo_default___closed__0_value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object*);
static const lean_closure_object l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_closure_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_closure_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_string_object l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Lean"};
static const lean_object* l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_string_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Meta"};
static const lean_object* l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_string_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "relationExt"};
static const lean_object* l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(194, 50, 106, 158, 41, 60, 103, 214)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(81, 84, 61, 109, 49, 211, 55, 10)}};
static const lean_object* l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*5 + 0, .m_other = 5, .m_tag = 0}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value)}};
static const lean_object* l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_ = (const lean_object*)&l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_relationExt;
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_instInhabitedMetaM___lam__0___boxed, .m_arity = 5, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___closed__0 = (const lean_object*)&l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___closed__0_value;
LEAN_EXPORT lean_object* l_panic___at___00Lean_Meta_inferRelationInfo_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "trace"};
static const lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__0 = (const lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__0_value;
static const lean_ctor_object l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__0_value),LEAN_SCALAR_PTR_LITERAL(212, 145, 141, 177, 67, 149, 127, 197)}};
static const lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__1 = (const lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Lean_Meta_inferRelationInfo___lam__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__0___boxed(lean_object*);
LEAN_EXPORT uint8_t l_Lean_Meta_inferRelationInfo___lam__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__1___boxed(lean_object*);
LEAN_EXPORT lean_object* l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15(lean_object*, size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0;
static const lean_string_object l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__1 = (const lean_object*)&l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__1_value;
static const lean_array_object l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__2 = (const lean_object*)&l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__2_value;
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10(lean_object*, lean_object*, size_t, size_t);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8___boxed(lean_object*, lean_object*);
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Invalid argument index `"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__0 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__0_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "`: The argument at this index (`"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__2 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__2_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 45, .m_capacity = 45, .m_length = 44, .m_data = "`) has already been specified as an argument"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__4 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__4_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "`: `"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__6 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__6_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "` has only "};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__8 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__8_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = " arguments"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__10 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__10_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 57, .m_capacity = 57, .m_length = 56, .m_data = "Invalid argument index `0`: Index must be greater than 0"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__12 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__12_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "Invalid argument name `"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__14 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__14_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "`: It has already been specified as an argument"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__16 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__16_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17;
static const lean_string_object l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 43, .m_capacity = 43, .m_length = 42, .m_data = "` does not have an argument with this name"};
static const lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__18 = (const lean_object*)&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__18_value;
static lean_once_cell_t l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19;
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12(lean_object*, lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Tactic"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__0 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__0_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "relation"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__1 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__1_value;
static const lean_ctor_object l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(211, 174, 49, 251, 64, 24, 251, 1)}};
static const lean_ctor_object l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value_aux_0),((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__0_value),LEAN_SCALAR_PTR_LITERAL(194, 95, 140, 15, 16, 100, 236, 219)}};
static const lean_ctor_object l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value_aux_1),((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__1_value),LEAN_SCALAR_PTR_LITERAL(35, 247, 243, 126, 111, 177, 68, 145)}};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__2 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__2_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "Relation `"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__3 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__3_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__4;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "` has "};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__5 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__5_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__6;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = " arguments. The first "};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__7 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__7_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__8_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__8;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 74, .m_capacity = 74, .m_length = 73, .m_data = " argument(s) identify the relation. The lhs and rhs are argument numbers "};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__9 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__9_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__10;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = " and "};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__11 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__11_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__12;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "."};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__13 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__13_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__14_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__14;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__15;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "Lean.Meta.Tactic.Relations"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__16 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__16_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "Lean.Meta.inferRelationInfo"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__17 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__17_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 45, .m_capacity = 45, .m_length = 44, .m_data = "assertion violation: operands.size == 2\n    "};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__18 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__18_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__19;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 42, .m_capacity = 42, .m_length = 41, .m_data = "Invalid argument indices: They are both `"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__20 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__20_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__21_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__21;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "` but must be different"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__22 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__22_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__23;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "Invalid relation: `"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__24 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__24_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__25_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__25;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "` does not have at least two explicit arguments"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__26 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__26_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__27_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__27;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "Invalid relation: type `"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__28 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__28_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__29_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__29;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "` in `"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__30 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__30_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__31_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__31;
static const lean_string_object l_Lean_Meta_inferRelationInfo___lam__2___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "` depends on arguments"};
static const lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__32 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__32_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___lam__2___closed__33_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___lam__2___closed__33;
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "A private declaration `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__6 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__6_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 79, .m_capacity = 79, .m_length = 78, .m_data = "` (from the current module) exists but would need to be public to access here."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__8 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__8_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "A public declaration `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__10 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__10_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 68, .m_capacity = 68, .m_length = 67, .m_data = "` exists but is imported privately; consider adding `public import "};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__12 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__12_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "`."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__14 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__14_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "` (from `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__16 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__16_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 54, .m_capacity = 54, .m_length = 53, .m_data = "`) exists but would need to be public to access here."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__18 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__18_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19;
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Unknown constant `"};
static const lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__0 = (const lean_object*)&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__0_value;
static lean_once_cell_t l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1;
static const lean_string_object l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__2 = (const lean_object*)&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__2_value;
static lean_once_cell_t l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3;
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_Lean_Meta_inferRelationInfo___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_inferRelationInfo___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__0 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__0_value;
static const lean_closure_object l_Lean_Meta_inferRelationInfo___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Lean_Meta_inferRelationInfo___lam__1___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__1 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__1_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___closed__2;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___closed__3;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___closed__4;
static const lean_array_object l_Lean_Meta_inferRelationInfo___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__5 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__5_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "null"};
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__6 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__6_value;
static const lean_ctor_object l_Lean_Meta_inferRelationInfo___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_inferRelationInfo___closed__6_value),LEAN_SCALAR_PTR_LITERAL(24, 58, 49, 223, 146, 207, 197, 136)}};
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__7 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__7_value;
static const lean_string_object l_Lean_Meta_inferRelationInfo___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 58, .m_capacity = 58, .m_length = 57, .m_data = "Must have exactly two arguments if arguments are provided"};
static const lean_object* l_Lean_Meta_inferRelationInfo___closed__8 = (const lean_object*)&l_Lean_Meta_inferRelationInfo___closed__8_value;
static lean_once_cell_t l_Lean_Meta_inferRelationInfo___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_inferRelationInfo___closed__9;
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0;
static lean_once_cell_t l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1;
static lean_once_cell_t l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2;
static lean_once_cell_t l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3;
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 24, .m_other = 0, .m_tag = 0}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 1, 1, 0),LEAN_SCALAR_PTR_LITERAL(1, 1, 0, 1, 1, 1, 2, 1),LEAN_SCALAR_PTR_LITERAL(1, 1, 1, 0, 0, 0, 0, 0)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "The relation `"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 30, .m_capacity = 30, .m_length = 29, .m_data = "` has already been registered"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "Attribute `["};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "]` cannot be erased"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static lean_once_cell_t l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_;
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "_private"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(103, 214, 75, 80, 34, 198, 193, 153)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(90, 18, 126, 130, 18, 214, 172, 143)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(30, 196, 118, 96, 111, 225, 34, 188)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__0_value),LEAN_SCALAR_PTR_LITERAL(195, 68, 87, 56, 63, 220, 109, 253)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "Relations"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(243, 24, 59, 184, 157, 168, 36, 230)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_closure_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*2, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed, .m_arity = 8, .m_num_fixed = 2, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(1) << 1) | 1))} };
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)(((size_t)(0) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(94, 86, 186, 211, 75, 15, 36, 187)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(167, 252, 114, 119, 244, 13, 234, 7)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(119, 224, 121, 46, 147, 6, 180, 11)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "initFn"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(198, 98, 86, 207, 66, 82, 91, 75)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "_@"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(119, 217, 136, 52, 189, 77, 93, 122)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(10, 56, 27, 105, 166, 194, 141, 194)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(174, 164, 154, 200, 97, 103, 42, 82)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__0_value),LEAN_SCALAR_PTR_LITERAL(83, 14, 72, 182, 188, 186, 239, 99)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(195, 58, 68, 134, 130, 125, 74, 230)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)(((size_t)(907532441) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(231, 226, 188, 24, 194, 150, 42, 243)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "_hygCtx"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(140, 109, 189, 247, 205, 96, 227, 102)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "_hyg"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(184, 113, 190, 148, 143, 248, 22, 140)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__24_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)(((size_t)(2) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(185, 24, 102, 192, 41, 81, 37, 191)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__24_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__24_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__25_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_inferRelationInfo___lam__2___closed__1_value),LEAN_SCALAR_PTR_LITERAL(70, 193, 156, 252, 136, 32, 87, 94)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__25_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__25_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_closure_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__26_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__25_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value)} };
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__26_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__26_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__27_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "Registers a declaration as a relation."};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__27_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__27_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__28_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 8, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__24_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__25_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__27_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__28_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__28_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__29_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 0}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__28_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__26_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__29_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__29_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 276, .m_capacity = 276, .m_length = 275, .m_data = "Marks a definition to be a binary relation.\n\n`@[relation]` can take additional arguments for the parameter names or indices (starting at 1) of\nthe parameters that should be used as the left and right arguments.\nBy default, the last two explicit arguments are used, in order.\n"};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_Lean_Meta_matchesPotentialRelation_x3f___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_Lean_Meta_matchesPotentialRelation_x3f___closed__0 = (const lean_object*)&l_Lean_Meta_matchesPotentialRelation_x3f___closed__0_value;
LEAN_EXPORT lean_object* l_Lean_Meta_matchesPotentialRelation_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_matchesPotentialRelation_x3f___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),((lean_object*)(((size_t)(343174607) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(111, 47, 72, 170, 138, 41, 216, 60)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(100, 68, 152, 141, 217, 196, 152, 140)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(240, 116, 72, 96, 188, 160, 169, 130)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value),((lean_object*)(((size_t)(2) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(161, 137, 50, 118, 178, 23, 245, 4)}};
static const lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(lean_object* v_st_5_, lean_object* v_x_6_){
_start:
{
lean_object* v_fst_7_; lean_object* v_snd_8_; lean_object* v___x_9_; 
v_fst_7_ = lean_ctor_get(v_x_6_, 0);
lean_inc(v_fst_7_);
v_snd_8_ = lean_ctor_get(v_x_6_, 1);
lean_inc(v_snd_8_);
lean_dec_ref(v_x_6_);
v___x_9_ = l_Std_DTreeMap_Internal_Impl_insert___at___00Lean_NameMap_insert_spec__0___redArg(v_fst_7_, v_snd_8_, v_st_5_);
return v___x_9_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(uint8_t v_x_10_, lean_object* v___y_11_){
_start:
{
lean_object* v___x_12_; 
v___x_12_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_12_, 0, v___y_11_);
return v___x_12_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object* v_x_13_, lean_object* v___y_14_){
_start:
{
uint8_t v_x_53__boxed_15_; lean_object* v_res_16_; 
v_x_53__boxed_15_ = lean_unbox(v_x_13_);
v_res_16_ = l_Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(v_x_53__boxed_15_, v___y_14_);
return v_res_16_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(lean_object* v___y_17_){
_start:
{
lean_inc(v___y_17_);
return v___y_17_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object* v___y_18_){
_start:
{
lean_object* v_res_19_; 
v_res_19_ = l_Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(v___y_18_);
lean_dec(v___y_18_);
return v_res_19_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_37_ = ((lean_object*)(l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_));
v___x_38_ = l_Lean_registerSimpleScopedEnvExtension___redArg(v___x_37_);
return v___x_38_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2____boxed(lean_object* v_a_39_){
_start:
{
lean_object* v_res_40_; 
v_res_40_ = l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_();
return v_res_40_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0(lean_object* v___x_41_, lean_object* v_declName_42_, lean_object* v_toPure_43_, lean_object* v_____do__lift_44_){
_start:
{
lean_object* v___x_45_; lean_object* v_ext_46_; lean_object* v_toEnvExtension_47_; lean_object* v_asyncMode_48_; lean_object* v___x_49_; lean_object* v___x_50_; lean_object* v___x_51_; 
v___x_45_ = l_Lean_Meta_relationExt;
v_ext_46_ = lean_ctor_get(v___x_45_, 1);
lean_inc_ref(v_ext_46_);
v_toEnvExtension_47_ = lean_ctor_get(v_ext_46_, 0);
lean_inc_ref(v_toEnvExtension_47_);
lean_dec_ref(v_ext_46_);
v_asyncMode_48_ = lean_ctor_get(v_toEnvExtension_47_, 2);
lean_inc(v_asyncMode_48_);
lean_dec_ref(v_toEnvExtension_47_);
v___x_49_ = l_Lean_ScopedEnvExtension_getState___redArg(v___x_41_, v___x_45_, v_____do__lift_44_, v_asyncMode_48_);
lean_dec(v_asyncMode_48_);
v___x_50_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v___x_49_, v_declName_42_);
lean_dec(v___x_49_);
v___x_51_ = lean_apply_2(v_toPure_43_, lean_box(0), v___x_50_);
return v___x_51_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0___boxed(lean_object* v___x_52_, lean_object* v_declName_53_, lean_object* v_toPure_54_, lean_object* v_____do__lift_55_){
_start:
{
lean_object* v_res_56_; 
v_res_56_ = l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0(v___x_52_, v_declName_53_, v_toPure_54_, v_____do__lift_55_);
lean_dec(v_declName_53_);
return v_res_56_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___redArg(lean_object* v_inst_57_, lean_object* v_inst_58_, lean_object* v_declName_59_){
_start:
{
lean_object* v_toApplicative_60_; lean_object* v_toBind_61_; lean_object* v_getEnv_62_; lean_object* v_toPure_63_; lean_object* v___x_64_; lean_object* v___f_65_; lean_object* v___x_66_; 
v_toApplicative_60_ = lean_ctor_get(v_inst_57_, 0);
lean_inc_ref(v_toApplicative_60_);
v_toBind_61_ = lean_ctor_get(v_inst_57_, 1);
lean_inc(v_toBind_61_);
lean_dec_ref(v_inst_57_);
v_getEnv_62_ = lean_ctor_get(v_inst_58_, 0);
lean_inc(v_getEnv_62_);
lean_dec_ref(v_inst_58_);
v_toPure_63_ = lean_ctor_get(v_toApplicative_60_, 1);
lean_inc(v_toPure_63_);
lean_dec_ref(v_toApplicative_60_);
v___x_64_ = lean_box(1);
v___f_65_ = lean_alloc_closure((void*)(l_Lean_Meta_getRelationInfo_x3f___redArg___lam__0___boxed), 4, 3);
lean_closure_set(v___f_65_, 0, v___x_64_);
lean_closure_set(v___f_65_, 1, v_declName_59_);
lean_closure_set(v___f_65_, 2, v_toPure_63_);
v___x_66_ = lean_apply_4(v_toBind_61_, lean_box(0), lean_box(0), v_getEnv_62_, v___f_65_);
return v___x_66_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f(lean_object* v_m_67_, lean_object* v_inst_68_, lean_object* v_inst_69_, lean_object* v_declName_70_){
_start:
{
lean_object* v___x_71_; 
v___x_71_ = l_Lean_Meta_getRelationInfo_x3f___redArg(v_inst_68_, v_inst_69_, v_declName_70_);
return v___x_71_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___redArg(lean_object* v_inst_72_, lean_object* v_inst_73_, lean_object* v_inst_74_, lean_object* v_declName_75_, lean_object* v_info_76_, uint8_t v_kind_77_){
_start:
{
lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; 
v___x_78_ = l_Lean_Meta_relationExt;
v___x_79_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_79_, 0, v_declName_75_);
lean_ctor_set(v___x_79_, 1, v_info_76_);
v___x_80_ = l_Lean_ScopedEnvExtension_add___redArg(v_inst_72_, v_inst_73_, v_inst_74_, v___x_78_, v___x_79_, v_kind_77_);
return v___x_80_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___redArg___boxed(lean_object* v_inst_81_, lean_object* v_inst_82_, lean_object* v_inst_83_, lean_object* v_declName_84_, lean_object* v_info_85_, lean_object* v_kind_86_){
_start:
{
uint8_t v_kind_boxed_87_; lean_object* v_res_88_; 
v_kind_boxed_87_ = lean_unbox(v_kind_86_);
v_res_88_ = l_Lean_Meta_registerRelation___redArg(v_inst_81_, v_inst_82_, v_inst_83_, v_declName_84_, v_info_85_, v_kind_boxed_87_);
return v_res_88_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation(lean_object* v_m_89_, lean_object* v_inst_90_, lean_object* v_inst_91_, lean_object* v_inst_92_, lean_object* v_declName_93_, lean_object* v_info_94_, uint8_t v_kind_95_){
_start:
{
lean_object* v___x_96_; 
v___x_96_ = l_Lean_Meta_registerRelation___redArg(v_inst_90_, v_inst_91_, v_inst_92_, v_declName_93_, v_info_94_, v_kind_95_);
return v___x_96_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___boxed(lean_object* v_m_97_, lean_object* v_inst_98_, lean_object* v_inst_99_, lean_object* v_inst_100_, lean_object* v_declName_101_, lean_object* v_info_102_, lean_object* v_kind_103_){
_start:
{
uint8_t v_kind_boxed_104_; lean_object* v_res_105_; 
v_kind_boxed_104_ = lean_unbox(v_kind_103_);
v_res_105_ = l_Lean_Meta_registerRelation(v_m_97_, v_inst_98_, v_inst_99_, v_inst_100_, v_declName_101_, v_info_102_, v_kind_boxed_104_);
return v_res_105_;
}
}
LEAN_EXPORT lean_object* l_panic___at___00Lean_Meta_inferRelationInfo_spec__1(lean_object* v_msg_107_, lean_object* v___y_108_, lean_object* v___y_109_, lean_object* v___y_110_, lean_object* v___y_111_){
_start:
{
lean_object* v___f_113_; lean_object* v___x_13770__overap_114_; lean_object* v___x_115_; 
v___f_113_ = ((lean_object*)(l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___closed__0));
v___x_13770__overap_114_ = lean_panic_fn(v___f_113_, v_msg_107_);
lean_inc(v___y_111_);
lean_inc_ref(v___y_110_);
lean_inc(v___y_109_);
lean_inc_ref(v___y_108_);
v___x_115_ = lean_apply_5(v___x_13770__overap_114_, v___y_108_, v___y_109_, v___y_110_, v___y_111_, lean_box(0));
return v___x_115_;
}
}
LEAN_EXPORT lean_object* l_panic___at___00Lean_Meta_inferRelationInfo_spec__1___boxed(lean_object* v_msg_116_, lean_object* v___y_117_, lean_object* v___y_118_, lean_object* v___y_119_, lean_object* v___y_120_, lean_object* v___y_121_){
_start:
{
lean_object* v_res_122_; 
v_res_122_ = l_panic___at___00Lean_Meta_inferRelationInfo_spec__1(v_msg_116_, v___y_117_, v___y_118_, v___y_119_, v___y_120_);
lean_dec(v___y_120_);
lean_dec_ref(v___y_119_);
lean_dec(v___y_118_);
lean_dec_ref(v___y_117_);
return v_res_122_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg(lean_object* v_cls_126_, lean_object* v___y_127_){
_start:
{
lean_object* v_options_129_; uint8_t v_hasTrace_130_; 
v_options_129_ = lean_ctor_get(v___y_127_, 2);
v_hasTrace_130_ = lean_ctor_get_uint8(v_options_129_, sizeof(void*)*1);
if (v_hasTrace_130_ == 0)
{
lean_object* v___x_131_; lean_object* v___x_132_; 
lean_dec(v_cls_126_);
v___x_131_ = lean_box(v_hasTrace_130_);
v___x_132_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_132_, 0, v___x_131_);
return v___x_132_;
}
else
{
lean_object* v_inheritedTraceOptions_133_; lean_object* v___x_134_; lean_object* v___x_135_; uint8_t v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; 
v_inheritedTraceOptions_133_ = lean_ctor_get(v___y_127_, 13);
v___x_134_ = ((lean_object*)(l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___closed__1));
v___x_135_ = l_Lean_Name_append(v___x_134_, v_cls_126_);
v___x_136_ = l___private_Lean_Util_Trace_0__Lean_checkTraceOption_go(v_inheritedTraceOptions_133_, v_options_129_, v___x_135_);
lean_dec(v___x_135_);
v___x_137_ = lean_box(v___x_136_);
v___x_138_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_138_, 0, v___x_137_);
return v___x_138_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg___boxed(lean_object* v_cls_139_, lean_object* v___y_140_, lean_object* v___y_141_){
_start:
{
lean_object* v_res_142_; 
v_res_142_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg(v_cls_139_, v___y_140_);
lean_dec_ref(v___y_140_);
return v_res_142_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4(lean_object* v_cls_143_, lean_object* v___y_144_, lean_object* v___y_145_, lean_object* v___y_146_, lean_object* v___y_147_){
_start:
{
lean_object* v___x_149_; 
v___x_149_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg(v_cls_143_, v___y_146_);
return v___x_149_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___boxed(lean_object* v_cls_150_, lean_object* v___y_151_, lean_object* v___y_152_, lean_object* v___y_153_, lean_object* v___y_154_, lean_object* v___y_155_){
_start:
{
lean_object* v_res_156_; 
v_res_156_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4(v_cls_150_, v___y_151_, v___y_152_, v___y_153_, v___y_154_);
lean_dec(v___y_154_);
lean_dec_ref(v___y_153_);
lean_dec(v___y_152_);
lean_dec_ref(v___y_151_);
return v_res_156_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0(lean_object* v_k_157_, lean_object* v_b_158_, lean_object* v_c_159_, lean_object* v___y_160_, lean_object* v___y_161_, lean_object* v___y_162_, lean_object* v___y_163_){
_start:
{
lean_object* v___x_165_; 
lean_inc(v___y_163_);
lean_inc_ref(v___y_162_);
lean_inc(v___y_161_);
lean_inc_ref(v___y_160_);
v___x_165_ = lean_apply_7(v_k_157_, v_b_158_, v_c_159_, v___y_160_, v___y_161_, v___y_162_, v___y_163_, lean_box(0));
return v___x_165_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0___boxed(lean_object* v_k_166_, lean_object* v_b_167_, lean_object* v_c_168_, lean_object* v___y_169_, lean_object* v___y_170_, lean_object* v___y_171_, lean_object* v___y_172_, lean_object* v___y_173_){
_start:
{
lean_object* v_res_174_; 
v_res_174_ = l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0(v_k_166_, v_b_167_, v_c_168_, v___y_169_, v___y_170_, v___y_171_, v___y_172_);
lean_dec(v___y_172_);
lean_dec_ref(v___y_171_);
lean_dec(v___y_170_);
lean_dec_ref(v___y_169_);
return v_res_174_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg(lean_object* v_type_175_, lean_object* v_k_176_, uint8_t v_cleanupAnnotations_177_, uint8_t v_whnfType_178_, lean_object* v___y_179_, lean_object* v___y_180_, lean_object* v___y_181_, lean_object* v___y_182_){
_start:
{
lean_object* v___f_184_; lean_object* v___x_185_; 
v___f_184_ = lean_alloc_closure((void*)(l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___lam__0___boxed), 8, 1);
lean_closure_set(v___f_184_, 0, v_k_176_);
v___x_185_ = l___private_Lean_Meta_Basic_0__Lean_Meta_forallTelescopeReducingImp(lean_box(0), v_type_175_, v___f_184_, v_cleanupAnnotations_177_, v_whnfType_178_, v___y_179_, v___y_180_, v___y_181_, v___y_182_);
if (lean_obj_tag(v___x_185_) == 0)
{
lean_object* v_a_186_; lean_object* v___x_188_; uint8_t v_isShared_189_; uint8_t v_isSharedCheck_193_; 
v_a_186_ = lean_ctor_get(v___x_185_, 0);
v_isSharedCheck_193_ = !lean_is_exclusive(v___x_185_);
if (v_isSharedCheck_193_ == 0)
{
v___x_188_ = v___x_185_;
v_isShared_189_ = v_isSharedCheck_193_;
goto v_resetjp_187_;
}
else
{
lean_inc(v_a_186_);
lean_dec(v___x_185_);
v___x_188_ = lean_box(0);
v_isShared_189_ = v_isSharedCheck_193_;
goto v_resetjp_187_;
}
v_resetjp_187_:
{
lean_object* v___x_191_; 
if (v_isShared_189_ == 0)
{
v___x_191_ = v___x_188_;
goto v_reusejp_190_;
}
else
{
lean_object* v_reuseFailAlloc_192_; 
v_reuseFailAlloc_192_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_192_, 0, v_a_186_);
v___x_191_ = v_reuseFailAlloc_192_;
goto v_reusejp_190_;
}
v_reusejp_190_:
{
return v___x_191_;
}
}
}
else
{
lean_object* v_a_194_; lean_object* v___x_196_; uint8_t v_isShared_197_; uint8_t v_isSharedCheck_201_; 
v_a_194_ = lean_ctor_get(v___x_185_, 0);
v_isSharedCheck_201_ = !lean_is_exclusive(v___x_185_);
if (v_isSharedCheck_201_ == 0)
{
v___x_196_ = v___x_185_;
v_isShared_197_ = v_isSharedCheck_201_;
goto v_resetjp_195_;
}
else
{
lean_inc(v_a_194_);
lean_dec(v___x_185_);
v___x_196_ = lean_box(0);
v_isShared_197_ = v_isSharedCheck_201_;
goto v_resetjp_195_;
}
v_resetjp_195_:
{
lean_object* v___x_199_; 
if (v_isShared_197_ == 0)
{
v___x_199_ = v___x_196_;
goto v_reusejp_198_;
}
else
{
lean_object* v_reuseFailAlloc_200_; 
v_reuseFailAlloc_200_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_200_, 0, v_a_194_);
v___x_199_ = v_reuseFailAlloc_200_;
goto v_reusejp_198_;
}
v_reusejp_198_:
{
return v___x_199_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg___boxed(lean_object* v_type_202_, lean_object* v_k_203_, lean_object* v_cleanupAnnotations_204_, lean_object* v_whnfType_205_, lean_object* v___y_206_, lean_object* v___y_207_, lean_object* v___y_208_, lean_object* v___y_209_, lean_object* v___y_210_){
_start:
{
uint8_t v_cleanupAnnotations_boxed_211_; uint8_t v_whnfType_boxed_212_; lean_object* v_res_213_; 
v_cleanupAnnotations_boxed_211_ = lean_unbox(v_cleanupAnnotations_204_);
v_whnfType_boxed_212_ = lean_unbox(v_whnfType_205_);
v_res_213_ = l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg(v_type_202_, v_k_203_, v_cleanupAnnotations_boxed_211_, v_whnfType_boxed_212_, v___y_206_, v___y_207_, v___y_208_, v___y_209_);
lean_dec(v___y_209_);
lean_dec_ref(v___y_208_);
lean_dec(v___y_207_);
lean_dec_ref(v___y_206_);
return v_res_213_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16(lean_object* v_00_u03b1_214_, lean_object* v_type_215_, lean_object* v_k_216_, uint8_t v_cleanupAnnotations_217_, uint8_t v_whnfType_218_, lean_object* v___y_219_, lean_object* v___y_220_, lean_object* v___y_221_, lean_object* v___y_222_){
_start:
{
lean_object* v___x_224_; 
v___x_224_ = l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___redArg(v_type_215_, v_k_216_, v_cleanupAnnotations_217_, v_whnfType_218_, v___y_219_, v___y_220_, v___y_221_, v___y_222_);
return v___x_224_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___boxed(lean_object* v_00_u03b1_225_, lean_object* v_type_226_, lean_object* v_k_227_, lean_object* v_cleanupAnnotations_228_, lean_object* v_whnfType_229_, lean_object* v___y_230_, lean_object* v___y_231_, lean_object* v___y_232_, lean_object* v___y_233_, lean_object* v___y_234_){
_start:
{
uint8_t v_cleanupAnnotations_boxed_235_; uint8_t v_whnfType_boxed_236_; lean_object* v_res_237_; 
v_cleanupAnnotations_boxed_235_ = lean_unbox(v_cleanupAnnotations_228_);
v_whnfType_boxed_236_ = lean_unbox(v_whnfType_229_);
v_res_237_ = l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16(v_00_u03b1_225_, v_type_226_, v_k_227_, v_cleanupAnnotations_boxed_235_, v_whnfType_boxed_236_, v___y_230_, v___y_231_, v___y_232_, v___y_233_);
lean_dec(v___y_233_);
lean_dec_ref(v___y_232_);
lean_dec(v___y_231_);
lean_dec_ref(v___y_230_);
return v_res_237_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg(lean_object* v_lctx_238_, lean_object* v_localInsts_239_, lean_object* v_x_240_, lean_object* v___y_241_, lean_object* v___y_242_, lean_object* v___y_243_, lean_object* v___y_244_){
_start:
{
lean_object* v___x_246_; 
v___x_246_ = l___private_Lean_Meta_Basic_0__Lean_Meta_withLocalContextImp(lean_box(0), v_lctx_238_, v_localInsts_239_, v_x_240_, v___y_241_, v___y_242_, v___y_243_, v___y_244_);
if (lean_obj_tag(v___x_246_) == 0)
{
lean_object* v_a_247_; lean_object* v___x_249_; uint8_t v_isShared_250_; uint8_t v_isSharedCheck_254_; 
v_a_247_ = lean_ctor_get(v___x_246_, 0);
v_isSharedCheck_254_ = !lean_is_exclusive(v___x_246_);
if (v_isSharedCheck_254_ == 0)
{
v___x_249_ = v___x_246_;
v_isShared_250_ = v_isSharedCheck_254_;
goto v_resetjp_248_;
}
else
{
lean_inc(v_a_247_);
lean_dec(v___x_246_);
v___x_249_ = lean_box(0);
v_isShared_250_ = v_isSharedCheck_254_;
goto v_resetjp_248_;
}
v_resetjp_248_:
{
lean_object* v___x_252_; 
if (v_isShared_250_ == 0)
{
v___x_252_ = v___x_249_;
goto v_reusejp_251_;
}
else
{
lean_object* v_reuseFailAlloc_253_; 
v_reuseFailAlloc_253_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_253_, 0, v_a_247_);
v___x_252_ = v_reuseFailAlloc_253_;
goto v_reusejp_251_;
}
v_reusejp_251_:
{
return v___x_252_;
}
}
}
else
{
lean_object* v_a_255_; lean_object* v___x_257_; uint8_t v_isShared_258_; uint8_t v_isSharedCheck_262_; 
v_a_255_ = lean_ctor_get(v___x_246_, 0);
v_isSharedCheck_262_ = !lean_is_exclusive(v___x_246_);
if (v_isSharedCheck_262_ == 0)
{
v___x_257_ = v___x_246_;
v_isShared_258_ = v_isSharedCheck_262_;
goto v_resetjp_256_;
}
else
{
lean_inc(v_a_255_);
lean_dec(v___x_246_);
v___x_257_ = lean_box(0);
v_isShared_258_ = v_isSharedCheck_262_;
goto v_resetjp_256_;
}
v_resetjp_256_:
{
lean_object* v___x_260_; 
if (v_isShared_258_ == 0)
{
v___x_260_ = v___x_257_;
goto v_reusejp_259_;
}
else
{
lean_object* v_reuseFailAlloc_261_; 
v_reuseFailAlloc_261_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_261_, 0, v_a_255_);
v___x_260_ = v_reuseFailAlloc_261_;
goto v_reusejp_259_;
}
v_reusejp_259_:
{
return v___x_260_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg___boxed(lean_object* v_lctx_263_, lean_object* v_localInsts_264_, lean_object* v_x_265_, lean_object* v___y_266_, lean_object* v___y_267_, lean_object* v___y_268_, lean_object* v___y_269_, lean_object* v___y_270_){
_start:
{
lean_object* v_res_271_; 
v_res_271_ = l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg(v_lctx_263_, v_localInsts_264_, v_x_265_, v___y_266_, v___y_267_, v___y_268_, v___y_269_);
lean_dec(v___y_269_);
lean_dec_ref(v___y_268_);
lean_dec(v___y_267_);
lean_dec_ref(v___y_266_);
return v_res_271_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17(lean_object* v_00_u03b1_272_, lean_object* v_lctx_273_, lean_object* v_localInsts_274_, lean_object* v_x_275_, lean_object* v___y_276_, lean_object* v___y_277_, lean_object* v___y_278_, lean_object* v___y_279_){
_start:
{
lean_object* v___x_281_; 
v___x_281_ = l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg(v_lctx_273_, v_localInsts_274_, v_x_275_, v___y_276_, v___y_277_, v___y_278_, v___y_279_);
return v___x_281_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___boxed(lean_object* v_00_u03b1_282_, lean_object* v_lctx_283_, lean_object* v_localInsts_284_, lean_object* v_x_285_, lean_object* v___y_286_, lean_object* v___y_287_, lean_object* v___y_288_, lean_object* v___y_289_, lean_object* v___y_290_){
_start:
{
lean_object* v_res_291_; 
v_res_291_ = l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17(v_00_u03b1_282_, v_lctx_283_, v_localInsts_284_, v_x_285_, v___y_286_, v___y_287_, v___y_288_, v___y_289_);
lean_dec(v___y_289_);
lean_dec_ref(v___y_288_);
lean_dec(v___y_287_);
lean_dec_ref(v___y_286_);
return v_res_291_;
}
}
LEAN_EXPORT uint8_t l_Lean_Meta_inferRelationInfo___lam__0(lean_object* v_x_292_){
_start:
{
uint8_t v___x_293_; 
v___x_293_ = 1;
return v___x_293_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__0___boxed(lean_object* v_x_294_){
_start:
{
uint8_t v_res_295_; lean_object* v_r_296_; 
v_res_295_ = l_Lean_Meta_inferRelationInfo___lam__0(v_x_294_);
lean_dec(v_x_294_);
v_r_296_ = lean_box(v_res_295_);
return v_r_296_;
}
}
LEAN_EXPORT uint8_t l_Lean_Meta_inferRelationInfo___lam__1(lean_object* v_x_297_){
_start:
{
uint8_t v___x_298_; 
v___x_298_ = 0;
return v___x_298_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__1___boxed(lean_object* v_x_299_){
_start:
{
uint8_t v_res_300_; lean_object* v_r_301_; 
v_res_300_ = l_Lean_Meta_inferRelationInfo___lam__1(v_x_299_);
lean_dec(v_x_299_);
v_r_301_ = lean_box(v_res_300_);
return v_r_301_;
}
}
LEAN_EXPORT lean_object* l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13___redArg(lean_object* v_a_302_, lean_object* v_b_303_){
_start:
{
lean_object* v_array_304_; lean_object* v_start_305_; lean_object* v_stop_306_; lean_object* v___x_308_; uint8_t v_isShared_309_; uint8_t v_isSharedCheck_319_; 
v_array_304_ = lean_ctor_get(v_a_302_, 0);
v_start_305_ = lean_ctor_get(v_a_302_, 1);
v_stop_306_ = lean_ctor_get(v_a_302_, 2);
v_isSharedCheck_319_ = !lean_is_exclusive(v_a_302_);
if (v_isSharedCheck_319_ == 0)
{
v___x_308_ = v_a_302_;
v_isShared_309_ = v_isSharedCheck_319_;
goto v_resetjp_307_;
}
else
{
lean_inc(v_stop_306_);
lean_inc(v_start_305_);
lean_inc(v_array_304_);
lean_dec(v_a_302_);
v___x_308_ = lean_box(0);
v_isShared_309_ = v_isSharedCheck_319_;
goto v_resetjp_307_;
}
v_resetjp_307_:
{
uint8_t v___x_310_; 
v___x_310_ = lean_nat_dec_lt(v_start_305_, v_stop_306_);
if (v___x_310_ == 0)
{
lean_del_object(v___x_308_);
lean_dec(v_stop_306_);
lean_dec(v_start_305_);
lean_dec_ref(v_array_304_);
return v_b_303_;
}
else
{
lean_object* v___x_311_; lean_object* v___x_312_; lean_object* v___x_314_; 
v___x_311_ = lean_unsigned_to_nat(1u);
v___x_312_ = lean_nat_add(v_start_305_, v___x_311_);
lean_inc_ref(v_array_304_);
if (v_isShared_309_ == 0)
{
lean_ctor_set(v___x_308_, 1, v___x_312_);
v___x_314_ = v___x_308_;
goto v_reusejp_313_;
}
else
{
lean_object* v_reuseFailAlloc_318_; 
v_reuseFailAlloc_318_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_318_, 0, v_array_304_);
lean_ctor_set(v_reuseFailAlloc_318_, 1, v___x_312_);
lean_ctor_set(v_reuseFailAlloc_318_, 2, v_stop_306_);
v___x_314_ = v_reuseFailAlloc_318_;
goto v_reusejp_313_;
}
v_reusejp_313_:
{
lean_object* v___x_315_; lean_object* v___x_316_; 
v___x_315_ = lean_array_fget(v_array_304_, v_start_305_);
lean_dec(v_start_305_);
lean_dec_ref(v_array_304_);
v___x_316_ = lean_array_push(v_b_303_, v___x_315_);
v_a_302_ = v___x_314_;
v_b_303_ = v___x_316_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg(size_t v_sz_320_, size_t v_i_321_, lean_object* v_bs_322_, lean_object* v___y_323_, lean_object* v___y_324_, lean_object* v___y_325_){
_start:
{
uint8_t v___x_327_; 
v___x_327_ = lean_usize_dec_lt(v_i_321_, v_sz_320_);
if (v___x_327_ == 0)
{
lean_object* v___x_328_; 
v___x_328_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_328_, 0, v_bs_322_);
return v___x_328_;
}
else
{
lean_object* v_v_329_; lean_object* v___x_330_; lean_object* v___x_331_; 
v_v_329_ = lean_array_uget_borrowed(v_bs_322_, v_i_321_);
v___x_330_ = l_Lean_Expr_fvarId_x21(v_v_329_);
v___x_331_ = l_Lean_FVarId_getBinderInfo___redArg(v___x_330_, v___y_323_, v___y_324_, v___y_325_);
if (lean_obj_tag(v___x_331_) == 0)
{
lean_object* v_a_332_; lean_object* v___x_333_; lean_object* v_bs_x27_334_; size_t v___x_335_; size_t v___x_336_; lean_object* v___x_337_; 
v_a_332_ = lean_ctor_get(v___x_331_, 0);
lean_inc(v_a_332_);
lean_dec_ref(v___x_331_);
v___x_333_ = lean_unsigned_to_nat(0u);
v_bs_x27_334_ = lean_array_uset(v_bs_322_, v_i_321_, v___x_333_);
v___x_335_ = ((size_t)1ULL);
v___x_336_ = lean_usize_add(v_i_321_, v___x_335_);
v___x_337_ = lean_array_uset(v_bs_x27_334_, v_i_321_, v_a_332_);
v_i_321_ = v___x_336_;
v_bs_322_ = v___x_337_;
goto _start;
}
else
{
lean_object* v_a_339_; lean_object* v___x_341_; uint8_t v_isShared_342_; uint8_t v_isSharedCheck_346_; 
lean_dec_ref(v_bs_322_);
v_a_339_ = lean_ctor_get(v___x_331_, 0);
v_isSharedCheck_346_ = !lean_is_exclusive(v___x_331_);
if (v_isSharedCheck_346_ == 0)
{
v___x_341_ = v___x_331_;
v_isShared_342_ = v_isSharedCheck_346_;
goto v_resetjp_340_;
}
else
{
lean_inc(v_a_339_);
lean_dec(v___x_331_);
v___x_341_ = lean_box(0);
v_isShared_342_ = v_isSharedCheck_346_;
goto v_resetjp_340_;
}
v_resetjp_340_:
{
lean_object* v___x_344_; 
if (v_isShared_342_ == 0)
{
v___x_344_ = v___x_341_;
goto v_reusejp_343_;
}
else
{
lean_object* v_reuseFailAlloc_345_; 
v_reuseFailAlloc_345_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_345_, 0, v_a_339_);
v___x_344_ = v_reuseFailAlloc_345_;
goto v_reusejp_343_;
}
v_reusejp_343_:
{
return v___x_344_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg___boxed(lean_object* v_sz_347_, lean_object* v_i_348_, lean_object* v_bs_349_, lean_object* v___y_350_, lean_object* v___y_351_, lean_object* v___y_352_, lean_object* v___y_353_){
_start:
{
size_t v_sz_boxed_354_; size_t v_i_boxed_355_; lean_object* v_res_356_; 
v_sz_boxed_354_ = lean_unbox_usize(v_sz_347_);
lean_dec(v_sz_347_);
v_i_boxed_355_ = lean_unbox_usize(v_i_348_);
lean_dec(v_i_348_);
v_res_356_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg(v_sz_boxed_354_, v_i_boxed_355_, v_bs_349_, v___y_350_, v___y_351_, v___y_352_);
lean_dec(v___y_352_);
lean_dec_ref(v___y_351_);
lean_dec_ref(v___y_350_);
return v_res_356_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14(size_t v_sz_357_, size_t v_i_358_, lean_object* v_bs_359_){
_start:
{
uint8_t v___x_360_; 
v___x_360_ = lean_usize_dec_lt(v_i_358_, v_sz_357_);
if (v___x_360_ == 0)
{
return v_bs_359_;
}
else
{
lean_object* v_v_361_; lean_object* v_snd_362_; lean_object* v___x_363_; lean_object* v_bs_x27_364_; size_t v___x_365_; size_t v___x_366_; lean_object* v___x_367_; 
v_v_361_ = lean_array_uget_borrowed(v_bs_359_, v_i_358_);
v_snd_362_ = lean_ctor_get(v_v_361_, 1);
lean_inc(v_snd_362_);
v___x_363_ = lean_unsigned_to_nat(0u);
v_bs_x27_364_ = lean_array_uset(v_bs_359_, v_i_358_, v___x_363_);
v___x_365_ = ((size_t)1ULL);
v___x_366_ = lean_usize_add(v_i_358_, v___x_365_);
v___x_367_ = lean_array_uset(v_bs_x27_364_, v_i_358_, v_snd_362_);
v_i_358_ = v___x_366_;
v_bs_359_ = v___x_367_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14___boxed(lean_object* v_sz_369_, lean_object* v_i_370_, lean_object* v_bs_371_){
_start:
{
size_t v_sz_boxed_372_; size_t v_i_boxed_373_; lean_object* v_res_374_; 
v_sz_boxed_372_ = lean_unbox_usize(v_sz_369_);
lean_dec(v_sz_369_);
v_i_boxed_373_ = lean_unbox_usize(v_i_370_);
lean_dec(v_i_370_);
v_res_374_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14(v_sz_boxed_372_, v_i_boxed_373_, v_bs_371_);
return v_res_374_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg(size_t v_sz_375_, size_t v_i_376_, lean_object* v_bs_377_, lean_object* v___y_378_, lean_object* v___y_379_, lean_object* v___y_380_){
_start:
{
uint8_t v___x_382_; 
v___x_382_ = lean_usize_dec_lt(v_i_376_, v_sz_375_);
if (v___x_382_ == 0)
{
lean_object* v___x_383_; 
v___x_383_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_383_, 0, v_bs_377_);
return v___x_383_;
}
else
{
lean_object* v_v_384_; lean_object* v___x_385_; lean_object* v___x_386_; 
v_v_384_ = lean_array_uget_borrowed(v_bs_377_, v_i_376_);
v___x_385_ = l_Lean_Expr_fvarId_x21(v_v_384_);
v___x_386_ = l_Lean_FVarId_getUserName___redArg(v___x_385_, v___y_378_, v___y_379_, v___y_380_);
if (lean_obj_tag(v___x_386_) == 0)
{
lean_object* v_a_387_; lean_object* v___x_388_; lean_object* v_bs_x27_389_; size_t v___x_390_; size_t v___x_391_; lean_object* v___x_392_; 
v_a_387_ = lean_ctor_get(v___x_386_, 0);
lean_inc(v_a_387_);
lean_dec_ref(v___x_386_);
v___x_388_ = lean_unsigned_to_nat(0u);
v_bs_x27_389_ = lean_array_uset(v_bs_377_, v_i_376_, v___x_388_);
v___x_390_ = ((size_t)1ULL);
v___x_391_ = lean_usize_add(v_i_376_, v___x_390_);
v___x_392_ = lean_array_uset(v_bs_x27_389_, v_i_376_, v_a_387_);
v_i_376_ = v___x_391_;
v_bs_377_ = v___x_392_;
goto _start;
}
else
{
lean_object* v_a_394_; lean_object* v___x_396_; uint8_t v_isShared_397_; uint8_t v_isSharedCheck_401_; 
lean_dec_ref(v_bs_377_);
v_a_394_ = lean_ctor_get(v___x_386_, 0);
v_isSharedCheck_401_ = !lean_is_exclusive(v___x_386_);
if (v_isSharedCheck_401_ == 0)
{
v___x_396_ = v___x_386_;
v_isShared_397_ = v_isSharedCheck_401_;
goto v_resetjp_395_;
}
else
{
lean_inc(v_a_394_);
lean_dec(v___x_386_);
v___x_396_ = lean_box(0);
v_isShared_397_ = v_isSharedCheck_401_;
goto v_resetjp_395_;
}
v_resetjp_395_:
{
lean_object* v___x_399_; 
if (v_isShared_397_ == 0)
{
v___x_399_ = v___x_396_;
goto v_reusejp_398_;
}
else
{
lean_object* v_reuseFailAlloc_400_; 
v_reuseFailAlloc_400_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_400_, 0, v_a_394_);
v___x_399_ = v_reuseFailAlloc_400_;
goto v_reusejp_398_;
}
v_reusejp_398_:
{
return v___x_399_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg___boxed(lean_object* v_sz_402_, lean_object* v_i_403_, lean_object* v_bs_404_, lean_object* v___y_405_, lean_object* v___y_406_, lean_object* v___y_407_, lean_object* v___y_408_){
_start:
{
size_t v_sz_boxed_409_; size_t v_i_boxed_410_; lean_object* v_res_411_; 
v_sz_boxed_409_ = lean_unbox_usize(v_sz_402_);
lean_dec(v_sz_402_);
v_i_boxed_410_ = lean_unbox_usize(v_i_403_);
lean_dec(v_i_403_);
v_res_411_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg(v_sz_boxed_409_, v_i_boxed_410_, v_bs_404_, v___y_405_, v___y_406_, v___y_407_);
lean_dec(v___y_407_);
lean_dec_ref(v___y_406_);
lean_dec_ref(v___y_405_);
return v_res_411_;
}
}
LEAN_EXPORT uint8_t l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(lean_object* v_k_412_, lean_object* v_t_413_){
_start:
{
if (lean_obj_tag(v_t_413_) == 0)
{
lean_object* v_k_414_; lean_object* v_l_415_; lean_object* v_r_416_; uint8_t v___x_417_; 
v_k_414_ = lean_ctor_get(v_t_413_, 1);
v_l_415_ = lean_ctor_get(v_t_413_, 3);
v_r_416_ = lean_ctor_get(v_t_413_, 4);
v___x_417_ = l___private_Lean_Data_Name_0__Lean_Name_quickCmpImpl(v_k_412_, v_k_414_);
switch(v___x_417_)
{
case 0:
{
v_t_413_ = v_l_415_;
goto _start;
}
case 1:
{
uint8_t v___x_419_; 
v___x_419_ = 1;
return v___x_419_;
}
default: 
{
v_t_413_ = v_r_416_;
goto _start;
}
}
}
else
{
uint8_t v___x_421_; 
v___x_421_ = 0;
return v___x_421_;
}
}
}
LEAN_EXPORT lean_object* l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg___boxed(lean_object* v_k_422_, lean_object* v_t_423_){
_start:
{
uint8_t v_res_424_; lean_object* v_r_425_; 
v_res_424_ = l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(v_k_422_, v_t_423_);
lean_dec(v_t_423_);
lean_dec(v_k_422_);
v_r_425_ = lean_box(v_res_424_);
return v_r_425_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg(lean_object* v_a_426_, lean_object* v_a_427_, lean_object* v_a_428_, lean_object* v_b_429_){
_start:
{
lean_object* v_array_431_; lean_object* v_start_432_; lean_object* v_stop_433_; lean_object* v___x_435_; uint8_t v_isShared_436_; uint8_t v_isSharedCheck_455_; 
v_array_431_ = lean_ctor_get(v_a_428_, 0);
v_start_432_ = lean_ctor_get(v_a_428_, 1);
v_stop_433_ = lean_ctor_get(v_a_428_, 2);
v_isSharedCheck_455_ = !lean_is_exclusive(v_a_428_);
if (v_isSharedCheck_455_ == 0)
{
v___x_435_ = v_a_428_;
v_isShared_436_ = v_isSharedCheck_455_;
goto v_resetjp_434_;
}
else
{
lean_inc(v_stop_433_);
lean_inc(v_start_432_);
lean_inc(v_array_431_);
lean_dec(v_a_428_);
v___x_435_ = lean_box(0);
v_isShared_436_ = v_isSharedCheck_455_;
goto v_resetjp_434_;
}
v_resetjp_434_:
{
uint8_t v___x_437_; 
v___x_437_ = lean_nat_dec_lt(v_start_432_, v_stop_433_);
if (v___x_437_ == 0)
{
lean_object* v___x_438_; 
lean_del_object(v___x_435_);
lean_dec(v_stop_433_);
lean_dec(v_start_432_);
lean_dec_ref(v_array_431_);
v___x_438_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_438_, 0, v_b_429_);
return v___x_438_;
}
else
{
lean_object* v_fvarSet_439_; lean_object* v_fvarSet_440_; lean_object* v___x_441_; lean_object* v___x_442_; lean_object* v___x_444_; 
v_fvarSet_439_ = lean_ctor_get(v_a_426_, 1);
v_fvarSet_440_ = lean_ctor_get(v_a_427_, 1);
v___x_441_ = lean_unsigned_to_nat(1u);
v___x_442_ = lean_nat_add(v_start_432_, v___x_441_);
lean_inc_ref(v_array_431_);
if (v_isShared_436_ == 0)
{
lean_ctor_set(v___x_435_, 1, v___x_442_);
v___x_444_ = v___x_435_;
goto v_reusejp_443_;
}
else
{
lean_object* v_reuseFailAlloc_454_; 
v_reuseFailAlloc_454_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v_reuseFailAlloc_454_, 0, v_array_431_);
lean_ctor_set(v_reuseFailAlloc_454_, 1, v___x_442_);
lean_ctor_set(v_reuseFailAlloc_454_, 2, v_stop_433_);
v___x_444_ = v_reuseFailAlloc_454_;
goto v_reusejp_443_;
}
v_reusejp_443_:
{
lean_object* v___x_448_; lean_object* v___x_449_; uint8_t v___x_450_; uint8_t v___x_451_; 
v___x_448_ = lean_array_fget(v_array_431_, v_start_432_);
lean_dec(v_start_432_);
lean_dec_ref(v_array_431_);
v___x_449_ = l_Lean_Expr_fvarId_x21(v___x_448_);
lean_dec(v___x_448_);
v___x_450_ = l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(v___x_449_, v_fvarSet_439_);
v___x_451_ = l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(v___x_449_, v_fvarSet_440_);
lean_dec(v___x_449_);
if (v___x_450_ == 0)
{
if (v___x_451_ == 0)
{
goto v___jp_445_;
}
else
{
lean_object* v___x_452_; 
lean_dec_ref(v___x_444_);
v___x_452_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_452_, 0, v_b_429_);
return v___x_452_;
}
}
else
{
if (v___x_451_ == 0)
{
lean_object* v___x_453_; 
lean_dec_ref(v___x_444_);
v___x_453_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_453_, 0, v_b_429_);
return v___x_453_;
}
else
{
goto v___jp_445_;
}
}
v___jp_445_:
{
lean_object* v___x_446_; 
v___x_446_ = lean_nat_add(v_b_429_, v___x_441_);
lean_dec(v_b_429_);
v_a_428_ = v___x_444_;
v_b_429_ = v___x_446_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg___boxed(lean_object* v_a_456_, lean_object* v_a_457_, lean_object* v_a_458_, lean_object* v_b_459_, lean_object* v___y_460_){
_start:
{
lean_object* v_res_461_; 
v_res_461_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg(v_a_456_, v_a_457_, v_a_458_, v_b_459_);
lean_dec_ref(v_a_457_);
lean_dec_ref(v_a_456_);
return v_res_461_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15(lean_object* v_as_462_, size_t v_i_463_, size_t v_stop_464_, lean_object* v_b_465_){
_start:
{
lean_object* v___y_467_; uint8_t v___x_471_; 
v___x_471_ = lean_usize_dec_eq(v_i_463_, v_stop_464_);
if (v___x_471_ == 0)
{
lean_object* v___x_472_; lean_object* v_fst_473_; uint8_t v___x_474_; uint8_t v___x_475_; 
v___x_472_ = lean_array_uget_borrowed(v_as_462_, v_i_463_);
v_fst_473_ = lean_ctor_get(v___x_472_, 0);
v___x_474_ = lean_unbox(v_fst_473_);
v___x_475_ = l_Lean_BinderInfo_isExplicit(v___x_474_);
if (v___x_475_ == 0)
{
v___y_467_ = v_b_465_;
goto v___jp_466_;
}
else
{
lean_object* v___x_476_; 
lean_inc(v___x_472_);
v___x_476_ = lean_array_push(v_b_465_, v___x_472_);
v___y_467_ = v___x_476_;
goto v___jp_466_;
}
}
else
{
return v_b_465_;
}
v___jp_466_:
{
size_t v___x_468_; size_t v___x_469_; 
v___x_468_ = ((size_t)1ULL);
v___x_469_ = lean_usize_add(v_i_463_, v___x_468_);
v_i_463_ = v___x_469_;
v_b_465_ = v___y_467_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15___boxed(lean_object* v_as_477_, lean_object* v_i_478_, lean_object* v_stop_479_, lean_object* v_b_480_){
_start:
{
size_t v_i_boxed_481_; size_t v_stop_boxed_482_; lean_object* v_res_483_; 
v_i_boxed_481_ = lean_unbox_usize(v_i_478_);
lean_dec(v_i_478_);
v_stop_boxed_482_ = lean_unbox_usize(v_stop_479_);
lean_dec(v_stop_479_);
v_res_483_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15(v_as_477_, v_i_boxed_481_, v_stop_boxed_482_, v_b_480_);
lean_dec_ref(v_as_477_);
return v_res_483_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6(lean_object* v_msgData_484_, lean_object* v___y_485_, lean_object* v___y_486_, lean_object* v___y_487_, lean_object* v___y_488_){
_start:
{
lean_object* v___x_490_; lean_object* v_env_491_; lean_object* v___x_492_; lean_object* v_mctx_493_; lean_object* v_lctx_494_; lean_object* v_options_495_; lean_object* v___x_496_; lean_object* v___x_497_; lean_object* v___x_498_; 
v___x_490_ = lean_st_ref_get(v___y_488_);
v_env_491_ = lean_ctor_get(v___x_490_, 0);
lean_inc_ref(v_env_491_);
lean_dec(v___x_490_);
v___x_492_ = lean_st_ref_get(v___y_486_);
v_mctx_493_ = lean_ctor_get(v___x_492_, 0);
lean_inc_ref(v_mctx_493_);
lean_dec(v___x_492_);
v_lctx_494_ = lean_ctor_get(v___y_485_, 2);
v_options_495_ = lean_ctor_get(v___y_487_, 2);
lean_inc_ref(v_options_495_);
lean_inc_ref(v_lctx_494_);
v___x_496_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_496_, 0, v_env_491_);
lean_ctor_set(v___x_496_, 1, v_mctx_493_);
lean_ctor_set(v___x_496_, 2, v_lctx_494_);
lean_ctor_set(v___x_496_, 3, v_options_495_);
v___x_497_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_497_, 0, v___x_496_);
lean_ctor_set(v___x_497_, 1, v_msgData_484_);
v___x_498_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_498_, 0, v___x_497_);
return v___x_498_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6___boxed(lean_object* v_msgData_499_, lean_object* v___y_500_, lean_object* v___y_501_, lean_object* v___y_502_, lean_object* v___y_503_, lean_object* v___y_504_){
_start:
{
lean_object* v_res_505_; 
v_res_505_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6(v_msgData_499_, v___y_500_, v___y_501_, v___y_502_, v___y_503_);
lean_dec(v___y_503_);
lean_dec_ref(v___y_502_);
lean_dec(v___y_501_);
lean_dec_ref(v___y_500_);
return v_res_505_;
}
}
static double _init_l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0(void){
_start:
{
lean_object* v___x_506_; double v___x_507_; 
v___x_506_ = lean_unsigned_to_nat(0u);
v___x_507_ = lean_float_of_nat(v___x_506_);
return v___x_507_;
}
}
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5(lean_object* v_cls_511_, lean_object* v_msg_512_, lean_object* v___y_513_, lean_object* v___y_514_, lean_object* v___y_515_, lean_object* v___y_516_){
_start:
{
lean_object* v_ref_518_; lean_object* v___x_519_; lean_object* v_a_520_; lean_object* v___x_522_; uint8_t v_isShared_523_; uint8_t v_isSharedCheck_564_; 
v_ref_518_ = lean_ctor_get(v___y_515_, 5);
v___x_519_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6(v_msg_512_, v___y_513_, v___y_514_, v___y_515_, v___y_516_);
v_a_520_ = lean_ctor_get(v___x_519_, 0);
v_isSharedCheck_564_ = !lean_is_exclusive(v___x_519_);
if (v_isSharedCheck_564_ == 0)
{
v___x_522_ = v___x_519_;
v_isShared_523_ = v_isSharedCheck_564_;
goto v_resetjp_521_;
}
else
{
lean_inc(v_a_520_);
lean_dec(v___x_519_);
v___x_522_ = lean_box(0);
v_isShared_523_ = v_isSharedCheck_564_;
goto v_resetjp_521_;
}
v_resetjp_521_:
{
lean_object* v___x_524_; lean_object* v_traceState_525_; lean_object* v_env_526_; lean_object* v_nextMacroScope_527_; lean_object* v_ngen_528_; lean_object* v_auxDeclNGen_529_; lean_object* v_cache_530_; lean_object* v_messages_531_; lean_object* v_infoState_532_; lean_object* v_snapshotTasks_533_; lean_object* v___x_535_; uint8_t v_isShared_536_; uint8_t v_isSharedCheck_563_; 
v___x_524_ = lean_st_ref_take(v___y_516_);
v_traceState_525_ = lean_ctor_get(v___x_524_, 4);
v_env_526_ = lean_ctor_get(v___x_524_, 0);
v_nextMacroScope_527_ = lean_ctor_get(v___x_524_, 1);
v_ngen_528_ = lean_ctor_get(v___x_524_, 2);
v_auxDeclNGen_529_ = lean_ctor_get(v___x_524_, 3);
v_cache_530_ = lean_ctor_get(v___x_524_, 5);
v_messages_531_ = lean_ctor_get(v___x_524_, 6);
v_infoState_532_ = lean_ctor_get(v___x_524_, 7);
v_snapshotTasks_533_ = lean_ctor_get(v___x_524_, 8);
v_isSharedCheck_563_ = !lean_is_exclusive(v___x_524_);
if (v_isSharedCheck_563_ == 0)
{
v___x_535_ = v___x_524_;
v_isShared_536_ = v_isSharedCheck_563_;
goto v_resetjp_534_;
}
else
{
lean_inc(v_snapshotTasks_533_);
lean_inc(v_infoState_532_);
lean_inc(v_messages_531_);
lean_inc(v_cache_530_);
lean_inc(v_traceState_525_);
lean_inc(v_auxDeclNGen_529_);
lean_inc(v_ngen_528_);
lean_inc(v_nextMacroScope_527_);
lean_inc(v_env_526_);
lean_dec(v___x_524_);
v___x_535_ = lean_box(0);
v_isShared_536_ = v_isSharedCheck_563_;
goto v_resetjp_534_;
}
v_resetjp_534_:
{
uint64_t v_tid_537_; lean_object* v_traces_538_; lean_object* v___x_540_; uint8_t v_isShared_541_; uint8_t v_isSharedCheck_562_; 
v_tid_537_ = lean_ctor_get_uint64(v_traceState_525_, sizeof(void*)*1);
v_traces_538_ = lean_ctor_get(v_traceState_525_, 0);
v_isSharedCheck_562_ = !lean_is_exclusive(v_traceState_525_);
if (v_isSharedCheck_562_ == 0)
{
v___x_540_ = v_traceState_525_;
v_isShared_541_ = v_isSharedCheck_562_;
goto v_resetjp_539_;
}
else
{
lean_inc(v_traces_538_);
lean_dec(v_traceState_525_);
v___x_540_ = lean_box(0);
v_isShared_541_ = v_isSharedCheck_562_;
goto v_resetjp_539_;
}
v_resetjp_539_:
{
lean_object* v___x_542_; double v___x_543_; uint8_t v___x_544_; lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; lean_object* v___x_548_; lean_object* v___x_549_; lean_object* v___x_550_; lean_object* v___x_552_; 
v___x_542_ = lean_box(0);
v___x_543_ = lean_float_once(&l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0, &l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0_once, _init_l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__0);
v___x_544_ = 0;
v___x_545_ = ((lean_object*)(l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__1));
v___x_546_ = lean_alloc_ctor(0, 3, 17);
lean_ctor_set(v___x_546_, 0, v_cls_511_);
lean_ctor_set(v___x_546_, 1, v___x_542_);
lean_ctor_set(v___x_546_, 2, v___x_545_);
lean_ctor_set_float(v___x_546_, sizeof(void*)*3, v___x_543_);
lean_ctor_set_float(v___x_546_, sizeof(void*)*3 + 8, v___x_543_);
lean_ctor_set_uint8(v___x_546_, sizeof(void*)*3 + 16, v___x_544_);
v___x_547_ = ((lean_object*)(l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___closed__2));
v___x_548_ = lean_alloc_ctor(9, 3, 0);
lean_ctor_set(v___x_548_, 0, v___x_546_);
lean_ctor_set(v___x_548_, 1, v_a_520_);
lean_ctor_set(v___x_548_, 2, v___x_547_);
lean_inc(v_ref_518_);
v___x_549_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_549_, 0, v_ref_518_);
lean_ctor_set(v___x_549_, 1, v___x_548_);
v___x_550_ = l_Lean_PersistentArray_push___redArg(v_traces_538_, v___x_549_);
if (v_isShared_541_ == 0)
{
lean_ctor_set(v___x_540_, 0, v___x_550_);
v___x_552_ = v___x_540_;
goto v_reusejp_551_;
}
else
{
lean_object* v_reuseFailAlloc_561_; 
v_reuseFailAlloc_561_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v_reuseFailAlloc_561_, 0, v___x_550_);
lean_ctor_set_uint64(v_reuseFailAlloc_561_, sizeof(void*)*1, v_tid_537_);
v___x_552_ = v_reuseFailAlloc_561_;
goto v_reusejp_551_;
}
v_reusejp_551_:
{
lean_object* v___x_554_; 
if (v_isShared_536_ == 0)
{
lean_ctor_set(v___x_535_, 4, v___x_552_);
v___x_554_ = v___x_535_;
goto v_reusejp_553_;
}
else
{
lean_object* v_reuseFailAlloc_560_; 
v_reuseFailAlloc_560_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_560_, 0, v_env_526_);
lean_ctor_set(v_reuseFailAlloc_560_, 1, v_nextMacroScope_527_);
lean_ctor_set(v_reuseFailAlloc_560_, 2, v_ngen_528_);
lean_ctor_set(v_reuseFailAlloc_560_, 3, v_auxDeclNGen_529_);
lean_ctor_set(v_reuseFailAlloc_560_, 4, v___x_552_);
lean_ctor_set(v_reuseFailAlloc_560_, 5, v_cache_530_);
lean_ctor_set(v_reuseFailAlloc_560_, 6, v_messages_531_);
lean_ctor_set(v_reuseFailAlloc_560_, 7, v_infoState_532_);
lean_ctor_set(v_reuseFailAlloc_560_, 8, v_snapshotTasks_533_);
v___x_554_ = v_reuseFailAlloc_560_;
goto v_reusejp_553_;
}
v_reusejp_553_:
{
lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_558_; 
v___x_555_ = lean_st_ref_set(v___y_516_, v___x_554_);
v___x_556_ = lean_box(0);
if (v_isShared_523_ == 0)
{
lean_ctor_set(v___x_522_, 0, v___x_556_);
v___x_558_ = v___x_522_;
goto v_reusejp_557_;
}
else
{
lean_object* v_reuseFailAlloc_559_; 
v_reuseFailAlloc_559_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_559_, 0, v___x_556_);
v___x_558_ = v_reuseFailAlloc_559_;
goto v_reusejp_557_;
}
v_reusejp_557_:
{
return v___x_558_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5___boxed(lean_object* v_cls_565_, lean_object* v_msg_566_, lean_object* v___y_567_, lean_object* v___y_568_, lean_object* v___y_569_, lean_object* v___y_570_, lean_object* v___y_571_){
_start:
{
lean_object* v_res_572_; 
v_res_572_ = l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5(v_cls_565_, v_msg_566_, v___y_567_, v___y_568_, v___y_569_, v___y_570_);
lean_dec(v___y_570_);
lean_dec_ref(v___y_569_);
lean_dec(v___y_568_);
lean_dec_ref(v___y_567_);
return v_res_572_;
}
}
LEAN_EXPORT lean_object* l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17(lean_object* v_xs_573_, lean_object* v_v_574_, lean_object* v_i_575_){
_start:
{
lean_object* v___x_576_; uint8_t v___x_577_; 
v___x_576_ = lean_array_get_size(v_xs_573_);
v___x_577_ = lean_nat_dec_lt(v_i_575_, v___x_576_);
if (v___x_577_ == 0)
{
lean_object* v___x_578_; 
lean_dec(v_i_575_);
v___x_578_ = lean_box(0);
return v___x_578_;
}
else
{
lean_object* v___x_579_; uint8_t v___x_580_; 
v___x_579_ = lean_array_fget_borrowed(v_xs_573_, v_i_575_);
v___x_580_ = lean_name_eq(v___x_579_, v_v_574_);
if (v___x_580_ == 0)
{
lean_object* v___x_581_; lean_object* v___x_582_; 
v___x_581_ = lean_unsigned_to_nat(1u);
v___x_582_ = lean_nat_add(v_i_575_, v___x_581_);
lean_dec(v_i_575_);
v_i_575_ = v___x_582_;
goto _start;
}
else
{
lean_object* v___x_584_; 
v___x_584_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_584_, 0, v_i_575_);
return v___x_584_;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17___boxed(lean_object* v_xs_585_, lean_object* v_v_586_, lean_object* v_i_587_){
_start:
{
lean_object* v_res_588_; 
v_res_588_ = l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17(v_xs_585_, v_v_586_, v_i_587_);
lean_dec(v_v_586_);
lean_dec_ref(v_xs_585_);
return v_res_588_;
}
}
LEAN_EXPORT lean_object* l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13(lean_object* v_xs_589_, lean_object* v_v_590_){
_start:
{
lean_object* v___x_591_; lean_object* v___x_592_; 
v___x_591_ = lean_unsigned_to_nat(0u);
v___x_592_ = l_Array_idxOfAux___at___00Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13_spec__17(v_xs_589_, v_v_590_, v___x_591_);
return v___x_592_;
}
}
LEAN_EXPORT lean_object* l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13___boxed(lean_object* v_xs_593_, lean_object* v_v_594_){
_start:
{
lean_object* v_res_595_; 
v_res_595_ = l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13(v_xs_593_, v_v_594_);
lean_dec(v_v_594_);
lean_dec_ref(v_xs_593_);
return v_res_595_;
}
}
LEAN_EXPORT lean_object* l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10(lean_object* v_xs_596_, lean_object* v_v_597_){
_start:
{
lean_object* v___x_598_; 
v___x_598_ = l_Array_finIdxOf_x3f___at___00Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10_spec__13(v_xs_596_, v_v_597_);
if (lean_obj_tag(v___x_598_) == 0)
{
lean_object* v___x_599_; 
v___x_599_ = lean_box(0);
return v___x_599_;
}
else
{
lean_object* v_val_600_; lean_object* v___x_602_; uint8_t v_isShared_603_; uint8_t v_isSharedCheck_607_; 
v_val_600_ = lean_ctor_get(v___x_598_, 0);
v_isSharedCheck_607_ = !lean_is_exclusive(v___x_598_);
if (v_isSharedCheck_607_ == 0)
{
v___x_602_ = v___x_598_;
v_isShared_603_ = v_isSharedCheck_607_;
goto v_resetjp_601_;
}
else
{
lean_inc(v_val_600_);
lean_dec(v___x_598_);
v___x_602_ = lean_box(0);
v_isShared_603_ = v_isSharedCheck_607_;
goto v_resetjp_601_;
}
v_resetjp_601_:
{
lean_object* v___x_605_; 
if (v_isShared_603_ == 0)
{
v___x_605_ = v___x_602_;
goto v_reusejp_604_;
}
else
{
lean_object* v_reuseFailAlloc_606_; 
v_reuseFailAlloc_606_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_606_, 0, v_val_600_);
v___x_605_ = v_reuseFailAlloc_606_;
goto v_reusejp_604_;
}
v_reusejp_604_:
{
return v___x_605_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10___boxed(lean_object* v_xs_608_, lean_object* v_v_609_){
_start:
{
lean_object* v_res_610_; 
v_res_610_ = l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10(v_xs_608_, v_v_609_);
lean_dec(v_v_609_);
lean_dec_ref(v_xs_608_);
return v_res_610_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(lean_object* v_msg_611_, lean_object* v___y_612_, lean_object* v___y_613_, lean_object* v___y_614_, lean_object* v___y_615_){
_start:
{
lean_object* v_ref_617_; lean_object* v___x_618_; lean_object* v_a_619_; lean_object* v___x_621_; uint8_t v_isShared_622_; uint8_t v_isSharedCheck_627_; 
v_ref_617_ = lean_ctor_get(v___y_614_, 5);
v___x_618_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5_spec__6(v_msg_611_, v___y_612_, v___y_613_, v___y_614_, v___y_615_);
v_a_619_ = lean_ctor_get(v___x_618_, 0);
v_isSharedCheck_627_ = !lean_is_exclusive(v___x_618_);
if (v_isSharedCheck_627_ == 0)
{
v___x_621_ = v___x_618_;
v_isShared_622_ = v_isSharedCheck_627_;
goto v_resetjp_620_;
}
else
{
lean_inc(v_a_619_);
lean_dec(v___x_618_);
v___x_621_ = lean_box(0);
v_isShared_622_ = v_isSharedCheck_627_;
goto v_resetjp_620_;
}
v_resetjp_620_:
{
lean_object* v___x_623_; lean_object* v___x_625_; 
lean_inc(v_ref_617_);
v___x_623_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_623_, 0, v_ref_617_);
lean_ctor_set(v___x_623_, 1, v_a_619_);
if (v_isShared_622_ == 0)
{
lean_ctor_set_tag(v___x_621_, 1);
lean_ctor_set(v___x_621_, 0, v___x_623_);
v___x_625_ = v___x_621_;
goto v_reusejp_624_;
}
else
{
lean_object* v_reuseFailAlloc_626_; 
v_reuseFailAlloc_626_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_626_, 0, v___x_623_);
v___x_625_ = v_reuseFailAlloc_626_;
goto v_reusejp_624_;
}
v_reusejp_624_:
{
return v___x_625_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg___boxed(lean_object* v_msg_628_, lean_object* v___y_629_, lean_object* v___y_630_, lean_object* v___y_631_, lean_object* v___y_632_, lean_object* v___y_633_){
_start:
{
lean_object* v_res_634_; 
v_res_634_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v_msg_628_, v___y_629_, v___y_630_, v___y_631_, v___y_632_);
lean_dec(v___y_632_);
lean_dec_ref(v___y_631_);
lean_dec(v___y_630_);
lean_dec_ref(v___y_629_);
return v_res_634_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(lean_object* v_ref_635_, lean_object* v_msg_636_, lean_object* v___y_637_, lean_object* v___y_638_, lean_object* v___y_639_, lean_object* v___y_640_){
_start:
{
lean_object* v_fileName_642_; lean_object* v_fileMap_643_; lean_object* v_options_644_; lean_object* v_currRecDepth_645_; lean_object* v_maxRecDepth_646_; lean_object* v_ref_647_; lean_object* v_currNamespace_648_; lean_object* v_openDecls_649_; lean_object* v_initHeartbeats_650_; lean_object* v_maxHeartbeats_651_; lean_object* v_quotContext_652_; lean_object* v_currMacroScope_653_; uint8_t v_diag_654_; lean_object* v_cancelTk_x3f_655_; uint8_t v_suppressElabErrors_656_; lean_object* v_inheritedTraceOptions_657_; lean_object* v_ref_658_; lean_object* v___x_659_; lean_object* v___x_660_; 
v_fileName_642_ = lean_ctor_get(v___y_639_, 0);
v_fileMap_643_ = lean_ctor_get(v___y_639_, 1);
v_options_644_ = lean_ctor_get(v___y_639_, 2);
v_currRecDepth_645_ = lean_ctor_get(v___y_639_, 3);
v_maxRecDepth_646_ = lean_ctor_get(v___y_639_, 4);
v_ref_647_ = lean_ctor_get(v___y_639_, 5);
v_currNamespace_648_ = lean_ctor_get(v___y_639_, 6);
v_openDecls_649_ = lean_ctor_get(v___y_639_, 7);
v_initHeartbeats_650_ = lean_ctor_get(v___y_639_, 8);
v_maxHeartbeats_651_ = lean_ctor_get(v___y_639_, 9);
v_quotContext_652_ = lean_ctor_get(v___y_639_, 10);
v_currMacroScope_653_ = lean_ctor_get(v___y_639_, 11);
v_diag_654_ = lean_ctor_get_uint8(v___y_639_, sizeof(void*)*14);
v_cancelTk_x3f_655_ = lean_ctor_get(v___y_639_, 12);
v_suppressElabErrors_656_ = lean_ctor_get_uint8(v___y_639_, sizeof(void*)*14 + 1);
v_inheritedTraceOptions_657_ = lean_ctor_get(v___y_639_, 13);
v_ref_658_ = l_Lean_replaceRef(v_ref_635_, v_ref_647_);
lean_inc_ref(v_inheritedTraceOptions_657_);
lean_inc(v_cancelTk_x3f_655_);
lean_inc(v_currMacroScope_653_);
lean_inc(v_quotContext_652_);
lean_inc(v_maxHeartbeats_651_);
lean_inc(v_initHeartbeats_650_);
lean_inc(v_openDecls_649_);
lean_inc(v_currNamespace_648_);
lean_inc(v_maxRecDepth_646_);
lean_inc(v_currRecDepth_645_);
lean_inc_ref(v_options_644_);
lean_inc_ref(v_fileMap_643_);
lean_inc_ref(v_fileName_642_);
v___x_659_ = lean_alloc_ctor(0, 14, 2);
lean_ctor_set(v___x_659_, 0, v_fileName_642_);
lean_ctor_set(v___x_659_, 1, v_fileMap_643_);
lean_ctor_set(v___x_659_, 2, v_options_644_);
lean_ctor_set(v___x_659_, 3, v_currRecDepth_645_);
lean_ctor_set(v___x_659_, 4, v_maxRecDepth_646_);
lean_ctor_set(v___x_659_, 5, v_ref_658_);
lean_ctor_set(v___x_659_, 6, v_currNamespace_648_);
lean_ctor_set(v___x_659_, 7, v_openDecls_649_);
lean_ctor_set(v___x_659_, 8, v_initHeartbeats_650_);
lean_ctor_set(v___x_659_, 9, v_maxHeartbeats_651_);
lean_ctor_set(v___x_659_, 10, v_quotContext_652_);
lean_ctor_set(v___x_659_, 11, v_currMacroScope_653_);
lean_ctor_set(v___x_659_, 12, v_cancelTk_x3f_655_);
lean_ctor_set(v___x_659_, 13, v_inheritedTraceOptions_657_);
lean_ctor_set_uint8(v___x_659_, sizeof(void*)*14, v_diag_654_);
lean_ctor_set_uint8(v___x_659_, sizeof(void*)*14 + 1, v_suppressElabErrors_656_);
v___x_660_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v_msg_636_, v___y_637_, v___y_638_, v___x_659_, v___y_640_);
lean_dec_ref(v___x_659_);
return v___x_660_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg___boxed(lean_object* v_ref_661_, lean_object* v_msg_662_, lean_object* v___y_663_, lean_object* v___y_664_, lean_object* v___y_665_, lean_object* v___y_666_, lean_object* v___y_667_){
_start:
{
lean_object* v_res_668_; 
v_res_668_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_ref_661_, v_msg_662_, v___y_663_, v___y_664_, v___y_665_, v___y_666_);
lean_dec(v___y_666_);
lean_dec_ref(v___y_665_);
lean_dec(v___y_664_);
lean_dec_ref(v___y_663_);
lean_dec(v_ref_661_);
return v_res_668_;
}
}
LEAN_EXPORT uint8_t l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10(lean_object* v_a_669_, lean_object* v_as_670_, size_t v_i_671_, size_t v_stop_672_){
_start:
{
uint8_t v___x_673_; 
v___x_673_ = lean_usize_dec_eq(v_i_671_, v_stop_672_);
if (v___x_673_ == 0)
{
lean_object* v___x_674_; uint8_t v___x_675_; 
v___x_674_ = lean_array_uget_borrowed(v_as_670_, v_i_671_);
v___x_675_ = lean_nat_dec_eq(v_a_669_, v___x_674_);
if (v___x_675_ == 0)
{
size_t v___x_676_; size_t v___x_677_; 
v___x_676_ = ((size_t)1ULL);
v___x_677_ = lean_usize_add(v_i_671_, v___x_676_);
v_i_671_ = v___x_677_;
goto _start;
}
else
{
return v___x_675_;
}
}
else
{
uint8_t v___x_679_; 
v___x_679_ = 0;
return v___x_679_;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10___boxed(lean_object* v_a_680_, lean_object* v_as_681_, lean_object* v_i_682_, lean_object* v_stop_683_){
_start:
{
size_t v_i_boxed_684_; size_t v_stop_boxed_685_; uint8_t v_res_686_; lean_object* v_r_687_; 
v_i_boxed_684_ = lean_unbox_usize(v_i_682_);
lean_dec(v_i_682_);
v_stop_boxed_685_ = lean_unbox_usize(v_stop_683_);
lean_dec(v_stop_683_);
v_res_686_ = l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10(v_a_680_, v_as_681_, v_i_boxed_684_, v_stop_boxed_685_);
lean_dec_ref(v_as_681_);
lean_dec(v_a_680_);
v_r_687_ = lean_box(v_res_686_);
return v_r_687_;
}
}
LEAN_EXPORT uint8_t l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8(lean_object* v_as_688_, lean_object* v_a_689_){
_start:
{
lean_object* v___x_690_; lean_object* v___x_691_; uint8_t v___x_692_; 
v___x_690_ = lean_unsigned_to_nat(0u);
v___x_691_ = lean_array_get_size(v_as_688_);
v___x_692_ = lean_nat_dec_lt(v___x_690_, v___x_691_);
if (v___x_692_ == 0)
{
return v___x_692_;
}
else
{
if (v___x_692_ == 0)
{
return v___x_692_;
}
else
{
size_t v___x_693_; size_t v___x_694_; uint8_t v___x_695_; 
v___x_693_ = ((size_t)0ULL);
v___x_694_ = lean_usize_of_nat(v___x_691_);
v___x_695_ = l___private_Init_Data_Array_Basic_0__Array_anyMUnsafe_any___at___00Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8_spec__10(v_a_689_, v_as_688_, v___x_693_, v___x_694_);
return v___x_695_;
}
}
}
}
LEAN_EXPORT lean_object* l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8___boxed(lean_object* v_as_696_, lean_object* v_a_697_){
_start:
{
uint8_t v_res_698_; lean_object* v_r_699_; 
v_res_698_ = l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8(v_as_696_, v_a_697_);
lean_dec(v_a_697_);
lean_dec_ref(v_as_696_);
v_r_699_ = lean_box(v_res_698_);
return v_r_699_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1(void){
_start:
{
lean_object* v___x_701_; lean_object* v___x_702_; 
v___x_701_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__0));
v___x_702_ = l_Lean_stringToMessageData(v___x_701_);
return v___x_702_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3(void){
_start:
{
lean_object* v___x_704_; lean_object* v___x_705_; 
v___x_704_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__2));
v___x_705_ = l_Lean_stringToMessageData(v___x_704_);
return v___x_705_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5(void){
_start:
{
lean_object* v___x_707_; lean_object* v___x_708_; 
v___x_707_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__4));
v___x_708_ = l_Lean_stringToMessageData(v___x_707_);
return v___x_708_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7(void){
_start:
{
lean_object* v___x_710_; lean_object* v___x_711_; 
v___x_710_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__6));
v___x_711_ = l_Lean_stringToMessageData(v___x_710_);
return v___x_711_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9(void){
_start:
{
lean_object* v___x_713_; lean_object* v___x_714_; 
v___x_713_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__8));
v___x_714_ = l_Lean_stringToMessageData(v___x_713_);
return v___x_714_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11(void){
_start:
{
lean_object* v___x_716_; lean_object* v___x_717_; 
v___x_716_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__10));
v___x_717_ = l_Lean_stringToMessageData(v___x_716_);
return v___x_717_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13(void){
_start:
{
lean_object* v___x_719_; lean_object* v___x_720_; 
v___x_719_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__12));
v___x_720_ = l_Lean_stringToMessageData(v___x_719_);
return v___x_720_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15(void){
_start:
{
lean_object* v___x_722_; lean_object* v___x_723_; 
v___x_722_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__14));
v___x_723_ = l_Lean_stringToMessageData(v___x_722_);
return v___x_723_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17(void){
_start:
{
lean_object* v___x_725_; lean_object* v___x_726_; 
v___x_725_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__16));
v___x_726_ = l_Lean_stringToMessageData(v___x_725_);
return v___x_726_;
}
}
static lean_object* _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19(void){
_start:
{
lean_object* v___x_728_; lean_object* v___x_729_; 
v___x_728_ = ((lean_object*)(l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__18));
v___x_729_ = l_Lean_stringToMessageData(v___x_728_);
return v___x_729_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12(lean_object* v_a_730_, lean_object* v_declName_731_, lean_object* v_as_732_, size_t v_sz_733_, size_t v_i_734_, lean_object* v_b_735_, lean_object* v___y_736_, lean_object* v___y_737_, lean_object* v___y_738_, lean_object* v___y_739_){
_start:
{
lean_object* v_a_742_; lean_object* v___y_747_; uint8_t v___x_749_; 
v___x_749_ = lean_usize_dec_lt(v_i_734_, v_sz_733_);
if (v___x_749_ == 0)
{
lean_object* v___x_750_; 
lean_dec(v_declName_731_);
v___x_750_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_750_, 0, v_b_735_);
return v___x_750_;
}
else
{
lean_object* v_a_751_; lean_object* v___x_752_; 
v_a_751_ = lean_array_uget_borrowed(v_as_732_, v_i_734_);
v___x_752_ = l_Lean_Syntax_isNatLit_x3f(v_a_751_);
if (lean_obj_tag(v___x_752_) == 1)
{
lean_object* v_val_753_; lean_object* v___x_755_; uint8_t v_isShared_756_; uint8_t v_isSharedCheck_833_; 
v_val_753_ = lean_ctor_get(v___x_752_, 0);
v_isSharedCheck_833_ = !lean_is_exclusive(v___x_752_);
if (v_isSharedCheck_833_ == 0)
{
v___x_755_ = v___x_752_;
v_isShared_756_ = v_isSharedCheck_833_;
goto v_resetjp_754_;
}
else
{
lean_inc(v_val_753_);
lean_dec(v___x_752_);
v___x_755_ = lean_box(0);
v_isShared_756_ = v_isSharedCheck_833_;
goto v_resetjp_754_;
}
v_resetjp_754_:
{
lean_object* v___y_758_; lean_object* v___y_759_; lean_object* v___y_760_; lean_object* v___y_761_; lean_object* v___x_821_; uint8_t v___x_822_; 
v___x_821_ = lean_unsigned_to_nat(0u);
v___x_822_ = lean_nat_dec_eq(v_val_753_, v___x_821_);
if (v___x_822_ == 0)
{
v___y_758_ = v___y_736_;
v___y_759_ = v___y_737_;
v___y_760_ = v___y_738_;
v___y_761_ = v___y_739_;
goto v___jp_757_;
}
else
{
lean_object* v___x_823_; lean_object* v___x_824_; 
v___x_823_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__13);
v___x_824_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_a_751_, v___x_823_, v___y_736_, v___y_737_, v___y_738_, v___y_739_);
if (lean_obj_tag(v___x_824_) == 0)
{
lean_dec_ref(v___x_824_);
v___y_758_ = v___y_736_;
v___y_759_ = v___y_737_;
v___y_760_ = v___y_738_;
v___y_761_ = v___y_739_;
goto v___jp_757_;
}
else
{
lean_object* v_a_825_; lean_object* v___x_827_; uint8_t v_isShared_828_; uint8_t v_isSharedCheck_832_; 
lean_del_object(v___x_755_);
lean_dec(v_val_753_);
lean_dec_ref(v_b_735_);
lean_dec(v_declName_731_);
v_a_825_ = lean_ctor_get(v___x_824_, 0);
v_isSharedCheck_832_ = !lean_is_exclusive(v___x_824_);
if (v_isSharedCheck_832_ == 0)
{
v___x_827_ = v___x_824_;
v_isShared_828_ = v_isSharedCheck_832_;
goto v_resetjp_826_;
}
else
{
lean_inc(v_a_825_);
lean_dec(v___x_824_);
v___x_827_ = lean_box(0);
v_isShared_828_ = v_isSharedCheck_832_;
goto v_resetjp_826_;
}
v_resetjp_826_:
{
lean_object* v___x_830_; 
if (v_isShared_828_ == 0)
{
v___x_830_ = v___x_827_;
goto v_reusejp_829_;
}
else
{
lean_object* v_reuseFailAlloc_831_; 
v_reuseFailAlloc_831_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_831_, 0, v_a_825_);
v___x_830_ = v_reuseFailAlloc_831_;
goto v_reusejp_829_;
}
v_reusejp_829_:
{
return v___x_830_;
}
}
}
}
v___jp_757_:
{
lean_object* v___x_762_; lean_object* v___x_763_; lean_object* v___x_764_; uint8_t v___x_765_; 
v___x_762_ = lean_unsigned_to_nat(1u);
v___x_763_ = lean_nat_sub(v_val_753_, v___x_762_);
lean_dec(v_val_753_);
v___x_764_ = lean_array_get_size(v_a_730_);
v___x_765_ = lean_nat_dec_le(v___x_764_, v___x_763_);
if (v___x_765_ == 0)
{
uint8_t v___x_766_; 
v___x_766_ = l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8(v_b_735_, v___x_763_);
if (v___x_766_ == 0)
{
lean_del_object(v___x_755_);
v___y_747_ = v___x_763_;
goto v___jp_746_;
}
else
{
lean_object* v___x_767_; lean_object* v___x_768_; lean_object* v___x_769_; lean_object* v___x_771_; 
v___x_767_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1);
v___x_768_ = lean_nat_add(v___x_763_, v___x_762_);
v___x_769_ = l_Nat_reprFast(v___x_768_);
if (v_isShared_756_ == 0)
{
lean_ctor_set_tag(v___x_755_, 3);
lean_ctor_set(v___x_755_, 0, v___x_769_);
v___x_771_ = v___x_755_;
goto v_reusejp_770_;
}
else
{
lean_object* v_reuseFailAlloc_791_; 
v_reuseFailAlloc_791_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_791_, 0, v___x_769_);
v___x_771_ = v_reuseFailAlloc_791_;
goto v_reusejp_770_;
}
v_reusejp_770_:
{
lean_object* v___x_772_; lean_object* v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; lean_object* v___x_776_; lean_object* v___x_777_; lean_object* v___x_778_; lean_object* v___x_779_; lean_object* v___x_780_; lean_object* v___x_781_; lean_object* v___x_782_; 
v___x_772_ = l_Lean_MessageData_ofFormat(v___x_771_);
v___x_773_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_773_, 0, v___x_767_);
lean_ctor_set(v___x_773_, 1, v___x_772_);
v___x_774_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__3);
v___x_775_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_775_, 0, v___x_773_);
lean_ctor_set(v___x_775_, 1, v___x_774_);
v___x_776_ = lean_box(0);
v___x_777_ = lean_array_get_borrowed(v___x_776_, v_a_730_, v___x_763_);
lean_inc(v___x_777_);
v___x_778_ = l_Lean_MessageData_ofName(v___x_777_);
v___x_779_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_779_, 0, v___x_775_);
lean_ctor_set(v___x_779_, 1, v___x_778_);
v___x_780_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__5);
v___x_781_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_781_, 0, v___x_779_);
lean_ctor_set(v___x_781_, 1, v___x_780_);
v___x_782_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_a_751_, v___x_781_, v___y_758_, v___y_759_, v___y_760_, v___y_761_);
if (lean_obj_tag(v___x_782_) == 0)
{
lean_dec_ref(v___x_782_);
v___y_747_ = v___x_763_;
goto v___jp_746_;
}
else
{
lean_object* v_a_783_; lean_object* v___x_785_; uint8_t v_isShared_786_; uint8_t v_isSharedCheck_790_; 
lean_dec(v___x_763_);
lean_dec_ref(v_b_735_);
lean_dec(v_declName_731_);
v_a_783_ = lean_ctor_get(v___x_782_, 0);
v_isSharedCheck_790_ = !lean_is_exclusive(v___x_782_);
if (v_isSharedCheck_790_ == 0)
{
v___x_785_ = v___x_782_;
v_isShared_786_ = v_isSharedCheck_790_;
goto v_resetjp_784_;
}
else
{
lean_inc(v_a_783_);
lean_dec(v___x_782_);
v___x_785_ = lean_box(0);
v_isShared_786_ = v_isSharedCheck_790_;
goto v_resetjp_784_;
}
v_resetjp_784_:
{
lean_object* v___x_788_; 
if (v_isShared_786_ == 0)
{
v___x_788_ = v___x_785_;
goto v_reusejp_787_;
}
else
{
lean_object* v_reuseFailAlloc_789_; 
v_reuseFailAlloc_789_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_789_, 0, v_a_783_);
v___x_788_ = v_reuseFailAlloc_789_;
goto v_reusejp_787_;
}
v_reusejp_787_:
{
return v___x_788_;
}
}
}
}
}
}
else
{
lean_object* v___x_792_; lean_object* v___x_793_; lean_object* v___x_795_; 
v___x_792_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__1);
v___x_793_ = l_Nat_reprFast(v___x_763_);
if (v_isShared_756_ == 0)
{
lean_ctor_set_tag(v___x_755_, 3);
lean_ctor_set(v___x_755_, 0, v___x_793_);
v___x_795_ = v___x_755_;
goto v_reusejp_794_;
}
else
{
lean_object* v_reuseFailAlloc_820_; 
v_reuseFailAlloc_820_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_820_, 0, v___x_793_);
v___x_795_ = v_reuseFailAlloc_820_;
goto v_reusejp_794_;
}
v_reusejp_794_:
{
lean_object* v___x_796_; lean_object* v___x_797_; lean_object* v___x_798_; lean_object* v___x_799_; uint8_t v___x_800_; lean_object* v___x_801_; lean_object* v___x_802_; lean_object* v___x_803_; lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___x_808_; lean_object* v___x_809_; lean_object* v___x_810_; lean_object* v___x_811_; 
v___x_796_ = l_Lean_MessageData_ofFormat(v___x_795_);
v___x_797_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_797_, 0, v___x_792_);
lean_ctor_set(v___x_797_, 1, v___x_796_);
v___x_798_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7);
v___x_799_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_799_, 0, v___x_797_);
lean_ctor_set(v___x_799_, 1, v___x_798_);
v___x_800_ = 0;
lean_inc(v_declName_731_);
v___x_801_ = l_Lean_MessageData_ofConstName(v_declName_731_, v___x_800_);
v___x_802_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_802_, 0, v___x_799_);
lean_ctor_set(v___x_802_, 1, v___x_801_);
v___x_803_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__9);
v___x_804_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_804_, 0, v___x_802_);
lean_ctor_set(v___x_804_, 1, v___x_803_);
v___x_805_ = l_Nat_reprFast(v___x_764_);
v___x_806_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_806_, 0, v___x_805_);
v___x_807_ = l_Lean_MessageData_ofFormat(v___x_806_);
v___x_808_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_808_, 0, v___x_804_);
lean_ctor_set(v___x_808_, 1, v___x_807_);
v___x_809_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__11);
v___x_810_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_810_, 0, v___x_808_);
lean_ctor_set(v___x_810_, 1, v___x_809_);
v___x_811_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_a_751_, v___x_810_, v___y_758_, v___y_759_, v___y_760_, v___y_761_);
if (lean_obj_tag(v___x_811_) == 0)
{
lean_dec_ref(v___x_811_);
v_a_742_ = v_b_735_;
goto v___jp_741_;
}
else
{
lean_object* v_a_812_; lean_object* v___x_814_; uint8_t v_isShared_815_; uint8_t v_isSharedCheck_819_; 
lean_dec_ref(v_b_735_);
lean_dec(v_declName_731_);
v_a_812_ = lean_ctor_get(v___x_811_, 0);
v_isSharedCheck_819_ = !lean_is_exclusive(v___x_811_);
if (v_isSharedCheck_819_ == 0)
{
v___x_814_ = v___x_811_;
v_isShared_815_ = v_isSharedCheck_819_;
goto v_resetjp_813_;
}
else
{
lean_inc(v_a_812_);
lean_dec(v___x_811_);
v___x_814_ = lean_box(0);
v_isShared_815_ = v_isSharedCheck_819_;
goto v_resetjp_813_;
}
v_resetjp_813_:
{
lean_object* v___x_817_; 
if (v_isShared_815_ == 0)
{
v___x_817_ = v___x_814_;
goto v_reusejp_816_;
}
else
{
lean_object* v_reuseFailAlloc_818_; 
v_reuseFailAlloc_818_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_818_, 0, v_a_812_);
v___x_817_ = v_reuseFailAlloc_818_;
goto v_reusejp_816_;
}
v_reusejp_816_:
{
return v___x_817_;
}
}
}
}
}
}
}
}
else
{
lean_object* v___x_834_; lean_object* v___x_835_; 
lean_dec(v___x_752_);
v___x_834_ = l_Lean_Syntax_getId(v_a_751_);
v___x_835_ = l_Array_idxOf_x3f___at___00Lean_Meta_inferRelationInfo_spec__10(v_a_730_, v___x_834_);
if (lean_obj_tag(v___x_835_) == 1)
{
lean_object* v_val_836_; uint8_t v___x_839_; 
v_val_836_ = lean_ctor_get(v___x_835_, 0);
lean_inc(v_val_836_);
lean_dec_ref(v___x_835_);
v___x_839_ = l_Array_contains___at___00Lean_Meta_inferRelationInfo_spec__8(v_b_735_, v_val_836_);
if (v___x_839_ == 0)
{
lean_dec(v___x_834_);
goto v___jp_837_;
}
else
{
lean_object* v___x_840_; lean_object* v___x_841_; lean_object* v___x_842_; lean_object* v___x_843_; lean_object* v___x_844_; lean_object* v___x_845_; 
v___x_840_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15);
v___x_841_ = l_Lean_MessageData_ofName(v___x_834_);
v___x_842_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_842_, 0, v___x_840_);
lean_ctor_set(v___x_842_, 1, v___x_841_);
v___x_843_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__17);
v___x_844_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_844_, 0, v___x_842_);
lean_ctor_set(v___x_844_, 1, v___x_843_);
v___x_845_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_a_751_, v___x_844_, v___y_736_, v___y_737_, v___y_738_, v___y_739_);
if (lean_obj_tag(v___x_845_) == 0)
{
lean_dec_ref(v___x_845_);
goto v___jp_837_;
}
else
{
lean_object* v_a_846_; lean_object* v___x_848_; uint8_t v_isShared_849_; uint8_t v_isSharedCheck_853_; 
lean_dec(v_val_836_);
lean_dec_ref(v_b_735_);
lean_dec(v_declName_731_);
v_a_846_ = lean_ctor_get(v___x_845_, 0);
v_isSharedCheck_853_ = !lean_is_exclusive(v___x_845_);
if (v_isSharedCheck_853_ == 0)
{
v___x_848_ = v___x_845_;
v_isShared_849_ = v_isSharedCheck_853_;
goto v_resetjp_847_;
}
else
{
lean_inc(v_a_846_);
lean_dec(v___x_845_);
v___x_848_ = lean_box(0);
v_isShared_849_ = v_isSharedCheck_853_;
goto v_resetjp_847_;
}
v_resetjp_847_:
{
lean_object* v___x_851_; 
if (v_isShared_849_ == 0)
{
v___x_851_ = v___x_848_;
goto v_reusejp_850_;
}
else
{
lean_object* v_reuseFailAlloc_852_; 
v_reuseFailAlloc_852_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_852_, 0, v_a_846_);
v___x_851_ = v_reuseFailAlloc_852_;
goto v_reusejp_850_;
}
v_reusejp_850_:
{
return v___x_851_;
}
}
}
}
v___jp_837_:
{
lean_object* v___x_838_; 
v___x_838_ = lean_array_push(v_b_735_, v_val_836_);
v_a_742_ = v___x_838_;
goto v___jp_741_;
}
}
else
{
lean_object* v___x_854_; lean_object* v___x_855_; lean_object* v___x_856_; lean_object* v___x_857_; lean_object* v___x_858_; uint8_t v___x_859_; lean_object* v___x_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; lean_object* v___x_864_; 
lean_dec(v___x_835_);
v___x_854_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__15);
v___x_855_ = l_Lean_MessageData_ofName(v___x_834_);
v___x_856_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_856_, 0, v___x_854_);
lean_ctor_set(v___x_856_, 1, v___x_855_);
v___x_857_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__7);
v___x_858_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_858_, 0, v___x_856_);
lean_ctor_set(v___x_858_, 1, v___x_857_);
v___x_859_ = 0;
lean_inc(v_declName_731_);
v___x_860_ = l_Lean_MessageData_ofConstName(v_declName_731_, v___x_859_);
v___x_861_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_861_, 0, v___x_858_);
lean_ctor_set(v___x_861_, 1, v___x_860_);
v___x_862_ = lean_obj_once(&l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19, &l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19_once, _init_l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___closed__19);
v___x_863_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_863_, 0, v___x_861_);
lean_ctor_set(v___x_863_, 1, v___x_862_);
v___x_864_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_a_751_, v___x_863_, v___y_736_, v___y_737_, v___y_738_, v___y_739_);
if (lean_obj_tag(v___x_864_) == 0)
{
lean_dec_ref(v___x_864_);
v_a_742_ = v_b_735_;
goto v___jp_741_;
}
else
{
lean_object* v_a_865_; lean_object* v___x_867_; uint8_t v_isShared_868_; uint8_t v_isSharedCheck_872_; 
lean_dec_ref(v_b_735_);
lean_dec(v_declName_731_);
v_a_865_ = lean_ctor_get(v___x_864_, 0);
v_isSharedCheck_872_ = !lean_is_exclusive(v___x_864_);
if (v_isSharedCheck_872_ == 0)
{
v___x_867_ = v___x_864_;
v_isShared_868_ = v_isSharedCheck_872_;
goto v_resetjp_866_;
}
else
{
lean_inc(v_a_865_);
lean_dec(v___x_864_);
v___x_867_ = lean_box(0);
v_isShared_868_ = v_isSharedCheck_872_;
goto v_resetjp_866_;
}
v_resetjp_866_:
{
lean_object* v___x_870_; 
if (v_isShared_868_ == 0)
{
v___x_870_ = v___x_867_;
goto v_reusejp_869_;
}
else
{
lean_object* v_reuseFailAlloc_871_; 
v_reuseFailAlloc_871_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_871_, 0, v_a_865_);
v___x_870_ = v_reuseFailAlloc_871_;
goto v_reusejp_869_;
}
v_reusejp_869_:
{
return v___x_870_;
}
}
}
}
}
}
v___jp_741_:
{
size_t v___x_743_; size_t v___x_744_; 
v___x_743_ = ((size_t)1ULL);
v___x_744_ = lean_usize_add(v_i_734_, v___x_743_);
v_i_734_ = v___x_744_;
v_b_735_ = v_a_742_;
goto _start;
}
v___jp_746_:
{
lean_object* v___x_748_; 
v___x_748_ = lean_array_push(v_b_735_, v___y_747_);
v_a_742_ = v___x_748_;
goto v___jp_741_;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12___boxed(lean_object* v_a_873_, lean_object* v_declName_874_, lean_object* v_as_875_, lean_object* v_sz_876_, lean_object* v_i_877_, lean_object* v_b_878_, lean_object* v___y_879_, lean_object* v___y_880_, lean_object* v___y_881_, lean_object* v___y_882_, lean_object* v___y_883_){
_start:
{
size_t v_sz_boxed_884_; size_t v_i_boxed_885_; lean_object* v_res_886_; 
v_sz_boxed_884_ = lean_unbox_usize(v_sz_876_);
lean_dec(v_sz_876_);
v_i_boxed_885_ = lean_unbox_usize(v_i_877_);
lean_dec(v_i_877_);
v_res_886_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12(v_a_873_, v_declName_874_, v_as_875_, v_sz_boxed_884_, v_i_boxed_885_, v_b_878_, v___y_879_, v___y_880_, v___y_881_, v___y_882_);
lean_dec(v___y_882_);
lean_dec_ref(v___y_881_);
lean_dec(v___y_880_);
lean_dec_ref(v___y_879_);
lean_dec_ref(v_as_875_);
lean_dec_ref(v_a_873_);
return v_res_886_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__4(void){
_start:
{
lean_object* v___x_894_; lean_object* v___x_895_; 
v___x_894_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__3));
v___x_895_ = l_Lean_stringToMessageData(v___x_894_);
return v___x_895_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__6(void){
_start:
{
lean_object* v___x_897_; lean_object* v___x_898_; 
v___x_897_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__5));
v___x_898_ = l_Lean_stringToMessageData(v___x_897_);
return v___x_898_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__8(void){
_start:
{
lean_object* v___x_900_; lean_object* v___x_901_; 
v___x_900_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__7));
v___x_901_ = l_Lean_stringToMessageData(v___x_900_);
return v___x_901_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__10(void){
_start:
{
lean_object* v___x_903_; lean_object* v___x_904_; 
v___x_903_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__9));
v___x_904_ = l_Lean_stringToMessageData(v___x_903_);
return v___x_904_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__12(void){
_start:
{
lean_object* v___x_906_; lean_object* v___x_907_; 
v___x_906_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__11));
v___x_907_ = l_Lean_stringToMessageData(v___x_906_);
return v___x_907_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__14(void){
_start:
{
lean_object* v___x_909_; lean_object* v___x_910_; 
v___x_909_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__13));
v___x_910_ = l_Lean_stringToMessageData(v___x_909_);
return v___x_910_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__15(void){
_start:
{
lean_object* v___x_911_; lean_object* v___x_912_; lean_object* v___x_913_; 
v___x_911_ = lean_box(0);
v___x_912_ = lean_unsigned_to_nat(16u);
v___x_913_ = lean_mk_array(v___x_912_, v___x_911_);
return v___x_913_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__19(void){
_start:
{
lean_object* v___x_917_; lean_object* v___x_918_; lean_object* v___x_919_; lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; 
v___x_917_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__18));
v___x_918_ = lean_unsigned_to_nat(4u);
v___x_919_ = lean_unsigned_to_nat(101u);
v___x_920_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__17));
v___x_921_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__16));
v___x_922_ = l_mkPanicMessageWithDecl(v___x_921_, v___x_920_, v___x_919_, v___x_918_, v___x_917_);
return v___x_922_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__21(void){
_start:
{
lean_object* v___x_924_; lean_object* v___x_925_; 
v___x_924_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__20));
v___x_925_ = l_Lean_stringToMessageData(v___x_924_);
return v___x_925_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__23(void){
_start:
{
lean_object* v___x_927_; lean_object* v___x_928_; 
v___x_927_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__22));
v___x_928_ = l_Lean_stringToMessageData(v___x_927_);
return v___x_928_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__25(void){
_start:
{
lean_object* v___x_930_; lean_object* v___x_931_; 
v___x_930_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__24));
v___x_931_ = l_Lean_stringToMessageData(v___x_930_);
return v___x_931_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__27(void){
_start:
{
lean_object* v___x_933_; lean_object* v___x_934_; 
v___x_933_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__26));
v___x_934_ = l_Lean_stringToMessageData(v___x_933_);
return v___x_934_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__29(void){
_start:
{
lean_object* v___x_936_; lean_object* v___x_937_; 
v___x_936_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__28));
v___x_937_ = l_Lean_stringToMessageData(v___x_936_);
return v___x_937_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__31(void){
_start:
{
lean_object* v___x_939_; lean_object* v___x_940_; 
v___x_939_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__30));
v___x_940_ = l_Lean_stringToMessageData(v___x_939_);
return v___x_940_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__33(void){
_start:
{
lean_object* v___x_942_; lean_object* v___x_943_; 
v___x_942_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__32));
v___x_943_ = l_Lean_stringToMessageData(v___x_942_);
return v___x_943_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__2(lean_object* v___x_944_, lean_object* v_declName_945_, lean_object* v_args_946_, lean_object* v___f_947_, lean_object* v___f_948_, lean_object* v_xs_949_, lean_object* v_ty_950_, lean_object* v___y_951_, lean_object* v___y_952_, lean_object* v___y_953_, lean_object* v___y_954_){
_start:
{
lean_object* v___y_957_; lean_object* v___y_958_; lean_object* v___y_959_; lean_object* v___y_960_; lean_object* v___y_961_; lean_object* v___y_962_; lean_object* v___y_963_; lean_object* v___y_964_; lean_object* v___y_965_; lean_object* v___y_966_; lean_object* v___y_1040_; lean_object* v___y_1041_; lean_object* v___y_1042_; lean_object* v___y_1043_; lean_object* v___y_1044_; lean_object* v___y_1045_; lean_object* v___y_1046_; lean_object* v_operands_1079_; lean_object* v___y_1080_; lean_object* v___y_1081_; lean_object* v___y_1082_; lean_object* v___y_1083_; lean_object* v___y_1112_; size_t v___y_1113_; lean_object* v___y_1114_; lean_object* v___y_1115_; lean_object* v___y_1116_; lean_object* v___y_1117_; lean_object* v___y_1118_; lean_object* v___y_1127_; lean_object* v___y_1128_; size_t v___y_1129_; lean_object* v___y_1130_; lean_object* v___y_1131_; lean_object* v___y_1132_; lean_object* v___y_1133_; lean_object* v___y_1152_; lean_object* v___y_1153_; lean_object* v___y_1154_; lean_object* v___y_1155_; lean_object* v___x_1201_; uint8_t v_fst_1203_; lean_object* v_mctx_1204_; lean_object* v___y_1240_; lean_object* v_mctx_1245_; lean_object* v___x_1246_; lean_object* v___x_1247_; lean_object* v___x_1248_; uint8_t v___x_1249_; 
v___x_1201_ = lean_st_ref_get(v___y_952_);
v_mctx_1245_ = lean_ctor_get(v___x_1201_, 0);
lean_inc_ref(v_mctx_1245_);
lean_dec(v___x_1201_);
v___x_1246_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__15, &l_Lean_Meta_inferRelationInfo___lam__2___closed__15_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__15);
lean_inc(v___x_944_);
v___x_1247_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1247_, 0, v___x_944_);
lean_ctor_set(v___x_1247_, 1, v___x_1246_);
lean_inc_ref(v_mctx_1245_);
v___x_1248_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1248_, 0, v___x_1247_);
lean_ctor_set(v___x_1248_, 1, v_mctx_1245_);
v___x_1249_ = l_Lean_Expr_hasFVar(v_ty_950_);
if (v___x_1249_ == 0)
{
uint8_t v___x_1250_; 
v___x_1250_ = l_Lean_Expr_hasMVar(v_ty_950_);
if (v___x_1250_ == 0)
{
lean_dec_ref(v___x_1248_);
lean_dec_ref(v___f_948_);
lean_dec_ref(v___f_947_);
v_fst_1203_ = v___x_1250_;
v_mctx_1204_ = v_mctx_1245_;
goto v___jp_1202_;
}
else
{
lean_object* v___x_1251_; 
lean_dec_ref(v_mctx_1245_);
lean_inc_ref(v_ty_950_);
v___x_1251_ = l___private_Lean_MetavarContext_0__Lean_DependsOn_dep_visit(v___f_947_, v___f_948_, v_ty_950_, v___x_1248_);
v___y_1240_ = v___x_1251_;
goto v___jp_1239_;
}
}
else
{
lean_object* v___x_1252_; 
lean_dec_ref(v_mctx_1245_);
lean_inc_ref(v_ty_950_);
v___x_1252_ = l___private_Lean_MetavarContext_0__Lean_DependsOn_dep_visit(v___f_947_, v___f_948_, v_ty_950_, v___x_1248_);
v___y_1240_ = v___x_1252_;
goto v___jp_1239_;
}
v___jp_956_:
{
lean_object* v___x_967_; lean_object* v___x_968_; 
lean_inc(v___x_944_);
lean_inc_ref(v_xs_949_);
v___x_967_ = l_Array_toSubarray___redArg(v_xs_949_, v___x_944_, v___y_966_);
v___x_968_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg(v___y_958_, v___y_962_, v___x_967_, v___x_944_);
lean_dec_ref(v___y_962_);
lean_dec_ref(v___y_958_);
if (lean_obj_tag(v___x_968_) == 0)
{
lean_object* v_a_969_; lean_object* v___x_970_; lean_object* v___x_971_; lean_object* v_a_972_; lean_object* v___x_974_; uint8_t v_isShared_975_; uint8_t v_isSharedCheck_1030_; 
v_a_969_ = lean_ctor_get(v___x_968_, 0);
lean_inc(v_a_969_);
lean_dec_ref(v___x_968_);
v___x_970_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__2));
v___x_971_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_inferRelationInfo_spec__4___redArg(v___x_970_, v___y_960_);
v_a_972_ = lean_ctor_get(v___x_971_, 0);
v_isSharedCheck_1030_ = !lean_is_exclusive(v___x_971_);
if (v_isSharedCheck_1030_ == 0)
{
v___x_974_ = v___x_971_;
v_isShared_975_ = v_isSharedCheck_1030_;
goto v_resetjp_973_;
}
else
{
lean_inc(v_a_972_);
lean_dec(v___x_971_);
v___x_974_ = lean_box(0);
v_isShared_975_ = v_isSharedCheck_1030_;
goto v_resetjp_973_;
}
v_resetjp_973_:
{
lean_object* v___x_976_; lean_object* v___x_977_; uint8_t v___x_978_; 
v___x_976_ = lean_array_get_size(v_xs_949_);
lean_dec_ref(v_xs_949_);
lean_inc(v___y_957_);
lean_inc(v___y_959_);
lean_inc(v_a_969_);
v___x_977_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_977_, 0, v___x_976_);
lean_ctor_set(v___x_977_, 1, v_a_969_);
lean_ctor_set(v___x_977_, 2, v___y_959_);
lean_ctor_set(v___x_977_, 3, v___y_957_);
v___x_978_ = lean_unbox(v_a_972_);
lean_dec(v_a_972_);
if (v___x_978_ == 0)
{
lean_object* v___x_980_; 
lean_dec(v_a_969_);
lean_dec(v___y_959_);
lean_dec(v___y_957_);
lean_dec(v_declName_945_);
if (v_isShared_975_ == 0)
{
lean_ctor_set(v___x_974_, 0, v___x_977_);
v___x_980_ = v___x_974_;
goto v_reusejp_979_;
}
else
{
lean_object* v_reuseFailAlloc_981_; 
v_reuseFailAlloc_981_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_981_, 0, v___x_977_);
v___x_980_ = v_reuseFailAlloc_981_;
goto v_reusejp_979_;
}
v_reusejp_979_:
{
return v___x_980_;
}
}
else
{
lean_object* v___x_982_; lean_object* v___x_983_; lean_object* v___x_984_; lean_object* v___x_985_; lean_object* v___x_986_; lean_object* v___x_987_; lean_object* v___x_988_; lean_object* v___x_989_; lean_object* v___x_990_; lean_object* v___x_991_; lean_object* v___x_992_; lean_object* v___x_993_; lean_object* v___x_994_; lean_object* v___x_995_; lean_object* v___x_996_; lean_object* v___x_997_; lean_object* v___x_998_; lean_object* v___x_999_; lean_object* v___x_1000_; lean_object* v___x_1001_; lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; lean_object* v___x_1005_; lean_object* v___x_1006_; lean_object* v___x_1007_; lean_object* v___x_1008_; lean_object* v___x_1009_; lean_object* v___x_1010_; lean_object* v___x_1011_; lean_object* v___x_1012_; lean_object* v___x_1013_; 
lean_del_object(v___x_974_);
v___x_982_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__4, &l_Lean_Meta_inferRelationInfo___lam__2___closed__4_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__4);
v___x_983_ = l_Lean_MessageData_ofName(v_declName_945_);
v___x_984_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_984_, 0, v___x_982_);
lean_ctor_set(v___x_984_, 1, v___x_983_);
v___x_985_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__6, &l_Lean_Meta_inferRelationInfo___lam__2___closed__6_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__6);
v___x_986_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_986_, 0, v___x_984_);
lean_ctor_set(v___x_986_, 1, v___x_985_);
v___x_987_ = l_Nat_reprFast(v___x_976_);
v___x_988_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_988_, 0, v___x_987_);
v___x_989_ = l_Lean_MessageData_ofFormat(v___x_988_);
v___x_990_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_990_, 0, v___x_986_);
lean_ctor_set(v___x_990_, 1, v___x_989_);
v___x_991_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__8, &l_Lean_Meta_inferRelationInfo___lam__2___closed__8_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__8);
v___x_992_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_992_, 0, v___x_990_);
lean_ctor_set(v___x_992_, 1, v___x_991_);
v___x_993_ = l_Nat_reprFast(v_a_969_);
v___x_994_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_994_, 0, v___x_993_);
v___x_995_ = l_Lean_MessageData_ofFormat(v___x_994_);
v___x_996_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_996_, 0, v___x_992_);
lean_ctor_set(v___x_996_, 1, v___x_995_);
v___x_997_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__10, &l_Lean_Meta_inferRelationInfo___lam__2___closed__10_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__10);
v___x_998_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_998_, 0, v___x_996_);
lean_ctor_set(v___x_998_, 1, v___x_997_);
v___x_999_ = lean_nat_add(v___y_959_, v___y_963_);
lean_dec(v___y_959_);
v___x_1000_ = l_Nat_reprFast(v___x_999_);
v___x_1001_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1001_, 0, v___x_1000_);
v___x_1002_ = l_Lean_MessageData_ofFormat(v___x_1001_);
v___x_1003_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1003_, 0, v___x_998_);
lean_ctor_set(v___x_1003_, 1, v___x_1002_);
v___x_1004_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__12, &l_Lean_Meta_inferRelationInfo___lam__2___closed__12_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__12);
v___x_1005_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1005_, 0, v___x_1003_);
lean_ctor_set(v___x_1005_, 1, v___x_1004_);
v___x_1006_ = lean_nat_add(v___y_957_, v___y_963_);
lean_dec(v___y_957_);
v___x_1007_ = l_Nat_reprFast(v___x_1006_);
v___x_1008_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1008_, 0, v___x_1007_);
v___x_1009_ = l_Lean_MessageData_ofFormat(v___x_1008_);
v___x_1010_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1010_, 0, v___x_1005_);
lean_ctor_set(v___x_1010_, 1, v___x_1009_);
v___x_1011_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__14, &l_Lean_Meta_inferRelationInfo___lam__2___closed__14_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__14);
v___x_1012_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1012_, 0, v___x_1010_);
lean_ctor_set(v___x_1012_, 1, v___x_1011_);
v___x_1013_ = l_Lean_addTrace___at___00Lean_Meta_inferRelationInfo_spec__5(v___x_970_, v___x_1012_, v___y_965_, v___y_961_, v___y_960_, v___y_964_);
if (lean_obj_tag(v___x_1013_) == 0)
{
lean_object* v___x_1015_; uint8_t v_isShared_1016_; uint8_t v_isSharedCheck_1020_; 
v_isSharedCheck_1020_ = !lean_is_exclusive(v___x_1013_);
if (v_isSharedCheck_1020_ == 0)
{
lean_object* v_unused_1021_; 
v_unused_1021_ = lean_ctor_get(v___x_1013_, 0);
lean_dec(v_unused_1021_);
v___x_1015_ = v___x_1013_;
v_isShared_1016_ = v_isSharedCheck_1020_;
goto v_resetjp_1014_;
}
else
{
lean_dec(v___x_1013_);
v___x_1015_ = lean_box(0);
v_isShared_1016_ = v_isSharedCheck_1020_;
goto v_resetjp_1014_;
}
v_resetjp_1014_:
{
lean_object* v___x_1018_; 
if (v_isShared_1016_ == 0)
{
lean_ctor_set(v___x_1015_, 0, v___x_977_);
v___x_1018_ = v___x_1015_;
goto v_reusejp_1017_;
}
else
{
lean_object* v_reuseFailAlloc_1019_; 
v_reuseFailAlloc_1019_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1019_, 0, v___x_977_);
v___x_1018_ = v_reuseFailAlloc_1019_;
goto v_reusejp_1017_;
}
v_reusejp_1017_:
{
return v___x_1018_;
}
}
}
else
{
lean_object* v_a_1022_; lean_object* v___x_1024_; uint8_t v_isShared_1025_; uint8_t v_isSharedCheck_1029_; 
lean_dec_ref(v___x_977_);
v_a_1022_ = lean_ctor_get(v___x_1013_, 0);
v_isSharedCheck_1029_ = !lean_is_exclusive(v___x_1013_);
if (v_isSharedCheck_1029_ == 0)
{
v___x_1024_ = v___x_1013_;
v_isShared_1025_ = v_isSharedCheck_1029_;
goto v_resetjp_1023_;
}
else
{
lean_inc(v_a_1022_);
lean_dec(v___x_1013_);
v___x_1024_ = lean_box(0);
v_isShared_1025_ = v_isSharedCheck_1029_;
goto v_resetjp_1023_;
}
v_resetjp_1023_:
{
lean_object* v___x_1027_; 
if (v_isShared_1025_ == 0)
{
v___x_1027_ = v___x_1024_;
goto v_reusejp_1026_;
}
else
{
lean_object* v_reuseFailAlloc_1028_; 
v_reuseFailAlloc_1028_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1028_, 0, v_a_1022_);
v___x_1027_ = v_reuseFailAlloc_1028_;
goto v_reusejp_1026_;
}
v_reusejp_1026_:
{
return v___x_1027_;
}
}
}
}
}
}
else
{
lean_object* v_a_1031_; lean_object* v___x_1033_; uint8_t v_isShared_1034_; uint8_t v_isSharedCheck_1038_; 
lean_dec(v___y_959_);
lean_dec(v___y_957_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
v_a_1031_ = lean_ctor_get(v___x_968_, 0);
v_isSharedCheck_1038_ = !lean_is_exclusive(v___x_968_);
if (v_isSharedCheck_1038_ == 0)
{
v___x_1033_ = v___x_968_;
v_isShared_1034_ = v_isSharedCheck_1038_;
goto v_resetjp_1032_;
}
else
{
lean_inc(v_a_1031_);
lean_dec(v___x_968_);
v___x_1033_ = lean_box(0);
v_isShared_1034_ = v_isSharedCheck_1038_;
goto v_resetjp_1032_;
}
v_resetjp_1032_:
{
lean_object* v___x_1036_; 
if (v_isShared_1034_ == 0)
{
v___x_1036_ = v___x_1033_;
goto v_reusejp_1035_;
}
else
{
lean_object* v_reuseFailAlloc_1037_; 
v_reuseFailAlloc_1037_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1037_, 0, v_a_1031_);
v___x_1036_ = v_reuseFailAlloc_1037_;
goto v_reusejp_1035_;
}
v_reusejp_1035_:
{
return v___x_1036_;
}
}
}
}
v___jp_1039_:
{
lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; 
v___x_1047_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__15, &l_Lean_Meta_inferRelationInfo___lam__2___closed__15_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__15);
lean_inc(v___x_944_);
v___x_1048_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1048_, 0, v___x_944_);
lean_ctor_set(v___x_1048_, 1, v___x_1047_);
v___x_1049_ = lean_box(1);
v___x_1050_ = lean_mk_empty_array_with_capacity(v___x_944_);
v___x_1051_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1051_, 0, v___x_1048_);
lean_ctor_set(v___x_1051_, 1, v___x_1049_);
lean_ctor_set(v___x_1051_, 2, v___x_1050_);
v___x_1052_ = l_Lean_instInhabitedExpr;
v___x_1053_ = lean_array_get_borrowed(v___x_1052_, v_xs_949_, v___y_1041_);
lean_inc(v___x_1053_);
lean_inc_ref(v___x_1051_);
v___x_1054_ = l_Lean_collectFVars(v___x_1051_, v___x_1053_);
v___x_1055_ = l_Lean_CollectFVars_State_addDependencies(v___x_1054_, v___y_1043_, v___y_1044_, v___y_1045_, v___y_1046_);
if (lean_obj_tag(v___x_1055_) == 0)
{
lean_object* v_a_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; lean_object* v___x_1059_; 
v_a_1056_ = lean_ctor_get(v___x_1055_, 0);
lean_inc(v_a_1056_);
lean_dec_ref(v___x_1055_);
v___x_1057_ = lean_array_get_borrowed(v___x_1052_, v_xs_949_, v___y_1040_);
lean_inc(v___x_1057_);
v___x_1058_ = l_Lean_collectFVars(v___x_1051_, v___x_1057_);
v___x_1059_ = l_Lean_CollectFVars_State_addDependencies(v___x_1058_, v___y_1043_, v___y_1044_, v___y_1045_, v___y_1046_);
if (lean_obj_tag(v___x_1059_) == 0)
{
lean_object* v_a_1060_; uint8_t v___x_1061_; 
v_a_1060_ = lean_ctor_get(v___x_1059_, 0);
lean_inc(v_a_1060_);
lean_dec_ref(v___x_1059_);
v___x_1061_ = lean_nat_dec_le(v___y_1041_, v___y_1040_);
if (v___x_1061_ == 0)
{
lean_inc(v___y_1040_);
v___y_957_ = v___y_1040_;
v___y_958_ = v_a_1056_;
v___y_959_ = v___y_1041_;
v___y_960_ = v___y_1045_;
v___y_961_ = v___y_1044_;
v___y_962_ = v_a_1060_;
v___y_963_ = v___y_1042_;
v___y_964_ = v___y_1046_;
v___y_965_ = v___y_1043_;
v___y_966_ = v___y_1040_;
goto v___jp_956_;
}
else
{
lean_inc(v___y_1041_);
v___y_957_ = v___y_1040_;
v___y_958_ = v_a_1056_;
v___y_959_ = v___y_1041_;
v___y_960_ = v___y_1045_;
v___y_961_ = v___y_1044_;
v___y_962_ = v_a_1060_;
v___y_963_ = v___y_1042_;
v___y_964_ = v___y_1046_;
v___y_965_ = v___y_1043_;
v___y_966_ = v___y_1041_;
goto v___jp_956_;
}
}
else
{
lean_object* v_a_1062_; lean_object* v___x_1064_; uint8_t v_isShared_1065_; uint8_t v_isSharedCheck_1069_; 
lean_dec(v_a_1056_);
lean_dec(v___y_1041_);
lean_dec(v___y_1040_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v_a_1062_ = lean_ctor_get(v___x_1059_, 0);
v_isSharedCheck_1069_ = !lean_is_exclusive(v___x_1059_);
if (v_isSharedCheck_1069_ == 0)
{
v___x_1064_ = v___x_1059_;
v_isShared_1065_ = v_isSharedCheck_1069_;
goto v_resetjp_1063_;
}
else
{
lean_inc(v_a_1062_);
lean_dec(v___x_1059_);
v___x_1064_ = lean_box(0);
v_isShared_1065_ = v_isSharedCheck_1069_;
goto v_resetjp_1063_;
}
v_resetjp_1063_:
{
lean_object* v___x_1067_; 
if (v_isShared_1065_ == 0)
{
v___x_1067_ = v___x_1064_;
goto v_reusejp_1066_;
}
else
{
lean_object* v_reuseFailAlloc_1068_; 
v_reuseFailAlloc_1068_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1068_, 0, v_a_1062_);
v___x_1067_ = v_reuseFailAlloc_1068_;
goto v_reusejp_1066_;
}
v_reusejp_1066_:
{
return v___x_1067_;
}
}
}
}
else
{
lean_object* v_a_1070_; lean_object* v___x_1072_; uint8_t v_isShared_1073_; uint8_t v_isSharedCheck_1077_; 
lean_dec_ref(v___x_1051_);
lean_dec(v___y_1041_);
lean_dec(v___y_1040_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v_a_1070_ = lean_ctor_get(v___x_1055_, 0);
v_isSharedCheck_1077_ = !lean_is_exclusive(v___x_1055_);
if (v_isSharedCheck_1077_ == 0)
{
v___x_1072_ = v___x_1055_;
v_isShared_1073_ = v_isSharedCheck_1077_;
goto v_resetjp_1071_;
}
else
{
lean_inc(v_a_1070_);
lean_dec(v___x_1055_);
v___x_1072_ = lean_box(0);
v_isShared_1073_ = v_isSharedCheck_1077_;
goto v_resetjp_1071_;
}
v_resetjp_1071_:
{
lean_object* v___x_1075_; 
if (v_isShared_1073_ == 0)
{
v___x_1075_ = v___x_1072_;
goto v_reusejp_1074_;
}
else
{
lean_object* v_reuseFailAlloc_1076_; 
v_reuseFailAlloc_1076_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1076_, 0, v_a_1070_);
v___x_1075_ = v_reuseFailAlloc_1076_;
goto v_reusejp_1074_;
}
v_reusejp_1074_:
{
return v___x_1075_;
}
}
}
}
v___jp_1078_:
{
lean_object* v___x_1084_; lean_object* v___x_1085_; uint8_t v___x_1086_; 
v___x_1084_ = lean_array_get_size(v_operands_1079_);
v___x_1085_ = lean_unsigned_to_nat(2u);
v___x_1086_ = lean_nat_dec_eq(v___x_1084_, v___x_1085_);
if (v___x_1086_ == 0)
{
lean_object* v___x_1087_; lean_object* v___x_1088_; 
lean_dec_ref(v_operands_1079_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v___x_1087_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__19, &l_Lean_Meta_inferRelationInfo___lam__2___closed__19_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__19);
v___x_1088_ = l_panic___at___00Lean_Meta_inferRelationInfo_spec__1(v___x_1087_, v___y_1080_, v___y_1081_, v___y_1082_, v___y_1083_);
return v___x_1088_;
}
else
{
lean_object* v___x_1089_; lean_object* v___x_1090_; lean_object* v___x_1091_; lean_object* v___x_1092_; uint8_t v___x_1093_; 
v___x_1089_ = lean_unsigned_to_nat(0u);
v___x_1090_ = lean_array_get(v___x_1089_, v_operands_1079_, v___x_944_);
v___x_1091_ = lean_unsigned_to_nat(1u);
v___x_1092_ = lean_array_get(v___x_1089_, v_operands_1079_, v___x_1091_);
lean_dec_ref(v_operands_1079_);
v___x_1093_ = lean_nat_dec_eq(v___x_1090_, v___x_1092_);
if (v___x_1093_ == 0)
{
v___y_1040_ = v___x_1092_;
v___y_1041_ = v___x_1090_;
v___y_1042_ = v___x_1091_;
v___y_1043_ = v___y_1080_;
v___y_1044_ = v___y_1081_;
v___y_1045_ = v___y_1082_;
v___y_1046_ = v___y_1083_;
goto v___jp_1039_;
}
else
{
lean_object* v___x_1094_; lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; lean_object* v_a_1103_; lean_object* v___x_1105_; uint8_t v_isShared_1106_; uint8_t v_isSharedCheck_1110_; 
lean_dec(v___x_1092_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v___x_1094_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__21, &l_Lean_Meta_inferRelationInfo___lam__2___closed__21_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__21);
v___x_1095_ = lean_nat_add(v___x_1090_, v___x_1091_);
lean_dec(v___x_1090_);
v___x_1096_ = l_Nat_reprFast(v___x_1095_);
v___x_1097_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1097_, 0, v___x_1096_);
v___x_1098_ = l_Lean_MessageData_ofFormat(v___x_1097_);
v___x_1099_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1099_, 0, v___x_1094_);
lean_ctor_set(v___x_1099_, 1, v___x_1098_);
v___x_1100_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__23, &l_Lean_Meta_inferRelationInfo___lam__2___closed__23_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__23);
v___x_1101_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1101_, 0, v___x_1099_);
lean_ctor_set(v___x_1101_, 1, v___x_1100_);
v___x_1102_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v___x_1101_, v___y_1080_, v___y_1081_, v___y_1082_, v___y_1083_);
v_a_1103_ = lean_ctor_get(v___x_1102_, 0);
v_isSharedCheck_1110_ = !lean_is_exclusive(v___x_1102_);
if (v_isSharedCheck_1110_ == 0)
{
v___x_1105_ = v___x_1102_;
v_isShared_1106_ = v_isSharedCheck_1110_;
goto v_resetjp_1104_;
}
else
{
lean_inc(v_a_1103_);
lean_dec(v___x_1102_);
v___x_1105_ = lean_box(0);
v_isShared_1106_ = v_isSharedCheck_1110_;
goto v_resetjp_1104_;
}
v_resetjp_1104_:
{
lean_object* v___x_1108_; 
if (v_isShared_1106_ == 0)
{
v___x_1108_ = v___x_1105_;
goto v_reusejp_1107_;
}
else
{
lean_object* v_reuseFailAlloc_1109_; 
v_reuseFailAlloc_1109_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1109_, 0, v_a_1103_);
v___x_1108_ = v_reuseFailAlloc_1109_;
goto v_reusejp_1107_;
}
v_reusejp_1107_:
{
return v___x_1108_;
}
}
}
}
}
v___jp_1111_:
{
lean_object* v___x_1119_; lean_object* v___x_1120_; lean_object* v___x_1121_; lean_object* v___x_1122_; lean_object* v___x_1123_; size_t v_sz_1124_; lean_object* v___x_1125_; 
v___x_1119_ = lean_array_get_size(v___y_1112_);
v___x_1120_ = lean_nat_sub(v___x_1119_, v___y_1114_);
v___x_1121_ = l_Array_toSubarray___redArg(v___y_1112_, v___x_1120_, v___x_1119_);
v___x_1122_ = lean_mk_empty_array_with_capacity(v___x_944_);
v___x_1123_ = l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13___redArg(v___x_1121_, v___x_1122_);
v_sz_1124_ = lean_array_size(v___x_1123_);
v___x_1125_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__14(v_sz_1124_, v___y_1113_, v___x_1123_);
v_operands_1079_ = v___x_1125_;
v___y_1080_ = v___y_1115_;
v___y_1081_ = v___y_1116_;
v___y_1082_ = v___y_1117_;
v___y_1083_ = v___y_1118_;
goto v___jp_1078_;
}
v___jp_1126_:
{
lean_object* v___x_1134_; uint8_t v___x_1135_; 
v___x_1134_ = lean_array_get_size(v___y_1133_);
v___x_1135_ = lean_nat_dec_lt(v___x_1134_, v___y_1132_);
if (v___x_1135_ == 0)
{
v___y_1112_ = v___y_1133_;
v___y_1113_ = v___y_1129_;
v___y_1114_ = v___y_1132_;
v___y_1115_ = v___y_1131_;
v___y_1116_ = v___y_1128_;
v___y_1117_ = v___y_1130_;
v___y_1118_ = v___y_1127_;
goto v___jp_1111_;
}
else
{
lean_object* v___x_1136_; uint8_t v___x_1137_; lean_object* v___x_1138_; lean_object* v___x_1139_; lean_object* v___x_1140_; lean_object* v___x_1141_; lean_object* v___x_1142_; lean_object* v_a_1143_; lean_object* v___x_1145_; uint8_t v_isShared_1146_; uint8_t v_isSharedCheck_1150_; 
lean_dec_ref(v___y_1133_);
lean_dec_ref(v_xs_949_);
lean_dec(v___x_944_);
v___x_1136_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__25, &l_Lean_Meta_inferRelationInfo___lam__2___closed__25_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__25);
v___x_1137_ = 0;
v___x_1138_ = l_Lean_MessageData_ofConstName(v_declName_945_, v___x_1137_);
v___x_1139_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1139_, 0, v___x_1136_);
lean_ctor_set(v___x_1139_, 1, v___x_1138_);
v___x_1140_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__27, &l_Lean_Meta_inferRelationInfo___lam__2___closed__27_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__27);
v___x_1141_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1141_, 0, v___x_1139_);
lean_ctor_set(v___x_1141_, 1, v___x_1140_);
v___x_1142_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v___x_1141_, v___y_1131_, v___y_1128_, v___y_1130_, v___y_1127_);
v_a_1143_ = lean_ctor_get(v___x_1142_, 0);
v_isSharedCheck_1150_ = !lean_is_exclusive(v___x_1142_);
if (v_isSharedCheck_1150_ == 0)
{
v___x_1145_ = v___x_1142_;
v_isShared_1146_ = v_isSharedCheck_1150_;
goto v_resetjp_1144_;
}
else
{
lean_inc(v_a_1143_);
lean_dec(v___x_1142_);
v___x_1145_ = lean_box(0);
v_isShared_1146_ = v_isSharedCheck_1150_;
goto v_resetjp_1144_;
}
v_resetjp_1144_:
{
lean_object* v___x_1148_; 
if (v_isShared_1146_ == 0)
{
v___x_1148_ = v___x_1145_;
goto v_reusejp_1147_;
}
else
{
lean_object* v_reuseFailAlloc_1149_; 
v_reuseFailAlloc_1149_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1149_, 0, v_a_1143_);
v___x_1148_ = v_reuseFailAlloc_1149_;
goto v_reusejp_1147_;
}
v_reusejp_1147_:
{
return v___x_1148_;
}
}
}
}
v___jp_1151_:
{
size_t v_sz_1156_; size_t v___x_1157_; lean_object* v___x_1158_; 
v_sz_1156_ = lean_array_size(v_xs_949_);
v___x_1157_ = ((size_t)0ULL);
lean_inc_ref(v_xs_949_);
v___x_1158_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg(v_sz_1156_, v___x_1157_, v_xs_949_, v___y_1152_, v___y_1154_, v___y_1155_);
if (lean_obj_tag(v___x_1158_) == 0)
{
lean_object* v_a_1159_; lean_object* v___x_1160_; 
v_a_1159_ = lean_ctor_get(v___x_1158_, 0);
lean_inc(v_a_1159_);
lean_dec_ref(v___x_1158_);
lean_inc_ref(v_xs_949_);
v___x_1160_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg(v_sz_1156_, v___x_1157_, v_xs_949_, v___y_1152_, v___y_1154_, v___y_1155_);
if (lean_obj_tag(v___x_1160_) == 0)
{
lean_object* v_a_1161_; lean_object* v___x_1162_; size_t v_sz_1163_; lean_object* v___x_1164_; 
v_a_1161_ = lean_ctor_get(v___x_1160_, 0);
lean_inc(v_a_1161_);
lean_dec_ref(v___x_1160_);
v___x_1162_ = lean_mk_empty_array_with_capacity(v___x_944_);
v_sz_1163_ = lean_array_size(v_args_946_);
lean_inc_ref(v___x_1162_);
lean_inc(v_declName_945_);
v___x_1164_ = l___private_Init_Data_Array_Basic_0__Array_forIn_x27Unsafe_loop___at___00Lean_Meta_inferRelationInfo_spec__12(v_a_1159_, v_declName_945_, v_args_946_, v_sz_1163_, v___x_1157_, v___x_1162_, v___y_1152_, v___y_1153_, v___y_1154_, v___y_1155_);
lean_dec(v_a_1159_);
if (lean_obj_tag(v___x_1164_) == 0)
{
lean_object* v_a_1165_; lean_object* v___x_1166_; lean_object* v___x_1167_; uint8_t v___x_1168_; 
v_a_1165_ = lean_ctor_get(v___x_1164_, 0);
lean_inc(v_a_1165_);
lean_dec_ref(v___x_1164_);
v___x_1166_ = lean_array_get_size(v_a_1165_);
v___x_1167_ = lean_unsigned_to_nat(2u);
v___x_1168_ = lean_nat_dec_lt(v___x_1166_, v___x_1167_);
if (v___x_1168_ == 0)
{
lean_dec_ref(v___x_1162_);
lean_dec(v_a_1161_);
v_operands_1079_ = v_a_1165_;
v___y_1080_ = v___y_1152_;
v___y_1081_ = v___y_1153_;
v___y_1082_ = v___y_1154_;
v___y_1083_ = v___y_1155_;
goto v___jp_1078_;
}
else
{
lean_object* v___x_1169_; lean_object* v___x_1170_; uint8_t v___x_1171_; 
lean_dec(v_a_1165_);
v___x_1169_ = l_Array_zipIdx___redArg(v_a_1161_, v___x_944_);
lean_dec(v_a_1161_);
v___x_1170_ = lean_array_get_size(v___x_1169_);
v___x_1171_ = lean_nat_dec_lt(v___x_944_, v___x_1170_);
if (v___x_1171_ == 0)
{
lean_dec_ref(v___x_1169_);
v___y_1127_ = v___y_1155_;
v___y_1128_ = v___y_1153_;
v___y_1129_ = v___x_1157_;
v___y_1130_ = v___y_1154_;
v___y_1131_ = v___y_1152_;
v___y_1132_ = v___x_1167_;
v___y_1133_ = v___x_1162_;
goto v___jp_1126_;
}
else
{
uint8_t v___x_1172_; 
v___x_1172_ = lean_nat_dec_le(v___x_1170_, v___x_1170_);
if (v___x_1172_ == 0)
{
if (v___x_1171_ == 0)
{
lean_dec_ref(v___x_1169_);
v___y_1127_ = v___y_1155_;
v___y_1128_ = v___y_1153_;
v___y_1129_ = v___x_1157_;
v___y_1130_ = v___y_1154_;
v___y_1131_ = v___y_1152_;
v___y_1132_ = v___x_1167_;
v___y_1133_ = v___x_1162_;
goto v___jp_1126_;
}
else
{
size_t v___x_1173_; lean_object* v___x_1174_; 
v___x_1173_ = lean_usize_of_nat(v___x_1170_);
v___x_1174_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15(v___x_1169_, v___x_1157_, v___x_1173_, v___x_1162_);
lean_dec_ref(v___x_1169_);
v___y_1127_ = v___y_1155_;
v___y_1128_ = v___y_1153_;
v___y_1129_ = v___x_1157_;
v___y_1130_ = v___y_1154_;
v___y_1131_ = v___y_1152_;
v___y_1132_ = v___x_1167_;
v___y_1133_ = v___x_1174_;
goto v___jp_1126_;
}
}
else
{
size_t v___x_1175_; lean_object* v___x_1176_; 
v___x_1175_ = lean_usize_of_nat(v___x_1170_);
v___x_1176_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Meta_inferRelationInfo_spec__15(v___x_1169_, v___x_1157_, v___x_1175_, v___x_1162_);
lean_dec_ref(v___x_1169_);
v___y_1127_ = v___y_1155_;
v___y_1128_ = v___y_1153_;
v___y_1129_ = v___x_1157_;
v___y_1130_ = v___y_1154_;
v___y_1131_ = v___y_1152_;
v___y_1132_ = v___x_1167_;
v___y_1133_ = v___x_1176_;
goto v___jp_1126_;
}
}
}
}
else
{
lean_object* v_a_1177_; lean_object* v___x_1179_; uint8_t v_isShared_1180_; uint8_t v_isSharedCheck_1184_; 
lean_dec_ref(v___x_1162_);
lean_dec(v_a_1161_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v_a_1177_ = lean_ctor_get(v___x_1164_, 0);
v_isSharedCheck_1184_ = !lean_is_exclusive(v___x_1164_);
if (v_isSharedCheck_1184_ == 0)
{
v___x_1179_ = v___x_1164_;
v_isShared_1180_ = v_isSharedCheck_1184_;
goto v_resetjp_1178_;
}
else
{
lean_inc(v_a_1177_);
lean_dec(v___x_1164_);
v___x_1179_ = lean_box(0);
v_isShared_1180_ = v_isSharedCheck_1184_;
goto v_resetjp_1178_;
}
v_resetjp_1178_:
{
lean_object* v___x_1182_; 
if (v_isShared_1180_ == 0)
{
v___x_1182_ = v___x_1179_;
goto v_reusejp_1181_;
}
else
{
lean_object* v_reuseFailAlloc_1183_; 
v_reuseFailAlloc_1183_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1183_, 0, v_a_1177_);
v___x_1182_ = v_reuseFailAlloc_1183_;
goto v_reusejp_1181_;
}
v_reusejp_1181_:
{
return v___x_1182_;
}
}
}
}
else
{
lean_object* v_a_1185_; lean_object* v___x_1187_; uint8_t v_isShared_1188_; uint8_t v_isSharedCheck_1192_; 
lean_dec(v_a_1159_);
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v_a_1185_ = lean_ctor_get(v___x_1160_, 0);
v_isSharedCheck_1192_ = !lean_is_exclusive(v___x_1160_);
if (v_isSharedCheck_1192_ == 0)
{
v___x_1187_ = v___x_1160_;
v_isShared_1188_ = v_isSharedCheck_1192_;
goto v_resetjp_1186_;
}
else
{
lean_inc(v_a_1185_);
lean_dec(v___x_1160_);
v___x_1187_ = lean_box(0);
v_isShared_1188_ = v_isSharedCheck_1192_;
goto v_resetjp_1186_;
}
v_resetjp_1186_:
{
lean_object* v___x_1190_; 
if (v_isShared_1188_ == 0)
{
v___x_1190_ = v___x_1187_;
goto v_reusejp_1189_;
}
else
{
lean_object* v_reuseFailAlloc_1191_; 
v_reuseFailAlloc_1191_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1191_, 0, v_a_1185_);
v___x_1190_ = v_reuseFailAlloc_1191_;
goto v_reusejp_1189_;
}
v_reusejp_1189_:
{
return v___x_1190_;
}
}
}
}
else
{
lean_object* v_a_1193_; lean_object* v___x_1195_; uint8_t v_isShared_1196_; uint8_t v_isSharedCheck_1200_; 
lean_dec_ref(v_xs_949_);
lean_dec(v_declName_945_);
lean_dec(v___x_944_);
v_a_1193_ = lean_ctor_get(v___x_1158_, 0);
v_isSharedCheck_1200_ = !lean_is_exclusive(v___x_1158_);
if (v_isSharedCheck_1200_ == 0)
{
v___x_1195_ = v___x_1158_;
v_isShared_1196_ = v_isSharedCheck_1200_;
goto v_resetjp_1194_;
}
else
{
lean_inc(v_a_1193_);
lean_dec(v___x_1158_);
v___x_1195_ = lean_box(0);
v_isShared_1196_ = v_isSharedCheck_1200_;
goto v_resetjp_1194_;
}
v_resetjp_1194_:
{
lean_object* v___x_1198_; 
if (v_isShared_1196_ == 0)
{
v___x_1198_ = v___x_1195_;
goto v_reusejp_1197_;
}
else
{
lean_object* v_reuseFailAlloc_1199_; 
v_reuseFailAlloc_1199_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1199_, 0, v_a_1193_);
v___x_1198_ = v_reuseFailAlloc_1199_;
goto v_reusejp_1197_;
}
v_reusejp_1197_:
{
return v___x_1198_;
}
}
}
}
v___jp_1202_:
{
lean_object* v___x_1205_; lean_object* v_cache_1206_; lean_object* v_zetaDeltaFVarIds_1207_; lean_object* v_postponed_1208_; lean_object* v_diag_1209_; lean_object* v___x_1211_; uint8_t v_isShared_1212_; uint8_t v_isSharedCheck_1237_; 
v___x_1205_ = lean_st_ref_take(v___y_952_);
v_cache_1206_ = lean_ctor_get(v___x_1205_, 1);
v_zetaDeltaFVarIds_1207_ = lean_ctor_get(v___x_1205_, 2);
v_postponed_1208_ = lean_ctor_get(v___x_1205_, 3);
v_diag_1209_ = lean_ctor_get(v___x_1205_, 4);
v_isSharedCheck_1237_ = !lean_is_exclusive(v___x_1205_);
if (v_isSharedCheck_1237_ == 0)
{
lean_object* v_unused_1238_; 
v_unused_1238_ = lean_ctor_get(v___x_1205_, 0);
lean_dec(v_unused_1238_);
v___x_1211_ = v___x_1205_;
v_isShared_1212_ = v_isSharedCheck_1237_;
goto v_resetjp_1210_;
}
else
{
lean_inc(v_diag_1209_);
lean_inc(v_postponed_1208_);
lean_inc(v_zetaDeltaFVarIds_1207_);
lean_inc(v_cache_1206_);
lean_dec(v___x_1205_);
v___x_1211_ = lean_box(0);
v_isShared_1212_ = v_isSharedCheck_1237_;
goto v_resetjp_1210_;
}
v_resetjp_1210_:
{
lean_object* v___x_1214_; 
if (v_isShared_1212_ == 0)
{
lean_ctor_set(v___x_1211_, 0, v_mctx_1204_);
v___x_1214_ = v___x_1211_;
goto v_reusejp_1213_;
}
else
{
lean_object* v_reuseFailAlloc_1236_; 
v_reuseFailAlloc_1236_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_1236_, 0, v_mctx_1204_);
lean_ctor_set(v_reuseFailAlloc_1236_, 1, v_cache_1206_);
lean_ctor_set(v_reuseFailAlloc_1236_, 2, v_zetaDeltaFVarIds_1207_);
lean_ctor_set(v_reuseFailAlloc_1236_, 3, v_postponed_1208_);
lean_ctor_set(v_reuseFailAlloc_1236_, 4, v_diag_1209_);
v___x_1214_ = v_reuseFailAlloc_1236_;
goto v_reusejp_1213_;
}
v_reusejp_1213_:
{
lean_object* v___x_1215_; 
v___x_1215_ = lean_st_ref_set(v___y_952_, v___x_1214_);
if (v_fst_1203_ == 0)
{
lean_dec_ref(v_ty_950_);
v___y_1152_ = v___y_951_;
v___y_1153_ = v___y_952_;
v___y_1154_ = v___y_953_;
v___y_1155_ = v___y_954_;
goto v___jp_1151_;
}
else
{
lean_object* v___x_1216_; lean_object* v___x_1217_; lean_object* v___x_1218_; lean_object* v___x_1219_; lean_object* v___x_1220_; lean_object* v___x_1221_; uint8_t v___x_1222_; lean_object* v___x_1223_; lean_object* v___x_1224_; lean_object* v___x_1225_; lean_object* v___x_1226_; lean_object* v___x_1227_; lean_object* v_a_1228_; lean_object* v___x_1230_; uint8_t v_isShared_1231_; uint8_t v_isSharedCheck_1235_; 
lean_dec_ref(v_xs_949_);
lean_dec(v___x_944_);
v___x_1216_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__29, &l_Lean_Meta_inferRelationInfo___lam__2___closed__29_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__29);
v___x_1217_ = lean_unsigned_to_nat(30u);
v___x_1218_ = l_Lean_inlineExpr(v_ty_950_, v___x_1217_);
v___x_1219_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1219_, 0, v___x_1216_);
lean_ctor_set(v___x_1219_, 1, v___x_1218_);
v___x_1220_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__31, &l_Lean_Meta_inferRelationInfo___lam__2___closed__31_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__31);
v___x_1221_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1221_, 0, v___x_1219_);
lean_ctor_set(v___x_1221_, 1, v___x_1220_);
v___x_1222_ = 0;
v___x_1223_ = l_Lean_MessageData_ofConstName(v_declName_945_, v___x_1222_);
v___x_1224_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1224_, 0, v___x_1221_);
lean_ctor_set(v___x_1224_, 1, v___x_1223_);
v___x_1225_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___lam__2___closed__33, &l_Lean_Meta_inferRelationInfo___lam__2___closed__33_once, _init_l_Lean_Meta_inferRelationInfo___lam__2___closed__33);
v___x_1226_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1226_, 0, v___x_1224_);
lean_ctor_set(v___x_1226_, 1, v___x_1225_);
v___x_1227_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v___x_1226_, v___y_951_, v___y_952_, v___y_953_, v___y_954_);
v_a_1228_ = lean_ctor_get(v___x_1227_, 0);
v_isSharedCheck_1235_ = !lean_is_exclusive(v___x_1227_);
if (v_isSharedCheck_1235_ == 0)
{
v___x_1230_ = v___x_1227_;
v_isShared_1231_ = v_isSharedCheck_1235_;
goto v_resetjp_1229_;
}
else
{
lean_inc(v_a_1228_);
lean_dec(v___x_1227_);
v___x_1230_ = lean_box(0);
v_isShared_1231_ = v_isSharedCheck_1235_;
goto v_resetjp_1229_;
}
v_resetjp_1229_:
{
lean_object* v___x_1233_; 
if (v_isShared_1231_ == 0)
{
v___x_1233_ = v___x_1230_;
goto v_reusejp_1232_;
}
else
{
lean_object* v_reuseFailAlloc_1234_; 
v_reuseFailAlloc_1234_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1234_, 0, v_a_1228_);
v___x_1233_ = v_reuseFailAlloc_1234_;
goto v_reusejp_1232_;
}
v_reusejp_1232_:
{
return v___x_1233_;
}
}
}
}
}
}
v___jp_1239_:
{
lean_object* v_snd_1241_; lean_object* v_fst_1242_; lean_object* v_mctx_1243_; uint8_t v___x_1244_; 
v_snd_1241_ = lean_ctor_get(v___y_1240_, 1);
lean_inc(v_snd_1241_);
v_fst_1242_ = lean_ctor_get(v___y_1240_, 0);
lean_inc(v_fst_1242_);
lean_dec_ref(v___y_1240_);
v_mctx_1243_ = lean_ctor_get(v_snd_1241_, 1);
lean_inc_ref(v_mctx_1243_);
lean_dec(v_snd_1241_);
v___x_1244_ = lean_unbox(v_fst_1242_);
lean_dec(v_fst_1242_);
v_fst_1203_ = v___x_1244_;
v_mctx_1204_ = v_mctx_1243_;
goto v___jp_1202_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___lam__2___boxed(lean_object* v___x_1253_, lean_object* v_declName_1254_, lean_object* v_args_1255_, lean_object* v___f_1256_, lean_object* v___f_1257_, lean_object* v_xs_1258_, lean_object* v_ty_1259_, lean_object* v___y_1260_, lean_object* v___y_1261_, lean_object* v___y_1262_, lean_object* v___y_1263_, lean_object* v___y_1264_){
_start:
{
lean_object* v_res_1265_; 
v_res_1265_ = l_Lean_Meta_inferRelationInfo___lam__2(v___x_1253_, v_declName_1254_, v_args_1255_, v___f_1256_, v___f_1257_, v_xs_1258_, v_ty_1259_, v___y_1260_, v___y_1261_, v___y_1262_, v___y_1263_);
lean_dec(v___y_1263_);
lean_dec_ref(v___y_1262_);
lean_dec(v___y_1261_);
lean_dec_ref(v___y_1260_);
lean_dec_ref(v_args_1255_);
return v_res_1265_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0(void){
_start:
{
lean_object* v___x_1266_; 
v___x_1266_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_1266_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1(void){
_start:
{
lean_object* v___x_1267_; lean_object* v___x_1268_; 
v___x_1267_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__0);
v___x_1268_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1268_, 0, v___x_1267_);
return v___x_1268_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2(void){
_start:
{
lean_object* v___x_1269_; lean_object* v___x_1270_; lean_object* v___x_1271_; 
v___x_1269_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1);
v___x_1270_ = lean_unsigned_to_nat(0u);
v___x_1271_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_1271_, 0, v___x_1270_);
lean_ctor_set(v___x_1271_, 1, v___x_1270_);
lean_ctor_set(v___x_1271_, 2, v___x_1270_);
lean_ctor_set(v___x_1271_, 3, v___x_1269_);
lean_ctor_set(v___x_1271_, 4, v___x_1269_);
lean_ctor_set(v___x_1271_, 5, v___x_1269_);
lean_ctor_set(v___x_1271_, 6, v___x_1269_);
lean_ctor_set(v___x_1271_, 7, v___x_1269_);
lean_ctor_set(v___x_1271_, 8, v___x_1269_);
return v___x_1271_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3(void){
_start:
{
lean_object* v___x_1272_; lean_object* v___x_1273_; lean_object* v___x_1274_; 
v___x_1272_ = lean_unsigned_to_nat(32u);
v___x_1273_ = lean_mk_empty_array_with_capacity(v___x_1272_);
v___x_1274_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1274_, 0, v___x_1273_);
return v___x_1274_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4(void){
_start:
{
size_t v___x_1275_; lean_object* v___x_1276_; lean_object* v___x_1277_; lean_object* v___x_1278_; lean_object* v___x_1279_; lean_object* v___x_1280_; 
v___x_1275_ = ((size_t)5ULL);
v___x_1276_ = lean_unsigned_to_nat(0u);
v___x_1277_ = lean_unsigned_to_nat(32u);
v___x_1278_ = lean_mk_empty_array_with_capacity(v___x_1277_);
v___x_1279_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3);
v___x_1280_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_1280_, 0, v___x_1279_);
lean_ctor_set(v___x_1280_, 1, v___x_1278_);
lean_ctor_set(v___x_1280_, 2, v___x_1276_);
lean_ctor_set(v___x_1280_, 3, v___x_1276_);
lean_ctor_set_usize(v___x_1280_, 4, v___x_1275_);
return v___x_1280_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5(void){
_start:
{
lean_object* v___x_1281_; lean_object* v___x_1282_; lean_object* v___x_1283_; lean_object* v___x_1284_; 
v___x_1281_ = lean_box(1);
v___x_1282_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4);
v___x_1283_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__1);
v___x_1284_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1284_, 0, v___x_1283_);
lean_ctor_set(v___x_1284_, 1, v___x_1282_);
lean_ctor_set(v___x_1284_, 2, v___x_1281_);
return v___x_1284_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7(void){
_start:
{
lean_object* v___x_1286_; lean_object* v___x_1287_; 
v___x_1286_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__6));
v___x_1287_ = l_Lean_stringToMessageData(v___x_1286_);
return v___x_1287_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9(void){
_start:
{
lean_object* v___x_1289_; lean_object* v___x_1290_; 
v___x_1289_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__8));
v___x_1290_ = l_Lean_stringToMessageData(v___x_1289_);
return v___x_1290_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11(void){
_start:
{
lean_object* v___x_1292_; lean_object* v___x_1293_; 
v___x_1292_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__10));
v___x_1293_ = l_Lean_stringToMessageData(v___x_1292_);
return v___x_1293_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13(void){
_start:
{
lean_object* v___x_1295_; lean_object* v___x_1296_; 
v___x_1295_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__12));
v___x_1296_ = l_Lean_stringToMessageData(v___x_1295_);
return v___x_1296_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15(void){
_start:
{
lean_object* v___x_1298_; lean_object* v___x_1299_; 
v___x_1298_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__14));
v___x_1299_ = l_Lean_stringToMessageData(v___x_1298_);
return v___x_1299_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17(void){
_start:
{
lean_object* v___x_1301_; lean_object* v___x_1302_; 
v___x_1301_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__16));
v___x_1302_ = l_Lean_stringToMessageData(v___x_1301_);
return v___x_1302_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19(void){
_start:
{
lean_object* v___x_1304_; lean_object* v___x_1305_; 
v___x_1304_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__18));
v___x_1305_ = l_Lean_stringToMessageData(v___x_1304_);
return v___x_1305_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg(lean_object* v_msg_1306_, lean_object* v_declHint_1307_, lean_object* v___y_1308_){
_start:
{
lean_object* v___x_1310_; lean_object* v_env_1311_; uint8_t v___x_1312_; 
v___x_1310_ = lean_st_ref_get(v___y_1308_);
v_env_1311_ = lean_ctor_get(v___x_1310_, 0);
lean_inc_ref(v_env_1311_);
lean_dec(v___x_1310_);
v___x_1312_ = l_Lean_Name_isAnonymous(v_declHint_1307_);
if (v___x_1312_ == 0)
{
uint8_t v_isExporting_1313_; 
v_isExporting_1313_ = lean_ctor_get_uint8(v_env_1311_, sizeof(void*)*8);
if (v_isExporting_1313_ == 0)
{
lean_object* v___x_1314_; 
lean_dec_ref(v_env_1311_);
lean_dec(v_declHint_1307_);
v___x_1314_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1314_, 0, v_msg_1306_);
return v___x_1314_;
}
else
{
lean_object* v___x_1315_; uint8_t v___x_1316_; 
lean_inc_ref(v_env_1311_);
v___x_1315_ = l_Lean_Environment_setExporting(v_env_1311_, v___x_1312_);
lean_inc(v_declHint_1307_);
lean_inc_ref(v___x_1315_);
v___x_1316_ = l_Lean_Environment_contains(v___x_1315_, v_declHint_1307_, v_isExporting_1313_);
if (v___x_1316_ == 0)
{
lean_object* v___x_1317_; 
lean_dec_ref(v___x_1315_);
lean_dec_ref(v_env_1311_);
lean_dec(v_declHint_1307_);
v___x_1317_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1317_, 0, v_msg_1306_);
return v___x_1317_;
}
else
{
lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v_c_1323_; lean_object* v___x_1324_; 
v___x_1318_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2);
v___x_1319_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5);
v___x_1320_ = l_Lean_Options_empty;
v___x_1321_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1321_, 0, v___x_1315_);
lean_ctor_set(v___x_1321_, 1, v___x_1318_);
lean_ctor_set(v___x_1321_, 2, v___x_1319_);
lean_ctor_set(v___x_1321_, 3, v___x_1320_);
lean_inc(v_declHint_1307_);
v___x_1322_ = l_Lean_MessageData_ofConstName(v_declHint_1307_, v___x_1312_);
v_c_1323_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v_c_1323_, 0, v___x_1321_);
lean_ctor_set(v_c_1323_, 1, v___x_1322_);
v___x_1324_ = l_Lean_Environment_getModuleIdxFor_x3f(v_env_1311_, v_declHint_1307_);
if (lean_obj_tag(v___x_1324_) == 0)
{
lean_object* v___x_1325_; lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; lean_object* v___x_1329_; lean_object* v___x_1330_; lean_object* v___x_1331_; 
lean_dec_ref(v_env_1311_);
lean_dec(v_declHint_1307_);
v___x_1325_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7);
v___x_1326_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1326_, 0, v___x_1325_);
lean_ctor_set(v___x_1326_, 1, v_c_1323_);
v___x_1327_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__9);
v___x_1328_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1328_, 0, v___x_1326_);
lean_ctor_set(v___x_1328_, 1, v___x_1327_);
v___x_1329_ = l_Lean_MessageData_note(v___x_1328_);
v___x_1330_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1330_, 0, v_msg_1306_);
lean_ctor_set(v___x_1330_, 1, v___x_1329_);
v___x_1331_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1331_, 0, v___x_1330_);
return v___x_1331_;
}
else
{
lean_object* v_val_1332_; lean_object* v___x_1334_; uint8_t v_isShared_1335_; uint8_t v_isSharedCheck_1367_; 
v_val_1332_ = lean_ctor_get(v___x_1324_, 0);
v_isSharedCheck_1367_ = !lean_is_exclusive(v___x_1324_);
if (v_isSharedCheck_1367_ == 0)
{
v___x_1334_ = v___x_1324_;
v_isShared_1335_ = v_isSharedCheck_1367_;
goto v_resetjp_1333_;
}
else
{
lean_inc(v_val_1332_);
lean_dec(v___x_1324_);
v___x_1334_ = lean_box(0);
v_isShared_1335_ = v_isSharedCheck_1367_;
goto v_resetjp_1333_;
}
v_resetjp_1333_:
{
lean_object* v___x_1336_; lean_object* v___x_1337_; lean_object* v___x_1338_; lean_object* v_mod_1339_; uint8_t v___x_1340_; 
v___x_1336_ = lean_box(0);
v___x_1337_ = l_Lean_Environment_header(v_env_1311_);
lean_dec_ref(v_env_1311_);
v___x_1338_ = l_Lean_EnvironmentHeader_moduleNames(v___x_1337_);
v_mod_1339_ = lean_array_get(v___x_1336_, v___x_1338_, v_val_1332_);
lean_dec(v_val_1332_);
lean_dec_ref(v___x_1338_);
v___x_1340_ = l_Lean_isPrivateName(v_declHint_1307_);
lean_dec(v_declHint_1307_);
if (v___x_1340_ == 0)
{
lean_object* v___x_1341_; lean_object* v___x_1342_; lean_object* v___x_1343_; lean_object* v___x_1344_; lean_object* v___x_1345_; lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1348_; lean_object* v___x_1349_; lean_object* v___x_1350_; lean_object* v___x_1352_; 
v___x_1341_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__11);
v___x_1342_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1342_, 0, v___x_1341_);
lean_ctor_set(v___x_1342_, 1, v_c_1323_);
v___x_1343_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__13);
v___x_1344_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1344_, 0, v___x_1342_);
lean_ctor_set(v___x_1344_, 1, v___x_1343_);
v___x_1345_ = l_Lean_MessageData_ofName(v_mod_1339_);
v___x_1346_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1346_, 0, v___x_1344_);
lean_ctor_set(v___x_1346_, 1, v___x_1345_);
v___x_1347_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__15);
v___x_1348_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1348_, 0, v___x_1346_);
lean_ctor_set(v___x_1348_, 1, v___x_1347_);
v___x_1349_ = l_Lean_MessageData_note(v___x_1348_);
v___x_1350_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1350_, 0, v_msg_1306_);
lean_ctor_set(v___x_1350_, 1, v___x_1349_);
if (v_isShared_1335_ == 0)
{
lean_ctor_set_tag(v___x_1334_, 0);
lean_ctor_set(v___x_1334_, 0, v___x_1350_);
v___x_1352_ = v___x_1334_;
goto v_reusejp_1351_;
}
else
{
lean_object* v_reuseFailAlloc_1353_; 
v_reuseFailAlloc_1353_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1353_, 0, v___x_1350_);
v___x_1352_ = v_reuseFailAlloc_1353_;
goto v_reusejp_1351_;
}
v_reusejp_1351_:
{
return v___x_1352_;
}
}
else
{
lean_object* v___x_1354_; lean_object* v___x_1355_; lean_object* v___x_1356_; lean_object* v___x_1357_; lean_object* v___x_1358_; lean_object* v___x_1359_; lean_object* v___x_1360_; lean_object* v___x_1361_; lean_object* v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1365_; 
v___x_1354_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__7);
v___x_1355_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1355_, 0, v___x_1354_);
lean_ctor_set(v___x_1355_, 1, v_c_1323_);
v___x_1356_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__17);
v___x_1357_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1357_, 0, v___x_1355_);
lean_ctor_set(v___x_1357_, 1, v___x_1356_);
v___x_1358_ = l_Lean_MessageData_ofName(v_mod_1339_);
v___x_1359_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1359_, 0, v___x_1357_);
lean_ctor_set(v___x_1359_, 1, v___x_1358_);
v___x_1360_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__19);
v___x_1361_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1361_, 0, v___x_1359_);
lean_ctor_set(v___x_1361_, 1, v___x_1360_);
v___x_1362_ = l_Lean_MessageData_note(v___x_1361_);
v___x_1363_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1363_, 0, v_msg_1306_);
lean_ctor_set(v___x_1363_, 1, v___x_1362_);
if (v_isShared_1335_ == 0)
{
lean_ctor_set_tag(v___x_1334_, 0);
lean_ctor_set(v___x_1334_, 0, v___x_1363_);
v___x_1365_ = v___x_1334_;
goto v_reusejp_1364_;
}
else
{
lean_object* v_reuseFailAlloc_1366_; 
v_reuseFailAlloc_1366_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1366_, 0, v___x_1363_);
v___x_1365_ = v_reuseFailAlloc_1366_;
goto v_reusejp_1364_;
}
v_reusejp_1364_:
{
return v___x_1365_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_1368_; 
lean_dec_ref(v_env_1311_);
lean_dec(v_declHint_1307_);
v___x_1368_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1368_, 0, v_msg_1306_);
return v___x_1368_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___boxed(lean_object* v_msg_1369_, lean_object* v_declHint_1370_, lean_object* v___y_1371_, lean_object* v___y_1372_){
_start:
{
lean_object* v_res_1373_; 
v_res_1373_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg(v_msg_1369_, v_declHint_1370_, v___y_1371_);
lean_dec(v___y_1371_);
return v_res_1373_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23(lean_object* v_msg_1374_, lean_object* v_declHint_1375_, lean_object* v___y_1376_, lean_object* v___y_1377_, lean_object* v___y_1378_, lean_object* v___y_1379_){
_start:
{
lean_object* v___x_1381_; lean_object* v_a_1382_; lean_object* v___x_1384_; uint8_t v_isShared_1385_; uint8_t v_isSharedCheck_1391_; 
v___x_1381_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg(v_msg_1374_, v_declHint_1375_, v___y_1379_);
v_a_1382_ = lean_ctor_get(v___x_1381_, 0);
v_isSharedCheck_1391_ = !lean_is_exclusive(v___x_1381_);
if (v_isSharedCheck_1391_ == 0)
{
v___x_1384_ = v___x_1381_;
v_isShared_1385_ = v_isSharedCheck_1391_;
goto v_resetjp_1383_;
}
else
{
lean_inc(v_a_1382_);
lean_dec(v___x_1381_);
v___x_1384_ = lean_box(0);
v_isShared_1385_ = v_isSharedCheck_1391_;
goto v_resetjp_1383_;
}
v_resetjp_1383_:
{
lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1389_; 
v___x_1386_ = l_Lean_unknownIdentifierMessageTag;
v___x_1387_ = lean_alloc_ctor(8, 2, 0);
lean_ctor_set(v___x_1387_, 0, v___x_1386_);
lean_ctor_set(v___x_1387_, 1, v_a_1382_);
if (v_isShared_1385_ == 0)
{
lean_ctor_set(v___x_1384_, 0, v___x_1387_);
v___x_1389_ = v___x_1384_;
goto v_reusejp_1388_;
}
else
{
lean_object* v_reuseFailAlloc_1390_; 
v_reuseFailAlloc_1390_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1390_, 0, v___x_1387_);
v___x_1389_ = v_reuseFailAlloc_1390_;
goto v_reusejp_1388_;
}
v_reusejp_1388_:
{
return v___x_1389_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23___boxed(lean_object* v_msg_1392_, lean_object* v_declHint_1393_, lean_object* v___y_1394_, lean_object* v___y_1395_, lean_object* v___y_1396_, lean_object* v___y_1397_, lean_object* v___y_1398_){
_start:
{
lean_object* v_res_1399_; 
v_res_1399_ = l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23(v_msg_1392_, v_declHint_1393_, v___y_1394_, v___y_1395_, v___y_1396_, v___y_1397_);
lean_dec(v___y_1397_);
lean_dec_ref(v___y_1396_);
lean_dec(v___y_1395_);
lean_dec_ref(v___y_1394_);
return v_res_1399_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg(lean_object* v_ref_1400_, lean_object* v_msg_1401_, lean_object* v_declHint_1402_, lean_object* v___y_1403_, lean_object* v___y_1404_, lean_object* v___y_1405_, lean_object* v___y_1406_){
_start:
{
lean_object* v___x_1408_; lean_object* v_a_1409_; lean_object* v___x_1410_; 
v___x_1408_ = l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23(v_msg_1401_, v_declHint_1402_, v___y_1403_, v___y_1404_, v___y_1405_, v___y_1406_);
v_a_1409_ = lean_ctor_get(v___x_1408_, 0);
lean_inc(v_a_1409_);
lean_dec_ref(v___x_1408_);
v___x_1410_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_ref_1400_, v_a_1409_, v___y_1403_, v___y_1404_, v___y_1405_, v___y_1406_);
return v___x_1410_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg___boxed(lean_object* v_ref_1411_, lean_object* v_msg_1412_, lean_object* v_declHint_1413_, lean_object* v___y_1414_, lean_object* v___y_1415_, lean_object* v___y_1416_, lean_object* v___y_1417_, lean_object* v___y_1418_){
_start:
{
lean_object* v_res_1419_; 
v_res_1419_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg(v_ref_1411_, v_msg_1412_, v_declHint_1413_, v___y_1414_, v___y_1415_, v___y_1416_, v___y_1417_);
lean_dec(v___y_1417_);
lean_dec_ref(v___y_1416_);
lean_dec(v___y_1415_);
lean_dec_ref(v___y_1414_);
lean_dec(v_ref_1411_);
return v_res_1419_;
}
}
static lean_object* _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1(void){
_start:
{
lean_object* v___x_1421_; lean_object* v___x_1422_; 
v___x_1421_ = ((lean_object*)(l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__0));
v___x_1422_ = l_Lean_stringToMessageData(v___x_1421_);
return v___x_1422_;
}
}
static lean_object* _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3(void){
_start:
{
lean_object* v___x_1424_; lean_object* v___x_1425_; 
v___x_1424_ = ((lean_object*)(l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__2));
v___x_1425_ = l_Lean_stringToMessageData(v___x_1424_);
return v___x_1425_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg(lean_object* v_ref_1426_, lean_object* v_constName_1427_, lean_object* v___y_1428_, lean_object* v___y_1429_, lean_object* v___y_1430_, lean_object* v___y_1431_){
_start:
{
lean_object* v___x_1433_; uint8_t v___x_1434_; lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; lean_object* v___x_1438_; lean_object* v___x_1439_; 
v___x_1433_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__1);
v___x_1434_ = 0;
lean_inc(v_constName_1427_);
v___x_1435_ = l_Lean_MessageData_ofConstName(v_constName_1427_, v___x_1434_);
v___x_1436_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1436_, 0, v___x_1433_);
lean_ctor_set(v___x_1436_, 1, v___x_1435_);
v___x_1437_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___closed__3);
v___x_1438_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1438_, 0, v___x_1436_);
lean_ctor_set(v___x_1438_, 1, v___x_1437_);
v___x_1439_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg(v_ref_1426_, v___x_1438_, v_constName_1427_, v___y_1428_, v___y_1429_, v___y_1430_, v___y_1431_);
return v___x_1439_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg___boxed(lean_object* v_ref_1440_, lean_object* v_constName_1441_, lean_object* v___y_1442_, lean_object* v___y_1443_, lean_object* v___y_1444_, lean_object* v___y_1445_, lean_object* v___y_1446_){
_start:
{
lean_object* v_res_1447_; 
v_res_1447_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg(v_ref_1440_, v_constName_1441_, v___y_1442_, v___y_1443_, v___y_1444_, v___y_1445_);
lean_dec(v___y_1445_);
lean_dec_ref(v___y_1444_);
lean_dec(v___y_1443_);
lean_dec_ref(v___y_1442_);
lean_dec(v_ref_1440_);
return v_res_1447_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg(lean_object* v_constName_1448_, lean_object* v___y_1449_, lean_object* v___y_1450_, lean_object* v___y_1451_, lean_object* v___y_1452_){
_start:
{
lean_object* v_ref_1454_; lean_object* v___x_1455_; 
v_ref_1454_ = lean_ctor_get(v___y_1451_, 5);
v___x_1455_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg(v_ref_1454_, v_constName_1448_, v___y_1449_, v___y_1450_, v___y_1451_, v___y_1452_);
return v___x_1455_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg___boxed(lean_object* v_constName_1456_, lean_object* v___y_1457_, lean_object* v___y_1458_, lean_object* v___y_1459_, lean_object* v___y_1460_, lean_object* v___y_1461_){
_start:
{
lean_object* v_res_1462_; 
v_res_1462_ = l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg(v_constName_1456_, v___y_1457_, v___y_1458_, v___y_1459_, v___y_1460_);
lean_dec(v___y_1460_);
lean_dec_ref(v___y_1459_);
lean_dec(v___y_1458_);
lean_dec_ref(v___y_1457_);
return v_res_1462_;
}
}
LEAN_EXPORT lean_object* l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0(lean_object* v_constName_1463_, lean_object* v___y_1464_, lean_object* v___y_1465_, lean_object* v___y_1466_, lean_object* v___y_1467_){
_start:
{
lean_object* v___x_1469_; lean_object* v_env_1470_; uint8_t v___x_1471_; lean_object* v___x_1472_; 
v___x_1469_ = lean_st_ref_get(v___y_1467_);
v_env_1470_ = lean_ctor_get(v___x_1469_, 0);
lean_inc_ref(v_env_1470_);
lean_dec(v___x_1469_);
v___x_1471_ = 0;
lean_inc(v_constName_1463_);
v___x_1472_ = l_Lean_Environment_findConstVal_x3f(v_env_1470_, v_constName_1463_, v___x_1471_);
if (lean_obj_tag(v___x_1472_) == 0)
{
lean_object* v___x_1473_; 
v___x_1473_ = l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg(v_constName_1463_, v___y_1464_, v___y_1465_, v___y_1466_, v___y_1467_);
return v___x_1473_;
}
else
{
lean_object* v_val_1474_; lean_object* v___x_1476_; uint8_t v_isShared_1477_; uint8_t v_isSharedCheck_1481_; 
lean_dec(v_constName_1463_);
v_val_1474_ = lean_ctor_get(v___x_1472_, 0);
v_isSharedCheck_1481_ = !lean_is_exclusive(v___x_1472_);
if (v_isSharedCheck_1481_ == 0)
{
v___x_1476_ = v___x_1472_;
v_isShared_1477_ = v_isSharedCheck_1481_;
goto v_resetjp_1475_;
}
else
{
lean_inc(v_val_1474_);
lean_dec(v___x_1472_);
v___x_1476_ = lean_box(0);
v_isShared_1477_ = v_isSharedCheck_1481_;
goto v_resetjp_1475_;
}
v_resetjp_1475_:
{
lean_object* v___x_1479_; 
if (v_isShared_1477_ == 0)
{
lean_ctor_set_tag(v___x_1476_, 0);
v___x_1479_ = v___x_1476_;
goto v_reusejp_1478_;
}
else
{
lean_object* v_reuseFailAlloc_1480_; 
v_reuseFailAlloc_1480_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1480_, 0, v_val_1474_);
v___x_1479_ = v_reuseFailAlloc_1480_;
goto v_reusejp_1478_;
}
v_reusejp_1478_:
{
return v___x_1479_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0___boxed(lean_object* v_constName_1482_, lean_object* v___y_1483_, lean_object* v___y_1484_, lean_object* v___y_1485_, lean_object* v___y_1486_, lean_object* v___y_1487_){
_start:
{
lean_object* v_res_1488_; 
v_res_1488_ = l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0(v_constName_1482_, v___y_1483_, v___y_1484_, v___y_1485_, v___y_1486_);
lean_dec(v___y_1486_);
lean_dec_ref(v___y_1485_);
lean_dec(v___y_1484_);
lean_dec_ref(v___y_1483_);
return v_res_1488_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___closed__2(void){
_start:
{
lean_object* v___x_1491_; 
v___x_1491_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_1491_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___closed__3(void){
_start:
{
lean_object* v___x_1492_; lean_object* v___x_1493_; 
v___x_1492_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__2, &l_Lean_Meta_inferRelationInfo___closed__2_once, _init_l_Lean_Meta_inferRelationInfo___closed__2);
v___x_1493_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1493_, 0, v___x_1492_);
return v___x_1493_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___closed__4(void){
_start:
{
lean_object* v___x_1494_; lean_object* v___x_1495_; lean_object* v___x_1496_; lean_object* v___x_1497_; 
v___x_1494_ = lean_box(1);
v___x_1495_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__4);
v___x_1496_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__3, &l_Lean_Meta_inferRelationInfo___closed__3_once, _init_l_Lean_Meta_inferRelationInfo___closed__3);
v___x_1497_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1497_, 0, v___x_1496_);
lean_ctor_set(v___x_1497_, 1, v___x_1495_);
lean_ctor_set(v___x_1497_, 2, v___x_1494_);
return v___x_1497_;
}
}
static lean_object* _init_l_Lean_Meta_inferRelationInfo___closed__9(void){
_start:
{
lean_object* v___x_1504_; lean_object* v___x_1505_; 
v___x_1504_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___closed__8));
v___x_1505_ = l_Lean_stringToMessageData(v___x_1504_);
return v___x_1505_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo(lean_object* v_declName_1506_, lean_object* v_args_1507_, lean_object* v_a_1508_, lean_object* v_a_1509_, lean_object* v_a_1510_, lean_object* v_a_1511_){
_start:
{
lean_object* v___f_1513_; lean_object* v___f_1514_; lean_object* v___y_1516_; lean_object* v___y_1517_; lean_object* v___y_1518_; lean_object* v___y_1519_; uint8_t v___y_1541_; lean_object* v___x_1555_; lean_object* v___x_1556_; uint8_t v___x_1557_; 
v___f_1513_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___closed__0));
v___f_1514_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___closed__1));
v___x_1555_ = lean_unsigned_to_nat(0u);
v___x_1556_ = lean_array_get_size(v_args_1507_);
v___x_1557_ = lean_nat_dec_lt(v___x_1555_, v___x_1556_);
if (v___x_1557_ == 0)
{
v___y_1541_ = v___x_1557_;
goto v___jp_1540_;
}
else
{
lean_object* v___x_1558_; uint8_t v___x_1559_; 
v___x_1558_ = lean_unsigned_to_nat(2u);
v___x_1559_ = lean_nat_dec_eq(v___x_1556_, v___x_1558_);
if (v___x_1559_ == 0)
{
v___y_1541_ = v___x_1557_;
goto v___jp_1540_;
}
else
{
v___y_1516_ = v_a_1508_;
v___y_1517_ = v_a_1509_;
v___y_1518_ = v_a_1510_;
v___y_1519_ = v_a_1511_;
goto v___jp_1515_;
}
}
v___jp_1515_:
{
lean_object* v___x_1520_; 
lean_inc(v_declName_1506_);
v___x_1520_ = l_Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0(v_declName_1506_, v___y_1516_, v___y_1517_, v___y_1518_, v___y_1519_);
if (lean_obj_tag(v___x_1520_) == 0)
{
lean_object* v_a_1521_; lean_object* v___x_1522_; lean_object* v_type_1523_; lean_object* v___f_1524_; lean_object* v___x_1525_; lean_object* v___x_1526_; uint8_t v___x_1527_; lean_object* v___x_1528_; lean_object* v___x_1529_; lean_object* v___x_1530_; lean_object* v___x_1531_; 
v_a_1521_ = lean_ctor_get(v___x_1520_, 0);
lean_inc(v_a_1521_);
lean_dec_ref(v___x_1520_);
v___x_1522_ = lean_unsigned_to_nat(0u);
v_type_1523_ = lean_ctor_get(v_a_1521_, 2);
lean_inc_ref(v_type_1523_);
lean_dec(v_a_1521_);
v___f_1524_ = lean_alloc_closure((void*)(l_Lean_Meta_inferRelationInfo___lam__2___boxed), 12, 5);
lean_closure_set(v___f_1524_, 0, v___x_1522_);
lean_closure_set(v___f_1524_, 1, v_declName_1506_);
lean_closure_set(v___f_1524_, 2, v_args_1507_);
lean_closure_set(v___f_1524_, 3, v___f_1513_);
lean_closure_set(v___f_1524_, 4, v___f_1514_);
v___x_1525_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__4, &l_Lean_Meta_inferRelationInfo___closed__4_once, _init_l_Lean_Meta_inferRelationInfo___closed__4);
v___x_1526_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___closed__5));
v___x_1527_ = 0;
v___x_1528_ = lean_box(v___x_1527_);
v___x_1529_ = lean_box(v___x_1527_);
v___x_1530_ = lean_alloc_closure((void*)(l_Lean_Meta_forallTelescopeReducing___at___00Lean_Meta_inferRelationInfo_spec__16___boxed), 10, 5);
lean_closure_set(v___x_1530_, 0, lean_box(0));
lean_closure_set(v___x_1530_, 1, v_type_1523_);
lean_closure_set(v___x_1530_, 2, v___f_1524_);
lean_closure_set(v___x_1530_, 3, v___x_1528_);
lean_closure_set(v___x_1530_, 4, v___x_1529_);
v___x_1531_ = l_Lean_Meta_withLCtx___at___00Lean_Meta_inferRelationInfo_spec__17___redArg(v___x_1525_, v___x_1526_, v___x_1530_, v___y_1516_, v___y_1517_, v___y_1518_, v___y_1519_);
return v___x_1531_;
}
else
{
lean_object* v_a_1532_; lean_object* v___x_1534_; uint8_t v_isShared_1535_; uint8_t v_isSharedCheck_1539_; 
lean_dec_ref(v_args_1507_);
lean_dec(v_declName_1506_);
v_a_1532_ = lean_ctor_get(v___x_1520_, 0);
v_isSharedCheck_1539_ = !lean_is_exclusive(v___x_1520_);
if (v_isSharedCheck_1539_ == 0)
{
v___x_1534_ = v___x_1520_;
v_isShared_1535_ = v_isSharedCheck_1539_;
goto v_resetjp_1533_;
}
else
{
lean_inc(v_a_1532_);
lean_dec(v___x_1520_);
v___x_1534_ = lean_box(0);
v_isShared_1535_ = v_isSharedCheck_1539_;
goto v_resetjp_1533_;
}
v_resetjp_1533_:
{
lean_object* v___x_1537_; 
if (v_isShared_1535_ == 0)
{
v___x_1537_ = v___x_1534_;
goto v_reusejp_1536_;
}
else
{
lean_object* v_reuseFailAlloc_1538_; 
v_reuseFailAlloc_1538_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1538_, 0, v_a_1532_);
v___x_1537_ = v_reuseFailAlloc_1538_;
goto v_reusejp_1536_;
}
v_reusejp_1536_:
{
return v___x_1537_;
}
}
}
}
v___jp_1540_:
{
if (v___y_1541_ == 0)
{
v___y_1516_ = v_a_1508_;
v___y_1517_ = v_a_1509_;
v___y_1518_ = v_a_1510_;
v___y_1519_ = v_a_1511_;
goto v___jp_1515_;
}
else
{
lean_object* v___x_1542_; lean_object* v___x_1543_; lean_object* v___x_1544_; lean_object* v___x_1545_; lean_object* v___x_1546_; lean_object* v_a_1547_; lean_object* v___x_1549_; uint8_t v_isShared_1550_; uint8_t v_isSharedCheck_1554_; 
lean_dec(v_declName_1506_);
v___x_1542_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___closed__7));
v___x_1543_ = lean_box(2);
v___x_1544_ = lean_alloc_ctor(1, 3, 0);
lean_ctor_set(v___x_1544_, 0, v___x_1543_);
lean_ctor_set(v___x_1544_, 1, v___x_1542_);
lean_ctor_set(v___x_1544_, 2, v_args_1507_);
v___x_1545_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__9, &l_Lean_Meta_inferRelationInfo___closed__9_once, _init_l_Lean_Meta_inferRelationInfo___closed__9);
v___x_1546_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v___x_1544_, v___x_1545_, v_a_1508_, v_a_1509_, v_a_1510_, v_a_1511_);
lean_dec_ref(v___x_1544_);
v_a_1547_ = lean_ctor_get(v___x_1546_, 0);
v_isSharedCheck_1554_ = !lean_is_exclusive(v___x_1546_);
if (v_isSharedCheck_1554_ == 0)
{
v___x_1549_ = v___x_1546_;
v_isShared_1550_ = v_isSharedCheck_1554_;
goto v_resetjp_1548_;
}
else
{
lean_inc(v_a_1547_);
lean_dec(v___x_1546_);
v___x_1549_ = lean_box(0);
v_isShared_1550_ = v_isSharedCheck_1554_;
goto v_resetjp_1548_;
}
v_resetjp_1548_:
{
lean_object* v___x_1552_; 
if (v_isShared_1550_ == 0)
{
v___x_1552_ = v___x_1549_;
goto v_reusejp_1551_;
}
else
{
lean_object* v_reuseFailAlloc_1553_; 
v_reuseFailAlloc_1553_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1553_, 0, v_a_1547_);
v___x_1552_ = v_reuseFailAlloc_1553_;
goto v_reusejp_1551_;
}
v_reusejp_1551_:
{
return v___x_1552_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_inferRelationInfo___boxed(lean_object* v_declName_1560_, lean_object* v_args_1561_, lean_object* v_a_1562_, lean_object* v_a_1563_, lean_object* v_a_1564_, lean_object* v_a_1565_, lean_object* v_a_1566_){
_start:
{
lean_object* v_res_1567_; 
v_res_1567_ = l_Lean_Meta_inferRelationInfo(v_declName_1560_, v_args_1561_, v_a_1562_, v_a_1563_, v_a_1564_, v_a_1565_);
lean_dec(v_a_1565_);
lean_dec_ref(v_a_1564_);
lean_dec(v_a_1563_);
lean_dec_ref(v_a_1562_);
return v_res_1567_;
}
}
LEAN_EXPORT uint8_t l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2(lean_object* v_00_u03b2_1568_, lean_object* v_k_1569_, lean_object* v_t_1570_){
_start:
{
uint8_t v___x_1571_; 
v___x_1571_ = l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___redArg(v_k_1569_, v_t_1570_);
return v___x_1571_;
}
}
LEAN_EXPORT lean_object* l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2___boxed(lean_object* v_00_u03b2_1572_, lean_object* v_k_1573_, lean_object* v_t_1574_){
_start:
{
uint8_t v_res_1575_; lean_object* v_r_1576_; 
v_res_1575_ = l_Std_DTreeMap_Internal_Impl_contains___at___00Lean_Meta_inferRelationInfo_spec__2(v_00_u03b2_1572_, v_k_1573_, v_t_1574_);
lean_dec(v_t_1574_);
lean_dec(v_k_1573_);
v_r_1576_ = lean_box(v_res_1575_);
return v_r_1576_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3(lean_object* v_a_1577_, lean_object* v_a_1578_, lean_object* v_inst_1579_, lean_object* v_R_1580_, lean_object* v_a_1581_, lean_object* v_b_1582_, lean_object* v_c_1583_, lean_object* v___y_1584_, lean_object* v___y_1585_, lean_object* v___y_1586_, lean_object* v___y_1587_){
_start:
{
lean_object* v___x_1589_; 
v___x_1589_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___redArg(v_a_1577_, v_a_1578_, v_a_1581_, v_b_1582_);
return v___x_1589_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3___boxed(lean_object* v_a_1590_, lean_object* v_a_1591_, lean_object* v_inst_1592_, lean_object* v_R_1593_, lean_object* v_a_1594_, lean_object* v_b_1595_, lean_object* v_c_1596_, lean_object* v___y_1597_, lean_object* v___y_1598_, lean_object* v___y_1599_, lean_object* v___y_1600_, lean_object* v___y_1601_){
_start:
{
lean_object* v_res_1602_; 
v_res_1602_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_inferRelationInfo_spec__3(v_a_1590_, v_a_1591_, v_inst_1592_, v_R_1593_, v_a_1594_, v_b_1595_, v_c_1596_, v___y_1597_, v___y_1598_, v___y_1599_, v___y_1600_);
lean_dec(v___y_1600_);
lean_dec_ref(v___y_1599_);
lean_dec(v___y_1598_);
lean_dec_ref(v___y_1597_);
lean_dec_ref(v_a_1591_);
lean_dec_ref(v_a_1590_);
return v_res_1602_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6(lean_object* v_00_u03b1_1603_, lean_object* v_msg_1604_, lean_object* v___y_1605_, lean_object* v___y_1606_, lean_object* v___y_1607_, lean_object* v___y_1608_){
_start:
{
lean_object* v___x_1610_; 
v___x_1610_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v_msg_1604_, v___y_1605_, v___y_1606_, v___y_1607_, v___y_1608_);
return v___x_1610_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___boxed(lean_object* v_00_u03b1_1611_, lean_object* v_msg_1612_, lean_object* v___y_1613_, lean_object* v___y_1614_, lean_object* v___y_1615_, lean_object* v___y_1616_, lean_object* v___y_1617_){
_start:
{
lean_object* v_res_1618_; 
v_res_1618_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6(v_00_u03b1_1611_, v_msg_1612_, v___y_1613_, v___y_1614_, v___y_1615_, v___y_1616_);
lean_dec(v___y_1616_);
lean_dec_ref(v___y_1615_);
lean_dec(v___y_1614_);
lean_dec_ref(v___y_1613_);
return v_res_1618_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7(size_t v_sz_1619_, size_t v_i_1620_, lean_object* v_bs_1621_, lean_object* v___y_1622_, lean_object* v___y_1623_, lean_object* v___y_1624_, lean_object* v___y_1625_){
_start:
{
lean_object* v___x_1627_; 
v___x_1627_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___redArg(v_sz_1619_, v_i_1620_, v_bs_1621_, v___y_1622_, v___y_1624_, v___y_1625_);
return v___x_1627_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7___boxed(lean_object* v_sz_1628_, lean_object* v_i_1629_, lean_object* v_bs_1630_, lean_object* v___y_1631_, lean_object* v___y_1632_, lean_object* v___y_1633_, lean_object* v___y_1634_, lean_object* v___y_1635_){
_start:
{
size_t v_sz_boxed_1636_; size_t v_i_boxed_1637_; lean_object* v_res_1638_; 
v_sz_boxed_1636_ = lean_unbox_usize(v_sz_1628_);
lean_dec(v_sz_1628_);
v_i_boxed_1637_ = lean_unbox_usize(v_i_1629_);
lean_dec(v_i_1629_);
v_res_1638_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__7(v_sz_boxed_1636_, v_i_boxed_1637_, v_bs_1630_, v___y_1631_, v___y_1632_, v___y_1633_, v___y_1634_);
lean_dec(v___y_1634_);
lean_dec_ref(v___y_1633_);
lean_dec(v___y_1632_);
lean_dec_ref(v___y_1631_);
return v_res_1638_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9(lean_object* v_00_u03b1_1639_, lean_object* v_ref_1640_, lean_object* v_msg_1641_, lean_object* v___y_1642_, lean_object* v___y_1643_, lean_object* v___y_1644_, lean_object* v___y_1645_){
_start:
{
lean_object* v___x_1647_; 
v___x_1647_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___redArg(v_ref_1640_, v_msg_1641_, v___y_1642_, v___y_1643_, v___y_1644_, v___y_1645_);
return v___x_1647_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9___boxed(lean_object* v_00_u03b1_1648_, lean_object* v_ref_1649_, lean_object* v_msg_1650_, lean_object* v___y_1651_, lean_object* v___y_1652_, lean_object* v___y_1653_, lean_object* v___y_1654_, lean_object* v___y_1655_){
_start:
{
lean_object* v_res_1656_; 
v_res_1656_ = l_Lean_throwErrorAt___at___00Lean_Meta_inferRelationInfo_spec__9(v_00_u03b1_1648_, v_ref_1649_, v_msg_1650_, v___y_1651_, v___y_1652_, v___y_1653_, v___y_1654_);
lean_dec(v___y_1654_);
lean_dec_ref(v___y_1653_);
lean_dec(v___y_1652_);
lean_dec_ref(v___y_1651_);
lean_dec(v_ref_1649_);
return v_res_1656_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11(size_t v_sz_1657_, size_t v_i_1658_, lean_object* v_bs_1659_, lean_object* v___y_1660_, lean_object* v___y_1661_, lean_object* v___y_1662_, lean_object* v___y_1663_){
_start:
{
lean_object* v___x_1665_; 
v___x_1665_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___redArg(v_sz_1657_, v_i_1658_, v_bs_1659_, v___y_1660_, v___y_1662_, v___y_1663_);
return v___x_1665_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11___boxed(lean_object* v_sz_1666_, lean_object* v_i_1667_, lean_object* v_bs_1668_, lean_object* v___y_1669_, lean_object* v___y_1670_, lean_object* v___y_1671_, lean_object* v___y_1672_, lean_object* v___y_1673_){
_start:
{
size_t v_sz_boxed_1674_; size_t v_i_boxed_1675_; lean_object* v_res_1676_; 
v_sz_boxed_1674_ = lean_unbox_usize(v_sz_1666_);
lean_dec(v_sz_1666_);
v_i_boxed_1675_ = lean_unbox_usize(v_i_1667_);
lean_dec(v_i_1667_);
v_res_1676_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_inferRelationInfo_spec__11(v_sz_boxed_1674_, v_i_boxed_1675_, v_bs_1668_, v___y_1669_, v___y_1670_, v___y_1671_, v___y_1672_);
lean_dec(v___y_1672_);
lean_dec_ref(v___y_1671_);
lean_dec(v___y_1670_);
lean_dec_ref(v___y_1669_);
return v_res_1676_;
}
}
LEAN_EXPORT lean_object* l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13(lean_object* v_inst_1677_, lean_object* v_R_1678_, lean_object* v_a_1679_, lean_object* v_b_1680_){
_start:
{
lean_object* v___x_1681_; 
v___x_1681_ = l___private_Init_WFExtrinsicFix_0__WellFounded_opaqueFix_u2082___at___00Lean_Meta_inferRelationInfo_spec__13___redArg(v_a_1679_, v_b_1680_);
return v___x_1681_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0(lean_object* v_00_u03b1_1682_, lean_object* v_constName_1683_, lean_object* v___y_1684_, lean_object* v___y_1685_, lean_object* v___y_1686_, lean_object* v___y_1687_){
_start:
{
lean_object* v___x_1689_; 
v___x_1689_ = l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___redArg(v_constName_1683_, v___y_1684_, v___y_1685_, v___y_1686_, v___y_1687_);
return v___x_1689_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0___boxed(lean_object* v_00_u03b1_1690_, lean_object* v_constName_1691_, lean_object* v___y_1692_, lean_object* v___y_1693_, lean_object* v___y_1694_, lean_object* v___y_1695_, lean_object* v___y_1696_){
_start:
{
lean_object* v_res_1697_; 
v_res_1697_ = l_Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0(v_00_u03b1_1690_, v_constName_1691_, v___y_1692_, v___y_1693_, v___y_1694_, v___y_1695_);
lean_dec(v___y_1695_);
lean_dec_ref(v___y_1694_);
lean_dec(v___y_1693_);
lean_dec_ref(v___y_1692_);
return v_res_1697_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5(lean_object* v_00_u03b1_1698_, lean_object* v_ref_1699_, lean_object* v_constName_1700_, lean_object* v___y_1701_, lean_object* v___y_1702_, lean_object* v___y_1703_, lean_object* v___y_1704_){
_start:
{
lean_object* v___x_1706_; 
v___x_1706_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___redArg(v_ref_1699_, v_constName_1700_, v___y_1701_, v___y_1702_, v___y_1703_, v___y_1704_);
return v___x_1706_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5___boxed(lean_object* v_00_u03b1_1707_, lean_object* v_ref_1708_, lean_object* v_constName_1709_, lean_object* v___y_1710_, lean_object* v___y_1711_, lean_object* v___y_1712_, lean_object* v___y_1713_, lean_object* v___y_1714_){
_start:
{
lean_object* v_res_1715_; 
v_res_1715_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5(v_00_u03b1_1707_, v_ref_1708_, v_constName_1709_, v___y_1710_, v___y_1711_, v___y_1712_, v___y_1713_);
lean_dec(v___y_1713_);
lean_dec_ref(v___y_1712_);
lean_dec(v___y_1711_);
lean_dec_ref(v___y_1710_);
lean_dec(v_ref_1708_);
return v_res_1715_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20(lean_object* v_00_u03b1_1716_, lean_object* v_ref_1717_, lean_object* v_msg_1718_, lean_object* v_declHint_1719_, lean_object* v___y_1720_, lean_object* v___y_1721_, lean_object* v___y_1722_, lean_object* v___y_1723_){
_start:
{
lean_object* v___x_1725_; 
v___x_1725_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___redArg(v_ref_1717_, v_msg_1718_, v_declHint_1719_, v___y_1720_, v___y_1721_, v___y_1722_, v___y_1723_);
return v___x_1725_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20___boxed(lean_object* v_00_u03b1_1726_, lean_object* v_ref_1727_, lean_object* v_msg_1728_, lean_object* v_declHint_1729_, lean_object* v___y_1730_, lean_object* v___y_1731_, lean_object* v___y_1732_, lean_object* v___y_1733_, lean_object* v___y_1734_){
_start:
{
lean_object* v_res_1735_; 
v_res_1735_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20(v_00_u03b1_1726_, v_ref_1727_, v_msg_1728_, v_declHint_1729_, v___y_1730_, v___y_1731_, v___y_1732_, v___y_1733_);
lean_dec(v___y_1733_);
lean_dec_ref(v___y_1732_);
lean_dec(v___y_1731_);
lean_dec_ref(v___y_1730_);
lean_dec(v_ref_1727_);
return v_res_1735_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25(lean_object* v_msg_1736_, lean_object* v_declHint_1737_, lean_object* v___y_1738_, lean_object* v___y_1739_, lean_object* v___y_1740_, lean_object* v___y_1741_){
_start:
{
lean_object* v___x_1743_; 
v___x_1743_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg(v_msg_1736_, v_declHint_1737_, v___y_1741_);
return v___x_1743_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___boxed(lean_object* v_msg_1744_, lean_object* v_declHint_1745_, lean_object* v___y_1746_, lean_object* v___y_1747_, lean_object* v___y_1748_, lean_object* v___y_1749_, lean_object* v___y_1750_){
_start:
{
lean_object* v_res_1751_; 
v_res_1751_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25(v_msg_1744_, v_declHint_1745_, v___y_1746_, v___y_1747_, v___y_1748_, v___y_1749_);
lean_dec(v___y_1749_);
lean_dec_ref(v___y_1748_);
lean_dec(v___y_1747_);
lean_dec_ref(v___y_1746_);
return v_res_1751_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(lean_object* v_declName_1752_, lean_object* v___y_1753_){
_start:
{
lean_object* v___x_1755_; lean_object* v_env_1756_; lean_object* v___x_1757_; lean_object* v_ext_1758_; lean_object* v_toEnvExtension_1759_; lean_object* v_asyncMode_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; lean_object* v___x_1763_; lean_object* v___x_1764_; 
v___x_1755_ = lean_st_ref_get(v___y_1753_);
v_env_1756_ = lean_ctor_get(v___x_1755_, 0);
lean_inc_ref(v_env_1756_);
lean_dec(v___x_1755_);
v___x_1757_ = l_Lean_Meta_relationExt;
v_ext_1758_ = lean_ctor_get(v___x_1757_, 1);
lean_inc_ref(v_ext_1758_);
v_toEnvExtension_1759_ = lean_ctor_get(v_ext_1758_, 0);
lean_inc_ref(v_toEnvExtension_1759_);
lean_dec_ref(v_ext_1758_);
v_asyncMode_1760_ = lean_ctor_get(v_toEnvExtension_1759_, 2);
lean_inc(v_asyncMode_1760_);
lean_dec_ref(v_toEnvExtension_1759_);
v___x_1761_ = lean_box(1);
v___x_1762_ = l_Lean_ScopedEnvExtension_getState___redArg(v___x_1761_, v___x_1757_, v_env_1756_, v_asyncMode_1760_);
lean_dec(v_asyncMode_1760_);
v___x_1763_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v___x_1762_, v_declName_1752_);
lean_dec(v___x_1762_);
v___x_1764_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1764_, 0, v___x_1763_);
return v___x_1764_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg___boxed(lean_object* v_declName_1765_, lean_object* v___y_1766_, lean_object* v___y_1767_){
_start:
{
lean_object* v_res_1768_; 
v_res_1768_ = l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(v_declName_1765_, v___y_1766_);
lean_dec(v___y_1766_);
lean_dec(v_declName_1765_);
return v_res_1768_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1(lean_object* v_declName_1769_, lean_object* v___y_1770_, lean_object* v___y_1771_, lean_object* v___y_1772_, lean_object* v___y_1773_){
_start:
{
lean_object* v___x_1775_; 
v___x_1775_ = l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(v_declName_1769_, v___y_1773_);
return v___x_1775_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___boxed(lean_object* v_declName_1776_, lean_object* v___y_1777_, lean_object* v___y_1778_, lean_object* v___y_1779_, lean_object* v___y_1780_, lean_object* v___y_1781_){
_start:
{
lean_object* v_res_1782_; 
v_res_1782_ = l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1(v_declName_1776_, v___y_1777_, v___y_1778_, v___y_1779_, v___y_1780_);
lean_dec(v___y_1780_);
lean_dec_ref(v___y_1779_);
lean_dec(v___y_1778_);
lean_dec_ref(v___y_1777_);
lean_dec(v_declName_1776_);
return v_res_1782_;
}
}
static lean_object* _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0(void){
_start:
{
lean_object* v___x_1783_; 
v___x_1783_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_1783_;
}
}
static lean_object* _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1(void){
_start:
{
lean_object* v___x_1784_; lean_object* v___x_1785_; 
v___x_1784_ = lean_obj_once(&l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0, &l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0_once, _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__0);
v___x_1785_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1785_, 0, v___x_1784_);
return v___x_1785_;
}
}
static lean_object* _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2(void){
_start:
{
lean_object* v___x_1786_; lean_object* v___x_1787_; 
v___x_1786_ = lean_obj_once(&l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1, &l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1_once, _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1);
v___x_1787_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1787_, 0, v___x_1786_);
lean_ctor_set(v___x_1787_, 1, v___x_1786_);
return v___x_1787_;
}
}
static lean_object* _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3(void){
_start:
{
lean_object* v___x_1788_; lean_object* v___x_1789_; 
v___x_1788_ = lean_obj_once(&l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1, &l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1_once, _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__1);
v___x_1789_ = lean_alloc_ctor(0, 6, 0);
lean_ctor_set(v___x_1789_, 0, v___x_1788_);
lean_ctor_set(v___x_1789_, 1, v___x_1788_);
lean_ctor_set(v___x_1789_, 2, v___x_1788_);
lean_ctor_set(v___x_1789_, 3, v___x_1788_);
lean_ctor_set(v___x_1789_, 4, v___x_1788_);
lean_ctor_set(v___x_1789_, 5, v___x_1788_);
return v___x_1789_;
}
}
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg(lean_object* v_ext_1790_, lean_object* v_b_1791_, uint8_t v_kind_1792_, lean_object* v___y_1793_, lean_object* v___y_1794_, lean_object* v___y_1795_){
_start:
{
lean_object* v_currNamespace_1797_; lean_object* v___x_1798_; lean_object* v_env_1799_; lean_object* v_nextMacroScope_1800_; lean_object* v_ngen_1801_; lean_object* v_auxDeclNGen_1802_; lean_object* v_traceState_1803_; lean_object* v_messages_1804_; lean_object* v_infoState_1805_; lean_object* v_snapshotTasks_1806_; lean_object* v___x_1808_; uint8_t v_isShared_1809_; uint8_t v_isSharedCheck_1833_; 
v_currNamespace_1797_ = lean_ctor_get(v___y_1794_, 6);
lean_inc(v_currNamespace_1797_);
lean_dec_ref(v___y_1794_);
v___x_1798_ = lean_st_ref_take(v___y_1795_);
v_env_1799_ = lean_ctor_get(v___x_1798_, 0);
v_nextMacroScope_1800_ = lean_ctor_get(v___x_1798_, 1);
v_ngen_1801_ = lean_ctor_get(v___x_1798_, 2);
v_auxDeclNGen_1802_ = lean_ctor_get(v___x_1798_, 3);
v_traceState_1803_ = lean_ctor_get(v___x_1798_, 4);
v_messages_1804_ = lean_ctor_get(v___x_1798_, 6);
v_infoState_1805_ = lean_ctor_get(v___x_1798_, 7);
v_snapshotTasks_1806_ = lean_ctor_get(v___x_1798_, 8);
v_isSharedCheck_1833_ = !lean_is_exclusive(v___x_1798_);
if (v_isSharedCheck_1833_ == 0)
{
lean_object* v_unused_1834_; 
v_unused_1834_ = lean_ctor_get(v___x_1798_, 5);
lean_dec(v_unused_1834_);
v___x_1808_ = v___x_1798_;
v_isShared_1809_ = v_isSharedCheck_1833_;
goto v_resetjp_1807_;
}
else
{
lean_inc(v_snapshotTasks_1806_);
lean_inc(v_infoState_1805_);
lean_inc(v_messages_1804_);
lean_inc(v_traceState_1803_);
lean_inc(v_auxDeclNGen_1802_);
lean_inc(v_ngen_1801_);
lean_inc(v_nextMacroScope_1800_);
lean_inc(v_env_1799_);
lean_dec(v___x_1798_);
v___x_1808_ = lean_box(0);
v_isShared_1809_ = v_isSharedCheck_1833_;
goto v_resetjp_1807_;
}
v_resetjp_1807_:
{
lean_object* v___x_1810_; lean_object* v___x_1811_; lean_object* v___x_1813_; 
v___x_1810_ = l_Lean_ScopedEnvExtension_addCore___redArg(v_env_1799_, v_ext_1790_, v_b_1791_, v_kind_1792_, v_currNamespace_1797_);
v___x_1811_ = lean_obj_once(&l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2, &l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2_once, _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__2);
if (v_isShared_1809_ == 0)
{
lean_ctor_set(v___x_1808_, 5, v___x_1811_);
lean_ctor_set(v___x_1808_, 0, v___x_1810_);
v___x_1813_ = v___x_1808_;
goto v_reusejp_1812_;
}
else
{
lean_object* v_reuseFailAlloc_1832_; 
v_reuseFailAlloc_1832_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_1832_, 0, v___x_1810_);
lean_ctor_set(v_reuseFailAlloc_1832_, 1, v_nextMacroScope_1800_);
lean_ctor_set(v_reuseFailAlloc_1832_, 2, v_ngen_1801_);
lean_ctor_set(v_reuseFailAlloc_1832_, 3, v_auxDeclNGen_1802_);
lean_ctor_set(v_reuseFailAlloc_1832_, 4, v_traceState_1803_);
lean_ctor_set(v_reuseFailAlloc_1832_, 5, v___x_1811_);
lean_ctor_set(v_reuseFailAlloc_1832_, 6, v_messages_1804_);
lean_ctor_set(v_reuseFailAlloc_1832_, 7, v_infoState_1805_);
lean_ctor_set(v_reuseFailAlloc_1832_, 8, v_snapshotTasks_1806_);
v___x_1813_ = v_reuseFailAlloc_1832_;
goto v_reusejp_1812_;
}
v_reusejp_1812_:
{
lean_object* v___x_1814_; lean_object* v___x_1815_; lean_object* v_mctx_1816_; lean_object* v_zetaDeltaFVarIds_1817_; lean_object* v_postponed_1818_; lean_object* v_diag_1819_; lean_object* v___x_1821_; uint8_t v_isShared_1822_; uint8_t v_isSharedCheck_1830_; 
v___x_1814_ = lean_st_ref_set(v___y_1795_, v___x_1813_);
v___x_1815_ = lean_st_ref_take(v___y_1793_);
v_mctx_1816_ = lean_ctor_get(v___x_1815_, 0);
v_zetaDeltaFVarIds_1817_ = lean_ctor_get(v___x_1815_, 2);
v_postponed_1818_ = lean_ctor_get(v___x_1815_, 3);
v_diag_1819_ = lean_ctor_get(v___x_1815_, 4);
v_isSharedCheck_1830_ = !lean_is_exclusive(v___x_1815_);
if (v_isSharedCheck_1830_ == 0)
{
lean_object* v_unused_1831_; 
v_unused_1831_ = lean_ctor_get(v___x_1815_, 1);
lean_dec(v_unused_1831_);
v___x_1821_ = v___x_1815_;
v_isShared_1822_ = v_isSharedCheck_1830_;
goto v_resetjp_1820_;
}
else
{
lean_inc(v_diag_1819_);
lean_inc(v_postponed_1818_);
lean_inc(v_zetaDeltaFVarIds_1817_);
lean_inc(v_mctx_1816_);
lean_dec(v___x_1815_);
v___x_1821_ = lean_box(0);
v_isShared_1822_ = v_isSharedCheck_1830_;
goto v_resetjp_1820_;
}
v_resetjp_1820_:
{
lean_object* v___x_1823_; lean_object* v___x_1825_; 
v___x_1823_ = lean_obj_once(&l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3, &l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3_once, _init_l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___closed__3);
if (v_isShared_1822_ == 0)
{
lean_ctor_set(v___x_1821_, 1, v___x_1823_);
v___x_1825_ = v___x_1821_;
goto v_reusejp_1824_;
}
else
{
lean_object* v_reuseFailAlloc_1829_; 
v_reuseFailAlloc_1829_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_1829_, 0, v_mctx_1816_);
lean_ctor_set(v_reuseFailAlloc_1829_, 1, v___x_1823_);
lean_ctor_set(v_reuseFailAlloc_1829_, 2, v_zetaDeltaFVarIds_1817_);
lean_ctor_set(v_reuseFailAlloc_1829_, 3, v_postponed_1818_);
lean_ctor_set(v_reuseFailAlloc_1829_, 4, v_diag_1819_);
v___x_1825_ = v_reuseFailAlloc_1829_;
goto v_reusejp_1824_;
}
v_reusejp_1824_:
{
lean_object* v___x_1826_; lean_object* v___x_1827_; lean_object* v___x_1828_; 
v___x_1826_ = lean_st_ref_set(v___y_1793_, v___x_1825_);
v___x_1827_ = lean_box(0);
v___x_1828_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1828_, 0, v___x_1827_);
return v___x_1828_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg___boxed(lean_object* v_ext_1835_, lean_object* v_b_1836_, lean_object* v_kind_1837_, lean_object* v___y_1838_, lean_object* v___y_1839_, lean_object* v___y_1840_, lean_object* v___y_1841_){
_start:
{
uint8_t v_kind_boxed_1842_; lean_object* v_res_1843_; 
v_kind_boxed_1842_ = lean_unbox(v_kind_1837_);
v_res_1843_ = l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg(v_ext_1835_, v_b_1836_, v_kind_boxed_1842_, v___y_1838_, v___y_1839_, v___y_1840_);
lean_dec(v___y_1840_);
lean_dec(v___y_1838_);
return v_res_1843_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0(lean_object* v_declName_1844_, lean_object* v_info_1845_, uint8_t v_kind_1846_, lean_object* v___y_1847_, lean_object* v___y_1848_, lean_object* v___y_1849_, lean_object* v___y_1850_){
_start:
{
lean_object* v___x_1852_; lean_object* v___x_1853_; lean_object* v___x_1854_; 
v___x_1852_ = l_Lean_Meta_relationExt;
v___x_1853_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1853_, 0, v_declName_1844_);
lean_ctor_set(v___x_1853_, 1, v_info_1845_);
lean_inc_ref(v___y_1849_);
v___x_1854_ = l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg(v___x_1852_, v___x_1853_, v_kind_1846_, v___y_1848_, v___y_1849_, v___y_1850_);
return v___x_1854_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0___boxed(lean_object* v_declName_1855_, lean_object* v_info_1856_, lean_object* v_kind_1857_, lean_object* v___y_1858_, lean_object* v___y_1859_, lean_object* v___y_1860_, lean_object* v___y_1861_, lean_object* v___y_1862_){
_start:
{
uint8_t v_kind_boxed_1863_; lean_object* v_res_1864_; 
v_kind_boxed_1863_ = lean_unbox(v_kind_1857_);
v_res_1864_ = l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0(v_declName_1855_, v_info_1856_, v_kind_boxed_1863_, v___y_1858_, v___y_1859_, v___y_1860_, v___y_1861_);
lean_dec(v___y_1861_);
lean_dec_ref(v___y_1860_);
lean_dec(v___y_1859_);
lean_dec_ref(v___y_1858_);
return v_res_1864_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object* v_stx_1865_, lean_object* v_decl_1866_, uint8_t v_kind_1867_, lean_object* v_____r_1868_, lean_object* v___y_1869_, lean_object* v___y_1870_, lean_object* v___y_1871_, lean_object* v___y_1872_){
_start:
{
lean_object* v___x_1874_; lean_object* v___x_1875_; lean_object* v___x_1876_; lean_object* v___x_1877_; 
v___x_1874_ = lean_unsigned_to_nat(1u);
v___x_1875_ = l_Lean_Syntax_getArg(v_stx_1865_, v___x_1874_);
v___x_1876_ = l_Lean_Syntax_getArgs(v___x_1875_);
lean_dec(v___x_1875_);
lean_inc(v_decl_1866_);
v___x_1877_ = l_Lean_Meta_inferRelationInfo(v_decl_1866_, v___x_1876_, v___y_1869_, v___y_1870_, v___y_1871_, v___y_1872_);
if (lean_obj_tag(v___x_1877_) == 0)
{
lean_object* v_a_1878_; lean_object* v___x_1879_; 
v_a_1878_ = lean_ctor_get(v___x_1877_, 0);
lean_inc(v_a_1878_);
lean_dec_ref(v___x_1877_);
v___x_1879_ = l_Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0(v_decl_1866_, v_a_1878_, v_kind_1867_, v___y_1869_, v___y_1870_, v___y_1871_, v___y_1872_);
return v___x_1879_;
}
else
{
lean_object* v_a_1880_; lean_object* v___x_1882_; uint8_t v_isShared_1883_; uint8_t v_isSharedCheck_1887_; 
lean_dec(v_decl_1866_);
v_a_1880_ = lean_ctor_get(v___x_1877_, 0);
v_isSharedCheck_1887_ = !lean_is_exclusive(v___x_1877_);
if (v_isSharedCheck_1887_ == 0)
{
v___x_1882_ = v___x_1877_;
v_isShared_1883_ = v_isSharedCheck_1887_;
goto v_resetjp_1881_;
}
else
{
lean_inc(v_a_1880_);
lean_dec(v___x_1877_);
v___x_1882_ = lean_box(0);
v_isShared_1883_ = v_isSharedCheck_1887_;
goto v_resetjp_1881_;
}
v_resetjp_1881_:
{
lean_object* v___x_1885_; 
if (v_isShared_1883_ == 0)
{
v___x_1885_ = v___x_1882_;
goto v_reusejp_1884_;
}
else
{
lean_object* v_reuseFailAlloc_1886_; 
v_reuseFailAlloc_1886_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1886_, 0, v_a_1880_);
v___x_1885_ = v_reuseFailAlloc_1886_;
goto v_reusejp_1884_;
}
v_reusejp_1884_:
{
return v___x_1885_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object* v_stx_1888_, lean_object* v_decl_1889_, lean_object* v_kind_1890_, lean_object* v_____r_1891_, lean_object* v___y_1892_, lean_object* v___y_1893_, lean_object* v___y_1894_, lean_object* v___y_1895_, lean_object* v___y_1896_){
_start:
{
uint8_t v_kind_boxed_1897_; lean_object* v_res_1898_; 
v_kind_boxed_1897_ = lean_unbox(v_kind_1890_);
v_res_1898_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(v_stx_1888_, v_decl_1889_, v_kind_boxed_1897_, v_____r_1891_, v___y_1892_, v___y_1893_, v___y_1894_, v___y_1895_);
lean_dec(v___y_1895_);
lean_dec_ref(v___y_1894_);
lean_dec(v___y_1893_);
lean_dec_ref(v___y_1892_);
lean_dec(v_stx_1888_);
return v_res_1898_;
}
}
static uint64_t _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_1905_; uint64_t v___x_1906_; 
v___x_1905_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_1906_ = l___private_Lean_Meta_Basic_0__Lean_Meta_Config_toKey(v___x_1905_);
return v___x_1906_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
uint64_t v___x_1907_; lean_object* v___x_1908_; lean_object* v___x_1909_; 
v___x_1907_ = lean_uint64_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1908_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_1909_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v___x_1909_, 0, v___x_1908_);
lean_ctor_set_uint64(v___x_1909_, sizeof(void*)*1, v___x_1907_);
return v___x_1909_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_1910_; lean_object* v___x_1911_; 
v___x_1910_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__3, &l_Lean_Meta_inferRelationInfo___closed__3_once, _init_l_Lean_Meta_inferRelationInfo___closed__3);
v___x_1911_ = lean_alloc_ctor(0, 6, 0);
lean_ctor_set(v___x_1911_, 0, v___x_1910_);
lean_ctor_set(v___x_1911_, 1, v___x_1910_);
lean_ctor_set(v___x_1911_, 2, v___x_1910_);
lean_ctor_set(v___x_1911_, 3, v___x_1910_);
lean_ctor_set(v___x_1911_, 4, v___x_1910_);
lean_ctor_set(v___x_1911_, 5, v___x_1910_);
return v___x_1911_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_1912_; lean_object* v___x_1913_; 
v___x_1912_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__3, &l_Lean_Meta_inferRelationInfo___closed__3_once, _init_l_Lean_Meta_inferRelationInfo___closed__3);
v___x_1913_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_1913_, 0, v___x_1912_);
lean_ctor_set(v___x_1913_, 1, v___x_1912_);
lean_ctor_set(v___x_1913_, 2, v___x_1912_);
lean_ctor_set(v___x_1913_, 3, v___x_1912_);
lean_ctor_set(v___x_1913_, 4, v___x_1912_);
return v___x_1913_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_1915_; lean_object* v___x_1916_; 
v___x_1915_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__5_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_1916_ = l_Lean_stringToMessageData(v___x_1915_);
return v___x_1916_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_1918_; lean_object* v___x_1919_; 
v___x_1918_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__7_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_1919_ = l_Lean_stringToMessageData(v___x_1918_);
return v___x_1919_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object* v___x_1920_, lean_object* v___x_1921_, lean_object* v_decl_1922_, lean_object* v_stx_1923_, uint8_t v_kind_1924_, lean_object* v___y_1925_, lean_object* v___y_1926_){
_start:
{
uint8_t v___x_1928_; uint8_t v___x_1929_; lean_object* v___x_1930_; lean_object* v___x_1931_; lean_object* v___x_1932_; lean_object* v___x_1933_; lean_object* v___x_1934_; size_t v___x_1935_; lean_object* v___x_1936_; lean_object* v___x_1937_; lean_object* v___x_1938_; lean_object* v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; lean_object* v___x_1942_; lean_object* v___x_1943_; lean_object* v___x_1944_; lean_object* v___x_1945_; lean_object* v___x_1946_; lean_object* v___y_1948_; lean_object* v___x_1958_; lean_object* v_a_1959_; 
v___x_1928_ = 0;
v___x_1929_ = 1;
v___x_1930_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1931_ = lean_obj_once(&l_Lean_Meta_inferRelationInfo___closed__3, &l_Lean_Meta_inferRelationInfo___closed__3_once, _init_l_Lean_Meta_inferRelationInfo___closed__3);
v___x_1932_ = lean_unsigned_to_nat(32u);
v___x_1933_ = lean_mk_empty_array_with_capacity(v___x_1932_);
v___x_1934_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__3);
v___x_1935_ = ((size_t)5ULL);
lean_inc_n(v___x_1920_, 2);
v___x_1936_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_1936_, 0, v___x_1934_);
lean_ctor_set(v___x_1936_, 1, v___x_1933_);
lean_ctor_set(v___x_1936_, 2, v___x_1920_);
lean_ctor_set(v___x_1936_, 3, v___x_1920_);
lean_ctor_set_usize(v___x_1936_, 4, v___x_1935_);
v___x_1937_ = lean_box(1);
lean_inc_ref(v___x_1936_);
v___x_1938_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1938_, 0, v___x_1931_);
lean_ctor_set(v___x_1938_, 1, v___x_1936_);
lean_ctor_set(v___x_1938_, 2, v___x_1937_);
v___x_1939_ = lean_mk_empty_array_with_capacity(v___x_1920_);
v___x_1940_ = lean_box(0);
lean_inc(v___x_1920_);
lean_inc(v___x_1921_);
v___x_1941_ = lean_alloc_ctor(0, 7, 4);
lean_ctor_set(v___x_1941_, 0, v___x_1930_);
lean_ctor_set(v___x_1941_, 1, v___x_1921_);
lean_ctor_set(v___x_1941_, 2, v___x_1938_);
lean_ctor_set(v___x_1941_, 3, v___x_1939_);
lean_ctor_set(v___x_1941_, 4, v___x_1940_);
lean_ctor_set(v___x_1941_, 5, v___x_1920_);
lean_ctor_set(v___x_1941_, 6, v___x_1940_);
lean_ctor_set_uint8(v___x_1941_, sizeof(void*)*7, v___x_1928_);
lean_ctor_set_uint8(v___x_1941_, sizeof(void*)*7 + 1, v___x_1928_);
lean_ctor_set_uint8(v___x_1941_, sizeof(void*)*7 + 2, v___x_1928_);
lean_ctor_set_uint8(v___x_1941_, sizeof(void*)*7 + 3, v___x_1929_);
lean_inc_n(v___x_1920_, 2);
v___x_1942_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_1942_, 0, v___x_1920_);
lean_ctor_set(v___x_1942_, 1, v___x_1920_);
lean_ctor_set(v___x_1942_, 2, v___x_1920_);
lean_ctor_set(v___x_1942_, 3, v___x_1931_);
lean_ctor_set(v___x_1942_, 4, v___x_1931_);
lean_ctor_set(v___x_1942_, 5, v___x_1931_);
lean_ctor_set(v___x_1942_, 6, v___x_1931_);
lean_ctor_set(v___x_1942_, 7, v___x_1931_);
lean_ctor_set(v___x_1942_, 8, v___x_1931_);
v___x_1943_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1944_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__4_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1945_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_1945_, 0, v___x_1942_);
lean_ctor_set(v___x_1945_, 1, v___x_1943_);
lean_ctor_set(v___x_1945_, 2, v___x_1921_);
lean_ctor_set(v___x_1945_, 3, v___x_1936_);
lean_ctor_set(v___x_1945_, 4, v___x_1944_);
v___x_1946_ = lean_st_mk_ref(v___x_1945_);
v___x_1958_ = l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(v_decl_1922_, v___y_1926_);
v_a_1959_ = lean_ctor_get(v___x_1958_, 0);
lean_inc(v_a_1959_);
lean_dec_ref(v___x_1958_);
if (lean_obj_tag(v_a_1959_) == 1)
{
lean_object* v___x_1960_; lean_object* v___x_1961_; lean_object* v___x_1962_; lean_object* v___x_1963_; lean_object* v___x_1964_; lean_object* v___x_1965_; 
lean_dec_ref(v_a_1959_);
v___x_1960_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__6_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1961_ = l_Lean_MessageData_ofConstName(v_decl_1922_, v___x_1928_);
v___x_1962_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1962_, 0, v___x_1960_);
lean_ctor_set(v___x_1962_, 1, v___x_1961_);
v___x_1963_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1___closed__8_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_1964_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1964_, 0, v___x_1962_);
lean_ctor_set(v___x_1964_, 1, v___x_1963_);
v___x_1965_ = l_Lean_throwError___at___00Lean_Meta_inferRelationInfo_spec__6___redArg(v___x_1964_, v___x_1941_, v___x_1946_, v___y_1925_, v___y_1926_);
lean_dec_ref(v___x_1941_);
v___y_1948_ = v___x_1965_;
goto v___jp_1947_;
}
else
{
lean_object* v___x_1966_; lean_object* v___x_1967_; 
lean_dec(v_a_1959_);
v___x_1966_ = lean_box(0);
v___x_1967_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(v_stx_1923_, v_decl_1922_, v_kind_1924_, v___x_1966_, v___x_1941_, v___x_1946_, v___y_1925_, v___y_1926_);
lean_dec_ref(v___x_1941_);
v___y_1948_ = v___x_1967_;
goto v___jp_1947_;
}
v___jp_1947_:
{
if (lean_obj_tag(v___y_1948_) == 0)
{
lean_object* v_a_1949_; lean_object* v___x_1951_; uint8_t v_isShared_1952_; uint8_t v_isSharedCheck_1957_; 
v_a_1949_ = lean_ctor_get(v___y_1948_, 0);
v_isSharedCheck_1957_ = !lean_is_exclusive(v___y_1948_);
if (v_isSharedCheck_1957_ == 0)
{
v___x_1951_ = v___y_1948_;
v_isShared_1952_ = v_isSharedCheck_1957_;
goto v_resetjp_1950_;
}
else
{
lean_inc(v_a_1949_);
lean_dec(v___y_1948_);
v___x_1951_ = lean_box(0);
v_isShared_1952_ = v_isSharedCheck_1957_;
goto v_resetjp_1950_;
}
v_resetjp_1950_:
{
lean_object* v___x_1953_; lean_object* v___x_1955_; 
v___x_1953_ = lean_st_ref_get(v___x_1946_);
lean_dec(v___x_1946_);
lean_dec(v___x_1953_);
if (v_isShared_1952_ == 0)
{
v___x_1955_ = v___x_1951_;
goto v_reusejp_1954_;
}
else
{
lean_object* v_reuseFailAlloc_1956_; 
v_reuseFailAlloc_1956_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1956_, 0, v_a_1949_);
v___x_1955_ = v_reuseFailAlloc_1956_;
goto v_reusejp_1954_;
}
v_reusejp_1954_:
{
return v___x_1955_;
}
}
}
else
{
lean_dec(v___x_1946_);
return v___y_1948_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object* v___x_1968_, lean_object* v___x_1969_, lean_object* v_decl_1970_, lean_object* v_stx_1971_, lean_object* v_kind_1972_, lean_object* v___y_1973_, lean_object* v___y_1974_, lean_object* v___y_1975_){
_start:
{
uint8_t v_kind_boxed_1976_; lean_object* v_res_1977_; 
v_kind_boxed_1976_ = lean_unbox(v_kind_1972_);
v_res_1977_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(v___x_1968_, v___x_1969_, v_decl_1970_, v_stx_1971_, v_kind_boxed_1976_, v___y_1973_, v___y_1974_);
lean_dec(v___y_1974_);
lean_dec_ref(v___y_1973_);
lean_dec(v_stx_1971_);
return v_res_1977_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3(lean_object* v_msgData_1978_, lean_object* v___y_1979_, lean_object* v___y_1980_){
_start:
{
lean_object* v___x_1982_; lean_object* v_env_1983_; lean_object* v_options_1984_; lean_object* v___x_1985_; lean_object* v___x_1986_; lean_object* v___x_1987_; lean_object* v___x_1988_; lean_object* v___x_1989_; lean_object* v___x_1990_; lean_object* v___x_1991_; 
v___x_1982_ = lean_st_ref_get(v___y_1980_);
v_env_1983_ = lean_ctor_get(v___x_1982_, 0);
lean_inc_ref(v_env_1983_);
lean_dec(v___x_1982_);
v_options_1984_ = lean_ctor_get(v___y_1979_, 2);
v___x_1985_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__2);
v___x_1986_ = lean_unsigned_to_nat(32u);
v___x_1987_ = lean_mk_empty_array_with_capacity(v___x_1986_);
lean_dec_ref(v___x_1987_);
v___x_1988_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstVal___at___00Lean_Meta_inferRelationInfo_spec__0_spec__0_spec__5_spec__20_spec__23_spec__25___redArg___closed__5);
lean_inc_ref(v_options_1984_);
v___x_1989_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1989_, 0, v_env_1983_);
lean_ctor_set(v___x_1989_, 1, v___x_1985_);
lean_ctor_set(v___x_1989_, 2, v___x_1988_);
lean_ctor_set(v___x_1989_, 3, v_options_1984_);
v___x_1990_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_1990_, 0, v___x_1989_);
lean_ctor_set(v___x_1990_, 1, v_msgData_1978_);
v___x_1991_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1991_, 0, v___x_1990_);
return v___x_1991_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3___boxed(lean_object* v_msgData_1992_, lean_object* v___y_1993_, lean_object* v___y_1994_, lean_object* v___y_1995_){
_start:
{
lean_object* v_res_1996_; 
v_res_1996_ = l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3(v_msgData_1992_, v___y_1993_, v___y_1994_);
lean_dec(v___y_1994_);
lean_dec_ref(v___y_1993_);
return v_res_1996_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg(lean_object* v_msg_1997_, lean_object* v___y_1998_, lean_object* v___y_1999_){
_start:
{
lean_object* v_ref_2001_; lean_object* v___x_2002_; lean_object* v_a_2003_; lean_object* v___x_2005_; uint8_t v_isShared_2006_; uint8_t v_isSharedCheck_2011_; 
v_ref_2001_ = lean_ctor_get(v___y_1998_, 5);
v___x_2002_ = l_Lean_addMessageContextPartial___at___00Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2_spec__3(v_msg_1997_, v___y_1998_, v___y_1999_);
v_a_2003_ = lean_ctor_get(v___x_2002_, 0);
v_isSharedCheck_2011_ = !lean_is_exclusive(v___x_2002_);
if (v_isSharedCheck_2011_ == 0)
{
v___x_2005_ = v___x_2002_;
v_isShared_2006_ = v_isSharedCheck_2011_;
goto v_resetjp_2004_;
}
else
{
lean_inc(v_a_2003_);
lean_dec(v___x_2002_);
v___x_2005_ = lean_box(0);
v_isShared_2006_ = v_isSharedCheck_2011_;
goto v_resetjp_2004_;
}
v_resetjp_2004_:
{
lean_object* v___x_2007_; lean_object* v___x_2009_; 
lean_inc(v_ref_2001_);
v___x_2007_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2007_, 0, v_ref_2001_);
lean_ctor_set(v___x_2007_, 1, v_a_2003_);
if (v_isShared_2006_ == 0)
{
lean_ctor_set_tag(v___x_2005_, 1);
lean_ctor_set(v___x_2005_, 0, v___x_2007_);
v___x_2009_ = v___x_2005_;
goto v_reusejp_2008_;
}
else
{
lean_object* v_reuseFailAlloc_2010_; 
v_reuseFailAlloc_2010_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2010_, 0, v___x_2007_);
v___x_2009_ = v_reuseFailAlloc_2010_;
goto v_reusejp_2008_;
}
v_reusejp_2008_:
{
return v___x_2009_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg___boxed(lean_object* v_msg_2012_, lean_object* v___y_2013_, lean_object* v___y_2014_, lean_object* v___y_2015_){
_start:
{
lean_object* v_res_2016_; 
v_res_2016_ = l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg(v_msg_2012_, v___y_2013_, v___y_2014_);
lean_dec(v___y_2014_);
lean_dec_ref(v___y_2013_);
return v_res_2016_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_2018_; lean_object* v___x_2019_; 
v___x_2018_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_2019_ = l_Lean_stringToMessageData(v___x_2018_);
return v___x_2019_;
}
}
static lean_object* _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(void){
_start:
{
lean_object* v___x_2021_; lean_object* v___x_2022_; 
v___x_2021_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_2022_ = l_Lean_stringToMessageData(v___x_2021_);
return v___x_2022_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(lean_object* v___x_2023_, lean_object* v_decl_2024_, lean_object* v___y_2025_, lean_object* v___y_2026_){
_start:
{
lean_object* v___x_2028_; lean_object* v___x_2029_; lean_object* v___x_2030_; lean_object* v___x_2031_; lean_object* v___x_2032_; lean_object* v___x_2033_; 
v___x_2028_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_2029_ = l_Lean_MessageData_ofName(v___x_2023_);
v___x_2030_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2030_, 0, v___x_2028_);
lean_ctor_set(v___x_2030_, 1, v___x_2029_);
v___x_2031_ = lean_obj_once(&l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_, &l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__once, _init_l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2___closed__3_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_);
v___x_2032_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2032_, 0, v___x_2030_);
lean_ctor_set(v___x_2032_, 1, v___x_2031_);
v___x_2033_ = l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg(v___x_2032_, v___y_2025_, v___y_2026_);
return v___x_2033_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object* v___x_2034_, lean_object* v_decl_2035_, lean_object* v___y_2036_, lean_object* v___y_2037_, lean_object* v___y_2038_){
_start:
{
lean_object* v_res_2039_; 
v_res_2039_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___lam__2_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(v___x_2034_, v_decl_2035_, v___y_2036_, v___y_2037_);
lean_dec(v___y_2037_);
lean_dec_ref(v___y_2036_);
lean_dec(v_decl_2035_);
return v_res_2039_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_2118_; lean_object* v___x_2119_; 
v___x_2118_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__29_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_2119_ = l_Lean_registerBuiltinAttribute(v___x_2118_);
return v___x_2119_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object* v_a_2120_){
_start:
{
lean_object* v_res_2121_; 
v_res_2121_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
return v_res_2121_;
}
}
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0(lean_object* v_00_u03b1_2122_, lean_object* v_00_u03b2_2123_, lean_object* v_00_u03c3_2124_, lean_object* v_ext_2125_, lean_object* v_b_2126_, uint8_t v_kind_2127_, lean_object* v___y_2128_, lean_object* v___y_2129_, lean_object* v___y_2130_, lean_object* v___y_2131_){
_start:
{
lean_object* v___x_2133_; 
lean_inc_ref(v___y_2130_);
v___x_2133_ = l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___redArg(v_ext_2125_, v_b_2126_, v_kind_2127_, v___y_2129_, v___y_2130_, v___y_2131_);
return v___x_2133_;
}
}
LEAN_EXPORT lean_object* l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0___boxed(lean_object* v_00_u03b1_2134_, lean_object* v_00_u03b2_2135_, lean_object* v_00_u03c3_2136_, lean_object* v_ext_2137_, lean_object* v_b_2138_, lean_object* v_kind_2139_, lean_object* v___y_2140_, lean_object* v___y_2141_, lean_object* v___y_2142_, lean_object* v___y_2143_, lean_object* v___y_2144_){
_start:
{
uint8_t v_kind_boxed_2145_; lean_object* v_res_2146_; 
v_kind_boxed_2145_ = lean_unbox(v_kind_2139_);
v_res_2146_ = l_Lean_ScopedEnvExtension_add___at___00Lean_Meta_registerRelation___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__0_spec__0(v_00_u03b1_2134_, v_00_u03b2_2135_, v_00_u03c3_2136_, v_ext_2137_, v_b_2138_, v_kind_boxed_2145_, v___y_2140_, v___y_2141_, v___y_2142_, v___y_2143_);
lean_dec(v___y_2143_);
lean_dec_ref(v___y_2142_);
lean_dec(v___y_2141_);
lean_dec_ref(v___y_2140_);
return v_res_2146_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2(lean_object* v_00_u03b1_2147_, lean_object* v_msg_2148_, lean_object* v___y_2149_, lean_object* v___y_2150_){
_start:
{
lean_object* v___x_2152_; 
v___x_2152_ = l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___redArg(v_msg_2148_, v___y_2149_, v___y_2150_);
return v___x_2152_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2___boxed(lean_object* v_00_u03b1_2153_, lean_object* v_msg_2154_, lean_object* v___y_2155_, lean_object* v___y_2156_, lean_object* v___y_2157_){
_start:
{
lean_object* v_res_2158_; 
v_res_2158_ = l_Lean_throwError___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__2(v_00_u03b1_2153_, v_msg_2154_, v___y_2155_, v___y_2156_);
lean_dec(v___y_2156_);
lean_dec_ref(v___y_2155_);
return v_res_2158_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_2161_; lean_object* v___x_2162_; lean_object* v___x_2163_; 
v___x_2161_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__24_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_2162_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1___closed__0_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_));
v___x_2163_ = l_Lean_addBuiltinDocString(v___x_2161_, v___x_2162_);
return v___x_2163_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2____boxed(lean_object* v_a_2164_){
_start:
{
lean_object* v_res_2165_; 
v_res_2165_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
return v_res_2165_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(lean_object* v_declName_2166_, lean_object* v_info_2167_, lean_object* v_e_2168_){
_start:
{
lean_object* v_numArgs_2169_; lean_object* v_relArgs_2170_; lean_object* v_lhsIdx_2171_; lean_object* v_rhsIdx_2172_; lean_object* v___x_2173_; uint8_t v___x_2174_; 
v_numArgs_2169_ = lean_ctor_get(v_info_2167_, 0);
v_relArgs_2170_ = lean_ctor_get(v_info_2167_, 1);
v_lhsIdx_2171_ = lean_ctor_get(v_info_2167_, 2);
v_rhsIdx_2172_ = lean_ctor_get(v_info_2167_, 3);
v___x_2173_ = l_Lean_Expr_getAppNumArgs(v_e_2168_);
v___x_2174_ = lean_nat_dec_eq(v___x_2173_, v_numArgs_2169_);
if (v___x_2174_ == 0)
{
lean_object* v___x_2175_; 
lean_dec(v___x_2173_);
lean_dec_ref(v_info_2167_);
lean_dec(v_declName_2166_);
v___x_2175_ = lean_box(0);
return v___x_2175_;
}
else
{
lean_object* v_rel_2176_; lean_object* v___x_2177_; lean_object* v___x_2178_; lean_object* v___x_2179_; lean_object* v_lhs_2180_; lean_object* v___x_2181_; lean_object* v___x_2182_; lean_object* v_rhs_2183_; lean_object* v___x_2184_; lean_object* v___x_2185_; 
v_rel_2176_ = l_Lean_Expr_getAppPrefix(v_e_2168_, v_relArgs_2170_);
v___x_2177_ = lean_nat_sub(v___x_2173_, v_lhsIdx_2171_);
v___x_2178_ = lean_unsigned_to_nat(1u);
v___x_2179_ = lean_nat_sub(v___x_2177_, v___x_2178_);
lean_dec(v___x_2177_);
v_lhs_2180_ = l_Lean_Expr_getRevArg_x21(v_e_2168_, v___x_2179_);
v___x_2181_ = lean_nat_sub(v___x_2173_, v_rhsIdx_2172_);
lean_dec(v___x_2173_);
v___x_2182_ = lean_nat_sub(v___x_2181_, v___x_2178_);
lean_dec(v___x_2181_);
v_rhs_2183_ = l_Lean_Expr_getRevArg_x21(v_e_2168_, v___x_2182_);
v___x_2184_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v___x_2184_, 0, v_info_2167_);
lean_ctor_set(v___x_2184_, 1, v_declName_2166_);
lean_ctor_set(v___x_2184_, 2, v_rel_2176_);
lean_ctor_set(v___x_2184_, 3, v_lhs_2180_);
lean_ctor_set(v___x_2184_, 4, v_rhs_2183_);
v___x_2185_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2185_, 0, v___x_2184_);
return v___x_2185_;
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation___boxed(lean_object* v_declName_2186_, lean_object* v_info_2187_, lean_object* v_e_2188_){
_start:
{
lean_object* v_res_2189_; 
v_res_2189_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(v_declName_2186_, v_info_2187_, v_e_2188_);
lean_dec_ref(v_e_2188_);
return v_res_2189_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg___lam__0(lean_object* v_declName_2190_, lean_object* v_e_2191_, lean_object* v_toPure_2192_, lean_object* v_____x_2193_){
_start:
{
if (lean_obj_tag(v_____x_2193_) == 1)
{
lean_object* v_val_2194_; lean_object* v___x_2195_; lean_object* v___x_2196_; 
v_val_2194_ = lean_ctor_get(v_____x_2193_, 0);
lean_inc(v_val_2194_);
lean_dec_ref(v_____x_2193_);
v___x_2195_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(v_declName_2190_, v_val_2194_, v_e_2191_);
v___x_2196_ = lean_apply_2(v_toPure_2192_, lean_box(0), v___x_2195_);
return v___x_2196_;
}
else
{
lean_object* v___x_2197_; lean_object* v___x_2198_; 
lean_dec(v_____x_2193_);
lean_dec(v_declName_2190_);
v___x_2197_ = lean_box(0);
v___x_2198_ = lean_apply_2(v_toPure_2192_, lean_box(0), v___x_2197_);
return v___x_2198_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg___lam__0___boxed(lean_object* v_declName_2199_, lean_object* v_e_2200_, lean_object* v_toPure_2201_, lean_object* v_____x_2202_){
_start:
{
lean_object* v_res_2203_; 
v_res_2203_ = l_Lean_Meta_matchesRelation_x3f___redArg___lam__0(v_declName_2199_, v_e_2200_, v_toPure_2201_, v_____x_2202_);
lean_dec_ref(v_e_2200_);
return v_res_2203_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f___redArg(lean_object* v_inst_2204_, lean_object* v_inst_2205_, lean_object* v_e_2206_){
_start:
{
lean_object* v_toApplicative_2207_; lean_object* v_toBind_2208_; lean_object* v_toPure_2209_; lean_object* v___x_2210_; 
v_toApplicative_2207_ = lean_ctor_get(v_inst_2204_, 0);
v_toBind_2208_ = lean_ctor_get(v_inst_2204_, 1);
lean_inc(v_toBind_2208_);
v_toPure_2209_ = lean_ctor_get(v_toApplicative_2207_, 1);
v___x_2210_ = l_Lean_Expr_getAppFn(v_e_2206_);
if (lean_obj_tag(v___x_2210_) == 4)
{
lean_object* v_declName_2211_; lean_object* v___f_2212_; lean_object* v___x_2213_; lean_object* v___x_2214_; 
v_declName_2211_ = lean_ctor_get(v___x_2210_, 0);
lean_inc(v_declName_2211_);
lean_dec_ref(v___x_2210_);
lean_inc(v_toPure_2209_);
lean_inc(v_declName_2211_);
v___f_2212_ = lean_alloc_closure((void*)(l_Lean_Meta_matchesRelation_x3f___redArg___lam__0___boxed), 4, 3);
lean_closure_set(v___f_2212_, 0, v_declName_2211_);
lean_closure_set(v___f_2212_, 1, v_e_2206_);
lean_closure_set(v___f_2212_, 2, v_toPure_2209_);
v___x_2213_ = l_Lean_Meta_getRelationInfo_x3f___redArg(v_inst_2204_, v_inst_2205_, v_declName_2211_);
v___x_2214_ = lean_apply_4(v_toBind_2208_, lean_box(0), lean_box(0), v___x_2213_, v___f_2212_);
return v___x_2214_;
}
else
{
lean_object* v___x_2215_; lean_object* v___x_2216_; 
lean_inc(v_toPure_2209_);
lean_dec_ref(v___x_2210_);
lean_dec(v_toBind_2208_);
lean_dec_ref(v_e_2206_);
lean_dec_ref(v_inst_2205_);
lean_dec_ref(v_inst_2204_);
v___x_2215_ = lean_box(0);
v___x_2216_ = lean_apply_2(v_toPure_2209_, lean_box(0), v___x_2215_);
return v___x_2216_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesRelation_x3f(lean_object* v_m_2217_, lean_object* v_inst_2218_, lean_object* v_inst_2219_, lean_object* v_e_2220_){
_start:
{
lean_object* v___x_2221_; 
v___x_2221_ = l_Lean_Meta_matchesRelation_x3f___redArg(v_inst_2218_, v_inst_2219_, v_e_2220_);
return v___x_2221_;
}
}
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg(lean_object* v_x_2222_, lean_object* v___y_2223_, lean_object* v___y_2224_, lean_object* v___y_2225_, lean_object* v___y_2226_){
_start:
{
lean_object* v___x_2228_; 
v___x_2228_ = l_Lean_Meta_saveState___redArg(v___y_2224_, v___y_2226_);
if (lean_obj_tag(v___x_2228_) == 0)
{
lean_object* v_a_2229_; lean_object* v_r_2230_; 
v_a_2229_ = lean_ctor_get(v___x_2228_, 0);
lean_inc(v_a_2229_);
lean_dec_ref(v___x_2228_);
lean_inc(v___y_2226_);
lean_inc_ref(v___y_2225_);
lean_inc(v___y_2224_);
lean_inc_ref(v___y_2223_);
v_r_2230_ = lean_apply_5(v_x_2222_, v___y_2223_, v___y_2224_, v___y_2225_, v___y_2226_, lean_box(0));
if (lean_obj_tag(v_r_2230_) == 0)
{
lean_object* v_a_2231_; lean_object* v___x_2232_; 
v_a_2231_ = lean_ctor_get(v_r_2230_, 0);
lean_inc(v_a_2231_);
lean_dec_ref(v_r_2230_);
v___x_2232_ = l_Lean_Meta_SavedState_restore___redArg(v_a_2229_, v___y_2224_, v___y_2226_);
lean_dec(v_a_2229_);
if (lean_obj_tag(v___x_2232_) == 0)
{
lean_object* v___x_2234_; uint8_t v_isShared_2235_; uint8_t v_isSharedCheck_2239_; 
v_isSharedCheck_2239_ = !lean_is_exclusive(v___x_2232_);
if (v_isSharedCheck_2239_ == 0)
{
lean_object* v_unused_2240_; 
v_unused_2240_ = lean_ctor_get(v___x_2232_, 0);
lean_dec(v_unused_2240_);
v___x_2234_ = v___x_2232_;
v_isShared_2235_ = v_isSharedCheck_2239_;
goto v_resetjp_2233_;
}
else
{
lean_dec(v___x_2232_);
v___x_2234_ = lean_box(0);
v_isShared_2235_ = v_isSharedCheck_2239_;
goto v_resetjp_2233_;
}
v_resetjp_2233_:
{
lean_object* v___x_2237_; 
if (v_isShared_2235_ == 0)
{
lean_ctor_set(v___x_2234_, 0, v_a_2231_);
v___x_2237_ = v___x_2234_;
goto v_reusejp_2236_;
}
else
{
lean_object* v_reuseFailAlloc_2238_; 
v_reuseFailAlloc_2238_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2238_, 0, v_a_2231_);
v___x_2237_ = v_reuseFailAlloc_2238_;
goto v_reusejp_2236_;
}
v_reusejp_2236_:
{
return v___x_2237_;
}
}
}
else
{
lean_object* v_a_2241_; lean_object* v___x_2243_; uint8_t v_isShared_2244_; uint8_t v_isSharedCheck_2248_; 
lean_dec(v_a_2231_);
v_a_2241_ = lean_ctor_get(v___x_2232_, 0);
v_isSharedCheck_2248_ = !lean_is_exclusive(v___x_2232_);
if (v_isSharedCheck_2248_ == 0)
{
v___x_2243_ = v___x_2232_;
v_isShared_2244_ = v_isSharedCheck_2248_;
goto v_resetjp_2242_;
}
else
{
lean_inc(v_a_2241_);
lean_dec(v___x_2232_);
v___x_2243_ = lean_box(0);
v_isShared_2244_ = v_isSharedCheck_2248_;
goto v_resetjp_2242_;
}
v_resetjp_2242_:
{
lean_object* v___x_2246_; 
if (v_isShared_2244_ == 0)
{
v___x_2246_ = v___x_2243_;
goto v_reusejp_2245_;
}
else
{
lean_object* v_reuseFailAlloc_2247_; 
v_reuseFailAlloc_2247_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2247_, 0, v_a_2241_);
v___x_2246_ = v_reuseFailAlloc_2247_;
goto v_reusejp_2245_;
}
v_reusejp_2245_:
{
return v___x_2246_;
}
}
}
}
else
{
lean_object* v_a_2249_; lean_object* v___x_2250_; 
v_a_2249_ = lean_ctor_get(v_r_2230_, 0);
lean_inc(v_a_2249_);
lean_dec_ref(v_r_2230_);
v___x_2250_ = l_Lean_Meta_SavedState_restore___redArg(v_a_2229_, v___y_2224_, v___y_2226_);
lean_dec(v_a_2229_);
if (lean_obj_tag(v___x_2250_) == 0)
{
lean_object* v___x_2252_; uint8_t v_isShared_2253_; uint8_t v_isSharedCheck_2257_; 
v_isSharedCheck_2257_ = !lean_is_exclusive(v___x_2250_);
if (v_isSharedCheck_2257_ == 0)
{
lean_object* v_unused_2258_; 
v_unused_2258_ = lean_ctor_get(v___x_2250_, 0);
lean_dec(v_unused_2258_);
v___x_2252_ = v___x_2250_;
v_isShared_2253_ = v_isSharedCheck_2257_;
goto v_resetjp_2251_;
}
else
{
lean_dec(v___x_2250_);
v___x_2252_ = lean_box(0);
v_isShared_2253_ = v_isSharedCheck_2257_;
goto v_resetjp_2251_;
}
v_resetjp_2251_:
{
lean_object* v___x_2255_; 
if (v_isShared_2253_ == 0)
{
lean_ctor_set_tag(v___x_2252_, 1);
lean_ctor_set(v___x_2252_, 0, v_a_2249_);
v___x_2255_ = v___x_2252_;
goto v_reusejp_2254_;
}
else
{
lean_object* v_reuseFailAlloc_2256_; 
v_reuseFailAlloc_2256_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2256_, 0, v_a_2249_);
v___x_2255_ = v_reuseFailAlloc_2256_;
goto v_reusejp_2254_;
}
v_reusejp_2254_:
{
return v___x_2255_;
}
}
}
else
{
lean_object* v_a_2259_; lean_object* v___x_2261_; uint8_t v_isShared_2262_; uint8_t v_isSharedCheck_2266_; 
lean_dec(v_a_2249_);
v_a_2259_ = lean_ctor_get(v___x_2250_, 0);
v_isSharedCheck_2266_ = !lean_is_exclusive(v___x_2250_);
if (v_isSharedCheck_2266_ == 0)
{
v___x_2261_ = v___x_2250_;
v_isShared_2262_ = v_isSharedCheck_2266_;
goto v_resetjp_2260_;
}
else
{
lean_inc(v_a_2259_);
lean_dec(v___x_2250_);
v___x_2261_ = lean_box(0);
v_isShared_2262_ = v_isSharedCheck_2266_;
goto v_resetjp_2260_;
}
v_resetjp_2260_:
{
lean_object* v___x_2264_; 
if (v_isShared_2262_ == 0)
{
v___x_2264_ = v___x_2261_;
goto v_reusejp_2263_;
}
else
{
lean_object* v_reuseFailAlloc_2265_; 
v_reuseFailAlloc_2265_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2265_, 0, v_a_2259_);
v___x_2264_ = v_reuseFailAlloc_2265_;
goto v_reusejp_2263_;
}
v_reusejp_2263_:
{
return v___x_2264_;
}
}
}
}
}
else
{
lean_object* v_a_2267_; lean_object* v___x_2269_; uint8_t v_isShared_2270_; uint8_t v_isSharedCheck_2274_; 
lean_dec_ref(v_x_2222_);
v_a_2267_ = lean_ctor_get(v___x_2228_, 0);
v_isSharedCheck_2274_ = !lean_is_exclusive(v___x_2228_);
if (v_isSharedCheck_2274_ == 0)
{
v___x_2269_ = v___x_2228_;
v_isShared_2270_ = v_isSharedCheck_2274_;
goto v_resetjp_2268_;
}
else
{
lean_inc(v_a_2267_);
lean_dec(v___x_2228_);
v___x_2269_ = lean_box(0);
v_isShared_2270_ = v_isSharedCheck_2274_;
goto v_resetjp_2268_;
}
v_resetjp_2268_:
{
lean_object* v___x_2272_; 
if (v_isShared_2270_ == 0)
{
v___x_2272_ = v___x_2269_;
goto v_reusejp_2271_;
}
else
{
lean_object* v_reuseFailAlloc_2273_; 
v_reuseFailAlloc_2273_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2273_, 0, v_a_2267_);
v___x_2272_ = v_reuseFailAlloc_2273_;
goto v_reusejp_2271_;
}
v_reusejp_2271_:
{
return v___x_2272_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg___boxed(lean_object* v_x_2275_, lean_object* v___y_2276_, lean_object* v___y_2277_, lean_object* v___y_2278_, lean_object* v___y_2279_, lean_object* v___y_2280_){
_start:
{
lean_object* v_res_2281_; 
v_res_2281_ = l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg(v_x_2275_, v___y_2276_, v___y_2277_, v___y_2278_, v___y_2279_);
lean_dec(v___y_2279_);
lean_dec_ref(v___y_2278_);
lean_dec(v___y_2277_);
lean_dec_ref(v___y_2276_);
return v_res_2281_;
}
}
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0(lean_object* v_00_u03b1_2282_, lean_object* v_x_2283_, lean_object* v___y_2284_, lean_object* v___y_2285_, lean_object* v___y_2286_, lean_object* v___y_2287_){
_start:
{
lean_object* v___x_2289_; 
v___x_2289_ = l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg(v_x_2283_, v___y_2284_, v___y_2285_, v___y_2286_, v___y_2287_);
return v___x_2289_;
}
}
LEAN_EXPORT lean_object* l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___boxed(lean_object* v_00_u03b1_2290_, lean_object* v_x_2291_, lean_object* v___y_2292_, lean_object* v___y_2293_, lean_object* v___y_2294_, lean_object* v___y_2295_, lean_object* v___y_2296_){
_start:
{
lean_object* v_res_2297_; 
v_res_2297_ = l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0(v_00_u03b1_2290_, v_x_2291_, v___y_2292_, v___y_2293_, v___y_2294_, v___y_2295_);
lean_dec(v___y_2295_);
lean_dec_ref(v___y_2294_);
lean_dec(v___y_2293_);
lean_dec_ref(v___y_2292_);
return v_res_2297_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesPotentialRelation_x3f(lean_object* v_e_2300_, lean_object* v_a_2301_, lean_object* v_a_2302_, lean_object* v_a_2303_, lean_object* v_a_2304_){
_start:
{
lean_object* v___x_2306_; 
v___x_2306_ = l_Lean_Meta_whnfCore(v_e_2300_, v_a_2301_, v_a_2302_, v_a_2303_, v_a_2304_);
if (lean_obj_tag(v___x_2306_) == 0)
{
lean_object* v_a_2307_; lean_object* v___x_2309_; uint8_t v_isShared_2310_; uint8_t v_isSharedCheck_2356_; 
v_a_2307_ = lean_ctor_get(v___x_2306_, 0);
v_isSharedCheck_2356_ = !lean_is_exclusive(v___x_2306_);
if (v_isSharedCheck_2356_ == 0)
{
v___x_2309_ = v___x_2306_;
v_isShared_2310_ = v_isSharedCheck_2356_;
goto v_resetjp_2308_;
}
else
{
lean_inc(v_a_2307_);
lean_dec(v___x_2306_);
v___x_2309_ = lean_box(0);
v_isShared_2310_ = v_isSharedCheck_2356_;
goto v_resetjp_2308_;
}
v_resetjp_2308_:
{
lean_object* v___x_2311_; 
v___x_2311_ = l_Lean_Expr_getAppFn(v_a_2307_);
if (lean_obj_tag(v___x_2311_) == 4)
{
lean_object* v_declName_2312_; lean_object* v___x_2313_; lean_object* v_a_2314_; lean_object* v___x_2316_; uint8_t v_isShared_2317_; uint8_t v_isSharedCheck_2351_; 
lean_del_object(v___x_2309_);
v_declName_2312_ = lean_ctor_get(v___x_2311_, 0);
lean_inc(v_declName_2312_);
lean_dec_ref(v___x_2311_);
v___x_2313_ = l_Lean_Meta_getRelationInfo_x3f___at___00__private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2__spec__1___redArg(v_declName_2312_, v_a_2304_);
v_a_2314_ = lean_ctor_get(v___x_2313_, 0);
v_isSharedCheck_2351_ = !lean_is_exclusive(v___x_2313_);
if (v_isSharedCheck_2351_ == 0)
{
v___x_2316_ = v___x_2313_;
v_isShared_2317_ = v_isSharedCheck_2351_;
goto v_resetjp_2315_;
}
else
{
lean_inc(v_a_2314_);
lean_dec(v___x_2313_);
v___x_2316_ = lean_box(0);
v_isShared_2317_ = v_isSharedCheck_2351_;
goto v_resetjp_2315_;
}
v_resetjp_2315_:
{
if (lean_obj_tag(v_a_2314_) == 1)
{
lean_object* v_val_2318_; lean_object* v___x_2319_; lean_object* v___x_2321_; 
v_val_2318_ = lean_ctor_get(v_a_2314_, 0);
lean_inc(v_val_2318_);
lean_dec_ref(v_a_2314_);
v___x_2319_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(v_declName_2312_, v_val_2318_, v_a_2307_);
lean_dec(v_a_2307_);
if (v_isShared_2317_ == 0)
{
lean_ctor_set(v___x_2316_, 0, v___x_2319_);
v___x_2321_ = v___x_2316_;
goto v_reusejp_2320_;
}
else
{
lean_object* v_reuseFailAlloc_2322_; 
v_reuseFailAlloc_2322_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2322_, 0, v___x_2319_);
v___x_2321_ = v_reuseFailAlloc_2322_;
goto v_reusejp_2320_;
}
v_reusejp_2320_:
{
return v___x_2321_;
}
}
else
{
lean_object* v___x_2323_; lean_object* v___x_2324_; lean_object* v___x_2325_; 
lean_del_object(v___x_2316_);
lean_dec(v_a_2314_);
v___x_2323_ = ((lean_object*)(l_Lean_Meta_matchesPotentialRelation_x3f___closed__0));
lean_inc(v_declName_2312_);
v___x_2324_ = lean_alloc_closure((void*)(l_Lean_Meta_inferRelationInfo___boxed), 7, 2);
lean_closure_set(v___x_2324_, 0, v_declName_2312_);
lean_closure_set(v___x_2324_, 1, v___x_2323_);
v___x_2325_ = l_Lean_withoutModifyingState___at___00Lean_Meta_matchesPotentialRelation_x3f_spec__0___redArg(v___x_2324_, v_a_2301_, v_a_2302_, v_a_2303_, v_a_2304_);
if (lean_obj_tag(v___x_2325_) == 0)
{
lean_object* v_a_2326_; lean_object* v___x_2328_; uint8_t v_isShared_2329_; uint8_t v_isSharedCheck_2334_; 
v_a_2326_ = lean_ctor_get(v___x_2325_, 0);
v_isSharedCheck_2334_ = !lean_is_exclusive(v___x_2325_);
if (v_isSharedCheck_2334_ == 0)
{
v___x_2328_ = v___x_2325_;
v_isShared_2329_ = v_isSharedCheck_2334_;
goto v_resetjp_2327_;
}
else
{
lean_inc(v_a_2326_);
lean_dec(v___x_2325_);
v___x_2328_ = lean_box(0);
v_isShared_2329_ = v_isSharedCheck_2334_;
goto v_resetjp_2327_;
}
v_resetjp_2327_:
{
lean_object* v___x_2330_; lean_object* v___x_2332_; 
v___x_2330_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_decomposeRelation(v_declName_2312_, v_a_2326_, v_a_2307_);
lean_dec(v_a_2307_);
if (v_isShared_2329_ == 0)
{
lean_ctor_set(v___x_2328_, 0, v___x_2330_);
v___x_2332_ = v___x_2328_;
goto v_reusejp_2331_;
}
else
{
lean_object* v_reuseFailAlloc_2333_; 
v_reuseFailAlloc_2333_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2333_, 0, v___x_2330_);
v___x_2332_ = v_reuseFailAlloc_2333_;
goto v_reusejp_2331_;
}
v_reusejp_2331_:
{
return v___x_2332_;
}
}
}
else
{
lean_object* v_a_2335_; lean_object* v___x_2337_; uint8_t v_isShared_2338_; uint8_t v_isSharedCheck_2350_; 
lean_dec(v_declName_2312_);
lean_dec(v_a_2307_);
v_a_2335_ = lean_ctor_get(v___x_2325_, 0);
v_isSharedCheck_2350_ = !lean_is_exclusive(v___x_2325_);
if (v_isSharedCheck_2350_ == 0)
{
v___x_2337_ = v___x_2325_;
v_isShared_2338_ = v_isSharedCheck_2350_;
goto v_resetjp_2336_;
}
else
{
lean_inc(v_a_2335_);
lean_dec(v___x_2325_);
v___x_2337_ = lean_box(0);
v_isShared_2338_ = v_isSharedCheck_2350_;
goto v_resetjp_2336_;
}
v_resetjp_2336_:
{
uint8_t v___y_2340_; uint8_t v___x_2348_; 
v___x_2348_ = l_Lean_Exception_isInterrupt(v_a_2335_);
if (v___x_2348_ == 0)
{
uint8_t v___x_2349_; 
lean_inc(v_a_2335_);
v___x_2349_ = l_Lean_Exception_isRuntime(v_a_2335_);
v___y_2340_ = v___x_2349_;
goto v___jp_2339_;
}
else
{
v___y_2340_ = v___x_2348_;
goto v___jp_2339_;
}
v___jp_2339_:
{
if (v___y_2340_ == 0)
{
lean_object* v___x_2341_; lean_object* v___x_2343_; 
lean_dec(v_a_2335_);
v___x_2341_ = lean_box(0);
if (v_isShared_2338_ == 0)
{
lean_ctor_set_tag(v___x_2337_, 0);
lean_ctor_set(v___x_2337_, 0, v___x_2341_);
v___x_2343_ = v___x_2337_;
goto v_reusejp_2342_;
}
else
{
lean_object* v_reuseFailAlloc_2344_; 
v_reuseFailAlloc_2344_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2344_, 0, v___x_2341_);
v___x_2343_ = v_reuseFailAlloc_2344_;
goto v_reusejp_2342_;
}
v_reusejp_2342_:
{
return v___x_2343_;
}
}
else
{
lean_object* v___x_2346_; 
if (v_isShared_2338_ == 0)
{
v___x_2346_ = v___x_2337_;
goto v_reusejp_2345_;
}
else
{
lean_object* v_reuseFailAlloc_2347_; 
v_reuseFailAlloc_2347_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2347_, 0, v_a_2335_);
v___x_2346_ = v_reuseFailAlloc_2347_;
goto v_reusejp_2345_;
}
v_reusejp_2345_:
{
return v___x_2346_;
}
}
}
}
}
}
}
}
else
{
lean_object* v___x_2352_; lean_object* v___x_2354_; 
lean_dec_ref(v___x_2311_);
lean_dec(v_a_2307_);
v___x_2352_ = lean_box(0);
if (v_isShared_2310_ == 0)
{
lean_ctor_set(v___x_2309_, 0, v___x_2352_);
v___x_2354_ = v___x_2309_;
goto v_reusejp_2353_;
}
else
{
lean_object* v_reuseFailAlloc_2355_; 
v_reuseFailAlloc_2355_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2355_, 0, v___x_2352_);
v___x_2354_ = v_reuseFailAlloc_2355_;
goto v_reusejp_2353_;
}
v_reusejp_2353_:
{
return v___x_2354_;
}
}
}
}
else
{
lean_object* v_a_2357_; lean_object* v___x_2359_; uint8_t v_isShared_2360_; uint8_t v_isSharedCheck_2364_; 
v_a_2357_ = lean_ctor_get(v___x_2306_, 0);
v_isSharedCheck_2364_ = !lean_is_exclusive(v___x_2306_);
if (v_isSharedCheck_2364_ == 0)
{
v___x_2359_ = v___x_2306_;
v_isShared_2360_ = v_isSharedCheck_2364_;
goto v_resetjp_2358_;
}
else
{
lean_inc(v_a_2357_);
lean_dec(v___x_2306_);
v___x_2359_ = lean_box(0);
v_isShared_2360_ = v_isSharedCheck_2364_;
goto v_resetjp_2358_;
}
v_resetjp_2358_:
{
lean_object* v___x_2362_; 
if (v_isShared_2360_ == 0)
{
v___x_2362_ = v___x_2359_;
goto v_reusejp_2361_;
}
else
{
lean_object* v_reuseFailAlloc_2363_; 
v_reuseFailAlloc_2363_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2363_, 0, v_a_2357_);
v___x_2362_ = v_reuseFailAlloc_2363_;
goto v_reusejp_2361_;
}
v_reusejp_2361_:
{
return v___x_2362_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_matchesPotentialRelation_x3f___boxed(lean_object* v_e_2365_, lean_object* v_a_2366_, lean_object* v_a_2367_, lean_object* v_a_2368_, lean_object* v_a_2369_, lean_object* v_a_2370_){
_start:
{
lean_object* v_res_2371_; 
v_res_2371_ = l_Lean_Meta_matchesPotentialRelation_x3f(v_e_2365_, v_a_2366_, v_a_2367_, v_a_2368_, v_a_2369_);
lean_dec(v_a_2369_);
lean_dec_ref(v_a_2368_);
lean_dec(v_a_2367_);
lean_dec_ref(v_a_2366_);
return v_res_2371_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_2385_; uint8_t v___x_2386_; lean_object* v___x_2387_; lean_object* v___x_2388_; 
v___x_2385_ = ((lean_object*)(l_Lean_Meta_inferRelationInfo___lam__2___closed__2));
v___x_2386_ = 0;
v___x_2387_ = ((lean_object*)(l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_));
v___x_2388_ = l_Lean_registerTraceClass(v___x_2385_, v___x_2386_, v___x_2387_);
return v___x_2388_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2____boxed(lean_object* v_a_2389_){
_start:
{
lean_object* v_res_2390_; 
v_res_2390_ = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_();
return v_res_2390_;
}
}
lean_object* runtime_initialize_Lean_Meta_WHNF(uint8_t builtin);
lean_object* runtime_initialize_Lean_Meta_CollectFVars(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_Lean_Meta_Tactic_Relations(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Lean_Meta_WHNF(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Meta_CollectFVars(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = l_Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_607290394____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
l_Lean_Meta_relationExt = lean_io_result_get_value(res);
lean_mark_persistent(l_Lean_Meta_relationExt);
lean_dec_ref(res);
res = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn___regBuiltin___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_docString__1_00___x40_Lean_Meta_Tactic_Relations_907532441____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = l___private_Lean_Meta_Tactic_Relations_0__Lean_Meta_initFn_00___x40_Lean_Meta_Tactic_Relations_343174607____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_Lean_Meta_Tactic_Relations(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Lean_Meta_WHNF(uint8_t builtin);
lean_object* initialize_Lean_Meta_CollectFVars(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_Lean_Meta_Tactic_Relations(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Lean_Meta_WHNF(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Meta_CollectFVars(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Meta_Tactic_Relations(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_Lean_Meta_Tactic_Relations(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_Lean_Meta_Tactic_Relations(builtin);
}
#ifdef __cplusplus
}
#endif
