#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_heap_type_ext(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeExt();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_func(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeFunc();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_any(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeAny();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_eq(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeEq();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_i31(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeI31();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_struct(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeStruct();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_array(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeArray();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_string(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeString();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_stringview_wtf8(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeStringviewWTF8();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_stringview_wtf16(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeStringviewWTF16();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_stringview_iter(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeStringviewIter();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_none(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeNone();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_noext(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeNoext();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_nofunc(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeNofunc();
  CAMLreturn(alloc_BinaryenHeapType(ty));
}

CAMLprim value
caml_binaryen_heap_type_is_basic(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  bool result = BinaryenHeapTypeIsBasic(ty);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_heap_type_is_signature(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  bool result = BinaryenHeapTypeIsSignature(ty);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_heap_type_is_struct(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  bool result = BinaryenHeapTypeIsStruct(ty);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_heap_type_is_array(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  bool result = BinaryenHeapTypeIsArray(ty);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_heap_type_is_bottom(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  bool result = BinaryenHeapTypeIsBottom(ty);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_heap_type_get_bottom(value _ty) {
  CAMLparam1(_ty);
  BinaryenHeapType ty = BinaryenHeapType_val(_ty);
  BinaryenHeapType heapTy = BinaryenHeapTypeGetBottom(ty);
  CAMLreturn(alloc_BinaryenHeapType(heapTy));
}

CAMLprim value
caml_binaryen_heap_type_is_sub_type(value _left, value _right) {
  CAMLparam2(_left, _right);
  BinaryenHeapType left = BinaryenHeapType_val(_left);
  BinaryenHeapType right = BinaryenHeapType_val(_right);
  bool result = BinaryenHeapTypeIsSubType(left, right);
  CAMLreturn(Val_bool(result));
}

CAMLprim value
caml_binaryen_type_get_heap_type(value _ty) {
  CAMLparam1(_ty);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenHeapType heapTy = BinaryenTypeGetHeapType(ty);
  CAMLreturn(alloc_BinaryenHeapType(heapTy));
}
