#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <binaryen-c.h>

#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenGlobalRef */
static value alloc_BinaryenGlobalRef(BinaryenGlobalRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenGlobalRef), 0, 1);
  BinaryenGlobalRef_val(v) = exp;
  return v;
}

CAMLprim value
caml_binaryen_add_global(value _module, value _name, value _ty, value _mutable_, value _init) {
  CAMLparam5(_module, _name, _ty, _mutable_, _init);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = String_val(_name);
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
  char* name = String_val(_name);
  BinaryenGlobalRef glob = BinaryenGetGlobal(module, name);
  CAMLreturn(alloc_BinaryenGlobalRef(glob));
}

CAMLprim value
caml_binaryen_remove_global(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = String_val(_name);
  BinaryenRemoveGlobal(module, name);
  CAMLreturn(Val_unit);
}
