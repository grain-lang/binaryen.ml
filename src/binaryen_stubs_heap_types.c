#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


/* Allocating an OCaml custom block to hold the given BinaryenHeapType */
static value alloc_BinaryenHeapType(BinaryenHeapType typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenHeapType), 0, 1);
  BinaryenHeapType_val(v) = typ;
  return v;
}


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
caml_binaryen_heap_type_data(value unit) {
  CAMLparam1(unit);
  BinaryenHeapType ty = BinaryenHeapTypeData();
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
caml_binaryen_type_get_heap_type(value _ty) {
  CAMLparam1(_ty);
  BinaryenType ty = BinaryenType_val(_ty);
  BinaryenHeapType heapTy = BinaryenTypeGetHeapType(ty);
  CAMLreturn(alloc_BinaryenHeapType(heapTy));
}
