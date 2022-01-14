#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

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
caml_binaryen_get_export(value _module, value _externalName) {
  CAMLparam2(_module, _externalName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* externalName = Safe_String_val(_externalName);
  BinaryenExportRef exp = BinaryenGetExport(module, externalName);
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

CAMLprim value
caml_binaryen_get_num_exports(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex num = BinaryenGetNumExports(module);
  CAMLreturn(Val_int(num));
}

CAMLprim value
caml_binaryen_get_export_by_index(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex index = Int_val(_index);
  BinaryenExportRef exp = BinaryenGetExportByIndex(module, index);
  CAMLreturn(alloc_BinaryenExportRef(exp));
}

CAMLprim value
caml_binaryen_export_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExportRef exp = BinaryenExportRef_val(_exp);
  CAMLreturn(caml_copy_string(BinaryenExportGetName(exp)));
}

CAMLprim value
caml_binaryen_export_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExportRef exp = BinaryenExportRef_val(_exp);
  CAMLreturn(caml_copy_string(BinaryenExportGetValue(exp)));
}

CAMLprim value
caml_binaryen_external_function(value _unit) {
  CAMLparam1(_unit);
  CAMLreturn(Val_int(BinaryenExternalFunction()));
}

CAMLprim value
caml_binaryen_external_table(value _unit) {
  CAMLparam1(_unit);
  CAMLreturn(Val_int(BinaryenExternalTable()));
}

CAMLprim value
caml_binaryen_external_memory(value _unit) {
  CAMLparam1(_unit);
  CAMLreturn(Val_int(BinaryenExternalMemory()));
}

CAMLprim value
caml_binaryen_external_global(value _unit) {
  CAMLparam1(_unit);
  CAMLreturn(Val_int(BinaryenExternalGlobal()));
}

CAMLprim value
caml_binaryen_external_tag(value _unit) {
  CAMLparam1(_unit);
  CAMLreturn(Val_int(BinaryenExternalTag()));
}

CAMLprim value
caml_binaryen_export_get_kind(value _exp) {
  CAMLparam1(_exp);
  BinaryenExportRef exp = BinaryenExportRef_val(_exp);
  CAMLreturn(Val_int(BinaryenExportGetKind(exp)));
}
