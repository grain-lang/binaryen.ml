#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


/* Allocating an OCaml custom block to hold the given BinaryenTableRef */
static value alloc_BinaryenTableRef(BinaryenTableRef table)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenTableRef), 0, 1);
  BinaryenTableRef_val(v) = table;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenElementSegmentRef */
static value alloc_BinaryenElementSegmentRef(BinaryenElementSegmentRef elem)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenElementSegmentRef), 0, 1);
  BinaryenElementSegmentRef_val(v) = elem;
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
caml_binaryen_add_table(value _module, value _table, value _initial, value _maximum) {
  CAMLparam4(_module, _table, _initial, _maximum);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* table = Safe_String_val(_table);
  BinaryenIndex initial = Int_val(_initial);
  BinaryenIndex maximum = Int_val(_maximum);
  CAMLreturn(alloc_BinaryenTableRef(BinaryenAddTable(module, table, initial, maximum)));
}

CAMLprim value
caml_binaryen_add_active_element_segment(value _module, value _table, value _name, value _funcnames, value _offset) {
  CAMLparam5(_module, _table, _name, _funcnames, _offset);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* table = Safe_String_val(_table);
  char* name = Safe_String_val(_name);
  _funcnames = array_of_list(_funcnames);
  int funcnamesLen = array_length(_funcnames);
  const char* funcnames[funcnamesLen];
  for (int i = 0; i < funcnamesLen; i++) {
    funcnames[i] = Safe_String_val(Field(_funcnames, i));
  }
  BinaryenExpressionRef offset = BinaryenExpressionRef_val(_offset);
  CAMLreturn(alloc_BinaryenElementSegmentRef(BinaryenAddActiveElementSegment(module, table, name, funcnames, funcnamesLen, offset)));
}

CAMLprim value
caml_binaryen_remove_element_segment(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenRemoveElementSegment(module, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_num_element_segments(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenGetNumElementSegments(module)));
}

CAMLprim value
caml_binaryen_get_element_segment(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  CAMLreturn(alloc_BinaryenElementSegmentRef(BinaryenGetElementSegment(module, name)));
}

CAMLprim value
caml_binaryen_get_element_segment_by_index(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenElementSegmentRef(BinaryenGetElementSegmentByIndex(module, index)));
}

CAMLprim value
caml_binaryen_element_segment_get_name(value _elem) {
  CAMLparam1(_elem);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  CAMLreturn(caml_copy_string(BinaryenElementSegmentGetName(elem)));
}

CAMLprim value
caml_binaryen_element_segment_set_name(value _elem, value _name) {
  CAMLparam2(_elem, _name);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  char* name = Safe_String_val(_name);
  BinaryenElementSegmentSetName(elem, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_element_segment_get_table(value _elem) {
  CAMLparam1(_elem);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  CAMLreturn(caml_copy_string(BinaryenElementSegmentGetTable(elem)));
}

CAMLprim value
caml_binaryen_element_segment_set_table(value _elem, value _table) {
  CAMLparam2(_elem, _table);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  char* table = Safe_String_val(_table);
  BinaryenElementSegmentSetTable(elem, table);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_element_segment_get_offset(value _elem) {
  CAMLparam1(_elem);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenElementSegmentGetOffset(elem)));
}

CAMLprim value
caml_binaryen_element_segment_get_length(value _elem) {
  CAMLparam1(_elem);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  CAMLreturn(Val_int(BinaryenElementSegmentGetLength(elem)));
}

CAMLprim value
caml_binaryen_element_segment_get_data(value _elem, value _index) {
  CAMLparam2(_elem, _index);
  BinaryenElementSegmentRef elem = BinaryenElementSegmentRef_val(_elem);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(caml_copy_string(BinaryenElementSegmentGetData(elem, index)));
}
