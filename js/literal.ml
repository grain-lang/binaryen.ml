(* This is a hack around Binaryen's stack allocations *)
type jsoo =
  | Int32 of int32
  | Int64 of int32 * int32
  | Float32Bits of int32
  | Float64Bits of int32 * int32
  | Float32 of float
  | Float64 of float

type t = jsoo

let int32 value = Int32 value

let int64 value =
  Int64
    (Int64.to_int32 value, Int64.to_int32 (Int64.shift_right_logical value 32))

let float32_bits value = Float32Bits value

let float64_bits value =
  Float64Bits
    (Int64.to_int32 value, Int64.to_int32 (Int64.shift_right_logical value 32))

let float32 value = Float32 value

let float64 value = Float64 value

(* This makes our `t` public so we can match on it *)
let to_jsoo lit = lit
