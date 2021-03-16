#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_add_table(value _module, value _name, value _initial, value _maximum, value _funcnames, value _offset) {
  CAMLparam5(_module, _name, _initial, _maximum, _funcnames);
  CAMLxparam1(_offset);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenIndex initial = Int_val(_initial);
  BinaryenIndex maximum = Int_val(_maximum);
  _funcnames = array_of_list(_funcnames);
  int funcnamesLen = array_length(_funcnames);
  const char* funcnames[funcnamesLen];
  for (int i = 0; i < funcnamesLen; i++) {
    funcnames[i] = Safe_String_val(Field(_funcnames, i));
  }
  BinaryenExpressionRef offset = BinaryenExpressionRef_val(_offset);
  BinaryenAddTable(module, name, initial, maximum, funcnames, funcnamesLen, offset);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_binaryen_add_table__bytecode(value * argv) {
  return caml_binaryen_add_table(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}
