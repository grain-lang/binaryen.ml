type t

val clz_int32 : t

val ctz_int32 : t

val popcnt_int32 : t

val neg_float32 : t

val abs_float32 : t

val ceil_float32 : t

val floor_float32 : t

val trunc_float32 : t

val nearest_float32 : t

val sqrt_float32 : t

val eq_z_int32 : t

val clz_int64 : t

val ctz_int64 : t

val popcnt_int64 : t

val neg_float64 : t

val abs_float64 : t

val ceil_float64 : t

val floor_float64 : t

val trunc_float64 : t

val nearest_float64 : t

val sqrt_float64 : t

val eq_z_int64 : t

val extend_s_int32 : t

val extend_u_int32 : t

val wrap_int64 : t

val trunc_s_float32_to_int32 : t

val trunc_s_float32_to_int64 : t

val trunc_u_float32_to_int32 : t

val trunc_u_float32_to_int64 : t

val trunc_s_float64_to_int32 : t

val trunc_s_float64_to_int64 : t

val trunc_u_float64_to_int32 : t

val trunc_u_float64_to_int64 : t

val reinterpret_float32 : t

val reinterpret_float64 : t

val convert_s_int32_to_float32 : t

val convert_s_int32_to_float64 : t

val convert_u_int32_to_float32 : t

val convert_u_int32_to_float64 : t

val convert_s_int64_to_float32 : t

val convert_s_int64_to_float64 : t

val convert_u_int64_to_float32 : t

val convert_u_int64_to_float64 : t

val promote_float32 : t

val demote_float64 : t

val reinterpret_int32 : t

val reinterpret_int64 : t

val extend_s8_int32 : t

val extend_s16_int32 : t

val extend_s8_int64 : t

val extend_s16_int64 : t

val extend_s32_int64 : t

val add_int32 : t

val sub_int32 : t

val mul_int32 : t

val div_s_int32 : t

val div_u_int32 : t

val rem_s_int32 : t

val rem_u_int32 : t

val and_int32 : t

val or_int32 : t

val xor_int32 : t

val shl_int32 : t

val shr_u_int32 : t

val shr_s_int32 : t

val rot_l_int32 : t

val rot_r_int32 : t

val eq_int32 : t

val ne_int32 : t

val lt_s_int32 : t

val lt_u_int32 : t

val le_s_int32 : t

val le_u_int32 : t

val gt_s_int32 : t

val gt_u_int32 : t

val ge_s_int32 : t

val ge_u_int32 : t

val add_int64 : t

val sub_int64 : t

val mul_int64 : t

val div_s_int64 : t

val div_u_int64 : t

val rem_s_int64 : t

val rem_u_int64 : t

val and_int64 : t

val or_int64 : t

val xor_int64 : t

val shl_int64 : t

val shr_u_int64 : t

val shr_s_int64 : t

val rot_l_int64 : t

val rot_r_int64 : t

val eq_int64 : t

val ne_int64 : t

val lt_s_int64 : t

val lt_u_int64 : t

val le_s_int64 : t

val le_u_int64 : t

val gt_s_int64 : t

val gt_u_int64 : t

val ge_s_int64 : t

val ge_u_int64 : t

val add_float32 : t

val sub_float32 : t

val mul_float32 : t

val div_float32 : t

val copy_sign_float32 : t

val min_float32 : t

val max_float32 : t

val eq_float32 : t

val ne_float32 : t

val lt_float32 : t

val le_float32 : t

val gt_float32 : t

val ge_float32 : t

val add_float64 : t

val sub_float64 : t

val mul_float64 : t

val div_float64 : t

val copy_sign_float64 : t

val min_float64 : t

val max_float64 : t

val eq_float64 : t

val ne_float64 : t

val lt_float64 : t

val le_float64 : t

val gt_float64 : t

val ge_float64 : t

val atomic_rmw_add : t

val atomic_rmw_sub : t

val atomic_rmw_and : t

val atomic_rmw_or : t

val atomic_rmw_xor : t

val atomic_rmw_xchg : t

val trunc_sat_s_float32_to_int32 : t

val trunc_sat_s_float32_to_int64 : t

val trunc_sat_u_float32_to_int32 : t

val trunc_sat_u_float32_to_int64 : t

val trunc_sat_s_float64_to_int32 : t

val trunc_sat_s_float64_to_int64 : t

val trunc_sat_u_float64_to_int32 : t

val trunc_sat_u_float64_to_int64 : t

val splat_vec_i8x16 : t

val extract_lane_s_vec_i8x16 : t

val extract_lane_u_vec_i8x16 : t

val replace_lane_vec_i8x16 : t

val splat_vec_i16x8 : t

val extract_lane_s_vec_i16x8 : t

val extract_lane_u_vec_i16x8 : t

val replace_lane_vec_i16x8 : t

val splat_vec_i32x4 : t

val extract_lane_vec_i32x4 : t

val replace_lane_vec_i32x4 : t

val splat_vec_i64x2 : t

val extract_lane_vec_i64x2 : t

val replace_lane_vec_i64x2 : t

val splat_vec_f32x4 : t

val extract_lane_vec_f32x4 : t

val replace_lane_vec_f32x4 : t

val splat_vec_f64x2 : t

val extract_lane_vec_f64x2 : t

val replace_lane_vec_f64x2 : t

val eq_vec_i8x16 : t

val ne_vec_i8x16 : t

val lt_s_vec_i8x16 : t

val lt_u_vec_i8x16 : t

val gt_s_vec_i8x16 : t

val gt_u_vec_i8x16 : t

val le_s_vec_i8x16 : t

val le_u_vec_i8x16 : t

val ge_s_vec_i8x16 : t

val ge_u_vec_i8x16 : t

val eq_vec_i16x8 : t

val ne_vec_i16x8 : t

val lt_s_vec_i16x8 : t

val lt_u_vec_i16x8 : t

val gt_s_vec_i16x8 : t

val gt_u_vec_i16x8 : t

val le_s_vec_i16x8 : t

val le_u_vec_i16x8 : t

val ge_s_vec_i16x8 : t

val ge_u_vec_i16x8 : t

val eq_vec_i32x4 : t

val ne_vec_i32x4 : t

val lt_s_vec_i32x4 : t

val lt_u_vec_i32x4 : t

val gt_s_vec_i32x4 : t

val gt_u_vec_i32x4 : t

val le_s_vec_i32x4 : t

val le_u_vec_i32x4 : t

val ge_s_vec_i32x4 : t

val ge_u_vec_i32x4 : t

val eq_vec_f32x4 : t

val ne_vec_f32x4 : t

val lt_vec_f32x4 : t

val gt_vec_f32x4 : t

val le_vec_f32x4 : t

val ge_vec_f32x4 : t

val eq_vec_f64x2 : t

val ne_vec_f64x2 : t

val lt_vec_f64x2 : t

val gt_vec_f64x2 : t

val le_vec_f64x2 : t

val ge_vec_f64x2 : t

val not_vec128 : t

val and_vec128 : t

val or_vec128 : t

val xor_vec128 : t

val and_not_vec128 : t

val bitselect_vec128 : t

val abs_vec_i8x16 : t

val neg_vec_i8x16 : t

val any_true_vec_i8x16 : t

val all_true_vec_i8x16 : t

val bitmask_vec_i8x16 : t

val shl_vec_i8x16 : t

val shr_s_vec_i8x16 : t

val shr_u_vec_i8x16 : t

val add_vec_i8x16 : t

val add_sat_s_vec_i8x16 : t

val add_sat_u_vec_i8x16 : t

val sub_vec_i8x16 : t

val sub_sat_s_vec_i8x16 : t

val sub_sat_u_vec_i8x16 : t

val mul_vec_i8x16 : t

val min_s_vec_i8x16 : t

val min_u_vec_i8x16 : t

val max_s_vec_i8x16 : t

val max_u_vec_i8x16 : t

val avgr_u_vec_i8x16 : t

val abs_vec_i16x8 : t

val neg_vec_i16x8 : t

val any_true_vec_i16x8 : t

val all_true_vec_i16x8 : t

val bitmask_vec_i16x8 : t

val shl_vec_i16x8 : t

val shr_s_vec_i16x8 : t

val shr_u_vec_i16x8 : t

val add_vec_i16x8 : t

val add_sat_s_vec_i16x8 : t

val add_sat_u_vec_i16x8 : t

val sub_vec_i16x8 : t

val sub_sat_s_vec_i16x8 : t

val sub_sat_u_vec_i16x8 : t

val mul_vec_i16x8 : t

val min_s_vec_i16x8 : t

val min_u_vec_i16x8 : t

val max_s_vec_i16x8 : t

val max_u_vec_i16x8 : t

val avgr_u_vec_i16x8 : t

val abs_vec_i32x4 : t

val neg_vec_i32x4 : t

val any_true_vec_i32x4 : t

val all_true_vec_i32x4 : t

val bitmask_vec_i32x4 : t

val shl_vec_i32x4 : t

val shr_s_vec_i32x4 : t

val shr_u_vec_i32x4 : t

val add_vec_i32x4 : t

val sub_vec_i32x4 : t

val mul_vec_i32x4 : t

val min_s_vec_i32x4 : t

val min_u_vec_i32x4 : t

val max_s_vec_i32x4 : t

val max_u_vec_i32x4 : t

val dot_s_vec_i16x8_to_vec_i32x4 : t

val neg_vec_i64x2 : t

val any_true_vec_i64x2 : t

val all_true_vec_i64x2 : t

val shl_vec_i64x2 : t

val shr_s_vec_i64x2 : t

val shr_u_vec_i64x2 : t

val add_vec_i64x2 : t

val sub_vec_i64x2 : t

val mul_vec_i64x2 : t

val abs_vec_f32x4 : t

val neg_vec_f32x4 : t

val sqrt_vec_f32x4 : t

val qfma_vec_f32x4 : t

val qfms_vec_f32x4 : t

val add_vec_f32x4 : t

val sub_vec_f32x4 : t

val mul_vec_f32x4 : t

val div_vec_f32x4 : t

val min_vec_f32x4 : t

val max_vec_f32x4 : t

val p_min_vec_f32x4 : t

val p_max_vec_f32x4 : t

val ceil_vec_f32x4 : t

val floor_vec_f32x4 : t

val trunc_vec_f32x4 : t

val nearest_vec_f32x4 : t

val abs_vec_f64x2 : t

val neg_vec_f64x2 : t

val sqrt_vec_f64x2 : t

val qfma_vec_f64x2 : t

val qfms_vec_f64x2 : t

val add_vec_f64x2 : t

val sub_vec_f64x2 : t

val mul_vec_f64x2 : t

val div_vec_f64x2 : t

val min_vec_f64x2 : t

val max_vec_f64x2 : t

val p_min_vec_f64x2 : t

val p_max_vec_f64x2 : t

val ceil_vec_f64x2 : t

val floor_vec_f64x2 : t

val trunc_vec_f64x2 : t

val nearest_vec_f64x2 : t

val trunc_sat_s_vec_f32x4_to_vec_i32x4 : t

val trunc_sat_u_vec_f32x4_to_vec_i32x4 : t

val trunc_sat_s_vec_f64x2_to_vec_i64x2 : t

val trunc_sat_u_vec_f64x2_to_vec_i64x2 : t

val convert_s_vec_i32x4_to_vec_f32x4 : t

val convert_u_vec_i32x4_to_vec_f32x4 : t

val convert_s_vec_i64x2_to_vec_f64x2 : t

val convert_u_vec_i64x2_to_vec_f64x2 : t

val load_splat_vec8x16 : t

val load_splat_vec16x8 : t

val load_splat_vec32x4 : t

val load_splat_vec64x2 : t

val load_ext_s_vec8x8_to_vec_i16x8 : t

val load_ext_u_vec8x8_to_vec_i16x8 : t

val load_ext_s_vec16x4_to_vec_i32x4 : t

val load_ext_u_vec16x4_to_vec_i32x4 : t

val load_ext_s_vec32x2_to_vec_i64x2 : t

val load_ext_u_vec32x2_to_vec_i64x2 : t

val narrow_s_vec_i16x8_to_vec_i8x16 : t

val narrow_u_vec_i16x8_to_vec_i8x16 : t

val narrow_s_vec_i32x4_to_vec_i16x8 : t

val narrow_u_vec_i32x4_to_vec_i16x8 : t

val widen_low_s_vec_i8x16_to_vec_i16x8 : t

val widen_high_s_vec_i8x16_to_vec_i16x8 : t

val widen_low_u_vec_i8x16_to_vec_i16x8 : t

val widen_high_u_vec_i8x16_to_vec_i16x8 : t

val widen_low_s_vec_i16x8_to_vec_i32x4 : t

val widen_high_s_vec_i16x8_to_vec_i32x4 : t

val widen_low_u_vec_i16x8_to_vec_i32x4 : t

val widen_high_u_vec_i16x8_to_vec_i32x4 : t

val swizzle_vec8x16 : t
