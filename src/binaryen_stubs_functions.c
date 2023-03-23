#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_add_function(value _module, value _name, value _params, value _results, value _locals, value _body) {
  CAMLparam5(_module, _name, _params, _results, _locals);
  CAMLxparam1(_body);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenType params = BinaryenType_val(_params);
  BinaryenType results = BinaryenType_val(_results);
  int len = array_length(_locals);
  BinaryenType locals[len];
  for (int i = 0; i < len; i++) {
    locals[i] = BinaryenType_val(Field(_locals, i));
  }
  BinaryenExpressionRef body = BinaryenExpressionRef_val(_body);
  BinaryenFunctionRef fun = BinaryenAddFunction(module, name, params, results, locals, len, body);
  CAMLreturn(alloc_BinaryenFunctionRef(fun));
}
CAMLprim value
caml_binaryen_add_function__bytecode(value * argv) {
  return caml_binaryen_add_function(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_binaryen_get_function(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenFunctionRef fun = BinaryenGetFunction(module, name);
  CAMLreturn(alloc_BinaryenFunctionRef(fun));
}

CAMLprim value
caml_binaryen_remove_function(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenRemoveFunction(module, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_get_num_functions(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenGetNumFunctions(module)));
}

CAMLprim value
caml_binaryen_get_function_by_index(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex index = Int_val(_index);
  BinaryenFunctionRef fun = BinaryenGetFunctionByIndex(module, index);
  CAMLreturn(alloc_BinaryenFunctionRef(fun));
}

CAMLprim value
caml_binaryen_set_start(value _module, value _fun) {
  CAMLparam2(_module, _fun);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  BinaryenSetStart(module, fun);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_function_set_debug_location(value _fun, value _exp, value _file, value _line, value _column) {
  CAMLparam5(_fun, _exp, _file, _line, _column);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex file = Int_val(_file);
  BinaryenIndex line = Int_val(_line);
  BinaryenIndex column = Int_val(_column);
  BinaryenFunctionSetDebugLocation(fun, exp, file, line, column);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_function_get_name(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(caml_copy_string(BinaryenFunctionGetName(fun)));
}

CAMLprim value
caml_binaryen_function_get_params(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(alloc_BinaryenType(BinaryenFunctionGetParams(fun)));
}

CAMLprim value
caml_binaryen_function_get_results(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(alloc_BinaryenType(BinaryenFunctionGetResults(fun)));
}

CAMLprim value
caml_binaryen_function_get_num_vars(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(Val_int(BinaryenFunctionGetNumVars(fun)));
}

CAMLprim value
caml_binaryen_function_get_var(value _fun, value _index) {
  CAMLparam2(_fun, _index);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenType(BinaryenFunctionGetVar(fun, index)));
}

CAMLprim value
caml_binaryen_function_get_body(value _fun) {
  CAMLparam1(_fun);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenFunctionGetBody(fun)));
}

CAMLprim value
caml_binaryen_function_set_body(value _fun, value _body) {
  CAMLparam2(_fun, _body);
  BinaryenFunctionRef fun = BinaryenFunctionRef_val(_fun);
  BinaryenExpressionRef body = BinaryenExpressionRef_val(_body);
  BinaryenFunctionSetBody(fun, body);
  CAMLreturn(Val_unit);
}
