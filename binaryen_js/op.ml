open Js_of_ocaml.Js.Unsafe

type t = int

let clz_int32 : t = global ##. binaryen ##. Operations ##. ClzInt32

let ctz_int32 : t = global ##. binaryen ##. Operations ##. CtzInt32

let popcnt_int32 : t = global ##. binaryen ##. Operations ##. PopcntInt32

let neg_float32 : t = global ##. binaryen ##. Operations ##. NegFloat32

let abs_float32 : t = global ##. binaryen ##. Operations ##. AbsFloat32

let ceil_float32 : t = global ##. binaryen ##. Operations ##. CeilFloat32

let floor_float32 : t = global ##. binaryen ##. Operations ##. FloorFloat32

let trunc_float32 : t = global ##. binaryen ##. Operations ##. TruncFloat32

let nearest_float32 : t = global ##. binaryen ##. Operations ##. NearestFloat32

let sqrt_float32 : t = global ##. binaryen ##. Operations ##. SqrtFloat32

let eq_z_int32 : t = global ##. binaryen ##. Operations ##. EqZInt32

let clz_int64 : t = global ##. binaryen ##. Operations ##. ClzInt64

let ctz_int64 : t = global ##. binaryen ##. Operations ##. CtzInt64

let popcnt_int64 : t = global ##. binaryen ##. Operations ##. PopcntInt64

let neg_float64 : t = global ##. binaryen ##. Operations ##. NegFloat64

let abs_float64 : t = global ##. binaryen ##. Operations ##. AbsFloat64

let ceil_float64 : t = global ##. binaryen ##. Operations ##. CeilFloat64

let floor_float64 : t = global ##. binaryen ##. Operations ##. FloorFloat64

let trunc_float64 : t = global ##. binaryen ##. Operations ##. TruncFloat64

let nearest_float64 : t = global ##. binaryen ##. Operations ##. NearestFloat64

let sqrt_float64 : t = global ##. binaryen ##. Operations ##. SqrtFloat64

let eq_z_int64 : t = global ##. binaryen ##. Operations ##. EqZInt64

let extend_s_int32 : t = global ##. binaryen ##. Operations ##. ExtendSInt32

let extend_u_int32 : t = global ##. binaryen ##. Operations ##. ExtendUInt32

let wrap_int64 : t = global ##. binaryen ##. Operations ##. WrapInt64

let trunc_s_float32_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSFloat32ToInt32

let trunc_s_float32_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSFloat32ToInt64

let trunc_u_float32_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncUFloat32ToInt32

let trunc_u_float32_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncUFloat32ToInt64

let trunc_s_float64_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSFloat64ToInt32

let trunc_s_float64_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSFloat64ToInt64

let trunc_u_float64_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncUFloat64ToInt32

let trunc_u_float64_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncUFloat64ToInt64

let reinterpret_float32 : t =
  global ##. binaryen ##. Operations ##. ReinterpretFloat32

let reinterpret_float64 : t =
  global ##. binaryen ##. Operations ##. ReinterpretFloat64

let convert_s_int32_to_float32 : t =
  global ##. binaryen ##. Operations ##. ConvertSInt32ToFloat32

let convert_s_int32_to_float64 : t =
  global ##. binaryen ##. Operations ##. ConvertSInt32ToFloat64

let convert_u_int32_to_float32 : t =
  global ##. binaryen ##. Operations ##. ConvertUInt32ToFloat32

let convert_u_int32_to_float64 : t =
  global ##. binaryen ##. Operations ##. ConvertUInt32ToFloat64

let convert_s_int64_to_float32 : t =
  global ##. binaryen ##. Operations ##. ConvertSInt64ToFloat32

let convert_s_int64_to_float64 : t =
  global ##. binaryen ##. Operations ##. ConvertSInt64ToFloat64

let convert_u_int64_to_float32 : t =
  global ##. binaryen ##. Operations ##. ConvertUInt64ToFloat32

let convert_u_int64_to_float64 : t =
  global ##. binaryen ##. Operations ##. ConvertUInt64ToFloat64

let promote_float32 : t = global ##. binaryen ##. Operations ##. PromoteFloat32

let demote_float64 : t = global ##. binaryen ##. Operations ##. DemoteFloat64

let reinterpret_int32 : t =
  global ##. binaryen ##. Operations ##. ReinterpretInt32

let reinterpret_int64 : t =
  global ##. binaryen ##. Operations ##. ReinterpretInt64

let extend_s8_int32 : t = global ##. binaryen ##. Operations ##. ExtendS8Int32

let extend_s16_int32 : t = global ##. binaryen ##. Operations ##. ExtendS16Int32

let extend_s8_int64 : t = global ##. binaryen ##. Operations ##. ExtendS8Int64

let extend_s16_int64 : t = global ##. binaryen ##. Operations ##. ExtendS16Int64

let extend_s32_int64 : t = global ##. binaryen ##. Operations ##. ExtendS32Int64

let add_int32 : t = global ##. binaryen ##. Operations ##. AddInt32

let sub_int32 : t = global ##. binaryen ##. Operations ##. SubInt32

let mul_int32 : t = global ##. binaryen ##. Operations ##. MulInt32

let div_s_int32 : t = global ##. binaryen ##. Operations ##. DivSInt32

let div_u_int32 : t = global ##. binaryen ##. Operations ##. DivUInt32

let rem_s_int32 : t = global ##. binaryen ##. Operations ##. RemSInt32

let rem_u_int32 : t = global ##. binaryen ##. Operations ##. RemUInt32

let and_int32 : t = global ##. binaryen ##. Operations ##. AndInt32

let or_int32 : t = global ##. binaryen ##. Operations ##. OrInt32

let xor_int32 : t = global ##. binaryen ##. Operations ##. XorInt32

let shl_int32 : t = global ##. binaryen ##. Operations ##. ShlInt32

let shr_u_int32 : t = global ##. binaryen ##. Operations ##. ShrUInt32

let shr_s_int32 : t = global ##. binaryen ##. Operations ##. ShrSInt32

let rot_l_int32 : t = global ##. binaryen ##. Operations ##. RotLInt32

let rot_r_int32 : t = global ##. binaryen ##. Operations ##. RotRInt32

let eq_int32 : t = global ##. binaryen ##. Operations ##. EqInt32

let ne_int32 : t = global ##. binaryen ##. Operations ##. NeInt32

let lt_s_int32 : t = global ##. binaryen ##. Operations ##. LtSInt32

let lt_u_int32 : t = global ##. binaryen ##. Operations ##. LtUInt32

let le_s_int32 : t = global ##. binaryen ##. Operations ##. LeSInt32

let le_u_int32 : t = global ##. binaryen ##. Operations ##. LeUInt32

let gt_s_int32 : t = global ##. binaryen ##. Operations ##. GtSInt32

let gt_u_int32 : t = global ##. binaryen ##. Operations ##. GtUInt32

let ge_s_int32 : t = global ##. binaryen ##. Operations ##. GeSInt32

let ge_u_int32 : t = global ##. binaryen ##. Operations ##. GeUInt32

let add_int64 : t = global ##. binaryen ##. Operations ##. AddInt64

let sub_int64 : t = global ##. binaryen ##. Operations ##. SubInt64

let mul_int64 : t = global ##. binaryen ##. Operations ##. MulInt64

let div_s_int64 : t = global ##. binaryen ##. Operations ##. DivSInt64

let div_u_int64 : t = global ##. binaryen ##. Operations ##. DivUInt64

let rem_s_int64 : t = global ##. binaryen ##. Operations ##. RemSInt64

let rem_u_int64 : t = global ##. binaryen ##. Operations ##. RemUInt64

let and_int64 : t = global ##. binaryen ##. Operations ##. AndInt64

let or_int64 : t = global ##. binaryen ##. Operations ##. OrInt64

let xor_int64 : t = global ##. binaryen ##. Operations ##. XorInt64

let shl_int64 : t = global ##. binaryen ##. Operations ##. ShlInt64

let shr_u_int64 : t = global ##. binaryen ##. Operations ##. ShrUInt64

let shr_s_int64 : t = global ##. binaryen ##. Operations ##. ShrSInt64

let rot_l_int64 : t = global ##. binaryen ##. Operations ##. RotLInt64

let rot_r_int64 : t = global ##. binaryen ##. Operations ##. RotRInt64

let eq_int64 : t = global ##. binaryen ##. Operations ##. EqInt64

let ne_int64 : t = global ##. binaryen ##. Operations ##. NeInt64

let lt_s_int64 : t = global ##. binaryen ##. Operations ##. LtSInt64

let lt_u_int64 : t = global ##. binaryen ##. Operations ##. LtUInt64

let le_s_int64 : t = global ##. binaryen ##. Operations ##. LeSInt64

let le_u_int64 : t = global ##. binaryen ##. Operations ##. LeUInt64

let gt_s_int64 : t = global ##. binaryen ##. Operations ##. GtSInt64

let gt_u_int64 : t = global ##. binaryen ##. Operations ##. GtUInt64

let ge_s_int64 : t = global ##. binaryen ##. Operations ##. GeSInt64

let ge_u_int64 : t = global ##. binaryen ##. Operations ##. GeUInt64

let add_float32 : t = global ##. binaryen ##. Operations ##. AddFloat32

let sub_float32 : t = global ##. binaryen ##. Operations ##. SubFloat32

let mul_float32 : t = global ##. binaryen ##. Operations ##. MulFloat32

let div_float32 : t = global ##. binaryen ##. Operations ##. DivFloat32

let copy_sign_float32 : t =
  global ##. binaryen ##. Operations ##. CopySignFloat32

let min_float32 : t = global ##. binaryen ##. Operations ##. MinFloat32

let max_float32 : t = global ##. binaryen ##. Operations ##. MaxFloat32

let eq_float32 : t = global ##. binaryen ##. Operations ##. EqFloat32

let ne_float32 : t = global ##. binaryen ##. Operations ##. NeFloat32

let lt_float32 : t = global ##. binaryen ##. Operations ##. LtFloat32

let le_float32 : t = global ##. binaryen ##. Operations ##. LeFloat32

let gt_float32 : t = global ##. binaryen ##. Operations ##. GtFloat32

let ge_float32 : t = global ##. binaryen ##. Operations ##. GeFloat32

let add_float64 : t = global ##. binaryen ##. Operations ##. AddFloat64

let sub_float64 : t = global ##. binaryen ##. Operations ##. SubFloat64

let mul_float64 : t = global ##. binaryen ##. Operations ##. MulFloat64

let div_float64 : t = global ##. binaryen ##. Operations ##. DivFloat64

let copy_sign_float64 : t =
  global ##. binaryen ##. Operations ##. CopySignFloat64

let min_float64 : t = global ##. binaryen ##. Operations ##. MinFloat64

let max_float64 : t = global ##. binaryen ##. Operations ##. MaxFloat64

let eq_float64 : t = global ##. binaryen ##. Operations ##. EqFloat64

let ne_float64 : t = global ##. binaryen ##. Operations ##. NeFloat64

let lt_float64 : t = global ##. binaryen ##. Operations ##. LtFloat64

let le_float64 : t = global ##. binaryen ##. Operations ##. LeFloat64

let gt_float64 : t = global ##. binaryen ##. Operations ##. GtFloat64

let ge_float64 : t = global ##. binaryen ##. Operations ##. GeFloat64

let memory_size : t = global ##. binaryen ##. Operations ##. MemorySize

let memory_grow : t = global ##. binaryen ##. Operations ##. MemoryGrow

let atomic_rmw_add : t = global ##. binaryen ##. Operations ##. AtomicRMWAdd

let atomic_rmw_sub : t = global ##. binaryen ##. Operations ##. AtomicRMWSub

let atomic_rmw_and : t = global ##. binaryen ##. Operations ##. AtomicRMWAnd

let atomic_rmw_or : t = global ##. binaryen ##. Operations ##. AtomicRMWOr

let atomic_rmw_xor : t = global ##. binaryen ##. Operations ##. AtomicRMWXor

let atomic_rmw_xchg : t = global ##. binaryen ##. Operations ##. AtomicRMWXchg

let trunc_sat_s_float32_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSatSFloat32ToInt32

let trunc_sat_s_float32_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSatSFloat32ToInt64

let trunc_sat_u_float32_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSatUFloat32ToInt32

let trunc_sat_u_float32_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSatUFloat32ToInt64

let trunc_sat_s_float64_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSatSFloat64ToInt32

let trunc_sat_s_float64_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSatSFloat64ToInt64

let trunc_sat_u_float64_to_int32 : t =
  global ##. binaryen ##. Operations ##. TruncSatUFloat64ToInt32

let trunc_sat_u_float64_to_int64 : t =
  global ##. binaryen ##. Operations ##. TruncSatUFloat64ToInt64

let splat_vec_i8x16 : t = global ##. binaryen ##. Operations ##. SplatVecI8x16

let extract_lane_s_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneSVecI8x16

let extract_lane_u_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneUVecI8x16

let replace_lane_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecI8x16

let splat_vec_i16x8 : t = global ##. binaryen ##. Operations ##. SplatVecI16x8

let extract_lane_s_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneSVecI16x8

let extract_lane_u_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneUVecI16x8

let replace_lane_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecI16x8

let splat_vec_i32x4 : t = global ##. binaryen ##. Operations ##. SplatVecI32x4

let extract_lane_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneVecI32x4

let replace_lane_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecI32x4

let splat_vec_i64x2 : t = global ##. binaryen ##. Operations ##. SplatVecI64x2

let extract_lane_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneVecI64x2

let replace_lane_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecI64x2

let splat_vec_f32x4 : t = global ##. binaryen ##. Operations ##. SplatVecF32x4

let extract_lane_vec_f32x4 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneVecF32x4

let replace_lane_vec_f32x4 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecF32x4

let splat_vec_f64x2 : t = global ##. binaryen ##. Operations ##. SplatVecF64x2

let extract_lane_vec_f64x2 : t =
  global ##. binaryen ##. Operations ##. ExtractLaneVecF64x2

let replace_lane_vec_f64x2 : t =
  global ##. binaryen ##. Operations ##. ReplaceLaneVecF64x2

let eq_vec_i8x16 : t = global ##. binaryen ##. Operations ##. EqVecI8x16

let ne_vec_i8x16 : t = global ##. binaryen ##. Operations ##. NeVecI8x16

let lt_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. LtSVecI8x16

let lt_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. LtUVecI8x16

let gt_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. GtSVecI8x16

let gt_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. GtUVecI8x16

let le_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. LeSVecI8x16

let le_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. LeUVecI8x16

let ge_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. GeSVecI8x16

let ge_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. GeUVecI8x16

let eq_vec_i16x8 : t = global ##. binaryen ##. Operations ##. EqVecI16x8

let ne_vec_i16x8 : t = global ##. binaryen ##. Operations ##. NeVecI16x8

let lt_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. LtSVecI16x8

let lt_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. LtUVecI16x8

let gt_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. GtSVecI16x8

let gt_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. GtUVecI16x8

let le_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. LeSVecI16x8

let le_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. LeUVecI16x8

let ge_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. GeSVecI16x8

let ge_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. GeUVecI16x8

let eq_vec_i32x4 : t = global ##. binaryen ##. Operations ##. EqVecI32x4

let ne_vec_i32x4 : t = global ##. binaryen ##. Operations ##. NeVecI32x4

let lt_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. LtSVecI32x4

let lt_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. LtUVecI32x4

let gt_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. GtSVecI32x4

let gt_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. GtUVecI32x4

let le_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. LeSVecI32x4

let le_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. LeUVecI32x4

let ge_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. GeSVecI32x4

let ge_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. GeUVecI32x4

let eq_vec_f32x4 : t = global ##. binaryen ##. Operations ##. EqVecF32x4

let ne_vec_f32x4 : t = global ##. binaryen ##. Operations ##. NeVecF32x4

let lt_vec_f32x4 : t = global ##. binaryen ##. Operations ##. LtVecF32x4

let gt_vec_f32x4 : t = global ##. binaryen ##. Operations ##. GtVecF32x4

let le_vec_f32x4 : t = global ##. binaryen ##. Operations ##. LeVecF32x4

let ge_vec_f32x4 : t = global ##. binaryen ##. Operations ##. GeVecF32x4

let eq_vec_f64x2 : t = global ##. binaryen ##. Operations ##. EqVecF64x2

let ne_vec_f64x2 : t = global ##. binaryen ##. Operations ##. NeVecF64x2

let lt_vec_f64x2 : t = global ##. binaryen ##. Operations ##. LtVecF64x2

let gt_vec_f64x2 : t = global ##. binaryen ##. Operations ##. GtVecF64x2

let le_vec_f64x2 : t = global ##. binaryen ##. Operations ##. LeVecF64x2

let ge_vec_f64x2 : t = global ##. binaryen ##. Operations ##. GeVecF64x2

let not_vec128 : t = global ##. binaryen ##. Operations ##. NotVec128

let and_vec128 : t = global ##. binaryen ##. Operations ##. AndVec128

let or_vec128 : t = global ##. binaryen ##. Operations ##. OrVec128

let xor_vec128 : t = global ##. binaryen ##. Operations ##. XorVec128

let and_not_vec128 : t = global ##. binaryen ##. Operations ##. AndNotVec128

let bitselect_vec128 : t =
  global ##. binaryen ##. Operations ##. BitselectVec128

let abs_vec_i8x16 : t = global ##. binaryen ##. Operations ##. AbsVecI8x16

let neg_vec_i8x16 : t = global ##. binaryen ##. Operations ##. NegVecI8x16

let any_true_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. AnyTrueVecI8x16

let all_true_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. AllTrueVecI8x16

let bitmask_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. BitmaskVecI8x16

let shl_vec_i8x16 : t = global ##. binaryen ##. Operations ##. ShlVecI8x16

let shr_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. ShrSVecI8x16

let shr_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. ShrUVecI8x16

let add_vec_i8x16 : t = global ##. binaryen ##. Operations ##. AddVecI8x16

let add_sat_s_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. AddSatSVecI8x16

let add_sat_u_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. AddSatUVecI8x16

let sub_vec_i8x16 : t = global ##. binaryen ##. Operations ##. SubVecI8x16

let sub_sat_s_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. SubSatSVecI8x16

let sub_sat_u_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. SubSatUVecI8x16

let mul_vec_i8x16 : t = global ##. binaryen ##. Operations ##. MulVecI8x16

let min_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. MinSVecI8x16

let min_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. MinUVecI8x16

let max_s_vec_i8x16 : t = global ##. binaryen ##. Operations ##. MaxSVecI8x16

let max_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. MaxUVecI8x16

let avgr_u_vec_i8x16 : t = global ##. binaryen ##. Operations ##. AvgrUVecI8x16

let abs_vec_i16x8 : t = global ##. binaryen ##. Operations ##. AbsVecI16x8

let neg_vec_i16x8 : t = global ##. binaryen ##. Operations ##. NegVecI16x8

let any_true_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. AnyTrueVecI16x8

let all_true_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. AllTrueVecI16x8

let bitmask_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. BitmaskVecI16x8

let shl_vec_i16x8 : t = global ##. binaryen ##. Operations ##. ShlVecI16x8

let shr_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. ShrSVecI16x8

let shr_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. ShrUVecI16x8

let add_vec_i16x8 : t = global ##. binaryen ##. Operations ##. AddVecI16x8

let add_sat_s_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. AddSatSVecI16x8

let add_sat_u_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. AddSatUVecI16x8

let sub_vec_i16x8 : t = global ##. binaryen ##. Operations ##. SubVecI16x8

let sub_sat_s_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. SubSatSVecI16x8

let sub_sat_u_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. SubSatUVecI16x8

let mul_vec_i16x8 : t = global ##. binaryen ##. Operations ##. MulVecI16x8

let min_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. MinSVecI16x8

let min_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. MinUVecI16x8

let max_s_vec_i16x8 : t = global ##. binaryen ##. Operations ##. MaxSVecI16x8

let max_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. MaxUVecI16x8

let avgr_u_vec_i16x8 : t = global ##. binaryen ##. Operations ##. AvgrUVecI16x8

let abs_vec_i32x4 : t = global ##. binaryen ##. Operations ##. AbsVecI32x4

let neg_vec_i32x4 : t = global ##. binaryen ##. Operations ##. NegVecI32x4

let any_true_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. AnyTrueVecI32x4

let all_true_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. AllTrueVecI32x4

let bitmask_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. BitmaskVecI32x4

let shl_vec_i32x4 : t = global ##. binaryen ##. Operations ##. ShlVecI32x4

let shr_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. ShrSVecI32x4

let shr_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. ShrUVecI32x4

let add_vec_i32x4 : t = global ##. binaryen ##. Operations ##. AddVecI32x4

let sub_vec_i32x4 : t = global ##. binaryen ##. Operations ##. SubVecI32x4

let mul_vec_i32x4 : t = global ##. binaryen ##. Operations ##. MulVecI32x4

let min_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. MinSVecI32x4

let min_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. MinUVecI32x4

let max_s_vec_i32x4 : t = global ##. binaryen ##. Operations ##. MaxSVecI32x4

let max_u_vec_i32x4 : t = global ##. binaryen ##. Operations ##. MaxUVecI32x4

let dot_s_vec_i16x8_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. DotSVecI16x8ToVecI32x4

let neg_vec_i64x2 : t = global ##. binaryen ##. Operations ##. NegVecI64x2

let any_true_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. AnyTrueVecI64x2

let all_true_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. AllTrueVecI64x2

let shl_vec_i64x2 : t = global ##. binaryen ##. Operations ##. ShlVecI64x2

let shr_s_vec_i64x2 : t = global ##. binaryen ##. Operations ##. ShrSVecI64x2

let shr_u_vec_i64x2 : t = global ##. binaryen ##. Operations ##. ShrUVecI64x2

let add_vec_i64x2 : t = global ##. binaryen ##. Operations ##. AddVecI64x2

let sub_vec_i64x2 : t = global ##. binaryen ##. Operations ##. SubVecI64x2

let mul_vec_i64x2 : t = global ##. binaryen ##. Operations ##. MulVecI64x2

let abs_vec_f32x4 : t = global ##. binaryen ##. Operations ##. AbsVecF32x4

let neg_vec_f32x4 : t = global ##. binaryen ##. Operations ##. NegVecF32x4

let sqrt_vec_f32x4 : t = global ##. binaryen ##. Operations ##. SqrtVecF32x4

let qfma_vec_f32x4 : t = global ##. binaryen ##. Operations ##. QFMAVecF32x4

let qfms_vec_f32x4 : t = global ##. binaryen ##. Operations ##. QFMSVecF32x4

let add_vec_f32x4 : t = global ##. binaryen ##. Operations ##. AddVecF32x4

let sub_vec_f32x4 : t = global ##. binaryen ##. Operations ##. SubVecF32x4

let mul_vec_f32x4 : t = global ##. binaryen ##. Operations ##. MulVecF32x4

let div_vec_f32x4 : t = global ##. binaryen ##. Operations ##. DivVecF32x4

let min_vec_f32x4 : t = global ##. binaryen ##. Operations ##. MinVecF32x4

let max_vec_f32x4 : t = global ##. binaryen ##. Operations ##. MaxVecF32x4

let p_min_vec_f32x4 : t = global ##. binaryen ##. Operations ##. PMinVecF32x4

let p_max_vec_f32x4 : t = global ##. binaryen ##. Operations ##. PMaxVecF32x4

let ceil_vec_f32x4 : t = global ##. binaryen ##. Operations ##. CeilVecF32x4

let floor_vec_f32x4 : t = global ##. binaryen ##. Operations ##. FloorVecF32x4

let trunc_vec_f32x4 : t = global ##. binaryen ##. Operations ##. TruncVecF32x4

let nearest_vec_f32x4 : t =
  global ##. binaryen ##. Operations ##. NearestVecF32x4

let abs_vec_f64x2 : t = global ##. binaryen ##. Operations ##. AbsVecF64x2

let neg_vec_f64x2 : t = global ##. binaryen ##. Operations ##. NegVecF64x2

let sqrt_vec_f64x2 : t = global ##. binaryen ##. Operations ##. SqrtVecF64x2

let qfma_vec_f64x2 : t = global ##. binaryen ##. Operations ##. QFMAVecF64x2

let qfms_vec_f64x2 : t = global ##. binaryen ##. Operations ##. QFMSVecF64x2

let add_vec_f64x2 : t = global ##. binaryen ##. Operations ##. AddVecF64x2

let sub_vec_f64x2 : t = global ##. binaryen ##. Operations ##. SubVecF64x2

let mul_vec_f64x2 : t = global ##. binaryen ##. Operations ##. MulVecF64x2

let div_vec_f64x2 : t = global ##. binaryen ##. Operations ##. DivVecF64x2

let min_vec_f64x2 : t = global ##. binaryen ##. Operations ##. MinVecF64x2

let max_vec_f64x2 : t = global ##. binaryen ##. Operations ##. MaxVecF64x2

let p_min_vec_f64x2 : t = global ##. binaryen ##. Operations ##. PMinVecF64x2

let p_max_vec_f64x2 : t = global ##. binaryen ##. Operations ##. PMaxVecF64x2

let ceil_vec_f64x2 : t = global ##. binaryen ##. Operations ##. CeilVecF64x2

let floor_vec_f64x2 : t = global ##. binaryen ##. Operations ##. FloorVecF64x2

let trunc_vec_f64x2 : t = global ##. binaryen ##. Operations ##. TruncVecF64x2

let nearest_vec_f64x2 : t =
  global ##. binaryen ##. Operations ##. NearestVecF64x2

let trunc_sat_s_vec_f32x4_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. TruncSatSVecF32x4ToVecI32x4

let trunc_sat_u_vec_f32x4_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. TruncSatUVecF32x4ToVecI32x4

let trunc_sat_s_vec_f64x2_to_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. TruncSatSVecF64x2ToVecI64x2

let trunc_sat_u_vec_f64x2_to_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. TruncSatUVecF64x2ToVecI64x2

let convert_s_vec_i32x4_to_vec_f32x4 : t =
  global ##. binaryen ##. Operations ##. ConvertSVecI32x4ToVecF32x4

let convert_u_vec_i32x4_to_vec_f32x4 : t =
  global ##. binaryen ##. Operations ##. ConvertUVecI32x4ToVecF32x4

let convert_s_vec_i64x2_to_vec_f64x2 : t =
  global ##. binaryen ##. Operations ##. ConvertSVecI64x2ToVecF64x2

let convert_u_vec_i64x2_to_vec_f64x2 : t =
  global ##. binaryen ##. Operations ##. ConvertUVecI64x2ToVecF64x2

let load_splat_vec8x16 : t =
  global ##. binaryen ##. Operations ##. LoadSplatVec8x16

let load_splat_vec16x8 : t =
  global ##. binaryen ##. Operations ##. LoadSplatVec16x8

let load_splat_vec32x4 : t =
  global ##. binaryen ##. Operations ##. LoadSplatVec32x4

let load_splat_vec64x2 : t =
  global ##. binaryen ##. Operations ##. LoadSplatVec64x2

let load_ext_s_vec8x8_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. LoadExtSVec8x8ToVecI16x8

let load_ext_u_vec8x8_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. LoadExtUVec8x8ToVecI16x8

let load_ext_s_vec16x4_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. LoadExtSVec16x4ToVecI32x4

let load_ext_u_vec16x4_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. LoadExtUVec16x4ToVecI32x4

let load_ext_s_vec32x2_to_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. LoadExtSVec32x2ToVecI64x2

let load_ext_u_vec32x2_to_vec_i64x2 : t =
  global ##. binaryen ##. Operations ##. LoadExtUVec32x2ToVecI64x2

let narrow_s_vec_i16x8_to_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. NarrowSVecI16x8ToVecI8x16

let narrow_u_vec_i16x8_to_vec_i8x16 : t =
  global ##. binaryen ##. Operations ##. NarrowUVecI16x8ToVecI8x16

let narrow_s_vec_i32x4_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. NarrowSVecI32x4ToVecI16x8

let narrow_u_vec_i32x4_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. NarrowUVecI32x4ToVecI16x8

let widen_low_s_vec_i8x16_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. WidenLowSVecI8x16ToVecI16x8

let widen_high_s_vec_i8x16_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. WidenHighSVecI8x16ToVecI16x8

let widen_low_u_vec_i8x16_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. WidenLowUVecI8x16ToVecI16x8

let widen_high_u_vec_i8x16_to_vec_i16x8 : t =
  global ##. binaryen ##. Operations ##. WidenHighUVecI8x16ToVecI16x8

let widen_low_s_vec_i16x8_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. WidenLowSVecI16x8ToVecI32x4

let widen_high_s_vec_i16x8_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. WidenHighSVecI16x8ToVecI32x4

let widen_low_u_vec_i16x8_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. WidenLowUVecI16x8ToVecI32x4

let widen_high_u_vec_i16x8_to_vec_i32x4 : t =
  global ##. binaryen ##. Operations ##. WidenHighUVecI16x8ToVecI32x4

let swizzle_vec8x16 : t = global ##. binaryen ##. Operations ##. SwizzleVec8x16
