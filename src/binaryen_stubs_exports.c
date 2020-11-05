#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenExportRef */
static value alloc_BinaryenExportRef(BinaryenExportRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExportRef), 0, 1);
  BinaryenExportRef_val(v) = exp;
  return v;
}

CAMLprim value
caml_binaryen_add_function_export(value _module, value _internalName, value _externalName) {
  CAMLparam3(_module, _internalName, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalName = Safe_String_val(_externalName);
  BinaryenExportRef exp = BinaryenAddFunctionExport(module, internalName, externalName);
  CAMLreturn(alloc_BinaryenExportRef(exp));
}

CAMLprim value
caml_binaryen_add_table_export(value _module, value _internalName, value _externalName) {
  CAMLparam3(_module, _internalName, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalName = Safe_String_val(_externalName);
  BinaryenExportRef exp = BinaryenAddTableExport(module, internalName, externalName);
  CAMLreturn(alloc_BinaryenExportRef(exp));
}

CAMLprim value
caml_binaryen_add_memory_export(value _module, value _internalName, value _externalName) {
  CAMLparam3(_module, _internalName, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalName = Safe_String_val(_externalName);
  BinaryenExportRef exp = BinaryenAddMemoryExport(module, internalName, externalName);
  CAMLreturn(alloc_BinaryenExportRef(exp));
}

CAMLprim value
caml_binaryen_add_global_export(value _module, value _internalName, value _externalName) {
  CAMLparam3(_module, _internalName, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* internalName = Safe_String_val(_internalName);
  char* externalName = Safe_String_val(_externalName);
  BinaryenExportRef exp = BinaryenAddGlobalExport(module, internalName, externalName);
  CAMLreturn(alloc_BinaryenExportRef(exp));
}

CAMLprim value
caml_binaryen_remove_export(value _module, value _externalName) {
  CAMLparam2(_module, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* externalName = Safe_String_val(_externalName);
  BinaryenRemoveExport(module, externalName);
  CAMLreturn(Val_unit);
}
