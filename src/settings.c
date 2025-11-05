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
caml_binaryen_get_traps_never_happen(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetTrapsNeverHappen();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_traps_never_happen(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetTrapsNeverHappen(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_closed_world(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetClosedWorld();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_closed_world(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetClosedWorld(on);
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
caml_binaryen_get_zero_filled_memory(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetZeroFilledMemory();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_zero_filled_memory(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetZeroFilledMemory(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_fast_math(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetFastMath();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_fast_math(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetFastMath(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_generate_stack_ir(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetGenerateStackIR();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_generate_stack_ir(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetGenerateStackIR(on);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_optimize_stack_ir(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetOptimizeStackIR();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_optimize_stack_ir(value _on) {
  CAMLparam1(_on);
  bool on = Bool_val(_on);
  BinaryenSetOptimizeStackIR(on);
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
caml_binaryen_clear_pass_arguments(value unit) {
  CAMLparam1(unit);
  BinaryenClearPassArguments();
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_has_pass_to_skip(value _pass) {
  CAMLparam1(_pass);
  const char* pass = Safe_String_val(_pass);
  bool res = BinaryenHasPassToSkip(pass);
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_add_pass_to_skip(value _pass) {
  CAMLparam1(_pass);
  const char* pass = Safe_String_val(_pass);
  BinaryenAddPassToSkip(pass);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_clear_passes_to_skip(value unit) {
  CAMLparam1(unit);
  BinaryenClearPassesToSkip();
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
caml_binaryen_get_allow_inlining_functions_with_loops(value unit) {
  CAMLparam1(unit);
  bool res = BinaryenGetAllowInliningFunctionsWithLoops();
  CAMLreturn(Val_bool(res));
}

CAMLprim value
caml_binaryen_set_allow_inlining_functions_with_loops(value _size) {
  CAMLparam1(_size);
  int on = Bool_val(_size);
  BinaryenSetAllowInliningFunctionsWithLoops(on);
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
