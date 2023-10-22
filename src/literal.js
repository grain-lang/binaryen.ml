//Provides: caml_binaryen_literal_int32
function caml_binaryen_literal_int32(i32) {
  // Hack around Binaryen.js
  return { type: 'int32', value: i32 };
}

//Provides: caml_binaryen_literal_int64
function caml_binaryen_literal_int64(i64) {
  // Hack around Binaryen.js
  return { type: 'int64', value: i64 };
}

//Provides: caml_binaryen_literal_float64
function caml_binaryen_literal_float64(f64) {
  // Hack around Binaryen.js
  return { type: 'float64', value: f64 };
}

//Provides: caml_binaryen_literal_float32_bits
function caml_binaryen_literal_float32_bits(i32) {
  // Hack around Binaryen.js
  return { type: 'float32_bits', value: i32 };
}

//Provides: caml_binaryen_literal_float64_bits
function caml_binaryen_literal_float64_bits(i64) {
  // Hack around Binaryen.js
  return { type: 'float64_bits', value: i64 };
}

//Provides: caml_binaryen_literal_vec128
function caml_binaryen_literal_vec128(x) {
  // Hack around Binaryen.js
  return { type: 'vec_128', value: x };
}
