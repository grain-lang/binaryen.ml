type t

external int32 : int32 -> t = "caml_binaryen_literal_int32"
external int64 : int64 -> t = "caml_binaryen_literal_int64"
external float32_bits : int32 -> t = "caml_binaryen_literal_float32_bits"
external float64_bits : int64 -> t = "caml_binaryen_literal_float64_bits"

let float32 n = float32_bits @@ Int32.bits_of_float n

external float64 : float -> t = "caml_binaryen_literal_float64"
external vec128 : int array -> t = "caml_binaryen_literal_vec128"

let vec128 (low, low_mid, high_mid, high) =
  let bytes = Bytes.create 16 in
  Bytes.set_int32_le bytes 0 low;
  Bytes.set_int32_le bytes 4 low_mid;
  Bytes.set_int32_le bytes 8 high_mid;
  Bytes.set_int32_le bytes 12 high;
  let arr = Array.init 16 (Bytes.get_uint8 bytes) in
  vec128 arr
