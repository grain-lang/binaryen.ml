#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

extern "C" {
  /* Allocating an OCaml custom block to hold the given BinaryenLiteral */
  static value alloc_BinaryenLiteral(struct BinaryenLiteral op)
  {
    value v = caml_alloc_custom(&binaryen_ops, sizeof(struct BinaryenLiteral), 0, 1);
    BinaryenLiteral_val(v) = op;
    return v;
  }

  CAMLprim value
  caml_binaryen_literal_int32(value _i32) {
    CAMLparam1(_i32);
    int32_t i32 = Int32_val(_i32);
    struct BinaryenLiteral lit = BinaryenLiteralInt32(i32);
    CAMLreturn(alloc_BinaryenLiteral(lit));
  }

  CAMLprim value
  caml_binaryen_literal_int64(value _i64) {
    CAMLparam1(_i64);
    int64_t i64 = Int64_val(_i64);
    struct BinaryenLiteral lit = BinaryenLiteralInt64(i64);
    CAMLreturn(alloc_BinaryenLiteral(lit));
  }

  CAMLprim value
  caml_binaryen_literal_float64(value _f64) {
    CAMLparam1(_f64);
    double f64 = Double_val(_f64);
    struct BinaryenLiteral lit = BinaryenLiteralFloat64(f64);
    CAMLreturn(alloc_BinaryenLiteral(lit));
  }

  CAMLprim value
  caml_binaryen_literal_float32_bits(value _i32) {
    CAMLparam1(_i32);
    int32_t i32 = Int32_val(_i32);
    struct BinaryenLiteral lit = BinaryenLiteralFloat32Bits(i32);
    CAMLreturn(alloc_BinaryenLiteral(lit));
  }

  CAMLprim value
  caml_binaryen_literal_float64_bits(value _i64) {
    CAMLparam1(_i64);
    int64_t i64 = Int64_val(_i64);
    struct BinaryenLiteral lit = BinaryenLiteralFloat64Bits(i64);
    CAMLreturn(alloc_BinaryenLiteral(lit));
  }
}
