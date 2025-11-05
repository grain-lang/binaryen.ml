#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_get_optimize_level(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetOptimizeLevel();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_optimize_level(value _level) {
  CAMLparam1(_level);
  int level = Int_val(_level);
  BinaryenSetOptimizeLevel(level);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_shrink_level(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetShrinkLevel();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_shrink_level(value _level) {
  CAMLparam1(_level);
  int level = Int_val(_level);
  BinaryenSetShrinkLevel(level);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_debug_info(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetDebugInfo();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_debug_info(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetDebugInfo(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_low_memory_unused(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetLowMemoryUnused();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_low_memory_unused(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetLowMemoryUnused(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_pass_argument(value _name) {
  CAMLparam1(_name);
  const char* name = Safe_String_val(_name);
  const char* val = BinaryenGetPassArgument(name);
  if (val == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(caml_copy_string(val)));
  }
}

CAMLprim value
caml_binaryen_set_pass_argument(value _name, value _val) {
  CAMLparam2(_name, _val);
  const char* name = Safe_String_val(_name);
  const char* val = Safe_String_val(_val);
  BinaryenSetPassArgument(name, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_always_inline_max_size(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetAlwaysInlineMaxSize();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_always_inline_max_size(value _size) {
  CAMLparam1(_size);
  int size = Int_val(_size);
  BinaryenSetAlwaysInlineMaxSize(size);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_flexible_inline_max_size(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetFlexibleInlineMaxSize();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_flexible_inline_max_size(value _size) {
  CAMLparam1(_size);
  int size = Int_val(_size);
  BinaryenSetFlexibleInlineMaxSize(size);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_one_caller_inline_max_size(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetOneCallerInlineMaxSize();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_one_caller_inline_max_size(value _size) {
  CAMLparam1(_size);
  int size = Int_val(_size);
  BinaryenSetOneCallerInlineMaxSize(size);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_set_colors_enabled(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetColorsEnabled(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_are_colors_enabled(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenAreColorsEnabled();
  CAMLreturn(Val_bool(res));
}
