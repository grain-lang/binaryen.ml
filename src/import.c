#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_add_function_import(value _module, value _internalName, value _externalModuleName, value _externalBaseName, value _paramsty, value _resultsty) {
  CAMLparam5(_module, _internalName, _externalModuleName, _externalBaseName, _paramsty);
  CAMLxparam1(_resultsty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalModuleName = Safe_String_val(_externalModuleName);
  char* externalBaseName = Safe_String_val(_externalBaseName);
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType resultsty = BinaryenType_val(_resultsty);
  BinaryenAddFunctionImport(module, internalName, externalModuleName, externalBaseName, paramsty, resultsty);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_binaryen_add_function_import__bytecode(value * argv) {
  return caml_binaryen_add_function_import(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_binaryen_add_table_import(value _module, value _internalName, value _externalModuleName, value _externalBaseName) {
  CAMLparam4(_module, _internalName, _externalModuleName, _externalBaseName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalModuleName = Safe_String_val(_externalModuleName);
  char* externalBaseName = Safe_String_val(_externalBaseName);
  BinaryenAddTableImport(module, internalName, externalModuleName, externalBaseName);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_add_memory_import(value _module, value _internalName, value _externalModuleName, value _externalBaseName, value _shared) {
  CAMLparam5(_module, _internalName, _externalModuleName, _externalBaseName, _shared);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalModuleName = Safe_String_val(_externalModuleName);
  char* externalBaseName = Safe_String_val(_externalBaseName);
  uint8_t shared = Bool_val(_shared);
  BinaryenAddMemoryImport(module, internalName, externalModuleName, externalBaseName, shared);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_add_global_import(value _module, value _internalName, value _externalModuleName, value _externalBaseName, value _ty, value _mutable_) {
  CAMLparam5(_module, _internalName, _externalModuleName, _externalBaseName, _ty);
  CAMLxparam1(_mutable_);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalModuleName = Safe_String_val(_externalModuleName);
  char* externalBaseName = Safe_String_val(_externalBaseName);
  BinaryenType ty = BinaryenType_val(_ty);
  int mutable_ = Bool_val(_mutable_);
  BinaryenAddGlobalImport(module, internalName, externalModuleName, externalBaseName, ty, mutable_);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_binaryen_add_global_import__bytecode(value * argv) {
  return caml_binaryen_add_global_import(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_binaryen_add_tag_import(value _module, value _internalName, value _externalModuleName, value _externalBaseName, value _paramsty, value _resultsty) {
  CAMLparam5(_module, _internalName, _externalModuleName, _externalBaseName, _paramsty);
  CAMLxparam1(_resultsty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalModuleName = Safe_String_val(_externalModuleName);
  char* externalBaseName = Safe_String_val(_externalBaseName);
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType resultsty = BinaryenType_val(_resultsty);
  BinaryenAddTagImport(module, internalName, externalModuleName, externalBaseName, paramsty, resultsty);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_binaryen_add_tag_import__bytecode(value * argv) {
  return caml_binaryen_add_tag_import(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_binaryen_function_import_get_module(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(caml_copy_string(BinaryenFunctionImportGetModule(fun)));
}

CAMLprim value
caml_binaryen_memory_import_get_module(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  CAMLreturn(caml_copy_string(BinaryenMemoryImportGetModule(module, memoryName)));
}

CAMLprim value
caml_binaryen_global_import_get_module(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  CAMLreturn(caml_copy_string(BinaryenGlobalImportGetModule(global)));
}

CAMLprim value
caml_binaryen_tag_import_get_module(value _tag) {
  CAMLparam1(_tag);
  BinaryenTagRef tag = BinaryenTagRef_val(_tag);
  CAMLreturn(caml_copy_string(BinaryenTagImportGetModule(tag)));
}

CAMLprim value
caml_binaryen_function_import_get_base(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(caml_copy_string(BinaryenFunctionImportGetBase(fun)));
}

CAMLprim value
caml_binaryen_memory_import_get_base(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  CAMLreturn(caml_copy_string(BinaryenMemoryImportGetBase(module, memoryName)));
}

CAMLprim value
caml_binaryen_global_import_get_base(value _global) {
  CAMLparam1(_global);
  BinaryenGlobalRef global = BinaryenGlobalRef_val(_global);
  CAMLreturn(caml_copy_string(BinaryenGlobalImportGetBase(global)));
}

CAMLprim value
caml_binaryen_tag_import_get_base(value _tag) {
  CAMLparam1(_tag);
  BinaryenTagRef tag = BinaryenTagRef_val(_tag);
  CAMLreturn(caml_copy_string(BinaryenTagImportGetBase(tag)));
}
