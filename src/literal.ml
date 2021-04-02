type t

external int32 : int32 -> t = "caml_binaryen_literal_int32"

external int64 : int64 -> t = "caml_binaryen_literal_int64"

external float32_bits : int32 -> t = "caml_binaryen_literal_float32_bits"

external float64_bits : int64 -> t = "caml_binaryen_literal_float64_bits"

let float32 n = float32_bits @@ Int32.bits_of_float n

external float64 : float -> t = "caml_binaryen_literal_float64"

(* Hacks for Binaryen.js stack allocations, Don't use in binaryen.native *)
type jsoo =
  | Int32 of int32
  | Int64 of int32 * int32
  | Float32Bits of int32
  | Float64Bits of int32 * int32
  | Float32 of float
  | Float64 of float

exception Invalid_usage

let to_jsoo _ = raise Invalid_usage
