#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

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
