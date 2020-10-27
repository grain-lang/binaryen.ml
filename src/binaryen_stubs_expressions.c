#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <binaryen-c.h>

#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenExpressionRef */
static value alloc_BinaryenExpressionRef(BinaryenExpressionRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExpressionRef), 0, 1);
  BinaryenExpressionRef_val(v) = exp;
  return v;
}

CAMLprim value
caml_binaryen_null_expression(value unit) {
  CAMLparam1(unit);
  CAMLreturn(alloc_BinaryenExpressionRef(NULL));
}

CAMLprim value
caml_binaryen_block(value _module, value _name, value _children) {
  CAMLparam3(_module, _name, _children);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  _children = array_of_list(_children);
  int childLen = array_length(_children);
  BinaryenExpressionRef children[childLen];
  for (int i = 0; i < childLen; i++) {
    children[i] = BinaryenExpressionRef_val(Field(_children, i));
  }
  BinaryenExpressionRef block = BinaryenBlock(module, name, children, childLen, BinaryenTypeAuto());
  CAMLreturn(alloc_BinaryenExpressionRef(block));
}

CAMLprim value
caml_binaryen_if(value _module, value _cond, value _tru, value _fals) {
  CAMLparam4(_module, _cond, _tru, _fals);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef cond = BinaryenExpressionRef_val(_cond);
  BinaryenExpressionRef tru = BinaryenExpressionRef_val(_tru);
  BinaryenExpressionRef fals = BinaryenExpressionRef_val(_fals);
  BinaryenExpressionRef exp = BinaryenIf(module, cond, tru, fals);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_loop(value _module, value _name, value _body) {
  CAMLparam3(_module, _name, _body);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef body = BinaryenExpressionRef_val(_body);
  BinaryenExpressionRef exp = BinaryenLoop(module, name, body);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_break(value _module, value _name, value _cond, value _res) {
  CAMLparam4(_module, _name, _cond, _res);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef cond = BinaryenExpressionRef_val(_cond);
  BinaryenExpressionRef res = BinaryenExpressionRef_val(_res);
  BinaryenExpressionRef exp = BinaryenBreak(module, name, cond, res);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_switch(value _module, value _names, value _defaultName, value _cond, value _val) {
  CAMLparam5(_module, _names, _defaultName, _cond, _val);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  _names = array_of_list(_names);
  int namesLen = array_length(_names);
  const char* names[namesLen];
  for (int i = 0; i < namesLen; i++) {
    names[i] = Safe_String_val(Field(_names, i));
  }
  char* defaultName = Safe_String_val(_defaultName);
  BinaryenExpressionRef cond = BinaryenExpressionRef_val(_cond);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenExpressionRef exp = BinaryenSwitch(module, names, namesLen, defaultName, cond, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_call(value _module, value _name, value _params, value _retty) {
  CAMLparam4(_module, _name, _params, _retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenCall(module, name, params, paramsLen, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_call_indirect(value _module, value _target, value _params, value _paramsty, value _retty) {
  CAMLparam5(_module, _target, _params, _paramsty, _retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef target = BinaryenExpressionRef_val(_target);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenCallIndirect(module, target, params, paramsLen, paramsty, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_return_call(value _module, value _name, value _params, value _retty) {
  CAMLparam4(_module, _name, _params, _retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenReturnCall(module, name, params, paramsLen, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_return_call_indirect(value _module, value _target, value _params, value _paramsty, value _retty) {
  CAMLparam5(_module, _target, _params, _paramsty, _retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef target = BinaryenExpressionRef_val(_target);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenReturnCallIndirect(module, target, params, paramsLen, paramsty, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_local_get(value _module, value _slot, value _ty) {
  CAMLparam3(_module, _slot, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int slot = Int_val(_slot);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenLocalGet(module, slot, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_local_set(value _module, value _slot, value _val) {
  CAMLparam3(_module, _slot, _val);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int slot = Int_val(_slot);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenExpressionRef exp = BinaryenLocalSet(module, slot, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_local_tee(value _module, value _slot, value _val, value _ty) {
  CAMLparam4(_module, _slot, _val, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int slot = Int_val(_slot);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenLocalTee(module, slot, val, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_global_get(value _module, value _name, value _ty) {
  CAMLparam3(_module, _name, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenGlobalGet(module, name, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_global_set(value _module, value _name, value _val) {
  CAMLparam3(_module, _name, _val);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenExpressionRef exp = BinaryenGlobalSet(module, name, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_load(value _module, value _bytes, value _offset, value _align, value _ty, value _ptr) {
  CAMLparam5(_module, _bytes, _offset, _align, _ty);
  CAMLxparam1(_ptr);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int bytes = Int_val(_bytes);
  int offset = Int_val(_offset);
  int align = Int_val(_align);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef ptr = BinaryenExpressionRef_val(_ptr);
  BinaryenExpressionRef exp = BinaryenLoad(module, bytes, 0, offset, align, ty, ptr);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
CAMLprim value
caml_binaryen_load__bytecode(value * argv) {
  return caml_binaryen_load(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_binaryen_store(value _module, value _bytes, value _offset, value _align, value _ptr, value _val, value _ty) {
  CAMLparam5(_module, _bytes, _offset, _align, _ptr);
  CAMLxparam2(_val, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int bytes = Int_val(_bytes);
  int offset = Int_val(_offset);
  int align = Int_val(_align);
  BinaryenExpressionRef ptr = BinaryenExpressionRef_val(_ptr);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenStore(module, bytes, offset, align, ptr, val, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
CAMLprim value
caml_binaryen_store__bytecode(value * argv) {
  return caml_binaryen_store(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

CAMLprim value
caml_binaryen_const(value _module, value _lit) {
  CAMLparam2(_module, _lit);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  struct BinaryenLiteral lit = BinaryenLiteral_val(_lit);
  BinaryenExpressionRef exp = BinaryenConst(module, lit);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_unary(value _module, value _op, value _p) {
  CAMLparam3(_module, _op, _p);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenOp op = BinaryenOp_val(_op);
  BinaryenExpressionRef p = BinaryenExpressionRef_val(_p);
  BinaryenExpressionRef exp = BinaryenUnary(module, op, p);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_binary(value _module, value _op, value _p1, value _p2) {
  CAMLparam4(_module, _op, _p1, _p2);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenOp op = BinaryenOp_val(_op);
  BinaryenExpressionRef p1 = BinaryenExpressionRef_val(_p1);
  BinaryenExpressionRef p2 = BinaryenExpressionRef_val(_p2);
  BinaryenExpressionRef exp = BinaryenBinary(module, op, p1, p2);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_select(value _module, value _cond, value _tru, value _fals, value _ty) {
  CAMLparam5(_module, _cond, _tru, _fals, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef cond = BinaryenExpressionRef_val(_cond);
  BinaryenExpressionRef tru = BinaryenExpressionRef_val(_tru);
  BinaryenExpressionRef fals = BinaryenExpressionRef_val(_fals);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenSelect(module, cond, tru, fals, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_drop(value _module, value _p1) {
  CAMLparam2(_module, _p1);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef p1 = BinaryenExpressionRef_val(_p1);
  BinaryenExpressionRef exp = BinaryenDrop(module, p1);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_return(value _module, value _p1) {
  CAMLparam2(_module, _p1);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef p1 = BinaryenExpressionRef_val(_p1);
  BinaryenExpressionRef exp = BinaryenReturn(module, p1);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_memory_size(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef exp = BinaryenMemorySize(module);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_memory_grow(value _module, value _p1) {
  CAMLparam2(_module, _p1);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef p1 = BinaryenExpressionRef_val(_p1);
  BinaryenExpressionRef exp = BinaryenMemoryGrow(module, p1);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_nop(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef exp = BinaryenNop(module);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_unreachable(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef exp = BinaryenUnreachable(module);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_memory_copy(value _module, value _dest, value _source, value _size) {
  CAMLparam4(_module, _dest, _source, _size);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef dest = BinaryenExpressionRef_val(_dest);
  BinaryenExpressionRef source = BinaryenExpressionRef_val(_source);
  BinaryenExpressionRef size = BinaryenExpressionRef_val(_size);
  BinaryenExpressionRef exp = BinaryenMemoryCopy(module, dest, source, size);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_memory_fill(value _module, value _dest, value _val, value _size) {
  CAMLparam4(_module, _dest, _val, _size);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef dest = BinaryenExpressionRef_val(_dest);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_val);
  BinaryenExpressionRef size = BinaryenExpressionRef_val(_size);
  BinaryenExpressionRef exp = BinaryenMemoryFill(module, dest, val, size);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_tuple_make(value _module, value _operands) {
  CAMLparam2(_module, _operands);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  _operands = array_of_list(_operands);
  int operandsLen = array_length(_operands);
  BinaryenExpressionRef operands[operandsLen];
  for (int i = 0; i < operandsLen; i++) {
    operands[i] = BinaryenExpressionRef_val(Field(_operands, i));
  }
  BinaryenExpressionRef exp = BinaryenTupleMake(module, operands, operandsLen);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_tuple_extract(value _module, value _tuple, value _index) {
  CAMLparam3(_module, _tuple, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef tuple = BinaryenExpressionRef_val(_tuple);
  int index = Int_val(_index);
  BinaryenExpressionRef exp = BinaryenTupleExtract(module, tuple, index);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_pop(value _module, value _ty) {
  CAMLparam2(_module, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenPop(module, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_expression_print(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionPrint(exp);
  CAMLreturn(Val_unit);
}
