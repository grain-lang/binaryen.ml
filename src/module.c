#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

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
caml_binaryen_module_print_stack_ir(value module) {
  CAMLparam1(module);
  BinaryenModulePrintStackIR(BinaryenModuleRef_val(module));
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

// There is something weird with this function that causes a bunch of newlines to
// be printed on stdout when calling it. Not sure if that's a bug in Binaryen.
CAMLprim value
caml_binaryen_module_write_stack_ir(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* result = BinaryenModuleAllocateAndWriteStackIR(module);
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

CAMLprim value
caml_binaryen_module_update_maps(value module) {
  CAMLparam1(module);
  BinaryenModuleUpdateMaps(BinaryenModuleRef_val(module));
  CAMLreturn(Val_unit);
}
