type t

val int32 : int32 -> t
val int64 : int64 -> t
val float32_bits : int32 -> t
val float64_bits : int64 -> t
val float32 : float -> t
val float64 : float -> t
val vec128 : Bytes.t -> t
