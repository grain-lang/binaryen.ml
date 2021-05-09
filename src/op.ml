type t

external clz_int32 : unit -> t = "caml_binaryen_binaryen_clz_int32"

let clz_int32 = clz_int32 ()

external ctz_int32 : unit -> t = "caml_binaryen_binaryen_ctz_int32"

let ctz_int32 = ctz_int32 ()

external popcnt_int32 : unit -> t = "caml_binaryen_binaryen_popcnt_int32"

let popcnt_int32 = popcnt_int32 ()

external neg_float32 : unit -> t = "caml_binaryen_binaryen_neg_float32"

let neg_float32 = neg_float32 ()

external abs_float32 : unit -> t = "caml_binaryen_binaryen_abs_float32"

let abs_float32 = abs_float32 ()

external ceil_float32 : unit -> t = "caml_binaryen_binaryen_ceil_float32"

let ceil_float32 = ceil_float32 ()

external floor_float32 : unit -> t = "caml_binaryen_binaryen_floor_float32"

let floor_float32 = floor_float32 ()

external trunc_float32 : unit -> t = "caml_binaryen_binaryen_trunc_float32"

let trunc_float32 = trunc_float32 ()

external nearest_float32 : unit -> t = "caml_binaryen_binaryen_nearest_float32"

let nearest_float32 = nearest_float32 ()

external sqrt_float32 : unit -> t = "caml_binaryen_binaryen_sqrt_float32"

let sqrt_float32 = sqrt_float32 ()

external eq_z_int32 : unit -> t = "caml_binaryen_binaryen_eq_z_int32"

let eq_z_int32 = eq_z_int32 ()

external clz_int64 : unit -> t = "caml_binaryen_binaryen_clz_int64"

let clz_int64 = clz_int64 ()

external ctz_int64 : unit -> t = "caml_binaryen_binaryen_ctz_int64"

let ctz_int64 = ctz_int64 ()

external popcnt_int64 : unit -> t = "caml_binaryen_binaryen_popcnt_int64"

let popcnt_int64 = popcnt_int64 ()

external neg_float64 : unit -> t = "caml_binaryen_binaryen_neg_float64"

let neg_float64 = neg_float64 ()

external abs_float64 : unit -> t = "caml_binaryen_binaryen_abs_float64"

let abs_float64 = abs_float64 ()

external ceil_float64 : unit -> t = "caml_binaryen_binaryen_ceil_float64"

let ceil_float64 = ceil_float64 ()

external floor_float64 : unit -> t = "caml_binaryen_binaryen_floor_float64"

let floor_float64 = floor_float64 ()

external trunc_float64 : unit -> t = "caml_binaryen_binaryen_trunc_float64"

let trunc_float64 = trunc_float64 ()

external nearest_float64 : unit -> t = "caml_binaryen_binaryen_nearest_float64"

let nearest_float64 = nearest_float64 ()

external sqrt_float64 : unit -> t = "caml_binaryen_binaryen_sqrt_float64"

let sqrt_float64 = sqrt_float64 ()

external eq_z_int64 : unit -> t = "caml_binaryen_binaryen_eq_z_int64"

let eq_z_int64 = eq_z_int64 ()

external extend_s_int32 : unit -> t = "caml_binaryen_binaryen_extend_s_int32"

let extend_s_int32 = extend_s_int32 ()

external extend_u_int32 : unit -> t = "caml_binaryen_binaryen_extend_u_int32"

let extend_u_int32 = extend_u_int32 ()

external wrap_int64 : unit -> t = "caml_binaryen_binaryen_wrap_int64"

let wrap_int64 = wrap_int64 ()

external trunc_s_float32_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_s_float32_to_int32"

let trunc_s_float32_to_int32 = trunc_s_float32_to_int32 ()

external trunc_s_float32_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_s_float32_to_int64"

let trunc_s_float32_to_int64 = trunc_s_float32_to_int64 ()

external trunc_u_float32_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_u_float32_to_int32"

let trunc_u_float32_to_int32 = trunc_u_float32_to_int32 ()

external trunc_u_float32_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_u_float32_to_int64"

let trunc_u_float32_to_int64 = trunc_u_float32_to_int64 ()

external trunc_s_float64_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_s_float64_to_int32"

let trunc_s_float64_to_int32 = trunc_s_float64_to_int32 ()

external trunc_s_float64_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_s_float64_to_int64"

let trunc_s_float64_to_int64 = trunc_s_float64_to_int64 ()

external trunc_u_float64_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_u_float64_to_int32"

let trunc_u_float64_to_int32 = trunc_u_float64_to_int32 ()

external trunc_u_float64_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_u_float64_to_int64"

let trunc_u_float64_to_int64 = trunc_u_float64_to_int64 ()

external reinterpret_float32 : unit -> t
  = "caml_binaryen_binaryen_reinterpret_float32"

let reinterpret_float32 = reinterpret_float32 ()

external reinterpret_float64 : unit -> t
  = "caml_binaryen_binaryen_reinterpret_float64"

let reinterpret_float64 = reinterpret_float64 ()

external convert_s_int32_to_float32 : unit -> t
  = "caml_binaryen_binaryen_convert_s_int32_to_float32"

let convert_s_int32_to_float32 = convert_s_int32_to_float32 ()

external convert_s_int32_to_float64 : unit -> t
  = "caml_binaryen_binaryen_convert_s_int32_to_float64"

let convert_s_int32_to_float64 = convert_s_int32_to_float64 ()

external convert_u_int32_to_float32 : unit -> t
  = "caml_binaryen_binaryen_convert_u_int32_to_float32"

let convert_u_int32_to_float32 = convert_u_int32_to_float32 ()

external convert_u_int32_to_float64 : unit -> t
  = "caml_binaryen_binaryen_convert_u_int32_to_float64"

let convert_u_int32_to_float64 = convert_u_int32_to_float64 ()

external convert_s_int64_to_float32 : unit -> t
  = "caml_binaryen_binaryen_convert_s_int64_to_float32"

let convert_s_int64_to_float32 = convert_s_int64_to_float32 ()

external convert_s_int64_to_float64 : unit -> t
  = "caml_binaryen_binaryen_convert_s_int64_to_float64"

let convert_s_int64_to_float64 = convert_s_int64_to_float64 ()

external convert_u_int64_to_float32 : unit -> t
  = "caml_binaryen_binaryen_convert_u_int64_to_float32"

let convert_u_int64_to_float32 = convert_u_int64_to_float32 ()

external convert_u_int64_to_float64 : unit -> t
  = "caml_binaryen_binaryen_convert_u_int64_to_float64"

let convert_u_int64_to_float64 = convert_u_int64_to_float64 ()

external promote_float32 : unit -> t = "caml_binaryen_binaryen_promote_float32"

let promote_float32 = promote_float32 ()

external demote_float64 : unit -> t = "caml_binaryen_binaryen_demote_float64"

let demote_float64 = demote_float64 ()

external reinterpret_int32 : unit -> t
  = "caml_binaryen_binaryen_reinterpret_int32"

let reinterpret_int32 = reinterpret_int32 ()

external reinterpret_int64 : unit -> t
  = "caml_binaryen_binaryen_reinterpret_int64"

let reinterpret_int64 = reinterpret_int64 ()

external extend_s8_int32 : unit -> t = "caml_binaryen_binaryen_extend_s8_int32"

let extend_s8_int32 = extend_s8_int32 ()

external extend_s16_int32 : unit -> t
  = "caml_binaryen_binaryen_extend_s16_int32"

let extend_s16_int32 = extend_s16_int32 ()

external extend_s8_int64 : unit -> t = "caml_binaryen_binaryen_extend_s8_int64"

let extend_s8_int64 = extend_s8_int64 ()

external extend_s16_int64 : unit -> t
  = "caml_binaryen_binaryen_extend_s16_int64"

let extend_s16_int64 = extend_s16_int64 ()

external extend_s32_int64 : unit -> t
  = "caml_binaryen_binaryen_extend_s32_int64"

let extend_s32_int64 = extend_s32_int64 ()

external add_int32 : unit -> t = "caml_binaryen_binaryen_add_int32"

let add_int32 = add_int32 ()

external sub_int32 : unit -> t = "caml_binaryen_binaryen_sub_int32"

let sub_int32 = sub_int32 ()

external mul_int32 : unit -> t = "caml_binaryen_binaryen_mul_int32"

let mul_int32 = mul_int32 ()

external div_s_int32 : unit -> t = "caml_binaryen_binaryen_div_s_int32"

let div_s_int32 = div_s_int32 ()

external div_u_int32 : unit -> t = "caml_binaryen_binaryen_div_u_int32"

let div_u_int32 = div_u_int32 ()

external rem_s_int32 : unit -> t = "caml_binaryen_binaryen_rem_s_int32"

let rem_s_int32 = rem_s_int32 ()

external rem_u_int32 : unit -> t = "caml_binaryen_binaryen_rem_u_int32"

let rem_u_int32 = rem_u_int32 ()

external and_int32 : unit -> t = "caml_binaryen_binaryen_and_int32"

let and_int32 = and_int32 ()

external or_int32 : unit -> t = "caml_binaryen_binaryen_or_int32"

let or_int32 = or_int32 ()

external xor_int32 : unit -> t = "caml_binaryen_binaryen_xor_int32"

let xor_int32 = xor_int32 ()

external shl_int32 : unit -> t = "caml_binaryen_binaryen_shl_int32"

let shl_int32 = shl_int32 ()

external shr_u_int32 : unit -> t = "caml_binaryen_binaryen_shr_u_int32"

let shr_u_int32 = shr_u_int32 ()

external shr_s_int32 : unit -> t = "caml_binaryen_binaryen_shr_s_int32"

let shr_s_int32 = shr_s_int32 ()

external rot_l_int32 : unit -> t = "caml_binaryen_binaryen_rot_l_int32"

let rot_l_int32 = rot_l_int32 ()

external rot_r_int32 : unit -> t = "caml_binaryen_binaryen_rot_r_int32"

let rot_r_int32 = rot_r_int32 ()

external eq_int32 : unit -> t = "caml_binaryen_binaryen_eq_int32"

let eq_int32 = eq_int32 ()

external ne_int32 : unit -> t = "caml_binaryen_binaryen_ne_int32"

let ne_int32 = ne_int32 ()

external lt_s_int32 : unit -> t = "caml_binaryen_binaryen_lt_s_int32"

let lt_s_int32 = lt_s_int32 ()

external lt_u_int32 : unit -> t = "caml_binaryen_binaryen_lt_u_int32"

let lt_u_int32 = lt_u_int32 ()

external le_s_int32 : unit -> t = "caml_binaryen_binaryen_le_s_int32"

let le_s_int32 = le_s_int32 ()

external le_u_int32 : unit -> t = "caml_binaryen_binaryen_le_u_int32"

let le_u_int32 = le_u_int32 ()

external gt_s_int32 : unit -> t = "caml_binaryen_binaryen_gt_s_int32"

let gt_s_int32 = gt_s_int32 ()

external gt_u_int32 : unit -> t = "caml_binaryen_binaryen_gt_u_int32"

let gt_u_int32 = gt_u_int32 ()

external ge_s_int32 : unit -> t = "caml_binaryen_binaryen_ge_s_int32"

let ge_s_int32 = ge_s_int32 ()

external ge_u_int32 : unit -> t = "caml_binaryen_binaryen_ge_u_int32"

let ge_u_int32 = ge_u_int32 ()

external add_int64 : unit -> t = "caml_binaryen_binaryen_add_int64"

let add_int64 = add_int64 ()

external sub_int64 : unit -> t = "caml_binaryen_binaryen_sub_int64"

let sub_int64 = sub_int64 ()

external mul_int64 : unit -> t = "caml_binaryen_binaryen_mul_int64"

let mul_int64 = mul_int64 ()

external div_s_int64 : unit -> t = "caml_binaryen_binaryen_div_s_int64"

let div_s_int64 = div_s_int64 ()

external div_u_int64 : unit -> t = "caml_binaryen_binaryen_div_u_int64"

let div_u_int64 = div_u_int64 ()

external rem_s_int64 : unit -> t = "caml_binaryen_binaryen_rem_s_int64"

let rem_s_int64 = rem_s_int64 ()

external rem_u_int64 : unit -> t = "caml_binaryen_binaryen_rem_u_int64"

let rem_u_int64 = rem_u_int64 ()

external and_int64 : unit -> t = "caml_binaryen_binaryen_and_int64"

let and_int64 = and_int64 ()

external or_int64 : unit -> t = "caml_binaryen_binaryen_or_int64"

let or_int64 = or_int64 ()

external xor_int64 : unit -> t = "caml_binaryen_binaryen_xor_int64"

let xor_int64 = xor_int64 ()

external shl_int64 : unit -> t = "caml_binaryen_binaryen_shl_int64"

let shl_int64 = shl_int64 ()

external shr_u_int64 : unit -> t = "caml_binaryen_binaryen_shr_u_int64"

let shr_u_int64 = shr_u_int64 ()

external shr_s_int64 : unit -> t = "caml_binaryen_binaryen_shr_s_int64"

let shr_s_int64 = shr_s_int64 ()

external rot_l_int64 : unit -> t = "caml_binaryen_binaryen_rot_l_int64"

let rot_l_int64 = rot_l_int64 ()

external rot_r_int64 : unit -> t = "caml_binaryen_binaryen_rot_r_int64"

let rot_r_int64 = rot_r_int64 ()

external eq_int64 : unit -> t = "caml_binaryen_binaryen_eq_int64"

let eq_int64 = eq_int64 ()

external ne_int64 : unit -> t = "caml_binaryen_binaryen_ne_int64"

let ne_int64 = ne_int64 ()

external lt_s_int64 : unit -> t = "caml_binaryen_binaryen_lt_s_int64"

let lt_s_int64 = lt_s_int64 ()

external lt_u_int64 : unit -> t = "caml_binaryen_binaryen_lt_u_int64"

let lt_u_int64 = lt_u_int64 ()

external le_s_int64 : unit -> t = "caml_binaryen_binaryen_le_s_int64"

let le_s_int64 = le_s_int64 ()

external le_u_int64 : unit -> t = "caml_binaryen_binaryen_le_u_int64"

let le_u_int64 = le_u_int64 ()

external gt_s_int64 : unit -> t = "caml_binaryen_binaryen_gt_s_int64"

let gt_s_int64 = gt_s_int64 ()

external gt_u_int64 : unit -> t = "caml_binaryen_binaryen_gt_u_int64"

let gt_u_int64 = gt_u_int64 ()

external ge_s_int64 : unit -> t = "caml_binaryen_binaryen_ge_s_int64"

let ge_s_int64 = ge_s_int64 ()

external ge_u_int64 : unit -> t = "caml_binaryen_binaryen_ge_u_int64"

let ge_u_int64 = ge_u_int64 ()

external add_float32 : unit -> t = "caml_binaryen_binaryen_add_float32"

let add_float32 = add_float32 ()

external sub_float32 : unit -> t = "caml_binaryen_binaryen_sub_float32"

let sub_float32 = sub_float32 ()

external mul_float32 : unit -> t = "caml_binaryen_binaryen_mul_float32"

let mul_float32 = mul_float32 ()

external div_float32 : unit -> t = "caml_binaryen_binaryen_div_float32"

let div_float32 = div_float32 ()

external copy_sign_float32 : unit -> t
  = "caml_binaryen_binaryen_copy_sign_float32"

let copy_sign_float32 = copy_sign_float32 ()

external min_float32 : unit -> t = "caml_binaryen_binaryen_min_float32"

let min_float32 = min_float32 ()

external max_float32 : unit -> t = "caml_binaryen_binaryen_max_float32"

let max_float32 = max_float32 ()

external eq_float32 : unit -> t = "caml_binaryen_binaryen_eq_float32"

let eq_float32 = eq_float32 ()

external ne_float32 : unit -> t = "caml_binaryen_binaryen_ne_float32"

let ne_float32 = ne_float32 ()

external lt_float32 : unit -> t = "caml_binaryen_binaryen_lt_float32"

let lt_float32 = lt_float32 ()

external le_float32 : unit -> t = "caml_binaryen_binaryen_le_float32"

let le_float32 = le_float32 ()

external gt_float32 : unit -> t = "caml_binaryen_binaryen_gt_float32"

let gt_float32 = gt_float32 ()

external ge_float32 : unit -> t = "caml_binaryen_binaryen_ge_float32"

let ge_float32 = ge_float32 ()

external add_float64 : unit -> t = "caml_binaryen_binaryen_add_float64"

let add_float64 = add_float64 ()

external sub_float64 : unit -> t = "caml_binaryen_binaryen_sub_float64"

let sub_float64 = sub_float64 ()

external mul_float64 : unit -> t = "caml_binaryen_binaryen_mul_float64"

let mul_float64 = mul_float64 ()

external div_float64 : unit -> t = "caml_binaryen_binaryen_div_float64"

let div_float64 = div_float64 ()

external copy_sign_float64 : unit -> t
  = "caml_binaryen_binaryen_copy_sign_float64"

let copy_sign_float64 = copy_sign_float64 ()

external min_float64 : unit -> t = "caml_binaryen_binaryen_min_float64"

let min_float64 = min_float64 ()

external max_float64 : unit -> t = "caml_binaryen_binaryen_max_float64"

let max_float64 = max_float64 ()

external eq_float64 : unit -> t = "caml_binaryen_binaryen_eq_float64"

let eq_float64 = eq_float64 ()

external ne_float64 : unit -> t = "caml_binaryen_binaryen_ne_float64"

let ne_float64 = ne_float64 ()

external lt_float64 : unit -> t = "caml_binaryen_binaryen_lt_float64"

let lt_float64 = lt_float64 ()

external le_float64 : unit -> t = "caml_binaryen_binaryen_le_float64"

let le_float64 = le_float64 ()

external gt_float64 : unit -> t = "caml_binaryen_binaryen_gt_float64"

let gt_float64 = gt_float64 ()

external ge_float64 : unit -> t = "caml_binaryen_binaryen_ge_float64"

let ge_float64 = ge_float64 ()

external atomic_rmw_add : unit -> t = "caml_binaryen_binaryen_atomic_rmw_add"

let atomic_rmw_add = atomic_rmw_add ()

external atomic_rmw_sub : unit -> t = "caml_binaryen_binaryen_atomic_rmw_sub"

let atomic_rmw_sub = atomic_rmw_sub ()

external atomic_rmw_and : unit -> t = "caml_binaryen_binaryen_atomic_rmw_and"

let atomic_rmw_and = atomic_rmw_and ()

external atomic_rmw_or : unit -> t = "caml_binaryen_binaryen_atomic_rmw_or"

let atomic_rmw_or = atomic_rmw_or ()

external atomic_rmw_xor : unit -> t = "caml_binaryen_binaryen_atomic_rmw_xor"

let atomic_rmw_xor = atomic_rmw_xor ()

external atomic_rmw_xchg : unit -> t = "caml_binaryen_binaryen_atomic_rmw_xchg"

let atomic_rmw_xchg = atomic_rmw_xchg ()

external trunc_sat_s_float32_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_s_float32_to_int32"

let trunc_sat_s_float32_to_int32 = trunc_sat_s_float32_to_int32 ()

external trunc_sat_s_float32_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_s_float32_to_int64"

let trunc_sat_s_float32_to_int64 = trunc_sat_s_float32_to_int64 ()

external trunc_sat_u_float32_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_u_float32_to_int32"

let trunc_sat_u_float32_to_int32 = trunc_sat_u_float32_to_int32 ()

external trunc_sat_u_float32_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_u_float32_to_int64"

let trunc_sat_u_float32_to_int64 = trunc_sat_u_float32_to_int64 ()

external trunc_sat_s_float64_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_s_float64_to_int32"

let trunc_sat_s_float64_to_int32 = trunc_sat_s_float64_to_int32 ()

external trunc_sat_s_float64_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_s_float64_to_int64"

let trunc_sat_s_float64_to_int64 = trunc_sat_s_float64_to_int64 ()

external trunc_sat_u_float64_to_int32 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_u_float64_to_int32"

let trunc_sat_u_float64_to_int32 = trunc_sat_u_float64_to_int32 ()

external trunc_sat_u_float64_to_int64 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_u_float64_to_int64"

let trunc_sat_u_float64_to_int64 = trunc_sat_u_float64_to_int64 ()

external splat_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_splat_vec_i8x16"

let splat_vec_i8x16 = splat_vec_i8x16 ()

external extract_lane_s_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_s_vec_i8x16"

let extract_lane_s_vec_i8x16 = extract_lane_s_vec_i8x16 ()

external extract_lane_u_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_u_vec_i8x16"

let extract_lane_u_vec_i8x16 = extract_lane_u_vec_i8x16 ()

external replace_lane_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_i8x16"

let replace_lane_vec_i8x16 = replace_lane_vec_i8x16 ()

external splat_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_splat_vec_i16x8"

let splat_vec_i16x8 = splat_vec_i16x8 ()

external extract_lane_s_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_s_vec_i16x8"

let extract_lane_s_vec_i16x8 = extract_lane_s_vec_i16x8 ()

external extract_lane_u_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_u_vec_i16x8"

let extract_lane_u_vec_i16x8 = extract_lane_u_vec_i16x8 ()

external replace_lane_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_i16x8"

let replace_lane_vec_i16x8 = replace_lane_vec_i16x8 ()

external splat_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_splat_vec_i32x4"

let splat_vec_i32x4 = splat_vec_i32x4 ()

external extract_lane_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_vec_i32x4"

let extract_lane_vec_i32x4 = extract_lane_vec_i32x4 ()

external replace_lane_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_i32x4"

let replace_lane_vec_i32x4 = replace_lane_vec_i32x4 ()

external splat_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_splat_vec_i64x2"

let splat_vec_i64x2 = splat_vec_i64x2 ()

external extract_lane_vec_i64x2 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_vec_i64x2"

let extract_lane_vec_i64x2 = extract_lane_vec_i64x2 ()

external replace_lane_vec_i64x2 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_i64x2"

let replace_lane_vec_i64x2 = replace_lane_vec_i64x2 ()

external splat_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_splat_vec_f32x4"

let splat_vec_f32x4 = splat_vec_f32x4 ()

external extract_lane_vec_f32x4 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_vec_f32x4"

let extract_lane_vec_f32x4 = extract_lane_vec_f32x4 ()

external replace_lane_vec_f32x4 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_f32x4"

let replace_lane_vec_f32x4 = replace_lane_vec_f32x4 ()

external splat_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_splat_vec_f64x2"

let splat_vec_f64x2 = splat_vec_f64x2 ()

external extract_lane_vec_f64x2 : unit -> t
  = "caml_binaryen_binaryen_extract_lane_vec_f64x2"

let extract_lane_vec_f64x2 = extract_lane_vec_f64x2 ()

external replace_lane_vec_f64x2 : unit -> t
  = "caml_binaryen_binaryen_replace_lane_vec_f64x2"

let replace_lane_vec_f64x2 = replace_lane_vec_f64x2 ()

external eq_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_eq_vec_i8x16"

let eq_vec_i8x16 = eq_vec_i8x16 ()

external ne_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_ne_vec_i8x16"

let ne_vec_i8x16 = ne_vec_i8x16 ()

external lt_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_lt_s_vec_i8x16"

let lt_s_vec_i8x16 = lt_s_vec_i8x16 ()

external lt_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_lt_u_vec_i8x16"

let lt_u_vec_i8x16 = lt_u_vec_i8x16 ()

external gt_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_gt_s_vec_i8x16"

let gt_s_vec_i8x16 = gt_s_vec_i8x16 ()

external gt_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_gt_u_vec_i8x16"

let gt_u_vec_i8x16 = gt_u_vec_i8x16 ()

external le_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_le_s_vec_i8x16"

let le_s_vec_i8x16 = le_s_vec_i8x16 ()

external le_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_le_u_vec_i8x16"

let le_u_vec_i8x16 = le_u_vec_i8x16 ()

external ge_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_ge_s_vec_i8x16"

let ge_s_vec_i8x16 = ge_s_vec_i8x16 ()

external ge_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_ge_u_vec_i8x16"

let ge_u_vec_i8x16 = ge_u_vec_i8x16 ()

external eq_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_eq_vec_i16x8"

let eq_vec_i16x8 = eq_vec_i16x8 ()

external ne_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_ne_vec_i16x8"

let ne_vec_i16x8 = ne_vec_i16x8 ()

external lt_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_lt_s_vec_i16x8"

let lt_s_vec_i16x8 = lt_s_vec_i16x8 ()

external lt_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_lt_u_vec_i16x8"

let lt_u_vec_i16x8 = lt_u_vec_i16x8 ()

external gt_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_gt_s_vec_i16x8"

let gt_s_vec_i16x8 = gt_s_vec_i16x8 ()

external gt_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_gt_u_vec_i16x8"

let gt_u_vec_i16x8 = gt_u_vec_i16x8 ()

external le_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_le_s_vec_i16x8"

let le_s_vec_i16x8 = le_s_vec_i16x8 ()

external le_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_le_u_vec_i16x8"

let le_u_vec_i16x8 = le_u_vec_i16x8 ()

external ge_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_ge_s_vec_i16x8"

let ge_s_vec_i16x8 = ge_s_vec_i16x8 ()

external ge_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_ge_u_vec_i16x8"

let ge_u_vec_i16x8 = ge_u_vec_i16x8 ()

external eq_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_eq_vec_i32x4"

let eq_vec_i32x4 = eq_vec_i32x4 ()

external ne_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_ne_vec_i32x4"

let ne_vec_i32x4 = ne_vec_i32x4 ()

external lt_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_lt_s_vec_i32x4"

let lt_s_vec_i32x4 = lt_s_vec_i32x4 ()

external lt_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_lt_u_vec_i32x4"

let lt_u_vec_i32x4 = lt_u_vec_i32x4 ()

external gt_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_gt_s_vec_i32x4"

let gt_s_vec_i32x4 = gt_s_vec_i32x4 ()

external gt_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_gt_u_vec_i32x4"

let gt_u_vec_i32x4 = gt_u_vec_i32x4 ()

external le_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_le_s_vec_i32x4"

let le_s_vec_i32x4 = le_s_vec_i32x4 ()

external le_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_le_u_vec_i32x4"

let le_u_vec_i32x4 = le_u_vec_i32x4 ()

external ge_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_ge_s_vec_i32x4"

let ge_s_vec_i32x4 = ge_s_vec_i32x4 ()

external ge_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_ge_u_vec_i32x4"

let ge_u_vec_i32x4 = ge_u_vec_i32x4 ()

external eq_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_eq_vec_f32x4"

let eq_vec_f32x4 = eq_vec_f32x4 ()

external ne_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_ne_vec_f32x4"

let ne_vec_f32x4 = ne_vec_f32x4 ()

external lt_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_lt_vec_f32x4"

let lt_vec_f32x4 = lt_vec_f32x4 ()

external gt_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_gt_vec_f32x4"

let gt_vec_f32x4 = gt_vec_f32x4 ()

external le_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_le_vec_f32x4"

let le_vec_f32x4 = le_vec_f32x4 ()

external ge_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_ge_vec_f32x4"

let ge_vec_f32x4 = ge_vec_f32x4 ()

external eq_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_eq_vec_f64x2"

let eq_vec_f64x2 = eq_vec_f64x2 ()

external ne_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_ne_vec_f64x2"

let ne_vec_f64x2 = ne_vec_f64x2 ()

external lt_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_lt_vec_f64x2"

let lt_vec_f64x2 = lt_vec_f64x2 ()

external gt_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_gt_vec_f64x2"

let gt_vec_f64x2 = gt_vec_f64x2 ()

external le_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_le_vec_f64x2"

let le_vec_f64x2 = le_vec_f64x2 ()

external ge_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_ge_vec_f64x2"

let ge_vec_f64x2 = ge_vec_f64x2 ()

external not_vec128 : unit -> t = "caml_binaryen_binaryen_not_vec128"

let not_vec128 = not_vec128 ()

external and_vec128 : unit -> t = "caml_binaryen_binaryen_and_vec128"

let and_vec128 = and_vec128 ()

external or_vec128 : unit -> t = "caml_binaryen_binaryen_or_vec128"

let or_vec128 = or_vec128 ()

external xor_vec128 : unit -> t = "caml_binaryen_binaryen_xor_vec128"

let xor_vec128 = xor_vec128 ()

external and_not_vec128 : unit -> t = "caml_binaryen_binaryen_and_not_vec128"

let and_not_vec128 = and_not_vec128 ()

external bitselect_vec128 : unit -> t
  = "caml_binaryen_binaryen_bitselect_vec128"

let bitselect_vec128 = bitselect_vec128 ()

external abs_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_abs_vec_i8x16"

let abs_vec_i8x16 = abs_vec_i8x16 ()

external neg_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_neg_vec_i8x16"

let neg_vec_i8x16 = neg_vec_i8x16 ()

external all_true_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_all_true_vec_i8x16"

let all_true_vec_i8x16 = all_true_vec_i8x16 ()

external bitmask_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_bitmask_vec_i8x16"

let bitmask_vec_i8x16 = bitmask_vec_i8x16 ()

external shl_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_shl_vec_i8x16"

let shl_vec_i8x16 = shl_vec_i8x16 ()

external shr_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_shr_s_vec_i8x16"

let shr_s_vec_i8x16 = shr_s_vec_i8x16 ()

external shr_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_shr_u_vec_i8x16"

let shr_u_vec_i8x16 = shr_u_vec_i8x16 ()

external add_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_add_vec_i8x16"

let add_vec_i8x16 = add_vec_i8x16 ()

external add_sat_s_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_add_sat_s_vec_i8x16"

let add_sat_s_vec_i8x16 = add_sat_s_vec_i8x16 ()

external add_sat_u_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_add_sat_u_vec_i8x16"

let add_sat_u_vec_i8x16 = add_sat_u_vec_i8x16 ()

external sub_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_sub_vec_i8x16"

let sub_vec_i8x16 = sub_vec_i8x16 ()

external sub_sat_s_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_sub_sat_s_vec_i8x16"

let sub_sat_s_vec_i8x16 = sub_sat_s_vec_i8x16 ()

external sub_sat_u_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_sub_sat_u_vec_i8x16"

let sub_sat_u_vec_i8x16 = sub_sat_u_vec_i8x16 ()

external min_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_min_s_vec_i8x16"

let min_s_vec_i8x16 = min_s_vec_i8x16 ()

external min_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_min_u_vec_i8x16"

let min_u_vec_i8x16 = min_u_vec_i8x16 ()

external max_s_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_max_s_vec_i8x16"

let max_s_vec_i8x16 = max_s_vec_i8x16 ()

external max_u_vec_i8x16 : unit -> t = "caml_binaryen_binaryen_max_u_vec_i8x16"

let max_u_vec_i8x16 = max_u_vec_i8x16 ()

external avgr_u_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_avgr_u_vec_i8x16"

let avgr_u_vec_i8x16 = avgr_u_vec_i8x16 ()

external abs_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_abs_vec_i16x8"

let abs_vec_i16x8 = abs_vec_i16x8 ()

external neg_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_neg_vec_i16x8"

let neg_vec_i16x8 = neg_vec_i16x8 ()

external all_true_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_all_true_vec_i16x8"

let all_true_vec_i16x8 = all_true_vec_i16x8 ()

external bitmask_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_bitmask_vec_i16x8"

let bitmask_vec_i16x8 = bitmask_vec_i16x8 ()

external shl_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_shl_vec_i16x8"

let shl_vec_i16x8 = shl_vec_i16x8 ()

external shr_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_shr_s_vec_i16x8"

let shr_s_vec_i16x8 = shr_s_vec_i16x8 ()

external shr_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_shr_u_vec_i16x8"

let shr_u_vec_i16x8 = shr_u_vec_i16x8 ()

external add_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_add_vec_i16x8"

let add_vec_i16x8 = add_vec_i16x8 ()

external add_sat_s_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_add_sat_s_vec_i16x8"

let add_sat_s_vec_i16x8 = add_sat_s_vec_i16x8 ()

external add_sat_u_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_add_sat_u_vec_i16x8"

let add_sat_u_vec_i16x8 = add_sat_u_vec_i16x8 ()

external sub_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_sub_vec_i16x8"

let sub_vec_i16x8 = sub_vec_i16x8 ()

external sub_sat_s_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_sub_sat_s_vec_i16x8"

let sub_sat_s_vec_i16x8 = sub_sat_s_vec_i16x8 ()

external sub_sat_u_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_sub_sat_u_vec_i16x8"

let sub_sat_u_vec_i16x8 = sub_sat_u_vec_i16x8 ()

external mul_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_mul_vec_i16x8"

let mul_vec_i16x8 = mul_vec_i16x8 ()

external min_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_min_s_vec_i16x8"

let min_s_vec_i16x8 = min_s_vec_i16x8 ()

external min_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_min_u_vec_i16x8"

let min_u_vec_i16x8 = min_u_vec_i16x8 ()

external max_s_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_max_s_vec_i16x8"

let max_s_vec_i16x8 = max_s_vec_i16x8 ()

external max_u_vec_i16x8 : unit -> t = "caml_binaryen_binaryen_max_u_vec_i16x8"

let max_u_vec_i16x8 = max_u_vec_i16x8 ()

external avgr_u_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_avgr_u_vec_i16x8"

let avgr_u_vec_i16x8 = avgr_u_vec_i16x8 ()

external abs_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_abs_vec_i32x4"

let abs_vec_i32x4 = abs_vec_i32x4 ()

external neg_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_neg_vec_i32x4"

let neg_vec_i32x4 = neg_vec_i32x4 ()

external all_true_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_all_true_vec_i32x4"

let all_true_vec_i32x4 = all_true_vec_i32x4 ()

external bitmask_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_bitmask_vec_i32x4"

let bitmask_vec_i32x4 = bitmask_vec_i32x4 ()

external shl_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_shl_vec_i32x4"

let shl_vec_i32x4 = shl_vec_i32x4 ()

external shr_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_shr_s_vec_i32x4"

let shr_s_vec_i32x4 = shr_s_vec_i32x4 ()

external shr_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_shr_u_vec_i32x4"

let shr_u_vec_i32x4 = shr_u_vec_i32x4 ()

external add_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_add_vec_i32x4"

let add_vec_i32x4 = add_vec_i32x4 ()

external sub_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_sub_vec_i32x4"

let sub_vec_i32x4 = sub_vec_i32x4 ()

external mul_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_mul_vec_i32x4"

let mul_vec_i32x4 = mul_vec_i32x4 ()

external min_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_min_s_vec_i32x4"

let min_s_vec_i32x4 = min_s_vec_i32x4 ()

external min_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_min_u_vec_i32x4"

let min_u_vec_i32x4 = min_u_vec_i32x4 ()

external max_s_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_max_s_vec_i32x4"

let max_s_vec_i32x4 = max_s_vec_i32x4 ()

external max_u_vec_i32x4 : unit -> t = "caml_binaryen_binaryen_max_u_vec_i32x4"

let max_u_vec_i32x4 = max_u_vec_i32x4 ()

external dot_s_vec_i16x8_to_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_dot_s_vec_i16x8_to_vec_i32x4"

let dot_s_vec_i16x8_to_vec_i32x4 = dot_s_vec_i16x8_to_vec_i32x4 ()

external neg_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_neg_vec_i64x2"

let neg_vec_i64x2 = neg_vec_i64x2 ()

external shl_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_shl_vec_i64x2"

let shl_vec_i64x2 = shl_vec_i64x2 ()

external shr_s_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_shr_s_vec_i64x2"

let shr_s_vec_i64x2 = shr_s_vec_i64x2 ()

external shr_u_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_shr_u_vec_i64x2"

let shr_u_vec_i64x2 = shr_u_vec_i64x2 ()

external add_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_add_vec_i64x2"

let add_vec_i64x2 = add_vec_i64x2 ()

external sub_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_sub_vec_i64x2"

let sub_vec_i64x2 = sub_vec_i64x2 ()

external mul_vec_i64x2 : unit -> t = "caml_binaryen_binaryen_mul_vec_i64x2"

let mul_vec_i64x2 = mul_vec_i64x2 ()

external abs_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_abs_vec_f32x4"

let abs_vec_f32x4 = abs_vec_f32x4 ()

external neg_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_neg_vec_f32x4"

let neg_vec_f32x4 = neg_vec_f32x4 ()

external sqrt_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_sqrt_vec_f32x4"

let sqrt_vec_f32x4 = sqrt_vec_f32x4 ()

external add_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_add_vec_f32x4"

let add_vec_f32x4 = add_vec_f32x4 ()

external sub_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_sub_vec_f32x4"

let sub_vec_f32x4 = sub_vec_f32x4 ()

external mul_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_mul_vec_f32x4"

let mul_vec_f32x4 = mul_vec_f32x4 ()

external div_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_div_vec_f32x4"

let div_vec_f32x4 = div_vec_f32x4 ()

external min_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_min_vec_f32x4"

let min_vec_f32x4 = min_vec_f32x4 ()

external max_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_max_vec_f32x4"

let max_vec_f32x4 = max_vec_f32x4 ()

external p_min_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_p_min_vec_f32x4"

let p_min_vec_f32x4 = p_min_vec_f32x4 ()

external p_max_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_p_max_vec_f32x4"

let p_max_vec_f32x4 = p_max_vec_f32x4 ()

external ceil_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_ceil_vec_f32x4"

let ceil_vec_f32x4 = ceil_vec_f32x4 ()

external floor_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_floor_vec_f32x4"

let floor_vec_f32x4 = floor_vec_f32x4 ()

external trunc_vec_f32x4 : unit -> t = "caml_binaryen_binaryen_trunc_vec_f32x4"

let trunc_vec_f32x4 = trunc_vec_f32x4 ()

external nearest_vec_f32x4 : unit -> t
  = "caml_binaryen_binaryen_nearest_vec_f32x4"

let nearest_vec_f32x4 = nearest_vec_f32x4 ()

external abs_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_abs_vec_f64x2"

let abs_vec_f64x2 = abs_vec_f64x2 ()

external neg_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_neg_vec_f64x2"

let neg_vec_f64x2 = neg_vec_f64x2 ()

external sqrt_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_sqrt_vec_f64x2"

let sqrt_vec_f64x2 = sqrt_vec_f64x2 ()

external add_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_add_vec_f64x2"

let add_vec_f64x2 = add_vec_f64x2 ()

external sub_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_sub_vec_f64x2"

let sub_vec_f64x2 = sub_vec_f64x2 ()

external mul_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_mul_vec_f64x2"

let mul_vec_f64x2 = mul_vec_f64x2 ()

external div_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_div_vec_f64x2"

let div_vec_f64x2 = div_vec_f64x2 ()

external min_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_min_vec_f64x2"

let min_vec_f64x2 = min_vec_f64x2 ()

external max_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_max_vec_f64x2"

let max_vec_f64x2 = max_vec_f64x2 ()

external p_min_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_p_min_vec_f64x2"

let p_min_vec_f64x2 = p_min_vec_f64x2 ()

external p_max_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_p_max_vec_f64x2"

let p_max_vec_f64x2 = p_max_vec_f64x2 ()

external ceil_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_ceil_vec_f64x2"

let ceil_vec_f64x2 = ceil_vec_f64x2 ()

external floor_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_floor_vec_f64x2"

let floor_vec_f64x2 = floor_vec_f64x2 ()

external trunc_vec_f64x2 : unit -> t = "caml_binaryen_binaryen_trunc_vec_f64x2"

let trunc_vec_f64x2 = trunc_vec_f64x2 ()

external nearest_vec_f64x2 : unit -> t
  = "caml_binaryen_binaryen_nearest_vec_f64x2"

let nearest_vec_f64x2 = nearest_vec_f64x2 ()

external trunc_sat_s_vec_f32x4_to_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_s_vec_f32x4_to_vec_i32x4"

let trunc_sat_s_vec_f32x4_to_vec_i32x4 = trunc_sat_s_vec_f32x4_to_vec_i32x4 ()

external trunc_sat_u_vec_f32x4_to_vec_i32x4 : unit -> t
  = "caml_binaryen_binaryen_trunc_sat_u_vec_f32x4_to_vec_i32x4"

let trunc_sat_u_vec_f32x4_to_vec_i32x4 = trunc_sat_u_vec_f32x4_to_vec_i32x4 ()

external convert_s_vec_i32x4_to_vec_f32x4 : unit -> t
  = "caml_binaryen_binaryen_convert_s_vec_i32x4_to_vec_f32x4"

let convert_s_vec_i32x4_to_vec_f32x4 = convert_s_vec_i32x4_to_vec_f32x4 ()

external convert_u_vec_i32x4_to_vec_f32x4 : unit -> t
  = "caml_binaryen_binaryen_convert_u_vec_i32x4_to_vec_f32x4"

let convert_u_vec_i32x4_to_vec_f32x4 = convert_u_vec_i32x4_to_vec_f32x4 ()

external narrow_s_vec_i16x8_to_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_narrow_s_vec_i16x8_to_vec_i8x16"

let narrow_s_vec_i16x8_to_vec_i8x16 = narrow_s_vec_i16x8_to_vec_i8x16 ()

external narrow_u_vec_i16x8_to_vec_i8x16 : unit -> t
  = "caml_binaryen_binaryen_narrow_u_vec_i16x8_to_vec_i8x16"

let narrow_u_vec_i16x8_to_vec_i8x16 = narrow_u_vec_i16x8_to_vec_i8x16 ()

external narrow_s_vec_i32x4_to_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_narrow_s_vec_i32x4_to_vec_i16x8"

let narrow_s_vec_i32x4_to_vec_i16x8 = narrow_s_vec_i32x4_to_vec_i16x8 ()

external narrow_u_vec_i32x4_to_vec_i16x8 : unit -> t
  = "caml_binaryen_binaryen_narrow_u_vec_i32x4_to_vec_i16x8"

let narrow_u_vec_i32x4_to_vec_i16x8 = narrow_u_vec_i32x4_to_vec_i16x8 ()

external swizzle_vec8x16 : unit -> t = "caml_binaryen_binaryen_swizzle_vec8x16"

let swizzle_vec8x16 = swizzle_vec8x16 ()
