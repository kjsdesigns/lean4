// Lean compiler output
// Module: Lean.Meta.InstanceNormalForm
// Imports: public import Lean.Meta.Closure public import Lean.Meta.SynthInstance public import Lean.Meta.CtorRecognizer
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
lean_object* lean_st_ref_take(lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_object*, lean_object*);
uint8_t l_Lean_Name_isAnonymous(lean_object*);
lean_object* l_Lean_Environment_setExporting(lean_object*, uint8_t);
uint8_t l_Lean_Environment_contains(lean_object*, lean_object*, uint8_t);
extern lean_object* l_Lean_Options_empty;
lean_object* l_Lean_MessageData_ofConstName(lean_object*, uint8_t);
lean_object* l_Lean_Environment_getModuleIdxFor_x3f(lean_object*, lean_object*);
lean_object* l_Lean_stringToMessageData(lean_object*);
lean_object* l_Lean_MessageData_note(lean_object*);
lean_object* l_Lean_Environment_header(lean_object*);
lean_object* l_Lean_EnvironmentHeader_moduleNames(lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_isPrivateName(lean_object*);
lean_object* l_Lean_MessageData_ofName(lean_object*);
extern lean_object* l_Lean_unknownIdentifierMessageTag;
lean_object* l_Lean_replaceRef(lean_object*, lean_object*);
lean_object* l_Lean_Environment_find_x3f(lean_object*, lean_object*, uint8_t);
lean_object* l_Lean_Name_str___override(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr2(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr4(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_register_option(lean_object*, lean_object*);
lean_object* l_Lean_DeclNameGenerator_mkUniqueName(lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
uint8_t l_Lean_instBEqMVarId_beq(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_array_fset(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l___private_Lean_ReducibilityAttrs_0__Lean_setReducibilityStatusCore(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*);
uint64_t l_Lean_instHashableMVarId_hash(lean_object*);
size_t lean_uint64_to_usize(uint64_t);
size_t lean_usize_shift_left(size_t, size_t);
size_t lean_usize_sub(size_t, size_t);
size_t lean_usize_land(size_t, size_t);
lean_object* lean_usize_to_nat(size_t);
lean_object* lean_array_fget(lean_object*, lean_object*);
lean_object* l_Lean_PersistentHashMap_mkCollisionNode___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
size_t lean_usize_shift_right(size_t, size_t);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Lean_PersistentHashMap_mkEmptyEntries(lean_object*, lean_object*);
size_t lean_usize_mul(size_t, size_t);
uint8_t lean_usize_dec_le(size_t, size_t);
lean_object* l_Lean_PersistentHashMap_getCollisionNodeSize___redArg(lean_object*);
lean_object* l_Lean_Name_num___override(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(lean_object*, lean_object*);
lean_object* lean_infer_type(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_isExprDefEq(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
lean_object* l_Lean_Meta_mkAuxDefinition(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_enableRealizationsForConst(lean_object*, lean_object*, lean_object*);
lean_object* lean_array_set(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Lean_Name_append(lean_object*, lean_object*);
uint8_t l___private_Lean_Util_Trace_0__Lean_checkTraceOption_go(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_MessageData_ofExpr(lean_object*);
double lean_float_of_nat(lean_object*);
lean_object* l_Lean_PersistentArray_push___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Expr_constName_x3f(lean_object*);
lean_object* l_Lean_Meta_forallMetaTelescope(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_mvarId_x21(lean_object*);
lean_object* l_Lean_MVarId_getDecl(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Expr_hasMVar(lean_object*);
lean_object* l_Lean_instantiateMVarsCore(lean_object*, lean_object*);
lean_object* l_Lean_Meta_isProp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_isClass_x3f(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Meta_Context_config(lean_object*);
uint64_t l_Lean_Meta_Context_configKey(lean_object*);
uint64_t lean_uint64_shift_right(uint64_t, uint64_t);
lean_object* lean_whnf(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Expr_sort___override(lean_object*);
lean_object* l_Lean_Expr_getAppNumArgs(lean_object*);
lean_object* lean_mk_array(lean_object*, lean_object*);
lean_object* l_Lean_Meta_mkAuxTheorem(lean_object*, lean_object*, uint8_t, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
uint64_t lean_uint64_shift_left(uint64_t, uint64_t);
uint64_t l_Lean_Meta_TransparencyMode_toUInt64(uint8_t);
uint64_t lean_uint64_lor(uint64_t, uint64_t);
lean_object* lean_io_get_num_heartbeats();
lean_object* l_Lean_PersistentArray_toArray___redArg(lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
extern lean_object* l_Lean_trace_profiler;
lean_object* l_Lean_TraceResult_toEmoji(uint8_t);
lean_object* l_Lean_PersistentArray_append___redArg(lean_object*, lean_object*);
double lean_float_sub(double, double);
uint8_t lean_float_decLt(double, double);
extern lean_object* l_Lean_trace_profiler_useHeartbeats;
extern lean_object* l_Lean_trace_profiler_threshold;
double lean_float_div(double, double);
lean_object* lean_io_mono_nanos_now();
lean_object* l_Lean_mkAppN(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_Lean_MessageData_ofList(lean_object*);
lean_object* l_Lean_registerTraceClass(lean_object*, uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "instance"};
static const lean_object* l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "normalForm"};
static const lean_object* l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(236, 216, 85, 168, 141, 176, 253, 81)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(73, 153, 175, 8, 196, 42, 151, 43)}};
static const lean_object* l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 59, .m_capacity = 59, .m_length = 58, .m_data = "normalize instance bodies to constructor-based normal form"};
static const lean_object* l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value)}};
static const lean_object* l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Lean"};
static const lean_object* l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Meta"};
static const lean_object* l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(194, 50, 106, 158, 41, 60, 103, 214)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(41, 115, 131, 180, 163, 150, 252, 139)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(160, 146, 44, 121, 184, 65, 92, 155)}};
static const lean_object* l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_instance_normalForm;
static const lean_string_object l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "wrapInstances"};
static const lean_object* l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(236, 216, 85, 168, 141, 176, 253, 81)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(73, 153, 175, 8, 196, 42, 151, 43)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(171, 24, 193, 118, 134, 163, 216, 244)}};
static const lean_object* l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 73, .m_capacity = 73, .m_length = 72, .m_data = "wrap non-reducible instances in auxiliary definitions to fix their types"};
static const lean_object* l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value)}};
static const lean_object* l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(194, 50, 106, 158, 41, 60, 103, 214)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(41, 115, 131, 180, 163, 150, 252, 139)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_3 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(160, 146, 44, 121, 184, 65, 92, 155)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value_aux_3),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(142, 204, 109, 217, 30, 56, 255, 63)}};
static const lean_object* l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_instance_normalForm_wrapInstances;
static const lean_string_object l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "wrapFields"};
static const lean_object* l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "data"};
static const lean_object* l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(236, 216, 85, 168, 141, 176, 253, 81)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(73, 153, 175, 8, 196, 42, 151, 43)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(18, 32, 189, 68, 220, 88, 214, 143)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(64, 252, 127, 200, 85, 163, 195, 74)}};
static const lean_object* l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 61, .m_capacity = 61, .m_length = 60, .m_data = "wrap data fields in auxiliary definitions to fix their types"};
static const lean_object* l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value)}};
static const lean_object* l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(194, 50, 106, 158, 41, 60, 103, 214)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(41, 115, 131, 180, 163, 150, 252, 139)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_3 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(160, 146, 44, 121, 184, 65, 92, 155)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_4 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_3),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(223, 237, 236, 2, 45, 11, 138, 253)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value_aux_4),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(17, 149, 83, 157, 10, 90, 49, 236)}};
static const lean_object* l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_instance_normalForm_wrapFields_data;
static const lean_string_object l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "proofs"};
static const lean_object* l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(236, 216, 85, 168, 141, 176, 253, 81)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(73, 153, 175, 8, 196, 42, 151, 43)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(18, 32, 189, 68, 220, 88, 214, 143)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(87, 7, 76, 210, 13, 180, 15, 35)}};
static const lean_object* l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value;
static const lean_string_object l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 59, .m_capacity = 59, .m_length = 58, .m_data = "wrap proof fields in auxiliary theorems to fix their types"};
static const lean_object* l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value)}};
static const lean_object* l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value;
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_0),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(194, 50, 106, 158, 41, 60, 103, 214)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_1),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(41, 115, 131, 180, 163, 150, 252, 139)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_3 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_2),((lean_object*)&l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(160, 146, 44, 121, 184, 65, 92, 155)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_4 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_3),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(223, 237, 236, 2, 45, 11, 138, 253)}};
static const lean_ctor_object l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value_aux_4),((lean_object*)&l_Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(46, 40, 176, 254, 112, 55, 178, 80)}};
static const lean_object* l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_ = (const lean_object*)&l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4__value;
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_();
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4____boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_instance_normalForm_wrapFields_proofs;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "instanceNormalForm"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(211, 174, 49, 251, 64, 24, 251, 1)}};
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value_aux_0),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__0_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(57, 153, 239, 137, 246, 214, 187, 192)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "_private"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(103, 214, 75, 80, 34, 198, 193, 153)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(90, 18, 126, 130, 18, 214, 172, 143)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(30, 196, 118, 96, 111, 225, 34, 188)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "InstanceNormalForm"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(38, 21, 166, 237, 247, 44, 227, 163)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)(((size_t)(0) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(47, 255, 247, 87, 67, 74, 3, 12)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__8_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(194, 214, 207, 188, 255, 52, 193, 89)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__9_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(150, 136, 85, 96, 245, 162, 112, 180)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "initFn"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__10_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__11_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(123, 81, 24, 186, 132, 125, 163, 108)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "_@"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__12_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__13_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(94, 9, 213, 84, 12, 241, 213, 223)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__14_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(167, 43, 106, 20, 97, 65, 200, 162)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__15_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l_Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__value),LEAN_SCALAR_PTR_LITERAL(119, 231, 13, 153, 128, 78, 86, 252)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__16_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__6_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(243, 42, 205, 166, 86, 40, 201, 52)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__17_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)(((size_t)(2034682956) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(10, 120, 80, 90, 150, 102, 44, 19)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "_hygCtx"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__18_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__19_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(5, 78, 161, 211, 122, 180, 152, 33)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_string_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "_hyg"};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__20_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__21_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),LEAN_SCALAR_PTR_LITERAL(37, 99, 74, 33, 199, 2, 218, 255)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
static const lean_ctor_object l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 2}, .m_objs = {((lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__22_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value),((lean_object*)(((size_t)(2) << 1) | 1)),LEAN_SCALAR_PTR_LITERAL(168, 75, 222, 33, 198, 141, 86, 83)}};
static const lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_ = (const lean_object*)&l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2__value;
LEAN_EXPORT lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_();
LEAN_EXPORT lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2____boxed(lean_object*);
LEAN_EXPORT uint8_t l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0;
static lean_once_cell_t l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1;
static lean_once_cell_t l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2;
static lean_once_cell_t l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3;
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2(lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "trace"};
static const lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__0 = (const lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__0_value;
static const lean_ctor_object l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__0_value),LEAN_SCALAR_PTR_LITERAL(212, 145, 141, 177, 67, 149, 127, 197)}};
static const lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__1 = (const lean_object*)&l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0;
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1;
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg(lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Meta_normalizeInstance___lam__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "type: "};
static const lean_object* l_Lean_Meta_normalizeInstance___lam__0___closed__0 = (const lean_object*)&l_Lean_Meta_normalizeInstance___lam__0___closed__0_value;
static lean_once_cell_t l_Lean_Meta_normalizeInstance___lam__0___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_normalizeInstance___lam__0___closed__1;
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27___redArg(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static size_t l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0;
static lean_once_cell_t l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static size_t l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1;
static lean_once_cell_t l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2;
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(lean_object*, size_t, size_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg(size_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(lean_object*);
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21(lean_object*);
LEAN_EXPORT lean_object* l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21___boxed(lean_object*);
static const lean_string_object l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = " "};
static const lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__0 = (const lean_object*)&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__0_value;
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1;
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2;
static const lean_string_object l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 54, .m_capacity = 54, .m_length = 53, .m_data = "<exception thrown while producing trace node message>"};
static const lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__3 = (const lean_object*)&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__3_value;
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4;
static lean_once_cell_t l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static double l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5;
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18(lean_object*, uint8_t, lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "A private declaration `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__6 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__6_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 79, .m_capacity = 79, .m_length = 78, .m_data = "` (from the current module) exists but would need to be public to access here."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__8 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__8_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "A public declaration `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__10 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__10_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 68, .m_capacity = 68, .m_length = 67, .m_data = "` exists but is imported privately; consider adding `public import "};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__12 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__12_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "`."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__14 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__14_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "` (from `"};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__16 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__16_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17;
static const lean_string_object l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 54, .m_capacity = 54, .m_length = 53, .m_data = "`) exists but would need to be public to access here."};
static const lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__18 = (const lean_object*)&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__18_value;
static lean_once_cell_t l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19;
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "Unknown constant `"};
static const lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__0 = (const lean_object*)&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__0_value;
static lean_once_cell_t l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1;
static const lean_string_object l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "`"};
static const lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__2 = (const lean_object*)&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__2_value;
static lean_once_cell_t l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3;
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(size_t, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__0 = (const lean_object*)&l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__0_value;
static const lean_array_object l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__1 = (const lean_object*)&l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__1_value;
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00Lean_Meta_normalizeInstance_spec__11(lean_object*, lean_object*);
static lean_once_cell_t l_Lean_Meta_normalizeInstance___lam__1___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_normalizeInstance___lam__1___closed__0;
static const lean_string_object l_Lean_Meta_normalizeInstance___lam__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "already compatible, returning as is: "};
static const lean_object* l_Lean_Meta_normalizeInstance___lam__1___closed__1 = (const lean_object*)&l_Lean_Meta_normalizeInstance___lam__1___closed__1_value;
static lean_once_cell_t l_Lean_Meta_normalizeInstance___lam__1___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_normalizeInstance___lam__1___closed__2;
static const lean_string_object l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "_aux"};
static const lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__0 = (const lean_object*)&l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__0_value;
static const lean_ctor_object l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__0_value),LEAN_SCALAR_PTR_LITERAL(239, 43, 245, 0, 252, 151, 26, 151)}};
static const lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1 = (const lean_object*)&l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1_value;
static const lean_string_object l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 70, .m_capacity = 70, .m_length = 69, .m_data = "did not reduce to constructor application, returning/wrapping as is: "};
static const lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__0 = (const lean_object*)&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__0_value;
static lean_once_cell_t l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1;
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 82, .m_capacity = 82, .m_length = 81, .m_data = "instance normal form: incorrect number of arguments for constructor application `"};
static const lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__2 = (const lean_object*)&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__2_value;
static lean_once_cell_t l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3;
static const lean_string_object l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "`: "};
static const lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__4 = (const lean_object*)&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__4_value;
static lean_once_cell_t l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5;
static const lean_string_object l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "instance normal form: `"};
static const lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__6 = (const lean_object*)&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__6_value;
static lean_once_cell_t l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7;
static const lean_string_object l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 42, .m_capacity = 42, .m_length = 41, .m_data = "` does not unify with the conclusion of `"};
static const lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__8 = (const lean_object*)&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__8_value;
static lean_once_cell_t l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9;
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Lean_Meta_normalizeInstance___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint64_t l_Lean_Meta_normalizeInstance___closed__0;
static const lean_string_object l_Lean_Meta_normalizeInstance___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "class is "};
static const lean_object* l_Lean_Meta_normalizeInstance___closed__1 = (const lean_object*)&l_Lean_Meta_normalizeInstance___closed__1_value;
static lean_once_cell_t l_Lean_Meta_normalizeInstance___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Lean_Meta_normalizeInstance___closed__2;
static lean_once_cell_t l_Lean_Meta_normalizeInstance___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double l_Lean_Meta_normalizeInstance___closed__3;
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__2(lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15(lean_object*, lean_object*, uint8_t, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__1(lean_object*, lean_object*, uint8_t, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16(lean_object*, lean_object*, lean_object*, uint8_t, uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13(lean_object*, lean_object*, size_t, size_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28(lean_object*, size_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(lean_object* v_name_1_, lean_object* v_decl_2_, lean_object* v_ref_3_){
_start:
{
lean_object* v_defValue_5_; lean_object* v_descr_6_; lean_object* v___x_8_; uint8_t v_isShared_9_; uint8_t v_isSharedCheck_33_; 
v_defValue_5_ = lean_ctor_get(v_decl_2_, 0);
v_descr_6_ = lean_ctor_get(v_decl_2_, 1);
v_isSharedCheck_33_ = !lean_is_exclusive(v_decl_2_);
if (v_isSharedCheck_33_ == 0)
{
v___x_8_ = v_decl_2_;
v_isShared_9_ = v_isSharedCheck_33_;
goto v_resetjp_7_;
}
else
{
lean_inc(v_descr_6_);
lean_inc(v_defValue_5_);
lean_dec(v_decl_2_);
v___x_8_ = lean_box(0);
v_isShared_9_ = v_isSharedCheck_33_;
goto v_resetjp_7_;
}
v_resetjp_7_:
{
lean_object* v___x_10_; uint8_t v___x_11_; lean_object* v___x_12_; lean_object* v___x_13_; 
v___x_10_ = lean_alloc_ctor(1, 0, 1);
v___x_11_ = lean_unbox(v_defValue_5_);
lean_ctor_set_uint8(v___x_10_, 0, v___x_11_);
lean_inc(v_name_1_);
v___x_12_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_12_, 0, v_name_1_);
lean_ctor_set(v___x_12_, 1, v_ref_3_);
lean_ctor_set(v___x_12_, 2, v___x_10_);
lean_ctor_set(v___x_12_, 3, v_descr_6_);
lean_inc(v_name_1_);
v___x_13_ = lean_register_option(v_name_1_, v___x_12_);
if (lean_obj_tag(v___x_13_) == 0)
{
lean_object* v___x_15_; uint8_t v_isShared_16_; uint8_t v_isSharedCheck_23_; 
v_isSharedCheck_23_ = !lean_is_exclusive(v___x_13_);
if (v_isSharedCheck_23_ == 0)
{
lean_object* v_unused_24_; 
v_unused_24_ = lean_ctor_get(v___x_13_, 0);
lean_dec(v_unused_24_);
v___x_15_ = v___x_13_;
v_isShared_16_ = v_isSharedCheck_23_;
goto v_resetjp_14_;
}
else
{
lean_dec(v___x_13_);
v___x_15_ = lean_box(0);
v_isShared_16_ = v_isSharedCheck_23_;
goto v_resetjp_14_;
}
v_resetjp_14_:
{
lean_object* v___x_18_; 
if (v_isShared_9_ == 0)
{
lean_ctor_set(v___x_8_, 1, v_defValue_5_);
lean_ctor_set(v___x_8_, 0, v_name_1_);
v___x_18_ = v___x_8_;
goto v_reusejp_17_;
}
else
{
lean_object* v_reuseFailAlloc_22_; 
v_reuseFailAlloc_22_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_22_, 0, v_name_1_);
lean_ctor_set(v_reuseFailAlloc_22_, 1, v_defValue_5_);
v___x_18_ = v_reuseFailAlloc_22_;
goto v_reusejp_17_;
}
v_reusejp_17_:
{
lean_object* v___x_20_; 
if (v_isShared_16_ == 0)
{
lean_ctor_set(v___x_15_, 0, v___x_18_);
v___x_20_ = v___x_15_;
goto v_reusejp_19_;
}
else
{
lean_object* v_reuseFailAlloc_21_; 
v_reuseFailAlloc_21_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_21_, 0, v___x_18_);
v___x_20_ = v_reuseFailAlloc_21_;
goto v_reusejp_19_;
}
v_reusejp_19_:
{
return v___x_20_;
}
}
}
}
else
{
lean_object* v_a_25_; lean_object* v___x_27_; uint8_t v_isShared_28_; uint8_t v_isSharedCheck_32_; 
lean_del_object(v___x_8_);
lean_dec(v_defValue_5_);
lean_dec(v_name_1_);
v_a_25_ = lean_ctor_get(v___x_13_, 0);
v_isSharedCheck_32_ = !lean_is_exclusive(v___x_13_);
if (v_isSharedCheck_32_ == 0)
{
v___x_27_ = v___x_13_;
v_isShared_28_ = v_isSharedCheck_32_;
goto v_resetjp_26_;
}
else
{
lean_inc(v_a_25_);
lean_dec(v___x_13_);
v___x_27_ = lean_box(0);
v_isShared_28_ = v_isSharedCheck_32_;
goto v_resetjp_26_;
}
v_resetjp_26_:
{
lean_object* v___x_30_; 
if (v_isShared_28_ == 0)
{
v___x_30_ = v___x_27_;
goto v_reusejp_29_;
}
else
{
lean_object* v_reuseFailAlloc_31_; 
v_reuseFailAlloc_31_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_31_, 0, v_a_25_);
v___x_30_ = v_reuseFailAlloc_31_;
goto v_reusejp_29_;
}
v_reusejp_29_:
{
return v___x_30_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0___boxed(lean_object* v_name_34_, lean_object* v_decl_35_, lean_object* v_ref_36_, lean_object* v_a_37_){
_start:
{
lean_object* v_res_38_; 
v_res_38_ = l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(v_name_34_, v_decl_35_, v_ref_36_);
return v_res_38_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_57_ = ((lean_object*)(l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_));
v___x_58_ = ((lean_object*)(l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_));
v___x_59_ = ((lean_object*)(l_Lean_Meta_initFn___closed__7_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_));
v___x_60_ = l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(v___x_57_, v___x_58_, v___x_59_);
return v___x_60_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4____boxed(lean_object* v_a_61_){
_start:
{
lean_object* v_res_62_; 
v_res_62_ = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_();
return v_res_62_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_80_; lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; 
v___x_80_ = ((lean_object*)(l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_));
v___x_81_ = ((lean_object*)(l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_));
v___x_82_ = ((lean_object*)(l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_));
v___x_83_ = l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(v___x_80_, v___x_81_, v___x_82_);
return v___x_83_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4____boxed(lean_object* v_a_84_){
_start:
{
lean_object* v_res_85_; 
v_res_85_ = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_();
return v_res_85_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; 
v___x_106_ = ((lean_object*)(l_Lean_Meta_initFn___closed__2_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_));
v___x_107_ = ((lean_object*)(l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_));
v___x_108_ = ((lean_object*)(l_Lean_Meta_initFn___closed__5_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_));
v___x_109_ = l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(v___x_106_, v___x_107_, v___x_108_);
return v___x_109_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4____boxed(lean_object* v_a_110_){
_start:
{
lean_object* v_res_111_; 
v_res_111_ = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_();
return v_res_111_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_(){
_start:
{
lean_object* v___x_131_; lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; 
v___x_131_ = ((lean_object*)(l_Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_));
v___x_132_ = ((lean_object*)(l_Lean_Meta_initFn___closed__3_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_));
v___x_133_ = ((lean_object*)(l_Lean_Meta_initFn___closed__4_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_));
v___x_134_ = l_Lean_Option_register___at___00Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4__spec__0(v___x_131_, v___x_132_, v___x_133_);
return v___x_134_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4____boxed(lean_object* v_a_135_){
_start:
{
lean_object* v_res_136_; 
v_res_136_ = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_();
return v_res_136_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_(){
_start:
{
lean_object* v___x_196_; uint8_t v___x_197_; lean_object* v___x_198_; lean_object* v___x_199_; 
v___x_196_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_197_ = 0;
v___x_198_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__23_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_199_ = l_Lean_registerTraceClass(v___x_196_, v___x_197_, v___x_198_);
return v___x_199_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2____boxed(lean_object* v_a_200_){
_start:
{
lean_object* v_res_201_; 
v_res_201_ = l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_();
return v_res_201_;
}
}
LEAN_EXPORT uint8_t l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(lean_object* v_opts_202_, lean_object* v_opt_203_){
_start:
{
lean_object* v_name_204_; lean_object* v_defValue_205_; lean_object* v_map_206_; lean_object* v___x_207_; 
v_name_204_ = lean_ctor_get(v_opt_203_, 0);
v_defValue_205_ = lean_ctor_get(v_opt_203_, 1);
v_map_206_ = lean_ctor_get(v_opts_202_, 0);
v___x_207_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_206_, v_name_204_);
if (lean_obj_tag(v___x_207_) == 0)
{
uint8_t v___x_208_; 
v___x_208_ = lean_unbox(v_defValue_205_);
return v___x_208_;
}
else
{
lean_object* v_val_209_; 
v_val_209_ = lean_ctor_get(v___x_207_, 0);
lean_inc(v_val_209_);
lean_dec_ref(v___x_207_);
if (lean_obj_tag(v_val_209_) == 1)
{
uint8_t v_v_210_; 
v_v_210_ = lean_ctor_get_uint8(v_val_209_, 0);
lean_dec_ref(v_val_209_);
return v_v_210_;
}
else
{
uint8_t v___x_211_; 
lean_dec(v_val_209_);
v___x_211_ = lean_unbox(v_defValue_205_);
return v___x_211_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0___boxed(lean_object* v_opts_212_, lean_object* v_opt_213_){
_start:
{
uint8_t v_res_214_; lean_object* v_r_215_; 
v_res_214_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_opts_212_, v_opt_213_);
lean_dec_ref(v_opt_213_);
lean_dec_ref(v_opts_212_);
v_r_215_ = lean_box(v_res_214_);
return v_r_215_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(lean_object* v_kind_216_, lean_object* v___y_217_){
_start:
{
lean_object* v___x_219_; lean_object* v_auxDeclNGen_220_; lean_object* v___x_221_; lean_object* v_env_222_; lean_object* v___x_223_; lean_object* v_fst_224_; lean_object* v_snd_225_; lean_object* v___x_226_; lean_object* v_env_227_; lean_object* v_nextMacroScope_228_; lean_object* v_ngen_229_; lean_object* v_traceState_230_; lean_object* v_cache_231_; lean_object* v_messages_232_; lean_object* v_infoState_233_; lean_object* v_snapshotTasks_234_; lean_object* v___x_236_; uint8_t v_isShared_237_; uint8_t v_isSharedCheck_243_; 
v___x_219_ = lean_st_ref_get(v___y_217_);
v_auxDeclNGen_220_ = lean_ctor_get(v___x_219_, 3);
lean_inc_ref(v_auxDeclNGen_220_);
lean_dec(v___x_219_);
v___x_221_ = lean_st_ref_get(v___y_217_);
v_env_222_ = lean_ctor_get(v___x_221_, 0);
lean_inc_ref(v_env_222_);
lean_dec(v___x_221_);
v___x_223_ = l_Lean_DeclNameGenerator_mkUniqueName(v_env_222_, v_auxDeclNGen_220_, v_kind_216_);
v_fst_224_ = lean_ctor_get(v___x_223_, 0);
lean_inc(v_fst_224_);
v_snd_225_ = lean_ctor_get(v___x_223_, 1);
lean_inc(v_snd_225_);
lean_dec_ref(v___x_223_);
v___x_226_ = lean_st_ref_take(v___y_217_);
v_env_227_ = lean_ctor_get(v___x_226_, 0);
v_nextMacroScope_228_ = lean_ctor_get(v___x_226_, 1);
v_ngen_229_ = lean_ctor_get(v___x_226_, 2);
v_traceState_230_ = lean_ctor_get(v___x_226_, 4);
v_cache_231_ = lean_ctor_get(v___x_226_, 5);
v_messages_232_ = lean_ctor_get(v___x_226_, 6);
v_infoState_233_ = lean_ctor_get(v___x_226_, 7);
v_snapshotTasks_234_ = lean_ctor_get(v___x_226_, 8);
v_isSharedCheck_243_ = !lean_is_exclusive(v___x_226_);
if (v_isSharedCheck_243_ == 0)
{
lean_object* v_unused_244_; 
v_unused_244_ = lean_ctor_get(v___x_226_, 3);
lean_dec(v_unused_244_);
v___x_236_ = v___x_226_;
v_isShared_237_ = v_isSharedCheck_243_;
goto v_resetjp_235_;
}
else
{
lean_inc(v_snapshotTasks_234_);
lean_inc(v_infoState_233_);
lean_inc(v_messages_232_);
lean_inc(v_cache_231_);
lean_inc(v_traceState_230_);
lean_inc(v_ngen_229_);
lean_inc(v_nextMacroScope_228_);
lean_inc(v_env_227_);
lean_dec(v___x_226_);
v___x_236_ = lean_box(0);
v_isShared_237_ = v_isSharedCheck_243_;
goto v_resetjp_235_;
}
v_resetjp_235_:
{
lean_object* v___x_239_; 
if (v_isShared_237_ == 0)
{
lean_ctor_set(v___x_236_, 3, v_snd_225_);
v___x_239_ = v___x_236_;
goto v_reusejp_238_;
}
else
{
lean_object* v_reuseFailAlloc_242_; 
v_reuseFailAlloc_242_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_242_, 0, v_env_227_);
lean_ctor_set(v_reuseFailAlloc_242_, 1, v_nextMacroScope_228_);
lean_ctor_set(v_reuseFailAlloc_242_, 2, v_ngen_229_);
lean_ctor_set(v_reuseFailAlloc_242_, 3, v_snd_225_);
lean_ctor_set(v_reuseFailAlloc_242_, 4, v_traceState_230_);
lean_ctor_set(v_reuseFailAlloc_242_, 5, v_cache_231_);
lean_ctor_set(v_reuseFailAlloc_242_, 6, v_messages_232_);
lean_ctor_set(v_reuseFailAlloc_242_, 7, v_infoState_233_);
lean_ctor_set(v_reuseFailAlloc_242_, 8, v_snapshotTasks_234_);
v___x_239_ = v_reuseFailAlloc_242_;
goto v_reusejp_238_;
}
v_reusejp_238_:
{
lean_object* v___x_240_; lean_object* v___x_241_; 
v___x_240_ = lean_st_ref_set(v___y_217_, v___x_239_);
v___x_241_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_241_, 0, v_fst_224_);
return v___x_241_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg___boxed(lean_object* v_kind_245_, lean_object* v___y_246_, lean_object* v___y_247_){
_start:
{
lean_object* v_res_248_; 
v_res_248_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v_kind_245_, v___y_246_);
lean_dec(v___y_246_);
return v_res_248_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1(lean_object* v_kind_249_, lean_object* v___y_250_, lean_object* v___y_251_, lean_object* v___y_252_, lean_object* v___y_253_){
_start:
{
lean_object* v___x_255_; 
v___x_255_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v_kind_249_, v___y_253_);
return v___x_255_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___boxed(lean_object* v_kind_256_, lean_object* v___y_257_, lean_object* v___y_258_, lean_object* v___y_259_, lean_object* v___y_260_, lean_object* v___y_261_){
_start:
{
lean_object* v_res_262_; 
v_res_262_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1(v_kind_256_, v___y_257_, v___y_258_, v___y_259_, v___y_260_);
lean_dec(v___y_260_);
lean_dec_ref(v___y_259_);
lean_dec(v___y_258_);
lean_dec_ref(v___y_257_);
return v_res_262_;
}
}
static lean_object* _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0(void){
_start:
{
lean_object* v___x_263_; 
v___x_263_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_263_;
}
}
static lean_object* _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1(void){
_start:
{
lean_object* v___x_264_; lean_object* v___x_265_; 
v___x_264_ = lean_obj_once(&l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0, &l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0_once, _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__0);
v___x_265_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_265_, 0, v___x_264_);
return v___x_265_;
}
}
static lean_object* _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2(void){
_start:
{
lean_object* v___x_266_; lean_object* v___x_267_; 
v___x_266_ = lean_obj_once(&l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1, &l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1_once, _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1);
v___x_267_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_267_, 0, v___x_266_);
lean_ctor_set(v___x_267_, 1, v___x_266_);
return v___x_267_;
}
}
static lean_object* _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3(void){
_start:
{
lean_object* v___x_268_; lean_object* v___x_269_; 
v___x_268_ = lean_obj_once(&l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1, &l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1_once, _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__1);
v___x_269_ = lean_alloc_ctor(0, 6, 0);
lean_ctor_set(v___x_269_, 0, v___x_268_);
lean_ctor_set(v___x_269_, 1, v___x_268_);
lean_ctor_set(v___x_269_, 2, v___x_268_);
lean_ctor_set(v___x_269_, 3, v___x_268_);
lean_ctor_set(v___x_269_, 4, v___x_268_);
lean_ctor_set(v___x_269_, 5, v___x_268_);
return v___x_269_;
}
}
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(lean_object* v_declName_270_, uint8_t v_s_271_, lean_object* v___y_272_, lean_object* v___y_273_){
_start:
{
lean_object* v___x_275_; lean_object* v_env_276_; lean_object* v_nextMacroScope_277_; lean_object* v_ngen_278_; lean_object* v_auxDeclNGen_279_; lean_object* v_traceState_280_; lean_object* v_messages_281_; lean_object* v_infoState_282_; lean_object* v_snapshotTasks_283_; lean_object* v___x_285_; uint8_t v_isShared_286_; uint8_t v_isSharedCheck_312_; 
v___x_275_ = lean_st_ref_take(v___y_273_);
v_env_276_ = lean_ctor_get(v___x_275_, 0);
v_nextMacroScope_277_ = lean_ctor_get(v___x_275_, 1);
v_ngen_278_ = lean_ctor_get(v___x_275_, 2);
v_auxDeclNGen_279_ = lean_ctor_get(v___x_275_, 3);
v_traceState_280_ = lean_ctor_get(v___x_275_, 4);
v_messages_281_ = lean_ctor_get(v___x_275_, 6);
v_infoState_282_ = lean_ctor_get(v___x_275_, 7);
v_snapshotTasks_283_ = lean_ctor_get(v___x_275_, 8);
v_isSharedCheck_312_ = !lean_is_exclusive(v___x_275_);
if (v_isSharedCheck_312_ == 0)
{
lean_object* v_unused_313_; 
v_unused_313_ = lean_ctor_get(v___x_275_, 5);
lean_dec(v_unused_313_);
v___x_285_ = v___x_275_;
v_isShared_286_ = v_isSharedCheck_312_;
goto v_resetjp_284_;
}
else
{
lean_inc(v_snapshotTasks_283_);
lean_inc(v_infoState_282_);
lean_inc(v_messages_281_);
lean_inc(v_traceState_280_);
lean_inc(v_auxDeclNGen_279_);
lean_inc(v_ngen_278_);
lean_inc(v_nextMacroScope_277_);
lean_inc(v_env_276_);
lean_dec(v___x_275_);
v___x_285_ = lean_box(0);
v_isShared_286_ = v_isSharedCheck_312_;
goto v_resetjp_284_;
}
v_resetjp_284_:
{
uint8_t v___x_287_; lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_292_; 
v___x_287_ = 0;
v___x_288_ = lean_box(0);
v___x_289_ = l___private_Lean_ReducibilityAttrs_0__Lean_setReducibilityStatusCore(v_env_276_, v_declName_270_, v_s_271_, v___x_287_, v___x_288_);
v___x_290_ = lean_obj_once(&l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2, &l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2_once, _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__2);
if (v_isShared_286_ == 0)
{
lean_ctor_set(v___x_285_, 5, v___x_290_);
lean_ctor_set(v___x_285_, 0, v___x_289_);
v___x_292_ = v___x_285_;
goto v_reusejp_291_;
}
else
{
lean_object* v_reuseFailAlloc_311_; 
v_reuseFailAlloc_311_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_311_, 0, v___x_289_);
lean_ctor_set(v_reuseFailAlloc_311_, 1, v_nextMacroScope_277_);
lean_ctor_set(v_reuseFailAlloc_311_, 2, v_ngen_278_);
lean_ctor_set(v_reuseFailAlloc_311_, 3, v_auxDeclNGen_279_);
lean_ctor_set(v_reuseFailAlloc_311_, 4, v_traceState_280_);
lean_ctor_set(v_reuseFailAlloc_311_, 5, v___x_290_);
lean_ctor_set(v_reuseFailAlloc_311_, 6, v_messages_281_);
lean_ctor_set(v_reuseFailAlloc_311_, 7, v_infoState_282_);
lean_ctor_set(v_reuseFailAlloc_311_, 8, v_snapshotTasks_283_);
v___x_292_ = v_reuseFailAlloc_311_;
goto v_reusejp_291_;
}
v_reusejp_291_:
{
lean_object* v___x_293_; lean_object* v___x_294_; lean_object* v_mctx_295_; lean_object* v_zetaDeltaFVarIds_296_; lean_object* v_postponed_297_; lean_object* v_diag_298_; lean_object* v___x_300_; uint8_t v_isShared_301_; uint8_t v_isSharedCheck_309_; 
v___x_293_ = lean_st_ref_set(v___y_273_, v___x_292_);
v___x_294_ = lean_st_ref_take(v___y_272_);
v_mctx_295_ = lean_ctor_get(v___x_294_, 0);
v_zetaDeltaFVarIds_296_ = lean_ctor_get(v___x_294_, 2);
v_postponed_297_ = lean_ctor_get(v___x_294_, 3);
v_diag_298_ = lean_ctor_get(v___x_294_, 4);
v_isSharedCheck_309_ = !lean_is_exclusive(v___x_294_);
if (v_isSharedCheck_309_ == 0)
{
lean_object* v_unused_310_; 
v_unused_310_ = lean_ctor_get(v___x_294_, 1);
lean_dec(v_unused_310_);
v___x_300_ = v___x_294_;
v_isShared_301_ = v_isSharedCheck_309_;
goto v_resetjp_299_;
}
else
{
lean_inc(v_diag_298_);
lean_inc(v_postponed_297_);
lean_inc(v_zetaDeltaFVarIds_296_);
lean_inc(v_mctx_295_);
lean_dec(v___x_294_);
v___x_300_ = lean_box(0);
v_isShared_301_ = v_isSharedCheck_309_;
goto v_resetjp_299_;
}
v_resetjp_299_:
{
lean_object* v___x_302_; lean_object* v___x_304_; 
v___x_302_ = lean_obj_once(&l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3, &l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3_once, _init_l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___closed__3);
if (v_isShared_301_ == 0)
{
lean_ctor_set(v___x_300_, 1, v___x_302_);
v___x_304_ = v___x_300_;
goto v_reusejp_303_;
}
else
{
lean_object* v_reuseFailAlloc_308_; 
v_reuseFailAlloc_308_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_308_, 0, v_mctx_295_);
lean_ctor_set(v_reuseFailAlloc_308_, 1, v___x_302_);
lean_ctor_set(v_reuseFailAlloc_308_, 2, v_zetaDeltaFVarIds_296_);
lean_ctor_set(v_reuseFailAlloc_308_, 3, v_postponed_297_);
lean_ctor_set(v_reuseFailAlloc_308_, 4, v_diag_298_);
v___x_304_ = v_reuseFailAlloc_308_;
goto v_reusejp_303_;
}
v_reusejp_303_:
{
lean_object* v___x_305_; lean_object* v___x_306_; lean_object* v___x_307_; 
v___x_305_ = lean_st_ref_set(v___y_272_, v___x_304_);
v___x_306_ = lean_box(0);
v___x_307_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_307_, 0, v___x_306_);
return v___x_307_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg___boxed(lean_object* v_declName_314_, lean_object* v_s_315_, lean_object* v___y_316_, lean_object* v___y_317_, lean_object* v___y_318_){
_start:
{
uint8_t v_s_boxed_319_; lean_object* v_res_320_; 
v_s_boxed_319_ = lean_unbox(v_s_315_);
v_res_320_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(v_declName_314_, v_s_boxed_319_, v___y_316_, v___y_317_);
lean_dec(v___y_317_);
lean_dec(v___y_316_);
return v_res_320_;
}
}
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2(lean_object* v_declName_321_, uint8_t v_s_322_, lean_object* v___y_323_, lean_object* v___y_324_, lean_object* v___y_325_, lean_object* v___y_326_){
_start:
{
lean_object* v___x_328_; 
v___x_328_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(v_declName_321_, v_s_322_, v___y_324_, v___y_326_);
return v___x_328_;
}
}
LEAN_EXPORT lean_object* l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___boxed(lean_object* v_declName_329_, lean_object* v_s_330_, lean_object* v___y_331_, lean_object* v___y_332_, lean_object* v___y_333_, lean_object* v___y_334_, lean_object* v___y_335_){
_start:
{
uint8_t v_s_boxed_336_; lean_object* v_res_337_; 
v_s_boxed_336_ = lean_unbox(v_s_330_);
v_res_337_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2(v_declName_329_, v_s_boxed_336_, v___y_331_, v___y_332_, v___y_333_, v___y_334_);
lean_dec(v___y_334_);
lean_dec_ref(v___y_333_);
lean_dec(v___y_332_);
lean_dec_ref(v___y_331_);
return v_res_337_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(lean_object* v_cls_341_, lean_object* v___y_342_){
_start:
{
lean_object* v_options_344_; uint8_t v_hasTrace_345_; 
v_options_344_ = lean_ctor_get(v___y_342_, 2);
v_hasTrace_345_ = lean_ctor_get_uint8(v_options_344_, sizeof(void*)*1);
if (v_hasTrace_345_ == 0)
{
lean_object* v___x_346_; lean_object* v___x_347_; 
lean_dec(v_cls_341_);
v___x_346_ = lean_box(v_hasTrace_345_);
v___x_347_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_347_, 0, v___x_346_);
return v___x_347_;
}
else
{
lean_object* v_inheritedTraceOptions_348_; lean_object* v___x_349_; lean_object* v___x_350_; uint8_t v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; 
v_inheritedTraceOptions_348_ = lean_ctor_get(v___y_342_, 13);
v___x_349_ = ((lean_object*)(l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___closed__1));
v___x_350_ = l_Lean_Name_append(v___x_349_, v_cls_341_);
v___x_351_ = l___private_Lean_Util_Trace_0__Lean_checkTraceOption_go(v_inheritedTraceOptions_348_, v_options_344_, v___x_350_);
lean_dec(v___x_350_);
v___x_352_ = lean_box(v___x_351_);
v___x_353_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_353_, 0, v___x_352_);
return v___x_353_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg___boxed(lean_object* v_cls_354_, lean_object* v___y_355_, lean_object* v___y_356_){
_start:
{
lean_object* v_res_357_; 
v_res_357_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_354_, v___y_355_);
lean_dec_ref(v___y_355_);
return v_res_357_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3(lean_object* v_cls_358_, lean_object* v___y_359_, lean_object* v___y_360_, lean_object* v___y_361_, lean_object* v___y_362_){
_start:
{
lean_object* v___x_364_; 
v___x_364_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_358_, v___y_361_);
return v___x_364_;
}
}
LEAN_EXPORT lean_object* l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___boxed(lean_object* v_cls_365_, lean_object* v___y_366_, lean_object* v___y_367_, lean_object* v___y_368_, lean_object* v___y_369_, lean_object* v___y_370_){
_start:
{
lean_object* v_res_371_; 
v_res_371_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3(v_cls_365_, v___y_366_, v___y_367_, v___y_368_, v___y_369_);
lean_dec(v___y_369_);
lean_dec_ref(v___y_368_);
lean_dec(v___y_367_);
lean_dec_ref(v___y_366_);
return v_res_371_;
}
}
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(lean_object* v_e_372_, lean_object* v___y_373_){
_start:
{
uint8_t v___x_375_; 
v___x_375_ = l_Lean_Expr_hasMVar(v_e_372_);
if (v___x_375_ == 0)
{
lean_object* v___x_376_; 
v___x_376_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_376_, 0, v_e_372_);
return v___x_376_;
}
else
{
lean_object* v___x_377_; lean_object* v_mctx_378_; lean_object* v___x_379_; lean_object* v_fst_380_; lean_object* v_snd_381_; lean_object* v___x_382_; lean_object* v_cache_383_; lean_object* v_zetaDeltaFVarIds_384_; lean_object* v_postponed_385_; lean_object* v_diag_386_; lean_object* v___x_388_; uint8_t v_isShared_389_; uint8_t v_isSharedCheck_395_; 
v___x_377_ = lean_st_ref_get(v___y_373_);
v_mctx_378_ = lean_ctor_get(v___x_377_, 0);
lean_inc_ref(v_mctx_378_);
lean_dec(v___x_377_);
v___x_379_ = l_Lean_instantiateMVarsCore(v_mctx_378_, v_e_372_);
v_fst_380_ = lean_ctor_get(v___x_379_, 0);
lean_inc(v_fst_380_);
v_snd_381_ = lean_ctor_get(v___x_379_, 1);
lean_inc(v_snd_381_);
lean_dec_ref(v___x_379_);
v___x_382_ = lean_st_ref_take(v___y_373_);
v_cache_383_ = lean_ctor_get(v___x_382_, 1);
v_zetaDeltaFVarIds_384_ = lean_ctor_get(v___x_382_, 2);
v_postponed_385_ = lean_ctor_get(v___x_382_, 3);
v_diag_386_ = lean_ctor_get(v___x_382_, 4);
v_isSharedCheck_395_ = !lean_is_exclusive(v___x_382_);
if (v_isSharedCheck_395_ == 0)
{
lean_object* v_unused_396_; 
v_unused_396_ = lean_ctor_get(v___x_382_, 0);
lean_dec(v_unused_396_);
v___x_388_ = v___x_382_;
v_isShared_389_ = v_isSharedCheck_395_;
goto v_resetjp_387_;
}
else
{
lean_inc(v_diag_386_);
lean_inc(v_postponed_385_);
lean_inc(v_zetaDeltaFVarIds_384_);
lean_inc(v_cache_383_);
lean_dec(v___x_382_);
v___x_388_ = lean_box(0);
v_isShared_389_ = v_isSharedCheck_395_;
goto v_resetjp_387_;
}
v_resetjp_387_:
{
lean_object* v___x_391_; 
if (v_isShared_389_ == 0)
{
lean_ctor_set(v___x_388_, 0, v_snd_381_);
v___x_391_ = v___x_388_;
goto v_reusejp_390_;
}
else
{
lean_object* v_reuseFailAlloc_394_; 
v_reuseFailAlloc_394_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_394_, 0, v_snd_381_);
lean_ctor_set(v_reuseFailAlloc_394_, 1, v_cache_383_);
lean_ctor_set(v_reuseFailAlloc_394_, 2, v_zetaDeltaFVarIds_384_);
lean_ctor_set(v_reuseFailAlloc_394_, 3, v_postponed_385_);
lean_ctor_set(v_reuseFailAlloc_394_, 4, v_diag_386_);
v___x_391_ = v_reuseFailAlloc_394_;
goto v_reusejp_390_;
}
v_reusejp_390_:
{
lean_object* v___x_392_; lean_object* v___x_393_; 
v___x_392_ = lean_st_ref_set(v___y_373_, v___x_391_);
v___x_393_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_393_, 0, v_fst_380_);
return v___x_393_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg___boxed(lean_object* v_e_397_, lean_object* v___y_398_, lean_object* v___y_399_){
_start:
{
lean_object* v_res_400_; 
v_res_400_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_e_397_, v___y_398_);
lean_dec(v___y_398_);
return v_res_400_;
}
}
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6(lean_object* v_e_401_, lean_object* v___y_402_, lean_object* v___y_403_, lean_object* v___y_404_, lean_object* v___y_405_){
_start:
{
lean_object* v___x_407_; 
v___x_407_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_e_401_, v___y_403_);
return v___x_407_;
}
}
LEAN_EXPORT lean_object* l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___boxed(lean_object* v_e_408_, lean_object* v___y_409_, lean_object* v___y_410_, lean_object* v___y_411_, lean_object* v___y_412_, lean_object* v___y_413_){
_start:
{
lean_object* v_res_414_; 
v_res_414_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6(v_e_408_, v___y_409_, v___y_410_, v___y_411_, v___y_412_);
lean_dec(v___y_412_);
lean_dec_ref(v___y_411_);
lean_dec(v___y_410_);
lean_dec_ref(v___y_409_);
return v_res_414_;
}
}
static lean_object* _init_l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0(void){
_start:
{
lean_object* v___x_415_; lean_object* v___x_416_; lean_object* v___x_417_; 
v___x_415_ = lean_unsigned_to_nat(32u);
v___x_416_ = lean_mk_empty_array_with_capacity(v___x_415_);
v___x_417_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_417_, 0, v___x_416_);
return v___x_417_;
}
}
static lean_object* _init_l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1(void){
_start:
{
size_t v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_423_; 
v___x_418_ = ((size_t)5ULL);
v___x_419_ = lean_unsigned_to_nat(0u);
v___x_420_ = lean_unsigned_to_nat(32u);
v___x_421_ = lean_mk_empty_array_with_capacity(v___x_420_);
v___x_422_ = lean_obj_once(&l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0, &l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0_once, _init_l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__0);
v___x_423_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_423_, 0, v___x_422_);
lean_ctor_set(v___x_423_, 1, v___x_421_);
lean_ctor_set(v___x_423_, 2, v___x_419_);
lean_ctor_set(v___x_423_, 3, v___x_419_);
lean_ctor_set_usize(v___x_423_, 4, v___x_418_);
return v___x_423_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg(lean_object* v___y_424_){
_start:
{
lean_object* v___x_426_; lean_object* v_traceState_427_; lean_object* v_traces_428_; lean_object* v___x_429_; lean_object* v_traceState_430_; lean_object* v_env_431_; lean_object* v_nextMacroScope_432_; lean_object* v_ngen_433_; lean_object* v_auxDeclNGen_434_; lean_object* v_cache_435_; lean_object* v_messages_436_; lean_object* v_infoState_437_; lean_object* v_snapshotTasks_438_; lean_object* v___x_440_; uint8_t v_isShared_441_; uint8_t v_isSharedCheck_457_; 
v___x_426_ = lean_st_ref_get(v___y_424_);
v_traceState_427_ = lean_ctor_get(v___x_426_, 4);
lean_inc_ref(v_traceState_427_);
lean_dec(v___x_426_);
v_traces_428_ = lean_ctor_get(v_traceState_427_, 0);
lean_inc_ref(v_traces_428_);
lean_dec_ref(v_traceState_427_);
v___x_429_ = lean_st_ref_take(v___y_424_);
v_traceState_430_ = lean_ctor_get(v___x_429_, 4);
v_env_431_ = lean_ctor_get(v___x_429_, 0);
v_nextMacroScope_432_ = lean_ctor_get(v___x_429_, 1);
v_ngen_433_ = lean_ctor_get(v___x_429_, 2);
v_auxDeclNGen_434_ = lean_ctor_get(v___x_429_, 3);
v_cache_435_ = lean_ctor_get(v___x_429_, 5);
v_messages_436_ = lean_ctor_get(v___x_429_, 6);
v_infoState_437_ = lean_ctor_get(v___x_429_, 7);
v_snapshotTasks_438_ = lean_ctor_get(v___x_429_, 8);
v_isSharedCheck_457_ = !lean_is_exclusive(v___x_429_);
if (v_isSharedCheck_457_ == 0)
{
v___x_440_ = v___x_429_;
v_isShared_441_ = v_isSharedCheck_457_;
goto v_resetjp_439_;
}
else
{
lean_inc(v_snapshotTasks_438_);
lean_inc(v_infoState_437_);
lean_inc(v_messages_436_);
lean_inc(v_cache_435_);
lean_inc(v_traceState_430_);
lean_inc(v_auxDeclNGen_434_);
lean_inc(v_ngen_433_);
lean_inc(v_nextMacroScope_432_);
lean_inc(v_env_431_);
lean_dec(v___x_429_);
v___x_440_ = lean_box(0);
v_isShared_441_ = v_isSharedCheck_457_;
goto v_resetjp_439_;
}
v_resetjp_439_:
{
uint64_t v_tid_442_; lean_object* v___x_444_; uint8_t v_isShared_445_; uint8_t v_isSharedCheck_455_; 
v_tid_442_ = lean_ctor_get_uint64(v_traceState_430_, sizeof(void*)*1);
v_isSharedCheck_455_ = !lean_is_exclusive(v_traceState_430_);
if (v_isSharedCheck_455_ == 0)
{
lean_object* v_unused_456_; 
v_unused_456_ = lean_ctor_get(v_traceState_430_, 0);
lean_dec(v_unused_456_);
v___x_444_ = v_traceState_430_;
v_isShared_445_ = v_isSharedCheck_455_;
goto v_resetjp_443_;
}
else
{
lean_dec(v_traceState_430_);
v___x_444_ = lean_box(0);
v_isShared_445_ = v_isSharedCheck_455_;
goto v_resetjp_443_;
}
v_resetjp_443_:
{
lean_object* v___x_446_; lean_object* v___x_448_; 
v___x_446_ = lean_obj_once(&l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1, &l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1_once, _init_l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___closed__1);
if (v_isShared_445_ == 0)
{
lean_ctor_set(v___x_444_, 0, v___x_446_);
v___x_448_ = v___x_444_;
goto v_reusejp_447_;
}
else
{
lean_object* v_reuseFailAlloc_454_; 
v_reuseFailAlloc_454_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v_reuseFailAlloc_454_, 0, v___x_446_);
lean_ctor_set_uint64(v_reuseFailAlloc_454_, sizeof(void*)*1, v_tid_442_);
v___x_448_ = v_reuseFailAlloc_454_;
goto v_reusejp_447_;
}
v_reusejp_447_:
{
lean_object* v___x_450_; 
if (v_isShared_441_ == 0)
{
lean_ctor_set(v___x_440_, 4, v___x_448_);
v___x_450_ = v___x_440_;
goto v_reusejp_449_;
}
else
{
lean_object* v_reuseFailAlloc_453_; 
v_reuseFailAlloc_453_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_453_, 0, v_env_431_);
lean_ctor_set(v_reuseFailAlloc_453_, 1, v_nextMacroScope_432_);
lean_ctor_set(v_reuseFailAlloc_453_, 2, v_ngen_433_);
lean_ctor_set(v_reuseFailAlloc_453_, 3, v_auxDeclNGen_434_);
lean_ctor_set(v_reuseFailAlloc_453_, 4, v___x_448_);
lean_ctor_set(v_reuseFailAlloc_453_, 5, v_cache_435_);
lean_ctor_set(v_reuseFailAlloc_453_, 6, v_messages_436_);
lean_ctor_set(v_reuseFailAlloc_453_, 7, v_infoState_437_);
lean_ctor_set(v_reuseFailAlloc_453_, 8, v_snapshotTasks_438_);
v___x_450_ = v_reuseFailAlloc_453_;
goto v_reusejp_449_;
}
v_reusejp_449_:
{
lean_object* v___x_451_; lean_object* v___x_452_; 
v___x_451_ = lean_st_ref_set(v___y_424_, v___x_450_);
v___x_452_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_452_, 0, v_traces_428_);
return v___x_452_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg___boxed(lean_object* v___y_458_, lean_object* v___y_459_){
_start:
{
lean_object* v_res_460_; 
v_res_460_ = l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg(v___y_458_);
lean_dec(v___y_458_);
return v_res_460_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13(lean_object* v___y_461_, lean_object* v___y_462_, lean_object* v___y_463_, lean_object* v___y_464_){
_start:
{
lean_object* v___x_466_; 
v___x_466_ = l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg(v___y_464_);
return v___x_466_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___boxed(lean_object* v___y_467_, lean_object* v___y_468_, lean_object* v___y_469_, lean_object* v___y_470_, lean_object* v___y_471_){
_start:
{
lean_object* v_res_472_; 
v_res_472_ = l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13(v___y_467_, v___y_468_, v___y_469_, v___y_470_);
lean_dec(v___y_470_);
lean_dec_ref(v___y_469_);
lean_dec(v___y_468_);
lean_dec_ref(v___y_467_);
return v_res_472_;
}
}
static lean_object* _init_l_Lean_Meta_normalizeInstance___lam__0___closed__1(void){
_start:
{
lean_object* v___x_474_; lean_object* v___x_475_; 
v___x_474_ = ((lean_object*)(l_Lean_Meta_normalizeInstance___lam__0___closed__0));
v___x_475_ = l_Lean_stringToMessageData(v___x_474_);
return v___x_475_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__0(lean_object* v_expectedType_476_, lean_object* v_x_477_, lean_object* v___y_478_, lean_object* v___y_479_, lean_object* v___y_480_, lean_object* v___y_481_){
_start:
{
lean_object* v___x_483_; lean_object* v___x_484_; lean_object* v___x_485_; lean_object* v___x_486_; 
v___x_483_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__0___closed__1, &l_Lean_Meta_normalizeInstance___lam__0___closed__1_once, _init_l_Lean_Meta_normalizeInstance___lam__0___closed__1);
v___x_484_ = l_Lean_MessageData_ofExpr(v_expectedType_476_);
v___x_485_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_485_, 0, v___x_483_);
lean_ctor_set(v___x_485_, 1, v___x_484_);
v___x_486_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_486_, 0, v___x_485_);
return v___x_486_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__0___boxed(lean_object* v_expectedType_487_, lean_object* v_x_488_, lean_object* v___y_489_, lean_object* v___y_490_, lean_object* v___y_491_, lean_object* v___y_492_, lean_object* v___y_493_){
_start:
{
lean_object* v_res_494_; 
v_res_494_ = l_Lean_Meta_normalizeInstance___lam__0(v_expectedType_487_, v_x_488_, v___y_489_, v___y_490_, v___y_491_, v___y_492_);
lean_dec(v___y_492_);
lean_dec_ref(v___y_491_);
lean_dec(v___y_490_);
lean_dec_ref(v___y_489_);
lean_dec_ref(v_x_488_);
return v_res_494_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31___redArg(lean_object* v_x_495_, lean_object* v_x_496_, lean_object* v_x_497_, lean_object* v_x_498_){
_start:
{
lean_object* v_ks_499_; lean_object* v_vs_500_; lean_object* v___x_502_; uint8_t v_isShared_503_; uint8_t v_isSharedCheck_524_; 
v_ks_499_ = lean_ctor_get(v_x_495_, 0);
v_vs_500_ = lean_ctor_get(v_x_495_, 1);
v_isSharedCheck_524_ = !lean_is_exclusive(v_x_495_);
if (v_isSharedCheck_524_ == 0)
{
v___x_502_ = v_x_495_;
v_isShared_503_ = v_isSharedCheck_524_;
goto v_resetjp_501_;
}
else
{
lean_inc(v_vs_500_);
lean_inc(v_ks_499_);
lean_dec(v_x_495_);
v___x_502_ = lean_box(0);
v_isShared_503_ = v_isSharedCheck_524_;
goto v_resetjp_501_;
}
v_resetjp_501_:
{
lean_object* v___x_504_; uint8_t v___x_505_; 
v___x_504_ = lean_array_get_size(v_ks_499_);
v___x_505_ = lean_nat_dec_lt(v_x_496_, v___x_504_);
if (v___x_505_ == 0)
{
lean_object* v___x_506_; lean_object* v___x_507_; lean_object* v___x_509_; 
lean_dec(v_x_496_);
v___x_506_ = lean_array_push(v_ks_499_, v_x_497_);
v___x_507_ = lean_array_push(v_vs_500_, v_x_498_);
if (v_isShared_503_ == 0)
{
lean_ctor_set(v___x_502_, 1, v___x_507_);
lean_ctor_set(v___x_502_, 0, v___x_506_);
v___x_509_ = v___x_502_;
goto v_reusejp_508_;
}
else
{
lean_object* v_reuseFailAlloc_510_; 
v_reuseFailAlloc_510_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_510_, 0, v___x_506_);
lean_ctor_set(v_reuseFailAlloc_510_, 1, v___x_507_);
v___x_509_ = v_reuseFailAlloc_510_;
goto v_reusejp_508_;
}
v_reusejp_508_:
{
return v___x_509_;
}
}
else
{
lean_object* v_k_x27_511_; uint8_t v___x_512_; 
v_k_x27_511_ = lean_array_fget_borrowed(v_ks_499_, v_x_496_);
v___x_512_ = l_Lean_instBEqMVarId_beq(v_x_497_, v_k_x27_511_);
if (v___x_512_ == 0)
{
lean_object* v___x_514_; 
if (v_isShared_503_ == 0)
{
v___x_514_ = v___x_502_;
goto v_reusejp_513_;
}
else
{
lean_object* v_reuseFailAlloc_518_; 
v_reuseFailAlloc_518_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_518_, 0, v_ks_499_);
lean_ctor_set(v_reuseFailAlloc_518_, 1, v_vs_500_);
v___x_514_ = v_reuseFailAlloc_518_;
goto v_reusejp_513_;
}
v_reusejp_513_:
{
lean_object* v___x_515_; lean_object* v___x_516_; 
v___x_515_ = lean_unsigned_to_nat(1u);
v___x_516_ = lean_nat_add(v_x_496_, v___x_515_);
lean_dec(v_x_496_);
v_x_495_ = v___x_514_;
v_x_496_ = v___x_516_;
goto _start;
}
}
else
{
lean_object* v___x_519_; lean_object* v___x_520_; lean_object* v___x_522_; 
v___x_519_ = lean_array_fset(v_ks_499_, v_x_496_, v_x_497_);
v___x_520_ = lean_array_fset(v_vs_500_, v_x_496_, v_x_498_);
lean_dec(v_x_496_);
if (v_isShared_503_ == 0)
{
lean_ctor_set(v___x_502_, 1, v___x_520_);
lean_ctor_set(v___x_502_, 0, v___x_519_);
v___x_522_ = v___x_502_;
goto v_reusejp_521_;
}
else
{
lean_object* v_reuseFailAlloc_523_; 
v_reuseFailAlloc_523_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_523_, 0, v___x_519_);
lean_ctor_set(v_reuseFailAlloc_523_, 1, v___x_520_);
v___x_522_ = v_reuseFailAlloc_523_;
goto v_reusejp_521_;
}
v_reusejp_521_:
{
return v___x_522_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27___redArg(lean_object* v_n_525_, lean_object* v_k_526_, lean_object* v_v_527_){
_start:
{
lean_object* v___x_528_; lean_object* v___x_529_; 
v___x_528_ = lean_unsigned_to_nat(0u);
v___x_529_ = l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31___redArg(v_n_525_, v___x_528_, v_k_526_, v_v_527_);
return v___x_529_;
}
}
static size_t _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0(void){
_start:
{
size_t v___x_530_; size_t v___x_531_; size_t v___x_532_; 
v___x_530_ = ((size_t)5ULL);
v___x_531_ = ((size_t)1ULL);
v___x_532_ = lean_usize_shift_left(v___x_531_, v___x_530_);
return v___x_532_;
}
}
static size_t _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1(void){
_start:
{
size_t v___x_533_; size_t v___x_534_; size_t v___x_535_; 
v___x_533_ = ((size_t)1ULL);
v___x_534_ = lean_usize_once(&l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0, &l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0_once, _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__0);
v___x_535_ = lean_usize_sub(v___x_534_, v___x_533_);
return v___x_535_;
}
}
static lean_object* _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2(void){
_start:
{
lean_object* v___x_536_; 
v___x_536_ = l_Lean_PersistentHashMap_mkEmptyEntries(lean_box(0), lean_box(0));
return v___x_536_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(lean_object* v_x_537_, size_t v_x_538_, size_t v_x_539_, lean_object* v_x_540_, lean_object* v_x_541_){
_start:
{
if (lean_obj_tag(v_x_537_) == 0)
{
lean_object* v_es_542_; size_t v___x_543_; size_t v___x_544_; size_t v___x_545_; size_t v___x_546_; lean_object* v_j_547_; lean_object* v___x_548_; uint8_t v___x_549_; 
v_es_542_ = lean_ctor_get(v_x_537_, 0);
v___x_543_ = ((size_t)5ULL);
v___x_544_ = ((size_t)1ULL);
v___x_545_ = lean_usize_once(&l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1, &l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1_once, _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__1);
v___x_546_ = lean_usize_land(v_x_538_, v___x_545_);
v_j_547_ = lean_usize_to_nat(v___x_546_);
v___x_548_ = lean_array_get_size(v_es_542_);
v___x_549_ = lean_nat_dec_lt(v_j_547_, v___x_548_);
if (v___x_549_ == 0)
{
lean_dec(v_j_547_);
lean_dec(v_x_541_);
lean_dec(v_x_540_);
return v_x_537_;
}
else
{
lean_object* v___x_551_; uint8_t v_isShared_552_; uint8_t v_isSharedCheck_586_; 
lean_inc_ref(v_es_542_);
v_isSharedCheck_586_ = !lean_is_exclusive(v_x_537_);
if (v_isSharedCheck_586_ == 0)
{
lean_object* v_unused_587_; 
v_unused_587_ = lean_ctor_get(v_x_537_, 0);
lean_dec(v_unused_587_);
v___x_551_ = v_x_537_;
v_isShared_552_ = v_isSharedCheck_586_;
goto v_resetjp_550_;
}
else
{
lean_dec(v_x_537_);
v___x_551_ = lean_box(0);
v_isShared_552_ = v_isSharedCheck_586_;
goto v_resetjp_550_;
}
v_resetjp_550_:
{
lean_object* v_v_553_; lean_object* v___x_554_; lean_object* v_xs_x27_555_; lean_object* v___y_557_; 
v_v_553_ = lean_array_fget(v_es_542_, v_j_547_);
v___x_554_ = lean_box(0);
v_xs_x27_555_ = lean_array_fset(v_es_542_, v_j_547_, v___x_554_);
switch(lean_obj_tag(v_v_553_))
{
case 0:
{
lean_object* v_key_562_; lean_object* v_val_563_; lean_object* v___x_565_; uint8_t v_isShared_566_; uint8_t v_isSharedCheck_573_; 
v_key_562_ = lean_ctor_get(v_v_553_, 0);
v_val_563_ = lean_ctor_get(v_v_553_, 1);
v_isSharedCheck_573_ = !lean_is_exclusive(v_v_553_);
if (v_isSharedCheck_573_ == 0)
{
v___x_565_ = v_v_553_;
v_isShared_566_ = v_isSharedCheck_573_;
goto v_resetjp_564_;
}
else
{
lean_inc(v_val_563_);
lean_inc(v_key_562_);
lean_dec(v_v_553_);
v___x_565_ = lean_box(0);
v_isShared_566_ = v_isSharedCheck_573_;
goto v_resetjp_564_;
}
v_resetjp_564_:
{
uint8_t v___x_567_; 
v___x_567_ = l_Lean_instBEqMVarId_beq(v_x_540_, v_key_562_);
if (v___x_567_ == 0)
{
lean_object* v___x_568_; lean_object* v___x_569_; 
lean_del_object(v___x_565_);
v___x_568_ = l_Lean_PersistentHashMap_mkCollisionNode___redArg(v_key_562_, v_val_563_, v_x_540_, v_x_541_);
v___x_569_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_569_, 0, v___x_568_);
v___y_557_ = v___x_569_;
goto v___jp_556_;
}
else
{
lean_object* v___x_571_; 
lean_dec(v_val_563_);
lean_dec(v_key_562_);
if (v_isShared_566_ == 0)
{
lean_ctor_set(v___x_565_, 1, v_x_541_);
lean_ctor_set(v___x_565_, 0, v_x_540_);
v___x_571_ = v___x_565_;
goto v_reusejp_570_;
}
else
{
lean_object* v_reuseFailAlloc_572_; 
v_reuseFailAlloc_572_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_572_, 0, v_x_540_);
lean_ctor_set(v_reuseFailAlloc_572_, 1, v_x_541_);
v___x_571_ = v_reuseFailAlloc_572_;
goto v_reusejp_570_;
}
v_reusejp_570_:
{
v___y_557_ = v___x_571_;
goto v___jp_556_;
}
}
}
}
case 1:
{
lean_object* v_node_574_; lean_object* v___x_576_; uint8_t v_isShared_577_; uint8_t v_isSharedCheck_584_; 
v_node_574_ = lean_ctor_get(v_v_553_, 0);
v_isSharedCheck_584_ = !lean_is_exclusive(v_v_553_);
if (v_isSharedCheck_584_ == 0)
{
v___x_576_ = v_v_553_;
v_isShared_577_ = v_isSharedCheck_584_;
goto v_resetjp_575_;
}
else
{
lean_inc(v_node_574_);
lean_dec(v_v_553_);
v___x_576_ = lean_box(0);
v_isShared_577_ = v_isSharedCheck_584_;
goto v_resetjp_575_;
}
v_resetjp_575_:
{
size_t v___x_578_; size_t v___x_579_; lean_object* v___x_580_; lean_object* v___x_582_; 
v___x_578_ = lean_usize_shift_right(v_x_538_, v___x_543_);
v___x_579_ = lean_usize_add(v_x_539_, v___x_544_);
v___x_580_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(v_node_574_, v___x_578_, v___x_579_, v_x_540_, v_x_541_);
if (v_isShared_577_ == 0)
{
lean_ctor_set(v___x_576_, 0, v___x_580_);
v___x_582_ = v___x_576_;
goto v_reusejp_581_;
}
else
{
lean_object* v_reuseFailAlloc_583_; 
v_reuseFailAlloc_583_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_583_, 0, v___x_580_);
v___x_582_ = v_reuseFailAlloc_583_;
goto v_reusejp_581_;
}
v_reusejp_581_:
{
v___y_557_ = v___x_582_;
goto v___jp_556_;
}
}
}
default: 
{
lean_object* v___x_585_; 
v___x_585_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_585_, 0, v_x_540_);
lean_ctor_set(v___x_585_, 1, v_x_541_);
v___y_557_ = v___x_585_;
goto v___jp_556_;
}
}
v___jp_556_:
{
lean_object* v___x_558_; lean_object* v___x_560_; 
v___x_558_ = lean_array_fset(v_xs_x27_555_, v_j_547_, v___y_557_);
lean_dec(v_j_547_);
if (v_isShared_552_ == 0)
{
lean_ctor_set(v___x_551_, 0, v___x_558_);
v___x_560_ = v___x_551_;
goto v_reusejp_559_;
}
else
{
lean_object* v_reuseFailAlloc_561_; 
v_reuseFailAlloc_561_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_561_, 0, v___x_558_);
v___x_560_ = v_reuseFailAlloc_561_;
goto v_reusejp_559_;
}
v_reusejp_559_:
{
return v___x_560_;
}
}
}
}
}
else
{
lean_object* v_ks_588_; lean_object* v_vs_589_; lean_object* v___x_591_; uint8_t v_isShared_592_; uint8_t v_isSharedCheck_609_; 
v_ks_588_ = lean_ctor_get(v_x_537_, 0);
v_vs_589_ = lean_ctor_get(v_x_537_, 1);
v_isSharedCheck_609_ = !lean_is_exclusive(v_x_537_);
if (v_isSharedCheck_609_ == 0)
{
v___x_591_ = v_x_537_;
v_isShared_592_ = v_isSharedCheck_609_;
goto v_resetjp_590_;
}
else
{
lean_inc(v_vs_589_);
lean_inc(v_ks_588_);
lean_dec(v_x_537_);
v___x_591_ = lean_box(0);
v_isShared_592_ = v_isSharedCheck_609_;
goto v_resetjp_590_;
}
v_resetjp_590_:
{
lean_object* v___x_594_; 
if (v_isShared_592_ == 0)
{
v___x_594_ = v___x_591_;
goto v_reusejp_593_;
}
else
{
lean_object* v_reuseFailAlloc_608_; 
v_reuseFailAlloc_608_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_608_, 0, v_ks_588_);
lean_ctor_set(v_reuseFailAlloc_608_, 1, v_vs_589_);
v___x_594_ = v_reuseFailAlloc_608_;
goto v_reusejp_593_;
}
v_reusejp_593_:
{
lean_object* v_newNode_595_; uint8_t v___y_597_; size_t v___x_603_; uint8_t v___x_604_; 
v_newNode_595_ = l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27___redArg(v___x_594_, v_x_540_, v_x_541_);
v___x_603_ = ((size_t)7ULL);
v___x_604_ = lean_usize_dec_le(v___x_603_, v_x_539_);
if (v___x_604_ == 0)
{
lean_object* v___x_605_; lean_object* v___x_606_; uint8_t v___x_607_; 
v___x_605_ = l_Lean_PersistentHashMap_getCollisionNodeSize___redArg(v_newNode_595_);
v___x_606_ = lean_unsigned_to_nat(4u);
v___x_607_ = lean_nat_dec_lt(v___x_605_, v___x_606_);
lean_dec(v___x_605_);
v___y_597_ = v___x_607_;
goto v___jp_596_;
}
else
{
v___y_597_ = v___x_604_;
goto v___jp_596_;
}
v___jp_596_:
{
if (v___y_597_ == 0)
{
lean_object* v_ks_598_; lean_object* v_vs_599_; lean_object* v___x_600_; lean_object* v___x_601_; lean_object* v___x_602_; 
v_ks_598_ = lean_ctor_get(v_newNode_595_, 0);
lean_inc_ref(v_ks_598_);
v_vs_599_ = lean_ctor_get(v_newNode_595_, 1);
lean_inc_ref(v_vs_599_);
lean_dec_ref(v_newNode_595_);
v___x_600_ = lean_unsigned_to_nat(0u);
v___x_601_ = lean_obj_once(&l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2, &l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2_once, _init_l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___closed__2);
v___x_602_ = l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg(v_x_539_, v_ks_598_, v_vs_599_, v___x_600_, v___x_601_);
lean_dec_ref(v_vs_599_);
lean_dec_ref(v_ks_598_);
return v___x_602_;
}
else
{
return v_newNode_595_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg(size_t v_depth_610_, lean_object* v_keys_611_, lean_object* v_vals_612_, lean_object* v_i_613_, lean_object* v_entries_614_){
_start:
{
lean_object* v___x_615_; uint8_t v___x_616_; 
v___x_615_ = lean_array_get_size(v_keys_611_);
v___x_616_ = lean_nat_dec_lt(v_i_613_, v___x_615_);
if (v___x_616_ == 0)
{
lean_dec(v_i_613_);
return v_entries_614_;
}
else
{
lean_object* v_k_617_; lean_object* v_v_618_; uint64_t v___x_619_; size_t v_h_620_; size_t v___x_621_; lean_object* v___x_622_; size_t v___x_623_; size_t v___x_624_; size_t v___x_625_; size_t v_h_626_; lean_object* v___x_627_; lean_object* v___x_628_; 
v_k_617_ = lean_array_fget_borrowed(v_keys_611_, v_i_613_);
v_v_618_ = lean_array_fget_borrowed(v_vals_612_, v_i_613_);
v___x_619_ = l_Lean_instHashableMVarId_hash(v_k_617_);
v_h_620_ = lean_uint64_to_usize(v___x_619_);
v___x_621_ = ((size_t)5ULL);
v___x_622_ = lean_unsigned_to_nat(1u);
v___x_623_ = ((size_t)1ULL);
v___x_624_ = lean_usize_sub(v_depth_610_, v___x_623_);
v___x_625_ = lean_usize_mul(v___x_621_, v___x_624_);
v_h_626_ = lean_usize_shift_right(v_h_620_, v___x_625_);
v___x_627_ = lean_nat_add(v_i_613_, v___x_622_);
lean_dec(v_i_613_);
lean_inc(v_v_618_);
lean_inc(v_k_617_);
v___x_628_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(v_entries_614_, v_h_626_, v_depth_610_, v_k_617_, v_v_618_);
v_i_613_ = v___x_627_;
v_entries_614_ = v___x_628_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg___boxed(lean_object* v_depth_630_, lean_object* v_keys_631_, lean_object* v_vals_632_, lean_object* v_i_633_, lean_object* v_entries_634_){
_start:
{
size_t v_depth_boxed_635_; lean_object* v_res_636_; 
v_depth_boxed_635_ = lean_unbox_usize(v_depth_630_);
lean_dec(v_depth_630_);
v_res_636_ = l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg(v_depth_boxed_635_, v_keys_631_, v_vals_632_, v_i_633_, v_entries_634_);
lean_dec_ref(v_vals_632_);
lean_dec_ref(v_keys_631_);
return v_res_636_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg___boxed(lean_object* v_x_637_, lean_object* v_x_638_, lean_object* v_x_639_, lean_object* v_x_640_, lean_object* v_x_641_){
_start:
{
size_t v_x_75192__boxed_642_; size_t v_x_75193__boxed_643_; lean_object* v_res_644_; 
v_x_75192__boxed_642_ = lean_unbox_usize(v_x_638_);
lean_dec(v_x_638_);
v_x_75193__boxed_643_ = lean_unbox_usize(v_x_639_);
lean_dec(v_x_639_);
v_res_644_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(v_x_637_, v_x_75192__boxed_642_, v_x_75193__boxed_643_, v_x_640_, v_x_641_);
return v_res_644_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10___redArg(lean_object* v_x_645_, lean_object* v_x_646_, lean_object* v_x_647_){
_start:
{
uint64_t v___x_648_; size_t v___x_649_; size_t v___x_650_; lean_object* v___x_651_; 
v___x_648_ = l_Lean_instHashableMVarId_hash(v_x_646_);
v___x_649_ = lean_uint64_to_usize(v___x_648_);
v___x_650_ = ((size_t)1ULL);
v___x_651_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(v_x_645_, v___x_649_, v___x_650_, v_x_646_, v_x_647_);
return v___x_651_;
}
}
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(lean_object* v_mvarId_652_, lean_object* v_val_653_, lean_object* v___y_654_){
_start:
{
lean_object* v___x_656_; lean_object* v_mctx_657_; lean_object* v_cache_658_; lean_object* v_zetaDeltaFVarIds_659_; lean_object* v_postponed_660_; lean_object* v_diag_661_; lean_object* v___x_663_; uint8_t v_isShared_664_; uint8_t v_isSharedCheck_688_; 
v___x_656_ = lean_st_ref_take(v___y_654_);
v_mctx_657_ = lean_ctor_get(v___x_656_, 0);
v_cache_658_ = lean_ctor_get(v___x_656_, 1);
v_zetaDeltaFVarIds_659_ = lean_ctor_get(v___x_656_, 2);
v_postponed_660_ = lean_ctor_get(v___x_656_, 3);
v_diag_661_ = lean_ctor_get(v___x_656_, 4);
v_isSharedCheck_688_ = !lean_is_exclusive(v___x_656_);
if (v_isSharedCheck_688_ == 0)
{
v___x_663_ = v___x_656_;
v_isShared_664_ = v_isSharedCheck_688_;
goto v_resetjp_662_;
}
else
{
lean_inc(v_diag_661_);
lean_inc(v_postponed_660_);
lean_inc(v_zetaDeltaFVarIds_659_);
lean_inc(v_cache_658_);
lean_inc(v_mctx_657_);
lean_dec(v___x_656_);
v___x_663_ = lean_box(0);
v_isShared_664_ = v_isSharedCheck_688_;
goto v_resetjp_662_;
}
v_resetjp_662_:
{
lean_object* v_depth_665_; lean_object* v_levelAssignDepth_666_; lean_object* v_mvarCounter_667_; lean_object* v_lDepth_668_; lean_object* v_decls_669_; lean_object* v_userNames_670_; lean_object* v_lAssignment_671_; lean_object* v_eAssignment_672_; lean_object* v_dAssignment_673_; lean_object* v___x_675_; uint8_t v_isShared_676_; uint8_t v_isSharedCheck_687_; 
v_depth_665_ = lean_ctor_get(v_mctx_657_, 0);
v_levelAssignDepth_666_ = lean_ctor_get(v_mctx_657_, 1);
v_mvarCounter_667_ = lean_ctor_get(v_mctx_657_, 2);
v_lDepth_668_ = lean_ctor_get(v_mctx_657_, 3);
v_decls_669_ = lean_ctor_get(v_mctx_657_, 4);
v_userNames_670_ = lean_ctor_get(v_mctx_657_, 5);
v_lAssignment_671_ = lean_ctor_get(v_mctx_657_, 6);
v_eAssignment_672_ = lean_ctor_get(v_mctx_657_, 7);
v_dAssignment_673_ = lean_ctor_get(v_mctx_657_, 8);
v_isSharedCheck_687_ = !lean_is_exclusive(v_mctx_657_);
if (v_isSharedCheck_687_ == 0)
{
v___x_675_ = v_mctx_657_;
v_isShared_676_ = v_isSharedCheck_687_;
goto v_resetjp_674_;
}
else
{
lean_inc(v_dAssignment_673_);
lean_inc(v_eAssignment_672_);
lean_inc(v_lAssignment_671_);
lean_inc(v_userNames_670_);
lean_inc(v_decls_669_);
lean_inc(v_lDepth_668_);
lean_inc(v_mvarCounter_667_);
lean_inc(v_levelAssignDepth_666_);
lean_inc(v_depth_665_);
lean_dec(v_mctx_657_);
v___x_675_ = lean_box(0);
v_isShared_676_ = v_isSharedCheck_687_;
goto v_resetjp_674_;
}
v_resetjp_674_:
{
lean_object* v___x_677_; lean_object* v___x_679_; 
v___x_677_ = l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10___redArg(v_eAssignment_672_, v_mvarId_652_, v_val_653_);
if (v_isShared_676_ == 0)
{
lean_ctor_set(v___x_675_, 7, v___x_677_);
v___x_679_ = v___x_675_;
goto v_reusejp_678_;
}
else
{
lean_object* v_reuseFailAlloc_686_; 
v_reuseFailAlloc_686_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_686_, 0, v_depth_665_);
lean_ctor_set(v_reuseFailAlloc_686_, 1, v_levelAssignDepth_666_);
lean_ctor_set(v_reuseFailAlloc_686_, 2, v_mvarCounter_667_);
lean_ctor_set(v_reuseFailAlloc_686_, 3, v_lDepth_668_);
lean_ctor_set(v_reuseFailAlloc_686_, 4, v_decls_669_);
lean_ctor_set(v_reuseFailAlloc_686_, 5, v_userNames_670_);
lean_ctor_set(v_reuseFailAlloc_686_, 6, v_lAssignment_671_);
lean_ctor_set(v_reuseFailAlloc_686_, 7, v___x_677_);
lean_ctor_set(v_reuseFailAlloc_686_, 8, v_dAssignment_673_);
v___x_679_ = v_reuseFailAlloc_686_;
goto v_reusejp_678_;
}
v_reusejp_678_:
{
lean_object* v___x_681_; 
if (v_isShared_664_ == 0)
{
lean_ctor_set(v___x_663_, 0, v___x_679_);
v___x_681_ = v___x_663_;
goto v_reusejp_680_;
}
else
{
lean_object* v_reuseFailAlloc_685_; 
v_reuseFailAlloc_685_ = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(v_reuseFailAlloc_685_, 0, v___x_679_);
lean_ctor_set(v_reuseFailAlloc_685_, 1, v_cache_658_);
lean_ctor_set(v_reuseFailAlloc_685_, 2, v_zetaDeltaFVarIds_659_);
lean_ctor_set(v_reuseFailAlloc_685_, 3, v_postponed_660_);
lean_ctor_set(v_reuseFailAlloc_685_, 4, v_diag_661_);
v___x_681_ = v_reuseFailAlloc_685_;
goto v_reusejp_680_;
}
v_reusejp_680_:
{
lean_object* v___x_682_; lean_object* v___x_683_; lean_object* v___x_684_; 
v___x_682_ = lean_st_ref_set(v___y_654_, v___x_681_);
v___x_683_ = lean_box(0);
v___x_684_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_684_, 0, v___x_683_);
return v___x_684_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg___boxed(lean_object* v_mvarId_689_, lean_object* v_val_690_, lean_object* v___y_691_, lean_object* v___y_692_){
_start:
{
lean_object* v_res_693_; 
v_res_693_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v_mvarId_689_, v_val_690_, v___y_691_);
lean_dec(v___y_691_);
return v_res_693_;
}
}
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24(lean_object* v_opts_694_, lean_object* v_opt_695_){
_start:
{
lean_object* v_name_696_; lean_object* v_defValue_697_; lean_object* v_map_698_; lean_object* v___x_699_; 
v_name_696_ = lean_ctor_get(v_opt_695_, 0);
v_defValue_697_ = lean_ctor_get(v_opt_695_, 1);
v_map_698_ = lean_ctor_get(v_opts_694_, 0);
v___x_699_ = l_Std_DTreeMap_Internal_Impl_Const_get_x3f___at___00Lean_NameMap_find_x3f_spec__0___redArg(v_map_698_, v_name_696_);
if (lean_obj_tag(v___x_699_) == 0)
{
lean_inc(v_defValue_697_);
return v_defValue_697_;
}
else
{
lean_object* v_val_700_; 
v_val_700_ = lean_ctor_get(v___x_699_, 0);
lean_inc(v_val_700_);
lean_dec_ref(v___x_699_);
if (lean_obj_tag(v_val_700_) == 3)
{
lean_object* v_v_701_; 
v_v_701_ = lean_ctor_get(v_val_700_, 0);
lean_inc(v_v_701_);
lean_dec_ref(v_val_700_);
return v_v_701_;
}
else
{
lean_dec(v_val_700_);
lean_inc(v_defValue_697_);
return v_defValue_697_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24___boxed(lean_object* v_opts_702_, lean_object* v_opt_703_){
_start:
{
lean_object* v_res_704_; 
v_res_704_ = l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24(v_opts_702_, v_opt_703_);
lean_dec_ref(v_opt_703_);
lean_dec_ref(v_opts_702_);
return v_res_704_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(lean_object* v_msgData_705_, lean_object* v___y_706_, lean_object* v___y_707_, lean_object* v___y_708_, lean_object* v___y_709_){
_start:
{
lean_object* v___x_711_; lean_object* v_env_712_; lean_object* v___x_713_; lean_object* v_mctx_714_; lean_object* v_lctx_715_; lean_object* v_options_716_; lean_object* v___x_717_; lean_object* v___x_718_; lean_object* v___x_719_; 
v___x_711_ = lean_st_ref_get(v___y_709_);
v_env_712_ = lean_ctor_get(v___x_711_, 0);
lean_inc_ref(v_env_712_);
lean_dec(v___x_711_);
v___x_713_ = lean_st_ref_get(v___y_707_);
v_mctx_714_ = lean_ctor_get(v___x_713_, 0);
lean_inc_ref(v_mctx_714_);
lean_dec(v___x_713_);
v_lctx_715_ = lean_ctor_get(v___y_706_, 2);
v_options_716_ = lean_ctor_get(v___y_708_, 2);
lean_inc_ref(v_options_716_);
lean_inc_ref(v_lctx_715_);
v___x_717_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_717_, 0, v_env_712_);
lean_ctor_set(v___x_717_, 1, v_mctx_714_);
lean_ctor_set(v___x_717_, 2, v_lctx_715_);
lean_ctor_set(v___x_717_, 3, v_options_716_);
v___x_718_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_718_, 0, v___x_717_);
lean_ctor_set(v___x_718_, 1, v_msgData_705_);
v___x_719_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_719_, 0, v___x_718_);
return v___x_719_;
}
}
LEAN_EXPORT lean_object* l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4___boxed(lean_object* v_msgData_720_, lean_object* v___y_721_, lean_object* v___y_722_, lean_object* v___y_723_, lean_object* v___y_724_, lean_object* v___y_725_){
_start:
{
lean_object* v_res_726_; 
v_res_726_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(v_msgData_720_, v___y_721_, v___y_722_, v___y_723_, v___y_724_);
lean_dec(v___y_724_);
lean_dec_ref(v___y_723_);
lean_dec(v___y_722_);
lean_dec_ref(v___y_721_);
return v_res_726_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25(size_t v_sz_727_, size_t v_i_728_, lean_object* v_bs_729_){
_start:
{
uint8_t v___x_730_; 
v___x_730_ = lean_usize_dec_lt(v_i_728_, v_sz_727_);
if (v___x_730_ == 0)
{
return v_bs_729_;
}
else
{
lean_object* v_v_731_; lean_object* v_msg_732_; lean_object* v___x_733_; lean_object* v_bs_x27_734_; size_t v___x_735_; size_t v___x_736_; lean_object* v___x_737_; 
v_v_731_ = lean_array_uget_borrowed(v_bs_729_, v_i_728_);
v_msg_732_ = lean_ctor_get(v_v_731_, 1);
lean_inc_ref(v_msg_732_);
v___x_733_ = lean_unsigned_to_nat(0u);
v_bs_x27_734_ = lean_array_uset(v_bs_729_, v_i_728_, v___x_733_);
v___x_735_ = ((size_t)1ULL);
v___x_736_ = lean_usize_add(v_i_728_, v___x_735_);
v___x_737_ = lean_array_uset(v_bs_x27_734_, v_i_728_, v_msg_732_);
v_i_728_ = v___x_736_;
v_bs_729_ = v___x_737_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25___boxed(lean_object* v_sz_739_, lean_object* v_i_740_, lean_object* v_bs_741_){
_start:
{
size_t v_sz_boxed_742_; size_t v_i_boxed_743_; lean_object* v_res_744_; 
v_sz_boxed_742_ = lean_unbox_usize(v_sz_739_);
lean_dec(v_sz_739_);
v_i_boxed_743_ = lean_unbox_usize(v_i_740_);
lean_dec(v_i_740_);
v_res_744_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25(v_sz_boxed_742_, v_i_boxed_743_, v_bs_741_);
return v_res_744_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22(lean_object* v_oldTraces_745_, lean_object* v_data_746_, lean_object* v_ref_747_, lean_object* v_msg_748_, lean_object* v___y_749_, lean_object* v___y_750_, lean_object* v___y_751_, lean_object* v___y_752_){
_start:
{
lean_object* v_fileName_754_; lean_object* v_fileMap_755_; lean_object* v_options_756_; lean_object* v_currRecDepth_757_; lean_object* v_maxRecDepth_758_; lean_object* v_ref_759_; lean_object* v_currNamespace_760_; lean_object* v_openDecls_761_; lean_object* v_initHeartbeats_762_; lean_object* v_maxHeartbeats_763_; lean_object* v_quotContext_764_; lean_object* v_currMacroScope_765_; uint8_t v_diag_766_; lean_object* v_cancelTk_x3f_767_; uint8_t v_suppressElabErrors_768_; lean_object* v_inheritedTraceOptions_769_; lean_object* v___x_771_; uint8_t v_isShared_772_; uint8_t v_isSharedCheck_824_; 
v_fileName_754_ = lean_ctor_get(v___y_751_, 0);
v_fileMap_755_ = lean_ctor_get(v___y_751_, 1);
v_options_756_ = lean_ctor_get(v___y_751_, 2);
v_currRecDepth_757_ = lean_ctor_get(v___y_751_, 3);
v_maxRecDepth_758_ = lean_ctor_get(v___y_751_, 4);
v_ref_759_ = lean_ctor_get(v___y_751_, 5);
v_currNamespace_760_ = lean_ctor_get(v___y_751_, 6);
v_openDecls_761_ = lean_ctor_get(v___y_751_, 7);
v_initHeartbeats_762_ = lean_ctor_get(v___y_751_, 8);
v_maxHeartbeats_763_ = lean_ctor_get(v___y_751_, 9);
v_quotContext_764_ = lean_ctor_get(v___y_751_, 10);
v_currMacroScope_765_ = lean_ctor_get(v___y_751_, 11);
v_diag_766_ = lean_ctor_get_uint8(v___y_751_, sizeof(void*)*14);
v_cancelTk_x3f_767_ = lean_ctor_get(v___y_751_, 12);
v_suppressElabErrors_768_ = lean_ctor_get_uint8(v___y_751_, sizeof(void*)*14 + 1);
v_inheritedTraceOptions_769_ = lean_ctor_get(v___y_751_, 13);
v_isSharedCheck_824_ = !lean_is_exclusive(v___y_751_);
if (v_isSharedCheck_824_ == 0)
{
v___x_771_ = v___y_751_;
v_isShared_772_ = v_isSharedCheck_824_;
goto v_resetjp_770_;
}
else
{
lean_inc(v_inheritedTraceOptions_769_);
lean_inc(v_cancelTk_x3f_767_);
lean_inc(v_currMacroScope_765_);
lean_inc(v_quotContext_764_);
lean_inc(v_maxHeartbeats_763_);
lean_inc(v_initHeartbeats_762_);
lean_inc(v_openDecls_761_);
lean_inc(v_currNamespace_760_);
lean_inc(v_ref_759_);
lean_inc(v_maxRecDepth_758_);
lean_inc(v_currRecDepth_757_);
lean_inc(v_options_756_);
lean_inc(v_fileMap_755_);
lean_inc(v_fileName_754_);
lean_dec(v___y_751_);
v___x_771_ = lean_box(0);
v_isShared_772_ = v_isSharedCheck_824_;
goto v_resetjp_770_;
}
v_resetjp_770_:
{
lean_object* v___x_773_; lean_object* v_traceState_774_; lean_object* v_traces_775_; lean_object* v_ref_776_; lean_object* v___x_778_; 
v___x_773_ = lean_st_ref_get(v___y_752_);
v_traceState_774_ = lean_ctor_get(v___x_773_, 4);
lean_inc_ref(v_traceState_774_);
lean_dec(v___x_773_);
v_traces_775_ = lean_ctor_get(v_traceState_774_, 0);
lean_inc_ref(v_traces_775_);
lean_dec_ref(v_traceState_774_);
v_ref_776_ = l_Lean_replaceRef(v_ref_747_, v_ref_759_);
lean_dec(v_ref_759_);
if (v_isShared_772_ == 0)
{
lean_ctor_set(v___x_771_, 5, v_ref_776_);
v___x_778_ = v___x_771_;
goto v_reusejp_777_;
}
else
{
lean_object* v_reuseFailAlloc_823_; 
v_reuseFailAlloc_823_ = lean_alloc_ctor(0, 14, 2);
lean_ctor_set(v_reuseFailAlloc_823_, 0, v_fileName_754_);
lean_ctor_set(v_reuseFailAlloc_823_, 1, v_fileMap_755_);
lean_ctor_set(v_reuseFailAlloc_823_, 2, v_options_756_);
lean_ctor_set(v_reuseFailAlloc_823_, 3, v_currRecDepth_757_);
lean_ctor_set(v_reuseFailAlloc_823_, 4, v_maxRecDepth_758_);
lean_ctor_set(v_reuseFailAlloc_823_, 5, v_ref_776_);
lean_ctor_set(v_reuseFailAlloc_823_, 6, v_currNamespace_760_);
lean_ctor_set(v_reuseFailAlloc_823_, 7, v_openDecls_761_);
lean_ctor_set(v_reuseFailAlloc_823_, 8, v_initHeartbeats_762_);
lean_ctor_set(v_reuseFailAlloc_823_, 9, v_maxHeartbeats_763_);
lean_ctor_set(v_reuseFailAlloc_823_, 10, v_quotContext_764_);
lean_ctor_set(v_reuseFailAlloc_823_, 11, v_currMacroScope_765_);
lean_ctor_set(v_reuseFailAlloc_823_, 12, v_cancelTk_x3f_767_);
lean_ctor_set(v_reuseFailAlloc_823_, 13, v_inheritedTraceOptions_769_);
lean_ctor_set_uint8(v_reuseFailAlloc_823_, sizeof(void*)*14, v_diag_766_);
lean_ctor_set_uint8(v_reuseFailAlloc_823_, sizeof(void*)*14 + 1, v_suppressElabErrors_768_);
v___x_778_ = v_reuseFailAlloc_823_;
goto v_reusejp_777_;
}
v_reusejp_777_:
{
lean_object* v___x_779_; size_t v_sz_780_; size_t v___x_781_; lean_object* v___x_782_; lean_object* v_msg_783_; lean_object* v___x_784_; lean_object* v_a_785_; lean_object* v___x_787_; uint8_t v_isShared_788_; uint8_t v_isSharedCheck_822_; 
v___x_779_ = l_Lean_PersistentArray_toArray___redArg(v_traces_775_);
lean_dec_ref(v_traces_775_);
v_sz_780_ = lean_array_size(v___x_779_);
v___x_781_ = ((size_t)0ULL);
v___x_782_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00__private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22_spec__25(v_sz_780_, v___x_781_, v___x_779_);
v_msg_783_ = lean_alloc_ctor(9, 3, 0);
lean_ctor_set(v_msg_783_, 0, v_data_746_);
lean_ctor_set(v_msg_783_, 1, v_msg_748_);
lean_ctor_set(v_msg_783_, 2, v___x_782_);
v___x_784_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(v_msg_783_, v___y_749_, v___y_750_, v___x_778_, v___y_752_);
lean_dec_ref(v___x_778_);
v_a_785_ = lean_ctor_get(v___x_784_, 0);
v_isSharedCheck_822_ = !lean_is_exclusive(v___x_784_);
if (v_isSharedCheck_822_ == 0)
{
v___x_787_ = v___x_784_;
v_isShared_788_ = v_isSharedCheck_822_;
goto v_resetjp_786_;
}
else
{
lean_inc(v_a_785_);
lean_dec(v___x_784_);
v___x_787_ = lean_box(0);
v_isShared_788_ = v_isSharedCheck_822_;
goto v_resetjp_786_;
}
v_resetjp_786_:
{
lean_object* v___x_789_; lean_object* v_traceState_790_; lean_object* v_env_791_; lean_object* v_nextMacroScope_792_; lean_object* v_ngen_793_; lean_object* v_auxDeclNGen_794_; lean_object* v_cache_795_; lean_object* v_messages_796_; lean_object* v_infoState_797_; lean_object* v_snapshotTasks_798_; lean_object* v___x_800_; uint8_t v_isShared_801_; uint8_t v_isSharedCheck_821_; 
v___x_789_ = lean_st_ref_take(v___y_752_);
v_traceState_790_ = lean_ctor_get(v___x_789_, 4);
v_env_791_ = lean_ctor_get(v___x_789_, 0);
v_nextMacroScope_792_ = lean_ctor_get(v___x_789_, 1);
v_ngen_793_ = lean_ctor_get(v___x_789_, 2);
v_auxDeclNGen_794_ = lean_ctor_get(v___x_789_, 3);
v_cache_795_ = lean_ctor_get(v___x_789_, 5);
v_messages_796_ = lean_ctor_get(v___x_789_, 6);
v_infoState_797_ = lean_ctor_get(v___x_789_, 7);
v_snapshotTasks_798_ = lean_ctor_get(v___x_789_, 8);
v_isSharedCheck_821_ = !lean_is_exclusive(v___x_789_);
if (v_isSharedCheck_821_ == 0)
{
v___x_800_ = v___x_789_;
v_isShared_801_ = v_isSharedCheck_821_;
goto v_resetjp_799_;
}
else
{
lean_inc(v_snapshotTasks_798_);
lean_inc(v_infoState_797_);
lean_inc(v_messages_796_);
lean_inc(v_cache_795_);
lean_inc(v_traceState_790_);
lean_inc(v_auxDeclNGen_794_);
lean_inc(v_ngen_793_);
lean_inc(v_nextMacroScope_792_);
lean_inc(v_env_791_);
lean_dec(v___x_789_);
v___x_800_ = lean_box(0);
v_isShared_801_ = v_isSharedCheck_821_;
goto v_resetjp_799_;
}
v_resetjp_799_:
{
uint64_t v_tid_802_; lean_object* v___x_804_; uint8_t v_isShared_805_; uint8_t v_isSharedCheck_819_; 
v_tid_802_ = lean_ctor_get_uint64(v_traceState_790_, sizeof(void*)*1);
v_isSharedCheck_819_ = !lean_is_exclusive(v_traceState_790_);
if (v_isSharedCheck_819_ == 0)
{
lean_object* v_unused_820_; 
v_unused_820_ = lean_ctor_get(v_traceState_790_, 0);
lean_dec(v_unused_820_);
v___x_804_ = v_traceState_790_;
v_isShared_805_ = v_isSharedCheck_819_;
goto v_resetjp_803_;
}
else
{
lean_dec(v_traceState_790_);
v___x_804_ = lean_box(0);
v_isShared_805_ = v_isSharedCheck_819_;
goto v_resetjp_803_;
}
v_resetjp_803_:
{
lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___x_809_; 
v___x_806_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_806_, 0, v_ref_747_);
lean_ctor_set(v___x_806_, 1, v_a_785_);
v___x_807_ = l_Lean_PersistentArray_push___redArg(v_oldTraces_745_, v___x_806_);
if (v_isShared_805_ == 0)
{
lean_ctor_set(v___x_804_, 0, v___x_807_);
v___x_809_ = v___x_804_;
goto v_reusejp_808_;
}
else
{
lean_object* v_reuseFailAlloc_818_; 
v_reuseFailAlloc_818_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v_reuseFailAlloc_818_, 0, v___x_807_);
lean_ctor_set_uint64(v_reuseFailAlloc_818_, sizeof(void*)*1, v_tid_802_);
v___x_809_ = v_reuseFailAlloc_818_;
goto v_reusejp_808_;
}
v_reusejp_808_:
{
lean_object* v___x_811_; 
if (v_isShared_801_ == 0)
{
lean_ctor_set(v___x_800_, 4, v___x_809_);
v___x_811_ = v___x_800_;
goto v_reusejp_810_;
}
else
{
lean_object* v_reuseFailAlloc_817_; 
v_reuseFailAlloc_817_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_817_, 0, v_env_791_);
lean_ctor_set(v_reuseFailAlloc_817_, 1, v_nextMacroScope_792_);
lean_ctor_set(v_reuseFailAlloc_817_, 2, v_ngen_793_);
lean_ctor_set(v_reuseFailAlloc_817_, 3, v_auxDeclNGen_794_);
lean_ctor_set(v_reuseFailAlloc_817_, 4, v___x_809_);
lean_ctor_set(v_reuseFailAlloc_817_, 5, v_cache_795_);
lean_ctor_set(v_reuseFailAlloc_817_, 6, v_messages_796_);
lean_ctor_set(v_reuseFailAlloc_817_, 7, v_infoState_797_);
lean_ctor_set(v_reuseFailAlloc_817_, 8, v_snapshotTasks_798_);
v___x_811_ = v_reuseFailAlloc_817_;
goto v_reusejp_810_;
}
v_reusejp_810_:
{
lean_object* v___x_812_; lean_object* v___x_813_; lean_object* v___x_815_; 
v___x_812_ = lean_st_ref_set(v___y_752_, v___x_811_);
v___x_813_ = lean_box(0);
if (v_isShared_788_ == 0)
{
lean_ctor_set(v___x_787_, 0, v___x_813_);
v___x_815_ = v___x_787_;
goto v_reusejp_814_;
}
else
{
lean_object* v_reuseFailAlloc_816_; 
v_reuseFailAlloc_816_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_816_, 0, v___x_813_);
v___x_815_ = v_reuseFailAlloc_816_;
goto v_reusejp_814_;
}
v_reusejp_814_:
{
return v___x_815_;
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22___boxed(lean_object* v_oldTraces_825_, lean_object* v_data_826_, lean_object* v_ref_827_, lean_object* v_msg_828_, lean_object* v___y_829_, lean_object* v___y_830_, lean_object* v___y_831_, lean_object* v___y_832_, lean_object* v___y_833_){
_start:
{
lean_object* v_res_834_; 
v_res_834_ = l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22(v_oldTraces_825_, v_data_826_, v_ref_827_, v_msg_828_, v___y_829_, v___y_830_, v___y_831_, v___y_832_);
lean_dec(v___y_832_);
lean_dec(v___y_830_);
lean_dec_ref(v___y_829_);
return v_res_834_;
}
}
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(lean_object* v_x_835_){
_start:
{
if (lean_obj_tag(v_x_835_) == 0)
{
lean_object* v_a_837_; lean_object* v___x_839_; uint8_t v_isShared_840_; uint8_t v_isSharedCheck_844_; 
v_a_837_ = lean_ctor_get(v_x_835_, 0);
v_isSharedCheck_844_ = !lean_is_exclusive(v_x_835_);
if (v_isSharedCheck_844_ == 0)
{
v___x_839_ = v_x_835_;
v_isShared_840_ = v_isSharedCheck_844_;
goto v_resetjp_838_;
}
else
{
lean_inc(v_a_837_);
lean_dec(v_x_835_);
v___x_839_ = lean_box(0);
v_isShared_840_ = v_isSharedCheck_844_;
goto v_resetjp_838_;
}
v_resetjp_838_:
{
lean_object* v___x_842_; 
if (v_isShared_840_ == 0)
{
lean_ctor_set_tag(v___x_839_, 1);
v___x_842_ = v___x_839_;
goto v_reusejp_841_;
}
else
{
lean_object* v_reuseFailAlloc_843_; 
v_reuseFailAlloc_843_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_843_, 0, v_a_837_);
v___x_842_ = v_reuseFailAlloc_843_;
goto v_reusejp_841_;
}
v_reusejp_841_:
{
return v___x_842_;
}
}
}
else
{
lean_object* v_a_845_; lean_object* v___x_847_; uint8_t v_isShared_848_; uint8_t v_isSharedCheck_852_; 
v_a_845_ = lean_ctor_get(v_x_835_, 0);
v_isSharedCheck_852_ = !lean_is_exclusive(v_x_835_);
if (v_isSharedCheck_852_ == 0)
{
v___x_847_ = v_x_835_;
v_isShared_848_ = v_isSharedCheck_852_;
goto v_resetjp_846_;
}
else
{
lean_inc(v_a_845_);
lean_dec(v_x_835_);
v___x_847_ = lean_box(0);
v_isShared_848_ = v_isSharedCheck_852_;
goto v_resetjp_846_;
}
v_resetjp_846_:
{
lean_object* v___x_850_; 
if (v_isShared_848_ == 0)
{
lean_ctor_set_tag(v___x_847_, 0);
v___x_850_ = v___x_847_;
goto v_reusejp_849_;
}
else
{
lean_object* v_reuseFailAlloc_851_; 
v_reuseFailAlloc_851_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_851_, 0, v_a_845_);
v___x_850_ = v_reuseFailAlloc_851_;
goto v_reusejp_849_;
}
v_reusejp_849_:
{
return v___x_850_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg___boxed(lean_object* v_x_853_, lean_object* v___y_854_){
_start:
{
lean_object* v_res_855_; 
v_res_855_ = l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(v_x_853_);
return v_res_855_;
}
}
LEAN_EXPORT uint8_t l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21(lean_object* v_e_856_){
_start:
{
if (lean_obj_tag(v_e_856_) == 0)
{
uint8_t v___x_857_; 
v___x_857_ = 2;
return v___x_857_;
}
else
{
uint8_t v___x_858_; 
v___x_858_ = 0;
return v___x_858_;
}
}
}
LEAN_EXPORT lean_object* l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21___boxed(lean_object* v_e_859_){
_start:
{
uint8_t v_res_860_; lean_object* v_r_861_; 
v_res_860_ = l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21(v_e_859_);
lean_dec_ref(v_e_859_);
v_r_861_ = lean_box(v_res_860_);
return v_r_861_;
}
}
static lean_object* _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1(void){
_start:
{
lean_object* v___x_863_; lean_object* v___x_864_; 
v___x_863_ = ((lean_object*)(l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__0));
v___x_864_ = l_Lean_stringToMessageData(v___x_863_);
return v___x_864_;
}
}
static double _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2(void){
_start:
{
lean_object* v___x_865_; double v___x_866_; 
v___x_865_ = lean_unsigned_to_nat(0u);
v___x_866_ = lean_float_of_nat(v___x_865_);
return v___x_866_;
}
}
static lean_object* _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4(void){
_start:
{
lean_object* v___x_868_; lean_object* v___x_869_; 
v___x_868_ = ((lean_object*)(l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__3));
v___x_869_ = l_Lean_stringToMessageData(v___x_868_);
return v___x_869_;
}
}
static double _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5(void){
_start:
{
lean_object* v___x_870_; double v___x_871_; 
v___x_870_ = lean_unsigned_to_nat(1000u);
v___x_871_ = lean_float_of_nat(v___x_870_);
return v___x_871_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18(lean_object* v_cls_872_, uint8_t v_collapsed_873_, lean_object* v_tag_874_, lean_object* v_opts_875_, uint8_t v_clsEnabled_876_, lean_object* v_oldTraces_877_, lean_object* v_msg_878_, lean_object* v_resStartStop_879_, lean_object* v___y_880_, lean_object* v___y_881_, lean_object* v___y_882_, lean_object* v___y_883_){
_start:
{
lean_object* v_fst_885_; lean_object* v_snd_886_; lean_object* v___x_888_; uint8_t v_isShared_889_; uint8_t v_isSharedCheck_984_; 
v_fst_885_ = lean_ctor_get(v_resStartStop_879_, 0);
v_snd_886_ = lean_ctor_get(v_resStartStop_879_, 1);
v_isSharedCheck_984_ = !lean_is_exclusive(v_resStartStop_879_);
if (v_isSharedCheck_984_ == 0)
{
v___x_888_ = v_resStartStop_879_;
v_isShared_889_ = v_isSharedCheck_984_;
goto v_resetjp_887_;
}
else
{
lean_inc(v_snd_886_);
lean_inc(v_fst_885_);
lean_dec(v_resStartStop_879_);
v___x_888_ = lean_box(0);
v_isShared_889_ = v_isSharedCheck_984_;
goto v_resetjp_887_;
}
v_resetjp_887_:
{
lean_object* v___y_891_; lean_object* v___y_892_; lean_object* v_data_893_; lean_object* v_fst_904_; lean_object* v_snd_905_; lean_object* v___x_907_; uint8_t v_isShared_908_; uint8_t v_isSharedCheck_983_; 
v_fst_904_ = lean_ctor_get(v_snd_886_, 0);
v_snd_905_ = lean_ctor_get(v_snd_886_, 1);
v_isSharedCheck_983_ = !lean_is_exclusive(v_snd_886_);
if (v_isSharedCheck_983_ == 0)
{
v___x_907_ = v_snd_886_;
v_isShared_908_ = v_isSharedCheck_983_;
goto v_resetjp_906_;
}
else
{
lean_inc(v_snd_905_);
lean_inc(v_fst_904_);
lean_dec(v_snd_886_);
v___x_907_ = lean_box(0);
v_isShared_908_ = v_isSharedCheck_983_;
goto v_resetjp_906_;
}
v___jp_890_:
{
lean_object* v___x_894_; 
v___x_894_ = l___private_Lean_Util_Trace_0__Lean_addTraceNode___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__22(v_oldTraces_877_, v_data_893_, v___y_892_, v___y_891_, v___y_880_, v___y_881_, v___y_882_, v___y_883_);
lean_dec(v___y_883_);
lean_dec(v___y_881_);
lean_dec_ref(v___y_880_);
if (lean_obj_tag(v___x_894_) == 0)
{
lean_object* v___x_895_; 
lean_dec_ref(v___x_894_);
v___x_895_ = l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(v_fst_885_);
return v___x_895_;
}
else
{
lean_object* v_a_896_; lean_object* v___x_898_; uint8_t v_isShared_899_; uint8_t v_isSharedCheck_903_; 
lean_dec(v_fst_885_);
v_a_896_ = lean_ctor_get(v___x_894_, 0);
v_isSharedCheck_903_ = !lean_is_exclusive(v___x_894_);
if (v_isSharedCheck_903_ == 0)
{
v___x_898_ = v___x_894_;
v_isShared_899_ = v_isSharedCheck_903_;
goto v_resetjp_897_;
}
else
{
lean_inc(v_a_896_);
lean_dec(v___x_894_);
v___x_898_ = lean_box(0);
v_isShared_899_ = v_isSharedCheck_903_;
goto v_resetjp_897_;
}
v_resetjp_897_:
{
lean_object* v___x_901_; 
if (v_isShared_899_ == 0)
{
v___x_901_ = v___x_898_;
goto v_reusejp_900_;
}
else
{
lean_object* v_reuseFailAlloc_902_; 
v_reuseFailAlloc_902_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_902_, 0, v_a_896_);
v___x_901_ = v_reuseFailAlloc_902_;
goto v_reusejp_900_;
}
v_reusejp_900_:
{
return v___x_901_;
}
}
}
}
v_resetjp_906_:
{
lean_object* v___x_909_; uint8_t v___x_910_; lean_object* v___y_912_; lean_object* v_a_913_; uint8_t v___y_937_; double v___y_968_; 
v___x_909_ = l_Lean_trace_profiler;
v___x_910_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_opts_875_, v___x_909_);
if (v___x_910_ == 0)
{
v___y_937_ = v___x_910_;
goto v___jp_936_;
}
else
{
lean_object* v___x_973_; uint8_t v___x_974_; 
v___x_973_ = l_Lean_trace_profiler_useHeartbeats;
v___x_974_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_opts_875_, v___x_973_);
if (v___x_974_ == 0)
{
lean_object* v___x_975_; lean_object* v___x_976_; double v___x_977_; double v___x_978_; double v___x_979_; 
v___x_975_ = l_Lean_trace_profiler_threshold;
v___x_976_ = l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24(v_opts_875_, v___x_975_);
v___x_977_ = lean_float_of_nat(v___x_976_);
v___x_978_ = lean_float_once(&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5, &l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5_once, _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__5);
v___x_979_ = lean_float_div(v___x_977_, v___x_978_);
v___y_968_ = v___x_979_;
goto v___jp_967_;
}
else
{
lean_object* v___x_980_; lean_object* v___x_981_; double v___x_982_; 
v___x_980_ = l_Lean_trace_profiler_threshold;
v___x_981_ = l_Lean_Option_get___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__24(v_opts_875_, v___x_980_);
v___x_982_ = lean_float_of_nat(v___x_981_);
v___y_968_ = v___x_982_;
goto v___jp_967_;
}
}
v___jp_911_:
{
uint8_t v_result_914_; lean_object* v___x_915_; lean_object* v___x_916_; lean_object* v___x_917_; lean_object* v___x_919_; 
v_result_914_ = l_Except_toTraceResult___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__21(v_fst_885_);
v___x_915_ = l_Lean_TraceResult_toEmoji(v_result_914_);
v___x_916_ = l_Lean_stringToMessageData(v___x_915_);
v___x_917_ = lean_obj_once(&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1, &l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1_once, _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__1);
if (v_isShared_908_ == 0)
{
lean_ctor_set_tag(v___x_907_, 7);
lean_ctor_set(v___x_907_, 1, v___x_917_);
lean_ctor_set(v___x_907_, 0, v___x_916_);
v___x_919_ = v___x_907_;
goto v_reusejp_918_;
}
else
{
lean_object* v_reuseFailAlloc_930_; 
v_reuseFailAlloc_930_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_930_, 0, v___x_916_);
lean_ctor_set(v_reuseFailAlloc_930_, 1, v___x_917_);
v___x_919_ = v_reuseFailAlloc_930_;
goto v_reusejp_918_;
}
v_reusejp_918_:
{
lean_object* v_m_921_; 
if (v_isShared_889_ == 0)
{
lean_ctor_set_tag(v___x_888_, 7);
lean_ctor_set(v___x_888_, 1, v_a_913_);
lean_ctor_set(v___x_888_, 0, v___x_919_);
v_m_921_ = v___x_888_;
goto v_reusejp_920_;
}
else
{
lean_object* v_reuseFailAlloc_929_; 
v_reuseFailAlloc_929_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_929_, 0, v___x_919_);
lean_ctor_set(v_reuseFailAlloc_929_, 1, v_a_913_);
v_m_921_ = v_reuseFailAlloc_929_;
goto v_reusejp_920_;
}
v_reusejp_920_:
{
lean_object* v___x_922_; lean_object* v___x_923_; double v___x_924_; lean_object* v_data_925_; 
v___x_922_ = lean_box(v_result_914_);
v___x_923_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_923_, 0, v___x_922_);
v___x_924_ = lean_float_once(&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2, &l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2_once, _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2);
lean_inc_ref(v_tag_874_);
lean_inc_ref(v___x_923_);
lean_inc(v_cls_872_);
v_data_925_ = lean_alloc_ctor(0, 3, 17);
lean_ctor_set(v_data_925_, 0, v_cls_872_);
lean_ctor_set(v_data_925_, 1, v___x_923_);
lean_ctor_set(v_data_925_, 2, v_tag_874_);
lean_ctor_set_float(v_data_925_, sizeof(void*)*3, v___x_924_);
lean_ctor_set_float(v_data_925_, sizeof(void*)*3 + 8, v___x_924_);
lean_ctor_set_uint8(v_data_925_, sizeof(void*)*3 + 16, v_collapsed_873_);
if (v___x_910_ == 0)
{
lean_dec_ref(v___x_923_);
lean_dec(v_snd_905_);
lean_dec(v_fst_904_);
lean_dec_ref(v_tag_874_);
lean_dec(v_cls_872_);
v___y_891_ = v_m_921_;
v___y_892_ = v___y_912_;
v_data_893_ = v_data_925_;
goto v___jp_890_;
}
else
{
lean_object* v_data_926_; double v___x_927_; double v___x_928_; 
lean_dec_ref(v_data_925_);
v_data_926_ = lean_alloc_ctor(0, 3, 17);
lean_ctor_set(v_data_926_, 0, v_cls_872_);
lean_ctor_set(v_data_926_, 1, v___x_923_);
lean_ctor_set(v_data_926_, 2, v_tag_874_);
v___x_927_ = lean_unbox_float(v_fst_904_);
lean_dec(v_fst_904_);
lean_ctor_set_float(v_data_926_, sizeof(void*)*3, v___x_927_);
v___x_928_ = lean_unbox_float(v_snd_905_);
lean_dec(v_snd_905_);
lean_ctor_set_float(v_data_926_, sizeof(void*)*3 + 8, v___x_928_);
lean_ctor_set_uint8(v_data_926_, sizeof(void*)*3 + 16, v_collapsed_873_);
v___y_891_ = v_m_921_;
v___y_892_ = v___y_912_;
v_data_893_ = v_data_926_;
goto v___jp_890_;
}
}
}
}
v___jp_931_:
{
lean_object* v_ref_932_; lean_object* v___x_933_; 
v_ref_932_ = lean_ctor_get(v___y_882_, 5);
lean_inc(v___y_883_);
lean_inc_ref(v___y_882_);
lean_inc(v___y_881_);
lean_inc_ref(v___y_880_);
lean_inc(v_fst_885_);
v___x_933_ = lean_apply_6(v_msg_878_, v_fst_885_, v___y_880_, v___y_881_, v___y_882_, v___y_883_, lean_box(0));
if (lean_obj_tag(v___x_933_) == 0)
{
lean_object* v_a_934_; 
v_a_934_ = lean_ctor_get(v___x_933_, 0);
lean_inc(v_a_934_);
lean_dec_ref(v___x_933_);
lean_inc(v_ref_932_);
v___y_912_ = v_ref_932_;
v_a_913_ = v_a_934_;
goto v___jp_911_;
}
else
{
lean_object* v___x_935_; 
lean_dec_ref(v___x_933_);
v___x_935_ = lean_obj_once(&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4, &l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4_once, _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__4);
lean_inc(v_ref_932_);
v___y_912_ = v_ref_932_;
v_a_913_ = v___x_935_;
goto v___jp_911_;
}
}
v___jp_936_:
{
if (v_clsEnabled_876_ == 0)
{
if (v___y_937_ == 0)
{
lean_object* v___x_938_; lean_object* v_traceState_939_; lean_object* v_env_940_; lean_object* v_nextMacroScope_941_; lean_object* v_ngen_942_; lean_object* v_auxDeclNGen_943_; lean_object* v_cache_944_; lean_object* v_messages_945_; lean_object* v_infoState_946_; lean_object* v_snapshotTasks_947_; lean_object* v___x_949_; uint8_t v_isShared_950_; uint8_t v_isSharedCheck_966_; 
lean_del_object(v___x_907_);
lean_dec(v_snd_905_);
lean_dec(v_fst_904_);
lean_del_object(v___x_888_);
lean_dec_ref(v___y_882_);
lean_dec(v___y_881_);
lean_dec_ref(v___y_880_);
lean_dec_ref(v_msg_878_);
lean_dec_ref(v_tag_874_);
lean_dec(v_cls_872_);
v___x_938_ = lean_st_ref_take(v___y_883_);
v_traceState_939_ = lean_ctor_get(v___x_938_, 4);
v_env_940_ = lean_ctor_get(v___x_938_, 0);
v_nextMacroScope_941_ = lean_ctor_get(v___x_938_, 1);
v_ngen_942_ = lean_ctor_get(v___x_938_, 2);
v_auxDeclNGen_943_ = lean_ctor_get(v___x_938_, 3);
v_cache_944_ = lean_ctor_get(v___x_938_, 5);
v_messages_945_ = lean_ctor_get(v___x_938_, 6);
v_infoState_946_ = lean_ctor_get(v___x_938_, 7);
v_snapshotTasks_947_ = lean_ctor_get(v___x_938_, 8);
v_isSharedCheck_966_ = !lean_is_exclusive(v___x_938_);
if (v_isSharedCheck_966_ == 0)
{
v___x_949_ = v___x_938_;
v_isShared_950_ = v_isSharedCheck_966_;
goto v_resetjp_948_;
}
else
{
lean_inc(v_snapshotTasks_947_);
lean_inc(v_infoState_946_);
lean_inc(v_messages_945_);
lean_inc(v_cache_944_);
lean_inc(v_traceState_939_);
lean_inc(v_auxDeclNGen_943_);
lean_inc(v_ngen_942_);
lean_inc(v_nextMacroScope_941_);
lean_inc(v_env_940_);
lean_dec(v___x_938_);
v___x_949_ = lean_box(0);
v_isShared_950_ = v_isSharedCheck_966_;
goto v_resetjp_948_;
}
v_resetjp_948_:
{
uint64_t v_tid_951_; lean_object* v_traces_952_; lean_object* v___x_954_; uint8_t v_isShared_955_; uint8_t v_isSharedCheck_965_; 
v_tid_951_ = lean_ctor_get_uint64(v_traceState_939_, sizeof(void*)*1);
v_traces_952_ = lean_ctor_get(v_traceState_939_, 0);
v_isSharedCheck_965_ = !lean_is_exclusive(v_traceState_939_);
if (v_isSharedCheck_965_ == 0)
{
v___x_954_ = v_traceState_939_;
v_isShared_955_ = v_isSharedCheck_965_;
goto v_resetjp_953_;
}
else
{
lean_inc(v_traces_952_);
lean_dec(v_traceState_939_);
v___x_954_ = lean_box(0);
v_isShared_955_ = v_isSharedCheck_965_;
goto v_resetjp_953_;
}
v_resetjp_953_:
{
lean_object* v___x_956_; lean_object* v___x_958_; 
v___x_956_ = l_Lean_PersistentArray_append___redArg(v_oldTraces_877_, v_traces_952_);
lean_dec_ref(v_traces_952_);
if (v_isShared_955_ == 0)
{
lean_ctor_set(v___x_954_, 0, v___x_956_);
v___x_958_ = v___x_954_;
goto v_reusejp_957_;
}
else
{
lean_object* v_reuseFailAlloc_964_; 
v_reuseFailAlloc_964_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v_reuseFailAlloc_964_, 0, v___x_956_);
lean_ctor_set_uint64(v_reuseFailAlloc_964_, sizeof(void*)*1, v_tid_951_);
v___x_958_ = v_reuseFailAlloc_964_;
goto v_reusejp_957_;
}
v_reusejp_957_:
{
lean_object* v___x_960_; 
if (v_isShared_950_ == 0)
{
lean_ctor_set(v___x_949_, 4, v___x_958_);
v___x_960_ = v___x_949_;
goto v_reusejp_959_;
}
else
{
lean_object* v_reuseFailAlloc_963_; 
v_reuseFailAlloc_963_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_963_, 0, v_env_940_);
lean_ctor_set(v_reuseFailAlloc_963_, 1, v_nextMacroScope_941_);
lean_ctor_set(v_reuseFailAlloc_963_, 2, v_ngen_942_);
lean_ctor_set(v_reuseFailAlloc_963_, 3, v_auxDeclNGen_943_);
lean_ctor_set(v_reuseFailAlloc_963_, 4, v___x_958_);
lean_ctor_set(v_reuseFailAlloc_963_, 5, v_cache_944_);
lean_ctor_set(v_reuseFailAlloc_963_, 6, v_messages_945_);
lean_ctor_set(v_reuseFailAlloc_963_, 7, v_infoState_946_);
lean_ctor_set(v_reuseFailAlloc_963_, 8, v_snapshotTasks_947_);
v___x_960_ = v_reuseFailAlloc_963_;
goto v_reusejp_959_;
}
v_reusejp_959_:
{
lean_object* v___x_961_; lean_object* v___x_962_; 
v___x_961_ = lean_st_ref_set(v___y_883_, v___x_960_);
lean_dec(v___y_883_);
v___x_962_ = l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(v_fst_885_);
return v___x_962_;
}
}
}
}
}
else
{
goto v___jp_931_;
}
}
else
{
goto v___jp_931_;
}
}
v___jp_967_:
{
double v___x_969_; double v___x_970_; double v___x_971_; uint8_t v___x_972_; 
v___x_969_ = lean_unbox_float(v_snd_905_);
v___x_970_ = lean_unbox_float(v_fst_904_);
v___x_971_ = lean_float_sub(v___x_969_, v___x_970_);
v___x_972_ = lean_float_decLt(v___y_968_, v___x_971_);
v___y_937_ = v___x_972_;
goto v___jp_936_;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___boxed(lean_object* v_cls_985_, lean_object* v_collapsed_986_, lean_object* v_tag_987_, lean_object* v_opts_988_, lean_object* v_clsEnabled_989_, lean_object* v_oldTraces_990_, lean_object* v_msg_991_, lean_object* v_resStartStop_992_, lean_object* v___y_993_, lean_object* v___y_994_, lean_object* v___y_995_, lean_object* v___y_996_, lean_object* v___y_997_){
_start:
{
uint8_t v_collapsed_boxed_998_; uint8_t v_clsEnabled_boxed_999_; lean_object* v_res_1000_; 
v_collapsed_boxed_998_ = lean_unbox(v_collapsed_986_);
v_clsEnabled_boxed_999_ = lean_unbox(v_clsEnabled_989_);
v_res_1000_ = l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18(v_cls_985_, v_collapsed_boxed_998_, v_tag_987_, v_opts_988_, v_clsEnabled_boxed_999_, v_oldTraces_990_, v_msg_991_, v_resStartStop_992_, v___y_993_, v___y_994_, v___y_995_, v___y_996_);
lean_dec_ref(v_opts_988_);
return v_res_1000_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0(void){
_start:
{
lean_object* v___x_1001_; 
v___x_1001_ = l_Lean_PersistentHashMap_mkEmptyEntriesArray(lean_box(0), lean_box(0));
return v___x_1001_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1(void){
_start:
{
lean_object* v___x_1002_; lean_object* v___x_1003_; 
v___x_1002_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__0);
v___x_1003_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1003_, 0, v___x_1002_);
return v___x_1003_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2(void){
_start:
{
lean_object* v___x_1004_; lean_object* v___x_1005_; lean_object* v___x_1006_; 
v___x_1004_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1);
v___x_1005_ = lean_unsigned_to_nat(0u);
v___x_1006_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v___x_1006_, 0, v___x_1005_);
lean_ctor_set(v___x_1006_, 1, v___x_1005_);
lean_ctor_set(v___x_1006_, 2, v___x_1005_);
lean_ctor_set(v___x_1006_, 3, v___x_1004_);
lean_ctor_set(v___x_1006_, 4, v___x_1004_);
lean_ctor_set(v___x_1006_, 5, v___x_1004_);
lean_ctor_set(v___x_1006_, 6, v___x_1004_);
lean_ctor_set(v___x_1006_, 7, v___x_1004_);
lean_ctor_set(v___x_1006_, 8, v___x_1004_);
return v___x_1006_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3(void){
_start:
{
lean_object* v___x_1007_; lean_object* v___x_1008_; lean_object* v___x_1009_; 
v___x_1007_ = lean_unsigned_to_nat(32u);
v___x_1008_ = lean_mk_empty_array_with_capacity(v___x_1007_);
v___x_1009_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1009_, 0, v___x_1008_);
return v___x_1009_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4(void){
_start:
{
size_t v___x_1010_; lean_object* v___x_1011_; lean_object* v___x_1012_; lean_object* v___x_1013_; lean_object* v___x_1014_; lean_object* v___x_1015_; 
v___x_1010_ = ((size_t)5ULL);
v___x_1011_ = lean_unsigned_to_nat(0u);
v___x_1012_ = lean_unsigned_to_nat(32u);
v___x_1013_ = lean_mk_empty_array_with_capacity(v___x_1012_);
v___x_1014_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__3);
v___x_1015_ = lean_alloc_ctor(0, 4, sizeof(size_t)*1);
lean_ctor_set(v___x_1015_, 0, v___x_1014_);
lean_ctor_set(v___x_1015_, 1, v___x_1013_);
lean_ctor_set(v___x_1015_, 2, v___x_1011_);
lean_ctor_set(v___x_1015_, 3, v___x_1011_);
lean_ctor_set_usize(v___x_1015_, 4, v___x_1010_);
return v___x_1015_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5(void){
_start:
{
lean_object* v___x_1016_; lean_object* v___x_1017_; lean_object* v___x_1018_; lean_object* v___x_1019_; 
v___x_1016_ = lean_box(1);
v___x_1017_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__4);
v___x_1018_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__1);
v___x_1019_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_1019_, 0, v___x_1018_);
lean_ctor_set(v___x_1019_, 1, v___x_1017_);
lean_ctor_set(v___x_1019_, 2, v___x_1016_);
return v___x_1019_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7(void){
_start:
{
lean_object* v___x_1021_; lean_object* v___x_1022_; 
v___x_1021_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__6));
v___x_1022_ = l_Lean_stringToMessageData(v___x_1021_);
return v___x_1022_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9(void){
_start:
{
lean_object* v___x_1024_; lean_object* v___x_1025_; 
v___x_1024_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__8));
v___x_1025_ = l_Lean_stringToMessageData(v___x_1024_);
return v___x_1025_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11(void){
_start:
{
lean_object* v___x_1027_; lean_object* v___x_1028_; 
v___x_1027_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__10));
v___x_1028_ = l_Lean_stringToMessageData(v___x_1027_);
return v___x_1028_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13(void){
_start:
{
lean_object* v___x_1030_; lean_object* v___x_1031_; 
v___x_1030_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__12));
v___x_1031_ = l_Lean_stringToMessageData(v___x_1030_);
return v___x_1031_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15(void){
_start:
{
lean_object* v___x_1033_; lean_object* v___x_1034_; 
v___x_1033_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__14));
v___x_1034_ = l_Lean_stringToMessageData(v___x_1033_);
return v___x_1034_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17(void){
_start:
{
lean_object* v___x_1036_; lean_object* v___x_1037_; 
v___x_1036_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__16));
v___x_1037_ = l_Lean_stringToMessageData(v___x_1036_);
return v___x_1037_;
}
}
static lean_object* _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19(void){
_start:
{
lean_object* v___x_1039_; lean_object* v___x_1040_; 
v___x_1039_ = ((lean_object*)(l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__18));
v___x_1040_ = l_Lean_stringToMessageData(v___x_1039_);
return v___x_1040_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg(lean_object* v_msg_1041_, lean_object* v_declHint_1042_, lean_object* v___y_1043_){
_start:
{
lean_object* v___x_1045_; lean_object* v_env_1046_; uint8_t v___x_1047_; 
v___x_1045_ = lean_st_ref_get(v___y_1043_);
v_env_1046_ = lean_ctor_get(v___x_1045_, 0);
lean_inc_ref(v_env_1046_);
lean_dec(v___x_1045_);
v___x_1047_ = l_Lean_Name_isAnonymous(v_declHint_1042_);
if (v___x_1047_ == 0)
{
uint8_t v_isExporting_1048_; 
v_isExporting_1048_ = lean_ctor_get_uint8(v_env_1046_, sizeof(void*)*8);
if (v_isExporting_1048_ == 0)
{
lean_object* v___x_1049_; 
lean_dec_ref(v_env_1046_);
lean_dec(v_declHint_1042_);
v___x_1049_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1049_, 0, v_msg_1041_);
return v___x_1049_;
}
else
{
lean_object* v___x_1050_; uint8_t v___x_1051_; 
lean_inc_ref(v_env_1046_);
v___x_1050_ = l_Lean_Environment_setExporting(v_env_1046_, v___x_1047_);
lean_inc(v_declHint_1042_);
lean_inc_ref(v___x_1050_);
v___x_1051_ = l_Lean_Environment_contains(v___x_1050_, v_declHint_1042_, v_isExporting_1048_);
if (v___x_1051_ == 0)
{
lean_object* v___x_1052_; 
lean_dec_ref(v___x_1050_);
lean_dec_ref(v_env_1046_);
lean_dec(v_declHint_1042_);
v___x_1052_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1052_, 0, v_msg_1041_);
return v___x_1052_;
}
else
{
lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v_c_1058_; lean_object* v___x_1059_; 
v___x_1053_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__2);
v___x_1054_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__5);
v___x_1055_ = l_Lean_Options_empty;
v___x_1056_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_1056_, 0, v___x_1050_);
lean_ctor_set(v___x_1056_, 1, v___x_1053_);
lean_ctor_set(v___x_1056_, 2, v___x_1054_);
lean_ctor_set(v___x_1056_, 3, v___x_1055_);
lean_inc(v_declHint_1042_);
v___x_1057_ = l_Lean_MessageData_ofConstName(v_declHint_1042_, v___x_1047_);
v_c_1058_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v_c_1058_, 0, v___x_1056_);
lean_ctor_set(v_c_1058_, 1, v___x_1057_);
v___x_1059_ = l_Lean_Environment_getModuleIdxFor_x3f(v_env_1046_, v_declHint_1042_);
if (lean_obj_tag(v___x_1059_) == 0)
{
lean_object* v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; lean_object* v___x_1065_; lean_object* v___x_1066_; 
lean_dec_ref(v_env_1046_);
lean_dec(v_declHint_1042_);
v___x_1060_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7);
v___x_1061_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1061_, 0, v___x_1060_);
lean_ctor_set(v___x_1061_, 1, v_c_1058_);
v___x_1062_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__9);
v___x_1063_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1063_, 0, v___x_1061_);
lean_ctor_set(v___x_1063_, 1, v___x_1062_);
v___x_1064_ = l_Lean_MessageData_note(v___x_1063_);
v___x_1065_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1065_, 0, v_msg_1041_);
lean_ctor_set(v___x_1065_, 1, v___x_1064_);
v___x_1066_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1066_, 0, v___x_1065_);
return v___x_1066_;
}
else
{
lean_object* v_val_1067_; lean_object* v___x_1069_; uint8_t v_isShared_1070_; uint8_t v_isSharedCheck_1102_; 
v_val_1067_ = lean_ctor_get(v___x_1059_, 0);
v_isSharedCheck_1102_ = !lean_is_exclusive(v___x_1059_);
if (v_isSharedCheck_1102_ == 0)
{
v___x_1069_ = v___x_1059_;
v_isShared_1070_ = v_isSharedCheck_1102_;
goto v_resetjp_1068_;
}
else
{
lean_inc(v_val_1067_);
lean_dec(v___x_1059_);
v___x_1069_ = lean_box(0);
v_isShared_1070_ = v_isSharedCheck_1102_;
goto v_resetjp_1068_;
}
v_resetjp_1068_:
{
lean_object* v___x_1071_; lean_object* v___x_1072_; lean_object* v___x_1073_; lean_object* v_mod_1074_; uint8_t v___x_1075_; 
v___x_1071_ = lean_box(0);
v___x_1072_ = l_Lean_Environment_header(v_env_1046_);
lean_dec_ref(v_env_1046_);
v___x_1073_ = l_Lean_EnvironmentHeader_moduleNames(v___x_1072_);
v_mod_1074_ = lean_array_get(v___x_1071_, v___x_1073_, v_val_1067_);
lean_dec(v_val_1067_);
lean_dec_ref(v___x_1073_);
v___x_1075_ = l_Lean_isPrivateName(v_declHint_1042_);
lean_dec(v_declHint_1042_);
if (v___x_1075_ == 0)
{
lean_object* v___x_1076_; lean_object* v___x_1077_; lean_object* v___x_1078_; lean_object* v___x_1079_; lean_object* v___x_1080_; lean_object* v___x_1081_; lean_object* v___x_1082_; lean_object* v___x_1083_; lean_object* v___x_1084_; lean_object* v___x_1085_; lean_object* v___x_1087_; 
v___x_1076_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__11);
v___x_1077_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1077_, 0, v___x_1076_);
lean_ctor_set(v___x_1077_, 1, v_c_1058_);
v___x_1078_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__13);
v___x_1079_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1079_, 0, v___x_1077_);
lean_ctor_set(v___x_1079_, 1, v___x_1078_);
v___x_1080_ = l_Lean_MessageData_ofName(v_mod_1074_);
v___x_1081_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1081_, 0, v___x_1079_);
lean_ctor_set(v___x_1081_, 1, v___x_1080_);
v___x_1082_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__15);
v___x_1083_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1083_, 0, v___x_1081_);
lean_ctor_set(v___x_1083_, 1, v___x_1082_);
v___x_1084_ = l_Lean_MessageData_note(v___x_1083_);
v___x_1085_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1085_, 0, v_msg_1041_);
lean_ctor_set(v___x_1085_, 1, v___x_1084_);
if (v_isShared_1070_ == 0)
{
lean_ctor_set_tag(v___x_1069_, 0);
lean_ctor_set(v___x_1069_, 0, v___x_1085_);
v___x_1087_ = v___x_1069_;
goto v_reusejp_1086_;
}
else
{
lean_object* v_reuseFailAlloc_1088_; 
v_reuseFailAlloc_1088_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1088_, 0, v___x_1085_);
v___x_1087_ = v_reuseFailAlloc_1088_;
goto v_reusejp_1086_;
}
v_reusejp_1086_:
{
return v___x_1087_;
}
}
else
{
lean_object* v___x_1089_; lean_object* v___x_1090_; lean_object* v___x_1091_; lean_object* v___x_1092_; lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1100_; 
v___x_1089_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__7);
v___x_1090_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1090_, 0, v___x_1089_);
lean_ctor_set(v___x_1090_, 1, v_c_1058_);
v___x_1091_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__17);
v___x_1092_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1092_, 0, v___x_1090_);
lean_ctor_set(v___x_1092_, 1, v___x_1091_);
v___x_1093_ = l_Lean_MessageData_ofName(v_mod_1074_);
v___x_1094_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1094_, 0, v___x_1092_);
lean_ctor_set(v___x_1094_, 1, v___x_1093_);
v___x_1095_ = lean_obj_once(&l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19, &l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19_once, _init_l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___closed__19);
v___x_1096_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1096_, 0, v___x_1094_);
lean_ctor_set(v___x_1096_, 1, v___x_1095_);
v___x_1097_ = l_Lean_MessageData_note(v___x_1096_);
v___x_1098_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1098_, 0, v_msg_1041_);
lean_ctor_set(v___x_1098_, 1, v___x_1097_);
if (v_isShared_1070_ == 0)
{
lean_ctor_set_tag(v___x_1069_, 0);
lean_ctor_set(v___x_1069_, 0, v___x_1098_);
v___x_1100_ = v___x_1069_;
goto v_reusejp_1099_;
}
else
{
lean_object* v_reuseFailAlloc_1101_; 
v_reuseFailAlloc_1101_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1101_, 0, v___x_1098_);
v___x_1100_ = v_reuseFailAlloc_1101_;
goto v_reusejp_1099_;
}
v_reusejp_1099_:
{
return v___x_1100_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_1103_; 
lean_dec_ref(v_env_1046_);
lean_dec(v_declHint_1042_);
v___x_1103_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1103_, 0, v_msg_1041_);
return v___x_1103_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg___boxed(lean_object* v_msg_1104_, lean_object* v_declHint_1105_, lean_object* v___y_1106_, lean_object* v___y_1107_){
_start:
{
lean_object* v_res_1108_; 
v_res_1108_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg(v_msg_1104_, v_declHint_1105_, v___y_1106_);
lean_dec(v___y_1106_);
return v_res_1108_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27(lean_object* v_msg_1109_, lean_object* v_declHint_1110_, lean_object* v___y_1111_, lean_object* v___y_1112_, lean_object* v___y_1113_, lean_object* v___y_1114_){
_start:
{
lean_object* v___x_1116_; lean_object* v_a_1117_; lean_object* v___x_1119_; uint8_t v_isShared_1120_; uint8_t v_isSharedCheck_1126_; 
v___x_1116_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg(v_msg_1109_, v_declHint_1110_, v___y_1114_);
v_a_1117_ = lean_ctor_get(v___x_1116_, 0);
v_isSharedCheck_1126_ = !lean_is_exclusive(v___x_1116_);
if (v_isSharedCheck_1126_ == 0)
{
v___x_1119_ = v___x_1116_;
v_isShared_1120_ = v_isSharedCheck_1126_;
goto v_resetjp_1118_;
}
else
{
lean_inc(v_a_1117_);
lean_dec(v___x_1116_);
v___x_1119_ = lean_box(0);
v_isShared_1120_ = v_isSharedCheck_1126_;
goto v_resetjp_1118_;
}
v_resetjp_1118_:
{
lean_object* v___x_1121_; lean_object* v___x_1122_; lean_object* v___x_1124_; 
v___x_1121_ = l_Lean_unknownIdentifierMessageTag;
v___x_1122_ = lean_alloc_ctor(8, 2, 0);
lean_ctor_set(v___x_1122_, 0, v___x_1121_);
lean_ctor_set(v___x_1122_, 1, v_a_1117_);
if (v_isShared_1120_ == 0)
{
lean_ctor_set(v___x_1119_, 0, v___x_1122_);
v___x_1124_ = v___x_1119_;
goto v_reusejp_1123_;
}
else
{
lean_object* v_reuseFailAlloc_1125_; 
v_reuseFailAlloc_1125_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1125_, 0, v___x_1122_);
v___x_1124_ = v_reuseFailAlloc_1125_;
goto v_reusejp_1123_;
}
v_reusejp_1123_:
{
return v___x_1124_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27___boxed(lean_object* v_msg_1127_, lean_object* v_declHint_1128_, lean_object* v___y_1129_, lean_object* v___y_1130_, lean_object* v___y_1131_, lean_object* v___y_1132_, lean_object* v___y_1133_){
_start:
{
lean_object* v_res_1134_; 
v_res_1134_ = l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27(v_msg_1127_, v_declHint_1128_, v___y_1129_, v___y_1130_, v___y_1131_, v___y_1132_);
lean_dec(v___y_1132_);
lean_dec_ref(v___y_1131_);
lean_dec(v___y_1130_);
lean_dec_ref(v___y_1129_);
return v_res_1134_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(lean_object* v_msg_1135_, lean_object* v___y_1136_, lean_object* v___y_1137_, lean_object* v___y_1138_, lean_object* v___y_1139_){
_start:
{
lean_object* v_ref_1141_; lean_object* v___x_1142_; lean_object* v_a_1143_; lean_object* v___x_1145_; uint8_t v_isShared_1146_; uint8_t v_isSharedCheck_1151_; 
v_ref_1141_ = lean_ctor_get(v___y_1138_, 5);
v___x_1142_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(v_msg_1135_, v___y_1136_, v___y_1137_, v___y_1138_, v___y_1139_);
v_a_1143_ = lean_ctor_get(v___x_1142_, 0);
v_isSharedCheck_1151_ = !lean_is_exclusive(v___x_1142_);
if (v_isSharedCheck_1151_ == 0)
{
v___x_1145_ = v___x_1142_;
v_isShared_1146_ = v_isSharedCheck_1151_;
goto v_resetjp_1144_;
}
else
{
lean_inc(v_a_1143_);
lean_dec(v___x_1142_);
v___x_1145_ = lean_box(0);
v_isShared_1146_ = v_isSharedCheck_1151_;
goto v_resetjp_1144_;
}
v_resetjp_1144_:
{
lean_object* v___x_1147_; lean_object* v___x_1149_; 
lean_inc(v_ref_1141_);
v___x_1147_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1147_, 0, v_ref_1141_);
lean_ctor_set(v___x_1147_, 1, v_a_1143_);
if (v_isShared_1146_ == 0)
{
lean_ctor_set_tag(v___x_1145_, 1);
lean_ctor_set(v___x_1145_, 0, v___x_1147_);
v___x_1149_ = v___x_1145_;
goto v_reusejp_1148_;
}
else
{
lean_object* v_reuseFailAlloc_1150_; 
v_reuseFailAlloc_1150_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1150_, 0, v___x_1147_);
v___x_1149_ = v_reuseFailAlloc_1150_;
goto v_reusejp_1148_;
}
v_reusejp_1148_:
{
return v___x_1149_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg___boxed(lean_object* v_msg_1152_, lean_object* v___y_1153_, lean_object* v___y_1154_, lean_object* v___y_1155_, lean_object* v___y_1156_, lean_object* v___y_1157_){
_start:
{
lean_object* v_res_1158_; 
v_res_1158_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v_msg_1152_, v___y_1153_, v___y_1154_, v___y_1155_, v___y_1156_);
lean_dec(v___y_1156_);
lean_dec_ref(v___y_1155_);
lean_dec(v___y_1154_);
lean_dec_ref(v___y_1153_);
return v_res_1158_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg(lean_object* v_ref_1159_, lean_object* v_msg_1160_, lean_object* v___y_1161_, lean_object* v___y_1162_, lean_object* v___y_1163_, lean_object* v___y_1164_){
_start:
{
lean_object* v_fileName_1166_; lean_object* v_fileMap_1167_; lean_object* v_options_1168_; lean_object* v_currRecDepth_1169_; lean_object* v_maxRecDepth_1170_; lean_object* v_ref_1171_; lean_object* v_currNamespace_1172_; lean_object* v_openDecls_1173_; lean_object* v_initHeartbeats_1174_; lean_object* v_maxHeartbeats_1175_; lean_object* v_quotContext_1176_; lean_object* v_currMacroScope_1177_; uint8_t v_diag_1178_; lean_object* v_cancelTk_x3f_1179_; uint8_t v_suppressElabErrors_1180_; lean_object* v_inheritedTraceOptions_1181_; lean_object* v___x_1183_; uint8_t v_isShared_1184_; uint8_t v_isSharedCheck_1190_; 
v_fileName_1166_ = lean_ctor_get(v___y_1163_, 0);
v_fileMap_1167_ = lean_ctor_get(v___y_1163_, 1);
v_options_1168_ = lean_ctor_get(v___y_1163_, 2);
v_currRecDepth_1169_ = lean_ctor_get(v___y_1163_, 3);
v_maxRecDepth_1170_ = lean_ctor_get(v___y_1163_, 4);
v_ref_1171_ = lean_ctor_get(v___y_1163_, 5);
v_currNamespace_1172_ = lean_ctor_get(v___y_1163_, 6);
v_openDecls_1173_ = lean_ctor_get(v___y_1163_, 7);
v_initHeartbeats_1174_ = lean_ctor_get(v___y_1163_, 8);
v_maxHeartbeats_1175_ = lean_ctor_get(v___y_1163_, 9);
v_quotContext_1176_ = lean_ctor_get(v___y_1163_, 10);
v_currMacroScope_1177_ = lean_ctor_get(v___y_1163_, 11);
v_diag_1178_ = lean_ctor_get_uint8(v___y_1163_, sizeof(void*)*14);
v_cancelTk_x3f_1179_ = lean_ctor_get(v___y_1163_, 12);
v_suppressElabErrors_1180_ = lean_ctor_get_uint8(v___y_1163_, sizeof(void*)*14 + 1);
v_inheritedTraceOptions_1181_ = lean_ctor_get(v___y_1163_, 13);
v_isSharedCheck_1190_ = !lean_is_exclusive(v___y_1163_);
if (v_isSharedCheck_1190_ == 0)
{
v___x_1183_ = v___y_1163_;
v_isShared_1184_ = v_isSharedCheck_1190_;
goto v_resetjp_1182_;
}
else
{
lean_inc(v_inheritedTraceOptions_1181_);
lean_inc(v_cancelTk_x3f_1179_);
lean_inc(v_currMacroScope_1177_);
lean_inc(v_quotContext_1176_);
lean_inc(v_maxHeartbeats_1175_);
lean_inc(v_initHeartbeats_1174_);
lean_inc(v_openDecls_1173_);
lean_inc(v_currNamespace_1172_);
lean_inc(v_ref_1171_);
lean_inc(v_maxRecDepth_1170_);
lean_inc(v_currRecDepth_1169_);
lean_inc(v_options_1168_);
lean_inc(v_fileMap_1167_);
lean_inc(v_fileName_1166_);
lean_dec(v___y_1163_);
v___x_1183_ = lean_box(0);
v_isShared_1184_ = v_isSharedCheck_1190_;
goto v_resetjp_1182_;
}
v_resetjp_1182_:
{
lean_object* v_ref_1185_; lean_object* v___x_1187_; 
v_ref_1185_ = l_Lean_replaceRef(v_ref_1159_, v_ref_1171_);
lean_dec(v_ref_1171_);
if (v_isShared_1184_ == 0)
{
lean_ctor_set(v___x_1183_, 5, v_ref_1185_);
v___x_1187_ = v___x_1183_;
goto v_reusejp_1186_;
}
else
{
lean_object* v_reuseFailAlloc_1189_; 
v_reuseFailAlloc_1189_ = lean_alloc_ctor(0, 14, 2);
lean_ctor_set(v_reuseFailAlloc_1189_, 0, v_fileName_1166_);
lean_ctor_set(v_reuseFailAlloc_1189_, 1, v_fileMap_1167_);
lean_ctor_set(v_reuseFailAlloc_1189_, 2, v_options_1168_);
lean_ctor_set(v_reuseFailAlloc_1189_, 3, v_currRecDepth_1169_);
lean_ctor_set(v_reuseFailAlloc_1189_, 4, v_maxRecDepth_1170_);
lean_ctor_set(v_reuseFailAlloc_1189_, 5, v_ref_1185_);
lean_ctor_set(v_reuseFailAlloc_1189_, 6, v_currNamespace_1172_);
lean_ctor_set(v_reuseFailAlloc_1189_, 7, v_openDecls_1173_);
lean_ctor_set(v_reuseFailAlloc_1189_, 8, v_initHeartbeats_1174_);
lean_ctor_set(v_reuseFailAlloc_1189_, 9, v_maxHeartbeats_1175_);
lean_ctor_set(v_reuseFailAlloc_1189_, 10, v_quotContext_1176_);
lean_ctor_set(v_reuseFailAlloc_1189_, 11, v_currMacroScope_1177_);
lean_ctor_set(v_reuseFailAlloc_1189_, 12, v_cancelTk_x3f_1179_);
lean_ctor_set(v_reuseFailAlloc_1189_, 13, v_inheritedTraceOptions_1181_);
lean_ctor_set_uint8(v_reuseFailAlloc_1189_, sizeof(void*)*14, v_diag_1178_);
lean_ctor_set_uint8(v_reuseFailAlloc_1189_, sizeof(void*)*14 + 1, v_suppressElabErrors_1180_);
v___x_1187_ = v_reuseFailAlloc_1189_;
goto v_reusejp_1186_;
}
v_reusejp_1186_:
{
lean_object* v___x_1188_; 
v___x_1188_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v_msg_1160_, v___y_1161_, v___y_1162_, v___x_1187_, v___y_1164_);
lean_dec_ref(v___x_1187_);
return v___x_1188_;
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg___boxed(lean_object* v_ref_1191_, lean_object* v_msg_1192_, lean_object* v___y_1193_, lean_object* v___y_1194_, lean_object* v___y_1195_, lean_object* v___y_1196_, lean_object* v___y_1197_){
_start:
{
lean_object* v_res_1198_; 
v_res_1198_ = l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg(v_ref_1191_, v_msg_1192_, v___y_1193_, v___y_1194_, v___y_1195_, v___y_1196_);
lean_dec(v___y_1196_);
lean_dec(v___y_1194_);
lean_dec_ref(v___y_1193_);
lean_dec(v_ref_1191_);
return v_res_1198_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg(lean_object* v_ref_1199_, lean_object* v_msg_1200_, lean_object* v_declHint_1201_, lean_object* v___y_1202_, lean_object* v___y_1203_, lean_object* v___y_1204_, lean_object* v___y_1205_){
_start:
{
lean_object* v___x_1207_; lean_object* v_a_1208_; lean_object* v___x_1209_; 
v___x_1207_ = l_Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27(v_msg_1200_, v_declHint_1201_, v___y_1202_, v___y_1203_, v___y_1204_, v___y_1205_);
v_a_1208_ = lean_ctor_get(v___x_1207_, 0);
lean_inc(v_a_1208_);
lean_dec_ref(v___x_1207_);
v___x_1209_ = l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg(v_ref_1199_, v_a_1208_, v___y_1202_, v___y_1203_, v___y_1204_, v___y_1205_);
return v___x_1209_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg___boxed(lean_object* v_ref_1210_, lean_object* v_msg_1211_, lean_object* v_declHint_1212_, lean_object* v___y_1213_, lean_object* v___y_1214_, lean_object* v___y_1215_, lean_object* v___y_1216_, lean_object* v___y_1217_){
_start:
{
lean_object* v_res_1218_; 
v_res_1218_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg(v_ref_1210_, v_msg_1211_, v_declHint_1212_, v___y_1213_, v___y_1214_, v___y_1215_, v___y_1216_);
lean_dec(v___y_1216_);
lean_dec(v___y_1214_);
lean_dec_ref(v___y_1213_);
lean_dec(v_ref_1210_);
return v_res_1218_;
}
}
static lean_object* _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1(void){
_start:
{
lean_object* v___x_1220_; lean_object* v___x_1221_; 
v___x_1220_ = ((lean_object*)(l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__0));
v___x_1221_ = l_Lean_stringToMessageData(v___x_1220_);
return v___x_1221_;
}
}
static lean_object* _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3(void){
_start:
{
lean_object* v___x_1223_; lean_object* v___x_1224_; 
v___x_1223_ = ((lean_object*)(l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__2));
v___x_1224_ = l_Lean_stringToMessageData(v___x_1223_);
return v___x_1224_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg(lean_object* v_ref_1225_, lean_object* v_constName_1226_, lean_object* v___y_1227_, lean_object* v___y_1228_, lean_object* v___y_1229_, lean_object* v___y_1230_){
_start:
{
lean_object* v___x_1232_; uint8_t v___x_1233_; lean_object* v___x_1234_; lean_object* v___x_1235_; lean_object* v___x_1236_; lean_object* v___x_1237_; lean_object* v___x_1238_; 
v___x_1232_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__1);
v___x_1233_ = 0;
lean_inc(v_constName_1226_);
v___x_1234_ = l_Lean_MessageData_ofConstName(v_constName_1226_, v___x_1233_);
v___x_1235_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1235_, 0, v___x_1232_);
lean_ctor_set(v___x_1235_, 1, v___x_1234_);
v___x_1236_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3);
v___x_1237_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1237_, 0, v___x_1235_);
lean_ctor_set(v___x_1237_, 1, v___x_1236_);
v___x_1238_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg(v_ref_1225_, v___x_1237_, v_constName_1226_, v___y_1227_, v___y_1228_, v___y_1229_, v___y_1230_);
return v___x_1238_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___boxed(lean_object* v_ref_1239_, lean_object* v_constName_1240_, lean_object* v___y_1241_, lean_object* v___y_1242_, lean_object* v___y_1243_, lean_object* v___y_1244_, lean_object* v___y_1245_){
_start:
{
lean_object* v_res_1246_; 
v_res_1246_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg(v_ref_1239_, v_constName_1240_, v___y_1241_, v___y_1242_, v___y_1243_, v___y_1244_);
lean_dec(v___y_1244_);
lean_dec(v___y_1242_);
lean_dec_ref(v___y_1241_);
lean_dec(v_ref_1239_);
return v_res_1246_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg(lean_object* v_constName_1247_, lean_object* v___y_1248_, lean_object* v___y_1249_, lean_object* v___y_1250_, lean_object* v___y_1251_){
_start:
{
lean_object* v_ref_1253_; lean_object* v___x_1254_; 
v_ref_1253_ = lean_ctor_get(v___y_1250_, 5);
lean_inc(v_ref_1253_);
v___x_1254_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg(v_ref_1253_, v_constName_1247_, v___y_1248_, v___y_1249_, v___y_1250_, v___y_1251_);
lean_dec(v_ref_1253_);
return v___x_1254_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg___boxed(lean_object* v_constName_1255_, lean_object* v___y_1256_, lean_object* v___y_1257_, lean_object* v___y_1258_, lean_object* v___y_1259_, lean_object* v___y_1260_){
_start:
{
lean_object* v_res_1261_; 
v_res_1261_ = l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg(v_constName_1255_, v___y_1256_, v___y_1257_, v___y_1258_, v___y_1259_);
lean_dec(v___y_1259_);
lean_dec(v___y_1257_);
lean_dec_ref(v___y_1256_);
return v_res_1261_;
}
}
LEAN_EXPORT lean_object* l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(lean_object* v_constName_1262_, lean_object* v___y_1263_, lean_object* v___y_1264_, lean_object* v___y_1265_, lean_object* v___y_1266_){
_start:
{
lean_object* v___x_1268_; lean_object* v_env_1269_; uint8_t v___x_1270_; lean_object* v___x_1271_; 
v___x_1268_ = lean_st_ref_get(v___y_1266_);
v_env_1269_ = lean_ctor_get(v___x_1268_, 0);
lean_inc_ref(v_env_1269_);
lean_dec(v___x_1268_);
v___x_1270_ = 0;
lean_inc(v_constName_1262_);
v___x_1271_ = l_Lean_Environment_find_x3f(v_env_1269_, v_constName_1262_, v___x_1270_);
if (lean_obj_tag(v___x_1271_) == 0)
{
lean_object* v___x_1272_; 
v___x_1272_ = l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg(v_constName_1262_, v___y_1263_, v___y_1264_, v___y_1265_, v___y_1266_);
return v___x_1272_;
}
else
{
lean_object* v_val_1273_; lean_object* v___x_1275_; uint8_t v_isShared_1276_; uint8_t v_isSharedCheck_1280_; 
lean_dec_ref(v___y_1265_);
lean_dec(v_constName_1262_);
v_val_1273_ = lean_ctor_get(v___x_1271_, 0);
v_isSharedCheck_1280_ = !lean_is_exclusive(v___x_1271_);
if (v_isSharedCheck_1280_ == 0)
{
v___x_1275_ = v___x_1271_;
v_isShared_1276_ = v_isSharedCheck_1280_;
goto v_resetjp_1274_;
}
else
{
lean_inc(v_val_1273_);
lean_dec(v___x_1271_);
v___x_1275_ = lean_box(0);
v_isShared_1276_ = v_isSharedCheck_1280_;
goto v_resetjp_1274_;
}
v_resetjp_1274_:
{
lean_object* v___x_1278_; 
if (v_isShared_1276_ == 0)
{
lean_ctor_set_tag(v___x_1275_, 0);
v___x_1278_ = v___x_1275_;
goto v_reusejp_1277_;
}
else
{
lean_object* v_reuseFailAlloc_1279_; 
v_reuseFailAlloc_1279_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1279_, 0, v_val_1273_);
v___x_1278_ = v_reuseFailAlloc_1279_;
goto v_reusejp_1277_;
}
v_reusejp_1277_:
{
return v___x_1278_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5___boxed(lean_object* v_constName_1281_, lean_object* v___y_1282_, lean_object* v___y_1283_, lean_object* v___y_1284_, lean_object* v___y_1285_, lean_object* v___y_1286_){
_start:
{
lean_object* v_res_1287_; 
v_res_1287_ = l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(v_constName_1281_, v___y_1282_, v___y_1283_, v___y_1284_, v___y_1285_);
lean_dec(v___y_1285_);
lean_dec(v___y_1283_);
lean_dec_ref(v___y_1282_);
return v_res_1287_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(size_t v_sz_1288_, size_t v_i_1289_, lean_object* v_bs_1290_, lean_object* v___y_1291_, lean_object* v___y_1292_, lean_object* v___y_1293_, lean_object* v___y_1294_){
_start:
{
uint8_t v___x_1296_; 
v___x_1296_ = lean_usize_dec_lt(v_i_1289_, v_sz_1288_);
if (v___x_1296_ == 0)
{
lean_object* v___x_1297_; 
v___x_1297_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1297_, 0, v_bs_1290_);
return v___x_1297_;
}
else
{
lean_object* v_v_1298_; lean_object* v___x_1299_; 
v_v_1298_ = lean_array_uget_borrowed(v_bs_1290_, v_i_1289_);
lean_inc(v_v_1298_);
v___x_1299_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_v_1298_, v___y_1292_);
if (lean_obj_tag(v___x_1299_) == 0)
{
lean_object* v_a_1300_; lean_object* v___x_1301_; lean_object* v_bs_x27_1302_; size_t v___x_1303_; size_t v___x_1304_; lean_object* v___x_1305_; 
v_a_1300_ = lean_ctor_get(v___x_1299_, 0);
lean_inc(v_a_1300_);
lean_dec_ref(v___x_1299_);
v___x_1301_ = lean_unsigned_to_nat(0u);
v_bs_x27_1302_ = lean_array_uset(v_bs_1290_, v_i_1289_, v___x_1301_);
v___x_1303_ = ((size_t)1ULL);
v___x_1304_ = lean_usize_add(v_i_1289_, v___x_1303_);
v___x_1305_ = lean_array_uset(v_bs_x27_1302_, v_i_1289_, v_a_1300_);
v_i_1289_ = v___x_1304_;
v_bs_1290_ = v___x_1305_;
goto _start;
}
else
{
lean_object* v_a_1307_; lean_object* v___x_1309_; uint8_t v_isShared_1310_; uint8_t v_isSharedCheck_1314_; 
lean_dec_ref(v_bs_1290_);
v_a_1307_ = lean_ctor_get(v___x_1299_, 0);
v_isSharedCheck_1314_ = !lean_is_exclusive(v___x_1299_);
if (v_isSharedCheck_1314_ == 0)
{
v___x_1309_ = v___x_1299_;
v_isShared_1310_ = v_isSharedCheck_1314_;
goto v_resetjp_1308_;
}
else
{
lean_inc(v_a_1307_);
lean_dec(v___x_1299_);
v___x_1309_ = lean_box(0);
v_isShared_1310_ = v_isSharedCheck_1314_;
goto v_resetjp_1308_;
}
v_resetjp_1308_:
{
lean_object* v___x_1312_; 
if (v_isShared_1310_ == 0)
{
v___x_1312_ = v___x_1309_;
goto v_reusejp_1311_;
}
else
{
lean_object* v_reuseFailAlloc_1313_; 
v_reuseFailAlloc_1313_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1313_, 0, v_a_1307_);
v___x_1312_ = v_reuseFailAlloc_1313_;
goto v_reusejp_1311_;
}
v_reusejp_1311_:
{
return v___x_1312_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7___boxed(lean_object* v_sz_1315_, lean_object* v_i_1316_, lean_object* v_bs_1317_, lean_object* v___y_1318_, lean_object* v___y_1319_, lean_object* v___y_1320_, lean_object* v___y_1321_, lean_object* v___y_1322_){
_start:
{
size_t v_sz_boxed_1323_; size_t v_i_boxed_1324_; lean_object* v_res_1325_; 
v_sz_boxed_1323_ = lean_unbox_usize(v_sz_1315_);
lean_dec(v_sz_1315_);
v_i_boxed_1324_ = lean_unbox_usize(v_i_1316_);
lean_dec(v_i_1316_);
v_res_1325_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(v_sz_boxed_1323_, v_i_boxed_1324_, v_bs_1317_, v___y_1318_, v___y_1319_, v___y_1320_, v___y_1321_);
lean_dec(v___y_1321_);
lean_dec_ref(v___y_1320_);
lean_dec(v___y_1319_);
lean_dec_ref(v___y_1318_);
return v_res_1325_;
}
}
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(lean_object* v_cls_1329_, lean_object* v_msg_1330_, lean_object* v___y_1331_, lean_object* v___y_1332_, lean_object* v___y_1333_, lean_object* v___y_1334_){
_start:
{
lean_object* v_ref_1336_; lean_object* v___x_1337_; lean_object* v_a_1338_; lean_object* v___x_1340_; uint8_t v_isShared_1341_; uint8_t v_isSharedCheck_1382_; 
v_ref_1336_ = lean_ctor_get(v___y_1333_, 5);
v___x_1337_ = l_Lean_addMessageContextFull___at___00Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4_spec__4(v_msg_1330_, v___y_1331_, v___y_1332_, v___y_1333_, v___y_1334_);
v_a_1338_ = lean_ctor_get(v___x_1337_, 0);
v_isSharedCheck_1382_ = !lean_is_exclusive(v___x_1337_);
if (v_isSharedCheck_1382_ == 0)
{
v___x_1340_ = v___x_1337_;
v_isShared_1341_ = v_isSharedCheck_1382_;
goto v_resetjp_1339_;
}
else
{
lean_inc(v_a_1338_);
lean_dec(v___x_1337_);
v___x_1340_ = lean_box(0);
v_isShared_1341_ = v_isSharedCheck_1382_;
goto v_resetjp_1339_;
}
v_resetjp_1339_:
{
lean_object* v___x_1342_; lean_object* v_traceState_1343_; lean_object* v_env_1344_; lean_object* v_nextMacroScope_1345_; lean_object* v_ngen_1346_; lean_object* v_auxDeclNGen_1347_; lean_object* v_cache_1348_; lean_object* v_messages_1349_; lean_object* v_infoState_1350_; lean_object* v_snapshotTasks_1351_; lean_object* v___x_1353_; uint8_t v_isShared_1354_; uint8_t v_isSharedCheck_1381_; 
v___x_1342_ = lean_st_ref_take(v___y_1334_);
v_traceState_1343_ = lean_ctor_get(v___x_1342_, 4);
v_env_1344_ = lean_ctor_get(v___x_1342_, 0);
v_nextMacroScope_1345_ = lean_ctor_get(v___x_1342_, 1);
v_ngen_1346_ = lean_ctor_get(v___x_1342_, 2);
v_auxDeclNGen_1347_ = lean_ctor_get(v___x_1342_, 3);
v_cache_1348_ = lean_ctor_get(v___x_1342_, 5);
v_messages_1349_ = lean_ctor_get(v___x_1342_, 6);
v_infoState_1350_ = lean_ctor_get(v___x_1342_, 7);
v_snapshotTasks_1351_ = lean_ctor_get(v___x_1342_, 8);
v_isSharedCheck_1381_ = !lean_is_exclusive(v___x_1342_);
if (v_isSharedCheck_1381_ == 0)
{
v___x_1353_ = v___x_1342_;
v_isShared_1354_ = v_isSharedCheck_1381_;
goto v_resetjp_1352_;
}
else
{
lean_inc(v_snapshotTasks_1351_);
lean_inc(v_infoState_1350_);
lean_inc(v_messages_1349_);
lean_inc(v_cache_1348_);
lean_inc(v_traceState_1343_);
lean_inc(v_auxDeclNGen_1347_);
lean_inc(v_ngen_1346_);
lean_inc(v_nextMacroScope_1345_);
lean_inc(v_env_1344_);
lean_dec(v___x_1342_);
v___x_1353_ = lean_box(0);
v_isShared_1354_ = v_isSharedCheck_1381_;
goto v_resetjp_1352_;
}
v_resetjp_1352_:
{
uint64_t v_tid_1355_; lean_object* v_traces_1356_; lean_object* v___x_1358_; uint8_t v_isShared_1359_; uint8_t v_isSharedCheck_1380_; 
v_tid_1355_ = lean_ctor_get_uint64(v_traceState_1343_, sizeof(void*)*1);
v_traces_1356_ = lean_ctor_get(v_traceState_1343_, 0);
v_isSharedCheck_1380_ = !lean_is_exclusive(v_traceState_1343_);
if (v_isSharedCheck_1380_ == 0)
{
v___x_1358_ = v_traceState_1343_;
v_isShared_1359_ = v_isSharedCheck_1380_;
goto v_resetjp_1357_;
}
else
{
lean_inc(v_traces_1356_);
lean_dec(v_traceState_1343_);
v___x_1358_ = lean_box(0);
v_isShared_1359_ = v_isSharedCheck_1380_;
goto v_resetjp_1357_;
}
v_resetjp_1357_:
{
lean_object* v___x_1360_; double v___x_1361_; uint8_t v___x_1362_; lean_object* v___x_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; lean_object* v___x_1366_; lean_object* v___x_1367_; lean_object* v___x_1368_; lean_object* v___x_1370_; 
v___x_1360_ = lean_box(0);
v___x_1361_ = lean_float_once(&l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2, &l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2_once, _init_l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18___closed__2);
v___x_1362_ = 0;
v___x_1363_ = ((lean_object*)(l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__0));
v___x_1364_ = lean_alloc_ctor(0, 3, 17);
lean_ctor_set(v___x_1364_, 0, v_cls_1329_);
lean_ctor_set(v___x_1364_, 1, v___x_1360_);
lean_ctor_set(v___x_1364_, 2, v___x_1363_);
lean_ctor_set_float(v___x_1364_, sizeof(void*)*3, v___x_1361_);
lean_ctor_set_float(v___x_1364_, sizeof(void*)*3 + 8, v___x_1361_);
lean_ctor_set_uint8(v___x_1364_, sizeof(void*)*3 + 16, v___x_1362_);
v___x_1365_ = ((lean_object*)(l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__1));
v___x_1366_ = lean_alloc_ctor(9, 3, 0);
lean_ctor_set(v___x_1366_, 0, v___x_1364_);
lean_ctor_set(v___x_1366_, 1, v_a_1338_);
lean_ctor_set(v___x_1366_, 2, v___x_1365_);
lean_inc(v_ref_1336_);
v___x_1367_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1367_, 0, v_ref_1336_);
lean_ctor_set(v___x_1367_, 1, v___x_1366_);
v___x_1368_ = l_Lean_PersistentArray_push___redArg(v_traces_1356_, v___x_1367_);
if (v_isShared_1359_ == 0)
{
lean_ctor_set(v___x_1358_, 0, v___x_1368_);
v___x_1370_ = v___x_1358_;
goto v_reusejp_1369_;
}
else
{
lean_object* v_reuseFailAlloc_1379_; 
v_reuseFailAlloc_1379_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v_reuseFailAlloc_1379_, 0, v___x_1368_);
lean_ctor_set_uint64(v_reuseFailAlloc_1379_, sizeof(void*)*1, v_tid_1355_);
v___x_1370_ = v_reuseFailAlloc_1379_;
goto v_reusejp_1369_;
}
v_reusejp_1369_:
{
lean_object* v___x_1372_; 
if (v_isShared_1354_ == 0)
{
lean_ctor_set(v___x_1353_, 4, v___x_1370_);
v___x_1372_ = v___x_1353_;
goto v_reusejp_1371_;
}
else
{
lean_object* v_reuseFailAlloc_1378_; 
v_reuseFailAlloc_1378_ = lean_alloc_ctor(0, 9, 0);
lean_ctor_set(v_reuseFailAlloc_1378_, 0, v_env_1344_);
lean_ctor_set(v_reuseFailAlloc_1378_, 1, v_nextMacroScope_1345_);
lean_ctor_set(v_reuseFailAlloc_1378_, 2, v_ngen_1346_);
lean_ctor_set(v_reuseFailAlloc_1378_, 3, v_auxDeclNGen_1347_);
lean_ctor_set(v_reuseFailAlloc_1378_, 4, v___x_1370_);
lean_ctor_set(v_reuseFailAlloc_1378_, 5, v_cache_1348_);
lean_ctor_set(v_reuseFailAlloc_1378_, 6, v_messages_1349_);
lean_ctor_set(v_reuseFailAlloc_1378_, 7, v_infoState_1350_);
lean_ctor_set(v_reuseFailAlloc_1378_, 8, v_snapshotTasks_1351_);
v___x_1372_ = v_reuseFailAlloc_1378_;
goto v_reusejp_1371_;
}
v_reusejp_1371_:
{
lean_object* v___x_1373_; lean_object* v___x_1374_; lean_object* v___x_1376_; 
v___x_1373_ = lean_st_ref_set(v___y_1334_, v___x_1372_);
v___x_1374_ = lean_box(0);
if (v_isShared_1341_ == 0)
{
lean_ctor_set(v___x_1340_, 0, v___x_1374_);
v___x_1376_ = v___x_1340_;
goto v_reusejp_1375_;
}
else
{
lean_object* v_reuseFailAlloc_1377_; 
v_reuseFailAlloc_1377_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1377_, 0, v___x_1374_);
v___x_1376_ = v_reuseFailAlloc_1377_;
goto v_reusejp_1375_;
}
v_reusejp_1375_:
{
return v___x_1376_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___boxed(lean_object* v_cls_1383_, lean_object* v_msg_1384_, lean_object* v___y_1385_, lean_object* v___y_1386_, lean_object* v___y_1387_, lean_object* v___y_1388_, lean_object* v___y_1389_){
_start:
{
lean_object* v_res_1390_; 
v_res_1390_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_1383_, v_msg_1384_, v___y_1385_, v___y_1386_, v___y_1387_, v___y_1388_);
lean_dec(v___y_1388_);
lean_dec_ref(v___y_1387_);
lean_dec(v___y_1386_);
lean_dec_ref(v___y_1385_);
return v_res_1390_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00Lean_Meta_normalizeInstance_spec__11(lean_object* v_a_1391_, lean_object* v_a_1392_){
_start:
{
if (lean_obj_tag(v_a_1391_) == 0)
{
lean_object* v___x_1393_; 
v___x_1393_ = l_List_reverse___redArg(v_a_1392_);
return v___x_1393_;
}
else
{
lean_object* v_head_1394_; lean_object* v_tail_1395_; lean_object* v___x_1397_; uint8_t v_isShared_1398_; uint8_t v_isSharedCheck_1404_; 
v_head_1394_ = lean_ctor_get(v_a_1391_, 0);
v_tail_1395_ = lean_ctor_get(v_a_1391_, 1);
v_isSharedCheck_1404_ = !lean_is_exclusive(v_a_1391_);
if (v_isSharedCheck_1404_ == 0)
{
v___x_1397_ = v_a_1391_;
v_isShared_1398_ = v_isSharedCheck_1404_;
goto v_resetjp_1396_;
}
else
{
lean_inc(v_tail_1395_);
lean_inc(v_head_1394_);
lean_dec(v_a_1391_);
v___x_1397_ = lean_box(0);
v_isShared_1398_ = v_isSharedCheck_1404_;
goto v_resetjp_1396_;
}
v_resetjp_1396_:
{
lean_object* v___x_1399_; lean_object* v___x_1401_; 
v___x_1399_ = l_Lean_MessageData_ofExpr(v_head_1394_);
if (v_isShared_1398_ == 0)
{
lean_ctor_set(v___x_1397_, 1, v_a_1392_);
lean_ctor_set(v___x_1397_, 0, v___x_1399_);
v___x_1401_ = v___x_1397_;
goto v_reusejp_1400_;
}
else
{
lean_object* v_reuseFailAlloc_1403_; 
v_reuseFailAlloc_1403_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1403_, 0, v___x_1399_);
lean_ctor_set(v_reuseFailAlloc_1403_, 1, v_a_1392_);
v___x_1401_ = v_reuseFailAlloc_1403_;
goto v_reusejp_1400_;
}
v_reusejp_1400_:
{
v_a_1391_ = v_tail_1395_;
v_a_1392_ = v___x_1401_;
goto _start;
}
}
}
}
}
static lean_object* _init_l_Lean_Meta_normalizeInstance___lam__1___closed__0(void){
_start:
{
lean_object* v___x_1405_; lean_object* v_dummy_1406_; 
v___x_1405_ = lean_box(0);
v_dummy_1406_ = l_Lean_Expr_sort___override(v___x_1405_);
return v_dummy_1406_;
}
}
static lean_object* _init_l_Lean_Meta_normalizeInstance___lam__1___closed__2(void){
_start:
{
lean_object* v___x_1408_; lean_object* v___x_1409_; 
v___x_1408_ = ((lean_object*)(l_Lean_Meta_normalizeInstance___lam__1___closed__1));
v___x_1409_ = l_Lean_stringToMessageData(v___x_1408_);
return v___x_1409_;
}
}
static lean_object* _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1(void){
_start:
{
lean_object* v___x_1414_; lean_object* v___x_1415_; 
v___x_1414_ = ((lean_object*)(l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__0));
v___x_1415_ = l_Lean_stringToMessageData(v___x_1414_);
return v___x_1415_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg(lean_object* v_upperBound_1416_, lean_object* v_fst_1417_, lean_object* v_args_1418_, uint8_t v___x_1419_, uint8_t v_compile_1420_, lean_object* v_a_1421_, lean_object* v_b_1422_, lean_object* v___y_1423_, lean_object* v___y_1424_, lean_object* v___y_1425_, lean_object* v___y_1426_){
_start:
{
lean_object* v_a_1429_; uint8_t v___x_1433_; 
v___x_1433_ = lean_nat_dec_lt(v_a_1421_, v_upperBound_1416_);
if (v___x_1433_ == 0)
{
lean_object* v___x_1434_; 
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v___x_1434_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1434_, 0, v_b_1422_);
return v___x_1434_;
}
else
{
lean_object* v___x_1435_; lean_object* v___x_1436_; lean_object* v___x_1437_; 
v___x_1435_ = lean_array_fget_borrowed(v_fst_1417_, v_a_1421_);
v___x_1436_ = l_Lean_Expr_mvarId_x21(v___x_1435_);
lean_inc(v___x_1436_);
v___x_1437_ = l_Lean_MVarId_getDecl(v___x_1436_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1437_) == 0)
{
lean_object* v_a_1438_; lean_object* v_type_1439_; lean_object* v___x_1440_; 
v_a_1438_ = lean_ctor_get(v___x_1437_, 0);
lean_inc(v_a_1438_);
lean_dec_ref(v___x_1437_);
v_type_1439_ = lean_ctor_get(v_a_1438_, 2);
lean_inc_ref(v_type_1439_);
lean_dec(v_a_1438_);
v___x_1440_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_type_1439_, v___y_1424_);
if (lean_obj_tag(v___x_1440_) == 0)
{
lean_object* v_a_1441_; lean_object* v___x_1442_; 
v_a_1441_ = lean_ctor_get(v___x_1440_, 0);
lean_inc(v_a_1441_);
lean_dec_ref(v___x_1440_);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v_a_1441_);
v___x_1442_ = l_Lean_Meta_isProp(v_a_1441_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1442_) == 0)
{
lean_object* v_a_1443_; lean_object* v___x_1444_; lean_object* v___x_1445_; uint8_t v___x_1446_; 
v_a_1443_ = lean_ctor_get(v___x_1442_, 0);
lean_inc(v_a_1443_);
lean_dec_ref(v___x_1442_);
v___x_1444_ = lean_box(0);
v___x_1445_ = lean_array_fget_borrowed(v_args_1418_, v_a_1421_);
v___x_1446_ = lean_unbox(v_a_1443_);
lean_dec(v_a_1443_);
if (v___x_1446_ == 0)
{
lean_object* v___x_1447_; 
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v_a_1441_);
v___x_1447_ = l_Lean_Meta_isClass_x3f(v_a_1441_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1447_) == 0)
{
lean_object* v_a_1448_; 
v_a_1448_ = lean_ctor_get(v___x_1447_, 0);
lean_inc(v_a_1448_);
lean_dec_ref(v___x_1447_);
if (lean_obj_tag(v_a_1448_) == 0)
{
lean_object* v_options_1449_; lean_object* v___x_1450_; uint8_t v___x_1451_; 
v_options_1449_ = lean_ctor_get(v___y_1425_, 2);
v___x_1450_ = l_Lean_Meta_instance_normalForm_wrapFields_data;
v___x_1451_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1449_, v___x_1450_);
if (v___x_1451_ == 0)
{
lean_object* v___x_1452_; 
lean_dec(v_a_1441_);
lean_inc(v___x_1445_);
v___x_1452_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v___x_1445_, v___y_1424_);
if (lean_obj_tag(v___x_1452_) == 0)
{
lean_dec_ref(v___x_1452_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1452_;
}
}
else
{
lean_object* v___x_1453_; 
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v___x_1445_);
v___x_1453_ = lean_infer_type(v___x_1445_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1453_) == 0)
{
lean_object* v_a_1454_; lean_object* v___x_1455_; 
v_a_1454_ = lean_ctor_get(v___x_1453_, 0);
lean_inc(v_a_1454_);
lean_dec_ref(v___x_1453_);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v_a_1441_);
v___x_1455_ = l_Lean_Meta_isExprDefEq(v_a_1441_, v_a_1454_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1455_) == 0)
{
lean_object* v_a_1456_; uint8_t v___x_1457_; 
v_a_1456_ = lean_ctor_get(v___x_1455_, 0);
lean_inc(v_a_1456_);
lean_dec_ref(v___x_1455_);
v___x_1457_ = lean_unbox(v_a_1456_);
lean_dec(v_a_1456_);
if (v___x_1457_ == 0)
{
lean_object* v___x_1458_; lean_object* v___x_1459_; 
v___x_1458_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_1459_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_1458_, v___y_1426_);
if (lean_obj_tag(v___x_1459_) == 0)
{
lean_object* v_a_1460_; lean_object* v___x_1461_; 
v_a_1460_ = lean_ctor_get(v___x_1459_, 0);
lean_inc(v_a_1460_);
lean_dec_ref(v___x_1459_);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v___x_1445_);
lean_inc(v_a_1460_);
v___x_1461_ = l_Lean_Meta_mkAuxDefinition(v_a_1460_, v_a_1441_, v___x_1445_, v___x_1419_, v_compile_1420_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1461_) == 0)
{
lean_object* v_a_1462_; lean_object* v___x_1463_; 
v_a_1462_ = lean_ctor_get(v___x_1461_, 0);
lean_inc(v_a_1462_);
lean_dec_ref(v___x_1461_);
v___x_1463_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v_a_1462_, v___y_1424_);
if (lean_obj_tag(v___x_1463_) == 0)
{
lean_object* v___x_1464_; 
lean_dec_ref(v___x_1463_);
lean_inc_ref(v___y_1425_);
v___x_1464_ = l_Lean_enableRealizationsForConst(v_a_1460_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1464_) == 0)
{
lean_dec_ref(v___x_1464_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1464_;
}
}
else
{
lean_dec(v_a_1460_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1463_;
}
}
else
{
lean_object* v_a_1465_; lean_object* v___x_1467_; uint8_t v_isShared_1468_; uint8_t v_isSharedCheck_1472_; 
lean_dec(v_a_1460_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1465_ = lean_ctor_get(v___x_1461_, 0);
v_isSharedCheck_1472_ = !lean_is_exclusive(v___x_1461_);
if (v_isSharedCheck_1472_ == 0)
{
v___x_1467_ = v___x_1461_;
v_isShared_1468_ = v_isSharedCheck_1472_;
goto v_resetjp_1466_;
}
else
{
lean_inc(v_a_1465_);
lean_dec(v___x_1461_);
v___x_1467_ = lean_box(0);
v_isShared_1468_ = v_isSharedCheck_1472_;
goto v_resetjp_1466_;
}
v_resetjp_1466_:
{
lean_object* v___x_1470_; 
if (v_isShared_1468_ == 0)
{
v___x_1470_ = v___x_1467_;
goto v_reusejp_1469_;
}
else
{
lean_object* v_reuseFailAlloc_1471_; 
v_reuseFailAlloc_1471_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1471_, 0, v_a_1465_);
v___x_1470_ = v_reuseFailAlloc_1471_;
goto v_reusejp_1469_;
}
v_reusejp_1469_:
{
return v___x_1470_;
}
}
}
}
else
{
lean_object* v_a_1473_; lean_object* v___x_1475_; uint8_t v_isShared_1476_; uint8_t v_isSharedCheck_1480_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1473_ = lean_ctor_get(v___x_1459_, 0);
v_isSharedCheck_1480_ = !lean_is_exclusive(v___x_1459_);
if (v_isSharedCheck_1480_ == 0)
{
v___x_1475_ = v___x_1459_;
v_isShared_1476_ = v_isSharedCheck_1480_;
goto v_resetjp_1474_;
}
else
{
lean_inc(v_a_1473_);
lean_dec(v___x_1459_);
v___x_1475_ = lean_box(0);
v_isShared_1476_ = v_isSharedCheck_1480_;
goto v_resetjp_1474_;
}
v_resetjp_1474_:
{
lean_object* v___x_1478_; 
if (v_isShared_1476_ == 0)
{
v___x_1478_ = v___x_1475_;
goto v_reusejp_1477_;
}
else
{
lean_object* v_reuseFailAlloc_1479_; 
v_reuseFailAlloc_1479_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1479_, 0, v_a_1473_);
v___x_1478_ = v_reuseFailAlloc_1479_;
goto v_reusejp_1477_;
}
v_reusejp_1477_:
{
return v___x_1478_;
}
}
}
}
else
{
lean_object* v___x_1481_; 
lean_dec(v_a_1441_);
lean_inc(v___x_1445_);
v___x_1481_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v___x_1445_, v___y_1424_);
if (lean_obj_tag(v___x_1481_) == 0)
{
lean_dec_ref(v___x_1481_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1481_;
}
}
}
else
{
lean_object* v_a_1482_; lean_object* v___x_1484_; uint8_t v_isShared_1485_; uint8_t v_isSharedCheck_1489_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1482_ = lean_ctor_get(v___x_1455_, 0);
v_isSharedCheck_1489_ = !lean_is_exclusive(v___x_1455_);
if (v_isSharedCheck_1489_ == 0)
{
v___x_1484_ = v___x_1455_;
v_isShared_1485_ = v_isSharedCheck_1489_;
goto v_resetjp_1483_;
}
else
{
lean_inc(v_a_1482_);
lean_dec(v___x_1455_);
v___x_1484_ = lean_box(0);
v_isShared_1485_ = v_isSharedCheck_1489_;
goto v_resetjp_1483_;
}
v_resetjp_1483_:
{
lean_object* v___x_1487_; 
if (v_isShared_1485_ == 0)
{
v___x_1487_ = v___x_1484_;
goto v_reusejp_1486_;
}
else
{
lean_object* v_reuseFailAlloc_1488_; 
v_reuseFailAlloc_1488_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1488_, 0, v_a_1482_);
v___x_1487_ = v_reuseFailAlloc_1488_;
goto v_reusejp_1486_;
}
v_reusejp_1486_:
{
return v___x_1487_;
}
}
}
}
else
{
lean_object* v_a_1490_; lean_object* v___x_1492_; uint8_t v_isShared_1493_; uint8_t v_isSharedCheck_1497_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1490_ = lean_ctor_get(v___x_1453_, 0);
v_isSharedCheck_1497_ = !lean_is_exclusive(v___x_1453_);
if (v_isSharedCheck_1497_ == 0)
{
v___x_1492_ = v___x_1453_;
v_isShared_1493_ = v_isSharedCheck_1497_;
goto v_resetjp_1491_;
}
else
{
lean_inc(v_a_1490_);
lean_dec(v___x_1453_);
v___x_1492_ = lean_box(0);
v_isShared_1493_ = v_isSharedCheck_1497_;
goto v_resetjp_1491_;
}
v_resetjp_1491_:
{
lean_object* v___x_1495_; 
if (v_isShared_1493_ == 0)
{
v___x_1495_ = v___x_1492_;
goto v_reusejp_1494_;
}
else
{
lean_object* v_reuseFailAlloc_1496_; 
v_reuseFailAlloc_1496_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1496_, 0, v_a_1490_);
v___x_1495_ = v_reuseFailAlloc_1496_;
goto v_reusejp_1494_;
}
v_reusejp_1494_:
{
return v___x_1495_;
}
}
}
}
}
else
{
lean_object* v___x_1498_; 
lean_dec_ref(v_a_1448_);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v___x_1445_);
v___x_1498_ = l_Lean_Meta_normalizeInstance(v___x_1445_, v_a_1441_, v_compile_1420_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1498_) == 0)
{
lean_object* v_a_1499_; lean_object* v___x_1500_; 
v_a_1499_ = lean_ctor_get(v___x_1498_, 0);
lean_inc(v_a_1499_);
lean_dec_ref(v___x_1498_);
v___x_1500_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v_a_1499_, v___y_1424_);
if (lean_obj_tag(v___x_1500_) == 0)
{
lean_dec_ref(v___x_1500_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1500_;
}
}
else
{
lean_object* v_a_1501_; lean_object* v___x_1503_; uint8_t v_isShared_1504_; uint8_t v_isSharedCheck_1508_; 
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1501_ = lean_ctor_get(v___x_1498_, 0);
v_isSharedCheck_1508_ = !lean_is_exclusive(v___x_1498_);
if (v_isSharedCheck_1508_ == 0)
{
v___x_1503_ = v___x_1498_;
v_isShared_1504_ = v_isSharedCheck_1508_;
goto v_resetjp_1502_;
}
else
{
lean_inc(v_a_1501_);
lean_dec(v___x_1498_);
v___x_1503_ = lean_box(0);
v_isShared_1504_ = v_isSharedCheck_1508_;
goto v_resetjp_1502_;
}
v_resetjp_1502_:
{
lean_object* v___x_1506_; 
if (v_isShared_1504_ == 0)
{
v___x_1506_ = v___x_1503_;
goto v_reusejp_1505_;
}
else
{
lean_object* v_reuseFailAlloc_1507_; 
v_reuseFailAlloc_1507_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1507_, 0, v_a_1501_);
v___x_1506_ = v_reuseFailAlloc_1507_;
goto v_reusejp_1505_;
}
v_reusejp_1505_:
{
return v___x_1506_;
}
}
}
}
}
else
{
lean_object* v_a_1509_; lean_object* v___x_1511_; uint8_t v_isShared_1512_; uint8_t v_isSharedCheck_1516_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1509_ = lean_ctor_get(v___x_1447_, 0);
v_isSharedCheck_1516_ = !lean_is_exclusive(v___x_1447_);
if (v_isSharedCheck_1516_ == 0)
{
v___x_1511_ = v___x_1447_;
v_isShared_1512_ = v_isSharedCheck_1516_;
goto v_resetjp_1510_;
}
else
{
lean_inc(v_a_1509_);
lean_dec(v___x_1447_);
v___x_1511_ = lean_box(0);
v_isShared_1512_ = v_isSharedCheck_1516_;
goto v_resetjp_1510_;
}
v_resetjp_1510_:
{
lean_object* v___x_1514_; 
if (v_isShared_1512_ == 0)
{
v___x_1514_ = v___x_1511_;
goto v_reusejp_1513_;
}
else
{
lean_object* v_reuseFailAlloc_1515_; 
v_reuseFailAlloc_1515_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1515_, 0, v_a_1509_);
v___x_1514_ = v_reuseFailAlloc_1515_;
goto v_reusejp_1513_;
}
v_reusejp_1513_:
{
return v___x_1514_;
}
}
}
}
else
{
lean_object* v_options_1517_; lean_object* v___x_1518_; uint8_t v___x_1519_; 
v_options_1517_ = lean_ctor_get(v___y_1425_, 2);
v___x_1518_ = l_Lean_Meta_instance_normalForm_wrapFields_proofs;
v___x_1519_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1517_, v___x_1518_);
if (v___x_1519_ == 0)
{
lean_object* v___x_1520_; 
lean_dec(v_a_1441_);
lean_inc(v___x_1445_);
v___x_1520_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v___x_1445_, v___y_1424_);
if (lean_obj_tag(v___x_1520_) == 0)
{
lean_dec_ref(v___x_1520_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1520_;
}
}
else
{
lean_object* v___x_1521_; 
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v___x_1445_);
v___x_1521_ = lean_infer_type(v___x_1445_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1521_) == 0)
{
lean_object* v_a_1522_; lean_object* v___x_1523_; 
v_a_1522_ = lean_ctor_get(v___x_1521_, 0);
lean_inc(v_a_1522_);
lean_dec_ref(v___x_1521_);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v_a_1441_);
v___x_1523_ = l_Lean_Meta_isExprDefEq(v_a_1441_, v_a_1522_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1523_) == 0)
{
lean_object* v_a_1524_; uint8_t v___x_1525_; 
v_a_1524_ = lean_ctor_get(v___x_1523_, 0);
lean_inc(v_a_1524_);
lean_dec_ref(v___x_1523_);
v___x_1525_ = lean_unbox(v_a_1524_);
lean_dec(v_a_1524_);
if (v___x_1525_ == 0)
{
lean_object* v___x_1526_; lean_object* v___x_1527_; 
v___x_1526_ = lean_box(0);
lean_inc(v___y_1426_);
lean_inc_ref(v___y_1425_);
lean_inc(v___y_1424_);
lean_inc_ref(v___y_1423_);
lean_inc(v___x_1445_);
v___x_1527_ = l_Lean_Meta_mkAuxTheorem(v_a_1441_, v___x_1445_, v___x_1519_, v___x_1526_, v___x_1519_, v___y_1423_, v___y_1424_, v___y_1425_, v___y_1426_);
if (lean_obj_tag(v___x_1527_) == 0)
{
lean_object* v_a_1528_; lean_object* v___x_1529_; 
v_a_1528_ = lean_ctor_get(v___x_1527_, 0);
lean_inc(v_a_1528_);
lean_dec_ref(v___x_1527_);
v___x_1529_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v_a_1528_, v___y_1424_);
if (lean_obj_tag(v___x_1529_) == 0)
{
lean_dec_ref(v___x_1529_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1529_;
}
}
else
{
lean_object* v_a_1530_; lean_object* v___x_1532_; uint8_t v_isShared_1533_; uint8_t v_isSharedCheck_1537_; 
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1530_ = lean_ctor_get(v___x_1527_, 0);
v_isSharedCheck_1537_ = !lean_is_exclusive(v___x_1527_);
if (v_isSharedCheck_1537_ == 0)
{
v___x_1532_ = v___x_1527_;
v_isShared_1533_ = v_isSharedCheck_1537_;
goto v_resetjp_1531_;
}
else
{
lean_inc(v_a_1530_);
lean_dec(v___x_1527_);
v___x_1532_ = lean_box(0);
v_isShared_1533_ = v_isSharedCheck_1537_;
goto v_resetjp_1531_;
}
v_resetjp_1531_:
{
lean_object* v___x_1535_; 
if (v_isShared_1533_ == 0)
{
v___x_1535_ = v___x_1532_;
goto v_reusejp_1534_;
}
else
{
lean_object* v_reuseFailAlloc_1536_; 
v_reuseFailAlloc_1536_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1536_, 0, v_a_1530_);
v___x_1535_ = v_reuseFailAlloc_1536_;
goto v_reusejp_1534_;
}
v_reusejp_1534_:
{
return v___x_1535_;
}
}
}
}
else
{
lean_object* v___x_1538_; 
lean_dec(v_a_1441_);
lean_inc(v___x_1445_);
v___x_1538_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1436_, v___x_1445_, v___y_1424_);
if (lean_obj_tag(v___x_1538_) == 0)
{
lean_dec_ref(v___x_1538_);
v_a_1429_ = v___x_1444_;
goto v___jp_1428_;
}
else
{
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
return v___x_1538_;
}
}
}
else
{
lean_object* v_a_1539_; lean_object* v___x_1541_; uint8_t v_isShared_1542_; uint8_t v_isSharedCheck_1546_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1539_ = lean_ctor_get(v___x_1523_, 0);
v_isSharedCheck_1546_ = !lean_is_exclusive(v___x_1523_);
if (v_isSharedCheck_1546_ == 0)
{
v___x_1541_ = v___x_1523_;
v_isShared_1542_ = v_isSharedCheck_1546_;
goto v_resetjp_1540_;
}
else
{
lean_inc(v_a_1539_);
lean_dec(v___x_1523_);
v___x_1541_ = lean_box(0);
v_isShared_1542_ = v_isSharedCheck_1546_;
goto v_resetjp_1540_;
}
v_resetjp_1540_:
{
lean_object* v___x_1544_; 
if (v_isShared_1542_ == 0)
{
v___x_1544_ = v___x_1541_;
goto v_reusejp_1543_;
}
else
{
lean_object* v_reuseFailAlloc_1545_; 
v_reuseFailAlloc_1545_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1545_, 0, v_a_1539_);
v___x_1544_ = v_reuseFailAlloc_1545_;
goto v_reusejp_1543_;
}
v_reusejp_1543_:
{
return v___x_1544_;
}
}
}
}
else
{
lean_object* v_a_1547_; lean_object* v___x_1549_; uint8_t v_isShared_1550_; uint8_t v_isSharedCheck_1554_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1547_ = lean_ctor_get(v___x_1521_, 0);
v_isSharedCheck_1554_ = !lean_is_exclusive(v___x_1521_);
if (v_isSharedCheck_1554_ == 0)
{
v___x_1549_ = v___x_1521_;
v_isShared_1550_ = v_isSharedCheck_1554_;
goto v_resetjp_1548_;
}
else
{
lean_inc(v_a_1547_);
lean_dec(v___x_1521_);
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
else
{
lean_object* v_a_1555_; lean_object* v___x_1557_; uint8_t v_isShared_1558_; uint8_t v_isSharedCheck_1562_; 
lean_dec(v_a_1441_);
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1555_ = lean_ctor_get(v___x_1442_, 0);
v_isSharedCheck_1562_ = !lean_is_exclusive(v___x_1442_);
if (v_isSharedCheck_1562_ == 0)
{
v___x_1557_ = v___x_1442_;
v_isShared_1558_ = v_isSharedCheck_1562_;
goto v_resetjp_1556_;
}
else
{
lean_inc(v_a_1555_);
lean_dec(v___x_1442_);
v___x_1557_ = lean_box(0);
v_isShared_1558_ = v_isSharedCheck_1562_;
goto v_resetjp_1556_;
}
v_resetjp_1556_:
{
lean_object* v___x_1560_; 
if (v_isShared_1558_ == 0)
{
v___x_1560_ = v___x_1557_;
goto v_reusejp_1559_;
}
else
{
lean_object* v_reuseFailAlloc_1561_; 
v_reuseFailAlloc_1561_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1561_, 0, v_a_1555_);
v___x_1560_ = v_reuseFailAlloc_1561_;
goto v_reusejp_1559_;
}
v_reusejp_1559_:
{
return v___x_1560_;
}
}
}
}
else
{
lean_object* v_a_1563_; lean_object* v___x_1565_; uint8_t v_isShared_1566_; uint8_t v_isSharedCheck_1570_; 
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1563_ = lean_ctor_get(v___x_1440_, 0);
v_isSharedCheck_1570_ = !lean_is_exclusive(v___x_1440_);
if (v_isSharedCheck_1570_ == 0)
{
v___x_1565_ = v___x_1440_;
v_isShared_1566_ = v_isSharedCheck_1570_;
goto v_resetjp_1564_;
}
else
{
lean_inc(v_a_1563_);
lean_dec(v___x_1440_);
v___x_1565_ = lean_box(0);
v_isShared_1566_ = v_isSharedCheck_1570_;
goto v_resetjp_1564_;
}
v_resetjp_1564_:
{
lean_object* v___x_1568_; 
if (v_isShared_1566_ == 0)
{
v___x_1568_ = v___x_1565_;
goto v_reusejp_1567_;
}
else
{
lean_object* v_reuseFailAlloc_1569_; 
v_reuseFailAlloc_1569_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1569_, 0, v_a_1563_);
v___x_1568_ = v_reuseFailAlloc_1569_;
goto v_reusejp_1567_;
}
v_reusejp_1567_:
{
return v___x_1568_;
}
}
}
}
else
{
lean_object* v_a_1571_; lean_object* v___x_1573_; uint8_t v_isShared_1574_; uint8_t v_isSharedCheck_1578_; 
lean_dec(v___x_1436_);
lean_dec(v___y_1426_);
lean_dec_ref(v___y_1425_);
lean_dec(v___y_1424_);
lean_dec_ref(v___y_1423_);
lean_dec(v_a_1421_);
v_a_1571_ = lean_ctor_get(v___x_1437_, 0);
v_isSharedCheck_1578_ = !lean_is_exclusive(v___x_1437_);
if (v_isSharedCheck_1578_ == 0)
{
v___x_1573_ = v___x_1437_;
v_isShared_1574_ = v_isSharedCheck_1578_;
goto v_resetjp_1572_;
}
else
{
lean_inc(v_a_1571_);
lean_dec(v___x_1437_);
v___x_1573_ = lean_box(0);
v_isShared_1574_ = v_isSharedCheck_1578_;
goto v_resetjp_1572_;
}
v_resetjp_1572_:
{
lean_object* v___x_1576_; 
if (v_isShared_1574_ == 0)
{
v___x_1576_ = v___x_1573_;
goto v_reusejp_1575_;
}
else
{
lean_object* v_reuseFailAlloc_1577_; 
v_reuseFailAlloc_1577_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1577_, 0, v_a_1571_);
v___x_1576_ = v_reuseFailAlloc_1577_;
goto v_reusejp_1575_;
}
v_reusejp_1575_:
{
return v___x_1576_;
}
}
}
}
v___jp_1428_:
{
lean_object* v___x_1430_; lean_object* v___x_1431_; 
v___x_1430_ = lean_unsigned_to_nat(1u);
v___x_1431_ = lean_nat_add(v_a_1421_, v___x_1430_);
lean_dec(v_a_1421_);
v_a_1421_ = v___x_1431_;
v_b_1422_ = v_a_1429_;
goto _start;
}
}
}
static lean_object* _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3(void){
_start:
{
lean_object* v___x_1580_; lean_object* v___x_1581_; 
v___x_1580_ = ((lean_object*)(l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__2));
v___x_1581_ = l_Lean_stringToMessageData(v___x_1580_);
return v___x_1581_;
}
}
static lean_object* _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5(void){
_start:
{
lean_object* v___x_1583_; lean_object* v___x_1584_; 
v___x_1583_ = ((lean_object*)(l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__4));
v___x_1584_ = l_Lean_stringToMessageData(v___x_1583_);
return v___x_1584_;
}
}
static lean_object* _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7(void){
_start:
{
lean_object* v___x_1586_; lean_object* v___x_1587_; 
v___x_1586_ = ((lean_object*)(l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__6));
v___x_1587_ = l_Lean_stringToMessageData(v___x_1586_);
return v___x_1587_;
}
}
static lean_object* _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9(void){
_start:
{
lean_object* v___x_1589_; lean_object* v___x_1590_; 
v___x_1589_ = ((lean_object*)(l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__8));
v___x_1590_ = l_Lean_stringToMessageData(v___x_1589_);
return v___x_1590_;
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12(lean_object* v_a_1591_, lean_object* v_expectedType_1592_, uint8_t v___x_1593_, uint8_t v_compile_1594_, lean_object* v_x_1595_, lean_object* v_x_1596_, lean_object* v_x_1597_, lean_object* v___y_1598_, lean_object* v___y_1599_, lean_object* v___y_1600_, lean_object* v___y_1601_){
_start:
{
lean_object* v___y_1604_; lean_object* v___y_1605_; lean_object* v___y_1606_; lean_object* v___y_1607_; 
if (lean_obj_tag(v_x_1595_) == 5)
{
lean_object* v_fn_1656_; lean_object* v_arg_1657_; lean_object* v___x_1658_; lean_object* v___x_1659_; lean_object* v___x_1660_; 
v_fn_1656_ = lean_ctor_get(v_x_1595_, 0);
lean_inc_ref(v_fn_1656_);
v_arg_1657_ = lean_ctor_get(v_x_1595_, 1);
lean_inc_ref(v_arg_1657_);
lean_dec_ref(v_x_1595_);
v___x_1658_ = lean_array_set(v_x_1596_, v_x_1597_, v_arg_1657_);
v___x_1659_ = lean_unsigned_to_nat(1u);
v___x_1660_ = lean_nat_sub(v_x_1597_, v___x_1659_);
lean_dec(v_x_1597_);
v_x_1595_ = v_fn_1656_;
v_x_1596_ = v___x_1658_;
v_x_1597_ = v___x_1660_;
goto _start;
}
else
{
lean_object* v_cls_1662_; lean_object* v___y_1664_; lean_object* v___y_1665_; lean_object* v___y_1666_; lean_object* v___y_1667_; lean_object* v___x_1683_; 
lean_dec(v_x_1597_);
v_cls_1662_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_1683_ = l_Lean_Expr_constName_x3f(v_x_1595_);
if (lean_obj_tag(v___x_1683_) == 0)
{
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
v___y_1664_ = v___y_1598_;
v___y_1665_ = v___y_1599_;
v___y_1666_ = v___y_1600_;
v___y_1667_ = v___y_1601_;
goto v___jp_1663_;
}
else
{
lean_object* v_val_1684_; lean_object* v___x_1685_; 
v_val_1684_ = lean_ctor_get(v___x_1683_, 0);
lean_inc(v_val_1684_);
lean_dec_ref(v___x_1683_);
lean_inc_ref(v___y_1600_);
v___x_1685_ = l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(v_val_1684_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
if (lean_obj_tag(v___x_1685_) == 0)
{
lean_object* v_a_1686_; 
v_a_1686_ = lean_ctor_get(v___x_1685_, 0);
lean_inc(v_a_1686_);
lean_dec_ref(v___x_1685_);
if (lean_obj_tag(v_a_1686_) == 6)
{
lean_object* v_val_1687_; lean_object* v___x_1688_; 
lean_dec_ref(v_a_1591_);
v_val_1687_ = lean_ctor_get(v_a_1686_, 0);
lean_inc_ref(v_val_1687_);
lean_dec_ref(v_a_1686_);
lean_inc(v___y_1601_);
lean_inc_ref(v___y_1600_);
lean_inc(v___y_1599_);
lean_inc_ref(v___y_1598_);
lean_inc_ref(v_x_1595_);
v___x_1688_ = lean_infer_type(v_x_1595_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
if (lean_obj_tag(v___x_1688_) == 0)
{
lean_object* v_a_1689_; uint8_t v___x_1690_; lean_object* v___x_1691_; 
v_a_1689_ = lean_ctor_get(v___x_1688_, 0);
lean_inc(v_a_1689_);
lean_dec_ref(v___x_1688_);
v___x_1690_ = 0;
lean_inc(v___y_1601_);
lean_inc_ref(v___y_1600_);
lean_inc(v___y_1599_);
lean_inc_ref(v___y_1598_);
v___x_1691_ = l_Lean_Meta_forallMetaTelescope(v_a_1689_, v___x_1690_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
if (lean_obj_tag(v___x_1691_) == 0)
{
lean_object* v_a_1692_; lean_object* v_snd_1693_; lean_object* v_fst_1694_; lean_object* v___x_1696_; uint8_t v_isShared_1697_; uint8_t v_isSharedCheck_1793_; 
v_a_1692_ = lean_ctor_get(v___x_1691_, 0);
lean_inc(v_a_1692_);
lean_dec_ref(v___x_1691_);
v_snd_1693_ = lean_ctor_get(v_a_1692_, 1);
v_fst_1694_ = lean_ctor_get(v_a_1692_, 0);
v_isSharedCheck_1793_ = !lean_is_exclusive(v_a_1692_);
if (v_isSharedCheck_1793_ == 0)
{
v___x_1696_ = v_a_1692_;
v_isShared_1697_ = v_isSharedCheck_1793_;
goto v_resetjp_1695_;
}
else
{
lean_inc(v_snd_1693_);
lean_inc(v_fst_1694_);
lean_dec(v_a_1692_);
v___x_1696_ = lean_box(0);
v_isShared_1697_ = v_isSharedCheck_1793_;
goto v_resetjp_1695_;
}
v_resetjp_1695_:
{
lean_object* v_snd_1698_; lean_object* v___x_1700_; uint8_t v_isShared_1701_; uint8_t v_isSharedCheck_1791_; 
v_snd_1698_ = lean_ctor_get(v_snd_1693_, 1);
v_isSharedCheck_1791_ = !lean_is_exclusive(v_snd_1693_);
if (v_isSharedCheck_1791_ == 0)
{
lean_object* v_unused_1792_; 
v_unused_1792_ = lean_ctor_get(v_snd_1693_, 0);
lean_dec(v_unused_1792_);
v___x_1700_ = v_snd_1693_;
v_isShared_1701_ = v_isSharedCheck_1791_;
goto v_resetjp_1699_;
}
else
{
lean_inc(v_snd_1698_);
lean_dec(v_snd_1693_);
v___x_1700_ = lean_box(0);
v_isShared_1701_ = v_isSharedCheck_1791_;
goto v_resetjp_1699_;
}
v_resetjp_1699_:
{
lean_object* v___x_1702_; lean_object* v___y_1704_; lean_object* v___y_1705_; lean_object* v___y_1706_; lean_object* v___y_1707_; lean_object* v___x_1739_; uint8_t v___x_1740_; 
v___x_1702_ = lean_array_get_size(v_x_1596_);
v___x_1739_ = lean_array_get_size(v_fst_1694_);
v___x_1740_ = lean_nat_dec_eq(v___x_1702_, v___x_1739_);
if (v___x_1740_ == 0)
{
lean_object* v___x_1741_; lean_object* v___x_1742_; lean_object* v___x_1744_; 
lean_dec(v_snd_1698_);
lean_dec(v_fst_1694_);
lean_dec_ref(v_val_1687_);
lean_dec_ref(v_expectedType_1592_);
v___x_1741_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3);
v___x_1742_ = l_Lean_MessageData_ofExpr(v_x_1595_);
if (v_isShared_1701_ == 0)
{
lean_ctor_set_tag(v___x_1700_, 7);
lean_ctor_set(v___x_1700_, 1, v___x_1742_);
lean_ctor_set(v___x_1700_, 0, v___x_1741_);
v___x_1744_ = v___x_1700_;
goto v_reusejp_1743_;
}
else
{
lean_object* v_reuseFailAlloc_1755_; 
v_reuseFailAlloc_1755_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1755_, 0, v___x_1741_);
lean_ctor_set(v_reuseFailAlloc_1755_, 1, v___x_1742_);
v___x_1744_ = v_reuseFailAlloc_1755_;
goto v_reusejp_1743_;
}
v_reusejp_1743_:
{
lean_object* v___x_1745_; lean_object* v___x_1747_; 
v___x_1745_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5);
if (v_isShared_1697_ == 0)
{
lean_ctor_set_tag(v___x_1696_, 7);
lean_ctor_set(v___x_1696_, 1, v___x_1745_);
lean_ctor_set(v___x_1696_, 0, v___x_1744_);
v___x_1747_ = v___x_1696_;
goto v_reusejp_1746_;
}
else
{
lean_object* v_reuseFailAlloc_1754_; 
v_reuseFailAlloc_1754_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1754_, 0, v___x_1744_);
lean_ctor_set(v_reuseFailAlloc_1754_, 1, v___x_1745_);
v___x_1747_ = v_reuseFailAlloc_1754_;
goto v_reusejp_1746_;
}
v_reusejp_1746_:
{
lean_object* v___x_1748_; lean_object* v___x_1749_; lean_object* v___x_1750_; lean_object* v___x_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; 
v___x_1748_ = lean_array_to_list(v_x_1596_);
v___x_1749_ = lean_box(0);
v___x_1750_ = l_List_mapTR_loop___at___00Lean_Meta_normalizeInstance_spec__11(v___x_1748_, v___x_1749_);
v___x_1751_ = l_Lean_MessageData_ofList(v___x_1750_);
v___x_1752_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1752_, 0, v___x_1747_);
lean_ctor_set(v___x_1752_, 1, v___x_1751_);
v___x_1753_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_1752_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
return v___x_1753_;
}
}
}
else
{
lean_object* v___x_1756_; 
lean_inc(v___y_1601_);
lean_inc_ref(v___y_1600_);
lean_inc(v___y_1599_);
lean_inc_ref(v___y_1598_);
lean_inc_ref(v_expectedType_1592_);
v___x_1756_ = l_Lean_Meta_isExprDefEq(v_expectedType_1592_, v_snd_1698_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
if (lean_obj_tag(v___x_1756_) == 0)
{
lean_object* v_a_1757_; uint8_t v___x_1758_; 
v_a_1757_ = lean_ctor_get(v___x_1756_, 0);
lean_inc(v_a_1757_);
lean_dec_ref(v___x_1756_);
v___x_1758_ = lean_unbox(v_a_1757_);
lean_dec(v_a_1757_);
if (v___x_1758_ == 0)
{
lean_object* v_toConstantVal_1759_; lean_object* v_name_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; lean_object* v___x_1764_; 
lean_dec(v_fst_1694_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
v_toConstantVal_1759_ = lean_ctor_get(v_val_1687_, 0);
lean_inc_ref(v_toConstantVal_1759_);
lean_dec_ref(v_val_1687_);
v_name_1760_ = lean_ctor_get(v_toConstantVal_1759_, 0);
lean_inc(v_name_1760_);
lean_dec_ref(v_toConstantVal_1759_);
v___x_1761_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7);
v___x_1762_ = l_Lean_MessageData_ofExpr(v_expectedType_1592_);
if (v_isShared_1701_ == 0)
{
lean_ctor_set_tag(v___x_1700_, 7);
lean_ctor_set(v___x_1700_, 1, v___x_1762_);
lean_ctor_set(v___x_1700_, 0, v___x_1761_);
v___x_1764_ = v___x_1700_;
goto v_reusejp_1763_;
}
else
{
lean_object* v_reuseFailAlloc_1782_; 
v_reuseFailAlloc_1782_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1782_, 0, v___x_1761_);
lean_ctor_set(v_reuseFailAlloc_1782_, 1, v___x_1762_);
v___x_1764_ = v_reuseFailAlloc_1782_;
goto v_reusejp_1763_;
}
v_reusejp_1763_:
{
lean_object* v___x_1765_; lean_object* v___x_1767_; 
v___x_1765_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9);
if (v_isShared_1697_ == 0)
{
lean_ctor_set_tag(v___x_1696_, 7);
lean_ctor_set(v___x_1696_, 1, v___x_1765_);
lean_ctor_set(v___x_1696_, 0, v___x_1764_);
v___x_1767_ = v___x_1696_;
goto v_reusejp_1766_;
}
else
{
lean_object* v_reuseFailAlloc_1781_; 
v_reuseFailAlloc_1781_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1781_, 0, v___x_1764_);
lean_ctor_set(v_reuseFailAlloc_1781_, 1, v___x_1765_);
v___x_1767_ = v_reuseFailAlloc_1781_;
goto v_reusejp_1766_;
}
v_reusejp_1766_:
{
lean_object* v___x_1768_; lean_object* v___x_1769_; lean_object* v___x_1770_; lean_object* v___x_1771_; lean_object* v___x_1772_; lean_object* v_a_1773_; lean_object* v___x_1775_; uint8_t v_isShared_1776_; uint8_t v_isSharedCheck_1780_; 
v___x_1768_ = l_Lean_MessageData_ofConstName(v_name_1760_, v___x_1593_);
v___x_1769_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1769_, 0, v___x_1767_);
lean_ctor_set(v___x_1769_, 1, v___x_1768_);
v___x_1770_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3);
v___x_1771_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1771_, 0, v___x_1769_);
lean_ctor_set(v___x_1771_, 1, v___x_1770_);
v___x_1772_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_1771_, v___y_1598_, v___y_1599_, v___y_1600_, v___y_1601_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
v_a_1773_ = lean_ctor_get(v___x_1772_, 0);
v_isSharedCheck_1780_ = !lean_is_exclusive(v___x_1772_);
if (v_isSharedCheck_1780_ == 0)
{
v___x_1775_ = v___x_1772_;
v_isShared_1776_ = v_isSharedCheck_1780_;
goto v_resetjp_1774_;
}
else
{
lean_inc(v_a_1773_);
lean_dec(v___x_1772_);
v___x_1775_ = lean_box(0);
v_isShared_1776_ = v_isSharedCheck_1780_;
goto v_resetjp_1774_;
}
v_resetjp_1774_:
{
lean_object* v___x_1778_; 
if (v_isShared_1776_ == 0)
{
v___x_1778_ = v___x_1775_;
goto v_reusejp_1777_;
}
else
{
lean_object* v_reuseFailAlloc_1779_; 
v_reuseFailAlloc_1779_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1779_, 0, v_a_1773_);
v___x_1778_ = v_reuseFailAlloc_1779_;
goto v_reusejp_1777_;
}
v_reusejp_1777_:
{
return v___x_1778_;
}
}
}
}
}
else
{
lean_del_object(v___x_1700_);
lean_del_object(v___x_1696_);
lean_dec_ref(v_expectedType_1592_);
v___y_1704_ = v___y_1598_;
v___y_1705_ = v___y_1599_;
v___y_1706_ = v___y_1600_;
v___y_1707_ = v___y_1601_;
goto v___jp_1703_;
}
}
else
{
lean_object* v_a_1783_; lean_object* v___x_1785_; uint8_t v_isShared_1786_; uint8_t v_isSharedCheck_1790_; 
lean_del_object(v___x_1700_);
lean_del_object(v___x_1696_);
lean_dec(v_fst_1694_);
lean_dec_ref(v_val_1687_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
lean_dec_ref(v_expectedType_1592_);
v_a_1783_ = lean_ctor_get(v___x_1756_, 0);
v_isSharedCheck_1790_ = !lean_is_exclusive(v___x_1756_);
if (v_isSharedCheck_1790_ == 0)
{
v___x_1785_ = v___x_1756_;
v_isShared_1786_ = v_isSharedCheck_1790_;
goto v_resetjp_1784_;
}
else
{
lean_inc(v_a_1783_);
lean_dec(v___x_1756_);
v___x_1785_ = lean_box(0);
v_isShared_1786_ = v_isSharedCheck_1790_;
goto v_resetjp_1784_;
}
v_resetjp_1784_:
{
lean_object* v___x_1788_; 
if (v_isShared_1786_ == 0)
{
v___x_1788_ = v___x_1785_;
goto v_reusejp_1787_;
}
else
{
lean_object* v_reuseFailAlloc_1789_; 
v_reuseFailAlloc_1789_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1789_, 0, v_a_1783_);
v___x_1788_ = v_reuseFailAlloc_1789_;
goto v_reusejp_1787_;
}
v_reusejp_1787_:
{
return v___x_1788_;
}
}
}
}
v___jp_1703_:
{
lean_object* v_numParams_1708_; lean_object* v___x_1709_; lean_object* v___x_1710_; 
v_numParams_1708_ = lean_ctor_get(v_val_1687_, 3);
lean_inc(v_numParams_1708_);
lean_dec_ref(v_val_1687_);
v___x_1709_ = lean_box(0);
lean_inc(v___y_1707_);
lean_inc_ref(v___y_1706_);
lean_inc(v___y_1705_);
lean_inc_ref(v___y_1704_);
v___x_1710_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg(v___x_1702_, v_fst_1694_, v_x_1596_, v___x_1593_, v_compile_1594_, v_numParams_1708_, v___x_1709_, v___y_1704_, v___y_1705_, v___y_1706_, v___y_1707_);
lean_dec_ref(v_x_1596_);
if (lean_obj_tag(v___x_1710_) == 0)
{
size_t v_sz_1711_; size_t v___x_1712_; lean_object* v___x_1713_; 
lean_dec_ref(v___x_1710_);
v_sz_1711_ = lean_array_size(v_fst_1694_);
v___x_1712_ = ((size_t)0ULL);
v___x_1713_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(v_sz_1711_, v___x_1712_, v_fst_1694_, v___y_1704_, v___y_1705_, v___y_1706_, v___y_1707_);
lean_dec(v___y_1707_);
lean_dec_ref(v___y_1706_);
lean_dec(v___y_1705_);
lean_dec_ref(v___y_1704_);
if (lean_obj_tag(v___x_1713_) == 0)
{
lean_object* v_a_1714_; lean_object* v___x_1716_; uint8_t v_isShared_1717_; uint8_t v_isSharedCheck_1722_; 
v_a_1714_ = lean_ctor_get(v___x_1713_, 0);
v_isSharedCheck_1722_ = !lean_is_exclusive(v___x_1713_);
if (v_isSharedCheck_1722_ == 0)
{
v___x_1716_ = v___x_1713_;
v_isShared_1717_ = v_isSharedCheck_1722_;
goto v_resetjp_1715_;
}
else
{
lean_inc(v_a_1714_);
lean_dec(v___x_1713_);
v___x_1716_ = lean_box(0);
v_isShared_1717_ = v_isSharedCheck_1722_;
goto v_resetjp_1715_;
}
v_resetjp_1715_:
{
lean_object* v___x_1718_; lean_object* v___x_1720_; 
v___x_1718_ = l_Lean_mkAppN(v_x_1595_, v_a_1714_);
lean_dec(v_a_1714_);
if (v_isShared_1717_ == 0)
{
lean_ctor_set(v___x_1716_, 0, v___x_1718_);
v___x_1720_ = v___x_1716_;
goto v_reusejp_1719_;
}
else
{
lean_object* v_reuseFailAlloc_1721_; 
v_reuseFailAlloc_1721_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1721_, 0, v___x_1718_);
v___x_1720_ = v_reuseFailAlloc_1721_;
goto v_reusejp_1719_;
}
v_reusejp_1719_:
{
return v___x_1720_;
}
}
}
else
{
lean_object* v_a_1723_; lean_object* v___x_1725_; uint8_t v_isShared_1726_; uint8_t v_isSharedCheck_1730_; 
lean_dec_ref(v_x_1595_);
v_a_1723_ = lean_ctor_get(v___x_1713_, 0);
v_isSharedCheck_1730_ = !lean_is_exclusive(v___x_1713_);
if (v_isSharedCheck_1730_ == 0)
{
v___x_1725_ = v___x_1713_;
v_isShared_1726_ = v_isSharedCheck_1730_;
goto v_resetjp_1724_;
}
else
{
lean_inc(v_a_1723_);
lean_dec(v___x_1713_);
v___x_1725_ = lean_box(0);
v_isShared_1726_ = v_isSharedCheck_1730_;
goto v_resetjp_1724_;
}
v_resetjp_1724_:
{
lean_object* v___x_1728_; 
if (v_isShared_1726_ == 0)
{
v___x_1728_ = v___x_1725_;
goto v_reusejp_1727_;
}
else
{
lean_object* v_reuseFailAlloc_1729_; 
v_reuseFailAlloc_1729_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1729_, 0, v_a_1723_);
v___x_1728_ = v_reuseFailAlloc_1729_;
goto v_reusejp_1727_;
}
v_reusejp_1727_:
{
return v___x_1728_;
}
}
}
}
else
{
lean_object* v_a_1731_; lean_object* v___x_1733_; uint8_t v_isShared_1734_; uint8_t v_isSharedCheck_1738_; 
lean_dec(v___y_1707_);
lean_dec_ref(v___y_1706_);
lean_dec(v___y_1705_);
lean_dec_ref(v___y_1704_);
lean_dec(v_fst_1694_);
lean_dec_ref(v_x_1595_);
v_a_1731_ = lean_ctor_get(v___x_1710_, 0);
v_isSharedCheck_1738_ = !lean_is_exclusive(v___x_1710_);
if (v_isSharedCheck_1738_ == 0)
{
v___x_1733_ = v___x_1710_;
v_isShared_1734_ = v_isSharedCheck_1738_;
goto v_resetjp_1732_;
}
else
{
lean_inc(v_a_1731_);
lean_dec(v___x_1710_);
v___x_1733_ = lean_box(0);
v_isShared_1734_ = v_isSharedCheck_1738_;
goto v_resetjp_1732_;
}
v_resetjp_1732_:
{
lean_object* v___x_1736_; 
if (v_isShared_1734_ == 0)
{
v___x_1736_ = v___x_1733_;
goto v_reusejp_1735_;
}
else
{
lean_object* v_reuseFailAlloc_1737_; 
v_reuseFailAlloc_1737_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1737_, 0, v_a_1731_);
v___x_1736_ = v_reuseFailAlloc_1737_;
goto v_reusejp_1735_;
}
v_reusejp_1735_:
{
return v___x_1736_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_1794_; lean_object* v___x_1796_; uint8_t v_isShared_1797_; uint8_t v_isSharedCheck_1801_; 
lean_dec_ref(v_val_1687_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
lean_dec_ref(v_expectedType_1592_);
v_a_1794_ = lean_ctor_get(v___x_1691_, 0);
v_isSharedCheck_1801_ = !lean_is_exclusive(v___x_1691_);
if (v_isSharedCheck_1801_ == 0)
{
v___x_1796_ = v___x_1691_;
v_isShared_1797_ = v_isSharedCheck_1801_;
goto v_resetjp_1795_;
}
else
{
lean_inc(v_a_1794_);
lean_dec(v___x_1691_);
v___x_1796_ = lean_box(0);
v_isShared_1797_ = v_isSharedCheck_1801_;
goto v_resetjp_1795_;
}
v_resetjp_1795_:
{
lean_object* v___x_1799_; 
if (v_isShared_1797_ == 0)
{
v___x_1799_ = v___x_1796_;
goto v_reusejp_1798_;
}
else
{
lean_object* v_reuseFailAlloc_1800_; 
v_reuseFailAlloc_1800_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1800_, 0, v_a_1794_);
v___x_1799_ = v_reuseFailAlloc_1800_;
goto v_reusejp_1798_;
}
v_reusejp_1798_:
{
return v___x_1799_;
}
}
}
}
else
{
lean_dec_ref(v_val_1687_);
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
lean_dec_ref(v_expectedType_1592_);
return v___x_1688_;
}
}
else
{
lean_dec(v_a_1686_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
v___y_1664_ = v___y_1598_;
v___y_1665_ = v___y_1599_;
v___y_1666_ = v___y_1600_;
v___y_1667_ = v___y_1601_;
goto v___jp_1663_;
}
}
else
{
lean_object* v_a_1802_; lean_object* v___x_1804_; uint8_t v_isShared_1805_; uint8_t v_isSharedCheck_1809_; 
lean_dec(v___y_1601_);
lean_dec_ref(v___y_1600_);
lean_dec(v___y_1599_);
lean_dec_ref(v___y_1598_);
lean_dec_ref(v_x_1596_);
lean_dec_ref(v_x_1595_);
lean_dec_ref(v_expectedType_1592_);
lean_dec_ref(v_a_1591_);
v_a_1802_ = lean_ctor_get(v___x_1685_, 0);
v_isSharedCheck_1809_ = !lean_is_exclusive(v___x_1685_);
if (v_isSharedCheck_1809_ == 0)
{
v___x_1804_ = v___x_1685_;
v_isShared_1805_ = v_isSharedCheck_1809_;
goto v_resetjp_1803_;
}
else
{
lean_inc(v_a_1802_);
lean_dec(v___x_1685_);
v___x_1804_ = lean_box(0);
v_isShared_1805_ = v_isSharedCheck_1809_;
goto v_resetjp_1803_;
}
v_resetjp_1803_:
{
lean_object* v___x_1807_; 
if (v_isShared_1805_ == 0)
{
v___x_1807_ = v___x_1804_;
goto v_reusejp_1806_;
}
else
{
lean_object* v_reuseFailAlloc_1808_; 
v_reuseFailAlloc_1808_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1808_, 0, v_a_1802_);
v___x_1807_ = v_reuseFailAlloc_1808_;
goto v_reusejp_1806_;
}
v_reusejp_1806_:
{
return v___x_1807_;
}
}
}
}
v___jp_1663_:
{
lean_object* v___x_1668_; lean_object* v_a_1669_; uint8_t v___x_1670_; 
v___x_1668_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_1662_, v___y_1666_);
v_a_1669_ = lean_ctor_get(v___x_1668_, 0);
lean_inc(v_a_1669_);
lean_dec_ref(v___x_1668_);
v___x_1670_ = lean_unbox(v_a_1669_);
lean_dec(v_a_1669_);
if (v___x_1670_ == 0)
{
v___y_1604_ = v___y_1664_;
v___y_1605_ = v___y_1665_;
v___y_1606_ = v___y_1666_;
v___y_1607_ = v___y_1667_;
goto v___jp_1603_;
}
else
{
lean_object* v___x_1671_; lean_object* v___x_1672_; lean_object* v___x_1673_; lean_object* v___x_1674_; 
v___x_1671_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1);
lean_inc_ref(v_a_1591_);
v___x_1672_ = l_Lean_MessageData_ofExpr(v_a_1591_);
v___x_1673_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_1673_, 0, v___x_1671_);
lean_ctor_set(v___x_1673_, 1, v___x_1672_);
v___x_1674_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_1662_, v___x_1673_, v___y_1664_, v___y_1665_, v___y_1666_, v___y_1667_);
if (lean_obj_tag(v___x_1674_) == 0)
{
lean_dec_ref(v___x_1674_);
v___y_1604_ = v___y_1664_;
v___y_1605_ = v___y_1665_;
v___y_1606_ = v___y_1666_;
v___y_1607_ = v___y_1667_;
goto v___jp_1603_;
}
else
{
lean_object* v_a_1675_; lean_object* v___x_1677_; uint8_t v_isShared_1678_; uint8_t v_isSharedCheck_1682_; 
lean_dec(v___y_1667_);
lean_dec_ref(v___y_1666_);
lean_dec(v___y_1665_);
lean_dec_ref(v___y_1664_);
lean_dec_ref(v_expectedType_1592_);
lean_dec_ref(v_a_1591_);
v_a_1675_ = lean_ctor_get(v___x_1674_, 0);
v_isSharedCheck_1682_ = !lean_is_exclusive(v___x_1674_);
if (v_isSharedCheck_1682_ == 0)
{
v___x_1677_ = v___x_1674_;
v_isShared_1678_ = v_isSharedCheck_1682_;
goto v_resetjp_1676_;
}
else
{
lean_inc(v_a_1675_);
lean_dec(v___x_1674_);
v___x_1677_ = lean_box(0);
v_isShared_1678_ = v_isSharedCheck_1682_;
goto v_resetjp_1676_;
}
v_resetjp_1676_:
{
lean_object* v___x_1680_; 
if (v_isShared_1678_ == 0)
{
v___x_1680_ = v___x_1677_;
goto v_reusejp_1679_;
}
else
{
lean_object* v_reuseFailAlloc_1681_; 
v_reuseFailAlloc_1681_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1681_, 0, v_a_1675_);
v___x_1680_ = v_reuseFailAlloc_1681_;
goto v_reusejp_1679_;
}
v_reusejp_1679_:
{
return v___x_1680_;
}
}
}
}
}
}
v___jp_1603_:
{
lean_object* v_options_1608_; lean_object* v___x_1609_; uint8_t v___x_1610_; 
v_options_1608_ = lean_ctor_get(v___y_1606_, 2);
v___x_1609_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_1610_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1608_, v___x_1609_);
if (v___x_1610_ == 0)
{
lean_object* v___x_1611_; 
lean_dec(v___y_1607_);
lean_dec_ref(v___y_1606_);
lean_dec(v___y_1605_);
lean_dec_ref(v___y_1604_);
lean_dec_ref(v_expectedType_1592_);
v___x_1611_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1611_, 0, v_a_1591_);
return v___x_1611_;
}
else
{
lean_object* v___x_1612_; 
lean_inc(v___y_1607_);
lean_inc_ref(v___y_1606_);
lean_inc(v___y_1605_);
lean_inc_ref(v___y_1604_);
lean_inc_ref(v_a_1591_);
v___x_1612_ = lean_infer_type(v_a_1591_, v___y_1604_, v___y_1605_, v___y_1606_, v___y_1607_);
if (lean_obj_tag(v___x_1612_) == 0)
{
lean_object* v_a_1613_; lean_object* v___x_1614_; 
v_a_1613_ = lean_ctor_get(v___x_1612_, 0);
lean_inc(v_a_1613_);
lean_dec_ref(v___x_1612_);
lean_inc(v___y_1607_);
lean_inc_ref(v___y_1606_);
lean_inc(v___y_1605_);
lean_inc_ref(v___y_1604_);
lean_inc_ref(v_expectedType_1592_);
v___x_1614_ = l_Lean_Meta_isExprDefEq(v_expectedType_1592_, v_a_1613_, v___y_1604_, v___y_1605_, v___y_1606_, v___y_1607_);
if (lean_obj_tag(v___x_1614_) == 0)
{
lean_object* v_a_1615_; lean_object* v___x_1617_; uint8_t v_isShared_1618_; uint8_t v_isSharedCheck_1647_; 
v_a_1615_ = lean_ctor_get(v___x_1614_, 0);
v_isSharedCheck_1647_ = !lean_is_exclusive(v___x_1614_);
if (v_isSharedCheck_1647_ == 0)
{
v___x_1617_ = v___x_1614_;
v_isShared_1618_ = v_isSharedCheck_1647_;
goto v_resetjp_1616_;
}
else
{
lean_inc(v_a_1615_);
lean_dec(v___x_1614_);
v___x_1617_ = lean_box(0);
v_isShared_1618_ = v_isSharedCheck_1647_;
goto v_resetjp_1616_;
}
v_resetjp_1616_:
{
uint8_t v___x_1619_; 
v___x_1619_ = lean_unbox(v_a_1615_);
lean_dec(v_a_1615_);
if (v___x_1619_ == 0)
{
lean_object* v___x_1620_; lean_object* v___x_1621_; lean_object* v_a_1622_; lean_object* v___x_1623_; 
lean_del_object(v___x_1617_);
v___x_1620_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_1621_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_1620_, v___y_1607_);
v_a_1622_ = lean_ctor_get(v___x_1621_, 0);
lean_inc(v_a_1622_);
lean_dec_ref(v___x_1621_);
lean_inc(v___y_1607_);
lean_inc_ref(v___y_1606_);
lean_inc(v___y_1605_);
lean_inc(v_a_1622_);
v___x_1623_ = l_Lean_Meta_mkAuxDefinition(v_a_1622_, v_expectedType_1592_, v_a_1591_, v___x_1593_, v_compile_1594_, v___y_1604_, v___y_1605_, v___y_1606_, v___y_1607_);
if (lean_obj_tag(v___x_1623_) == 0)
{
lean_object* v_a_1624_; uint8_t v___x_1625_; lean_object* v___x_1626_; lean_object* v___x_1627_; 
v_a_1624_ = lean_ctor_get(v___x_1623_, 0);
lean_inc(v_a_1624_);
lean_dec_ref(v___x_1623_);
v___x_1625_ = 3;
lean_inc(v_a_1622_);
v___x_1626_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(v_a_1622_, v___x_1625_, v___y_1605_, v___y_1607_);
lean_dec(v___y_1605_);
lean_dec_ref(v___x_1626_);
v___x_1627_ = l_Lean_enableRealizationsForConst(v_a_1622_, v___y_1606_, v___y_1607_);
lean_dec(v___y_1607_);
if (lean_obj_tag(v___x_1627_) == 0)
{
lean_object* v___x_1629_; uint8_t v_isShared_1630_; uint8_t v_isSharedCheck_1634_; 
v_isSharedCheck_1634_ = !lean_is_exclusive(v___x_1627_);
if (v_isSharedCheck_1634_ == 0)
{
lean_object* v_unused_1635_; 
v_unused_1635_ = lean_ctor_get(v___x_1627_, 0);
lean_dec(v_unused_1635_);
v___x_1629_ = v___x_1627_;
v_isShared_1630_ = v_isSharedCheck_1634_;
goto v_resetjp_1628_;
}
else
{
lean_dec(v___x_1627_);
v___x_1629_ = lean_box(0);
v_isShared_1630_ = v_isSharedCheck_1634_;
goto v_resetjp_1628_;
}
v_resetjp_1628_:
{
lean_object* v___x_1632_; 
if (v_isShared_1630_ == 0)
{
lean_ctor_set(v___x_1629_, 0, v_a_1624_);
v___x_1632_ = v___x_1629_;
goto v_reusejp_1631_;
}
else
{
lean_object* v_reuseFailAlloc_1633_; 
v_reuseFailAlloc_1633_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1633_, 0, v_a_1624_);
v___x_1632_ = v_reuseFailAlloc_1633_;
goto v_reusejp_1631_;
}
v_reusejp_1631_:
{
return v___x_1632_;
}
}
}
else
{
lean_object* v_a_1636_; lean_object* v___x_1638_; uint8_t v_isShared_1639_; uint8_t v_isSharedCheck_1643_; 
lean_dec(v_a_1624_);
v_a_1636_ = lean_ctor_get(v___x_1627_, 0);
v_isSharedCheck_1643_ = !lean_is_exclusive(v___x_1627_);
if (v_isSharedCheck_1643_ == 0)
{
v___x_1638_ = v___x_1627_;
v_isShared_1639_ = v_isSharedCheck_1643_;
goto v_resetjp_1637_;
}
else
{
lean_inc(v_a_1636_);
lean_dec(v___x_1627_);
v___x_1638_ = lean_box(0);
v_isShared_1639_ = v_isSharedCheck_1643_;
goto v_resetjp_1637_;
}
v_resetjp_1637_:
{
lean_object* v___x_1641_; 
if (v_isShared_1639_ == 0)
{
v___x_1641_ = v___x_1638_;
goto v_reusejp_1640_;
}
else
{
lean_object* v_reuseFailAlloc_1642_; 
v_reuseFailAlloc_1642_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1642_, 0, v_a_1636_);
v___x_1641_ = v_reuseFailAlloc_1642_;
goto v_reusejp_1640_;
}
v_reusejp_1640_:
{
return v___x_1641_;
}
}
}
}
else
{
lean_dec(v_a_1622_);
lean_dec(v___y_1607_);
lean_dec_ref(v___y_1606_);
lean_dec(v___y_1605_);
return v___x_1623_;
}
}
else
{
lean_object* v___x_1645_; 
lean_dec(v___y_1607_);
lean_dec_ref(v___y_1606_);
lean_dec(v___y_1605_);
lean_dec_ref(v___y_1604_);
lean_dec_ref(v_expectedType_1592_);
if (v_isShared_1618_ == 0)
{
lean_ctor_set(v___x_1617_, 0, v_a_1591_);
v___x_1645_ = v___x_1617_;
goto v_reusejp_1644_;
}
else
{
lean_object* v_reuseFailAlloc_1646_; 
v_reuseFailAlloc_1646_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1646_, 0, v_a_1591_);
v___x_1645_ = v_reuseFailAlloc_1646_;
goto v_reusejp_1644_;
}
v_reusejp_1644_:
{
return v___x_1645_;
}
}
}
}
else
{
lean_object* v_a_1648_; lean_object* v___x_1650_; uint8_t v_isShared_1651_; uint8_t v_isSharedCheck_1655_; 
lean_dec(v___y_1607_);
lean_dec_ref(v___y_1606_);
lean_dec(v___y_1605_);
lean_dec_ref(v___y_1604_);
lean_dec_ref(v_expectedType_1592_);
lean_dec_ref(v_a_1591_);
v_a_1648_ = lean_ctor_get(v___x_1614_, 0);
v_isSharedCheck_1655_ = !lean_is_exclusive(v___x_1614_);
if (v_isSharedCheck_1655_ == 0)
{
v___x_1650_ = v___x_1614_;
v_isShared_1651_ = v_isSharedCheck_1655_;
goto v_resetjp_1649_;
}
else
{
lean_inc(v_a_1648_);
lean_dec(v___x_1614_);
v___x_1650_ = lean_box(0);
v_isShared_1651_ = v_isSharedCheck_1655_;
goto v_resetjp_1649_;
}
v_resetjp_1649_:
{
lean_object* v___x_1653_; 
if (v_isShared_1651_ == 0)
{
v___x_1653_ = v___x_1650_;
goto v_reusejp_1652_;
}
else
{
lean_object* v_reuseFailAlloc_1654_; 
v_reuseFailAlloc_1654_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1654_, 0, v_a_1648_);
v___x_1653_ = v_reuseFailAlloc_1654_;
goto v_reusejp_1652_;
}
v_reusejp_1652_:
{
return v___x_1653_;
}
}
}
}
else
{
lean_dec(v___y_1607_);
lean_dec_ref(v___y_1606_);
lean_dec(v___y_1605_);
lean_dec_ref(v___y_1604_);
lean_dec_ref(v_expectedType_1592_);
lean_dec_ref(v_a_1591_);
return v___x_1612_;
}
}
}
}
}
static uint64_t _init_l_Lean_Meta_normalizeInstance___closed__0(void){
_start:
{
uint8_t v___x_1810_; uint64_t v___x_1811_; 
v___x_1810_ = 3;
v___x_1811_ = l_Lean_Meta_TransparencyMode_toUInt64(v___x_1810_);
return v___x_1811_;
}
}
static lean_object* _init_l_Lean_Meta_normalizeInstance___closed__2(void){
_start:
{
lean_object* v___x_1813_; lean_object* v___x_1814_; 
v___x_1813_ = ((lean_object*)(l_Lean_Meta_normalizeInstance___closed__1));
v___x_1814_ = l_Lean_stringToMessageData(v___x_1813_);
return v___x_1814_;
}
}
static double _init_l_Lean_Meta_normalizeInstance___closed__3(void){
_start:
{
lean_object* v___x_1815_; double v___x_1816_; 
v___x_1815_ = lean_unsigned_to_nat(1000000000u);
v___x_1816_ = lean_float_of_nat(v___x_1815_);
return v___x_1816_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg(lean_object* v_upperBound_1817_, lean_object* v_fst_1818_, lean_object* v_args_1819_, uint8_t v_compile_1820_, uint8_t v___x_1821_, lean_object* v_a_1822_, lean_object* v_b_1823_, lean_object* v___y_1824_, lean_object* v___y_1825_, lean_object* v___y_1826_, lean_object* v___y_1827_){
_start:
{
lean_object* v_a_1830_; uint8_t v___x_1834_; 
v___x_1834_ = lean_nat_dec_lt(v_a_1822_, v_upperBound_1817_);
if (v___x_1834_ == 0)
{
lean_object* v___x_1835_; 
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v___x_1835_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1835_, 0, v_b_1823_);
return v___x_1835_;
}
else
{
lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; 
v___x_1836_ = lean_array_fget_borrowed(v_fst_1818_, v_a_1822_);
v___x_1837_ = l_Lean_Expr_mvarId_x21(v___x_1836_);
lean_inc(v___x_1837_);
v___x_1838_ = l_Lean_MVarId_getDecl(v___x_1837_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1838_) == 0)
{
lean_object* v_a_1839_; lean_object* v_type_1840_; lean_object* v___x_1841_; 
v_a_1839_ = lean_ctor_get(v___x_1838_, 0);
lean_inc(v_a_1839_);
lean_dec_ref(v___x_1838_);
v_type_1840_ = lean_ctor_get(v_a_1839_, 2);
lean_inc_ref(v_type_1840_);
lean_dec(v_a_1839_);
v___x_1841_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_type_1840_, v___y_1825_);
if (lean_obj_tag(v___x_1841_) == 0)
{
lean_object* v_a_1842_; lean_object* v___x_1843_; 
v_a_1842_ = lean_ctor_get(v___x_1841_, 0);
lean_inc(v_a_1842_);
lean_dec_ref(v___x_1841_);
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v_a_1842_);
v___x_1843_ = l_Lean_Meta_isProp(v_a_1842_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1843_) == 0)
{
lean_object* v_a_1844_; lean_object* v___x_1845_; lean_object* v___x_1846_; uint8_t v___x_1847_; 
v_a_1844_ = lean_ctor_get(v___x_1843_, 0);
lean_inc(v_a_1844_);
lean_dec_ref(v___x_1843_);
v___x_1845_ = lean_box(0);
v___x_1846_ = lean_array_fget_borrowed(v_args_1819_, v_a_1822_);
v___x_1847_ = lean_unbox(v_a_1844_);
lean_dec(v_a_1844_);
if (v___x_1847_ == 0)
{
lean_object* v___x_1848_; 
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v_a_1842_);
v___x_1848_ = l_Lean_Meta_isClass_x3f(v_a_1842_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1848_) == 0)
{
lean_object* v_a_1849_; 
v_a_1849_ = lean_ctor_get(v___x_1848_, 0);
lean_inc(v_a_1849_);
lean_dec_ref(v___x_1848_);
if (lean_obj_tag(v_a_1849_) == 0)
{
goto v___jp_1850_;
}
else
{
lean_dec_ref(v_a_1849_);
if (v___x_1821_ == 0)
{
goto v___jp_1850_;
}
else
{
lean_object* v___x_1901_; 
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v___x_1846_);
v___x_1901_ = l_Lean_Meta_normalizeInstance(v___x_1846_, v_a_1842_, v_compile_1820_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1901_) == 0)
{
lean_object* v_a_1902_; lean_object* v___x_1903_; 
v_a_1902_ = lean_ctor_get(v___x_1901_, 0);
lean_inc(v_a_1902_);
lean_dec_ref(v___x_1901_);
v___x_1903_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v_a_1902_, v___y_1825_);
if (lean_obj_tag(v___x_1903_) == 0)
{
lean_dec_ref(v___x_1903_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1903_;
}
}
else
{
lean_object* v_a_1904_; lean_object* v___x_1906_; uint8_t v_isShared_1907_; uint8_t v_isSharedCheck_1911_; 
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1904_ = lean_ctor_get(v___x_1901_, 0);
v_isSharedCheck_1911_ = !lean_is_exclusive(v___x_1901_);
if (v_isSharedCheck_1911_ == 0)
{
v___x_1906_ = v___x_1901_;
v_isShared_1907_ = v_isSharedCheck_1911_;
goto v_resetjp_1905_;
}
else
{
lean_inc(v_a_1904_);
lean_dec(v___x_1901_);
v___x_1906_ = lean_box(0);
v_isShared_1907_ = v_isSharedCheck_1911_;
goto v_resetjp_1905_;
}
v_resetjp_1905_:
{
lean_object* v___x_1909_; 
if (v_isShared_1907_ == 0)
{
v___x_1909_ = v___x_1906_;
goto v_reusejp_1908_;
}
else
{
lean_object* v_reuseFailAlloc_1910_; 
v_reuseFailAlloc_1910_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1910_, 0, v_a_1904_);
v___x_1909_ = v_reuseFailAlloc_1910_;
goto v_reusejp_1908_;
}
v_reusejp_1908_:
{
return v___x_1909_;
}
}
}
}
}
v___jp_1850_:
{
lean_object* v_options_1851_; lean_object* v___x_1852_; uint8_t v___x_1853_; 
v_options_1851_ = lean_ctor_get(v___y_1826_, 2);
v___x_1852_ = l_Lean_Meta_instance_normalForm_wrapFields_data;
v___x_1853_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1851_, v___x_1852_);
if (v___x_1853_ == 0)
{
lean_object* v___x_1854_; 
lean_dec(v_a_1842_);
lean_inc(v___x_1846_);
v___x_1854_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v___x_1846_, v___y_1825_);
if (lean_obj_tag(v___x_1854_) == 0)
{
lean_dec_ref(v___x_1854_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1854_;
}
}
else
{
lean_object* v___x_1855_; 
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v___x_1846_);
v___x_1855_ = lean_infer_type(v___x_1846_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1855_) == 0)
{
lean_object* v_a_1856_; lean_object* v___x_1857_; 
v_a_1856_ = lean_ctor_get(v___x_1855_, 0);
lean_inc(v_a_1856_);
lean_dec_ref(v___x_1855_);
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v_a_1842_);
v___x_1857_ = l_Lean_Meta_isExprDefEq(v_a_1842_, v_a_1856_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1857_) == 0)
{
lean_object* v_a_1858_; uint8_t v___x_1859_; 
v_a_1858_ = lean_ctor_get(v___x_1857_, 0);
lean_inc(v_a_1858_);
lean_dec_ref(v___x_1857_);
v___x_1859_ = lean_unbox(v_a_1858_);
if (v___x_1859_ == 0)
{
lean_object* v___x_1860_; lean_object* v___x_1861_; 
v___x_1860_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_1861_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_1860_, v___y_1827_);
if (lean_obj_tag(v___x_1861_) == 0)
{
lean_object* v_a_1862_; uint8_t v___x_1863_; lean_object* v___x_1864_; 
v_a_1862_ = lean_ctor_get(v___x_1861_, 0);
lean_inc(v_a_1862_);
lean_dec_ref(v___x_1861_);
v___x_1863_ = lean_unbox(v_a_1858_);
lean_dec(v_a_1858_);
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v___x_1846_);
lean_inc(v_a_1862_);
v___x_1864_ = l_Lean_Meta_mkAuxDefinition(v_a_1862_, v_a_1842_, v___x_1846_, v___x_1863_, v_compile_1820_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1864_) == 0)
{
lean_object* v_a_1865_; lean_object* v___x_1866_; 
v_a_1865_ = lean_ctor_get(v___x_1864_, 0);
lean_inc(v_a_1865_);
lean_dec_ref(v___x_1864_);
v___x_1866_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v_a_1865_, v___y_1825_);
if (lean_obj_tag(v___x_1866_) == 0)
{
lean_object* v___x_1867_; 
lean_dec_ref(v___x_1866_);
lean_inc_ref(v___y_1826_);
v___x_1867_ = l_Lean_enableRealizationsForConst(v_a_1862_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1867_) == 0)
{
lean_dec_ref(v___x_1867_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1867_;
}
}
else
{
lean_dec(v_a_1862_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1866_;
}
}
else
{
lean_object* v_a_1868_; lean_object* v___x_1870_; uint8_t v_isShared_1871_; uint8_t v_isSharedCheck_1875_; 
lean_dec(v_a_1862_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1868_ = lean_ctor_get(v___x_1864_, 0);
v_isSharedCheck_1875_ = !lean_is_exclusive(v___x_1864_);
if (v_isSharedCheck_1875_ == 0)
{
v___x_1870_ = v___x_1864_;
v_isShared_1871_ = v_isSharedCheck_1875_;
goto v_resetjp_1869_;
}
else
{
lean_inc(v_a_1868_);
lean_dec(v___x_1864_);
v___x_1870_ = lean_box(0);
v_isShared_1871_ = v_isSharedCheck_1875_;
goto v_resetjp_1869_;
}
v_resetjp_1869_:
{
lean_object* v___x_1873_; 
if (v_isShared_1871_ == 0)
{
v___x_1873_ = v___x_1870_;
goto v_reusejp_1872_;
}
else
{
lean_object* v_reuseFailAlloc_1874_; 
v_reuseFailAlloc_1874_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1874_, 0, v_a_1868_);
v___x_1873_ = v_reuseFailAlloc_1874_;
goto v_reusejp_1872_;
}
v_reusejp_1872_:
{
return v___x_1873_;
}
}
}
}
else
{
lean_object* v_a_1876_; lean_object* v___x_1878_; uint8_t v_isShared_1879_; uint8_t v_isSharedCheck_1883_; 
lean_dec(v_a_1858_);
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1876_ = lean_ctor_get(v___x_1861_, 0);
v_isSharedCheck_1883_ = !lean_is_exclusive(v___x_1861_);
if (v_isSharedCheck_1883_ == 0)
{
v___x_1878_ = v___x_1861_;
v_isShared_1879_ = v_isSharedCheck_1883_;
goto v_resetjp_1877_;
}
else
{
lean_inc(v_a_1876_);
lean_dec(v___x_1861_);
v___x_1878_ = lean_box(0);
v_isShared_1879_ = v_isSharedCheck_1883_;
goto v_resetjp_1877_;
}
v_resetjp_1877_:
{
lean_object* v___x_1881_; 
if (v_isShared_1879_ == 0)
{
v___x_1881_ = v___x_1878_;
goto v_reusejp_1880_;
}
else
{
lean_object* v_reuseFailAlloc_1882_; 
v_reuseFailAlloc_1882_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1882_, 0, v_a_1876_);
v___x_1881_ = v_reuseFailAlloc_1882_;
goto v_reusejp_1880_;
}
v_reusejp_1880_:
{
return v___x_1881_;
}
}
}
}
else
{
lean_object* v___x_1884_; 
lean_dec(v_a_1858_);
lean_dec(v_a_1842_);
lean_inc(v___x_1846_);
v___x_1884_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v___x_1846_, v___y_1825_);
if (lean_obj_tag(v___x_1884_) == 0)
{
lean_dec_ref(v___x_1884_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1884_;
}
}
}
else
{
lean_object* v_a_1885_; lean_object* v___x_1887_; uint8_t v_isShared_1888_; uint8_t v_isSharedCheck_1892_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1885_ = lean_ctor_get(v___x_1857_, 0);
v_isSharedCheck_1892_ = !lean_is_exclusive(v___x_1857_);
if (v_isSharedCheck_1892_ == 0)
{
v___x_1887_ = v___x_1857_;
v_isShared_1888_ = v_isSharedCheck_1892_;
goto v_resetjp_1886_;
}
else
{
lean_inc(v_a_1885_);
lean_dec(v___x_1857_);
v___x_1887_ = lean_box(0);
v_isShared_1888_ = v_isSharedCheck_1892_;
goto v_resetjp_1886_;
}
v_resetjp_1886_:
{
lean_object* v___x_1890_; 
if (v_isShared_1888_ == 0)
{
v___x_1890_ = v___x_1887_;
goto v_reusejp_1889_;
}
else
{
lean_object* v_reuseFailAlloc_1891_; 
v_reuseFailAlloc_1891_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1891_, 0, v_a_1885_);
v___x_1890_ = v_reuseFailAlloc_1891_;
goto v_reusejp_1889_;
}
v_reusejp_1889_:
{
return v___x_1890_;
}
}
}
}
else
{
lean_object* v_a_1893_; lean_object* v___x_1895_; uint8_t v_isShared_1896_; uint8_t v_isSharedCheck_1900_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1893_ = lean_ctor_get(v___x_1855_, 0);
v_isSharedCheck_1900_ = !lean_is_exclusive(v___x_1855_);
if (v_isSharedCheck_1900_ == 0)
{
v___x_1895_ = v___x_1855_;
v_isShared_1896_ = v_isSharedCheck_1900_;
goto v_resetjp_1894_;
}
else
{
lean_inc(v_a_1893_);
lean_dec(v___x_1855_);
v___x_1895_ = lean_box(0);
v_isShared_1896_ = v_isSharedCheck_1900_;
goto v_resetjp_1894_;
}
v_resetjp_1894_:
{
lean_object* v___x_1898_; 
if (v_isShared_1896_ == 0)
{
v___x_1898_ = v___x_1895_;
goto v_reusejp_1897_;
}
else
{
lean_object* v_reuseFailAlloc_1899_; 
v_reuseFailAlloc_1899_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1899_, 0, v_a_1893_);
v___x_1898_ = v_reuseFailAlloc_1899_;
goto v_reusejp_1897_;
}
v_reusejp_1897_:
{
return v___x_1898_;
}
}
}
}
}
}
else
{
lean_object* v_a_1912_; lean_object* v___x_1914_; uint8_t v_isShared_1915_; uint8_t v_isSharedCheck_1919_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1912_ = lean_ctor_get(v___x_1848_, 0);
v_isSharedCheck_1919_ = !lean_is_exclusive(v___x_1848_);
if (v_isSharedCheck_1919_ == 0)
{
v___x_1914_ = v___x_1848_;
v_isShared_1915_ = v_isSharedCheck_1919_;
goto v_resetjp_1913_;
}
else
{
lean_inc(v_a_1912_);
lean_dec(v___x_1848_);
v___x_1914_ = lean_box(0);
v_isShared_1915_ = v_isSharedCheck_1919_;
goto v_resetjp_1913_;
}
v_resetjp_1913_:
{
lean_object* v___x_1917_; 
if (v_isShared_1915_ == 0)
{
v___x_1917_ = v___x_1914_;
goto v_reusejp_1916_;
}
else
{
lean_object* v_reuseFailAlloc_1918_; 
v_reuseFailAlloc_1918_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1918_, 0, v_a_1912_);
v___x_1917_ = v_reuseFailAlloc_1918_;
goto v_reusejp_1916_;
}
v_reusejp_1916_:
{
return v___x_1917_;
}
}
}
}
else
{
lean_object* v_options_1920_; lean_object* v___x_1921_; uint8_t v___x_1922_; 
v_options_1920_ = lean_ctor_get(v___y_1826_, 2);
v___x_1921_ = l_Lean_Meta_instance_normalForm_wrapFields_proofs;
v___x_1922_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1920_, v___x_1921_);
if (v___x_1922_ == 0)
{
lean_object* v___x_1923_; 
lean_dec(v_a_1842_);
lean_inc(v___x_1846_);
v___x_1923_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v___x_1846_, v___y_1825_);
if (lean_obj_tag(v___x_1923_) == 0)
{
lean_dec_ref(v___x_1923_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1923_;
}
}
else
{
lean_object* v___x_1924_; 
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v___x_1846_);
v___x_1924_ = lean_infer_type(v___x_1846_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1924_) == 0)
{
lean_object* v_a_1925_; lean_object* v___x_1926_; 
v_a_1925_ = lean_ctor_get(v___x_1924_, 0);
lean_inc(v_a_1925_);
lean_dec_ref(v___x_1924_);
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v_a_1842_);
v___x_1926_ = l_Lean_Meta_isExprDefEq(v_a_1842_, v_a_1925_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1926_) == 0)
{
lean_object* v_a_1927_; uint8_t v___x_1928_; 
v_a_1927_ = lean_ctor_get(v___x_1926_, 0);
lean_inc(v_a_1927_);
lean_dec_ref(v___x_1926_);
v___x_1928_ = lean_unbox(v_a_1927_);
lean_dec(v_a_1927_);
if (v___x_1928_ == 0)
{
lean_object* v___x_1929_; lean_object* v___x_1930_; 
v___x_1929_ = lean_box(0);
lean_inc(v___y_1827_);
lean_inc_ref(v___y_1826_);
lean_inc(v___y_1825_);
lean_inc_ref(v___y_1824_);
lean_inc(v___x_1846_);
v___x_1930_ = l_Lean_Meta_mkAuxTheorem(v_a_1842_, v___x_1846_, v___x_1821_, v___x_1929_, v___x_1821_, v___y_1824_, v___y_1825_, v___y_1826_, v___y_1827_);
if (lean_obj_tag(v___x_1930_) == 0)
{
lean_object* v_a_1931_; lean_object* v___x_1932_; 
v_a_1931_ = lean_ctor_get(v___x_1930_, 0);
lean_inc(v_a_1931_);
lean_dec_ref(v___x_1930_);
v___x_1932_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v_a_1931_, v___y_1825_);
if (lean_obj_tag(v___x_1932_) == 0)
{
lean_dec_ref(v___x_1932_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1932_;
}
}
else
{
lean_object* v_a_1933_; lean_object* v___x_1935_; uint8_t v_isShared_1936_; uint8_t v_isSharedCheck_1940_; 
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1933_ = lean_ctor_get(v___x_1930_, 0);
v_isSharedCheck_1940_ = !lean_is_exclusive(v___x_1930_);
if (v_isSharedCheck_1940_ == 0)
{
v___x_1935_ = v___x_1930_;
v_isShared_1936_ = v_isSharedCheck_1940_;
goto v_resetjp_1934_;
}
else
{
lean_inc(v_a_1933_);
lean_dec(v___x_1930_);
v___x_1935_ = lean_box(0);
v_isShared_1936_ = v_isSharedCheck_1940_;
goto v_resetjp_1934_;
}
v_resetjp_1934_:
{
lean_object* v___x_1938_; 
if (v_isShared_1936_ == 0)
{
v___x_1938_ = v___x_1935_;
goto v_reusejp_1937_;
}
else
{
lean_object* v_reuseFailAlloc_1939_; 
v_reuseFailAlloc_1939_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1939_, 0, v_a_1933_);
v___x_1938_ = v_reuseFailAlloc_1939_;
goto v_reusejp_1937_;
}
v_reusejp_1937_:
{
return v___x_1938_;
}
}
}
}
else
{
lean_object* v___x_1941_; 
lean_dec(v_a_1842_);
lean_inc(v___x_1846_);
v___x_1941_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_1837_, v___x_1846_, v___y_1825_);
if (lean_obj_tag(v___x_1941_) == 0)
{
lean_dec_ref(v___x_1941_);
v_a_1830_ = v___x_1845_;
goto v___jp_1829_;
}
else
{
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
return v___x_1941_;
}
}
}
else
{
lean_object* v_a_1942_; lean_object* v___x_1944_; uint8_t v_isShared_1945_; uint8_t v_isSharedCheck_1949_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1942_ = lean_ctor_get(v___x_1926_, 0);
v_isSharedCheck_1949_ = !lean_is_exclusive(v___x_1926_);
if (v_isSharedCheck_1949_ == 0)
{
v___x_1944_ = v___x_1926_;
v_isShared_1945_ = v_isSharedCheck_1949_;
goto v_resetjp_1943_;
}
else
{
lean_inc(v_a_1942_);
lean_dec(v___x_1926_);
v___x_1944_ = lean_box(0);
v_isShared_1945_ = v_isSharedCheck_1949_;
goto v_resetjp_1943_;
}
v_resetjp_1943_:
{
lean_object* v___x_1947_; 
if (v_isShared_1945_ == 0)
{
v___x_1947_ = v___x_1944_;
goto v_reusejp_1946_;
}
else
{
lean_object* v_reuseFailAlloc_1948_; 
v_reuseFailAlloc_1948_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1948_, 0, v_a_1942_);
v___x_1947_ = v_reuseFailAlloc_1948_;
goto v_reusejp_1946_;
}
v_reusejp_1946_:
{
return v___x_1947_;
}
}
}
}
else
{
lean_object* v_a_1950_; lean_object* v___x_1952_; uint8_t v_isShared_1953_; uint8_t v_isSharedCheck_1957_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1950_ = lean_ctor_get(v___x_1924_, 0);
v_isSharedCheck_1957_ = !lean_is_exclusive(v___x_1924_);
if (v_isSharedCheck_1957_ == 0)
{
v___x_1952_ = v___x_1924_;
v_isShared_1953_ = v_isSharedCheck_1957_;
goto v_resetjp_1951_;
}
else
{
lean_inc(v_a_1950_);
lean_dec(v___x_1924_);
v___x_1952_ = lean_box(0);
v_isShared_1953_ = v_isSharedCheck_1957_;
goto v_resetjp_1951_;
}
v_resetjp_1951_:
{
lean_object* v___x_1955_; 
if (v_isShared_1953_ == 0)
{
v___x_1955_ = v___x_1952_;
goto v_reusejp_1954_;
}
else
{
lean_object* v_reuseFailAlloc_1956_; 
v_reuseFailAlloc_1956_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1956_, 0, v_a_1950_);
v___x_1955_ = v_reuseFailAlloc_1956_;
goto v_reusejp_1954_;
}
v_reusejp_1954_:
{
return v___x_1955_;
}
}
}
}
}
}
else
{
lean_object* v_a_1958_; lean_object* v___x_1960_; uint8_t v_isShared_1961_; uint8_t v_isSharedCheck_1965_; 
lean_dec(v_a_1842_);
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1958_ = lean_ctor_get(v___x_1843_, 0);
v_isSharedCheck_1965_ = !lean_is_exclusive(v___x_1843_);
if (v_isSharedCheck_1965_ == 0)
{
v___x_1960_ = v___x_1843_;
v_isShared_1961_ = v_isSharedCheck_1965_;
goto v_resetjp_1959_;
}
else
{
lean_inc(v_a_1958_);
lean_dec(v___x_1843_);
v___x_1960_ = lean_box(0);
v_isShared_1961_ = v_isSharedCheck_1965_;
goto v_resetjp_1959_;
}
v_resetjp_1959_:
{
lean_object* v___x_1963_; 
if (v_isShared_1961_ == 0)
{
v___x_1963_ = v___x_1960_;
goto v_reusejp_1962_;
}
else
{
lean_object* v_reuseFailAlloc_1964_; 
v_reuseFailAlloc_1964_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1964_, 0, v_a_1958_);
v___x_1963_ = v_reuseFailAlloc_1964_;
goto v_reusejp_1962_;
}
v_reusejp_1962_:
{
return v___x_1963_;
}
}
}
}
else
{
lean_object* v_a_1966_; lean_object* v___x_1968_; uint8_t v_isShared_1969_; uint8_t v_isSharedCheck_1973_; 
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1966_ = lean_ctor_get(v___x_1841_, 0);
v_isSharedCheck_1973_ = !lean_is_exclusive(v___x_1841_);
if (v_isSharedCheck_1973_ == 0)
{
v___x_1968_ = v___x_1841_;
v_isShared_1969_ = v_isSharedCheck_1973_;
goto v_resetjp_1967_;
}
else
{
lean_inc(v_a_1966_);
lean_dec(v___x_1841_);
v___x_1968_ = lean_box(0);
v_isShared_1969_ = v_isSharedCheck_1973_;
goto v_resetjp_1967_;
}
v_resetjp_1967_:
{
lean_object* v___x_1971_; 
if (v_isShared_1969_ == 0)
{
v___x_1971_ = v___x_1968_;
goto v_reusejp_1970_;
}
else
{
lean_object* v_reuseFailAlloc_1972_; 
v_reuseFailAlloc_1972_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1972_, 0, v_a_1966_);
v___x_1971_ = v_reuseFailAlloc_1972_;
goto v_reusejp_1970_;
}
v_reusejp_1970_:
{
return v___x_1971_;
}
}
}
}
else
{
lean_object* v_a_1974_; lean_object* v___x_1976_; uint8_t v_isShared_1977_; uint8_t v_isSharedCheck_1981_; 
lean_dec(v___x_1837_);
lean_dec(v___y_1827_);
lean_dec_ref(v___y_1826_);
lean_dec(v___y_1825_);
lean_dec_ref(v___y_1824_);
lean_dec(v_a_1822_);
v_a_1974_ = lean_ctor_get(v___x_1838_, 0);
v_isSharedCheck_1981_ = !lean_is_exclusive(v___x_1838_);
if (v_isSharedCheck_1981_ == 0)
{
v___x_1976_ = v___x_1838_;
v_isShared_1977_ = v_isSharedCheck_1981_;
goto v_resetjp_1975_;
}
else
{
lean_inc(v_a_1974_);
lean_dec(v___x_1838_);
v___x_1976_ = lean_box(0);
v_isShared_1977_ = v_isSharedCheck_1981_;
goto v_resetjp_1975_;
}
v_resetjp_1975_:
{
lean_object* v___x_1979_; 
if (v_isShared_1977_ == 0)
{
v___x_1979_ = v___x_1976_;
goto v_reusejp_1978_;
}
else
{
lean_object* v_reuseFailAlloc_1980_; 
v_reuseFailAlloc_1980_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1980_, 0, v_a_1974_);
v___x_1979_ = v_reuseFailAlloc_1980_;
goto v_reusejp_1978_;
}
v_reusejp_1978_:
{
return v___x_1979_;
}
}
}
}
v___jp_1829_:
{
lean_object* v___x_1831_; lean_object* v___x_1832_; 
v___x_1831_ = lean_unsigned_to_nat(1u);
v___x_1832_ = lean_nat_add(v_a_1822_, v___x_1831_);
lean_dec(v_a_1822_);
v_a_1822_ = v___x_1832_;
v_b_1823_ = v_a_1830_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17(lean_object* v_a_1982_, lean_object* v_expectedType_1983_, uint8_t v_compile_1984_, uint8_t v___x_1985_, lean_object* v_x_1986_, lean_object* v_x_1987_, lean_object* v_x_1988_, lean_object* v___y_1989_, lean_object* v___y_1990_, lean_object* v___y_1991_, lean_object* v___y_1992_){
_start:
{
lean_object* v___y_1995_; lean_object* v___y_1996_; lean_object* v___y_1997_; lean_object* v___y_1998_; 
if (lean_obj_tag(v_x_1986_) == 5)
{
lean_object* v_fn_2048_; lean_object* v_arg_2049_; lean_object* v___x_2050_; lean_object* v___x_2051_; lean_object* v___x_2052_; 
v_fn_2048_ = lean_ctor_get(v_x_1986_, 0);
lean_inc_ref(v_fn_2048_);
v_arg_2049_ = lean_ctor_get(v_x_1986_, 1);
lean_inc_ref(v_arg_2049_);
lean_dec_ref(v_x_1986_);
v___x_2050_ = lean_array_set(v_x_1987_, v_x_1988_, v_arg_2049_);
v___x_2051_ = lean_unsigned_to_nat(1u);
v___x_2052_ = lean_nat_sub(v_x_1988_, v___x_2051_);
lean_dec(v_x_1988_);
v_x_1986_ = v_fn_2048_;
v_x_1987_ = v___x_2050_;
v_x_1988_ = v___x_2052_;
goto _start;
}
else
{
lean_object* v_cls_2054_; lean_object* v___y_2056_; lean_object* v___y_2057_; lean_object* v___y_2058_; lean_object* v___y_2059_; lean_object* v___x_2075_; 
lean_dec(v_x_1988_);
v_cls_2054_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_2075_ = l_Lean_Expr_constName_x3f(v_x_1986_);
if (lean_obj_tag(v___x_2075_) == 0)
{
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
v___y_2056_ = v___y_1989_;
v___y_2057_ = v___y_1990_;
v___y_2058_ = v___y_1991_;
v___y_2059_ = v___y_1992_;
goto v___jp_2055_;
}
else
{
lean_object* v_val_2076_; lean_object* v___x_2077_; 
v_val_2076_ = lean_ctor_get(v___x_2075_, 0);
lean_inc(v_val_2076_);
lean_dec_ref(v___x_2075_);
lean_inc_ref(v___y_1991_);
v___x_2077_ = l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(v_val_2076_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
if (lean_obj_tag(v___x_2077_) == 0)
{
lean_object* v_a_2078_; 
v_a_2078_ = lean_ctor_get(v___x_2077_, 0);
lean_inc(v_a_2078_);
lean_dec_ref(v___x_2077_);
if (lean_obj_tag(v_a_2078_) == 6)
{
lean_object* v_val_2079_; lean_object* v___x_2080_; 
lean_dec_ref(v_a_1982_);
v_val_2079_ = lean_ctor_get(v_a_2078_, 0);
lean_inc_ref(v_val_2079_);
lean_dec_ref(v_a_2078_);
lean_inc(v___y_1992_);
lean_inc_ref(v___y_1991_);
lean_inc(v___y_1990_);
lean_inc_ref(v___y_1989_);
lean_inc_ref(v_x_1986_);
v___x_2080_ = lean_infer_type(v_x_1986_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
if (lean_obj_tag(v___x_2080_) == 0)
{
lean_object* v_a_2081_; uint8_t v___x_2082_; lean_object* v___x_2083_; 
v_a_2081_ = lean_ctor_get(v___x_2080_, 0);
lean_inc(v_a_2081_);
lean_dec_ref(v___x_2080_);
v___x_2082_ = 0;
lean_inc(v___y_1992_);
lean_inc_ref(v___y_1991_);
lean_inc(v___y_1990_);
lean_inc_ref(v___y_1989_);
v___x_2083_ = l_Lean_Meta_forallMetaTelescope(v_a_2081_, v___x_2082_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
if (lean_obj_tag(v___x_2083_) == 0)
{
lean_object* v_a_2084_; lean_object* v_snd_2085_; lean_object* v_fst_2086_; lean_object* v___x_2088_; uint8_t v_isShared_2089_; uint8_t v_isSharedCheck_2186_; 
v_a_2084_ = lean_ctor_get(v___x_2083_, 0);
lean_inc(v_a_2084_);
lean_dec_ref(v___x_2083_);
v_snd_2085_ = lean_ctor_get(v_a_2084_, 1);
v_fst_2086_ = lean_ctor_get(v_a_2084_, 0);
v_isSharedCheck_2186_ = !lean_is_exclusive(v_a_2084_);
if (v_isSharedCheck_2186_ == 0)
{
v___x_2088_ = v_a_2084_;
v_isShared_2089_ = v_isSharedCheck_2186_;
goto v_resetjp_2087_;
}
else
{
lean_inc(v_snd_2085_);
lean_inc(v_fst_2086_);
lean_dec(v_a_2084_);
v___x_2088_ = lean_box(0);
v_isShared_2089_ = v_isSharedCheck_2186_;
goto v_resetjp_2087_;
}
v_resetjp_2087_:
{
lean_object* v_snd_2090_; lean_object* v___x_2092_; uint8_t v_isShared_2093_; uint8_t v_isSharedCheck_2184_; 
v_snd_2090_ = lean_ctor_get(v_snd_2085_, 1);
v_isSharedCheck_2184_ = !lean_is_exclusive(v_snd_2085_);
if (v_isSharedCheck_2184_ == 0)
{
lean_object* v_unused_2185_; 
v_unused_2185_ = lean_ctor_get(v_snd_2085_, 0);
lean_dec(v_unused_2185_);
v___x_2092_ = v_snd_2085_;
v_isShared_2093_ = v_isSharedCheck_2184_;
goto v_resetjp_2091_;
}
else
{
lean_inc(v_snd_2090_);
lean_dec(v_snd_2085_);
v___x_2092_ = lean_box(0);
v_isShared_2093_ = v_isSharedCheck_2184_;
goto v_resetjp_2091_;
}
v_resetjp_2091_:
{
lean_object* v___x_2094_; lean_object* v___y_2096_; lean_object* v___y_2097_; lean_object* v___y_2098_; lean_object* v___y_2099_; lean_object* v___x_2131_; uint8_t v___x_2132_; 
v___x_2094_ = lean_array_get_size(v_x_1987_);
v___x_2131_ = lean_array_get_size(v_fst_2086_);
v___x_2132_ = lean_nat_dec_eq(v___x_2094_, v___x_2131_);
if (v___x_2132_ == 0)
{
lean_object* v___x_2133_; lean_object* v___x_2134_; lean_object* v___x_2136_; 
lean_dec(v_snd_2090_);
lean_dec(v_fst_2086_);
lean_dec_ref(v_val_2079_);
lean_dec_ref(v_expectedType_1983_);
v___x_2133_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3);
v___x_2134_ = l_Lean_MessageData_ofExpr(v_x_1986_);
if (v_isShared_2093_ == 0)
{
lean_ctor_set_tag(v___x_2092_, 7);
lean_ctor_set(v___x_2092_, 1, v___x_2134_);
lean_ctor_set(v___x_2092_, 0, v___x_2133_);
v___x_2136_ = v___x_2092_;
goto v_reusejp_2135_;
}
else
{
lean_object* v_reuseFailAlloc_2147_; 
v_reuseFailAlloc_2147_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2147_, 0, v___x_2133_);
lean_ctor_set(v_reuseFailAlloc_2147_, 1, v___x_2134_);
v___x_2136_ = v_reuseFailAlloc_2147_;
goto v_reusejp_2135_;
}
v_reusejp_2135_:
{
lean_object* v___x_2137_; lean_object* v___x_2139_; 
v___x_2137_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5);
if (v_isShared_2089_ == 0)
{
lean_ctor_set_tag(v___x_2088_, 7);
lean_ctor_set(v___x_2088_, 1, v___x_2137_);
lean_ctor_set(v___x_2088_, 0, v___x_2136_);
v___x_2139_ = v___x_2088_;
goto v_reusejp_2138_;
}
else
{
lean_object* v_reuseFailAlloc_2146_; 
v_reuseFailAlloc_2146_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2146_, 0, v___x_2136_);
lean_ctor_set(v_reuseFailAlloc_2146_, 1, v___x_2137_);
v___x_2139_ = v_reuseFailAlloc_2146_;
goto v_reusejp_2138_;
}
v_reusejp_2138_:
{
lean_object* v___x_2140_; lean_object* v___x_2141_; lean_object* v___x_2142_; lean_object* v___x_2143_; lean_object* v___x_2144_; lean_object* v___x_2145_; 
v___x_2140_ = lean_array_to_list(v_x_1987_);
v___x_2141_ = lean_box(0);
v___x_2142_ = l_List_mapTR_loop___at___00Lean_Meta_normalizeInstance_spec__11(v___x_2140_, v___x_2141_);
v___x_2143_ = l_Lean_MessageData_ofList(v___x_2142_);
v___x_2144_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2144_, 0, v___x_2139_);
lean_ctor_set(v___x_2144_, 1, v___x_2143_);
v___x_2145_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_2144_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
return v___x_2145_;
}
}
}
else
{
lean_object* v___x_2148_; 
lean_inc(v___y_1992_);
lean_inc_ref(v___y_1991_);
lean_inc(v___y_1990_);
lean_inc_ref(v___y_1989_);
lean_inc_ref(v_expectedType_1983_);
v___x_2148_ = l_Lean_Meta_isExprDefEq(v_expectedType_1983_, v_snd_2090_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
if (lean_obj_tag(v___x_2148_) == 0)
{
lean_object* v_a_2149_; uint8_t v___x_2150_; 
v_a_2149_ = lean_ctor_get(v___x_2148_, 0);
lean_inc(v_a_2149_);
lean_dec_ref(v___x_2148_);
v___x_2150_ = lean_unbox(v_a_2149_);
if (v___x_2150_ == 0)
{
lean_object* v_toConstantVal_2151_; lean_object* v_name_2152_; lean_object* v___x_2153_; lean_object* v___x_2154_; lean_object* v___x_2156_; 
lean_dec(v_fst_2086_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
v_toConstantVal_2151_ = lean_ctor_get(v_val_2079_, 0);
lean_inc_ref(v_toConstantVal_2151_);
lean_dec_ref(v_val_2079_);
v_name_2152_ = lean_ctor_get(v_toConstantVal_2151_, 0);
lean_inc(v_name_2152_);
lean_dec_ref(v_toConstantVal_2151_);
v___x_2153_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7);
v___x_2154_ = l_Lean_MessageData_ofExpr(v_expectedType_1983_);
if (v_isShared_2093_ == 0)
{
lean_ctor_set_tag(v___x_2092_, 7);
lean_ctor_set(v___x_2092_, 1, v___x_2154_);
lean_ctor_set(v___x_2092_, 0, v___x_2153_);
v___x_2156_ = v___x_2092_;
goto v_reusejp_2155_;
}
else
{
lean_object* v_reuseFailAlloc_2175_; 
v_reuseFailAlloc_2175_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2175_, 0, v___x_2153_);
lean_ctor_set(v_reuseFailAlloc_2175_, 1, v___x_2154_);
v___x_2156_ = v_reuseFailAlloc_2175_;
goto v_reusejp_2155_;
}
v_reusejp_2155_:
{
lean_object* v___x_2157_; lean_object* v___x_2159_; 
v___x_2157_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9);
if (v_isShared_2089_ == 0)
{
lean_ctor_set_tag(v___x_2088_, 7);
lean_ctor_set(v___x_2088_, 1, v___x_2157_);
lean_ctor_set(v___x_2088_, 0, v___x_2156_);
v___x_2159_ = v___x_2088_;
goto v_reusejp_2158_;
}
else
{
lean_object* v_reuseFailAlloc_2174_; 
v_reuseFailAlloc_2174_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2174_, 0, v___x_2156_);
lean_ctor_set(v_reuseFailAlloc_2174_, 1, v___x_2157_);
v___x_2159_ = v_reuseFailAlloc_2174_;
goto v_reusejp_2158_;
}
v_reusejp_2158_:
{
uint8_t v___x_2160_; lean_object* v___x_2161_; lean_object* v___x_2162_; lean_object* v___x_2163_; lean_object* v___x_2164_; lean_object* v___x_2165_; lean_object* v_a_2166_; lean_object* v___x_2168_; uint8_t v_isShared_2169_; uint8_t v_isSharedCheck_2173_; 
v___x_2160_ = lean_unbox(v_a_2149_);
lean_dec(v_a_2149_);
v___x_2161_ = l_Lean_MessageData_ofConstName(v_name_2152_, v___x_2160_);
v___x_2162_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2162_, 0, v___x_2159_);
lean_ctor_set(v___x_2162_, 1, v___x_2161_);
v___x_2163_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3);
v___x_2164_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2164_, 0, v___x_2162_);
lean_ctor_set(v___x_2164_, 1, v___x_2163_);
v___x_2165_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_2164_, v___y_1989_, v___y_1990_, v___y_1991_, v___y_1992_);
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
v_a_2166_ = lean_ctor_get(v___x_2165_, 0);
v_isSharedCheck_2173_ = !lean_is_exclusive(v___x_2165_);
if (v_isSharedCheck_2173_ == 0)
{
v___x_2168_ = v___x_2165_;
v_isShared_2169_ = v_isSharedCheck_2173_;
goto v_resetjp_2167_;
}
else
{
lean_inc(v_a_2166_);
lean_dec(v___x_2165_);
v___x_2168_ = lean_box(0);
v_isShared_2169_ = v_isSharedCheck_2173_;
goto v_resetjp_2167_;
}
v_resetjp_2167_:
{
lean_object* v___x_2171_; 
if (v_isShared_2169_ == 0)
{
v___x_2171_ = v___x_2168_;
goto v_reusejp_2170_;
}
else
{
lean_object* v_reuseFailAlloc_2172_; 
v_reuseFailAlloc_2172_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2172_, 0, v_a_2166_);
v___x_2171_ = v_reuseFailAlloc_2172_;
goto v_reusejp_2170_;
}
v_reusejp_2170_:
{
return v___x_2171_;
}
}
}
}
}
else
{
lean_dec(v_a_2149_);
lean_del_object(v___x_2092_);
lean_del_object(v___x_2088_);
lean_dec_ref(v_expectedType_1983_);
v___y_2096_ = v___y_1989_;
v___y_2097_ = v___y_1990_;
v___y_2098_ = v___y_1991_;
v___y_2099_ = v___y_1992_;
goto v___jp_2095_;
}
}
else
{
lean_object* v_a_2176_; lean_object* v___x_2178_; uint8_t v_isShared_2179_; uint8_t v_isSharedCheck_2183_; 
lean_del_object(v___x_2092_);
lean_del_object(v___x_2088_);
lean_dec(v_fst_2086_);
lean_dec_ref(v_val_2079_);
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
lean_dec_ref(v_expectedType_1983_);
v_a_2176_ = lean_ctor_get(v___x_2148_, 0);
v_isSharedCheck_2183_ = !lean_is_exclusive(v___x_2148_);
if (v_isSharedCheck_2183_ == 0)
{
v___x_2178_ = v___x_2148_;
v_isShared_2179_ = v_isSharedCheck_2183_;
goto v_resetjp_2177_;
}
else
{
lean_inc(v_a_2176_);
lean_dec(v___x_2148_);
v___x_2178_ = lean_box(0);
v_isShared_2179_ = v_isSharedCheck_2183_;
goto v_resetjp_2177_;
}
v_resetjp_2177_:
{
lean_object* v___x_2181_; 
if (v_isShared_2179_ == 0)
{
v___x_2181_ = v___x_2178_;
goto v_reusejp_2180_;
}
else
{
lean_object* v_reuseFailAlloc_2182_; 
v_reuseFailAlloc_2182_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2182_, 0, v_a_2176_);
v___x_2181_ = v_reuseFailAlloc_2182_;
goto v_reusejp_2180_;
}
v_reusejp_2180_:
{
return v___x_2181_;
}
}
}
}
v___jp_2095_:
{
lean_object* v_numParams_2100_; lean_object* v___x_2101_; lean_object* v___x_2102_; 
v_numParams_2100_ = lean_ctor_get(v_val_2079_, 3);
lean_inc(v_numParams_2100_);
lean_dec_ref(v_val_2079_);
v___x_2101_ = lean_box(0);
lean_inc(v___y_2099_);
lean_inc_ref(v___y_2098_);
lean_inc(v___y_2097_);
lean_inc_ref(v___y_2096_);
v___x_2102_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg(v___x_2094_, v_fst_2086_, v_x_1987_, v_compile_1984_, v___x_1985_, v_numParams_2100_, v___x_2101_, v___y_2096_, v___y_2097_, v___y_2098_, v___y_2099_);
lean_dec_ref(v_x_1987_);
if (lean_obj_tag(v___x_2102_) == 0)
{
size_t v_sz_2103_; size_t v___x_2104_; lean_object* v___x_2105_; 
lean_dec_ref(v___x_2102_);
v_sz_2103_ = lean_array_size(v_fst_2086_);
v___x_2104_ = ((size_t)0ULL);
v___x_2105_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(v_sz_2103_, v___x_2104_, v_fst_2086_, v___y_2096_, v___y_2097_, v___y_2098_, v___y_2099_);
lean_dec(v___y_2099_);
lean_dec_ref(v___y_2098_);
lean_dec(v___y_2097_);
lean_dec_ref(v___y_2096_);
if (lean_obj_tag(v___x_2105_) == 0)
{
lean_object* v_a_2106_; lean_object* v___x_2108_; uint8_t v_isShared_2109_; uint8_t v_isSharedCheck_2114_; 
v_a_2106_ = lean_ctor_get(v___x_2105_, 0);
v_isSharedCheck_2114_ = !lean_is_exclusive(v___x_2105_);
if (v_isSharedCheck_2114_ == 0)
{
v___x_2108_ = v___x_2105_;
v_isShared_2109_ = v_isSharedCheck_2114_;
goto v_resetjp_2107_;
}
else
{
lean_inc(v_a_2106_);
lean_dec(v___x_2105_);
v___x_2108_ = lean_box(0);
v_isShared_2109_ = v_isSharedCheck_2114_;
goto v_resetjp_2107_;
}
v_resetjp_2107_:
{
lean_object* v___x_2110_; lean_object* v___x_2112_; 
v___x_2110_ = l_Lean_mkAppN(v_x_1986_, v_a_2106_);
lean_dec(v_a_2106_);
if (v_isShared_2109_ == 0)
{
lean_ctor_set(v___x_2108_, 0, v___x_2110_);
v___x_2112_ = v___x_2108_;
goto v_reusejp_2111_;
}
else
{
lean_object* v_reuseFailAlloc_2113_; 
v_reuseFailAlloc_2113_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2113_, 0, v___x_2110_);
v___x_2112_ = v_reuseFailAlloc_2113_;
goto v_reusejp_2111_;
}
v_reusejp_2111_:
{
return v___x_2112_;
}
}
}
else
{
lean_object* v_a_2115_; lean_object* v___x_2117_; uint8_t v_isShared_2118_; uint8_t v_isSharedCheck_2122_; 
lean_dec_ref(v_x_1986_);
v_a_2115_ = lean_ctor_get(v___x_2105_, 0);
v_isSharedCheck_2122_ = !lean_is_exclusive(v___x_2105_);
if (v_isSharedCheck_2122_ == 0)
{
v___x_2117_ = v___x_2105_;
v_isShared_2118_ = v_isSharedCheck_2122_;
goto v_resetjp_2116_;
}
else
{
lean_inc(v_a_2115_);
lean_dec(v___x_2105_);
v___x_2117_ = lean_box(0);
v_isShared_2118_ = v_isSharedCheck_2122_;
goto v_resetjp_2116_;
}
v_resetjp_2116_:
{
lean_object* v___x_2120_; 
if (v_isShared_2118_ == 0)
{
v___x_2120_ = v___x_2117_;
goto v_reusejp_2119_;
}
else
{
lean_object* v_reuseFailAlloc_2121_; 
v_reuseFailAlloc_2121_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2121_, 0, v_a_2115_);
v___x_2120_ = v_reuseFailAlloc_2121_;
goto v_reusejp_2119_;
}
v_reusejp_2119_:
{
return v___x_2120_;
}
}
}
}
else
{
lean_object* v_a_2123_; lean_object* v___x_2125_; uint8_t v_isShared_2126_; uint8_t v_isSharedCheck_2130_; 
lean_dec(v___y_2099_);
lean_dec_ref(v___y_2098_);
lean_dec(v___y_2097_);
lean_dec_ref(v___y_2096_);
lean_dec(v_fst_2086_);
lean_dec_ref(v_x_1986_);
v_a_2123_ = lean_ctor_get(v___x_2102_, 0);
v_isSharedCheck_2130_ = !lean_is_exclusive(v___x_2102_);
if (v_isSharedCheck_2130_ == 0)
{
v___x_2125_ = v___x_2102_;
v_isShared_2126_ = v_isSharedCheck_2130_;
goto v_resetjp_2124_;
}
else
{
lean_inc(v_a_2123_);
lean_dec(v___x_2102_);
v___x_2125_ = lean_box(0);
v_isShared_2126_ = v_isSharedCheck_2130_;
goto v_resetjp_2124_;
}
v_resetjp_2124_:
{
lean_object* v___x_2128_; 
if (v_isShared_2126_ == 0)
{
v___x_2128_ = v___x_2125_;
goto v_reusejp_2127_;
}
else
{
lean_object* v_reuseFailAlloc_2129_; 
v_reuseFailAlloc_2129_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2129_, 0, v_a_2123_);
v___x_2128_ = v_reuseFailAlloc_2129_;
goto v_reusejp_2127_;
}
v_reusejp_2127_:
{
return v___x_2128_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_2187_; lean_object* v___x_2189_; uint8_t v_isShared_2190_; uint8_t v_isSharedCheck_2194_; 
lean_dec_ref(v_val_2079_);
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
lean_dec_ref(v_expectedType_1983_);
v_a_2187_ = lean_ctor_get(v___x_2083_, 0);
v_isSharedCheck_2194_ = !lean_is_exclusive(v___x_2083_);
if (v_isSharedCheck_2194_ == 0)
{
v___x_2189_ = v___x_2083_;
v_isShared_2190_ = v_isSharedCheck_2194_;
goto v_resetjp_2188_;
}
else
{
lean_inc(v_a_2187_);
lean_dec(v___x_2083_);
v___x_2189_ = lean_box(0);
v_isShared_2190_ = v_isSharedCheck_2194_;
goto v_resetjp_2188_;
}
v_resetjp_2188_:
{
lean_object* v___x_2192_; 
if (v_isShared_2190_ == 0)
{
v___x_2192_ = v___x_2189_;
goto v_reusejp_2191_;
}
else
{
lean_object* v_reuseFailAlloc_2193_; 
v_reuseFailAlloc_2193_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2193_, 0, v_a_2187_);
v___x_2192_ = v_reuseFailAlloc_2193_;
goto v_reusejp_2191_;
}
v_reusejp_2191_:
{
return v___x_2192_;
}
}
}
}
else
{
lean_dec_ref(v_val_2079_);
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
lean_dec_ref(v_expectedType_1983_);
return v___x_2080_;
}
}
else
{
lean_dec(v_a_2078_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
v___y_2056_ = v___y_1989_;
v___y_2057_ = v___y_1990_;
v___y_2058_ = v___y_1991_;
v___y_2059_ = v___y_1992_;
goto v___jp_2055_;
}
}
else
{
lean_object* v_a_2195_; lean_object* v___x_2197_; uint8_t v_isShared_2198_; uint8_t v_isSharedCheck_2202_; 
lean_dec(v___y_1992_);
lean_dec_ref(v___y_1991_);
lean_dec(v___y_1990_);
lean_dec_ref(v___y_1989_);
lean_dec_ref(v_x_1987_);
lean_dec_ref(v_x_1986_);
lean_dec_ref(v_expectedType_1983_);
lean_dec_ref(v_a_1982_);
v_a_2195_ = lean_ctor_get(v___x_2077_, 0);
v_isSharedCheck_2202_ = !lean_is_exclusive(v___x_2077_);
if (v_isSharedCheck_2202_ == 0)
{
v___x_2197_ = v___x_2077_;
v_isShared_2198_ = v_isSharedCheck_2202_;
goto v_resetjp_2196_;
}
else
{
lean_inc(v_a_2195_);
lean_dec(v___x_2077_);
v___x_2197_ = lean_box(0);
v_isShared_2198_ = v_isSharedCheck_2202_;
goto v_resetjp_2196_;
}
v_resetjp_2196_:
{
lean_object* v___x_2200_; 
if (v_isShared_2198_ == 0)
{
v___x_2200_ = v___x_2197_;
goto v_reusejp_2199_;
}
else
{
lean_object* v_reuseFailAlloc_2201_; 
v_reuseFailAlloc_2201_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2201_, 0, v_a_2195_);
v___x_2200_ = v_reuseFailAlloc_2201_;
goto v_reusejp_2199_;
}
v_reusejp_2199_:
{
return v___x_2200_;
}
}
}
}
v___jp_2055_:
{
lean_object* v___x_2060_; lean_object* v_a_2061_; uint8_t v___x_2062_; 
v___x_2060_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2054_, v___y_2058_);
v_a_2061_ = lean_ctor_get(v___x_2060_, 0);
lean_inc(v_a_2061_);
lean_dec_ref(v___x_2060_);
v___x_2062_ = lean_unbox(v_a_2061_);
lean_dec(v_a_2061_);
if (v___x_2062_ == 0)
{
v___y_1995_ = v___y_2056_;
v___y_1996_ = v___y_2057_;
v___y_1997_ = v___y_2058_;
v___y_1998_ = v___y_2059_;
goto v___jp_1994_;
}
else
{
lean_object* v___x_2063_; lean_object* v___x_2064_; lean_object* v___x_2065_; lean_object* v___x_2066_; 
v___x_2063_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1);
lean_inc_ref(v_a_1982_);
v___x_2064_ = l_Lean_MessageData_ofExpr(v_a_1982_);
v___x_2065_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2065_, 0, v___x_2063_);
lean_ctor_set(v___x_2065_, 1, v___x_2064_);
v___x_2066_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2054_, v___x_2065_, v___y_2056_, v___y_2057_, v___y_2058_, v___y_2059_);
if (lean_obj_tag(v___x_2066_) == 0)
{
lean_dec_ref(v___x_2066_);
v___y_1995_ = v___y_2056_;
v___y_1996_ = v___y_2057_;
v___y_1997_ = v___y_2058_;
v___y_1998_ = v___y_2059_;
goto v___jp_1994_;
}
else
{
lean_object* v_a_2067_; lean_object* v___x_2069_; uint8_t v_isShared_2070_; uint8_t v_isSharedCheck_2074_; 
lean_dec(v___y_2059_);
lean_dec_ref(v___y_2058_);
lean_dec(v___y_2057_);
lean_dec_ref(v___y_2056_);
lean_dec_ref(v_expectedType_1983_);
lean_dec_ref(v_a_1982_);
v_a_2067_ = lean_ctor_get(v___x_2066_, 0);
v_isSharedCheck_2074_ = !lean_is_exclusive(v___x_2066_);
if (v_isSharedCheck_2074_ == 0)
{
v___x_2069_ = v___x_2066_;
v_isShared_2070_ = v_isSharedCheck_2074_;
goto v_resetjp_2068_;
}
else
{
lean_inc(v_a_2067_);
lean_dec(v___x_2066_);
v___x_2069_ = lean_box(0);
v_isShared_2070_ = v_isSharedCheck_2074_;
goto v_resetjp_2068_;
}
v_resetjp_2068_:
{
lean_object* v___x_2072_; 
if (v_isShared_2070_ == 0)
{
v___x_2072_ = v___x_2069_;
goto v_reusejp_2071_;
}
else
{
lean_object* v_reuseFailAlloc_2073_; 
v_reuseFailAlloc_2073_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2073_, 0, v_a_2067_);
v___x_2072_ = v_reuseFailAlloc_2073_;
goto v_reusejp_2071_;
}
v_reusejp_2071_:
{
return v___x_2072_;
}
}
}
}
}
}
v___jp_1994_:
{
lean_object* v_options_1999_; lean_object* v___x_2000_; uint8_t v___x_2001_; 
v_options_1999_ = lean_ctor_get(v___y_1997_, 2);
v___x_2000_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_2001_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_1999_, v___x_2000_);
if (v___x_2001_ == 0)
{
lean_object* v___x_2002_; 
lean_dec(v___y_1998_);
lean_dec_ref(v___y_1997_);
lean_dec(v___y_1996_);
lean_dec_ref(v___y_1995_);
lean_dec_ref(v_expectedType_1983_);
v___x_2002_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2002_, 0, v_a_1982_);
return v___x_2002_;
}
else
{
lean_object* v___x_2003_; 
lean_inc(v___y_1998_);
lean_inc_ref(v___y_1997_);
lean_inc(v___y_1996_);
lean_inc_ref(v___y_1995_);
lean_inc_ref(v_a_1982_);
v___x_2003_ = lean_infer_type(v_a_1982_, v___y_1995_, v___y_1996_, v___y_1997_, v___y_1998_);
if (lean_obj_tag(v___x_2003_) == 0)
{
lean_object* v_a_2004_; lean_object* v___x_2005_; 
v_a_2004_ = lean_ctor_get(v___x_2003_, 0);
lean_inc(v_a_2004_);
lean_dec_ref(v___x_2003_);
lean_inc(v___y_1998_);
lean_inc_ref(v___y_1997_);
lean_inc(v___y_1996_);
lean_inc_ref(v___y_1995_);
lean_inc_ref(v_expectedType_1983_);
v___x_2005_ = l_Lean_Meta_isExprDefEq(v_expectedType_1983_, v_a_2004_, v___y_1995_, v___y_1996_, v___y_1997_, v___y_1998_);
if (lean_obj_tag(v___x_2005_) == 0)
{
lean_object* v_a_2006_; lean_object* v___x_2008_; uint8_t v_isShared_2009_; uint8_t v_isSharedCheck_2039_; 
v_a_2006_ = lean_ctor_get(v___x_2005_, 0);
v_isSharedCheck_2039_ = !lean_is_exclusive(v___x_2005_);
if (v_isSharedCheck_2039_ == 0)
{
v___x_2008_ = v___x_2005_;
v_isShared_2009_ = v_isSharedCheck_2039_;
goto v_resetjp_2007_;
}
else
{
lean_inc(v_a_2006_);
lean_dec(v___x_2005_);
v___x_2008_ = lean_box(0);
v_isShared_2009_ = v_isSharedCheck_2039_;
goto v_resetjp_2007_;
}
v_resetjp_2007_:
{
uint8_t v___x_2010_; 
v___x_2010_ = lean_unbox(v_a_2006_);
if (v___x_2010_ == 0)
{
lean_object* v___x_2011_; lean_object* v___x_2012_; lean_object* v_a_2013_; uint8_t v___x_2014_; lean_object* v___x_2015_; 
lean_del_object(v___x_2008_);
v___x_2011_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_2012_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_2011_, v___y_1998_);
v_a_2013_ = lean_ctor_get(v___x_2012_, 0);
lean_inc(v_a_2013_);
lean_dec_ref(v___x_2012_);
v___x_2014_ = lean_unbox(v_a_2006_);
lean_dec(v_a_2006_);
lean_inc(v___y_1998_);
lean_inc_ref(v___y_1997_);
lean_inc(v___y_1996_);
lean_inc(v_a_2013_);
v___x_2015_ = l_Lean_Meta_mkAuxDefinition(v_a_2013_, v_expectedType_1983_, v_a_1982_, v___x_2014_, v_compile_1984_, v___y_1995_, v___y_1996_, v___y_1997_, v___y_1998_);
if (lean_obj_tag(v___x_2015_) == 0)
{
lean_object* v_a_2016_; uint8_t v___x_2017_; lean_object* v___x_2018_; lean_object* v___x_2019_; 
v_a_2016_ = lean_ctor_get(v___x_2015_, 0);
lean_inc(v_a_2016_);
lean_dec_ref(v___x_2015_);
v___x_2017_ = 3;
lean_inc(v_a_2013_);
v___x_2018_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(v_a_2013_, v___x_2017_, v___y_1996_, v___y_1998_);
lean_dec(v___y_1996_);
lean_dec_ref(v___x_2018_);
v___x_2019_ = l_Lean_enableRealizationsForConst(v_a_2013_, v___y_1997_, v___y_1998_);
lean_dec(v___y_1998_);
if (lean_obj_tag(v___x_2019_) == 0)
{
lean_object* v___x_2021_; uint8_t v_isShared_2022_; uint8_t v_isSharedCheck_2026_; 
v_isSharedCheck_2026_ = !lean_is_exclusive(v___x_2019_);
if (v_isSharedCheck_2026_ == 0)
{
lean_object* v_unused_2027_; 
v_unused_2027_ = lean_ctor_get(v___x_2019_, 0);
lean_dec(v_unused_2027_);
v___x_2021_ = v___x_2019_;
v_isShared_2022_ = v_isSharedCheck_2026_;
goto v_resetjp_2020_;
}
else
{
lean_dec(v___x_2019_);
v___x_2021_ = lean_box(0);
v_isShared_2022_ = v_isSharedCheck_2026_;
goto v_resetjp_2020_;
}
v_resetjp_2020_:
{
lean_object* v___x_2024_; 
if (v_isShared_2022_ == 0)
{
lean_ctor_set(v___x_2021_, 0, v_a_2016_);
v___x_2024_ = v___x_2021_;
goto v_reusejp_2023_;
}
else
{
lean_object* v_reuseFailAlloc_2025_; 
v_reuseFailAlloc_2025_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2025_, 0, v_a_2016_);
v___x_2024_ = v_reuseFailAlloc_2025_;
goto v_reusejp_2023_;
}
v_reusejp_2023_:
{
return v___x_2024_;
}
}
}
else
{
lean_object* v_a_2028_; lean_object* v___x_2030_; uint8_t v_isShared_2031_; uint8_t v_isSharedCheck_2035_; 
lean_dec(v_a_2016_);
v_a_2028_ = lean_ctor_get(v___x_2019_, 0);
v_isSharedCheck_2035_ = !lean_is_exclusive(v___x_2019_);
if (v_isSharedCheck_2035_ == 0)
{
v___x_2030_ = v___x_2019_;
v_isShared_2031_ = v_isSharedCheck_2035_;
goto v_resetjp_2029_;
}
else
{
lean_inc(v_a_2028_);
lean_dec(v___x_2019_);
v___x_2030_ = lean_box(0);
v_isShared_2031_ = v_isSharedCheck_2035_;
goto v_resetjp_2029_;
}
v_resetjp_2029_:
{
lean_object* v___x_2033_; 
if (v_isShared_2031_ == 0)
{
v___x_2033_ = v___x_2030_;
goto v_reusejp_2032_;
}
else
{
lean_object* v_reuseFailAlloc_2034_; 
v_reuseFailAlloc_2034_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2034_, 0, v_a_2028_);
v___x_2033_ = v_reuseFailAlloc_2034_;
goto v_reusejp_2032_;
}
v_reusejp_2032_:
{
return v___x_2033_;
}
}
}
}
else
{
lean_dec(v_a_2013_);
lean_dec(v___y_1998_);
lean_dec_ref(v___y_1997_);
lean_dec(v___y_1996_);
return v___x_2015_;
}
}
else
{
lean_object* v___x_2037_; 
lean_dec(v_a_2006_);
lean_dec(v___y_1998_);
lean_dec_ref(v___y_1997_);
lean_dec(v___y_1996_);
lean_dec_ref(v___y_1995_);
lean_dec_ref(v_expectedType_1983_);
if (v_isShared_2009_ == 0)
{
lean_ctor_set(v___x_2008_, 0, v_a_1982_);
v___x_2037_ = v___x_2008_;
goto v_reusejp_2036_;
}
else
{
lean_object* v_reuseFailAlloc_2038_; 
v_reuseFailAlloc_2038_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2038_, 0, v_a_1982_);
v___x_2037_ = v_reuseFailAlloc_2038_;
goto v_reusejp_2036_;
}
v_reusejp_2036_:
{
return v___x_2037_;
}
}
}
}
else
{
lean_object* v_a_2040_; lean_object* v___x_2042_; uint8_t v_isShared_2043_; uint8_t v_isSharedCheck_2047_; 
lean_dec(v___y_1998_);
lean_dec_ref(v___y_1997_);
lean_dec(v___y_1996_);
lean_dec_ref(v___y_1995_);
lean_dec_ref(v_expectedType_1983_);
lean_dec_ref(v_a_1982_);
v_a_2040_ = lean_ctor_get(v___x_2005_, 0);
v_isSharedCheck_2047_ = !lean_is_exclusive(v___x_2005_);
if (v_isSharedCheck_2047_ == 0)
{
v___x_2042_ = v___x_2005_;
v_isShared_2043_ = v_isSharedCheck_2047_;
goto v_resetjp_2041_;
}
else
{
lean_inc(v_a_2040_);
lean_dec(v___x_2005_);
v___x_2042_ = lean_box(0);
v_isShared_2043_ = v_isSharedCheck_2047_;
goto v_resetjp_2041_;
}
v_resetjp_2041_:
{
lean_object* v___x_2045_; 
if (v_isShared_2043_ == 0)
{
v___x_2045_ = v___x_2042_;
goto v_reusejp_2044_;
}
else
{
lean_object* v_reuseFailAlloc_2046_; 
v_reuseFailAlloc_2046_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2046_, 0, v_a_2040_);
v___x_2045_ = v_reuseFailAlloc_2046_;
goto v_reusejp_2044_;
}
v_reusejp_2044_:
{
return v___x_2045_;
}
}
}
}
else
{
lean_dec(v___y_1998_);
lean_dec_ref(v___y_1997_);
lean_dec(v___y_1996_);
lean_dec_ref(v___y_1995_);
lean_dec_ref(v_expectedType_1983_);
lean_dec_ref(v_a_1982_);
return v___x_2003_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__2(lean_object* v_inst_2203_, lean_object* v_expectedType_2204_, uint8_t v_compile_2205_, uint8_t v___x_2206_, lean_object* v_cls_2207_, lean_object* v_____r_2208_, lean_object* v___y_2209_, lean_object* v___y_2210_, lean_object* v___y_2211_, lean_object* v___y_2212_){
_start:
{
lean_object* v___x_2214_; 
lean_inc(v___y_2212_);
lean_inc_ref(v___y_2211_);
lean_inc(v___y_2210_);
lean_inc_ref(v___y_2209_);
lean_inc_ref(v_inst_2203_);
v___x_2214_ = lean_infer_type(v_inst_2203_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
if (lean_obj_tag(v___x_2214_) == 0)
{
lean_object* v_a_2215_; lean_object* v___x_2216_; 
v_a_2215_ = lean_ctor_get(v___x_2214_, 0);
lean_inc(v_a_2215_);
lean_dec_ref(v___x_2214_);
lean_inc(v___y_2212_);
lean_inc_ref(v___y_2211_);
lean_inc(v___y_2210_);
lean_inc_ref(v___y_2209_);
lean_inc_ref(v_expectedType_2204_);
v___x_2216_ = l_Lean_Meta_isExprDefEq(v_a_2215_, v_expectedType_2204_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
if (lean_obj_tag(v___x_2216_) == 0)
{
lean_object* v_a_2217_; uint8_t v___x_2218_; 
v_a_2217_ = lean_ctor_get(v___x_2216_, 0);
lean_inc(v_a_2217_);
lean_dec_ref(v___x_2216_);
v___x_2218_ = lean_unbox(v_a_2217_);
lean_dec(v_a_2217_);
if (v___x_2218_ == 0)
{
lean_object* v___x_2219_; 
lean_dec(v_cls_2207_);
lean_inc(v___y_2212_);
lean_inc_ref(v___y_2211_);
lean_inc(v___y_2210_);
lean_inc_ref(v___y_2209_);
lean_inc_ref(v_expectedType_2204_);
v___x_2219_ = l_Lean_Meta_isProp(v_expectedType_2204_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
if (lean_obj_tag(v___x_2219_) == 0)
{
lean_object* v_a_2220_; lean_object* v___x_2222_; uint8_t v_isShared_2223_; uint8_t v_isSharedCheck_2241_; 
v_a_2220_ = lean_ctor_get(v___x_2219_, 0);
v_isSharedCheck_2241_ = !lean_is_exclusive(v___x_2219_);
if (v_isSharedCheck_2241_ == 0)
{
v___x_2222_ = v___x_2219_;
v_isShared_2223_ = v_isSharedCheck_2241_;
goto v_resetjp_2221_;
}
else
{
lean_inc(v_a_2220_);
lean_dec(v___x_2219_);
v___x_2222_ = lean_box(0);
v_isShared_2223_ = v_isSharedCheck_2241_;
goto v_resetjp_2221_;
}
v_resetjp_2221_:
{
uint8_t v___x_2224_; 
v___x_2224_ = lean_unbox(v_a_2220_);
lean_dec(v_a_2220_);
if (v___x_2224_ == 0)
{
lean_object* v___x_2225_; 
lean_del_object(v___x_2222_);
lean_inc(v___y_2212_);
lean_inc_ref(v___y_2211_);
lean_inc(v___y_2210_);
lean_inc_ref(v___y_2209_);
v___x_2225_ = lean_whnf(v_inst_2203_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
if (lean_obj_tag(v___x_2225_) == 0)
{
lean_object* v_a_2226_; lean_object* v_dummy_2227_; lean_object* v_nargs_2228_; lean_object* v___x_2229_; lean_object* v___x_2230_; lean_object* v___x_2231_; lean_object* v___x_2232_; 
v_a_2226_ = lean_ctor_get(v___x_2225_, 0);
lean_inc(v_a_2226_);
lean_dec_ref(v___x_2225_);
v_dummy_2227_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__0, &l_Lean_Meta_normalizeInstance___lam__1___closed__0_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__0);
v_nargs_2228_ = l_Lean_Expr_getAppNumArgs(v_a_2226_);
lean_inc(v_nargs_2228_);
v___x_2229_ = lean_mk_array(v_nargs_2228_, v_dummy_2227_);
v___x_2230_ = lean_unsigned_to_nat(1u);
v___x_2231_ = lean_nat_sub(v_nargs_2228_, v___x_2230_);
lean_dec(v_nargs_2228_);
lean_inc(v_a_2226_);
v___x_2232_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17(v_a_2226_, v_expectedType_2204_, v_compile_2205_, v___x_2206_, v_a_2226_, v___x_2229_, v___x_2231_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
return v___x_2232_;
}
else
{
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec_ref(v_expectedType_2204_);
return v___x_2225_;
}
}
else
{
lean_object* v_options_2233_; lean_object* v___x_2234_; uint8_t v___x_2235_; 
v_options_2233_ = lean_ctor_get(v___y_2211_, 2);
v___x_2234_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_2235_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2233_, v___x_2234_);
if (v___x_2235_ == 0)
{
lean_object* v___x_2237_; 
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec_ref(v_expectedType_2204_);
if (v_isShared_2223_ == 0)
{
lean_ctor_set(v___x_2222_, 0, v_inst_2203_);
v___x_2237_ = v___x_2222_;
goto v_reusejp_2236_;
}
else
{
lean_object* v_reuseFailAlloc_2238_; 
v_reuseFailAlloc_2238_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2238_, 0, v_inst_2203_);
v___x_2237_ = v_reuseFailAlloc_2238_;
goto v_reusejp_2236_;
}
v_reusejp_2236_:
{
return v___x_2237_;
}
}
else
{
lean_object* v___x_2239_; lean_object* v___x_2240_; 
lean_del_object(v___x_2222_);
v___x_2239_ = lean_box(0);
v___x_2240_ = l_Lean_Meta_mkAuxTheorem(v_expectedType_2204_, v_inst_2203_, v___x_2206_, v___x_2239_, v___x_2206_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
return v___x_2240_;
}
}
}
}
else
{
lean_object* v_a_2242_; lean_object* v___x_2244_; uint8_t v_isShared_2245_; uint8_t v_isSharedCheck_2249_; 
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec_ref(v_expectedType_2204_);
lean_dec_ref(v_inst_2203_);
v_a_2242_ = lean_ctor_get(v___x_2219_, 0);
v_isSharedCheck_2249_ = !lean_is_exclusive(v___x_2219_);
if (v_isSharedCheck_2249_ == 0)
{
v___x_2244_ = v___x_2219_;
v_isShared_2245_ = v_isSharedCheck_2249_;
goto v_resetjp_2243_;
}
else
{
lean_inc(v_a_2242_);
lean_dec(v___x_2219_);
v___x_2244_ = lean_box(0);
v_isShared_2245_ = v_isSharedCheck_2249_;
goto v_resetjp_2243_;
}
v_resetjp_2243_:
{
lean_object* v___x_2247_; 
if (v_isShared_2245_ == 0)
{
v___x_2247_ = v___x_2244_;
goto v_reusejp_2246_;
}
else
{
lean_object* v_reuseFailAlloc_2248_; 
v_reuseFailAlloc_2248_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2248_, 0, v_a_2242_);
v___x_2247_ = v_reuseFailAlloc_2248_;
goto v_reusejp_2246_;
}
v_reusejp_2246_:
{
return v___x_2247_;
}
}
}
}
else
{
lean_object* v___x_2250_; 
lean_dec_ref(v_expectedType_2204_);
lean_inc(v_cls_2207_);
v___x_2250_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2207_, v___y_2211_);
if (lean_obj_tag(v___x_2250_) == 0)
{
lean_object* v_a_2251_; lean_object* v___x_2253_; uint8_t v_isShared_2254_; uint8_t v_isSharedCheck_2279_; 
v_a_2251_ = lean_ctor_get(v___x_2250_, 0);
v_isSharedCheck_2279_ = !lean_is_exclusive(v___x_2250_);
if (v_isSharedCheck_2279_ == 0)
{
v___x_2253_ = v___x_2250_;
v_isShared_2254_ = v_isSharedCheck_2279_;
goto v_resetjp_2252_;
}
else
{
lean_inc(v_a_2251_);
lean_dec(v___x_2250_);
v___x_2253_ = lean_box(0);
v_isShared_2254_ = v_isSharedCheck_2279_;
goto v_resetjp_2252_;
}
v_resetjp_2252_:
{
uint8_t v___x_2255_; 
v___x_2255_ = lean_unbox(v_a_2251_);
lean_dec(v_a_2251_);
if (v___x_2255_ == 0)
{
lean_object* v___x_2257_; 
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec(v_cls_2207_);
if (v_isShared_2254_ == 0)
{
lean_ctor_set(v___x_2253_, 0, v_inst_2203_);
v___x_2257_ = v___x_2253_;
goto v_reusejp_2256_;
}
else
{
lean_object* v_reuseFailAlloc_2258_; 
v_reuseFailAlloc_2258_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2258_, 0, v_inst_2203_);
v___x_2257_ = v_reuseFailAlloc_2258_;
goto v_reusejp_2256_;
}
v_reusejp_2256_:
{
return v___x_2257_;
}
}
else
{
lean_object* v___x_2259_; lean_object* v___x_2260_; lean_object* v___x_2261_; lean_object* v___x_2262_; 
lean_del_object(v___x_2253_);
v___x_2259_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__2, &l_Lean_Meta_normalizeInstance___lam__1___closed__2_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__2);
lean_inc_ref(v_inst_2203_);
v___x_2260_ = l_Lean_MessageData_ofExpr(v_inst_2203_);
v___x_2261_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2261_, 0, v___x_2259_);
lean_ctor_set(v___x_2261_, 1, v___x_2260_);
v___x_2262_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2207_, v___x_2261_, v___y_2209_, v___y_2210_, v___y_2211_, v___y_2212_);
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
if (lean_obj_tag(v___x_2262_) == 0)
{
lean_object* v___x_2264_; uint8_t v_isShared_2265_; uint8_t v_isSharedCheck_2269_; 
v_isSharedCheck_2269_ = !lean_is_exclusive(v___x_2262_);
if (v_isSharedCheck_2269_ == 0)
{
lean_object* v_unused_2270_; 
v_unused_2270_ = lean_ctor_get(v___x_2262_, 0);
lean_dec(v_unused_2270_);
v___x_2264_ = v___x_2262_;
v_isShared_2265_ = v_isSharedCheck_2269_;
goto v_resetjp_2263_;
}
else
{
lean_dec(v___x_2262_);
v___x_2264_ = lean_box(0);
v_isShared_2265_ = v_isSharedCheck_2269_;
goto v_resetjp_2263_;
}
v_resetjp_2263_:
{
lean_object* v___x_2267_; 
if (v_isShared_2265_ == 0)
{
lean_ctor_set(v___x_2264_, 0, v_inst_2203_);
v___x_2267_ = v___x_2264_;
goto v_reusejp_2266_;
}
else
{
lean_object* v_reuseFailAlloc_2268_; 
v_reuseFailAlloc_2268_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2268_, 0, v_inst_2203_);
v___x_2267_ = v_reuseFailAlloc_2268_;
goto v_reusejp_2266_;
}
v_reusejp_2266_:
{
return v___x_2267_;
}
}
}
else
{
lean_object* v_a_2271_; lean_object* v___x_2273_; uint8_t v_isShared_2274_; uint8_t v_isSharedCheck_2278_; 
lean_dec_ref(v_inst_2203_);
v_a_2271_ = lean_ctor_get(v___x_2262_, 0);
v_isSharedCheck_2278_ = !lean_is_exclusive(v___x_2262_);
if (v_isSharedCheck_2278_ == 0)
{
v___x_2273_ = v___x_2262_;
v_isShared_2274_ = v_isSharedCheck_2278_;
goto v_resetjp_2272_;
}
else
{
lean_inc(v_a_2271_);
lean_dec(v___x_2262_);
v___x_2273_ = lean_box(0);
v_isShared_2274_ = v_isSharedCheck_2278_;
goto v_resetjp_2272_;
}
v_resetjp_2272_:
{
lean_object* v___x_2276_; 
if (v_isShared_2274_ == 0)
{
v___x_2276_ = v___x_2273_;
goto v_reusejp_2275_;
}
else
{
lean_object* v_reuseFailAlloc_2277_; 
v_reuseFailAlloc_2277_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2277_, 0, v_a_2271_);
v___x_2276_ = v_reuseFailAlloc_2277_;
goto v_reusejp_2275_;
}
v_reusejp_2275_:
{
return v___x_2276_;
}
}
}
}
}
}
else
{
lean_object* v_a_2280_; lean_object* v___x_2282_; uint8_t v_isShared_2283_; uint8_t v_isSharedCheck_2287_; 
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec(v_cls_2207_);
lean_dec_ref(v_inst_2203_);
v_a_2280_ = lean_ctor_get(v___x_2250_, 0);
v_isSharedCheck_2287_ = !lean_is_exclusive(v___x_2250_);
if (v_isSharedCheck_2287_ == 0)
{
v___x_2282_ = v___x_2250_;
v_isShared_2283_ = v_isSharedCheck_2287_;
goto v_resetjp_2281_;
}
else
{
lean_inc(v_a_2280_);
lean_dec(v___x_2250_);
v___x_2282_ = lean_box(0);
v_isShared_2283_ = v_isSharedCheck_2287_;
goto v_resetjp_2281_;
}
v_resetjp_2281_:
{
lean_object* v___x_2285_; 
if (v_isShared_2283_ == 0)
{
v___x_2285_ = v___x_2282_;
goto v_reusejp_2284_;
}
else
{
lean_object* v_reuseFailAlloc_2286_; 
v_reuseFailAlloc_2286_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2286_, 0, v_a_2280_);
v___x_2285_ = v_reuseFailAlloc_2286_;
goto v_reusejp_2284_;
}
v_reusejp_2284_:
{
return v___x_2285_;
}
}
}
}
}
else
{
lean_object* v_a_2288_; lean_object* v___x_2290_; uint8_t v_isShared_2291_; uint8_t v_isSharedCheck_2295_; 
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec(v_cls_2207_);
lean_dec_ref(v_expectedType_2204_);
lean_dec_ref(v_inst_2203_);
v_a_2288_ = lean_ctor_get(v___x_2216_, 0);
v_isSharedCheck_2295_ = !lean_is_exclusive(v___x_2216_);
if (v_isSharedCheck_2295_ == 0)
{
v___x_2290_ = v___x_2216_;
v_isShared_2291_ = v_isSharedCheck_2295_;
goto v_resetjp_2289_;
}
else
{
lean_inc(v_a_2288_);
lean_dec(v___x_2216_);
v___x_2290_ = lean_box(0);
v_isShared_2291_ = v_isSharedCheck_2295_;
goto v_resetjp_2289_;
}
v_resetjp_2289_:
{
lean_object* v___x_2293_; 
if (v_isShared_2291_ == 0)
{
v___x_2293_ = v___x_2290_;
goto v_reusejp_2292_;
}
else
{
lean_object* v_reuseFailAlloc_2294_; 
v_reuseFailAlloc_2294_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2294_, 0, v_a_2288_);
v___x_2293_ = v_reuseFailAlloc_2294_;
goto v_reusejp_2292_;
}
v_reusejp_2292_:
{
return v___x_2293_;
}
}
}
}
else
{
lean_dec(v___y_2212_);
lean_dec_ref(v___y_2211_);
lean_dec(v___y_2210_);
lean_dec_ref(v___y_2209_);
lean_dec(v_cls_2207_);
lean_dec_ref(v_expectedType_2204_);
lean_dec_ref(v_inst_2203_);
return v___x_2214_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance(lean_object* v_inst_2296_, lean_object* v_expectedType_2297_, uint8_t v_compile_2298_, lean_object* v_a_2299_, lean_object* v_a_2300_, lean_object* v_a_2301_, lean_object* v_a_2302_){
_start:
{
lean_object* v___x_2304_; lean_object* v_options_2305_; uint8_t v_foApprox_2306_; uint8_t v_ctxApprox_2307_; uint8_t v_quasiPatternApprox_2308_; uint8_t v_constApprox_2309_; uint8_t v_isDefEqStuckEx_2310_; uint8_t v_unificationHints_2311_; uint8_t v_proofIrrelevance_2312_; uint8_t v_assignSyntheticOpaque_2313_; uint8_t v_offsetCnstrs_2314_; uint8_t v_etaStruct_2315_; uint8_t v_univApprox_2316_; uint8_t v_iota_2317_; uint8_t v_beta_2318_; uint8_t v_proj_2319_; uint8_t v_zeta_2320_; uint8_t v_zetaDelta_2321_; uint8_t v_zetaUnused_2322_; uint8_t v_zetaHave_2323_; lean_object* v___x_2325_; uint8_t v_isShared_2326_; uint8_t v_isSharedCheck_2745_; 
v___x_2304_ = l_Lean_Meta_Context_config(v_a_2299_);
v_options_2305_ = lean_ctor_get(v_a_2301_, 2);
v_foApprox_2306_ = lean_ctor_get_uint8(v___x_2304_, 0);
v_ctxApprox_2307_ = lean_ctor_get_uint8(v___x_2304_, 1);
v_quasiPatternApprox_2308_ = lean_ctor_get_uint8(v___x_2304_, 2);
v_constApprox_2309_ = lean_ctor_get_uint8(v___x_2304_, 3);
v_isDefEqStuckEx_2310_ = lean_ctor_get_uint8(v___x_2304_, 4);
v_unificationHints_2311_ = lean_ctor_get_uint8(v___x_2304_, 5);
v_proofIrrelevance_2312_ = lean_ctor_get_uint8(v___x_2304_, 6);
v_assignSyntheticOpaque_2313_ = lean_ctor_get_uint8(v___x_2304_, 7);
v_offsetCnstrs_2314_ = lean_ctor_get_uint8(v___x_2304_, 8);
v_etaStruct_2315_ = lean_ctor_get_uint8(v___x_2304_, 10);
v_univApprox_2316_ = lean_ctor_get_uint8(v___x_2304_, 11);
v_iota_2317_ = lean_ctor_get_uint8(v___x_2304_, 12);
v_beta_2318_ = lean_ctor_get_uint8(v___x_2304_, 13);
v_proj_2319_ = lean_ctor_get_uint8(v___x_2304_, 14);
v_zeta_2320_ = lean_ctor_get_uint8(v___x_2304_, 15);
v_zetaDelta_2321_ = lean_ctor_get_uint8(v___x_2304_, 16);
v_zetaUnused_2322_ = lean_ctor_get_uint8(v___x_2304_, 17);
v_zetaHave_2323_ = lean_ctor_get_uint8(v___x_2304_, 18);
v_isSharedCheck_2745_ = !lean_is_exclusive(v___x_2304_);
if (v_isSharedCheck_2745_ == 0)
{
v___x_2325_ = v___x_2304_;
v_isShared_2326_ = v_isSharedCheck_2745_;
goto v_resetjp_2324_;
}
else
{
lean_dec(v___x_2304_);
v___x_2325_ = lean_box(0);
v_isShared_2326_ = v_isSharedCheck_2745_;
goto v_resetjp_2324_;
}
v_resetjp_2324_:
{
uint8_t v_trackZetaDelta_2327_; lean_object* v_zetaDeltaSet_2328_; lean_object* v_lctx_2329_; lean_object* v_localInstances_2330_; lean_object* v_defEqCtx_x3f_2331_; lean_object* v_synthPendingDepth_2332_; lean_object* v_canUnfold_x3f_2333_; uint8_t v_univApprox_2334_; uint8_t v_inTypeClassResolution_2335_; uint8_t v_cacheInferType_2336_; uint8_t v_hasTrace_2337_; uint8_t v___x_2338_; lean_object* v_config_2340_; 
v_trackZetaDelta_2327_ = lean_ctor_get_uint8(v_a_2299_, sizeof(void*)*7);
v_zetaDeltaSet_2328_ = lean_ctor_get(v_a_2299_, 1);
lean_inc(v_zetaDeltaSet_2328_);
v_lctx_2329_ = lean_ctor_get(v_a_2299_, 2);
lean_inc_ref(v_lctx_2329_);
v_localInstances_2330_ = lean_ctor_get(v_a_2299_, 3);
lean_inc_ref(v_localInstances_2330_);
v_defEqCtx_x3f_2331_ = lean_ctor_get(v_a_2299_, 4);
lean_inc(v_defEqCtx_x3f_2331_);
v_synthPendingDepth_2332_ = lean_ctor_get(v_a_2299_, 5);
lean_inc(v_synthPendingDepth_2332_);
v_canUnfold_x3f_2333_ = lean_ctor_get(v_a_2299_, 6);
lean_inc(v_canUnfold_x3f_2333_);
v_univApprox_2334_ = lean_ctor_get_uint8(v_a_2299_, sizeof(void*)*7 + 1);
v_inTypeClassResolution_2335_ = lean_ctor_get_uint8(v_a_2299_, sizeof(void*)*7 + 2);
v_cacheInferType_2336_ = lean_ctor_get_uint8(v_a_2299_, sizeof(void*)*7 + 3);
v_hasTrace_2337_ = lean_ctor_get_uint8(v_options_2305_, sizeof(void*)*1);
v___x_2338_ = 3;
if (v_isShared_2326_ == 0)
{
v_config_2340_ = v___x_2325_;
goto v_reusejp_2339_;
}
else
{
lean_object* v_reuseFailAlloc_2744_; 
v_reuseFailAlloc_2744_ = lean_alloc_ctor(0, 0, 19);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 0, v_foApprox_2306_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 1, v_ctxApprox_2307_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 2, v_quasiPatternApprox_2308_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 3, v_constApprox_2309_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 4, v_isDefEqStuckEx_2310_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 5, v_unificationHints_2311_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 6, v_proofIrrelevance_2312_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 7, v_assignSyntheticOpaque_2313_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 8, v_offsetCnstrs_2314_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 10, v_etaStruct_2315_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 11, v_univApprox_2316_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 12, v_iota_2317_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 13, v_beta_2318_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 14, v_proj_2319_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 15, v_zeta_2320_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 16, v_zetaDelta_2321_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 17, v_zetaUnused_2322_);
lean_ctor_set_uint8(v_reuseFailAlloc_2744_, 18, v_zetaHave_2323_);
v_config_2340_ = v_reuseFailAlloc_2744_;
goto v_reusejp_2339_;
}
v_reusejp_2339_:
{
uint64_t v___x_2341_; lean_object* v___x_2343_; uint8_t v_isShared_2344_; uint8_t v_isSharedCheck_2736_; 
lean_ctor_set_uint8(v_config_2340_, 9, v___x_2338_);
v___x_2341_ = l_Lean_Meta_Context_configKey(v_a_2299_);
v_isSharedCheck_2736_ = !lean_is_exclusive(v_a_2299_);
if (v_isSharedCheck_2736_ == 0)
{
lean_object* v_unused_2737_; lean_object* v_unused_2738_; lean_object* v_unused_2739_; lean_object* v_unused_2740_; lean_object* v_unused_2741_; lean_object* v_unused_2742_; lean_object* v_unused_2743_; 
v_unused_2737_ = lean_ctor_get(v_a_2299_, 6);
lean_dec(v_unused_2737_);
v_unused_2738_ = lean_ctor_get(v_a_2299_, 5);
lean_dec(v_unused_2738_);
v_unused_2739_ = lean_ctor_get(v_a_2299_, 4);
lean_dec(v_unused_2739_);
v_unused_2740_ = lean_ctor_get(v_a_2299_, 3);
lean_dec(v_unused_2740_);
v_unused_2741_ = lean_ctor_get(v_a_2299_, 2);
lean_dec(v_unused_2741_);
v_unused_2742_ = lean_ctor_get(v_a_2299_, 1);
lean_dec(v_unused_2742_);
v_unused_2743_ = lean_ctor_get(v_a_2299_, 0);
lean_dec(v_unused_2743_);
v___x_2343_ = v_a_2299_;
v_isShared_2344_ = v_isSharedCheck_2736_;
goto v_resetjp_2342_;
}
else
{
lean_dec(v_a_2299_);
v___x_2343_ = lean_box(0);
v_isShared_2344_ = v_isSharedCheck_2736_;
goto v_resetjp_2342_;
}
v_resetjp_2342_:
{
uint64_t v___x_2345_; uint64_t v___x_2346_; lean_object* v_cls_2347_; lean_object* v___y_2349_; lean_object* v___y_2350_; lean_object* v___y_2351_; lean_object* v___y_2352_; uint64_t v___x_2435_; uint64_t v___x_2436_; uint64_t v_key_2437_; lean_object* v___x_2438_; lean_object* v___x_2440_; 
v___x_2345_ = 2ULL;
v___x_2346_ = lean_uint64_shift_right(v___x_2341_, v___x_2345_);
v_cls_2347_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_2435_ = lean_uint64_shift_left(v___x_2346_, v___x_2345_);
v___x_2436_ = lean_uint64_once(&l_Lean_Meta_normalizeInstance___closed__0, &l_Lean_Meta_normalizeInstance___closed__0_once, _init_l_Lean_Meta_normalizeInstance___closed__0);
v_key_2437_ = lean_uint64_lor(v___x_2435_, v___x_2436_);
v___x_2438_ = lean_alloc_ctor(0, 1, 8);
lean_ctor_set(v___x_2438_, 0, v_config_2340_);
lean_ctor_set_uint64(v___x_2438_, sizeof(void*)*1, v_key_2437_);
if (v_isShared_2344_ == 0)
{
lean_ctor_set(v___x_2343_, 0, v___x_2438_);
v___x_2440_ = v___x_2343_;
goto v_reusejp_2439_;
}
else
{
lean_object* v_reuseFailAlloc_2735_; 
v_reuseFailAlloc_2735_ = lean_alloc_ctor(0, 7, 4);
lean_ctor_set(v_reuseFailAlloc_2735_, 0, v___x_2438_);
lean_ctor_set(v_reuseFailAlloc_2735_, 1, v_zetaDeltaSet_2328_);
lean_ctor_set(v_reuseFailAlloc_2735_, 2, v_lctx_2329_);
lean_ctor_set(v_reuseFailAlloc_2735_, 3, v_localInstances_2330_);
lean_ctor_set(v_reuseFailAlloc_2735_, 4, v_defEqCtx_x3f_2331_);
lean_ctor_set(v_reuseFailAlloc_2735_, 5, v_synthPendingDepth_2332_);
lean_ctor_set(v_reuseFailAlloc_2735_, 6, v_canUnfold_x3f_2333_);
lean_ctor_set_uint8(v_reuseFailAlloc_2735_, sizeof(void*)*7, v_trackZetaDelta_2327_);
lean_ctor_set_uint8(v_reuseFailAlloc_2735_, sizeof(void*)*7 + 1, v_univApprox_2334_);
lean_ctor_set_uint8(v_reuseFailAlloc_2735_, sizeof(void*)*7 + 2, v_inTypeClassResolution_2335_);
lean_ctor_set_uint8(v_reuseFailAlloc_2735_, sizeof(void*)*7 + 3, v_cacheInferType_2336_);
v___x_2440_ = v_reuseFailAlloc_2735_;
goto v_reusejp_2439_;
}
v___jp_2348_:
{
lean_object* v___x_2353_; 
lean_inc(v___y_2352_);
lean_inc_ref(v___y_2351_);
lean_inc(v___y_2350_);
lean_inc_ref(v___y_2349_);
lean_inc_ref(v_inst_2296_);
v___x_2353_ = lean_infer_type(v_inst_2296_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
if (lean_obj_tag(v___x_2353_) == 0)
{
lean_object* v_a_2354_; lean_object* v___x_2355_; 
v_a_2354_ = lean_ctor_get(v___x_2353_, 0);
lean_inc(v_a_2354_);
lean_dec_ref(v___x_2353_);
lean_inc(v___y_2352_);
lean_inc_ref(v___y_2351_);
lean_inc(v___y_2350_);
lean_inc_ref(v___y_2349_);
lean_inc_ref(v_expectedType_2297_);
v___x_2355_ = l_Lean_Meta_isExprDefEq(v_a_2354_, v_expectedType_2297_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
if (lean_obj_tag(v___x_2355_) == 0)
{
lean_object* v_a_2356_; uint8_t v___x_2357_; 
v_a_2356_ = lean_ctor_get(v___x_2355_, 0);
lean_inc(v_a_2356_);
lean_dec_ref(v___x_2355_);
v___x_2357_ = lean_unbox(v_a_2356_);
lean_dec(v_a_2356_);
if (v___x_2357_ == 0)
{
lean_object* v___x_2358_; 
lean_inc(v___y_2352_);
lean_inc_ref(v___y_2351_);
lean_inc(v___y_2350_);
lean_inc_ref(v___y_2349_);
lean_inc_ref(v_expectedType_2297_);
v___x_2358_ = l_Lean_Meta_isProp(v_expectedType_2297_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
if (lean_obj_tag(v___x_2358_) == 0)
{
lean_object* v_a_2359_; lean_object* v___x_2361_; uint8_t v_isShared_2362_; uint8_t v_isSharedCheck_2380_; 
v_a_2359_ = lean_ctor_get(v___x_2358_, 0);
v_isSharedCheck_2380_ = !lean_is_exclusive(v___x_2358_);
if (v_isSharedCheck_2380_ == 0)
{
v___x_2361_ = v___x_2358_;
v_isShared_2362_ = v_isSharedCheck_2380_;
goto v_resetjp_2360_;
}
else
{
lean_inc(v_a_2359_);
lean_dec(v___x_2358_);
v___x_2361_ = lean_box(0);
v_isShared_2362_ = v_isSharedCheck_2380_;
goto v_resetjp_2360_;
}
v_resetjp_2360_:
{
uint8_t v___x_2363_; 
v___x_2363_ = lean_unbox(v_a_2359_);
lean_dec(v_a_2359_);
if (v___x_2363_ == 0)
{
lean_object* v___x_2364_; 
lean_del_object(v___x_2361_);
lean_inc(v___y_2352_);
lean_inc_ref(v___y_2351_);
lean_inc(v___y_2350_);
lean_inc_ref(v___y_2349_);
v___x_2364_ = lean_whnf(v_inst_2296_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
if (lean_obj_tag(v___x_2364_) == 0)
{
lean_object* v_a_2365_; lean_object* v_dummy_2366_; lean_object* v_nargs_2367_; lean_object* v___x_2368_; lean_object* v___x_2369_; lean_object* v___x_2370_; lean_object* v___x_2371_; 
v_a_2365_ = lean_ctor_get(v___x_2364_, 0);
lean_inc(v_a_2365_);
lean_dec_ref(v___x_2364_);
v_dummy_2366_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__0, &l_Lean_Meta_normalizeInstance___lam__1___closed__0_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__0);
v_nargs_2367_ = l_Lean_Expr_getAppNumArgs(v_a_2365_);
lean_inc(v_nargs_2367_);
v___x_2368_ = lean_mk_array(v_nargs_2367_, v_dummy_2366_);
v___x_2369_ = lean_unsigned_to_nat(1u);
v___x_2370_ = lean_nat_sub(v_nargs_2367_, v___x_2369_);
lean_dec(v_nargs_2367_);
lean_inc(v_a_2365_);
v___x_2371_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12(v_a_2365_, v_expectedType_2297_, v_hasTrace_2337_, v_compile_2298_, v_a_2365_, v___x_2368_, v___x_2370_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
return v___x_2371_;
}
else
{
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_expectedType_2297_);
return v___x_2364_;
}
}
else
{
lean_object* v_options_2372_; lean_object* v___x_2373_; uint8_t v___x_2374_; 
v_options_2372_ = lean_ctor_get(v___y_2351_, 2);
v___x_2373_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_2374_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2372_, v___x_2373_);
if (v___x_2374_ == 0)
{
lean_object* v___x_2376_; 
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_expectedType_2297_);
if (v_isShared_2362_ == 0)
{
lean_ctor_set(v___x_2361_, 0, v_inst_2296_);
v___x_2376_ = v___x_2361_;
goto v_reusejp_2375_;
}
else
{
lean_object* v_reuseFailAlloc_2377_; 
v_reuseFailAlloc_2377_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2377_, 0, v_inst_2296_);
v___x_2376_ = v_reuseFailAlloc_2377_;
goto v_reusejp_2375_;
}
v_reusejp_2375_:
{
return v___x_2376_;
}
}
else
{
lean_object* v___x_2378_; lean_object* v___x_2379_; 
lean_del_object(v___x_2361_);
v___x_2378_ = lean_box(0);
v___x_2379_ = l_Lean_Meta_mkAuxTheorem(v_expectedType_2297_, v_inst_2296_, v___x_2374_, v___x_2378_, v___x_2374_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
return v___x_2379_;
}
}
}
}
else
{
lean_object* v_a_2381_; lean_object* v___x_2383_; uint8_t v_isShared_2384_; uint8_t v_isSharedCheck_2388_; 
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2381_ = lean_ctor_get(v___x_2358_, 0);
v_isSharedCheck_2388_ = !lean_is_exclusive(v___x_2358_);
if (v_isSharedCheck_2388_ == 0)
{
v___x_2383_ = v___x_2358_;
v_isShared_2384_ = v_isSharedCheck_2388_;
goto v_resetjp_2382_;
}
else
{
lean_inc(v_a_2381_);
lean_dec(v___x_2358_);
v___x_2383_ = lean_box(0);
v_isShared_2384_ = v_isSharedCheck_2388_;
goto v_resetjp_2382_;
}
v_resetjp_2382_:
{
lean_object* v___x_2386_; 
if (v_isShared_2384_ == 0)
{
v___x_2386_ = v___x_2383_;
goto v_reusejp_2385_;
}
else
{
lean_object* v_reuseFailAlloc_2387_; 
v_reuseFailAlloc_2387_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2387_, 0, v_a_2381_);
v___x_2386_ = v_reuseFailAlloc_2387_;
goto v_reusejp_2385_;
}
v_reusejp_2385_:
{
return v___x_2386_;
}
}
}
}
else
{
lean_object* v___x_2389_; 
lean_dec_ref(v_expectedType_2297_);
v___x_2389_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v___y_2351_);
if (lean_obj_tag(v___x_2389_) == 0)
{
lean_object* v_a_2390_; lean_object* v___x_2392_; uint8_t v_isShared_2393_; uint8_t v_isSharedCheck_2418_; 
v_a_2390_ = lean_ctor_get(v___x_2389_, 0);
v_isSharedCheck_2418_ = !lean_is_exclusive(v___x_2389_);
if (v_isSharedCheck_2418_ == 0)
{
v___x_2392_ = v___x_2389_;
v_isShared_2393_ = v_isSharedCheck_2418_;
goto v_resetjp_2391_;
}
else
{
lean_inc(v_a_2390_);
lean_dec(v___x_2389_);
v___x_2392_ = lean_box(0);
v_isShared_2393_ = v_isSharedCheck_2418_;
goto v_resetjp_2391_;
}
v_resetjp_2391_:
{
uint8_t v___x_2394_; 
v___x_2394_ = lean_unbox(v_a_2390_);
lean_dec(v_a_2390_);
if (v___x_2394_ == 0)
{
lean_object* v___x_2396_; 
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
if (v_isShared_2393_ == 0)
{
lean_ctor_set(v___x_2392_, 0, v_inst_2296_);
v___x_2396_ = v___x_2392_;
goto v_reusejp_2395_;
}
else
{
lean_object* v_reuseFailAlloc_2397_; 
v_reuseFailAlloc_2397_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2397_, 0, v_inst_2296_);
v___x_2396_ = v_reuseFailAlloc_2397_;
goto v_reusejp_2395_;
}
v_reusejp_2395_:
{
return v___x_2396_;
}
}
else
{
lean_object* v___x_2398_; lean_object* v___x_2399_; lean_object* v___x_2400_; lean_object* v___x_2401_; 
lean_del_object(v___x_2392_);
v___x_2398_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__2, &l_Lean_Meta_normalizeInstance___lam__1___closed__2_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__2);
lean_inc_ref(v_inst_2296_);
v___x_2399_ = l_Lean_MessageData_ofExpr(v_inst_2296_);
v___x_2400_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2400_, 0, v___x_2398_);
lean_ctor_set(v___x_2400_, 1, v___x_2399_);
v___x_2401_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2400_, v___y_2349_, v___y_2350_, v___y_2351_, v___y_2352_);
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
if (lean_obj_tag(v___x_2401_) == 0)
{
lean_object* v___x_2403_; uint8_t v_isShared_2404_; uint8_t v_isSharedCheck_2408_; 
v_isSharedCheck_2408_ = !lean_is_exclusive(v___x_2401_);
if (v_isSharedCheck_2408_ == 0)
{
lean_object* v_unused_2409_; 
v_unused_2409_ = lean_ctor_get(v___x_2401_, 0);
lean_dec(v_unused_2409_);
v___x_2403_ = v___x_2401_;
v_isShared_2404_ = v_isSharedCheck_2408_;
goto v_resetjp_2402_;
}
else
{
lean_dec(v___x_2401_);
v___x_2403_ = lean_box(0);
v_isShared_2404_ = v_isSharedCheck_2408_;
goto v_resetjp_2402_;
}
v_resetjp_2402_:
{
lean_object* v___x_2406_; 
if (v_isShared_2404_ == 0)
{
lean_ctor_set(v___x_2403_, 0, v_inst_2296_);
v___x_2406_ = v___x_2403_;
goto v_reusejp_2405_;
}
else
{
lean_object* v_reuseFailAlloc_2407_; 
v_reuseFailAlloc_2407_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2407_, 0, v_inst_2296_);
v___x_2406_ = v_reuseFailAlloc_2407_;
goto v_reusejp_2405_;
}
v_reusejp_2405_:
{
return v___x_2406_;
}
}
}
else
{
lean_object* v_a_2410_; lean_object* v___x_2412_; uint8_t v_isShared_2413_; uint8_t v_isSharedCheck_2417_; 
lean_dec_ref(v_inst_2296_);
v_a_2410_ = lean_ctor_get(v___x_2401_, 0);
v_isSharedCheck_2417_ = !lean_is_exclusive(v___x_2401_);
if (v_isSharedCheck_2417_ == 0)
{
v___x_2412_ = v___x_2401_;
v_isShared_2413_ = v_isSharedCheck_2417_;
goto v_resetjp_2411_;
}
else
{
lean_inc(v_a_2410_);
lean_dec(v___x_2401_);
v___x_2412_ = lean_box(0);
v_isShared_2413_ = v_isSharedCheck_2417_;
goto v_resetjp_2411_;
}
v_resetjp_2411_:
{
lean_object* v___x_2415_; 
if (v_isShared_2413_ == 0)
{
v___x_2415_ = v___x_2412_;
goto v_reusejp_2414_;
}
else
{
lean_object* v_reuseFailAlloc_2416_; 
v_reuseFailAlloc_2416_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2416_, 0, v_a_2410_);
v___x_2415_ = v_reuseFailAlloc_2416_;
goto v_reusejp_2414_;
}
v_reusejp_2414_:
{
return v___x_2415_;
}
}
}
}
}
}
else
{
lean_object* v_a_2419_; lean_object* v___x_2421_; uint8_t v_isShared_2422_; uint8_t v_isSharedCheck_2426_; 
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_inst_2296_);
v_a_2419_ = lean_ctor_get(v___x_2389_, 0);
v_isSharedCheck_2426_ = !lean_is_exclusive(v___x_2389_);
if (v_isSharedCheck_2426_ == 0)
{
v___x_2421_ = v___x_2389_;
v_isShared_2422_ = v_isSharedCheck_2426_;
goto v_resetjp_2420_;
}
else
{
lean_inc(v_a_2419_);
lean_dec(v___x_2389_);
v___x_2421_ = lean_box(0);
v_isShared_2422_ = v_isSharedCheck_2426_;
goto v_resetjp_2420_;
}
v_resetjp_2420_:
{
lean_object* v___x_2424_; 
if (v_isShared_2422_ == 0)
{
v___x_2424_ = v___x_2421_;
goto v_reusejp_2423_;
}
else
{
lean_object* v_reuseFailAlloc_2425_; 
v_reuseFailAlloc_2425_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2425_, 0, v_a_2419_);
v___x_2424_ = v_reuseFailAlloc_2425_;
goto v_reusejp_2423_;
}
v_reusejp_2423_:
{
return v___x_2424_;
}
}
}
}
}
else
{
lean_object* v_a_2427_; lean_object* v___x_2429_; uint8_t v_isShared_2430_; uint8_t v_isSharedCheck_2434_; 
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2427_ = lean_ctor_get(v___x_2355_, 0);
v_isSharedCheck_2434_ = !lean_is_exclusive(v___x_2355_);
if (v_isSharedCheck_2434_ == 0)
{
v___x_2429_ = v___x_2355_;
v_isShared_2430_ = v_isSharedCheck_2434_;
goto v_resetjp_2428_;
}
else
{
lean_inc(v_a_2427_);
lean_dec(v___x_2355_);
v___x_2429_ = lean_box(0);
v_isShared_2430_ = v_isSharedCheck_2434_;
goto v_resetjp_2428_;
}
v_resetjp_2428_:
{
lean_object* v___x_2432_; 
if (v_isShared_2430_ == 0)
{
v___x_2432_ = v___x_2429_;
goto v_reusejp_2431_;
}
else
{
lean_object* v_reuseFailAlloc_2433_; 
v_reuseFailAlloc_2433_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2433_, 0, v_a_2427_);
v___x_2432_ = v_reuseFailAlloc_2433_;
goto v_reusejp_2431_;
}
v_reusejp_2431_:
{
return v___x_2432_;
}
}
}
}
else
{
lean_dec(v___y_2352_);
lean_dec_ref(v___y_2351_);
lean_dec(v___y_2350_);
lean_dec_ref(v___y_2349_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
return v___x_2353_;
}
}
v_reusejp_2439_:
{
if (v_hasTrace_2337_ == 0)
{
lean_object* v___x_2441_; 
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
lean_inc_ref(v_expectedType_2297_);
v___x_2441_ = l_Lean_Meta_isClass_x3f(v_expectedType_2297_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2441_) == 0)
{
lean_object* v_a_2442_; lean_object* v___x_2444_; uint8_t v_isShared_2445_; uint8_t v_isSharedCheck_2473_; 
v_a_2442_ = lean_ctor_get(v___x_2441_, 0);
v_isSharedCheck_2473_ = !lean_is_exclusive(v___x_2441_);
if (v_isSharedCheck_2473_ == 0)
{
v___x_2444_ = v___x_2441_;
v_isShared_2445_ = v_isSharedCheck_2473_;
goto v_resetjp_2443_;
}
else
{
lean_inc(v_a_2442_);
lean_dec(v___x_2441_);
v___x_2444_ = lean_box(0);
v_isShared_2445_ = v_isSharedCheck_2473_;
goto v_resetjp_2443_;
}
v_resetjp_2443_:
{
if (lean_obj_tag(v_a_2442_) == 1)
{
lean_object* v_val_2446_; lean_object* v___x_2447_; 
lean_del_object(v___x_2444_);
v_val_2446_ = lean_ctor_get(v_a_2442_, 0);
lean_inc(v_val_2446_);
lean_dec_ref(v_a_2442_);
v___x_2447_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v_a_2301_);
if (lean_obj_tag(v___x_2447_) == 0)
{
lean_object* v_a_2448_; uint8_t v___x_2449_; 
v_a_2448_ = lean_ctor_get(v___x_2447_, 0);
lean_inc(v_a_2448_);
lean_dec_ref(v___x_2447_);
v___x_2449_ = lean_unbox(v_a_2448_);
lean_dec(v_a_2448_);
if (v___x_2449_ == 0)
{
lean_dec(v_val_2446_);
v___y_2349_ = v___x_2440_;
v___y_2350_ = v_a_2300_;
v___y_2351_ = v_a_2301_;
v___y_2352_ = v_a_2302_;
goto v___jp_2348_;
}
else
{
lean_object* v___x_2450_; lean_object* v___x_2451_; lean_object* v___x_2452_; lean_object* v___x_2453_; 
v___x_2450_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___closed__2, &l_Lean_Meta_normalizeInstance___closed__2_once, _init_l_Lean_Meta_normalizeInstance___closed__2);
v___x_2451_ = l_Lean_MessageData_ofName(v_val_2446_);
v___x_2452_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2452_, 0, v___x_2450_);
lean_ctor_set(v___x_2452_, 1, v___x_2451_);
v___x_2453_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2452_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2453_) == 0)
{
lean_dec_ref(v___x_2453_);
v___y_2349_ = v___x_2440_;
v___y_2350_ = v_a_2300_;
v___y_2351_ = v_a_2301_;
v___y_2352_ = v_a_2302_;
goto v___jp_2348_;
}
else
{
lean_object* v_a_2454_; lean_object* v___x_2456_; uint8_t v_isShared_2457_; uint8_t v_isSharedCheck_2461_; 
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2454_ = lean_ctor_get(v___x_2453_, 0);
v_isSharedCheck_2461_ = !lean_is_exclusive(v___x_2453_);
if (v_isSharedCheck_2461_ == 0)
{
v___x_2456_ = v___x_2453_;
v_isShared_2457_ = v_isSharedCheck_2461_;
goto v_resetjp_2455_;
}
else
{
lean_inc(v_a_2454_);
lean_dec(v___x_2453_);
v___x_2456_ = lean_box(0);
v_isShared_2457_ = v_isSharedCheck_2461_;
goto v_resetjp_2455_;
}
v_resetjp_2455_:
{
lean_object* v___x_2459_; 
if (v_isShared_2457_ == 0)
{
v___x_2459_ = v___x_2456_;
goto v_reusejp_2458_;
}
else
{
lean_object* v_reuseFailAlloc_2460_; 
v_reuseFailAlloc_2460_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2460_, 0, v_a_2454_);
v___x_2459_ = v_reuseFailAlloc_2460_;
goto v_reusejp_2458_;
}
v_reusejp_2458_:
{
return v___x_2459_;
}
}
}
}
}
else
{
lean_object* v_a_2462_; lean_object* v___x_2464_; uint8_t v_isShared_2465_; uint8_t v_isSharedCheck_2469_; 
lean_dec(v_val_2446_);
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2462_ = lean_ctor_get(v___x_2447_, 0);
v_isSharedCheck_2469_ = !lean_is_exclusive(v___x_2447_);
if (v_isSharedCheck_2469_ == 0)
{
v___x_2464_ = v___x_2447_;
v_isShared_2465_ = v_isSharedCheck_2469_;
goto v_resetjp_2463_;
}
else
{
lean_inc(v_a_2462_);
lean_dec(v___x_2447_);
v___x_2464_ = lean_box(0);
v_isShared_2465_ = v_isSharedCheck_2469_;
goto v_resetjp_2463_;
}
v_resetjp_2463_:
{
lean_object* v___x_2467_; 
if (v_isShared_2465_ == 0)
{
v___x_2467_ = v___x_2464_;
goto v_reusejp_2466_;
}
else
{
lean_object* v_reuseFailAlloc_2468_; 
v_reuseFailAlloc_2468_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2468_, 0, v_a_2462_);
v___x_2467_ = v_reuseFailAlloc_2468_;
goto v_reusejp_2466_;
}
v_reusejp_2466_:
{
return v___x_2467_;
}
}
}
}
else
{
lean_object* v___x_2471_; 
lean_dec(v_a_2442_);
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
if (v_isShared_2445_ == 0)
{
lean_ctor_set(v___x_2444_, 0, v_inst_2296_);
v___x_2471_ = v___x_2444_;
goto v_reusejp_2470_;
}
else
{
lean_object* v_reuseFailAlloc_2472_; 
v_reuseFailAlloc_2472_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2472_, 0, v_inst_2296_);
v___x_2471_ = v_reuseFailAlloc_2472_;
goto v_reusejp_2470_;
}
v_reusejp_2470_:
{
return v___x_2471_;
}
}
}
}
else
{
lean_object* v_a_2474_; lean_object* v___x_2476_; uint8_t v_isShared_2477_; uint8_t v_isSharedCheck_2481_; 
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2474_ = lean_ctor_get(v___x_2441_, 0);
v_isSharedCheck_2481_ = !lean_is_exclusive(v___x_2441_);
if (v_isSharedCheck_2481_ == 0)
{
v___x_2476_ = v___x_2441_;
v_isShared_2477_ = v_isSharedCheck_2481_;
goto v_resetjp_2475_;
}
else
{
lean_inc(v_a_2474_);
lean_dec(v___x_2441_);
v___x_2476_ = lean_box(0);
v_isShared_2477_ = v_isSharedCheck_2481_;
goto v_resetjp_2475_;
}
v_resetjp_2475_:
{
lean_object* v___x_2479_; 
if (v_isShared_2477_ == 0)
{
v___x_2479_ = v___x_2476_;
goto v_reusejp_2478_;
}
else
{
lean_object* v_reuseFailAlloc_2480_; 
v_reuseFailAlloc_2480_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2480_, 0, v_a_2474_);
v___x_2479_ = v_reuseFailAlloc_2480_;
goto v_reusejp_2478_;
}
v_reusejp_2478_:
{
return v___x_2479_;
}
}
}
}
else
{
lean_object* v___x_2482_; 
v___x_2482_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v_a_2301_);
if (lean_obj_tag(v___x_2482_) == 0)
{
lean_object* v_a_2483_; lean_object* v___f_2484_; lean_object* v___x_2485_; lean_object* v___y_2487_; lean_object* v___y_2488_; lean_object* v_a_2489_; lean_object* v___y_2500_; lean_object* v___y_2501_; lean_object* v_a_2502_; lean_object* v___y_2505_; lean_object* v___y_2506_; lean_object* v_a_2507_; lean_object* v___y_2510_; lean_object* v___y_2511_; lean_object* v___y_2512_; lean_object* v___y_2516_; lean_object* v___y_2517_; lean_object* v_a_2518_; lean_object* v___y_2532_; lean_object* v___y_2533_; lean_object* v_a_2534_; lean_object* v___y_2537_; lean_object* v___y_2538_; lean_object* v_a_2539_; lean_object* v___y_2542_; lean_object* v___y_2543_; lean_object* v___y_2544_; uint8_t v___x_2596_; 
v_a_2483_ = lean_ctor_get(v___x_2482_, 0);
lean_inc(v_a_2483_);
lean_dec_ref(v___x_2482_);
lean_inc_ref(v_expectedType_2297_);
v___f_2484_ = lean_alloc_closure((void*)(l_Lean_Meta_normalizeInstance___lam__0___boxed), 7, 1);
lean_closure_set(v___f_2484_, 0, v_expectedType_2297_);
v___x_2485_ = ((lean_object*)(l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4___closed__0));
v___x_2596_ = lean_unbox(v_a_2483_);
if (v___x_2596_ == 0)
{
lean_object* v___x_2597_; uint8_t v___x_2598_; lean_object* v___y_2600_; lean_object* v___y_2601_; lean_object* v___y_2602_; lean_object* v___y_2603_; 
v___x_2597_ = l_Lean_trace_profiler;
v___x_2598_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2305_, v___x_2597_);
if (v___x_2598_ == 0)
{
lean_object* v___x_2686_; 
lean_dec_ref(v___f_2484_);
lean_dec(v_a_2483_);
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
lean_inc_ref(v_expectedType_2297_);
v___x_2686_ = l_Lean_Meta_isClass_x3f(v_expectedType_2297_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2686_) == 0)
{
lean_object* v_a_2687_; lean_object* v___x_2689_; uint8_t v_isShared_2690_; uint8_t v_isSharedCheck_2718_; 
v_a_2687_ = lean_ctor_get(v___x_2686_, 0);
v_isSharedCheck_2718_ = !lean_is_exclusive(v___x_2686_);
if (v_isSharedCheck_2718_ == 0)
{
v___x_2689_ = v___x_2686_;
v_isShared_2690_ = v_isSharedCheck_2718_;
goto v_resetjp_2688_;
}
else
{
lean_inc(v_a_2687_);
lean_dec(v___x_2686_);
v___x_2689_ = lean_box(0);
v_isShared_2690_ = v_isSharedCheck_2718_;
goto v_resetjp_2688_;
}
v_resetjp_2688_:
{
if (lean_obj_tag(v_a_2687_) == 1)
{
lean_object* v_val_2691_; lean_object* v___x_2692_; 
lean_del_object(v___x_2689_);
v_val_2691_ = lean_ctor_get(v_a_2687_, 0);
lean_inc(v_val_2691_);
lean_dec_ref(v_a_2687_);
v___x_2692_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v_a_2301_);
if (lean_obj_tag(v___x_2692_) == 0)
{
lean_object* v_a_2693_; uint8_t v___x_2694_; 
v_a_2693_ = lean_ctor_get(v___x_2692_, 0);
lean_inc(v_a_2693_);
lean_dec_ref(v___x_2692_);
v___x_2694_ = lean_unbox(v_a_2693_);
lean_dec(v_a_2693_);
if (v___x_2694_ == 0)
{
lean_dec(v_val_2691_);
v___y_2600_ = v___x_2440_;
v___y_2601_ = v_a_2300_;
v___y_2602_ = v_a_2301_;
v___y_2603_ = v_a_2302_;
goto v___jp_2599_;
}
else
{
lean_object* v___x_2695_; lean_object* v___x_2696_; lean_object* v___x_2697_; lean_object* v___x_2698_; 
v___x_2695_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___closed__2, &l_Lean_Meta_normalizeInstance___closed__2_once, _init_l_Lean_Meta_normalizeInstance___closed__2);
v___x_2696_ = l_Lean_MessageData_ofName(v_val_2691_);
v___x_2697_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2697_, 0, v___x_2695_);
lean_ctor_set(v___x_2697_, 1, v___x_2696_);
v___x_2698_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2697_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2698_) == 0)
{
lean_dec_ref(v___x_2698_);
v___y_2600_ = v___x_2440_;
v___y_2601_ = v_a_2300_;
v___y_2602_ = v_a_2301_;
v___y_2603_ = v_a_2302_;
goto v___jp_2599_;
}
else
{
lean_object* v_a_2699_; lean_object* v___x_2701_; uint8_t v_isShared_2702_; uint8_t v_isSharedCheck_2706_; 
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2699_ = lean_ctor_get(v___x_2698_, 0);
v_isSharedCheck_2706_ = !lean_is_exclusive(v___x_2698_);
if (v_isSharedCheck_2706_ == 0)
{
v___x_2701_ = v___x_2698_;
v_isShared_2702_ = v_isSharedCheck_2706_;
goto v_resetjp_2700_;
}
else
{
lean_inc(v_a_2699_);
lean_dec(v___x_2698_);
v___x_2701_ = lean_box(0);
v_isShared_2702_ = v_isSharedCheck_2706_;
goto v_resetjp_2700_;
}
v_resetjp_2700_:
{
lean_object* v___x_2704_; 
if (v_isShared_2702_ == 0)
{
v___x_2704_ = v___x_2701_;
goto v_reusejp_2703_;
}
else
{
lean_object* v_reuseFailAlloc_2705_; 
v_reuseFailAlloc_2705_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2705_, 0, v_a_2699_);
v___x_2704_ = v_reuseFailAlloc_2705_;
goto v_reusejp_2703_;
}
v_reusejp_2703_:
{
return v___x_2704_;
}
}
}
}
}
else
{
lean_object* v_a_2707_; lean_object* v___x_2709_; uint8_t v_isShared_2710_; uint8_t v_isSharedCheck_2714_; 
lean_dec(v_val_2691_);
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2707_ = lean_ctor_get(v___x_2692_, 0);
v_isSharedCheck_2714_ = !lean_is_exclusive(v___x_2692_);
if (v_isSharedCheck_2714_ == 0)
{
v___x_2709_ = v___x_2692_;
v_isShared_2710_ = v_isSharedCheck_2714_;
goto v_resetjp_2708_;
}
else
{
lean_inc(v_a_2707_);
lean_dec(v___x_2692_);
v___x_2709_ = lean_box(0);
v_isShared_2710_ = v_isSharedCheck_2714_;
goto v_resetjp_2708_;
}
v_resetjp_2708_:
{
lean_object* v___x_2712_; 
if (v_isShared_2710_ == 0)
{
v___x_2712_ = v___x_2709_;
goto v_reusejp_2711_;
}
else
{
lean_object* v_reuseFailAlloc_2713_; 
v_reuseFailAlloc_2713_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2713_, 0, v_a_2707_);
v___x_2712_ = v_reuseFailAlloc_2713_;
goto v_reusejp_2711_;
}
v_reusejp_2711_:
{
return v___x_2712_;
}
}
}
}
else
{
lean_object* v___x_2716_; 
lean_dec(v_a_2687_);
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
if (v_isShared_2690_ == 0)
{
lean_ctor_set(v___x_2689_, 0, v_inst_2296_);
v___x_2716_ = v___x_2689_;
goto v_reusejp_2715_;
}
else
{
lean_object* v_reuseFailAlloc_2717_; 
v_reuseFailAlloc_2717_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2717_, 0, v_inst_2296_);
v___x_2716_ = v_reuseFailAlloc_2717_;
goto v_reusejp_2715_;
}
v_reusejp_2715_:
{
return v___x_2716_;
}
}
}
}
else
{
lean_object* v_a_2719_; lean_object* v___x_2721_; uint8_t v_isShared_2722_; uint8_t v_isSharedCheck_2726_; 
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2719_ = lean_ctor_get(v___x_2686_, 0);
v_isSharedCheck_2726_ = !lean_is_exclusive(v___x_2686_);
if (v_isSharedCheck_2726_ == 0)
{
v___x_2721_ = v___x_2686_;
v_isShared_2722_ = v_isSharedCheck_2726_;
goto v_resetjp_2720_;
}
else
{
lean_inc(v_a_2719_);
lean_dec(v___x_2686_);
v___x_2721_ = lean_box(0);
v_isShared_2722_ = v_isSharedCheck_2726_;
goto v_resetjp_2720_;
}
v_resetjp_2720_:
{
lean_object* v___x_2724_; 
if (v_isShared_2722_ == 0)
{
v___x_2724_ = v___x_2721_;
goto v_reusejp_2723_;
}
else
{
lean_object* v_reuseFailAlloc_2725_; 
v_reuseFailAlloc_2725_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2725_, 0, v_a_2719_);
v___x_2724_ = v_reuseFailAlloc_2725_;
goto v_reusejp_2723_;
}
v_reusejp_2723_:
{
return v___x_2724_;
}
}
}
}
else
{
lean_inc_ref(v_options_2305_);
goto v___jp_2547_;
}
v___jp_2599_:
{
lean_object* v___x_2604_; 
lean_inc(v___y_2603_);
lean_inc_ref(v___y_2602_);
lean_inc(v___y_2601_);
lean_inc_ref(v___y_2600_);
lean_inc_ref(v_inst_2296_);
v___x_2604_ = lean_infer_type(v_inst_2296_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
if (lean_obj_tag(v___x_2604_) == 0)
{
lean_object* v_a_2605_; lean_object* v___x_2606_; 
v_a_2605_ = lean_ctor_get(v___x_2604_, 0);
lean_inc(v_a_2605_);
lean_dec_ref(v___x_2604_);
lean_inc(v___y_2603_);
lean_inc_ref(v___y_2602_);
lean_inc(v___y_2601_);
lean_inc_ref(v___y_2600_);
lean_inc_ref(v_expectedType_2297_);
v___x_2606_ = l_Lean_Meta_isExprDefEq(v_a_2605_, v_expectedType_2297_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
if (lean_obj_tag(v___x_2606_) == 0)
{
lean_object* v_a_2607_; uint8_t v___x_2608_; 
v_a_2607_ = lean_ctor_get(v___x_2606_, 0);
lean_inc(v_a_2607_);
lean_dec_ref(v___x_2606_);
v___x_2608_ = lean_unbox(v_a_2607_);
lean_dec(v_a_2607_);
if (v___x_2608_ == 0)
{
lean_object* v___x_2609_; 
lean_inc(v___y_2603_);
lean_inc_ref(v___y_2602_);
lean_inc(v___y_2601_);
lean_inc_ref(v___y_2600_);
lean_inc_ref(v_expectedType_2297_);
v___x_2609_ = l_Lean_Meta_isProp(v_expectedType_2297_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
if (lean_obj_tag(v___x_2609_) == 0)
{
lean_object* v_a_2610_; lean_object* v___x_2612_; uint8_t v_isShared_2613_; uint8_t v_isSharedCheck_2631_; 
v_a_2610_ = lean_ctor_get(v___x_2609_, 0);
v_isSharedCheck_2631_ = !lean_is_exclusive(v___x_2609_);
if (v_isSharedCheck_2631_ == 0)
{
v___x_2612_ = v___x_2609_;
v_isShared_2613_ = v_isSharedCheck_2631_;
goto v_resetjp_2611_;
}
else
{
lean_inc(v_a_2610_);
lean_dec(v___x_2609_);
v___x_2612_ = lean_box(0);
v_isShared_2613_ = v_isSharedCheck_2631_;
goto v_resetjp_2611_;
}
v_resetjp_2611_:
{
uint8_t v___x_2614_; 
v___x_2614_ = lean_unbox(v_a_2610_);
lean_dec(v_a_2610_);
if (v___x_2614_ == 0)
{
lean_object* v___x_2615_; 
lean_del_object(v___x_2612_);
lean_inc(v___y_2603_);
lean_inc_ref(v___y_2602_);
lean_inc(v___y_2601_);
lean_inc_ref(v___y_2600_);
v___x_2615_ = lean_whnf(v_inst_2296_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
if (lean_obj_tag(v___x_2615_) == 0)
{
lean_object* v_a_2616_; lean_object* v_dummy_2617_; lean_object* v_nargs_2618_; lean_object* v___x_2619_; lean_object* v___x_2620_; lean_object* v___x_2621_; lean_object* v___x_2622_; 
v_a_2616_ = lean_ctor_get(v___x_2615_, 0);
lean_inc(v_a_2616_);
lean_dec_ref(v___x_2615_);
v_dummy_2617_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__0, &l_Lean_Meta_normalizeInstance___lam__1___closed__0_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__0);
v_nargs_2618_ = l_Lean_Expr_getAppNumArgs(v_a_2616_);
lean_inc(v_nargs_2618_);
v___x_2619_ = lean_mk_array(v_nargs_2618_, v_dummy_2617_);
v___x_2620_ = lean_unsigned_to_nat(1u);
v___x_2621_ = lean_nat_sub(v_nargs_2618_, v___x_2620_);
lean_dec(v_nargs_2618_);
lean_inc(v_a_2616_);
v___x_2622_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15(v_a_2616_, v_expectedType_2297_, v___x_2598_, v_compile_2298_, v_hasTrace_2337_, v_a_2616_, v___x_2619_, v___x_2621_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
return v___x_2622_;
}
else
{
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_expectedType_2297_);
return v___x_2615_;
}
}
else
{
lean_object* v_options_2623_; lean_object* v___x_2624_; uint8_t v___x_2625_; 
v_options_2623_ = lean_ctor_get(v___y_2602_, 2);
v___x_2624_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_2625_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2623_, v___x_2624_);
if (v___x_2625_ == 0)
{
lean_object* v___x_2627_; 
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_expectedType_2297_);
if (v_isShared_2613_ == 0)
{
lean_ctor_set(v___x_2612_, 0, v_inst_2296_);
v___x_2627_ = v___x_2612_;
goto v_reusejp_2626_;
}
else
{
lean_object* v_reuseFailAlloc_2628_; 
v_reuseFailAlloc_2628_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2628_, 0, v_inst_2296_);
v___x_2627_ = v_reuseFailAlloc_2628_;
goto v_reusejp_2626_;
}
v_reusejp_2626_:
{
return v___x_2627_;
}
}
else
{
lean_object* v___x_2629_; lean_object* v___x_2630_; 
lean_del_object(v___x_2612_);
v___x_2629_ = lean_box(0);
v___x_2630_ = l_Lean_Meta_mkAuxTheorem(v_expectedType_2297_, v_inst_2296_, v_hasTrace_2337_, v___x_2629_, v_hasTrace_2337_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
return v___x_2630_;
}
}
}
}
else
{
lean_object* v_a_2632_; lean_object* v___x_2634_; uint8_t v_isShared_2635_; uint8_t v_isSharedCheck_2639_; 
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2632_ = lean_ctor_get(v___x_2609_, 0);
v_isSharedCheck_2639_ = !lean_is_exclusive(v___x_2609_);
if (v_isSharedCheck_2639_ == 0)
{
v___x_2634_ = v___x_2609_;
v_isShared_2635_ = v_isSharedCheck_2639_;
goto v_resetjp_2633_;
}
else
{
lean_inc(v_a_2632_);
lean_dec(v___x_2609_);
v___x_2634_ = lean_box(0);
v_isShared_2635_ = v_isSharedCheck_2639_;
goto v_resetjp_2633_;
}
v_resetjp_2633_:
{
lean_object* v___x_2637_; 
if (v_isShared_2635_ == 0)
{
v___x_2637_ = v___x_2634_;
goto v_reusejp_2636_;
}
else
{
lean_object* v_reuseFailAlloc_2638_; 
v_reuseFailAlloc_2638_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2638_, 0, v_a_2632_);
v___x_2637_ = v_reuseFailAlloc_2638_;
goto v_reusejp_2636_;
}
v_reusejp_2636_:
{
return v___x_2637_;
}
}
}
}
else
{
lean_object* v___x_2640_; 
lean_dec_ref(v_expectedType_2297_);
v___x_2640_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v___y_2602_);
if (lean_obj_tag(v___x_2640_) == 0)
{
lean_object* v_a_2641_; lean_object* v___x_2643_; uint8_t v_isShared_2644_; uint8_t v_isSharedCheck_2669_; 
v_a_2641_ = lean_ctor_get(v___x_2640_, 0);
v_isSharedCheck_2669_ = !lean_is_exclusive(v___x_2640_);
if (v_isSharedCheck_2669_ == 0)
{
v___x_2643_ = v___x_2640_;
v_isShared_2644_ = v_isSharedCheck_2669_;
goto v_resetjp_2642_;
}
else
{
lean_inc(v_a_2641_);
lean_dec(v___x_2640_);
v___x_2643_ = lean_box(0);
v_isShared_2644_ = v_isSharedCheck_2669_;
goto v_resetjp_2642_;
}
v_resetjp_2642_:
{
uint8_t v___x_2645_; 
v___x_2645_ = lean_unbox(v_a_2641_);
lean_dec(v_a_2641_);
if (v___x_2645_ == 0)
{
lean_object* v___x_2647_; 
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
if (v_isShared_2644_ == 0)
{
lean_ctor_set(v___x_2643_, 0, v_inst_2296_);
v___x_2647_ = v___x_2643_;
goto v_reusejp_2646_;
}
else
{
lean_object* v_reuseFailAlloc_2648_; 
v_reuseFailAlloc_2648_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2648_, 0, v_inst_2296_);
v___x_2647_ = v_reuseFailAlloc_2648_;
goto v_reusejp_2646_;
}
v_reusejp_2646_:
{
return v___x_2647_;
}
}
else
{
lean_object* v___x_2649_; lean_object* v___x_2650_; lean_object* v___x_2651_; lean_object* v___x_2652_; 
lean_del_object(v___x_2643_);
v___x_2649_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__2, &l_Lean_Meta_normalizeInstance___lam__1___closed__2_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__2);
lean_inc_ref(v_inst_2296_);
v___x_2650_ = l_Lean_MessageData_ofExpr(v_inst_2296_);
v___x_2651_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2651_, 0, v___x_2649_);
lean_ctor_set(v___x_2651_, 1, v___x_2650_);
v___x_2652_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2651_, v___y_2600_, v___y_2601_, v___y_2602_, v___y_2603_);
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
if (lean_obj_tag(v___x_2652_) == 0)
{
lean_object* v___x_2654_; uint8_t v_isShared_2655_; uint8_t v_isSharedCheck_2659_; 
v_isSharedCheck_2659_ = !lean_is_exclusive(v___x_2652_);
if (v_isSharedCheck_2659_ == 0)
{
lean_object* v_unused_2660_; 
v_unused_2660_ = lean_ctor_get(v___x_2652_, 0);
lean_dec(v_unused_2660_);
v___x_2654_ = v___x_2652_;
v_isShared_2655_ = v_isSharedCheck_2659_;
goto v_resetjp_2653_;
}
else
{
lean_dec(v___x_2652_);
v___x_2654_ = lean_box(0);
v_isShared_2655_ = v_isSharedCheck_2659_;
goto v_resetjp_2653_;
}
v_resetjp_2653_:
{
lean_object* v___x_2657_; 
if (v_isShared_2655_ == 0)
{
lean_ctor_set(v___x_2654_, 0, v_inst_2296_);
v___x_2657_ = v___x_2654_;
goto v_reusejp_2656_;
}
else
{
lean_object* v_reuseFailAlloc_2658_; 
v_reuseFailAlloc_2658_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2658_, 0, v_inst_2296_);
v___x_2657_ = v_reuseFailAlloc_2658_;
goto v_reusejp_2656_;
}
v_reusejp_2656_:
{
return v___x_2657_;
}
}
}
else
{
lean_object* v_a_2661_; lean_object* v___x_2663_; uint8_t v_isShared_2664_; uint8_t v_isSharedCheck_2668_; 
lean_dec_ref(v_inst_2296_);
v_a_2661_ = lean_ctor_get(v___x_2652_, 0);
v_isSharedCheck_2668_ = !lean_is_exclusive(v___x_2652_);
if (v_isSharedCheck_2668_ == 0)
{
v___x_2663_ = v___x_2652_;
v_isShared_2664_ = v_isSharedCheck_2668_;
goto v_resetjp_2662_;
}
else
{
lean_inc(v_a_2661_);
lean_dec(v___x_2652_);
v___x_2663_ = lean_box(0);
v_isShared_2664_ = v_isSharedCheck_2668_;
goto v_resetjp_2662_;
}
v_resetjp_2662_:
{
lean_object* v___x_2666_; 
if (v_isShared_2664_ == 0)
{
v___x_2666_ = v___x_2663_;
goto v_reusejp_2665_;
}
else
{
lean_object* v_reuseFailAlloc_2667_; 
v_reuseFailAlloc_2667_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2667_, 0, v_a_2661_);
v___x_2666_ = v_reuseFailAlloc_2667_;
goto v_reusejp_2665_;
}
v_reusejp_2665_:
{
return v___x_2666_;
}
}
}
}
}
}
else
{
lean_object* v_a_2670_; lean_object* v___x_2672_; uint8_t v_isShared_2673_; uint8_t v_isSharedCheck_2677_; 
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_inst_2296_);
v_a_2670_ = lean_ctor_get(v___x_2640_, 0);
v_isSharedCheck_2677_ = !lean_is_exclusive(v___x_2640_);
if (v_isSharedCheck_2677_ == 0)
{
v___x_2672_ = v___x_2640_;
v_isShared_2673_ = v_isSharedCheck_2677_;
goto v_resetjp_2671_;
}
else
{
lean_inc(v_a_2670_);
lean_dec(v___x_2640_);
v___x_2672_ = lean_box(0);
v_isShared_2673_ = v_isSharedCheck_2677_;
goto v_resetjp_2671_;
}
v_resetjp_2671_:
{
lean_object* v___x_2675_; 
if (v_isShared_2673_ == 0)
{
v___x_2675_ = v___x_2672_;
goto v_reusejp_2674_;
}
else
{
lean_object* v_reuseFailAlloc_2676_; 
v_reuseFailAlloc_2676_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2676_, 0, v_a_2670_);
v___x_2675_ = v_reuseFailAlloc_2676_;
goto v_reusejp_2674_;
}
v_reusejp_2674_:
{
return v___x_2675_;
}
}
}
}
}
else
{
lean_object* v_a_2678_; lean_object* v___x_2680_; uint8_t v_isShared_2681_; uint8_t v_isSharedCheck_2685_; 
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2678_ = lean_ctor_get(v___x_2606_, 0);
v_isSharedCheck_2685_ = !lean_is_exclusive(v___x_2606_);
if (v_isSharedCheck_2685_ == 0)
{
v___x_2680_ = v___x_2606_;
v_isShared_2681_ = v_isSharedCheck_2685_;
goto v_resetjp_2679_;
}
else
{
lean_inc(v_a_2678_);
lean_dec(v___x_2606_);
v___x_2680_ = lean_box(0);
v_isShared_2681_ = v_isSharedCheck_2685_;
goto v_resetjp_2679_;
}
v_resetjp_2679_:
{
lean_object* v___x_2683_; 
if (v_isShared_2681_ == 0)
{
v___x_2683_ = v___x_2680_;
goto v_reusejp_2682_;
}
else
{
lean_object* v_reuseFailAlloc_2684_; 
v_reuseFailAlloc_2684_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2684_, 0, v_a_2678_);
v___x_2683_ = v_reuseFailAlloc_2684_;
goto v_reusejp_2682_;
}
v_reusejp_2682_:
{
return v___x_2683_;
}
}
}
}
else
{
lean_dec(v___y_2603_);
lean_dec_ref(v___y_2602_);
lean_dec(v___y_2601_);
lean_dec_ref(v___y_2600_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
return v___x_2604_;
}
}
}
else
{
lean_inc_ref(v_options_2305_);
goto v___jp_2547_;
}
v___jp_2486_:
{
lean_object* v___x_2490_; double v___x_2491_; double v___x_2492_; lean_object* v___x_2493_; lean_object* v___x_2494_; lean_object* v___x_2495_; lean_object* v___x_2496_; uint8_t v___x_2497_; lean_object* v___x_2498_; 
v___x_2490_ = lean_io_get_num_heartbeats();
v___x_2491_ = lean_float_of_nat(v___y_2488_);
v___x_2492_ = lean_float_of_nat(v___x_2490_);
v___x_2493_ = lean_box_float(v___x_2491_);
v___x_2494_ = lean_box_float(v___x_2492_);
v___x_2495_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2495_, 0, v___x_2493_);
lean_ctor_set(v___x_2495_, 1, v___x_2494_);
v___x_2496_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2496_, 0, v_a_2489_);
lean_ctor_set(v___x_2496_, 1, v___x_2495_);
v___x_2497_ = lean_unbox(v_a_2483_);
lean_dec(v_a_2483_);
v___x_2498_ = l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18(v_cls_2347_, v_hasTrace_2337_, v___x_2485_, v_options_2305_, v___x_2497_, v___y_2487_, v___f_2484_, v___x_2496_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
lean_dec_ref(v_options_2305_);
return v___x_2498_;
}
v___jp_2499_:
{
lean_object* v___x_2503_; 
v___x_2503_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2503_, 0, v_a_2502_);
v___y_2487_ = v___y_2500_;
v___y_2488_ = v___y_2501_;
v_a_2489_ = v___x_2503_;
goto v___jp_2486_;
}
v___jp_2504_:
{
lean_object* v___x_2508_; 
v___x_2508_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2508_, 0, v_a_2507_);
v___y_2487_ = v___y_2505_;
v___y_2488_ = v___y_2506_;
v_a_2489_ = v___x_2508_;
goto v___jp_2486_;
}
v___jp_2509_:
{
if (lean_obj_tag(v___y_2512_) == 0)
{
lean_object* v_a_2513_; 
v_a_2513_ = lean_ctor_get(v___y_2512_, 0);
lean_inc(v_a_2513_);
lean_dec_ref(v___y_2512_);
v___y_2500_ = v___y_2510_;
v___y_2501_ = v___y_2511_;
v_a_2502_ = v_a_2513_;
goto v___jp_2499_;
}
else
{
lean_object* v_a_2514_; 
v_a_2514_ = lean_ctor_get(v___y_2512_, 0);
lean_inc(v_a_2514_);
lean_dec_ref(v___y_2512_);
v___y_2505_ = v___y_2510_;
v___y_2506_ = v___y_2511_;
v_a_2507_ = v_a_2514_;
goto v___jp_2504_;
}
}
v___jp_2515_:
{
lean_object* v___x_2519_; double v___x_2520_; double v___x_2521_; double v___x_2522_; double v___x_2523_; double v___x_2524_; lean_object* v___x_2525_; lean_object* v___x_2526_; lean_object* v___x_2527_; lean_object* v___x_2528_; uint8_t v___x_2529_; lean_object* v___x_2530_; 
v___x_2519_ = lean_io_mono_nanos_now();
v___x_2520_ = lean_float_of_nat(v___y_2517_);
v___x_2521_ = lean_float_once(&l_Lean_Meta_normalizeInstance___closed__3, &l_Lean_Meta_normalizeInstance___closed__3_once, _init_l_Lean_Meta_normalizeInstance___closed__3);
v___x_2522_ = lean_float_div(v___x_2520_, v___x_2521_);
v___x_2523_ = lean_float_of_nat(v___x_2519_);
v___x_2524_ = lean_float_div(v___x_2523_, v___x_2521_);
v___x_2525_ = lean_box_float(v___x_2522_);
v___x_2526_ = lean_box_float(v___x_2524_);
v___x_2527_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2527_, 0, v___x_2525_);
lean_ctor_set(v___x_2527_, 1, v___x_2526_);
v___x_2528_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2528_, 0, v_a_2518_);
lean_ctor_set(v___x_2528_, 1, v___x_2527_);
v___x_2529_ = lean_unbox(v_a_2483_);
lean_dec(v_a_2483_);
v___x_2530_ = l___private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18(v_cls_2347_, v_hasTrace_2337_, v___x_2485_, v_options_2305_, v___x_2529_, v___y_2516_, v___f_2484_, v___x_2528_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
lean_dec_ref(v_options_2305_);
return v___x_2530_;
}
v___jp_2531_:
{
lean_object* v___x_2535_; 
v___x_2535_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2535_, 0, v_a_2534_);
v___y_2516_ = v___y_2532_;
v___y_2517_ = v___y_2533_;
v_a_2518_ = v___x_2535_;
goto v___jp_2515_;
}
v___jp_2536_:
{
lean_object* v___x_2540_; 
v___x_2540_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2540_, 0, v_a_2539_);
v___y_2516_ = v___y_2537_;
v___y_2517_ = v___y_2538_;
v_a_2518_ = v___x_2540_;
goto v___jp_2515_;
}
v___jp_2541_:
{
if (lean_obj_tag(v___y_2544_) == 0)
{
lean_object* v_a_2545_; 
v_a_2545_ = lean_ctor_get(v___y_2544_, 0);
lean_inc(v_a_2545_);
lean_dec_ref(v___y_2544_);
v___y_2532_ = v___y_2542_;
v___y_2533_ = v___y_2543_;
v_a_2534_ = v_a_2545_;
goto v___jp_2531_;
}
else
{
lean_object* v_a_2546_; 
v_a_2546_ = lean_ctor_get(v___y_2544_, 0);
lean_inc(v_a_2546_);
lean_dec_ref(v___y_2544_);
v___y_2537_ = v___y_2542_;
v___y_2538_ = v___y_2543_;
v_a_2539_ = v_a_2546_;
goto v___jp_2536_;
}
}
v___jp_2547_:
{
lean_object* v___x_2548_; 
v___x_2548_ = l___private_Lean_Util_Trace_0__Lean_getResetTraces___at___00Lean_Meta_normalizeInstance_spec__13___redArg(v_a_2302_);
if (lean_obj_tag(v___x_2548_) == 0)
{
lean_object* v_a_2549_; lean_object* v___x_2550_; uint8_t v___x_2551_; 
v_a_2549_ = lean_ctor_get(v___x_2548_, 0);
lean_inc(v_a_2549_);
lean_dec_ref(v___x_2548_);
v___x_2550_ = l_Lean_trace_profiler_useHeartbeats;
v___x_2551_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2305_, v___x_2550_);
if (v___x_2551_ == 0)
{
lean_object* v___x_2552_; lean_object* v___x_2553_; 
v___x_2552_ = lean_io_mono_nanos_now();
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
lean_inc_ref(v_expectedType_2297_);
v___x_2553_ = l_Lean_Meta_isClass_x3f(v_expectedType_2297_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2553_) == 0)
{
lean_object* v_a_2554_; 
v_a_2554_ = lean_ctor_get(v___x_2553_, 0);
lean_inc(v_a_2554_);
lean_dec_ref(v___x_2553_);
if (lean_obj_tag(v_a_2554_) == 1)
{
lean_object* v_val_2555_; lean_object* v___x_2556_; 
v_val_2555_ = lean_ctor_get(v_a_2554_, 0);
lean_inc(v_val_2555_);
lean_dec_ref(v_a_2554_);
v___x_2556_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v_a_2301_);
if (lean_obj_tag(v___x_2556_) == 0)
{
lean_object* v_a_2557_; uint8_t v___x_2558_; 
v_a_2557_ = lean_ctor_get(v___x_2556_, 0);
lean_inc(v_a_2557_);
lean_dec_ref(v___x_2556_);
v___x_2558_ = lean_unbox(v_a_2557_);
lean_dec(v_a_2557_);
if (v___x_2558_ == 0)
{
lean_object* v___x_2559_; lean_object* v___x_2560_; 
lean_dec(v_val_2555_);
v___x_2559_ = lean_box(0);
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
v___x_2560_ = l_Lean_Meta_normalizeInstance___lam__1(v_inst_2296_, v_expectedType_2297_, v___x_2551_, v_compile_2298_, v_hasTrace_2337_, v_cls_2347_, v___x_2559_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
v___y_2542_ = v_a_2549_;
v___y_2543_ = v___x_2552_;
v___y_2544_ = v___x_2560_;
goto v___jp_2541_;
}
else
{
lean_object* v___x_2561_; lean_object* v___x_2562_; lean_object* v___x_2563_; lean_object* v___x_2564_; 
v___x_2561_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___closed__2, &l_Lean_Meta_normalizeInstance___closed__2_once, _init_l_Lean_Meta_normalizeInstance___closed__2);
v___x_2562_ = l_Lean_MessageData_ofName(v_val_2555_);
v___x_2563_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2563_, 0, v___x_2561_);
lean_ctor_set(v___x_2563_, 1, v___x_2562_);
v___x_2564_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2563_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2564_) == 0)
{
lean_object* v_a_2565_; lean_object* v___x_2566_; 
v_a_2565_ = lean_ctor_get(v___x_2564_, 0);
lean_inc(v_a_2565_);
lean_dec_ref(v___x_2564_);
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
v___x_2566_ = l_Lean_Meta_normalizeInstance___lam__1(v_inst_2296_, v_expectedType_2297_, v___x_2551_, v_compile_2298_, v_hasTrace_2337_, v_cls_2347_, v_a_2565_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
v___y_2542_ = v_a_2549_;
v___y_2543_ = v___x_2552_;
v___y_2544_ = v___x_2566_;
goto v___jp_2541_;
}
else
{
lean_object* v_a_2567_; 
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2567_ = lean_ctor_get(v___x_2564_, 0);
lean_inc(v_a_2567_);
lean_dec_ref(v___x_2564_);
v___y_2537_ = v_a_2549_;
v___y_2538_ = v___x_2552_;
v_a_2539_ = v_a_2567_;
goto v___jp_2536_;
}
}
}
else
{
lean_object* v_a_2568_; 
lean_dec(v_val_2555_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2568_ = lean_ctor_get(v___x_2556_, 0);
lean_inc(v_a_2568_);
lean_dec_ref(v___x_2556_);
v___y_2537_ = v_a_2549_;
v___y_2538_ = v___x_2552_;
v_a_2539_ = v_a_2568_;
goto v___jp_2536_;
}
}
else
{
lean_dec(v_a_2554_);
lean_dec_ref(v_expectedType_2297_);
v___y_2532_ = v_a_2549_;
v___y_2533_ = v___x_2552_;
v_a_2534_ = v_inst_2296_;
goto v___jp_2531_;
}
}
else
{
lean_object* v_a_2569_; 
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2569_ = lean_ctor_get(v___x_2553_, 0);
lean_inc(v_a_2569_);
lean_dec_ref(v___x_2553_);
v___y_2537_ = v_a_2549_;
v___y_2538_ = v___x_2552_;
v_a_2539_ = v_a_2569_;
goto v___jp_2536_;
}
}
else
{
lean_object* v___x_2570_; lean_object* v___x_2571_; 
v___x_2570_ = lean_io_get_num_heartbeats();
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
lean_inc_ref(v_expectedType_2297_);
v___x_2571_ = l_Lean_Meta_isClass_x3f(v_expectedType_2297_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2571_) == 0)
{
lean_object* v_a_2572_; 
v_a_2572_ = lean_ctor_get(v___x_2571_, 0);
lean_inc(v_a_2572_);
lean_dec_ref(v___x_2571_);
if (lean_obj_tag(v_a_2572_) == 1)
{
lean_object* v_val_2573_; lean_object* v___x_2574_; 
v_val_2573_ = lean_ctor_get(v_a_2572_, 0);
lean_inc(v_val_2573_);
lean_dec_ref(v_a_2572_);
v___x_2574_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2347_, v_a_2301_);
if (lean_obj_tag(v___x_2574_) == 0)
{
lean_object* v_a_2575_; uint8_t v___x_2576_; 
v_a_2575_ = lean_ctor_get(v___x_2574_, 0);
lean_inc(v_a_2575_);
lean_dec_ref(v___x_2574_);
v___x_2576_ = lean_unbox(v_a_2575_);
lean_dec(v_a_2575_);
if (v___x_2576_ == 0)
{
lean_object* v___x_2577_; lean_object* v___x_2578_; 
lean_dec(v_val_2573_);
v___x_2577_ = lean_box(0);
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
v___x_2578_ = l_Lean_Meta_normalizeInstance___lam__2(v_inst_2296_, v_expectedType_2297_, v_compile_2298_, v___x_2551_, v_cls_2347_, v___x_2577_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
v___y_2510_ = v_a_2549_;
v___y_2511_ = v___x_2570_;
v___y_2512_ = v___x_2578_;
goto v___jp_2509_;
}
else
{
lean_object* v___x_2579_; lean_object* v___x_2580_; lean_object* v___x_2581_; lean_object* v___x_2582_; 
v___x_2579_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___closed__2, &l_Lean_Meta_normalizeInstance___closed__2_once, _init_l_Lean_Meta_normalizeInstance___closed__2);
v___x_2580_ = l_Lean_MessageData_ofName(v_val_2573_);
v___x_2581_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2581_, 0, v___x_2579_);
lean_ctor_set(v___x_2581_, 1, v___x_2580_);
v___x_2582_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2347_, v___x_2581_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
if (lean_obj_tag(v___x_2582_) == 0)
{
lean_object* v_a_2583_; lean_object* v___x_2584_; 
v_a_2583_ = lean_ctor_get(v___x_2582_, 0);
lean_inc(v_a_2583_);
lean_dec_ref(v___x_2582_);
lean_inc(v_a_2302_);
lean_inc_ref(v_a_2301_);
lean_inc(v_a_2300_);
lean_inc_ref(v___x_2440_);
v___x_2584_ = l_Lean_Meta_normalizeInstance___lam__2(v_inst_2296_, v_expectedType_2297_, v_compile_2298_, v___x_2551_, v_cls_2347_, v_a_2583_, v___x_2440_, v_a_2300_, v_a_2301_, v_a_2302_);
v___y_2510_ = v_a_2549_;
v___y_2511_ = v___x_2570_;
v___y_2512_ = v___x_2584_;
goto v___jp_2509_;
}
else
{
lean_object* v_a_2585_; 
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2585_ = lean_ctor_get(v___x_2582_, 0);
lean_inc(v_a_2585_);
lean_dec_ref(v___x_2582_);
v___y_2505_ = v_a_2549_;
v___y_2506_ = v___x_2570_;
v_a_2507_ = v_a_2585_;
goto v___jp_2504_;
}
}
}
else
{
lean_object* v_a_2586_; 
lean_dec(v_val_2573_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2586_ = lean_ctor_get(v___x_2574_, 0);
lean_inc(v_a_2586_);
lean_dec_ref(v___x_2574_);
v___y_2505_ = v_a_2549_;
v___y_2506_ = v___x_2570_;
v_a_2507_ = v_a_2586_;
goto v___jp_2504_;
}
}
else
{
lean_dec(v_a_2572_);
lean_dec_ref(v_expectedType_2297_);
v___y_2500_ = v_a_2549_;
v___y_2501_ = v___x_2570_;
v_a_2502_ = v_inst_2296_;
goto v___jp_2499_;
}
}
else
{
lean_object* v_a_2587_; 
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2587_ = lean_ctor_get(v___x_2571_, 0);
lean_inc(v_a_2587_);
lean_dec_ref(v___x_2571_);
v___y_2505_ = v_a_2549_;
v___y_2506_ = v___x_2570_;
v_a_2507_ = v_a_2587_;
goto v___jp_2504_;
}
}
}
else
{
lean_object* v_a_2588_; lean_object* v___x_2590_; uint8_t v_isShared_2591_; uint8_t v_isSharedCheck_2595_; 
lean_dec_ref(v___f_2484_);
lean_dec(v_a_2483_);
lean_dec_ref(v___x_2440_);
lean_dec_ref(v_options_2305_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2588_ = lean_ctor_get(v___x_2548_, 0);
v_isSharedCheck_2595_ = !lean_is_exclusive(v___x_2548_);
if (v_isSharedCheck_2595_ == 0)
{
v___x_2590_ = v___x_2548_;
v_isShared_2591_ = v_isSharedCheck_2595_;
goto v_resetjp_2589_;
}
else
{
lean_inc(v_a_2588_);
lean_dec(v___x_2548_);
v___x_2590_ = lean_box(0);
v_isShared_2591_ = v_isSharedCheck_2595_;
goto v_resetjp_2589_;
}
v_resetjp_2589_:
{
lean_object* v___x_2593_; 
if (v_isShared_2591_ == 0)
{
v___x_2593_ = v___x_2590_;
goto v_reusejp_2592_;
}
else
{
lean_object* v_reuseFailAlloc_2594_; 
v_reuseFailAlloc_2594_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2594_, 0, v_a_2588_);
v___x_2593_ = v_reuseFailAlloc_2594_;
goto v_reusejp_2592_;
}
v_reusejp_2592_:
{
return v___x_2593_;
}
}
}
}
}
else
{
lean_object* v_a_2727_; lean_object* v___x_2729_; uint8_t v_isShared_2730_; uint8_t v_isSharedCheck_2734_; 
lean_dec_ref(v___x_2440_);
lean_dec(v_a_2302_);
lean_dec_ref(v_a_2301_);
lean_dec(v_a_2300_);
lean_dec_ref(v_expectedType_2297_);
lean_dec_ref(v_inst_2296_);
v_a_2727_ = lean_ctor_get(v___x_2482_, 0);
v_isSharedCheck_2734_ = !lean_is_exclusive(v___x_2482_);
if (v_isSharedCheck_2734_ == 0)
{
v___x_2729_ = v___x_2482_;
v_isShared_2730_ = v_isSharedCheck_2734_;
goto v_resetjp_2728_;
}
else
{
lean_inc(v_a_2727_);
lean_dec(v___x_2482_);
v___x_2729_ = lean_box(0);
v_isShared_2730_ = v_isSharedCheck_2734_;
goto v_resetjp_2728_;
}
v_resetjp_2728_:
{
lean_object* v___x_2732_; 
if (v_isShared_2730_ == 0)
{
v___x_2732_ = v___x_2729_;
goto v_reusejp_2731_;
}
else
{
lean_object* v_reuseFailAlloc_2733_; 
v_reuseFailAlloc_2733_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2733_, 0, v_a_2727_);
v___x_2732_ = v_reuseFailAlloc_2733_;
goto v_reusejp_2731_;
}
v_reusejp_2731_:
{
return v___x_2732_;
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg(lean_object* v_upperBound_2746_, lean_object* v_fst_2747_, lean_object* v_args_2748_, uint8_t v_compile_2749_, uint8_t v___x_2750_, uint8_t v___x_2751_, lean_object* v_a_2752_, lean_object* v_b_2753_, lean_object* v___y_2754_, lean_object* v___y_2755_, lean_object* v___y_2756_, lean_object* v___y_2757_){
_start:
{
lean_object* v_a_2760_; uint8_t v___x_2764_; 
v___x_2764_ = lean_nat_dec_lt(v_a_2752_, v_upperBound_2746_);
if (v___x_2764_ == 0)
{
lean_object* v___x_2765_; 
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v___x_2765_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2765_, 0, v_b_2753_);
return v___x_2765_;
}
else
{
lean_object* v___x_2766_; lean_object* v___x_2767_; lean_object* v___x_2768_; 
v___x_2766_ = lean_array_fget_borrowed(v_fst_2747_, v_a_2752_);
v___x_2767_ = l_Lean_Expr_mvarId_x21(v___x_2766_);
lean_inc(v___x_2767_);
v___x_2768_ = l_Lean_MVarId_getDecl(v___x_2767_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2768_) == 0)
{
lean_object* v_a_2769_; lean_object* v_type_2770_; lean_object* v___x_2771_; 
v_a_2769_ = lean_ctor_get(v___x_2768_, 0);
lean_inc(v_a_2769_);
lean_dec_ref(v___x_2768_);
v_type_2770_ = lean_ctor_get(v_a_2769_, 2);
lean_inc_ref(v_type_2770_);
lean_dec(v_a_2769_);
v___x_2771_ = l_Lean_instantiateMVars___at___00Lean_Meta_normalizeInstance_spec__6___redArg(v_type_2770_, v___y_2755_);
if (lean_obj_tag(v___x_2771_) == 0)
{
lean_object* v_a_2772_; lean_object* v___x_2773_; 
v_a_2772_ = lean_ctor_get(v___x_2771_, 0);
lean_inc(v_a_2772_);
lean_dec_ref(v___x_2771_);
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v_a_2772_);
v___x_2773_ = l_Lean_Meta_isProp(v_a_2772_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2773_) == 0)
{
lean_object* v_a_2774_; lean_object* v___x_2775_; lean_object* v___x_2776_; uint8_t v___x_2777_; 
v_a_2774_ = lean_ctor_get(v___x_2773_, 0);
lean_inc(v_a_2774_);
lean_dec_ref(v___x_2773_);
v___x_2775_ = lean_box(0);
v___x_2776_ = lean_array_fget_borrowed(v_args_2748_, v_a_2752_);
v___x_2777_ = lean_unbox(v_a_2774_);
lean_dec(v_a_2774_);
if (v___x_2777_ == 0)
{
lean_object* v___x_2778_; 
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v_a_2772_);
v___x_2778_ = l_Lean_Meta_isClass_x3f(v_a_2772_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2778_) == 0)
{
lean_object* v_a_2779_; 
v_a_2779_ = lean_ctor_get(v___x_2778_, 0);
lean_inc(v_a_2779_);
lean_dec_ref(v___x_2778_);
if (lean_obj_tag(v_a_2779_) == 0)
{
if (v___x_2750_ == 0)
{
lean_object* v_options_2792_; lean_object* v___x_2793_; uint8_t v___x_2794_; 
v_options_2792_ = lean_ctor_get(v___y_2756_, 2);
v___x_2793_ = l_Lean_Meta_instance_normalForm_wrapFields_data;
v___x_2794_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2792_, v___x_2793_);
if (v___x_2794_ == 0)
{
lean_object* v___x_2795_; 
lean_dec(v_a_2772_);
lean_inc(v___x_2776_);
v___x_2795_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v___x_2776_, v___y_2755_);
if (lean_obj_tag(v___x_2795_) == 0)
{
lean_dec_ref(v___x_2795_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2795_;
}
}
else
{
lean_object* v___x_2796_; 
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v___x_2776_);
v___x_2796_ = lean_infer_type(v___x_2776_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2796_) == 0)
{
lean_object* v_a_2797_; lean_object* v___x_2798_; 
v_a_2797_ = lean_ctor_get(v___x_2796_, 0);
lean_inc(v_a_2797_);
lean_dec_ref(v___x_2796_);
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v_a_2772_);
v___x_2798_ = l_Lean_Meta_isExprDefEq(v_a_2772_, v_a_2797_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2798_) == 0)
{
lean_object* v_a_2799_; uint8_t v___x_2800_; 
v_a_2799_ = lean_ctor_get(v___x_2798_, 0);
lean_inc(v_a_2799_);
lean_dec_ref(v___x_2798_);
v___x_2800_ = lean_unbox(v_a_2799_);
lean_dec(v_a_2799_);
if (v___x_2800_ == 0)
{
lean_object* v___x_2801_; lean_object* v___x_2802_; 
v___x_2801_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_2802_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_2801_, v___y_2757_);
if (lean_obj_tag(v___x_2802_) == 0)
{
lean_object* v_a_2803_; lean_object* v___x_2804_; 
v_a_2803_ = lean_ctor_get(v___x_2802_, 0);
lean_inc(v_a_2803_);
lean_dec_ref(v___x_2802_);
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v___x_2776_);
lean_inc(v_a_2803_);
v___x_2804_ = l_Lean_Meta_mkAuxDefinition(v_a_2803_, v_a_2772_, v___x_2776_, v___x_2750_, v_compile_2749_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2804_) == 0)
{
lean_object* v_a_2805_; lean_object* v___x_2806_; 
v_a_2805_ = lean_ctor_get(v___x_2804_, 0);
lean_inc(v_a_2805_);
lean_dec_ref(v___x_2804_);
v___x_2806_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v_a_2805_, v___y_2755_);
if (lean_obj_tag(v___x_2806_) == 0)
{
lean_object* v___x_2807_; 
lean_dec_ref(v___x_2806_);
lean_inc_ref(v___y_2756_);
v___x_2807_ = l_Lean_enableRealizationsForConst(v_a_2803_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2807_) == 0)
{
lean_dec_ref(v___x_2807_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2807_;
}
}
else
{
lean_dec(v_a_2803_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2806_;
}
}
else
{
lean_object* v_a_2808_; lean_object* v___x_2810_; uint8_t v_isShared_2811_; uint8_t v_isSharedCheck_2815_; 
lean_dec(v_a_2803_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2808_ = lean_ctor_get(v___x_2804_, 0);
v_isSharedCheck_2815_ = !lean_is_exclusive(v___x_2804_);
if (v_isSharedCheck_2815_ == 0)
{
v___x_2810_ = v___x_2804_;
v_isShared_2811_ = v_isSharedCheck_2815_;
goto v_resetjp_2809_;
}
else
{
lean_inc(v_a_2808_);
lean_dec(v___x_2804_);
v___x_2810_ = lean_box(0);
v_isShared_2811_ = v_isSharedCheck_2815_;
goto v_resetjp_2809_;
}
v_resetjp_2809_:
{
lean_object* v___x_2813_; 
if (v_isShared_2811_ == 0)
{
v___x_2813_ = v___x_2810_;
goto v_reusejp_2812_;
}
else
{
lean_object* v_reuseFailAlloc_2814_; 
v_reuseFailAlloc_2814_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2814_, 0, v_a_2808_);
v___x_2813_ = v_reuseFailAlloc_2814_;
goto v_reusejp_2812_;
}
v_reusejp_2812_:
{
return v___x_2813_;
}
}
}
}
else
{
lean_object* v_a_2816_; lean_object* v___x_2818_; uint8_t v_isShared_2819_; uint8_t v_isSharedCheck_2823_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2816_ = lean_ctor_get(v___x_2802_, 0);
v_isSharedCheck_2823_ = !lean_is_exclusive(v___x_2802_);
if (v_isSharedCheck_2823_ == 0)
{
v___x_2818_ = v___x_2802_;
v_isShared_2819_ = v_isSharedCheck_2823_;
goto v_resetjp_2817_;
}
else
{
lean_inc(v_a_2816_);
lean_dec(v___x_2802_);
v___x_2818_ = lean_box(0);
v_isShared_2819_ = v_isSharedCheck_2823_;
goto v_resetjp_2817_;
}
v_resetjp_2817_:
{
lean_object* v___x_2821_; 
if (v_isShared_2819_ == 0)
{
v___x_2821_ = v___x_2818_;
goto v_reusejp_2820_;
}
else
{
lean_object* v_reuseFailAlloc_2822_; 
v_reuseFailAlloc_2822_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2822_, 0, v_a_2816_);
v___x_2821_ = v_reuseFailAlloc_2822_;
goto v_reusejp_2820_;
}
v_reusejp_2820_:
{
return v___x_2821_;
}
}
}
}
else
{
lean_object* v___x_2824_; 
lean_dec(v_a_2772_);
lean_inc(v___x_2776_);
v___x_2824_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v___x_2776_, v___y_2755_);
if (lean_obj_tag(v___x_2824_) == 0)
{
lean_dec_ref(v___x_2824_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2824_;
}
}
}
else
{
lean_object* v_a_2825_; lean_object* v___x_2827_; uint8_t v_isShared_2828_; uint8_t v_isSharedCheck_2832_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2825_ = lean_ctor_get(v___x_2798_, 0);
v_isSharedCheck_2832_ = !lean_is_exclusive(v___x_2798_);
if (v_isSharedCheck_2832_ == 0)
{
v___x_2827_ = v___x_2798_;
v_isShared_2828_ = v_isSharedCheck_2832_;
goto v_resetjp_2826_;
}
else
{
lean_inc(v_a_2825_);
lean_dec(v___x_2798_);
v___x_2827_ = lean_box(0);
v_isShared_2828_ = v_isSharedCheck_2832_;
goto v_resetjp_2826_;
}
v_resetjp_2826_:
{
lean_object* v___x_2830_; 
if (v_isShared_2828_ == 0)
{
v___x_2830_ = v___x_2827_;
goto v_reusejp_2829_;
}
else
{
lean_object* v_reuseFailAlloc_2831_; 
v_reuseFailAlloc_2831_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2831_, 0, v_a_2825_);
v___x_2830_ = v_reuseFailAlloc_2831_;
goto v_reusejp_2829_;
}
v_reusejp_2829_:
{
return v___x_2830_;
}
}
}
}
else
{
lean_object* v_a_2833_; lean_object* v___x_2835_; uint8_t v_isShared_2836_; uint8_t v_isSharedCheck_2840_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2833_ = lean_ctor_get(v___x_2796_, 0);
v_isSharedCheck_2840_ = !lean_is_exclusive(v___x_2796_);
if (v_isSharedCheck_2840_ == 0)
{
v___x_2835_ = v___x_2796_;
v_isShared_2836_ = v_isSharedCheck_2840_;
goto v_resetjp_2834_;
}
else
{
lean_inc(v_a_2833_);
lean_dec(v___x_2796_);
v___x_2835_ = lean_box(0);
v_isShared_2836_ = v_isSharedCheck_2840_;
goto v_resetjp_2834_;
}
v_resetjp_2834_:
{
lean_object* v___x_2838_; 
if (v_isShared_2836_ == 0)
{
v___x_2838_ = v___x_2835_;
goto v_reusejp_2837_;
}
else
{
lean_object* v_reuseFailAlloc_2839_; 
v_reuseFailAlloc_2839_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2839_, 0, v_a_2833_);
v___x_2838_ = v_reuseFailAlloc_2839_;
goto v_reusejp_2837_;
}
v_reusejp_2837_:
{
return v___x_2838_;
}
}
}
}
}
else
{
goto v___jp_2780_;
}
}
else
{
lean_dec_ref(v_a_2779_);
goto v___jp_2780_;
}
v___jp_2780_:
{
lean_object* v___x_2781_; 
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v___x_2776_);
v___x_2781_ = l_Lean_Meta_normalizeInstance(v___x_2776_, v_a_2772_, v_compile_2749_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2781_) == 0)
{
lean_object* v_a_2782_; lean_object* v___x_2783_; 
v_a_2782_ = lean_ctor_get(v___x_2781_, 0);
lean_inc(v_a_2782_);
lean_dec_ref(v___x_2781_);
v___x_2783_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v_a_2782_, v___y_2755_);
if (lean_obj_tag(v___x_2783_) == 0)
{
lean_dec_ref(v___x_2783_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2783_;
}
}
else
{
lean_object* v_a_2784_; lean_object* v___x_2786_; uint8_t v_isShared_2787_; uint8_t v_isSharedCheck_2791_; 
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2784_ = lean_ctor_get(v___x_2781_, 0);
v_isSharedCheck_2791_ = !lean_is_exclusive(v___x_2781_);
if (v_isSharedCheck_2791_ == 0)
{
v___x_2786_ = v___x_2781_;
v_isShared_2787_ = v_isSharedCheck_2791_;
goto v_resetjp_2785_;
}
else
{
lean_inc(v_a_2784_);
lean_dec(v___x_2781_);
v___x_2786_ = lean_box(0);
v_isShared_2787_ = v_isSharedCheck_2791_;
goto v_resetjp_2785_;
}
v_resetjp_2785_:
{
lean_object* v___x_2789_; 
if (v_isShared_2787_ == 0)
{
v___x_2789_ = v___x_2786_;
goto v_reusejp_2788_;
}
else
{
lean_object* v_reuseFailAlloc_2790_; 
v_reuseFailAlloc_2790_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2790_, 0, v_a_2784_);
v___x_2789_ = v_reuseFailAlloc_2790_;
goto v_reusejp_2788_;
}
v_reusejp_2788_:
{
return v___x_2789_;
}
}
}
}
}
else
{
lean_object* v_a_2841_; lean_object* v___x_2843_; uint8_t v_isShared_2844_; uint8_t v_isSharedCheck_2848_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2841_ = lean_ctor_get(v___x_2778_, 0);
v_isSharedCheck_2848_ = !lean_is_exclusive(v___x_2778_);
if (v_isSharedCheck_2848_ == 0)
{
v___x_2843_ = v___x_2778_;
v_isShared_2844_ = v_isSharedCheck_2848_;
goto v_resetjp_2842_;
}
else
{
lean_inc(v_a_2841_);
lean_dec(v___x_2778_);
v___x_2843_ = lean_box(0);
v_isShared_2844_ = v_isSharedCheck_2848_;
goto v_resetjp_2842_;
}
v_resetjp_2842_:
{
lean_object* v___x_2846_; 
if (v_isShared_2844_ == 0)
{
v___x_2846_ = v___x_2843_;
goto v_reusejp_2845_;
}
else
{
lean_object* v_reuseFailAlloc_2847_; 
v_reuseFailAlloc_2847_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2847_, 0, v_a_2841_);
v___x_2846_ = v_reuseFailAlloc_2847_;
goto v_reusejp_2845_;
}
v_reusejp_2845_:
{
return v___x_2846_;
}
}
}
}
else
{
lean_object* v_options_2849_; lean_object* v___x_2850_; uint8_t v___x_2851_; 
v_options_2849_ = lean_ctor_get(v___y_2756_, 2);
v___x_2850_ = l_Lean_Meta_instance_normalForm_wrapFields_proofs;
v___x_2851_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2849_, v___x_2850_);
if (v___x_2851_ == 0)
{
lean_object* v___x_2852_; 
lean_dec(v_a_2772_);
lean_inc(v___x_2776_);
v___x_2852_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v___x_2776_, v___y_2755_);
if (lean_obj_tag(v___x_2852_) == 0)
{
lean_dec_ref(v___x_2852_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2852_;
}
}
else
{
lean_object* v___x_2853_; 
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v___x_2776_);
v___x_2853_ = lean_infer_type(v___x_2776_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2853_) == 0)
{
lean_object* v_a_2854_; lean_object* v___x_2855_; 
v_a_2854_ = lean_ctor_get(v___x_2853_, 0);
lean_inc(v_a_2854_);
lean_dec_ref(v___x_2853_);
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v_a_2772_);
v___x_2855_ = l_Lean_Meta_isExprDefEq(v_a_2772_, v_a_2854_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2855_) == 0)
{
lean_object* v_a_2856_; uint8_t v___x_2857_; 
v_a_2856_ = lean_ctor_get(v___x_2855_, 0);
lean_inc(v_a_2856_);
lean_dec_ref(v___x_2855_);
v___x_2857_ = lean_unbox(v_a_2856_);
lean_dec(v_a_2856_);
if (v___x_2857_ == 0)
{
lean_object* v___x_2858_; lean_object* v___x_2859_; 
v___x_2858_ = lean_box(0);
lean_inc(v___y_2757_);
lean_inc_ref(v___y_2756_);
lean_inc(v___y_2755_);
lean_inc_ref(v___y_2754_);
lean_inc(v___x_2776_);
v___x_2859_ = l_Lean_Meta_mkAuxTheorem(v_a_2772_, v___x_2776_, v___x_2751_, v___x_2858_, v___x_2751_, v___y_2754_, v___y_2755_, v___y_2756_, v___y_2757_);
if (lean_obj_tag(v___x_2859_) == 0)
{
lean_object* v_a_2860_; lean_object* v___x_2861_; 
v_a_2860_ = lean_ctor_get(v___x_2859_, 0);
lean_inc(v_a_2860_);
lean_dec_ref(v___x_2859_);
v___x_2861_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v_a_2860_, v___y_2755_);
if (lean_obj_tag(v___x_2861_) == 0)
{
lean_dec_ref(v___x_2861_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2861_;
}
}
else
{
lean_object* v_a_2862_; lean_object* v___x_2864_; uint8_t v_isShared_2865_; uint8_t v_isSharedCheck_2869_; 
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2862_ = lean_ctor_get(v___x_2859_, 0);
v_isSharedCheck_2869_ = !lean_is_exclusive(v___x_2859_);
if (v_isSharedCheck_2869_ == 0)
{
v___x_2864_ = v___x_2859_;
v_isShared_2865_ = v_isSharedCheck_2869_;
goto v_resetjp_2863_;
}
else
{
lean_inc(v_a_2862_);
lean_dec(v___x_2859_);
v___x_2864_ = lean_box(0);
v_isShared_2865_ = v_isSharedCheck_2869_;
goto v_resetjp_2863_;
}
v_resetjp_2863_:
{
lean_object* v___x_2867_; 
if (v_isShared_2865_ == 0)
{
v___x_2867_ = v___x_2864_;
goto v_reusejp_2866_;
}
else
{
lean_object* v_reuseFailAlloc_2868_; 
v_reuseFailAlloc_2868_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2868_, 0, v_a_2862_);
v___x_2867_ = v_reuseFailAlloc_2868_;
goto v_reusejp_2866_;
}
v_reusejp_2866_:
{
return v___x_2867_;
}
}
}
}
else
{
lean_object* v___x_2870_; 
lean_dec(v_a_2772_);
lean_inc(v___x_2776_);
v___x_2870_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v___x_2767_, v___x_2776_, v___y_2755_);
if (lean_obj_tag(v___x_2870_) == 0)
{
lean_dec_ref(v___x_2870_);
v_a_2760_ = v___x_2775_;
goto v___jp_2759_;
}
else
{
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
return v___x_2870_;
}
}
}
else
{
lean_object* v_a_2871_; lean_object* v___x_2873_; uint8_t v_isShared_2874_; uint8_t v_isSharedCheck_2878_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2871_ = lean_ctor_get(v___x_2855_, 0);
v_isSharedCheck_2878_ = !lean_is_exclusive(v___x_2855_);
if (v_isSharedCheck_2878_ == 0)
{
v___x_2873_ = v___x_2855_;
v_isShared_2874_ = v_isSharedCheck_2878_;
goto v_resetjp_2872_;
}
else
{
lean_inc(v_a_2871_);
lean_dec(v___x_2855_);
v___x_2873_ = lean_box(0);
v_isShared_2874_ = v_isSharedCheck_2878_;
goto v_resetjp_2872_;
}
v_resetjp_2872_:
{
lean_object* v___x_2876_; 
if (v_isShared_2874_ == 0)
{
v___x_2876_ = v___x_2873_;
goto v_reusejp_2875_;
}
else
{
lean_object* v_reuseFailAlloc_2877_; 
v_reuseFailAlloc_2877_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2877_, 0, v_a_2871_);
v___x_2876_ = v_reuseFailAlloc_2877_;
goto v_reusejp_2875_;
}
v_reusejp_2875_:
{
return v___x_2876_;
}
}
}
}
else
{
lean_object* v_a_2879_; lean_object* v___x_2881_; uint8_t v_isShared_2882_; uint8_t v_isSharedCheck_2886_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2879_ = lean_ctor_get(v___x_2853_, 0);
v_isSharedCheck_2886_ = !lean_is_exclusive(v___x_2853_);
if (v_isSharedCheck_2886_ == 0)
{
v___x_2881_ = v___x_2853_;
v_isShared_2882_ = v_isSharedCheck_2886_;
goto v_resetjp_2880_;
}
else
{
lean_inc(v_a_2879_);
lean_dec(v___x_2853_);
v___x_2881_ = lean_box(0);
v_isShared_2882_ = v_isSharedCheck_2886_;
goto v_resetjp_2880_;
}
v_resetjp_2880_:
{
lean_object* v___x_2884_; 
if (v_isShared_2882_ == 0)
{
v___x_2884_ = v___x_2881_;
goto v_reusejp_2883_;
}
else
{
lean_object* v_reuseFailAlloc_2885_; 
v_reuseFailAlloc_2885_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2885_, 0, v_a_2879_);
v___x_2884_ = v_reuseFailAlloc_2885_;
goto v_reusejp_2883_;
}
v_reusejp_2883_:
{
return v___x_2884_;
}
}
}
}
}
}
else
{
lean_object* v_a_2887_; lean_object* v___x_2889_; uint8_t v_isShared_2890_; uint8_t v_isSharedCheck_2894_; 
lean_dec(v_a_2772_);
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2887_ = lean_ctor_get(v___x_2773_, 0);
v_isSharedCheck_2894_ = !lean_is_exclusive(v___x_2773_);
if (v_isSharedCheck_2894_ == 0)
{
v___x_2889_ = v___x_2773_;
v_isShared_2890_ = v_isSharedCheck_2894_;
goto v_resetjp_2888_;
}
else
{
lean_inc(v_a_2887_);
lean_dec(v___x_2773_);
v___x_2889_ = lean_box(0);
v_isShared_2890_ = v_isSharedCheck_2894_;
goto v_resetjp_2888_;
}
v_resetjp_2888_:
{
lean_object* v___x_2892_; 
if (v_isShared_2890_ == 0)
{
v___x_2892_ = v___x_2889_;
goto v_reusejp_2891_;
}
else
{
lean_object* v_reuseFailAlloc_2893_; 
v_reuseFailAlloc_2893_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2893_, 0, v_a_2887_);
v___x_2892_ = v_reuseFailAlloc_2893_;
goto v_reusejp_2891_;
}
v_reusejp_2891_:
{
return v___x_2892_;
}
}
}
}
else
{
lean_object* v_a_2895_; lean_object* v___x_2897_; uint8_t v_isShared_2898_; uint8_t v_isSharedCheck_2902_; 
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2895_ = lean_ctor_get(v___x_2771_, 0);
v_isSharedCheck_2902_ = !lean_is_exclusive(v___x_2771_);
if (v_isSharedCheck_2902_ == 0)
{
v___x_2897_ = v___x_2771_;
v_isShared_2898_ = v_isSharedCheck_2902_;
goto v_resetjp_2896_;
}
else
{
lean_inc(v_a_2895_);
lean_dec(v___x_2771_);
v___x_2897_ = lean_box(0);
v_isShared_2898_ = v_isSharedCheck_2902_;
goto v_resetjp_2896_;
}
v_resetjp_2896_:
{
lean_object* v___x_2900_; 
if (v_isShared_2898_ == 0)
{
v___x_2900_ = v___x_2897_;
goto v_reusejp_2899_;
}
else
{
lean_object* v_reuseFailAlloc_2901_; 
v_reuseFailAlloc_2901_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2901_, 0, v_a_2895_);
v___x_2900_ = v_reuseFailAlloc_2901_;
goto v_reusejp_2899_;
}
v_reusejp_2899_:
{
return v___x_2900_;
}
}
}
}
else
{
lean_object* v_a_2903_; lean_object* v___x_2905_; uint8_t v_isShared_2906_; uint8_t v_isSharedCheck_2910_; 
lean_dec(v___x_2767_);
lean_dec(v___y_2757_);
lean_dec_ref(v___y_2756_);
lean_dec(v___y_2755_);
lean_dec_ref(v___y_2754_);
lean_dec(v_a_2752_);
v_a_2903_ = lean_ctor_get(v___x_2768_, 0);
v_isSharedCheck_2910_ = !lean_is_exclusive(v___x_2768_);
if (v_isSharedCheck_2910_ == 0)
{
v___x_2905_ = v___x_2768_;
v_isShared_2906_ = v_isSharedCheck_2910_;
goto v_resetjp_2904_;
}
else
{
lean_inc(v_a_2903_);
lean_dec(v___x_2768_);
v___x_2905_ = lean_box(0);
v_isShared_2906_ = v_isSharedCheck_2910_;
goto v_resetjp_2904_;
}
v_resetjp_2904_:
{
lean_object* v___x_2908_; 
if (v_isShared_2906_ == 0)
{
v___x_2908_ = v___x_2905_;
goto v_reusejp_2907_;
}
else
{
lean_object* v_reuseFailAlloc_2909_; 
v_reuseFailAlloc_2909_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2909_, 0, v_a_2903_);
v___x_2908_ = v_reuseFailAlloc_2909_;
goto v_reusejp_2907_;
}
v_reusejp_2907_:
{
return v___x_2908_;
}
}
}
}
v___jp_2759_:
{
lean_object* v___x_2761_; lean_object* v___x_2762_; 
v___x_2761_ = lean_unsigned_to_nat(1u);
v___x_2762_ = lean_nat_add(v_a_2752_, v___x_2761_);
lean_dec(v_a_2752_);
v_a_2752_ = v___x_2762_;
v_b_2753_ = v_a_2760_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15(lean_object* v_a_2911_, lean_object* v_expectedType_2912_, uint8_t v___x_2913_, uint8_t v_compile_2914_, uint8_t v___x_2915_, lean_object* v_x_2916_, lean_object* v_x_2917_, lean_object* v_x_2918_, lean_object* v___y_2919_, lean_object* v___y_2920_, lean_object* v___y_2921_, lean_object* v___y_2922_){
_start:
{
lean_object* v___y_2925_; lean_object* v___y_2926_; lean_object* v___y_2927_; lean_object* v___y_2928_; 
if (lean_obj_tag(v_x_2916_) == 5)
{
lean_object* v_fn_2977_; lean_object* v_arg_2978_; lean_object* v___x_2979_; lean_object* v___x_2980_; lean_object* v___x_2981_; 
v_fn_2977_ = lean_ctor_get(v_x_2916_, 0);
lean_inc_ref(v_fn_2977_);
v_arg_2978_ = lean_ctor_get(v_x_2916_, 1);
lean_inc_ref(v_arg_2978_);
lean_dec_ref(v_x_2916_);
v___x_2979_ = lean_array_set(v_x_2917_, v_x_2918_, v_arg_2978_);
v___x_2980_ = lean_unsigned_to_nat(1u);
v___x_2981_ = lean_nat_sub(v_x_2918_, v___x_2980_);
lean_dec(v_x_2918_);
v_x_2916_ = v_fn_2977_;
v_x_2917_ = v___x_2979_;
v_x_2918_ = v___x_2981_;
goto _start;
}
else
{
lean_object* v_cls_2983_; lean_object* v___y_2985_; lean_object* v___y_2986_; lean_object* v___y_2987_; lean_object* v___y_2988_; lean_object* v___x_3004_; 
lean_dec(v_x_2918_);
v_cls_2983_ = ((lean_object*)(l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn___closed__1_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_));
v___x_3004_ = l_Lean_Expr_constName_x3f(v_x_2916_);
if (lean_obj_tag(v___x_3004_) == 0)
{
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
v___y_2985_ = v___y_2919_;
v___y_2986_ = v___y_2920_;
v___y_2987_ = v___y_2921_;
v___y_2988_ = v___y_2922_;
goto v___jp_2984_;
}
else
{
lean_object* v_val_3005_; lean_object* v___x_3006_; 
v_val_3005_ = lean_ctor_get(v___x_3004_, 0);
lean_inc(v_val_3005_);
lean_dec_ref(v___x_3004_);
lean_inc_ref(v___y_2921_);
v___x_3006_ = l_Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5(v_val_3005_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
if (lean_obj_tag(v___x_3006_) == 0)
{
lean_object* v_a_3007_; 
v_a_3007_ = lean_ctor_get(v___x_3006_, 0);
lean_inc(v_a_3007_);
lean_dec_ref(v___x_3006_);
if (lean_obj_tag(v_a_3007_) == 6)
{
lean_object* v_val_3008_; lean_object* v___x_3009_; 
lean_dec_ref(v_a_2911_);
v_val_3008_ = lean_ctor_get(v_a_3007_, 0);
lean_inc_ref(v_val_3008_);
lean_dec_ref(v_a_3007_);
lean_inc(v___y_2922_);
lean_inc_ref(v___y_2921_);
lean_inc(v___y_2920_);
lean_inc_ref(v___y_2919_);
lean_inc_ref(v_x_2916_);
v___x_3009_ = lean_infer_type(v_x_2916_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
if (lean_obj_tag(v___x_3009_) == 0)
{
lean_object* v_a_3010_; uint8_t v___x_3011_; lean_object* v___x_3012_; 
v_a_3010_ = lean_ctor_get(v___x_3009_, 0);
lean_inc(v_a_3010_);
lean_dec_ref(v___x_3009_);
v___x_3011_ = 0;
lean_inc(v___y_2922_);
lean_inc_ref(v___y_2921_);
lean_inc(v___y_2920_);
lean_inc_ref(v___y_2919_);
v___x_3012_ = l_Lean_Meta_forallMetaTelescope(v_a_3010_, v___x_3011_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
if (lean_obj_tag(v___x_3012_) == 0)
{
lean_object* v_a_3013_; lean_object* v_snd_3014_; lean_object* v_fst_3015_; lean_object* v___x_3017_; uint8_t v_isShared_3018_; uint8_t v_isSharedCheck_3114_; 
v_a_3013_ = lean_ctor_get(v___x_3012_, 0);
lean_inc(v_a_3013_);
lean_dec_ref(v___x_3012_);
v_snd_3014_ = lean_ctor_get(v_a_3013_, 1);
v_fst_3015_ = lean_ctor_get(v_a_3013_, 0);
v_isSharedCheck_3114_ = !lean_is_exclusive(v_a_3013_);
if (v_isSharedCheck_3114_ == 0)
{
v___x_3017_ = v_a_3013_;
v_isShared_3018_ = v_isSharedCheck_3114_;
goto v_resetjp_3016_;
}
else
{
lean_inc(v_snd_3014_);
lean_inc(v_fst_3015_);
lean_dec(v_a_3013_);
v___x_3017_ = lean_box(0);
v_isShared_3018_ = v_isSharedCheck_3114_;
goto v_resetjp_3016_;
}
v_resetjp_3016_:
{
lean_object* v_snd_3019_; lean_object* v___x_3021_; uint8_t v_isShared_3022_; uint8_t v_isSharedCheck_3112_; 
v_snd_3019_ = lean_ctor_get(v_snd_3014_, 1);
v_isSharedCheck_3112_ = !lean_is_exclusive(v_snd_3014_);
if (v_isSharedCheck_3112_ == 0)
{
lean_object* v_unused_3113_; 
v_unused_3113_ = lean_ctor_get(v_snd_3014_, 0);
lean_dec(v_unused_3113_);
v___x_3021_ = v_snd_3014_;
v_isShared_3022_ = v_isSharedCheck_3112_;
goto v_resetjp_3020_;
}
else
{
lean_inc(v_snd_3019_);
lean_dec(v_snd_3014_);
v___x_3021_ = lean_box(0);
v_isShared_3022_ = v_isSharedCheck_3112_;
goto v_resetjp_3020_;
}
v_resetjp_3020_:
{
lean_object* v___x_3023_; lean_object* v___y_3025_; lean_object* v___y_3026_; lean_object* v___y_3027_; lean_object* v___y_3028_; lean_object* v___x_3060_; uint8_t v___x_3061_; 
v___x_3023_ = lean_array_get_size(v_x_2917_);
v___x_3060_ = lean_array_get_size(v_fst_3015_);
v___x_3061_ = lean_nat_dec_eq(v___x_3023_, v___x_3060_);
if (v___x_3061_ == 0)
{
lean_object* v___x_3062_; lean_object* v___x_3063_; lean_object* v___x_3065_; 
lean_dec(v_snd_3019_);
lean_dec(v_fst_3015_);
lean_dec_ref(v_val_3008_);
lean_dec_ref(v_expectedType_2912_);
v___x_3062_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__3);
v___x_3063_ = l_Lean_MessageData_ofExpr(v_x_2916_);
if (v_isShared_3022_ == 0)
{
lean_ctor_set_tag(v___x_3021_, 7);
lean_ctor_set(v___x_3021_, 1, v___x_3063_);
lean_ctor_set(v___x_3021_, 0, v___x_3062_);
v___x_3065_ = v___x_3021_;
goto v_reusejp_3064_;
}
else
{
lean_object* v_reuseFailAlloc_3076_; 
v_reuseFailAlloc_3076_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3076_, 0, v___x_3062_);
lean_ctor_set(v_reuseFailAlloc_3076_, 1, v___x_3063_);
v___x_3065_ = v_reuseFailAlloc_3076_;
goto v_reusejp_3064_;
}
v_reusejp_3064_:
{
lean_object* v___x_3066_; lean_object* v___x_3068_; 
v___x_3066_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__5);
if (v_isShared_3018_ == 0)
{
lean_ctor_set_tag(v___x_3017_, 7);
lean_ctor_set(v___x_3017_, 1, v___x_3066_);
lean_ctor_set(v___x_3017_, 0, v___x_3065_);
v___x_3068_ = v___x_3017_;
goto v_reusejp_3067_;
}
else
{
lean_object* v_reuseFailAlloc_3075_; 
v_reuseFailAlloc_3075_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3075_, 0, v___x_3065_);
lean_ctor_set(v_reuseFailAlloc_3075_, 1, v___x_3066_);
v___x_3068_ = v_reuseFailAlloc_3075_;
goto v_reusejp_3067_;
}
v_reusejp_3067_:
{
lean_object* v___x_3069_; lean_object* v___x_3070_; lean_object* v___x_3071_; lean_object* v___x_3072_; lean_object* v___x_3073_; lean_object* v___x_3074_; 
v___x_3069_ = lean_array_to_list(v_x_2917_);
v___x_3070_ = lean_box(0);
v___x_3071_ = l_List_mapTR_loop___at___00Lean_Meta_normalizeInstance_spec__11(v___x_3069_, v___x_3070_);
v___x_3072_ = l_Lean_MessageData_ofList(v___x_3071_);
v___x_3073_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_3073_, 0, v___x_3068_);
lean_ctor_set(v___x_3073_, 1, v___x_3072_);
v___x_3074_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_3073_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
return v___x_3074_;
}
}
}
else
{
lean_object* v___x_3077_; 
lean_inc(v___y_2922_);
lean_inc_ref(v___y_2921_);
lean_inc(v___y_2920_);
lean_inc_ref(v___y_2919_);
lean_inc_ref(v_expectedType_2912_);
v___x_3077_ = l_Lean_Meta_isExprDefEq(v_expectedType_2912_, v_snd_3019_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
if (lean_obj_tag(v___x_3077_) == 0)
{
lean_object* v_a_3078_; uint8_t v___x_3079_; 
v_a_3078_ = lean_ctor_get(v___x_3077_, 0);
lean_inc(v_a_3078_);
lean_dec_ref(v___x_3077_);
v___x_3079_ = lean_unbox(v_a_3078_);
lean_dec(v_a_3078_);
if (v___x_3079_ == 0)
{
lean_object* v_toConstantVal_3080_; lean_object* v_name_3081_; lean_object* v___x_3082_; lean_object* v___x_3083_; lean_object* v___x_3085_; 
lean_dec(v_fst_3015_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
v_toConstantVal_3080_ = lean_ctor_get(v_val_3008_, 0);
lean_inc_ref(v_toConstantVal_3080_);
lean_dec_ref(v_val_3008_);
v_name_3081_ = lean_ctor_get(v_toConstantVal_3080_, 0);
lean_inc(v_name_3081_);
lean_dec_ref(v_toConstantVal_3080_);
v___x_3082_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__7);
v___x_3083_ = l_Lean_MessageData_ofExpr(v_expectedType_2912_);
if (v_isShared_3022_ == 0)
{
lean_ctor_set_tag(v___x_3021_, 7);
lean_ctor_set(v___x_3021_, 1, v___x_3083_);
lean_ctor_set(v___x_3021_, 0, v___x_3082_);
v___x_3085_ = v___x_3021_;
goto v_reusejp_3084_;
}
else
{
lean_object* v_reuseFailAlloc_3103_; 
v_reuseFailAlloc_3103_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3103_, 0, v___x_3082_);
lean_ctor_set(v_reuseFailAlloc_3103_, 1, v___x_3083_);
v___x_3085_ = v_reuseFailAlloc_3103_;
goto v_reusejp_3084_;
}
v_reusejp_3084_:
{
lean_object* v___x_3086_; lean_object* v___x_3088_; 
v___x_3086_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__9);
if (v_isShared_3018_ == 0)
{
lean_ctor_set_tag(v___x_3017_, 7);
lean_ctor_set(v___x_3017_, 1, v___x_3086_);
lean_ctor_set(v___x_3017_, 0, v___x_3085_);
v___x_3088_ = v___x_3017_;
goto v_reusejp_3087_;
}
else
{
lean_object* v_reuseFailAlloc_3102_; 
v_reuseFailAlloc_3102_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v_reuseFailAlloc_3102_, 0, v___x_3085_);
lean_ctor_set(v_reuseFailAlloc_3102_, 1, v___x_3086_);
v___x_3088_ = v_reuseFailAlloc_3102_;
goto v_reusejp_3087_;
}
v_reusejp_3087_:
{
lean_object* v___x_3089_; lean_object* v___x_3090_; lean_object* v___x_3091_; lean_object* v___x_3092_; lean_object* v___x_3093_; lean_object* v_a_3094_; lean_object* v___x_3096_; uint8_t v_isShared_3097_; uint8_t v_isSharedCheck_3101_; 
v___x_3089_ = l_Lean_MessageData_ofConstName(v_name_3081_, v___x_2913_);
v___x_3090_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_3090_, 0, v___x_3088_);
lean_ctor_set(v___x_3090_, 1, v___x_3089_);
v___x_3091_ = lean_obj_once(&l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3, &l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3_once, _init_l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg___closed__3);
v___x_3092_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_3092_, 0, v___x_3090_);
lean_ctor_set(v___x_3092_, 1, v___x_3091_);
v___x_3093_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v___x_3092_, v___y_2919_, v___y_2920_, v___y_2921_, v___y_2922_);
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
v_a_3094_ = lean_ctor_get(v___x_3093_, 0);
v_isSharedCheck_3101_ = !lean_is_exclusive(v___x_3093_);
if (v_isSharedCheck_3101_ == 0)
{
v___x_3096_ = v___x_3093_;
v_isShared_3097_ = v_isSharedCheck_3101_;
goto v_resetjp_3095_;
}
else
{
lean_inc(v_a_3094_);
lean_dec(v___x_3093_);
v___x_3096_ = lean_box(0);
v_isShared_3097_ = v_isSharedCheck_3101_;
goto v_resetjp_3095_;
}
v_resetjp_3095_:
{
lean_object* v___x_3099_; 
if (v_isShared_3097_ == 0)
{
v___x_3099_ = v___x_3096_;
goto v_reusejp_3098_;
}
else
{
lean_object* v_reuseFailAlloc_3100_; 
v_reuseFailAlloc_3100_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3100_, 0, v_a_3094_);
v___x_3099_ = v_reuseFailAlloc_3100_;
goto v_reusejp_3098_;
}
v_reusejp_3098_:
{
return v___x_3099_;
}
}
}
}
}
else
{
lean_del_object(v___x_3021_);
lean_del_object(v___x_3017_);
lean_dec_ref(v_expectedType_2912_);
v___y_3025_ = v___y_2919_;
v___y_3026_ = v___y_2920_;
v___y_3027_ = v___y_2921_;
v___y_3028_ = v___y_2922_;
goto v___jp_3024_;
}
}
else
{
lean_object* v_a_3104_; lean_object* v___x_3106_; uint8_t v_isShared_3107_; uint8_t v_isSharedCheck_3111_; 
lean_del_object(v___x_3021_);
lean_del_object(v___x_3017_);
lean_dec(v_fst_3015_);
lean_dec_ref(v_val_3008_);
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
lean_dec_ref(v_expectedType_2912_);
v_a_3104_ = lean_ctor_get(v___x_3077_, 0);
v_isSharedCheck_3111_ = !lean_is_exclusive(v___x_3077_);
if (v_isSharedCheck_3111_ == 0)
{
v___x_3106_ = v___x_3077_;
v_isShared_3107_ = v_isSharedCheck_3111_;
goto v_resetjp_3105_;
}
else
{
lean_inc(v_a_3104_);
lean_dec(v___x_3077_);
v___x_3106_ = lean_box(0);
v_isShared_3107_ = v_isSharedCheck_3111_;
goto v_resetjp_3105_;
}
v_resetjp_3105_:
{
lean_object* v___x_3109_; 
if (v_isShared_3107_ == 0)
{
v___x_3109_ = v___x_3106_;
goto v_reusejp_3108_;
}
else
{
lean_object* v_reuseFailAlloc_3110_; 
v_reuseFailAlloc_3110_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3110_, 0, v_a_3104_);
v___x_3109_ = v_reuseFailAlloc_3110_;
goto v_reusejp_3108_;
}
v_reusejp_3108_:
{
return v___x_3109_;
}
}
}
}
v___jp_3024_:
{
lean_object* v_numParams_3029_; lean_object* v___x_3030_; lean_object* v___x_3031_; 
v_numParams_3029_ = lean_ctor_get(v_val_3008_, 3);
lean_inc(v_numParams_3029_);
lean_dec_ref(v_val_3008_);
v___x_3030_ = lean_box(0);
lean_inc(v___y_3028_);
lean_inc_ref(v___y_3027_);
lean_inc(v___y_3026_);
lean_inc_ref(v___y_3025_);
v___x_3031_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg(v___x_3023_, v_fst_3015_, v_x_2917_, v_compile_2914_, v___x_2913_, v___x_2915_, v_numParams_3029_, v___x_3030_, v___y_3025_, v___y_3026_, v___y_3027_, v___y_3028_);
lean_dec_ref(v_x_2917_);
if (lean_obj_tag(v___x_3031_) == 0)
{
size_t v_sz_3032_; size_t v___x_3033_; lean_object* v___x_3034_; 
lean_dec_ref(v___x_3031_);
v_sz_3032_ = lean_array_size(v_fst_3015_);
v___x_3033_ = ((size_t)0ULL);
v___x_3034_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Meta_normalizeInstance_spec__7(v_sz_3032_, v___x_3033_, v_fst_3015_, v___y_3025_, v___y_3026_, v___y_3027_, v___y_3028_);
lean_dec(v___y_3028_);
lean_dec_ref(v___y_3027_);
lean_dec(v___y_3026_);
lean_dec_ref(v___y_3025_);
if (lean_obj_tag(v___x_3034_) == 0)
{
lean_object* v_a_3035_; lean_object* v___x_3037_; uint8_t v_isShared_3038_; uint8_t v_isSharedCheck_3043_; 
v_a_3035_ = lean_ctor_get(v___x_3034_, 0);
v_isSharedCheck_3043_ = !lean_is_exclusive(v___x_3034_);
if (v_isSharedCheck_3043_ == 0)
{
v___x_3037_ = v___x_3034_;
v_isShared_3038_ = v_isSharedCheck_3043_;
goto v_resetjp_3036_;
}
else
{
lean_inc(v_a_3035_);
lean_dec(v___x_3034_);
v___x_3037_ = lean_box(0);
v_isShared_3038_ = v_isSharedCheck_3043_;
goto v_resetjp_3036_;
}
v_resetjp_3036_:
{
lean_object* v___x_3039_; lean_object* v___x_3041_; 
v___x_3039_ = l_Lean_mkAppN(v_x_2916_, v_a_3035_);
lean_dec(v_a_3035_);
if (v_isShared_3038_ == 0)
{
lean_ctor_set(v___x_3037_, 0, v___x_3039_);
v___x_3041_ = v___x_3037_;
goto v_reusejp_3040_;
}
else
{
lean_object* v_reuseFailAlloc_3042_; 
v_reuseFailAlloc_3042_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3042_, 0, v___x_3039_);
v___x_3041_ = v_reuseFailAlloc_3042_;
goto v_reusejp_3040_;
}
v_reusejp_3040_:
{
return v___x_3041_;
}
}
}
else
{
lean_object* v_a_3044_; lean_object* v___x_3046_; uint8_t v_isShared_3047_; uint8_t v_isSharedCheck_3051_; 
lean_dec_ref(v_x_2916_);
v_a_3044_ = lean_ctor_get(v___x_3034_, 0);
v_isSharedCheck_3051_ = !lean_is_exclusive(v___x_3034_);
if (v_isSharedCheck_3051_ == 0)
{
v___x_3046_ = v___x_3034_;
v_isShared_3047_ = v_isSharedCheck_3051_;
goto v_resetjp_3045_;
}
else
{
lean_inc(v_a_3044_);
lean_dec(v___x_3034_);
v___x_3046_ = lean_box(0);
v_isShared_3047_ = v_isSharedCheck_3051_;
goto v_resetjp_3045_;
}
v_resetjp_3045_:
{
lean_object* v___x_3049_; 
if (v_isShared_3047_ == 0)
{
v___x_3049_ = v___x_3046_;
goto v_reusejp_3048_;
}
else
{
lean_object* v_reuseFailAlloc_3050_; 
v_reuseFailAlloc_3050_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3050_, 0, v_a_3044_);
v___x_3049_ = v_reuseFailAlloc_3050_;
goto v_reusejp_3048_;
}
v_reusejp_3048_:
{
return v___x_3049_;
}
}
}
}
else
{
lean_object* v_a_3052_; lean_object* v___x_3054_; uint8_t v_isShared_3055_; uint8_t v_isSharedCheck_3059_; 
lean_dec(v___y_3028_);
lean_dec_ref(v___y_3027_);
lean_dec(v___y_3026_);
lean_dec_ref(v___y_3025_);
lean_dec(v_fst_3015_);
lean_dec_ref(v_x_2916_);
v_a_3052_ = lean_ctor_get(v___x_3031_, 0);
v_isSharedCheck_3059_ = !lean_is_exclusive(v___x_3031_);
if (v_isSharedCheck_3059_ == 0)
{
v___x_3054_ = v___x_3031_;
v_isShared_3055_ = v_isSharedCheck_3059_;
goto v_resetjp_3053_;
}
else
{
lean_inc(v_a_3052_);
lean_dec(v___x_3031_);
v___x_3054_ = lean_box(0);
v_isShared_3055_ = v_isSharedCheck_3059_;
goto v_resetjp_3053_;
}
v_resetjp_3053_:
{
lean_object* v___x_3057_; 
if (v_isShared_3055_ == 0)
{
v___x_3057_ = v___x_3054_;
goto v_reusejp_3056_;
}
else
{
lean_object* v_reuseFailAlloc_3058_; 
v_reuseFailAlloc_3058_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3058_, 0, v_a_3052_);
v___x_3057_ = v_reuseFailAlloc_3058_;
goto v_reusejp_3056_;
}
v_reusejp_3056_:
{
return v___x_3057_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_3115_; lean_object* v___x_3117_; uint8_t v_isShared_3118_; uint8_t v_isSharedCheck_3122_; 
lean_dec_ref(v_val_3008_);
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
lean_dec_ref(v_expectedType_2912_);
v_a_3115_ = lean_ctor_get(v___x_3012_, 0);
v_isSharedCheck_3122_ = !lean_is_exclusive(v___x_3012_);
if (v_isSharedCheck_3122_ == 0)
{
v___x_3117_ = v___x_3012_;
v_isShared_3118_ = v_isSharedCheck_3122_;
goto v_resetjp_3116_;
}
else
{
lean_inc(v_a_3115_);
lean_dec(v___x_3012_);
v___x_3117_ = lean_box(0);
v_isShared_3118_ = v_isSharedCheck_3122_;
goto v_resetjp_3116_;
}
v_resetjp_3116_:
{
lean_object* v___x_3120_; 
if (v_isShared_3118_ == 0)
{
v___x_3120_ = v___x_3117_;
goto v_reusejp_3119_;
}
else
{
lean_object* v_reuseFailAlloc_3121_; 
v_reuseFailAlloc_3121_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3121_, 0, v_a_3115_);
v___x_3120_ = v_reuseFailAlloc_3121_;
goto v_reusejp_3119_;
}
v_reusejp_3119_:
{
return v___x_3120_;
}
}
}
}
else
{
lean_dec_ref(v_val_3008_);
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
lean_dec_ref(v_expectedType_2912_);
return v___x_3009_;
}
}
else
{
lean_dec(v_a_3007_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
v___y_2985_ = v___y_2919_;
v___y_2986_ = v___y_2920_;
v___y_2987_ = v___y_2921_;
v___y_2988_ = v___y_2922_;
goto v___jp_2984_;
}
}
else
{
lean_object* v_a_3123_; lean_object* v___x_3125_; uint8_t v_isShared_3126_; uint8_t v_isSharedCheck_3130_; 
lean_dec(v___y_2922_);
lean_dec_ref(v___y_2921_);
lean_dec(v___y_2920_);
lean_dec_ref(v___y_2919_);
lean_dec_ref(v_x_2917_);
lean_dec_ref(v_x_2916_);
lean_dec_ref(v_expectedType_2912_);
lean_dec_ref(v_a_2911_);
v_a_3123_ = lean_ctor_get(v___x_3006_, 0);
v_isSharedCheck_3130_ = !lean_is_exclusive(v___x_3006_);
if (v_isSharedCheck_3130_ == 0)
{
v___x_3125_ = v___x_3006_;
v_isShared_3126_ = v_isSharedCheck_3130_;
goto v_resetjp_3124_;
}
else
{
lean_inc(v_a_3123_);
lean_dec(v___x_3006_);
v___x_3125_ = lean_box(0);
v_isShared_3126_ = v_isSharedCheck_3130_;
goto v_resetjp_3124_;
}
v_resetjp_3124_:
{
lean_object* v___x_3128_; 
if (v_isShared_3126_ == 0)
{
v___x_3128_ = v___x_3125_;
goto v_reusejp_3127_;
}
else
{
lean_object* v_reuseFailAlloc_3129_; 
v_reuseFailAlloc_3129_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3129_, 0, v_a_3123_);
v___x_3128_ = v_reuseFailAlloc_3129_;
goto v_reusejp_3127_;
}
v_reusejp_3127_:
{
return v___x_3128_;
}
}
}
}
v___jp_2984_:
{
lean_object* v___x_2989_; lean_object* v_a_2990_; uint8_t v___x_2991_; 
v___x_2989_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_2983_, v___y_2987_);
v_a_2990_ = lean_ctor_get(v___x_2989_, 0);
lean_inc(v_a_2990_);
lean_dec_ref(v___x_2989_);
v___x_2991_ = lean_unbox(v_a_2990_);
lean_dec(v_a_2990_);
if (v___x_2991_ == 0)
{
v___y_2925_ = v___y_2985_;
v___y_2926_ = v___y_2986_;
v___y_2927_ = v___y_2987_;
v___y_2928_ = v___y_2988_;
goto v___jp_2924_;
}
else
{
lean_object* v___x_2992_; lean_object* v___x_2993_; lean_object* v___x_2994_; lean_object* v___x_2995_; 
v___x_2992_ = lean_obj_once(&l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1, &l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1_once, _init_l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___closed__1);
lean_inc_ref(v_a_2911_);
v___x_2993_ = l_Lean_MessageData_ofExpr(v_a_2911_);
v___x_2994_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_2994_, 0, v___x_2992_);
lean_ctor_set(v___x_2994_, 1, v___x_2993_);
v___x_2995_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_2983_, v___x_2994_, v___y_2985_, v___y_2986_, v___y_2987_, v___y_2988_);
if (lean_obj_tag(v___x_2995_) == 0)
{
lean_dec_ref(v___x_2995_);
v___y_2925_ = v___y_2985_;
v___y_2926_ = v___y_2986_;
v___y_2927_ = v___y_2987_;
v___y_2928_ = v___y_2988_;
goto v___jp_2924_;
}
else
{
lean_object* v_a_2996_; lean_object* v___x_2998_; uint8_t v_isShared_2999_; uint8_t v_isSharedCheck_3003_; 
lean_dec(v___y_2988_);
lean_dec_ref(v___y_2987_);
lean_dec(v___y_2986_);
lean_dec_ref(v___y_2985_);
lean_dec_ref(v_expectedType_2912_);
lean_dec_ref(v_a_2911_);
v_a_2996_ = lean_ctor_get(v___x_2995_, 0);
v_isSharedCheck_3003_ = !lean_is_exclusive(v___x_2995_);
if (v_isSharedCheck_3003_ == 0)
{
v___x_2998_ = v___x_2995_;
v_isShared_2999_ = v_isSharedCheck_3003_;
goto v_resetjp_2997_;
}
else
{
lean_inc(v_a_2996_);
lean_dec(v___x_2995_);
v___x_2998_ = lean_box(0);
v_isShared_2999_ = v_isSharedCheck_3003_;
goto v_resetjp_2997_;
}
v_resetjp_2997_:
{
lean_object* v___x_3001_; 
if (v_isShared_2999_ == 0)
{
v___x_3001_ = v___x_2998_;
goto v_reusejp_3000_;
}
else
{
lean_object* v_reuseFailAlloc_3002_; 
v_reuseFailAlloc_3002_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3002_, 0, v_a_2996_);
v___x_3001_ = v_reuseFailAlloc_3002_;
goto v_reusejp_3000_;
}
v_reusejp_3000_:
{
return v___x_3001_;
}
}
}
}
}
}
v___jp_2924_:
{
lean_object* v_options_2929_; lean_object* v___x_2930_; uint8_t v___x_2931_; 
v_options_2929_ = lean_ctor_get(v___y_2927_, 2);
v___x_2930_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_2931_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_2929_, v___x_2930_);
if (v___x_2931_ == 0)
{
lean_object* v___x_2932_; 
lean_dec(v___y_2928_);
lean_dec_ref(v___y_2927_);
lean_dec(v___y_2926_);
lean_dec_ref(v___y_2925_);
lean_dec_ref(v_expectedType_2912_);
v___x_2932_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2932_, 0, v_a_2911_);
return v___x_2932_;
}
else
{
lean_object* v___x_2933_; 
lean_inc(v___y_2928_);
lean_inc_ref(v___y_2927_);
lean_inc(v___y_2926_);
lean_inc_ref(v___y_2925_);
lean_inc_ref(v_a_2911_);
v___x_2933_ = lean_infer_type(v_a_2911_, v___y_2925_, v___y_2926_, v___y_2927_, v___y_2928_);
if (lean_obj_tag(v___x_2933_) == 0)
{
lean_object* v_a_2934_; lean_object* v___x_2935_; 
v_a_2934_ = lean_ctor_get(v___x_2933_, 0);
lean_inc(v_a_2934_);
lean_dec_ref(v___x_2933_);
lean_inc(v___y_2928_);
lean_inc_ref(v___y_2927_);
lean_inc(v___y_2926_);
lean_inc_ref(v___y_2925_);
lean_inc_ref(v_expectedType_2912_);
v___x_2935_ = l_Lean_Meta_isExprDefEq(v_expectedType_2912_, v_a_2934_, v___y_2925_, v___y_2926_, v___y_2927_, v___y_2928_);
if (lean_obj_tag(v___x_2935_) == 0)
{
lean_object* v_a_2936_; lean_object* v___x_2938_; uint8_t v_isShared_2939_; uint8_t v_isSharedCheck_2968_; 
v_a_2936_ = lean_ctor_get(v___x_2935_, 0);
v_isSharedCheck_2968_ = !lean_is_exclusive(v___x_2935_);
if (v_isSharedCheck_2968_ == 0)
{
v___x_2938_ = v___x_2935_;
v_isShared_2939_ = v_isSharedCheck_2968_;
goto v_resetjp_2937_;
}
else
{
lean_inc(v_a_2936_);
lean_dec(v___x_2935_);
v___x_2938_ = lean_box(0);
v_isShared_2939_ = v_isSharedCheck_2968_;
goto v_resetjp_2937_;
}
v_resetjp_2937_:
{
uint8_t v___x_2940_; 
v___x_2940_ = lean_unbox(v_a_2936_);
lean_dec(v_a_2936_);
if (v___x_2940_ == 0)
{
lean_object* v___x_2941_; lean_object* v___x_2942_; lean_object* v_a_2943_; lean_object* v___x_2944_; 
lean_del_object(v___x_2938_);
v___x_2941_ = ((lean_object*)(l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___closed__1));
v___x_2942_ = l_Lean_mkAuxDeclName___at___00Lean_Meta_normalizeInstance_spec__1___redArg(v___x_2941_, v___y_2928_);
v_a_2943_ = lean_ctor_get(v___x_2942_, 0);
lean_inc(v_a_2943_);
lean_dec_ref(v___x_2942_);
lean_inc(v___y_2928_);
lean_inc_ref(v___y_2927_);
lean_inc(v___y_2926_);
lean_inc(v_a_2943_);
v___x_2944_ = l_Lean_Meta_mkAuxDefinition(v_a_2943_, v_expectedType_2912_, v_a_2911_, v___x_2913_, v_compile_2914_, v___y_2925_, v___y_2926_, v___y_2927_, v___y_2928_);
if (lean_obj_tag(v___x_2944_) == 0)
{
lean_object* v_a_2945_; uint8_t v___x_2946_; lean_object* v___x_2947_; lean_object* v___x_2948_; 
v_a_2945_ = lean_ctor_get(v___x_2944_, 0);
lean_inc(v_a_2945_);
lean_dec_ref(v___x_2944_);
v___x_2946_ = 3;
lean_inc(v_a_2943_);
v___x_2947_ = l_Lean_setReducibilityStatus___at___00Lean_Meta_normalizeInstance_spec__2___redArg(v_a_2943_, v___x_2946_, v___y_2926_, v___y_2928_);
lean_dec(v___y_2926_);
lean_dec_ref(v___x_2947_);
v___x_2948_ = l_Lean_enableRealizationsForConst(v_a_2943_, v___y_2927_, v___y_2928_);
lean_dec(v___y_2928_);
if (lean_obj_tag(v___x_2948_) == 0)
{
lean_object* v___x_2950_; uint8_t v_isShared_2951_; uint8_t v_isSharedCheck_2955_; 
v_isSharedCheck_2955_ = !lean_is_exclusive(v___x_2948_);
if (v_isSharedCheck_2955_ == 0)
{
lean_object* v_unused_2956_; 
v_unused_2956_ = lean_ctor_get(v___x_2948_, 0);
lean_dec(v_unused_2956_);
v___x_2950_ = v___x_2948_;
v_isShared_2951_ = v_isSharedCheck_2955_;
goto v_resetjp_2949_;
}
else
{
lean_dec(v___x_2948_);
v___x_2950_ = lean_box(0);
v_isShared_2951_ = v_isSharedCheck_2955_;
goto v_resetjp_2949_;
}
v_resetjp_2949_:
{
lean_object* v___x_2953_; 
if (v_isShared_2951_ == 0)
{
lean_ctor_set(v___x_2950_, 0, v_a_2945_);
v___x_2953_ = v___x_2950_;
goto v_reusejp_2952_;
}
else
{
lean_object* v_reuseFailAlloc_2954_; 
v_reuseFailAlloc_2954_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2954_, 0, v_a_2945_);
v___x_2953_ = v_reuseFailAlloc_2954_;
goto v_reusejp_2952_;
}
v_reusejp_2952_:
{
return v___x_2953_;
}
}
}
else
{
lean_object* v_a_2957_; lean_object* v___x_2959_; uint8_t v_isShared_2960_; uint8_t v_isSharedCheck_2964_; 
lean_dec(v_a_2945_);
v_a_2957_ = lean_ctor_get(v___x_2948_, 0);
v_isSharedCheck_2964_ = !lean_is_exclusive(v___x_2948_);
if (v_isSharedCheck_2964_ == 0)
{
v___x_2959_ = v___x_2948_;
v_isShared_2960_ = v_isSharedCheck_2964_;
goto v_resetjp_2958_;
}
else
{
lean_inc(v_a_2957_);
lean_dec(v___x_2948_);
v___x_2959_ = lean_box(0);
v_isShared_2960_ = v_isSharedCheck_2964_;
goto v_resetjp_2958_;
}
v_resetjp_2958_:
{
lean_object* v___x_2962_; 
if (v_isShared_2960_ == 0)
{
v___x_2962_ = v___x_2959_;
goto v_reusejp_2961_;
}
else
{
lean_object* v_reuseFailAlloc_2963_; 
v_reuseFailAlloc_2963_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2963_, 0, v_a_2957_);
v___x_2962_ = v_reuseFailAlloc_2963_;
goto v_reusejp_2961_;
}
v_reusejp_2961_:
{
return v___x_2962_;
}
}
}
}
else
{
lean_dec(v_a_2943_);
lean_dec(v___y_2928_);
lean_dec_ref(v___y_2927_);
lean_dec(v___y_2926_);
return v___x_2944_;
}
}
else
{
lean_object* v___x_2966_; 
lean_dec(v___y_2928_);
lean_dec_ref(v___y_2927_);
lean_dec(v___y_2926_);
lean_dec_ref(v___y_2925_);
lean_dec_ref(v_expectedType_2912_);
if (v_isShared_2939_ == 0)
{
lean_ctor_set(v___x_2938_, 0, v_a_2911_);
v___x_2966_ = v___x_2938_;
goto v_reusejp_2965_;
}
else
{
lean_object* v_reuseFailAlloc_2967_; 
v_reuseFailAlloc_2967_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2967_, 0, v_a_2911_);
v___x_2966_ = v_reuseFailAlloc_2967_;
goto v_reusejp_2965_;
}
v_reusejp_2965_:
{
return v___x_2966_;
}
}
}
}
else
{
lean_object* v_a_2969_; lean_object* v___x_2971_; uint8_t v_isShared_2972_; uint8_t v_isSharedCheck_2976_; 
lean_dec(v___y_2928_);
lean_dec_ref(v___y_2927_);
lean_dec(v___y_2926_);
lean_dec_ref(v___y_2925_);
lean_dec_ref(v_expectedType_2912_);
lean_dec_ref(v_a_2911_);
v_a_2969_ = lean_ctor_get(v___x_2935_, 0);
v_isSharedCheck_2976_ = !lean_is_exclusive(v___x_2935_);
if (v_isSharedCheck_2976_ == 0)
{
v___x_2971_ = v___x_2935_;
v_isShared_2972_ = v_isSharedCheck_2976_;
goto v_resetjp_2970_;
}
else
{
lean_inc(v_a_2969_);
lean_dec(v___x_2935_);
v___x_2971_ = lean_box(0);
v_isShared_2972_ = v_isSharedCheck_2976_;
goto v_resetjp_2970_;
}
v_resetjp_2970_:
{
lean_object* v___x_2974_; 
if (v_isShared_2972_ == 0)
{
v___x_2974_ = v___x_2971_;
goto v_reusejp_2973_;
}
else
{
lean_object* v_reuseFailAlloc_2975_; 
v_reuseFailAlloc_2975_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2975_, 0, v_a_2969_);
v___x_2974_ = v_reuseFailAlloc_2975_;
goto v_reusejp_2973_;
}
v_reusejp_2973_:
{
return v___x_2974_;
}
}
}
}
else
{
lean_dec(v___y_2928_);
lean_dec_ref(v___y_2927_);
lean_dec(v___y_2926_);
lean_dec_ref(v___y_2925_);
lean_dec_ref(v_expectedType_2912_);
lean_dec_ref(v_a_2911_);
return v___x_2933_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__1(lean_object* v_inst_3131_, lean_object* v_expectedType_3132_, uint8_t v___x_3133_, uint8_t v_compile_3134_, uint8_t v_hasTrace_3135_, lean_object* v_cls_3136_, lean_object* v_____r_3137_, lean_object* v___y_3138_, lean_object* v___y_3139_, lean_object* v___y_3140_, lean_object* v___y_3141_){
_start:
{
lean_object* v___x_3143_; 
lean_inc(v___y_3141_);
lean_inc_ref(v___y_3140_);
lean_inc(v___y_3139_);
lean_inc_ref(v___y_3138_);
lean_inc_ref(v_inst_3131_);
v___x_3143_ = lean_infer_type(v_inst_3131_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
if (lean_obj_tag(v___x_3143_) == 0)
{
lean_object* v_a_3144_; lean_object* v___x_3145_; 
v_a_3144_ = lean_ctor_get(v___x_3143_, 0);
lean_inc(v_a_3144_);
lean_dec_ref(v___x_3143_);
lean_inc(v___y_3141_);
lean_inc_ref(v___y_3140_);
lean_inc(v___y_3139_);
lean_inc_ref(v___y_3138_);
lean_inc_ref(v_expectedType_3132_);
v___x_3145_ = l_Lean_Meta_isExprDefEq(v_a_3144_, v_expectedType_3132_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
if (lean_obj_tag(v___x_3145_) == 0)
{
lean_object* v_a_3146_; uint8_t v___x_3147_; 
v_a_3146_ = lean_ctor_get(v___x_3145_, 0);
lean_inc(v_a_3146_);
lean_dec_ref(v___x_3145_);
v___x_3147_ = lean_unbox(v_a_3146_);
lean_dec(v_a_3146_);
if (v___x_3147_ == 0)
{
lean_object* v___x_3148_; 
lean_dec(v_cls_3136_);
lean_inc(v___y_3141_);
lean_inc_ref(v___y_3140_);
lean_inc(v___y_3139_);
lean_inc_ref(v___y_3138_);
lean_inc_ref(v_expectedType_3132_);
v___x_3148_ = l_Lean_Meta_isProp(v_expectedType_3132_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
if (lean_obj_tag(v___x_3148_) == 0)
{
lean_object* v_a_3149_; lean_object* v___x_3151_; uint8_t v_isShared_3152_; uint8_t v_isSharedCheck_3170_; 
v_a_3149_ = lean_ctor_get(v___x_3148_, 0);
v_isSharedCheck_3170_ = !lean_is_exclusive(v___x_3148_);
if (v_isSharedCheck_3170_ == 0)
{
v___x_3151_ = v___x_3148_;
v_isShared_3152_ = v_isSharedCheck_3170_;
goto v_resetjp_3150_;
}
else
{
lean_inc(v_a_3149_);
lean_dec(v___x_3148_);
v___x_3151_ = lean_box(0);
v_isShared_3152_ = v_isSharedCheck_3170_;
goto v_resetjp_3150_;
}
v_resetjp_3150_:
{
uint8_t v___x_3153_; 
v___x_3153_ = lean_unbox(v_a_3149_);
lean_dec(v_a_3149_);
if (v___x_3153_ == 0)
{
lean_object* v___x_3154_; 
lean_del_object(v___x_3151_);
lean_inc(v___y_3141_);
lean_inc_ref(v___y_3140_);
lean_inc(v___y_3139_);
lean_inc_ref(v___y_3138_);
v___x_3154_ = lean_whnf(v_inst_3131_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
if (lean_obj_tag(v___x_3154_) == 0)
{
lean_object* v_a_3155_; lean_object* v_dummy_3156_; lean_object* v_nargs_3157_; lean_object* v___x_3158_; lean_object* v___x_3159_; lean_object* v___x_3160_; lean_object* v___x_3161_; 
v_a_3155_ = lean_ctor_get(v___x_3154_, 0);
lean_inc(v_a_3155_);
lean_dec_ref(v___x_3154_);
v_dummy_3156_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__0, &l_Lean_Meta_normalizeInstance___lam__1___closed__0_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__0);
v_nargs_3157_ = l_Lean_Expr_getAppNumArgs(v_a_3155_);
lean_inc(v_nargs_3157_);
v___x_3158_ = lean_mk_array(v_nargs_3157_, v_dummy_3156_);
v___x_3159_ = lean_unsigned_to_nat(1u);
v___x_3160_ = lean_nat_sub(v_nargs_3157_, v___x_3159_);
lean_dec(v_nargs_3157_);
lean_inc(v_a_3155_);
v___x_3161_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15(v_a_3155_, v_expectedType_3132_, v___x_3133_, v_compile_3134_, v_hasTrace_3135_, v_a_3155_, v___x_3158_, v___x_3160_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
return v___x_3161_;
}
else
{
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec_ref(v_expectedType_3132_);
return v___x_3154_;
}
}
else
{
lean_object* v_options_3162_; lean_object* v___x_3163_; uint8_t v___x_3164_; 
v_options_3162_ = lean_ctor_get(v___y_3140_, 2);
v___x_3163_ = l_Lean_Meta_instance_normalForm_wrapInstances;
v___x_3164_ = l_Lean_Option_get___at___00Lean_Meta_normalizeInstance_spec__0(v_options_3162_, v___x_3163_);
if (v___x_3164_ == 0)
{
lean_object* v___x_3166_; 
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec_ref(v_expectedType_3132_);
if (v_isShared_3152_ == 0)
{
lean_ctor_set(v___x_3151_, 0, v_inst_3131_);
v___x_3166_ = v___x_3151_;
goto v_reusejp_3165_;
}
else
{
lean_object* v_reuseFailAlloc_3167_; 
v_reuseFailAlloc_3167_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3167_, 0, v_inst_3131_);
v___x_3166_ = v_reuseFailAlloc_3167_;
goto v_reusejp_3165_;
}
v_reusejp_3165_:
{
return v___x_3166_;
}
}
else
{
lean_object* v___x_3168_; lean_object* v___x_3169_; 
lean_del_object(v___x_3151_);
v___x_3168_ = lean_box(0);
v___x_3169_ = l_Lean_Meta_mkAuxTheorem(v_expectedType_3132_, v_inst_3131_, v_hasTrace_3135_, v___x_3168_, v_hasTrace_3135_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
return v___x_3169_;
}
}
}
}
else
{
lean_object* v_a_3171_; lean_object* v___x_3173_; uint8_t v_isShared_3174_; uint8_t v_isSharedCheck_3178_; 
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec_ref(v_expectedType_3132_);
lean_dec_ref(v_inst_3131_);
v_a_3171_ = lean_ctor_get(v___x_3148_, 0);
v_isSharedCheck_3178_ = !lean_is_exclusive(v___x_3148_);
if (v_isSharedCheck_3178_ == 0)
{
v___x_3173_ = v___x_3148_;
v_isShared_3174_ = v_isSharedCheck_3178_;
goto v_resetjp_3172_;
}
else
{
lean_inc(v_a_3171_);
lean_dec(v___x_3148_);
v___x_3173_ = lean_box(0);
v_isShared_3174_ = v_isSharedCheck_3178_;
goto v_resetjp_3172_;
}
v_resetjp_3172_:
{
lean_object* v___x_3176_; 
if (v_isShared_3174_ == 0)
{
v___x_3176_ = v___x_3173_;
goto v_reusejp_3175_;
}
else
{
lean_object* v_reuseFailAlloc_3177_; 
v_reuseFailAlloc_3177_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3177_, 0, v_a_3171_);
v___x_3176_ = v_reuseFailAlloc_3177_;
goto v_reusejp_3175_;
}
v_reusejp_3175_:
{
return v___x_3176_;
}
}
}
}
else
{
lean_object* v___x_3179_; 
lean_dec_ref(v_expectedType_3132_);
lean_inc(v_cls_3136_);
v___x_3179_ = l_Lean_isTracingEnabledFor___at___00Lean_Meta_normalizeInstance_spec__3___redArg(v_cls_3136_, v___y_3140_);
if (lean_obj_tag(v___x_3179_) == 0)
{
lean_object* v_a_3180_; lean_object* v___x_3182_; uint8_t v_isShared_3183_; uint8_t v_isSharedCheck_3208_; 
v_a_3180_ = lean_ctor_get(v___x_3179_, 0);
v_isSharedCheck_3208_ = !lean_is_exclusive(v___x_3179_);
if (v_isSharedCheck_3208_ == 0)
{
v___x_3182_ = v___x_3179_;
v_isShared_3183_ = v_isSharedCheck_3208_;
goto v_resetjp_3181_;
}
else
{
lean_inc(v_a_3180_);
lean_dec(v___x_3179_);
v___x_3182_ = lean_box(0);
v_isShared_3183_ = v_isSharedCheck_3208_;
goto v_resetjp_3181_;
}
v_resetjp_3181_:
{
uint8_t v___x_3184_; 
v___x_3184_ = lean_unbox(v_a_3180_);
lean_dec(v_a_3180_);
if (v___x_3184_ == 0)
{
lean_object* v___x_3186_; 
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec(v_cls_3136_);
if (v_isShared_3183_ == 0)
{
lean_ctor_set(v___x_3182_, 0, v_inst_3131_);
v___x_3186_ = v___x_3182_;
goto v_reusejp_3185_;
}
else
{
lean_object* v_reuseFailAlloc_3187_; 
v_reuseFailAlloc_3187_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3187_, 0, v_inst_3131_);
v___x_3186_ = v_reuseFailAlloc_3187_;
goto v_reusejp_3185_;
}
v_reusejp_3185_:
{
return v___x_3186_;
}
}
else
{
lean_object* v___x_3188_; lean_object* v___x_3189_; lean_object* v___x_3190_; lean_object* v___x_3191_; 
lean_del_object(v___x_3182_);
v___x_3188_ = lean_obj_once(&l_Lean_Meta_normalizeInstance___lam__1___closed__2, &l_Lean_Meta_normalizeInstance___lam__1___closed__2_once, _init_l_Lean_Meta_normalizeInstance___lam__1___closed__2);
lean_inc_ref(v_inst_3131_);
v___x_3189_ = l_Lean_MessageData_ofExpr(v_inst_3131_);
v___x_3190_ = lean_alloc_ctor(7, 2, 0);
lean_ctor_set(v___x_3190_, 0, v___x_3188_);
lean_ctor_set(v___x_3190_, 1, v___x_3189_);
v___x_3191_ = l_Lean_addTrace___at___00Lean_Meta_normalizeInstance_spec__4(v_cls_3136_, v___x_3190_, v___y_3138_, v___y_3139_, v___y_3140_, v___y_3141_);
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
if (lean_obj_tag(v___x_3191_) == 0)
{
lean_object* v___x_3193_; uint8_t v_isShared_3194_; uint8_t v_isSharedCheck_3198_; 
v_isSharedCheck_3198_ = !lean_is_exclusive(v___x_3191_);
if (v_isSharedCheck_3198_ == 0)
{
lean_object* v_unused_3199_; 
v_unused_3199_ = lean_ctor_get(v___x_3191_, 0);
lean_dec(v_unused_3199_);
v___x_3193_ = v___x_3191_;
v_isShared_3194_ = v_isSharedCheck_3198_;
goto v_resetjp_3192_;
}
else
{
lean_dec(v___x_3191_);
v___x_3193_ = lean_box(0);
v_isShared_3194_ = v_isSharedCheck_3198_;
goto v_resetjp_3192_;
}
v_resetjp_3192_:
{
lean_object* v___x_3196_; 
if (v_isShared_3194_ == 0)
{
lean_ctor_set(v___x_3193_, 0, v_inst_3131_);
v___x_3196_ = v___x_3193_;
goto v_reusejp_3195_;
}
else
{
lean_object* v_reuseFailAlloc_3197_; 
v_reuseFailAlloc_3197_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3197_, 0, v_inst_3131_);
v___x_3196_ = v_reuseFailAlloc_3197_;
goto v_reusejp_3195_;
}
v_reusejp_3195_:
{
return v___x_3196_;
}
}
}
else
{
lean_object* v_a_3200_; lean_object* v___x_3202_; uint8_t v_isShared_3203_; uint8_t v_isSharedCheck_3207_; 
lean_dec_ref(v_inst_3131_);
v_a_3200_ = lean_ctor_get(v___x_3191_, 0);
v_isSharedCheck_3207_ = !lean_is_exclusive(v___x_3191_);
if (v_isSharedCheck_3207_ == 0)
{
v___x_3202_ = v___x_3191_;
v_isShared_3203_ = v_isSharedCheck_3207_;
goto v_resetjp_3201_;
}
else
{
lean_inc(v_a_3200_);
lean_dec(v___x_3191_);
v___x_3202_ = lean_box(0);
v_isShared_3203_ = v_isSharedCheck_3207_;
goto v_resetjp_3201_;
}
v_resetjp_3201_:
{
lean_object* v___x_3205_; 
if (v_isShared_3203_ == 0)
{
v___x_3205_ = v___x_3202_;
goto v_reusejp_3204_;
}
else
{
lean_object* v_reuseFailAlloc_3206_; 
v_reuseFailAlloc_3206_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3206_, 0, v_a_3200_);
v___x_3205_ = v_reuseFailAlloc_3206_;
goto v_reusejp_3204_;
}
v_reusejp_3204_:
{
return v___x_3205_;
}
}
}
}
}
}
else
{
lean_object* v_a_3209_; lean_object* v___x_3211_; uint8_t v_isShared_3212_; uint8_t v_isSharedCheck_3216_; 
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec(v_cls_3136_);
lean_dec_ref(v_inst_3131_);
v_a_3209_ = lean_ctor_get(v___x_3179_, 0);
v_isSharedCheck_3216_ = !lean_is_exclusive(v___x_3179_);
if (v_isSharedCheck_3216_ == 0)
{
v___x_3211_ = v___x_3179_;
v_isShared_3212_ = v_isSharedCheck_3216_;
goto v_resetjp_3210_;
}
else
{
lean_inc(v_a_3209_);
lean_dec(v___x_3179_);
v___x_3211_ = lean_box(0);
v_isShared_3212_ = v_isSharedCheck_3216_;
goto v_resetjp_3210_;
}
v_resetjp_3210_:
{
lean_object* v___x_3214_; 
if (v_isShared_3212_ == 0)
{
v___x_3214_ = v___x_3211_;
goto v_reusejp_3213_;
}
else
{
lean_object* v_reuseFailAlloc_3215_; 
v_reuseFailAlloc_3215_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3215_, 0, v_a_3209_);
v___x_3214_ = v_reuseFailAlloc_3215_;
goto v_reusejp_3213_;
}
v_reusejp_3213_:
{
return v___x_3214_;
}
}
}
}
}
else
{
lean_object* v_a_3217_; lean_object* v___x_3219_; uint8_t v_isShared_3220_; uint8_t v_isSharedCheck_3224_; 
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec(v_cls_3136_);
lean_dec_ref(v_expectedType_3132_);
lean_dec_ref(v_inst_3131_);
v_a_3217_ = lean_ctor_get(v___x_3145_, 0);
v_isSharedCheck_3224_ = !lean_is_exclusive(v___x_3145_);
if (v_isSharedCheck_3224_ == 0)
{
v___x_3219_ = v___x_3145_;
v_isShared_3220_ = v_isSharedCheck_3224_;
goto v_resetjp_3218_;
}
else
{
lean_inc(v_a_3217_);
lean_dec(v___x_3145_);
v___x_3219_ = lean_box(0);
v_isShared_3220_ = v_isSharedCheck_3224_;
goto v_resetjp_3218_;
}
v_resetjp_3218_:
{
lean_object* v___x_3222_; 
if (v_isShared_3220_ == 0)
{
v___x_3222_ = v___x_3219_;
goto v_reusejp_3221_;
}
else
{
lean_object* v_reuseFailAlloc_3223_; 
v_reuseFailAlloc_3223_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3223_, 0, v_a_3217_);
v___x_3222_ = v_reuseFailAlloc_3223_;
goto v_reusejp_3221_;
}
v_reusejp_3221_:
{
return v___x_3222_;
}
}
}
}
else
{
lean_dec(v___y_3141_);
lean_dec_ref(v___y_3140_);
lean_dec(v___y_3139_);
lean_dec_ref(v___y_3138_);
lean_dec(v_cls_3136_);
lean_dec_ref(v_expectedType_3132_);
lean_dec_ref(v_inst_3131_);
return v___x_3143_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__1___boxed(lean_object* v_inst_3225_, lean_object* v_expectedType_3226_, lean_object* v___x_3227_, lean_object* v_compile_3228_, lean_object* v_hasTrace_3229_, lean_object* v_cls_3230_, lean_object* v_____r_3231_, lean_object* v___y_3232_, lean_object* v___y_3233_, lean_object* v___y_3234_, lean_object* v___y_3235_, lean_object* v___y_3236_){
_start:
{
uint8_t v___x_76595__boxed_3237_; uint8_t v_compile_boxed_3238_; uint8_t v_hasTrace_boxed_3239_; lean_object* v_res_3240_; 
v___x_76595__boxed_3237_ = lean_unbox(v___x_3227_);
v_compile_boxed_3238_ = lean_unbox(v_compile_3228_);
v_hasTrace_boxed_3239_ = lean_unbox(v_hasTrace_3229_);
v_res_3240_ = l_Lean_Meta_normalizeInstance___lam__1(v_inst_3225_, v_expectedType_3226_, v___x_76595__boxed_3237_, v_compile_boxed_3238_, v_hasTrace_boxed_3239_, v_cls_3230_, v_____r_3231_, v___y_3232_, v___y_3233_, v___y_3234_, v___y_3235_);
return v_res_3240_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___lam__2___boxed(lean_object* v_inst_3241_, lean_object* v_expectedType_3242_, lean_object* v_compile_3243_, lean_object* v___x_3244_, lean_object* v_cls_3245_, lean_object* v_____r_3246_, lean_object* v___y_3247_, lean_object* v___y_3248_, lean_object* v___y_3249_, lean_object* v___y_3250_, lean_object* v___y_3251_){
_start:
{
uint8_t v_compile_boxed_3252_; uint8_t v___x_76639__boxed_3253_; lean_object* v_res_3254_; 
v_compile_boxed_3252_ = lean_unbox(v_compile_3243_);
v___x_76639__boxed_3253_ = lean_unbox(v___x_3244_);
v_res_3254_ = l_Lean_Meta_normalizeInstance___lam__2(v_inst_3241_, v_expectedType_3242_, v_compile_boxed_3252_, v___x_76639__boxed_3253_, v_cls_3245_, v_____r_3246_, v___y_3247_, v___y_3248_, v___y_3249_, v___y_3250_);
return v_res_3254_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg___boxed(lean_object* v_upperBound_3255_, lean_object* v_fst_3256_, lean_object* v_args_3257_, lean_object* v___x_3258_, lean_object* v_compile_3259_, lean_object* v_a_3260_, lean_object* v_b_3261_, lean_object* v___y_3262_, lean_object* v___y_3263_, lean_object* v___y_3264_, lean_object* v___y_3265_, lean_object* v___y_3266_){
_start:
{
uint8_t v___x_76690__boxed_3267_; uint8_t v_compile_boxed_3268_; lean_object* v_res_3269_; 
v___x_76690__boxed_3267_ = lean_unbox(v___x_3258_);
v_compile_boxed_3268_ = lean_unbox(v_compile_3259_);
v_res_3269_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg(v_upperBound_3255_, v_fst_3256_, v_args_3257_, v___x_76690__boxed_3267_, v_compile_boxed_3268_, v_a_3260_, v_b_3261_, v___y_3262_, v___y_3263_, v___y_3264_, v___y_3265_);
lean_dec_ref(v_args_3257_);
lean_dec_ref(v_fst_3256_);
lean_dec(v_upperBound_3255_);
return v_res_3269_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg___boxed(lean_object* v_upperBound_3270_, lean_object* v_fst_3271_, lean_object* v_args_3272_, lean_object* v_compile_3273_, lean_object* v___x_3274_, lean_object* v___x_3275_, lean_object* v_a_3276_, lean_object* v_b_3277_, lean_object* v___y_3278_, lean_object* v___y_3279_, lean_object* v___y_3280_, lean_object* v___y_3281_, lean_object* v___y_3282_){
_start:
{
uint8_t v_compile_boxed_3283_; uint8_t v___x_76788__boxed_3284_; uint8_t v___x_76789__boxed_3285_; lean_object* v_res_3286_; 
v_compile_boxed_3283_ = lean_unbox(v_compile_3273_);
v___x_76788__boxed_3284_ = lean_unbox(v___x_3274_);
v___x_76789__boxed_3285_ = lean_unbox(v___x_3275_);
v_res_3286_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg(v_upperBound_3270_, v_fst_3271_, v_args_3272_, v_compile_boxed_3283_, v___x_76788__boxed_3284_, v___x_76789__boxed_3285_, v_a_3276_, v_b_3277_, v___y_3278_, v___y_3279_, v___y_3280_, v___y_3281_);
lean_dec_ref(v_args_3272_);
lean_dec_ref(v_fst_3271_);
lean_dec(v_upperBound_3270_);
return v_res_3286_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg___boxed(lean_object* v_upperBound_3287_, lean_object* v_fst_3288_, lean_object* v_args_3289_, lean_object* v_compile_3290_, lean_object* v___x_3291_, lean_object* v_a_3292_, lean_object* v_b_3293_, lean_object* v___y_3294_, lean_object* v___y_3295_, lean_object* v___y_3296_, lean_object* v___y_3297_, lean_object* v___y_3298_){
_start:
{
uint8_t v_compile_boxed_3299_; uint8_t v___x_76889__boxed_3300_; lean_object* v_res_3301_; 
v_compile_boxed_3299_ = lean_unbox(v_compile_3290_);
v___x_76889__boxed_3300_ = lean_unbox(v___x_3291_);
v_res_3301_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg(v_upperBound_3287_, v_fst_3288_, v_args_3289_, v_compile_boxed_3299_, v___x_76889__boxed_3300_, v_a_3292_, v_b_3293_, v___y_3294_, v___y_3295_, v___y_3296_, v___y_3297_);
lean_dec_ref(v_args_3289_);
lean_dec_ref(v_fst_3288_);
lean_dec(v_upperBound_3287_);
return v_res_3301_;
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12___boxed(lean_object* v_a_3302_, lean_object* v_expectedType_3303_, lean_object* v___x_3304_, lean_object* v_compile_3305_, lean_object* v_x_3306_, lean_object* v_x_3307_, lean_object* v_x_3308_, lean_object* v___y_3309_, lean_object* v___y_3310_, lean_object* v___y_3311_, lean_object* v___y_3312_, lean_object* v___y_3313_){
_start:
{
uint8_t v___x_77002__boxed_3314_; uint8_t v_compile_boxed_3315_; lean_object* v_res_3316_; 
v___x_77002__boxed_3314_ = lean_unbox(v___x_3304_);
v_compile_boxed_3315_ = lean_unbox(v_compile_3305_);
v_res_3316_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__12(v_a_3302_, v_expectedType_3303_, v___x_77002__boxed_3314_, v_compile_boxed_3315_, v_x_3306_, v_x_3307_, v_x_3308_, v___y_3309_, v___y_3310_, v___y_3311_, v___y_3312_);
return v_res_3316_;
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15___boxed(lean_object* v_a_3317_, lean_object* v_expectedType_3318_, lean_object* v___x_3319_, lean_object* v_compile_3320_, lean_object* v___x_3321_, lean_object* v_x_3322_, lean_object* v_x_3323_, lean_object* v_x_3324_, lean_object* v___y_3325_, lean_object* v___y_3326_, lean_object* v___y_3327_, lean_object* v___y_3328_, lean_object* v___y_3329_){
_start:
{
uint8_t v___x_77133__boxed_3330_; uint8_t v_compile_boxed_3331_; uint8_t v___x_77134__boxed_3332_; lean_object* v_res_3333_; 
v___x_77133__boxed_3330_ = lean_unbox(v___x_3319_);
v_compile_boxed_3331_ = lean_unbox(v_compile_3320_);
v___x_77134__boxed_3332_ = lean_unbox(v___x_3321_);
v_res_3333_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__15(v_a_3317_, v_expectedType_3318_, v___x_77133__boxed_3330_, v_compile_boxed_3331_, v___x_77134__boxed_3332_, v_x_3322_, v_x_3323_, v_x_3324_, v___y_3325_, v___y_3326_, v___y_3327_, v___y_3328_);
return v_res_3333_;
}
}
LEAN_EXPORT lean_object* l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17___boxed(lean_object* v_a_3334_, lean_object* v_expectedType_3335_, lean_object* v_compile_3336_, lean_object* v___x_3337_, lean_object* v_x_3338_, lean_object* v_x_3339_, lean_object* v_x_3340_, lean_object* v___y_3341_, lean_object* v___y_3342_, lean_object* v___y_3343_, lean_object* v___y_3344_, lean_object* v___y_3345_){
_start:
{
uint8_t v_compile_boxed_3346_; uint8_t v___x_77274__boxed_3347_; lean_object* v_res_3348_; 
v_compile_boxed_3346_ = lean_unbox(v_compile_3336_);
v___x_77274__boxed_3347_ = lean_unbox(v___x_3337_);
v_res_3348_ = l_Lean_Expr_withAppAux___at___00Lean_Meta_normalizeInstance_spec__17(v_a_3334_, v_expectedType_3335_, v_compile_boxed_3346_, v___x_77274__boxed_3347_, v_x_3338_, v_x_3339_, v_x_3340_, v___y_3341_, v___y_3342_, v___y_3343_, v___y_3344_);
return v_res_3348_;
}
}
LEAN_EXPORT lean_object* l_Lean_Meta_normalizeInstance___boxed(lean_object* v_inst_3349_, lean_object* v_expectedType_3350_, lean_object* v_compile_3351_, lean_object* v_a_3352_, lean_object* v_a_3353_, lean_object* v_a_3354_, lean_object* v_a_3355_, lean_object* v_a_3356_){
_start:
{
uint8_t v_compile_boxed_3357_; lean_object* v_res_3358_; 
v_compile_boxed_3357_ = lean_unbox(v_compile_3351_);
v_res_3358_ = l_Lean_Meta_normalizeInstance(v_inst_3349_, v_expectedType_3350_, v_compile_boxed_3357_, v_a_3352_, v_a_3353_, v_a_3354_, v_a_3355_);
return v_res_3358_;
}
}
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8(lean_object* v_mvarId_3359_, lean_object* v_val_3360_, lean_object* v___y_3361_, lean_object* v___y_3362_, lean_object* v___y_3363_, lean_object* v___y_3364_){
_start:
{
lean_object* v___x_3366_; 
v___x_3366_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___redArg(v_mvarId_3359_, v_val_3360_, v___y_3362_);
return v___x_3366_;
}
}
LEAN_EXPORT lean_object* l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8___boxed(lean_object* v_mvarId_3367_, lean_object* v_val_3368_, lean_object* v___y_3369_, lean_object* v___y_3370_, lean_object* v___y_3371_, lean_object* v___y_3372_, lean_object* v___y_3373_){
_start:
{
lean_object* v_res_3374_; 
v_res_3374_ = l_Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8(v_mvarId_3367_, v_val_3368_, v___y_3369_, v___y_3370_, v___y_3371_, v___y_3372_);
lean_dec(v___y_3372_);
lean_dec_ref(v___y_3371_);
lean_dec(v___y_3370_);
lean_dec_ref(v___y_3369_);
return v_res_3374_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9(lean_object* v_upperBound_3375_, lean_object* v_fst_3376_, lean_object* v_args_3377_, uint8_t v___x_3378_, uint8_t v_compile_3379_, lean_object* v_inst_3380_, lean_object* v_R_3381_, lean_object* v_a_3382_, lean_object* v_b_3383_, lean_object* v_c_3384_, lean_object* v___y_3385_, lean_object* v___y_3386_, lean_object* v___y_3387_, lean_object* v___y_3388_){
_start:
{
lean_object* v___x_3390_; 
v___x_3390_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___redArg(v_upperBound_3375_, v_fst_3376_, v_args_3377_, v___x_3378_, v_compile_3379_, v_a_3382_, v_b_3383_, v___y_3385_, v___y_3386_, v___y_3387_, v___y_3388_);
return v___x_3390_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9___boxed(lean_object* v_upperBound_3391_, lean_object* v_fst_3392_, lean_object* v_args_3393_, lean_object* v___x_3394_, lean_object* v_compile_3395_, lean_object* v_inst_3396_, lean_object* v_R_3397_, lean_object* v_a_3398_, lean_object* v_b_3399_, lean_object* v_c_3400_, lean_object* v___y_3401_, lean_object* v___y_3402_, lean_object* v___y_3403_, lean_object* v___y_3404_, lean_object* v___y_3405_){
_start:
{
uint8_t v___x_80255__boxed_3406_; uint8_t v_compile_boxed_3407_; lean_object* v_res_3408_; 
v___x_80255__boxed_3406_ = lean_unbox(v___x_3394_);
v_compile_boxed_3407_ = lean_unbox(v_compile_3395_);
v_res_3408_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__9(v_upperBound_3391_, v_fst_3392_, v_args_3393_, v___x_80255__boxed_3406_, v_compile_boxed_3407_, v_inst_3396_, v_R_3397_, v_a_3398_, v_b_3399_, v_c_3400_, v___y_3401_, v___y_3402_, v___y_3403_, v___y_3404_);
lean_dec_ref(v_args_3393_);
lean_dec_ref(v_fst_3392_);
lean_dec(v_upperBound_3391_);
return v_res_3408_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10(lean_object* v_00_u03b1_3409_, lean_object* v_msg_3410_, lean_object* v___y_3411_, lean_object* v___y_3412_, lean_object* v___y_3413_, lean_object* v___y_3414_){
_start:
{
lean_object* v___x_3416_; 
v___x_3416_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___redArg(v_msg_3410_, v___y_3411_, v___y_3412_, v___y_3413_, v___y_3414_);
return v___x_3416_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10___boxed(lean_object* v_00_u03b1_3417_, lean_object* v_msg_3418_, lean_object* v___y_3419_, lean_object* v___y_3420_, lean_object* v___y_3421_, lean_object* v___y_3422_, lean_object* v___y_3423_){
_start:
{
lean_object* v_res_3424_; 
v_res_3424_ = l_Lean_throwError___at___00Lean_Meta_normalizeInstance_spec__10(v_00_u03b1_3417_, v_msg_3418_, v___y_3419_, v___y_3420_, v___y_3421_, v___y_3422_);
lean_dec(v___y_3422_);
lean_dec_ref(v___y_3421_);
lean_dec(v___y_3420_);
lean_dec_ref(v___y_3419_);
return v_res_3424_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14(lean_object* v_upperBound_3425_, lean_object* v_fst_3426_, lean_object* v_args_3427_, uint8_t v_compile_3428_, uint8_t v___x_3429_, uint8_t v___x_3430_, lean_object* v_inst_3431_, lean_object* v_R_3432_, lean_object* v_a_3433_, lean_object* v_b_3434_, lean_object* v_c_3435_, lean_object* v___y_3436_, lean_object* v___y_3437_, lean_object* v___y_3438_, lean_object* v___y_3439_){
_start:
{
lean_object* v___x_3441_; 
v___x_3441_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___redArg(v_upperBound_3425_, v_fst_3426_, v_args_3427_, v_compile_3428_, v___x_3429_, v___x_3430_, v_a_3433_, v_b_3434_, v___y_3436_, v___y_3437_, v___y_3438_, v___y_3439_);
return v___x_3441_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14___boxed(lean_object* v_upperBound_3442_, lean_object* v_fst_3443_, lean_object* v_args_3444_, lean_object* v_compile_3445_, lean_object* v___x_3446_, lean_object* v___x_3447_, lean_object* v_inst_3448_, lean_object* v_R_3449_, lean_object* v_a_3450_, lean_object* v_b_3451_, lean_object* v_c_3452_, lean_object* v___y_3453_, lean_object* v___y_3454_, lean_object* v___y_3455_, lean_object* v___y_3456_, lean_object* v___y_3457_){
_start:
{
uint8_t v_compile_boxed_3458_; uint8_t v___x_80301__boxed_3459_; uint8_t v___x_80302__boxed_3460_; lean_object* v_res_3461_; 
v_compile_boxed_3458_ = lean_unbox(v_compile_3445_);
v___x_80301__boxed_3459_ = lean_unbox(v___x_3446_);
v___x_80302__boxed_3460_ = lean_unbox(v___x_3447_);
v_res_3461_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__14(v_upperBound_3442_, v_fst_3443_, v_args_3444_, v_compile_boxed_3458_, v___x_80301__boxed_3459_, v___x_80302__boxed_3460_, v_inst_3448_, v_R_3449_, v_a_3450_, v_b_3451_, v_c_3452_, v___y_3453_, v___y_3454_, v___y_3455_, v___y_3456_);
lean_dec_ref(v_args_3444_);
lean_dec_ref(v_fst_3443_);
lean_dec(v_upperBound_3442_);
return v_res_3461_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16(lean_object* v_upperBound_3462_, lean_object* v_fst_3463_, lean_object* v_args_3464_, uint8_t v_compile_3465_, uint8_t v___x_3466_, lean_object* v_inst_3467_, lean_object* v_R_3468_, lean_object* v_a_3469_, lean_object* v_b_3470_, lean_object* v_c_3471_, lean_object* v___y_3472_, lean_object* v___y_3473_, lean_object* v___y_3474_, lean_object* v___y_3475_){
_start:
{
lean_object* v___x_3477_; 
v___x_3477_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___redArg(v_upperBound_3462_, v_fst_3463_, v_args_3464_, v_compile_3465_, v___x_3466_, v_a_3469_, v_b_3470_, v___y_3472_, v___y_3473_, v___y_3474_, v___y_3475_);
return v___x_3477_;
}
}
LEAN_EXPORT lean_object* l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16___boxed(lean_object* v_upperBound_3478_, lean_object* v_fst_3479_, lean_object* v_args_3480_, lean_object* v_compile_3481_, lean_object* v___x_3482_, lean_object* v_inst_3483_, lean_object* v_R_3484_, lean_object* v_a_3485_, lean_object* v_b_3486_, lean_object* v_c_3487_, lean_object* v___y_3488_, lean_object* v___y_3489_, lean_object* v___y_3490_, lean_object* v___y_3491_, lean_object* v___y_3492_){
_start:
{
uint8_t v_compile_boxed_3493_; uint8_t v___x_80333__boxed_3494_; lean_object* v_res_3495_; 
v_compile_boxed_3493_ = lean_unbox(v_compile_3481_);
v___x_80333__boxed_3494_ = lean_unbox(v___x_3482_);
v_res_3495_ = l_WellFounded_opaqueFix_u2083___at___00Lean_Meta_normalizeInstance_spec__16(v_upperBound_3478_, v_fst_3479_, v_args_3480_, v_compile_boxed_3493_, v___x_80333__boxed_3494_, v_inst_3483_, v_R_3484_, v_a_3485_, v_b_3486_, v_c_3487_, v___y_3488_, v___y_3489_, v___y_3490_, v___y_3491_);
lean_dec_ref(v_args_3480_);
lean_dec_ref(v_fst_3479_);
lean_dec(v_upperBound_3478_);
return v_res_3495_;
}
}
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23(lean_object* v_00_u03b1_3496_, lean_object* v_x_3497_, lean_object* v___y_3498_, lean_object* v___y_3499_, lean_object* v___y_3500_, lean_object* v___y_3501_){
_start:
{
lean_object* v___x_3503_; 
v___x_3503_ = l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___redArg(v_x_3497_);
return v___x_3503_;
}
}
LEAN_EXPORT lean_object* l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23___boxed(lean_object* v_00_u03b1_3504_, lean_object* v_x_3505_, lean_object* v___y_3506_, lean_object* v___y_3507_, lean_object* v___y_3508_, lean_object* v___y_3509_, lean_object* v___y_3510_){
_start:
{
lean_object* v_res_3511_; 
v_res_3511_ = l_MonadExcept_ofExcept___at___00__private_Lean_Util_Trace_0__Lean_withTraceNode_postCallback___at___00Lean_Meta_normalizeInstance_spec__18_spec__23(v_00_u03b1_3504_, v_x_3505_, v___y_3506_, v___y_3507_, v___y_3508_, v___y_3509_);
lean_dec(v___y_3509_);
lean_dec_ref(v___y_3508_);
lean_dec(v___y_3507_);
lean_dec_ref(v___y_3506_);
return v_res_3511_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6(lean_object* v_00_u03b1_3512_, lean_object* v_constName_3513_, lean_object* v___y_3514_, lean_object* v___y_3515_, lean_object* v___y_3516_, lean_object* v___y_3517_){
_start:
{
lean_object* v___x_3519_; 
v___x_3519_ = l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___redArg(v_constName_3513_, v___y_3514_, v___y_3515_, v___y_3516_, v___y_3517_);
return v___x_3519_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6___boxed(lean_object* v_00_u03b1_3520_, lean_object* v_constName_3521_, lean_object* v___y_3522_, lean_object* v___y_3523_, lean_object* v___y_3524_, lean_object* v___y_3525_, lean_object* v___y_3526_){
_start:
{
lean_object* v_res_3527_; 
v_res_3527_ = l_Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6(v_00_u03b1_3520_, v_constName_3521_, v___y_3522_, v___y_3523_, v___y_3524_, v___y_3525_);
lean_dec(v___y_3525_);
lean_dec(v___y_3523_);
lean_dec_ref(v___y_3522_);
return v_res_3527_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10(lean_object* v_00_u03b2_3528_, lean_object* v_x_3529_, lean_object* v_x_3530_, lean_object* v_x_3531_){
_start:
{
lean_object* v___x_3532_; 
v___x_3532_ = l_Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10___redArg(v_x_3529_, v_x_3530_, v_x_3531_);
return v___x_3532_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9(lean_object* v_00_u03b1_3533_, lean_object* v_ref_3534_, lean_object* v_constName_3535_, lean_object* v___y_3536_, lean_object* v___y_3537_, lean_object* v___y_3538_, lean_object* v___y_3539_){
_start:
{
lean_object* v___x_3541_; 
v___x_3541_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___redArg(v_ref_3534_, v_constName_3535_, v___y_3536_, v___y_3537_, v___y_3538_, v___y_3539_);
return v___x_3541_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9___boxed(lean_object* v_00_u03b1_3542_, lean_object* v_ref_3543_, lean_object* v_constName_3544_, lean_object* v___y_3545_, lean_object* v___y_3546_, lean_object* v___y_3547_, lean_object* v___y_3548_, lean_object* v___y_3549_){
_start:
{
lean_object* v_res_3550_; 
v_res_3550_ = l_Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9(v_00_u03b1_3542_, v_ref_3543_, v_constName_3544_, v___y_3545_, v___y_3546_, v___y_3547_, v___y_3548_);
lean_dec(v___y_3548_);
lean_dec(v___y_3546_);
lean_dec_ref(v___y_3545_);
lean_dec(v_ref_3543_);
return v_res_3550_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13(lean_object* v_00_u03b2_3551_, lean_object* v_x_3552_, size_t v_x_3553_, size_t v_x_3554_, lean_object* v_x_3555_, lean_object* v_x_3556_){
_start:
{
lean_object* v___x_3557_; 
v___x_3557_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___redArg(v_x_3552_, v_x_3553_, v_x_3554_, v_x_3555_, v_x_3556_);
return v___x_3557_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13___boxed(lean_object* v_00_u03b2_3558_, lean_object* v_x_3559_, lean_object* v_x_3560_, lean_object* v_x_3561_, lean_object* v_x_3562_, lean_object* v_x_3563_){
_start:
{
size_t v_x_80423__boxed_3564_; size_t v_x_80424__boxed_3565_; lean_object* v_res_3566_; 
v_x_80423__boxed_3564_ = lean_unbox_usize(v_x_3560_);
lean_dec(v_x_3560_);
v_x_80424__boxed_3565_ = lean_unbox_usize(v_x_3561_);
lean_dec(v_x_3561_);
v_res_3566_ = l_Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13(v_00_u03b2_3558_, v_x_3559_, v_x_80423__boxed_3564_, v_x_80424__boxed_3565_, v_x_3562_, v_x_3563_);
return v_res_3566_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24(lean_object* v_00_u03b1_3567_, lean_object* v_ref_3568_, lean_object* v_msg_3569_, lean_object* v_declHint_3570_, lean_object* v___y_3571_, lean_object* v___y_3572_, lean_object* v___y_3573_, lean_object* v___y_3574_){
_start:
{
lean_object* v___x_3576_; 
v___x_3576_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___redArg(v_ref_3568_, v_msg_3569_, v_declHint_3570_, v___y_3571_, v___y_3572_, v___y_3573_, v___y_3574_);
return v___x_3576_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24___boxed(lean_object* v_00_u03b1_3577_, lean_object* v_ref_3578_, lean_object* v_msg_3579_, lean_object* v_declHint_3580_, lean_object* v___y_3581_, lean_object* v___y_3582_, lean_object* v___y_3583_, lean_object* v___y_3584_, lean_object* v___y_3585_){
_start:
{
lean_object* v_res_3586_; 
v_res_3586_ = l_Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24(v_00_u03b1_3577_, v_ref_3578_, v_msg_3579_, v_declHint_3580_, v___y_3581_, v___y_3582_, v___y_3583_, v___y_3584_);
lean_dec(v___y_3584_);
lean_dec(v___y_3582_);
lean_dec_ref(v___y_3581_);
lean_dec(v_ref_3578_);
return v_res_3586_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27(lean_object* v_00_u03b2_3587_, lean_object* v_n_3588_, lean_object* v_k_3589_, lean_object* v_v_3590_){
_start:
{
lean_object* v___x_3591_; 
v___x_3591_ = l_Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27___redArg(v_n_3588_, v_k_3589_, v_v_3590_);
return v___x_3591_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28(lean_object* v_00_u03b2_3592_, size_t v_depth_3593_, lean_object* v_keys_3594_, lean_object* v_vals_3595_, lean_object* v_heq_3596_, lean_object* v_i_3597_, lean_object* v_entries_3598_){
_start:
{
lean_object* v___x_3599_; 
v___x_3599_ = l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___redArg(v_depth_3593_, v_keys_3594_, v_vals_3595_, v_i_3597_, v_entries_3598_);
return v___x_3599_;
}
}
LEAN_EXPORT lean_object* l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28___boxed(lean_object* v_00_u03b2_3600_, lean_object* v_depth_3601_, lean_object* v_keys_3602_, lean_object* v_vals_3603_, lean_object* v_heq_3604_, lean_object* v_i_3605_, lean_object* v_entries_3606_){
_start:
{
size_t v_depth_boxed_3607_; lean_object* v_res_3608_; 
v_depth_boxed_3607_ = lean_unbox_usize(v_depth_3601_);
lean_dec(v_depth_3601_);
v_res_3608_ = l___private_Lean_Data_PersistentHashMap_0__Lean_PersistentHashMap_insertAux_traverse___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__28(v_00_u03b2_3600_, v_depth_boxed_3607_, v_keys_3602_, v_vals_3603_, v_heq_3604_, v_i_3605_, v_entries_3606_);
lean_dec_ref(v_vals_3603_);
lean_dec_ref(v_keys_3602_);
return v_res_3608_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30(lean_object* v_msg_3609_, lean_object* v_declHint_3610_, lean_object* v___y_3611_, lean_object* v___y_3612_, lean_object* v___y_3613_, lean_object* v___y_3614_){
_start:
{
lean_object* v___x_3616_; 
v___x_3616_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___redArg(v_msg_3609_, v_declHint_3610_, v___y_3614_);
return v___x_3616_;
}
}
LEAN_EXPORT lean_object* l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30___boxed(lean_object* v_msg_3617_, lean_object* v_declHint_3618_, lean_object* v___y_3619_, lean_object* v___y_3620_, lean_object* v___y_3621_, lean_object* v___y_3622_, lean_object* v___y_3623_){
_start:
{
lean_object* v_res_3624_; 
v_res_3624_ = l_Lean_mkUnknownIdentifierMessageCore___at___00Lean_mkUnknownIdentifierMessage___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__27_spec__30(v_msg_3617_, v_declHint_3618_, v___y_3619_, v___y_3620_, v___y_3621_, v___y_3622_);
lean_dec(v___y_3622_);
lean_dec_ref(v___y_3621_);
lean_dec(v___y_3620_);
lean_dec_ref(v___y_3619_);
return v_res_3624_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28(lean_object* v_00_u03b1_3625_, lean_object* v_ref_3626_, lean_object* v_msg_3627_, lean_object* v___y_3628_, lean_object* v___y_3629_, lean_object* v___y_3630_, lean_object* v___y_3631_){
_start:
{
lean_object* v___x_3633_; 
v___x_3633_ = l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___redArg(v_ref_3626_, v_msg_3627_, v___y_3628_, v___y_3629_, v___y_3630_, v___y_3631_);
return v___x_3633_;
}
}
LEAN_EXPORT lean_object* l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28___boxed(lean_object* v_00_u03b1_3634_, lean_object* v_ref_3635_, lean_object* v_msg_3636_, lean_object* v___y_3637_, lean_object* v___y_3638_, lean_object* v___y_3639_, lean_object* v___y_3640_, lean_object* v___y_3641_){
_start:
{
lean_object* v_res_3642_; 
v_res_3642_ = l_Lean_throwErrorAt___at___00Lean_throwUnknownIdentifierAt___at___00Lean_throwUnknownConstantAt___at___00Lean_throwUnknownConstant___at___00Lean_getConstInfo___at___00Lean_Meta_normalizeInstance_spec__5_spec__6_spec__9_spec__24_spec__28(v_00_u03b1_3634_, v_ref_3635_, v_msg_3636_, v___y_3637_, v___y_3638_, v___y_3639_, v___y_3640_);
lean_dec(v___y_3640_);
lean_dec(v___y_3638_);
lean_dec_ref(v___y_3637_);
lean_dec(v_ref_3635_);
return v_res_3642_;
}
}
LEAN_EXPORT lean_object* l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31(lean_object* v_00_u03b2_3643_, lean_object* v_x_3644_, lean_object* v_x_3645_, lean_object* v_x_3646_, lean_object* v_x_3647_){
_start:
{
lean_object* v___x_3648_; 
v___x_3648_ = l_Lean_PersistentHashMap_insertAtCollisionNodeAux___at___00Lean_PersistentHashMap_insertAtCollisionNode___at___00Lean_PersistentHashMap_insertAux___at___00Lean_PersistentHashMap_insert___at___00Lean_MVarId_assign___at___00Lean_Meta_normalizeInstance_spec__8_spec__10_spec__13_spec__27_spec__31___redArg(v_x_3644_, v_x_3645_, v_x_3646_, v_x_3647_);
return v___x_3648_;
}
}
lean_object* runtime_initialize_Lean_Meta_Closure(uint8_t builtin);
lean_object* runtime_initialize_Lean_Meta_SynthInstance(uint8_t builtin);
lean_object* runtime_initialize_Lean_Meta_CtorRecognizer(uint8_t builtin);
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_Lean_Meta_InstanceNormalForm(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
res = runtime_initialize_Lean_Meta_Closure(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Meta_SynthInstance(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Meta_CtorRecognizer(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2931430899____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
l_Lean_Meta_instance_normalForm = lean_io_result_get_value(res);
lean_mark_persistent(l_Lean_Meta_instance_normalForm);
lean_dec_ref(res);
res = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_1451004386____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
l_Lean_Meta_instance_normalForm_wrapInstances = lean_io_result_get_value(res);
lean_mark_persistent(l_Lean_Meta_instance_normalForm_wrapInstances);
lean_dec_ref(res);
res = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2151339642____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
l_Lean_Meta_instance_normalForm_wrapFields_data = lean_io_result_get_value(res);
lean_mark_persistent(l_Lean_Meta_instance_normalForm_wrapFields_data);
lean_dec_ref(res);
res = l_Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2032797773____hygCtx___hyg_4_();
if (lean_io_result_is_error(res)) return res;
l_Lean_Meta_instance_normalForm_wrapFields_proofs = lean_io_result_get_value(res);
lean_mark_persistent(l_Lean_Meta_instance_normalForm_wrapFields_proofs);
lean_dec_ref(res);
res = l___private_Lean_Meta_InstanceNormalForm_0__Lean_Meta_initFn_00___x40_Lean_Meta_InstanceNormalForm_2034682956____hygCtx___hyg_2_();
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_Lean_Meta_InstanceNormalForm(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Lean_Meta_Closure(uint8_t builtin);
lean_object* initialize_Lean_Meta_SynthInstance(uint8_t builtin);
lean_object* initialize_Lean_Meta_CtorRecognizer(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_Lean_Meta_InstanceNormalForm(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Lean_Meta_Closure(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Meta_SynthInstance(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean_Meta_CtorRecognizer(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_Lean_Meta_InstanceNormalForm(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_Lean_Meta_InstanceNormalForm(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_Lean_Meta_InstanceNormalForm(builtin);
}
#ifdef __cplusplus
}
#endif
