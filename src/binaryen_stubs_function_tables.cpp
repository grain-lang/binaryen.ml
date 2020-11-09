#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

extern "C" {
  CAMLprim value
  caml_binaryen_set_function_table(value _module, value _initial, value _maximum, value _funcnames, value _offset) {
    CAMLparam5(_module, _initial, _maximum, _funcnames, _offset);
    BinaryenModuleRef module = BinaryenModuleRef_val(_module);
    BinaryenIndex initial = Int_val(_initial);
    BinaryenIndex maximum = Int_val(_maximum);
    _funcnames = array_of_list(_funcnames);
    int funcnamesLen = array_length(_funcnames);
    const char* funcnames[funcnamesLen];
    for (int i = 0; i < funcnamesLen; i++) {
      funcnames[i] = Safe_String_val(Field(_funcnames, i));
    }
    BinaryenExpressionRef offset = BinaryenExpressionRef_val(_offset);
    BinaryenSetFunctionTable(module, initial, maximum, funcnames, funcnamesLen, offset);
    CAMLreturn(Val_unit);
  }
}
