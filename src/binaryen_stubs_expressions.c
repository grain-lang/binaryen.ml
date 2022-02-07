#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


/* Allocating an OCaml custom block to hold the given BinaryenExpressionRef */
static value alloc_BinaryenExpressionRef(BinaryenExpressionRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExpressionRef), 0, 1);
  BinaryenExpressionRef_val(v) = exp;
  return v;
}

CAMLprim value
caml_binaryen_expression_get_id(value _expr) {
  CAMLparam1(_expr);
  BinaryenExpressionRef expr = BinaryenExpressionRef_val(_expr);
  CAMLreturn(Val_int(BinaryenExpressionGetId(expr)));
}

CAMLprim value
caml_binaryen_null_expression(value unit) {
  CAMLparam1(unit);
  CAMLreturn(alloc_BinaryenExpressionRef(NULL));
}

CAMLprim value
caml_binaryen_block(value _module, value _name, value _children, value _ty) {
  CAMLparam4(_module, _name, _children, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  _children = array_of_list(_children);
  int childLen = array_length(_children);
  BinaryenExpressionRef children[childLen];
  for (int i = 0; i < childLen; i++) {
    children[i] = BinaryenExpressionRef_val(Field(_children, i));
  }
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef block = BinaryenBlock(module, name, children, childLen, ty);
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
caml_binaryen_call_indirect(value _module, value _table, value _target, value _params, value _paramsty, value _retty) {
  CAMLparam5(_module, _table, _target, _params, _paramsty);
  CAMLxparam1(_retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* table = Safe_String_val(_table);
  BinaryenExpressionRef target = BinaryenExpressionRef_val(_target);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenCallIndirect(module, table, target, params, paramsLen, paramsty, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
CAMLprim value
caml_binaryen_call_indirect__bytecode(value * argv) {
  return caml_binaryen_call_indirect(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
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
caml_binaryen_return_call_indirect(value _module, value _table, value _target, value _params, value _paramsty, value _retty) {
  CAMLparam5(_module, _table, _target, _params, _paramsty);
  CAMLxparam1(_retty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* table = Safe_String_val(_table);
  BinaryenExpressionRef target = BinaryenExpressionRef_val(_target);
  _params = array_of_list(_params);
  int paramsLen = array_length(_params);
  BinaryenExpressionRef params[paramsLen];
  for (int i = 0; i < paramsLen; i++) {
    params[i] = BinaryenExpressionRef_val(Field(_params, i));
  }
  BinaryenType paramsty = BinaryenType_val(_paramsty);
  BinaryenType retty = BinaryenType_val(_retty);
  BinaryenExpressionRef exp = BinaryenReturnCallIndirect(module, table, target, params, paramsLen, paramsty, retty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
CAMLprim value
caml_binaryen_return_call_indirect__bytecode(value * argv) {
  return caml_binaryen_return_call_indirect(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
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
caml_binaryen_load(value _module, value _bytes, value _signed_, value _offset, value _align, value _ty, value _ptr) {
  CAMLparam5(_module, _bytes, _signed_, _offset, _align);
  CAMLxparam2(_ty, _ptr);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int bytes = Int_val(_bytes);
  int8_t signed_ = Bool_val(_signed_);
  int offset = Int_val(_offset);
  int align = Int_val(_align);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef ptr = BinaryenExpressionRef_val(_ptr);
  BinaryenExpressionRef exp = BinaryenLoad(module, bytes, signed_, offset, align, ty, ptr);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}
CAMLprim value
caml_binaryen_load__bytecode(value * argv) {
  return caml_binaryen_load(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
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
caml_binaryen_expression_id_invalid(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenInvalidId()));
}

CAMLprim value
caml_binaryen_expression_id_nop(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenNopId()));
}
CAMLprim value
caml_binaryen_expression_id_block(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenBlockId()));
}
CAMLprim value
caml_binaryen_expression_id_if(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenIfId()));
}
CAMLprim value
caml_binaryen_expression_id_loop(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenLoopId()));
}
CAMLprim value
caml_binaryen_expression_id_break(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenBreakId()));
}
CAMLprim value
caml_binaryen_expression_id_switch(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSwitchId()));
}
CAMLprim value
caml_binaryen_expression_id_call(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenCallId()));
}
CAMLprim value
caml_binaryen_expression_id_call_indirect(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenCallIndirectId()));
}
CAMLprim value
caml_binaryen_expression_id_local_get(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenLocalGetId()));
}
CAMLprim value
caml_binaryen_expression_id_local_set(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenLocalSetId()));
}
CAMLprim value
caml_binaryen_expression_id_global_get(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenGlobalGetId()));
}
CAMLprim value
caml_binaryen_expression_id_global_set(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenGlobalSetId()));
}
CAMLprim value
caml_binaryen_expression_id_load(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenLoadId()));
}
CAMLprim value
caml_binaryen_expression_id_store(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenStoreId()));
}
CAMLprim value
caml_binaryen_expression_id_atomic_rmw(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenAtomicRMWId()));
}
CAMLprim value
caml_binaryen_expression_id_atomic_cmpxchg(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenAtomicCmpxchgId()));
}
CAMLprim value
caml_binaryen_expression_id_atomic_wait(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenAtomicWaitId()));
}
CAMLprim value
caml_binaryen_expression_id_atomic_notify(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenAtomicNotifyId()));
}
CAMLprim value
caml_binaryen_expression_id_atomic_fence(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenAtomicFenceId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_extract(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDExtractId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_replace(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDReplaceId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_shuffle(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDShuffleId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_ternary(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDTernaryId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_shift(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDShiftId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_load(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDLoadId()));
}
CAMLprim value
caml_binaryen_expression_id_simd_load_store_lane(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSIMDLoadStoreLaneId()));
}
CAMLprim value
caml_binaryen_expression_id_memory_init(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenMemoryInitId()));
}
CAMLprim value
caml_binaryen_expression_id_data_drop(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenDataDropId()));
}
CAMLprim value
caml_binaryen_expression_id_memory_copy(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenMemoryCopyId()));
}
CAMLprim value
caml_binaryen_expression_id_memory_fill(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenMemoryFillId()));
}
CAMLprim value
caml_binaryen_expression_id_const(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenConstId()));
}
CAMLprim value
caml_binaryen_expression_id_unary(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenUnaryId()));
}
CAMLprim value
caml_binaryen_expression_id_binary(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenBinaryId()));
}
CAMLprim value
caml_binaryen_expression_id_select(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenSelectId()));
}
CAMLprim value
caml_binaryen_expression_id_drop(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenDropId()));
}
CAMLprim value
caml_binaryen_expression_id_return(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenReturnId()));
}
CAMLprim value
caml_binaryen_expression_id_memory_size(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenMemorySizeId()));
}
CAMLprim value
caml_binaryen_expression_id_memory_grow(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenMemoryGrowId()));
}
CAMLprim value
caml_binaryen_expression_id_unreachable(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenUnreachableId()));
}
CAMLprim value
caml_binaryen_expression_id_pop(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenPopId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_null(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefNullId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_is(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefIsId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_as(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefAsId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_func(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefFuncId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_eq(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefEqId()));
}
CAMLprim value
caml_binaryen_expression_id_try(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTryId()));
}
CAMLprim value
caml_binaryen_expression_id_throw(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenThrowId()));
}
CAMLprim value
caml_binaryen_expression_id_rethrow(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRethrowId()));
}
CAMLprim value
caml_binaryen_expression_id_tuple_make(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTupleMakeId()));
}
CAMLprim value
caml_binaryen_expression_id_tuple_extract(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTupleExtractId()));
}
CAMLprim value
caml_binaryen_expression_id_i31_new(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenI31NewId()));
}
CAMLprim value
caml_binaryen_expression_id_i31_get(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenI31GetId()));
}
CAMLprim value
caml_binaryen_expression_id_call_ref(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenCallRefId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_test(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefTestId()));
}
CAMLprim value
caml_binaryen_expression_id_ref_cast(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRefCastId()));
}
CAMLprim value
caml_binaryen_expression_id_br_on(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenBrOnId()));
}
CAMLprim value
caml_binaryen_expression_id_rtt_canon(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRttCanonId()));
}
CAMLprim value
caml_binaryen_expression_id_rtt_sub(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenRttSubId()));
}
CAMLprim value
caml_binaryen_expression_id_struct_new(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenStructNewId()));
}
CAMLprim value
caml_binaryen_expression_id_struct_get(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenStructGetId()));
}
CAMLprim value
caml_binaryen_expression_id_struct_set(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenStructSetId()));
}
CAMLprim value
caml_binaryen_expression_id_array_new(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenArrayNewId()));
}
CAMLprim value
caml_binaryen_expression_id_array_get(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenArrayGetId()));
}
CAMLprim value
caml_binaryen_expression_id_array_set(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenArraySetId()));
}
CAMLprim value
caml_binaryen_expression_id_array_len(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenArrayLenId()));
}

// Expression operations

CAMLprim value
caml_binaryen_expression_print(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionPrint(exp);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_expression_finalize(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionFinalize(exp);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_expression_copy(value _exp, value _module) {
  CAMLparam1(_exp);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef exp = BinaryenExpressionCopy(BinaryenExpressionRef_val(_exp), module);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

// Block operations

CAMLprim value
caml_binaryen_block_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenBlockGetName(exp);
  if (name == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(caml_copy_string(name)));
  }
}

CAMLprim value
caml_binaryen_block_set_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenBlockSetName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_block_get_num_children(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_int(BinaryenBlockGetNumChildren(exp)));
}

CAMLprim value
caml_binaryen_block_get_child_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenBlockGetChildAt(exp, index)));
}

CAMLprim value
caml_binaryen_block_set_child_at(value _exp, value _index, value _child) {
  CAMLparam3(_exp, _index, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenBlockSetChildAt(exp, index, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_block_append_child(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  CAMLreturn(Val_int(BinaryenBlockAppendChild(exp, child)));
}

CAMLprim value
caml_binaryen_block_insert_child_at(value _exp, value _index, value _child) {
  CAMLparam3(_exp, _index, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenBlockInsertChildAt(exp, index, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_block_remove_child_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenBlockRemoveChildAt(exp, index)));
}

// If operations

CAMLprim value
caml_binaryen_if_get_condition(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenIfGetCondition(exp)));
}

CAMLprim value
caml_binaryen_if_set_condition(value _exp, value _cond) {
  CAMLparam2(_exp, _cond);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef cond = BinaryenExpressionRef_val(_cond);
  BinaryenIfSetCondition(exp, cond);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_if_get_if_true(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenIfGetIfTrue(exp)));
}

CAMLprim value
caml_binaryen_if_set_if_true(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenIfSetIfTrue(exp, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_if_get_if_false(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef ifFalse = BinaryenIfGetIfFalse(exp);
  if (ifFalse == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(alloc_BinaryenExpressionRef(ifFalse)));
  }
}

CAMLprim value
caml_binaryen_if_set_if_false(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenIfSetIfFalse(exp, child);
  CAMLreturn(Val_unit);
}

// Loop operations

CAMLprim value
caml_binaryen_loop_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenLoopGetName(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_loop_set_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenLoopSetName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_loop_get_body(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenLoopGetBody(exp)));
}

CAMLprim value
caml_binaryen_loop_set_body(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenLoopSetBody(exp, child);
  CAMLreturn(Val_unit);
}

// Break operations

CAMLprim value
caml_binaryen_break_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenBreakGetName(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_break_set_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenBreakSetName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_break_get_condition(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef cond = BinaryenBreakGetCondition(exp);
  if (cond == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(alloc_BinaryenExpressionRef(cond)));
  }
}

CAMLprim value
caml_binaryen_break_set_condition(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenBreakSetCondition(exp, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_break_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenBreakGetValue(exp);
  if (val == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(alloc_BinaryenExpressionRef(val)));
  }
}

CAMLprim value
caml_binaryen_break_set_value(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenBreakSetValue(exp, child);
  CAMLreturn(Val_unit);
}

// Switch operations

CAMLprim value
caml_binaryen_switch_get_num_names(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_int(BinaryenSwitchGetNumNames(exp)));
}

CAMLprim value
caml_binaryen_switch_get_name_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  const char* name = BinaryenSwitchGetNameAt(exp, index);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_switch_set_name_at(value _exp, value _index, value _name) {
  CAMLparam3(_exp, _index, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  char* name = Safe_String_val(_name);
  BinaryenSwitchSetNameAt(exp, index, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_switch_append_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  CAMLreturn(Val_int(BinaryenSwitchAppendName(exp, name)));
}

CAMLprim value
caml_binaryen_switch_insert_name_at(value _exp, value _index, value _name) {
  CAMLparam3(_exp, _index, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  char* name = Safe_String_val(_name);
  BinaryenSwitchInsertNameAt(exp, index, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_switch_remove_name_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  const char* name = BinaryenSwitchRemoveNameAt(exp, index);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_switch_get_default_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenSwitchGetDefaultName(exp);
  if (name == NULL) {
    CAMLreturn(Val_none);
  }
  CAMLreturn(caml_alloc_some(caml_copy_string(name)));
}

CAMLprim value
caml_binaryen_switch_set_default_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenSwitchSetDefaultName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_switch_get_condition(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenSwitchGetCondition(exp)));
}

CAMLprim value
caml_binaryen_switch_set_condition(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenSwitchSetCondition(exp, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_switch_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenSwitchGetValue(exp);
  if (val == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(alloc_BinaryenExpressionRef(val)));
  }
}

CAMLprim value
caml_binaryen_switch_set_value(value _exp, value _child) {
  CAMLparam2(_exp, _child);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef child = BinaryenExpressionRef_val(_child);
  BinaryenSwitchSetValue(exp, child);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_get_target(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenCallGetTarget(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_call_set_target(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenCallSetTarget(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_get_num_operands(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_int(BinaryenCallGetNumOperands(exp)));
}

CAMLprim value
caml_binaryen_call_get_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenCallGetOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_call_set_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenCallSetOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_append_operand(value _exp, value _operand) {
  CAMLparam2(_exp, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  CAMLreturn(Val_int(BinaryenCallAppendOperand(exp, operand)));
}

CAMLprim value
caml_binaryen_call_insert_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenCallInsertOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_remove_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenCallRemoveOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_call_is_return(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_bool(BinaryenCallIsReturn(exp)));
}

CAMLprim value
caml_binaryen_call_set_return(value _exp, value _isReturn) {
  CAMLparam2(_exp, _isReturn);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  int isReturn = Bool_val(_isReturn);
  BinaryenCallSetReturn(exp, isReturn);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_indirect_get_target(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenCallIndirectGetTarget(exp)));
}

CAMLprim value
caml_binaryen_call_indirect_set_target(value _exp, value _target) {
  CAMLparam2(_exp, _target);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef target = BinaryenExpressionRef_val(_target);
  BinaryenCallIndirectSetTarget(exp, target);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_indirect_get_table(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenCallIndirectGetTable(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_call_indirect_set_table(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenCallIndirectSetTable(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_indirect_get_num_operands(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_int(BinaryenCallIndirectGetNumOperands(exp)));
}

CAMLprim value
caml_binaryen_call_indirect_get_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenCallIndirectGetOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_call_indirect_set_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenCallIndirectSetOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_indirect_append_operand(value _exp, value _operand) {
  CAMLparam2(_exp, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  CAMLreturn(Val_int(BinaryenCallIndirectAppendOperand(exp, operand)));
}

CAMLprim value
caml_binaryen_call_indirect_insert_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenCallIndirectInsertOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_call_indirect_remove_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenCallIndirectRemoveOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_call_indirect_is_return(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_bool(BinaryenCallIndirectIsReturn(exp)));
}

CAMLprim value
caml_binaryen_call_indirect_set_return(value _exp, value _isReturn) {
  CAMLparam2(_exp, _isReturn);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  int isReturn = Bool_val(_isReturn);
  BinaryenCallIndirectSetReturn(exp, isReturn);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_local_set_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenLocalSetGetValue(exp)));
}

CAMLprim value
caml_binaryen_local_set_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenLocalSetSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_global_get_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenGlobalGetGetName(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_global_get_set_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenGlobalGetSetName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_global_set_get_name(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenGlobalSetGetName(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_global_set_set_name(value _exp, value _name) {
  CAMLparam2(_exp, _name);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* name = Safe_String_val(_name);
  BinaryenGlobalSetSetName(exp, name);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_global_set_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenGlobalSetGetValue(exp)));
}

CAMLprim value
caml_binaryen_global_set_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenGlobalSetSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_grow_get_delta(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryGrowGetDelta(exp)));
}

CAMLprim value
caml_binaryen_memory_grow_set_delta(value _exp, value _delta) {
  CAMLparam2(_exp, _delta);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef delta = BinaryenExpressionRef_val(_delta);
  BinaryenMemoryGrowSetDelta(exp, delta);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_load_get_ptr(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenLoadGetPtr(exp)));
}

CAMLprim value
caml_binaryen_load_set_ptr(value _exp, value _ptr) {
  CAMLparam2(_exp, _ptr);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef ptr = BinaryenExpressionRef_val(_ptr);
  BinaryenLoadSetPtr(exp, ptr);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_store_get_ptr(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenStoreGetPtr(exp)));
}

CAMLprim value
caml_binaryen_store_set_ptr(value _exp, value _ptr) {
  CAMLparam2(_exp, _ptr);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef ptr = BinaryenExpressionRef_val(_ptr);
  BinaryenStoreSetPtr(exp, ptr);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_store_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenStoreGetValue(exp)));
}

CAMLprim value
caml_binaryen_store_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenStoreSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_unary_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenUnaryGetValue(exp)));
}

CAMLprim value
caml_binaryen_unary_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenUnarySetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_binary_get_left(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenBinaryGetLeft(exp)));
}

CAMLprim value
caml_binaryen_binary_set_left(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenBinarySetLeft(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_binary_get_right(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenBinaryGetRight(exp)));
}

CAMLprim value
caml_binaryen_binary_set_right(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenBinarySetRight(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_select_get_if_true(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenSelectGetIfTrue(exp)));
}

CAMLprim value
caml_binaryen_select_set_if_true(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenSelectSetIfTrue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_select_get_if_false(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenSelectGetIfFalse(exp)));
}

CAMLprim value
caml_binaryen_select_set_if_false(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenSelectSetIfFalse(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_select_get_condition(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenSelectGetCondition(exp)));
}

CAMLprim value
caml_binaryen_select_set_condition(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenSelectSetCondition(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_drop_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenDropGetValue(exp)));
}

CAMLprim value
caml_binaryen_drop_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenDropSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_return_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenReturnGetValue(exp)));
}

CAMLprim value
caml_binaryen_return_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenReturnSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_copy_get_dest(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryCopyGetDest(exp)));
}

CAMLprim value
caml_binaryen_memory_copy_set_dest(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryCopySetDest(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_copy_get_source(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryCopyGetSource(exp)));
}

CAMLprim value
caml_binaryen_memory_copy_set_source(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryCopySetSource(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_copy_get_size(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryCopyGetSize(exp)));
}

CAMLprim value
caml_binaryen_memory_copy_set_size(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryCopySetSize(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_fill_get_dest(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryFillGetDest(exp)));
}

CAMLprim value
caml_binaryen_memory_fill_set_dest(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryFillSetDest(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_fill_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryFillGetValue(exp)));
}

CAMLprim value
caml_binaryen_memory_fill_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryFillSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_memory_fill_get_size(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenMemoryFillGetSize(exp)));
}

CAMLprim value
caml_binaryen_memory_fill_set_size(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenMemoryFillSetSize(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tuple_make_get_num_operands(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(Val_int(BinaryenTupleMakeGetNumOperands(exp)));
}

CAMLprim value
caml_binaryen_tuple_make_get_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenTupleMakeGetOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_tuple_make_set_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenTupleMakeSetOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tuple_make_append_operand(value _exp, value _operand) {
  CAMLparam2(_exp, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  CAMLreturn(Val_int(BinaryenTupleMakeAppendOperand(exp, operand)));
}

CAMLprim value
caml_binaryen_tuple_make_insert_operand_at(value _exp, value _index, value _operand) {
  CAMLparam3(_exp, _index, _operand);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  BinaryenExpressionRef operand = BinaryenExpressionRef_val(_operand);
  BinaryenTupleMakeInsertOperandAt(exp, index, operand);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tuple_make_remove_operand_at(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenTupleMakeRemoveOperandAt(exp, index)));
}

CAMLprim value
caml_binaryen_tuple_extract_get_tuple(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  CAMLreturn(alloc_BinaryenExpressionRef(BinaryenTupleExtractGetTuple(exp)));
}

CAMLprim value
caml_binaryen_tuple_extract_set_tuple(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenTupleExtractSetTuple(exp, val);
  CAMLreturn(Val_unit);
}

// Ref operations
CAMLprim value
caml_binaryen_ref_null(value _module, value _ty) {
  CAMLparam2(_module, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenRefNull(module, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_ref_is(value _module, value _op, value _value) {
  CAMLparam3(_module, _op, _value);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenOp op = BinaryenOp_val(_op);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenExpressionRef exp = BinaryenRefIs(module, op, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_ref_as(value _module, value _op, value _value) {
  CAMLparam3(_module, _op, _value);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenOp op = BinaryenOp_val(_op);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenExpressionRef exp = BinaryenRefAs(module, op, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_ref_func(value _module, value _name, value _ty) {
  CAMLparam3(_module, _name, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenRefFunc(module, name, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_ref_eq(value _module, value _left, value _right) {
  CAMLparam3(_module, _left, _right);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenExpressionRef left = BinaryenExpressionRef_val(_left);
  BinaryenExpressionRef right = BinaryenExpressionRef_val(_right);
  BinaryenExpressionRef exp = BinaryenRefEq(module, left, right);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

// Table operations
CAMLprim value
caml_binaryen_table_get(value _module, value _name, value _index, value _ty) {
  CAMLparam4(_module, _name, _index, _ty);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef index = BinaryenExpressionRef_val(_index);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenExpressionRef exp = BinaryenTableGet(module, name, index, ty);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_table_set(value _module, value _name, value _index, value _value) {
  CAMLparam4(_module, _name, _index, _value);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef index = BinaryenExpressionRef_val(_index);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenExpressionRef exp = BinaryenTableSet(module, name, index, val);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_table_size(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef exp = BinaryenTableSize(module, name);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

CAMLprim value
caml_binaryen_table_grow(value _module, value _name, value _value, value _delta) {
  CAMLparam4(_module, _name, _value, _delta);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenExpressionRef delta = BinaryenExpressionRef_val(_delta);
  BinaryenExpressionRef exp = BinaryenTableGrow(module, name, val, delta);
  CAMLreturn(alloc_BinaryenExpressionRef(exp));
}

// TableGet operations
CAMLprim value
caml_binaryen_tableget_get_table(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenTableGetGetTable(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_tableget_set_table(value _exp, value _table) {
  CAMLparam2(_exp, _table);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* table = Safe_String_val(_table);
  BinaryenTableGetSetTable(exp, table);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tableget_get_index(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef index = BinaryenTableGetGetIndex(exp);
  CAMLreturn(alloc_BinaryenExpressionRef(index));
}

CAMLprim value
caml_binaryen_tableget_set_index(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef index = BinaryenExpressionRef_val(_index);
  BinaryenTableGetSetIndex(exp, index);
  CAMLreturn(Val_unit);
}

// TableSet operations
CAMLprim value
caml_binaryen_tableset_get_table(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenTableSetGetTable(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_tableset_set_table(value _exp, value _table) {
  CAMLparam2(_exp, _table);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* table = Safe_String_val(_table);
  BinaryenTableSetSetTable(exp, table);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tableset_get_index(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef index = BinaryenTableSetGetIndex(exp);
  CAMLreturn(alloc_BinaryenExpressionRef(index));
}

CAMLprim value
caml_binaryen_tableset_set_index(value _exp, value _index) {
  CAMLparam2(_exp, _index);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef index = BinaryenExpressionRef_val(_index);
  BinaryenTableSetSetIndex(exp, index);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tableset_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenTableSetGetValue(exp);
  CAMLreturn(alloc_BinaryenExpressionRef(val));
}

CAMLprim value
caml_binaryen_tableset_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenTableSetSetValue(exp, val);
  CAMLreturn(Val_unit);
}

// TableSize operations
CAMLprim value
caml_binaryen_tablesize_get_table(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenTableSizeGetTable(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_tablesize_set_table(value _exp, value _table) {
  CAMLparam2(_exp, _table);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* table = Safe_String_val(_table);
  BinaryenTableSizeSetTable(exp, table);
  CAMLreturn(Val_unit);
}

// TableGrow operations
CAMLprim value
caml_binaryen_tablegrow_get_table(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  const char* name = BinaryenTableGrowGetTable(exp);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_tablegrow_set_table(value _exp, value _table) {
  CAMLparam2(_exp, _table);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  char* table = Safe_String_val(_table);
  BinaryenTableGrowSetTable(exp, table);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tablegrow_get_value(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenTableGrowGetValue(exp);
  CAMLreturn(alloc_BinaryenExpressionRef(val));
}

CAMLprim value
caml_binaryen_tablegrow_set_value(value _exp, value _value) {
  CAMLparam2(_exp, _value);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef val = BinaryenExpressionRef_val(_value);
  BinaryenTableGrowSetValue(exp, val);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_tablegrow_get_delta(value _exp) {
  CAMLparam1(_exp);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef delta = BinaryenTableGrowGetDelta(exp);
  CAMLreturn(alloc_BinaryenExpressionRef(delta));
}

CAMLprim value
caml_binaryen_tablegrow_set_delta(value _exp, value _delta) {
  CAMLparam2(_exp, _delta);
  BinaryenExpressionRef exp = BinaryenExpressionRef_val(_exp);
  BinaryenExpressionRef delta = BinaryenExpressionRef_val(_delta);
  BinaryenTableGrowSetDelta(exp, delta);
  CAMLreturn(Val_unit);
}
