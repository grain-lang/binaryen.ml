type t

val int32 : int32 -> t
val int64 : int64 -> t
val float32_bits : int32 -> t
val float64_bits : int64 -> t
val float32 : float -> t
val float64 : float -> t

(* Hacks for Binaryen.js stack allocations *)
type jsoo =
  | Int32 of int32
  | Int64 of int32 * int32
  | Float32Bits of int32
  | Float64Bits of int32 * int32
  | Float32 of float
  | Float64 of float

val to_jsoo : t -> jsoo
