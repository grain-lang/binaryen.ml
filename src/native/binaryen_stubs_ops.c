#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <binaryen-c.h>

#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenOp */
static value alloc_BinaryenOp(BinaryenOp op)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenOp), 0, 1);
  BinaryenOp_val(v) = op;
  return v;
}

CAMLprim value
caml_binaryen_binaryen_clz_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenClzInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ctz_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCtzInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_popcnt_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPopcntInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ceil_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCeilFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_floor_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenFloorFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_nearest_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNearestFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sqrt_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSqrtFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_z_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqZInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_clz_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenClzInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ctz_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCtzInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_popcnt_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPopcntInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ceil_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCeilFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_floor_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenFloorFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_nearest_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNearestFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sqrt_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSqrtFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_z_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqZInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_wrap_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWrapInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_s_float32_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSFloat32ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_s_float32_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSFloat32ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_u_float32_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncUFloat32ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_u_float32_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncUFloat32ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_s_float64_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSFloat64ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_s_float64_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSFloat64ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_u_float64_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncUFloat64ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_u_float64_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncUFloat64ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_reinterpret_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReinterpretFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_reinterpret_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReinterpretFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_int32_to_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSInt32ToFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_int32_to_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSInt32ToFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_int32_to_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUInt32ToFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_int32_to_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUInt32ToFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_int64_to_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSInt64ToFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_int64_to_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSInt64ToFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_int64_to_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUInt64ToFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_int64_to_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUInt64ToFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_promote_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPromoteFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_demote_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDemoteFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_reinterpret_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReinterpretInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_reinterpret_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReinterpretInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s8_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendS8Int32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s16_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendS16Int32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s8_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendS8Int64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s16_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendS16Int64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extend_s32_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtendS32Int64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rem_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRemSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rem_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRemUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_and_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAndInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_or_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenOrInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_xor_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenXorInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rot_l_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRotLInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rot_r_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRotRInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_s_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeSInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_u_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeUInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rem_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRemSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rem_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRemUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_and_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAndInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_or_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenOrInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_xor_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenXorInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rot_l_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRotLInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_rot_r_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenRotRInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_s_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeSInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_u_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeUInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_copy_sign_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCopySignFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_float32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeFloat32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_copy_sign_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCopySignFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_float64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeFloat64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_memory_size(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMemorySize();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_memory_grow(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMemoryGrow();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_add(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWAdd();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_sub(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWSub();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_and(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWAnd();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_or(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWOr();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_xor(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWXor();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_atomic_rmw_xchg(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAtomicRMWXchg();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_float32_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSFloat32ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_float32_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSFloat32ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_float32_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUFloat32ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_float32_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUFloat32ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_float64_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSFloat64ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_float64_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSFloat64ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_float64_to_int32(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUFloat64ToInt32();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_float64_to_int64(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUFloat64ToInt64();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_splat_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSplatVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_extract_lane_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenExtractLaneVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_replace_lane_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenReplaceLaneVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_eq_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenEqVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ne_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNeVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_lt_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLtVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_gt_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGtVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_le_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLeVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ge_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenGeVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_not_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNotVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_and_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAndVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_or_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenOrVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_xor_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenXorVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_and_not_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAndNotVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_bitselect_vec128(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenBitselectVec128();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_any_true_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAnyTrueVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_all_true_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAllTrueVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_bitmask_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenBitmaskVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_sat_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddSatSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_sat_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddSatUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_sat_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubSatSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_sat_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubSatUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_s_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxSVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_avgr_u_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAvgrUVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_any_true_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAnyTrueVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_all_true_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAllTrueVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_bitmask_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenBitmaskVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_sat_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddSatSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_sat_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddSatUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_sat_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubSatSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_sat_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubSatUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_s_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxSVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_avgr_u_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAvgrUVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_any_true_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAnyTrueVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_all_true_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAllTrueVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_bitmask_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenBitmaskVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_s_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxSVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_u_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxUVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_dot_s_vec_i16x8_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDotSVecI16x8ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_any_true_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAnyTrueVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_all_true_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAllTrueVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shl_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShlVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_s_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrSVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_shr_u_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenShrUVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sqrt_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSqrtVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_qfma_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenQFMAVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_qfms_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenQFMSVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_p_min_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPMinVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_p_max_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPMaxVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ceil_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCeilVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_floor_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenFloorVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_nearest_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNearestVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_abs_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAbsVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_neg_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNegVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sqrt_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSqrtVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_qfma_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenQFMAVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_qfms_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenQFMSVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_add_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenAddVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_sub_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSubVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_mul_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMulVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_div_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenDivVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_min_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMinVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_max_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenMaxVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_p_min_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPMinVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_p_max_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenPMaxVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_ceil_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenCeilVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_floor_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenFloorVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_nearest_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNearestVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_vec_f32x4_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSVecF32x4ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_vec_f32x4_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUVecF32x4ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_s_vec_f64x2_to_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatSVecF64x2ToVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_trunc_sat_u_vec_f64x2_to_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenTruncSatUVecF64x2ToVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_vec_i32x4_to_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSVecI32x4ToVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_vec_i32x4_to_vec_f32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUVecI32x4ToVecF32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_s_vec_i64x2_to_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertSVecI64x2ToVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_convert_u_vec_i64x2_to_vec_f64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenConvertUVecI64x2ToVecF64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_splat_vec8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadSplatVec8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_splat_vec16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadSplatVec16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_splat_vec32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadSplatVec32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_splat_vec64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadSplatVec64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_s_vec8x8_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtSVec8x8ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_u_vec8x8_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtUVec8x8ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_s_vec16x4_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtSVec16x4ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_u_vec16x4_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtUVec16x4ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_s_vec32x2_to_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtSVec32x2ToVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_load_ext_u_vec32x2_to_vec_i64x2(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenLoadExtUVec32x2ToVecI64x2();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_narrow_s_vec_i16x8_to_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNarrowSVecI16x8ToVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_narrow_u_vec_i16x8_to_vec_i8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNarrowUVecI16x8ToVecI8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_narrow_s_vec_i32x4_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNarrowSVecI32x4ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_narrow_u_vec_i32x4_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenNarrowUVecI32x4ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_low_s_vec_i8x16_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenLowSVecI8x16ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_high_s_vec_i8x16_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenHighSVecI8x16ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_low_u_vec_i8x16_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenLowUVecI8x16ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_high_u_vec_i8x16_to_vec_i16x8(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenHighUVecI8x16ToVecI16x8();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_low_s_vec_i16x8_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenLowSVecI16x8ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_high_s_vec_i16x8_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenHighSVecI16x8ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_low_u_vec_i16x8_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenLowUVecI16x8ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_widen_high_u_vec_i16x8_to_vec_i32x4(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenWidenHighUVecI16x8ToVecI32x4();
  CAMLreturn(alloc_BinaryenOp(op));
}

CAMLprim value
caml_binaryen_binaryen_swizzle_vec8x16(value unit) {
  CAMLparam1(unit);
  BinaryenOp op = BinaryenSwizzleVec8x16();
  CAMLreturn(alloc_BinaryenOp(op));
}
