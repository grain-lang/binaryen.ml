type t
external int32 : int32 -> t = "caml_binaryen_literal_int32"
external int64 : int64 -> t = "caml_binaryen_literal_int64"
external float32_bits : int32 -> t = "caml_binaryen_literal_float32_bits"
external float64_bits : int64 -> t = "caml_binaryen_literal_float64_bits"
val float32 : float -> t
external float64 : float -> t = "caml_binaryen_literal_float64"
