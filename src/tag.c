#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_add_tag(value _module, value _name, value _params, value _results) {
  CAMLparam4(_module, _name, _params, _results);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenType params = BinaryenType_val(_params);
  BinaryenType results = BinaryenType_val(_results);
  BinaryenTagRef tag = BinaryenAddTag(module, name, params, results);
  CAMLreturn(alloc_BinaryenTagRef(tag));
}

CAMLprim value
caml_binaryen_get_tag(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenTagRef tag = BinaryenGetTag(module, name);
  CAMLreturn(alloc_BinaryenTagRef(tag));
}

CAMLprim value
caml_binaryen_remove_tag(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenRemoveTag(module, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tag_get_name(value _tag) {
  CAMLparam1(_tag);
  BinaryenTagRef tag = BinaryenTagRef_val(_tag);
  const char* name = BinaryenTagGetName(tag);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_tag_get_params(value _tag) {
  CAMLparam1(_tag);
  BinaryenTagRef tag = BinaryenTagRef_val(_tag);
  BinaryenType ty = BinaryenTagGetParams(tag);
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_tag_get_results(value _tag) {
  CAMLparam1(_tag);
  BinaryenTagRef tag = BinaryenTagRef_val(_tag);
  BinaryenType ty = BinaryenTagGetResults(tag);
  CAMLreturn(alloc_BinaryenType(ty));
}
