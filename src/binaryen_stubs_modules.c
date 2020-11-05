#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenModuleRef */
static value alloc_BinaryenModuleRef(BinaryenModuleRef typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenModuleRef), 0, 1);
  BinaryenModuleRef_val(v) = typ;
  return v;
}

CAMLprim value
caml_binaryen_module_create(value unit) {
  CAMLparam1(unit);
  BinaryenModuleRef module = BinaryenModuleCreate();
  CAMLreturn(alloc_BinaryenModuleRef(module));
}

CAMLprim value
caml_binaryen_module_dispose(value module) {
  CAMLparam1(module);
  BinaryenModuleDispose(BinaryenModuleRef_val(module));
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_parse(value _text) {
  CAMLparam1(_text);
  const char* text = Safe_String_val(_text);
  BinaryenModuleRef module = BinaryenModuleParse(text);
  CAMLreturn(alloc_BinaryenModuleRef(module));
}

CAMLprim value
caml_binaryen_module_print(value module) {
  CAMLparam1(module);
  BinaryenModulePrint(BinaryenModuleRef_val(module));
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_print_asmjs(value module) {
  CAMLparam1(module);
  BinaryenModulePrintAsmjs(BinaryenModuleRef_val(module));
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_validate(value module) {
  CAMLparam1(module);
  int res = BinaryenModuleValidate(BinaryenModuleRef_val(module));
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_module_optimize(value module) {
  CAMLparam1(module);
  BinaryenModuleOptimize(BinaryenModuleRef_val(module));
  CAMLreturn(Val_unit);
}

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
  int res = BinaryenGetDebugInfo();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_debug_info(value _level) {
  CAMLparam1(_level);
  int level = Int_val(_level);
  BinaryenSetDebugInfo(level);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_low_memory_unused(value unit) {
  CAMLparam1(unit);
  int res = BinaryenGetLowMemoryUnused();
  CAMLreturn(Val_int(res));
}

CAMLprim value
caml_binaryen_set_low_memory_unused(value _level) {
  CAMLparam1(_level);
  int level = Int_val(_level);
  BinaryenSetLowMemoryUnused(level);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_pass_argument(value _name) {
  CAMLparam1(_name);
  const char* name = Safe_String_val(_name);
  const char* val = BinaryenGetPassArgument(name);
  CAMLreturn(caml_copy_string(val));
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
caml_binaryen_module_run_passes(value _module, value _passes) {
  CAMLparam2(_module, _passes);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  _passes = array_of_list(_passes);
  int passesLen = array_length(_passes);
  const char* passes[passesLen];
  for (int i = 0; i < passesLen; i++) {
    passes[i] = Safe_String_val(Field(_passes, i));
  }
  BinaryenModuleRunPasses(module, passes, passesLen);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_auto_drop(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenModuleAutoDrop(module);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_write(value _module, value _sourceMapUrl) {
  CAMLparam2(_module, _sourceMapUrl);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  const char* sourceMapUrl;
  if (Is_some(_sourceMapUrl)) {
    sourceMapUrl = Safe_String_val(Field(_sourceMapUrl, 0));
  } else {
    sourceMapUrl = NULL;
  }
  BinaryenModuleAllocateAndWriteResult result = BinaryenModuleAllocateAndWrite(module, sourceMapUrl);
  CAMLlocal3(binary, sourceMap, tuple);
  binary = caml_alloc_initialized_string(result.binaryBytes, result.binary);
  if (Is_some(_sourceMapUrl)) {
    sourceMap = caml_alloc_some(caml_copy_string(result.sourceMap));
  } else {
    sourceMap = Val_none;
  }
  free(result.binary);
  free(result.sourceMap);
  tuple = caml_alloc_tuple(2);
  Store_field(tuple, 0, binary);
  Store_field(tuple, 1, sourceMap);
  CAMLreturn(tuple);
}

CAMLprim value
caml_binaryen_module_write_text(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* result = BinaryenModuleAllocateAndWriteText(module);
  CAMLlocal1(text);
  text = caml_copy_string(result);
  free(result);
  CAMLreturn(text);
}

CAMLprim value
caml_binaryen_module_read(value _bytes) {
  CAMLparam1(_bytes);
  char* bytes = Safe_String_val(_bytes);
  int length = caml_string_length(_bytes);
  BinaryenModuleRef result = BinaryenModuleRead(bytes, length);
  CAMLreturn(alloc_BinaryenModuleRef(result));
}

CAMLprim value
caml_binaryen_module_interpret(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenModuleInterpret(module);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_module_add_debug_info_filename(value _module, value _filename) {
  CAMLparam2(_module, _filename);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  const char* filename = Safe_String_val(_filename);
  int result = BinaryenModuleAddDebugInfoFileName(module, filename);
  CAMLreturn(Val_int(result));
}

CAMLprim value
caml_binaryen_module_get_debug_info_filename(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int index = Int_val(_index);
  const char* result = BinaryenModuleGetDebugInfoFileName(module, index);
  CAMLlocal1(text);
  text = caml_copy_string(result);
  CAMLreturn(text);
}

CAMLprim value
caml_binaryen_add_custom_section(value _module, value _name, value _contents) {
  CAMLparam3(_module, _name, _contents);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  const char* name = Safe_String_val(_name);
  const char* contents = Safe_String_val(_contents);
  int contentsLen = caml_string_length(_contents);
  BinaryenAddCustomSection(module, name, contents, contentsLen);
  CAMLreturn(Val_unit);
}
