type t

external int32 : int32 -> t = "caml_binaryen_literal_int32"
external int64 : int64 -> t = "caml_binaryen_literal_int64"
external float32_bits : int32 -> t = "caml_binaryen_literal_float32_bits"
external float64_bits : int64 -> t = "caml_binaryen_literal_float64_bits"
external vec128 : Bytes.t -> t = "caml_binaryen_literal_vec128"

let float32 n = float32_bits @@ Int32.bits_of_float n

external float64 : float -> t = "caml_binaryen_literal_float64"
