#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_type_none(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeNone();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_int32(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeInt32();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_int64(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeInt64();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_float32(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeFloat32();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_float64(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeFloat64();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeVec128();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_funcref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeFuncref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_anyref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeAnyref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_eqref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeEqref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_i31ref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeI31ref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_dataref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeDataref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_arrayref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeArrayref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_stringref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeStringref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_stringview_wtf8(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeStringviewWTF8();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_stringview_wtf16(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeStringviewWTF16();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_stringview_iter(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeStringviewIter();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_nullref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeNullref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_null_externref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeNullExternref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_null_funcref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeNullFuncref();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_unreachable(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeUnreachable();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_auto(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeAuto();
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_type_create(value tys) {
  CAMLparam1(tys);
  int len = array_length(tys);
  BinaryenType valueTypes[len];
  for (int i = 0; i < len; i++) {
    valueTypes[i] = BinaryenType_val(Field(tys, i));
  }
  BinaryenType newType = BinaryenTypeCreate(valueTypes, len);
  CAMLreturn(alloc_BinaryenType(newType));
}

CAMLprim value
caml_binaryen_type_expand(value _ty) {
  CAMLparam1(_ty);
  BinaryenType ty = BinaryenType_val(_ty);
  int arity = BinaryenTypeArity(ty);
  BinaryenType* buf = malloc(sizeof(BinaryenType) * arity);
  BinaryenTypeExpand(ty, buf);

  value typeArray = caml_alloc(arity, 0);
  for (int i = 0; i < arity; i++) {
    Field(typeArray, i) = alloc_BinaryenType(buf[i]);
  }

  free(buf);

  CAMLreturn(typeArray);
}

CAMLprim value
caml_binaryen_type_is_nullable(value _ty) {
  CAMLparam1(_ty);
  BinaryenType ty = BinaryenType_val(_ty);
  CAMLreturn(Val_bool(BinaryenTypeIsNullable(ty)));
}

CAMLprim value
caml_binaryen_type_from_heap_type(value _ty, value _nullable) {
  CAMLparam2(_ty, _nullable);
  BinaryenHeapType heapTy = BinaryenHeapType_val(_ty);
  bool nullable = Bool_val(_nullable);
  BinaryenType ty = BinaryenTypeFromHeapType(heapTy, nullable);
  CAMLreturn(alloc_BinaryenType(ty));
}
