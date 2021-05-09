#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


/* Allocating an OCaml custom block to hold the given BinaryenType */
static value alloc_BinaryenType(BinaryenType typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenType), 0, 1);
  BinaryenType_val(v) = typ;
  return v;
}


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
caml_binaryen_type_externref(value unit) {
  CAMLparam1(unit);
  BinaryenType ty = BinaryenTypeExternref();
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
