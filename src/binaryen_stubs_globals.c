#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


/* Allocating an OCaml custom block to hold the given BinaryenGlobalRef */
static value alloc_BinaryenGlobalRef(BinaryenGlobalRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenGlobalRef), 0, 1);
  BinaryenGlobalRef_val(v) = exp;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenType */
static value alloc_BinaryenType(BinaryenType typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenType), 0, 1);
  BinaryenType_val(v) = typ;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenExpressionRef */
static value alloc_BinaryenExpressionRef(BinaryenExpressionRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExpressionRef), 0, 1);
  BinaryenExpressionRef_val(v) = exp;
  return v;
}

CAMLprim value
caml_binaryen_add_global(value _module, value _name, value _ty, value _mutable_, value _init) {
  CAMLparam5(_module, _name, _ty, _mutable_, _init);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenType ty = BinaryenType_val(_ty);
  int8_t mutable_ = Bool_val(_mutable_);
  BinaryenExpressionRef init = BinaryenExpressionRef_val(_init);
  BinaryenGlobalRef glob = BinaryenAddGlobal(module, name, ty, mutable_, init);
  CAMLreturn(alloc_BinaryenGlobalRef(glob));
}

CAMLprim value
caml_binaryen_get_global(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenGlobalRef glob = BinaryenGetGlobal(module, name);
  CAMLreturn(alloc_BinaryenGlobalRef(glob));
}

CAMLprim value
caml_binaryen_remove_global(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenRemoveGlobal(module, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_num_globals(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenGetNumGlobals(module)));
}

CAMLprim value
caml_binaryen_get_global_by_index(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenGlobalRef(BinaryenGetGlobalByIndex(module, index)));
}

CAMLprim value
caml_binaryen_global_get_name(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  const char* name = BinaryenGlobalGetName(global);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_global_get_type(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  BinaryenType ty = BinaryenGlobalGetType(global);
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_global_is_mutable(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  CAMLreturn(Val_bool(BinaryenGlobalIsMutable(global)));
}

CAMLprim value
caml_binaryen_global_get_init_expr(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  BinaryenExpressionRef exp = BinaryenGlobalGetInitExpr(global);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
