type t


external none : unit -> t = "caml_binaryen_type_none"
let none = none ()

external int32 : unit -> t = "caml_binaryen_type_int32"
let int32 = int32 ()

external int64 : unit -> t = "caml_binaryen_type_int64"
let int64 = int64 ()

external float32 : unit -> t = "caml_binaryen_type_float32"
let float32 = float32 ()

external float64 : unit -> t = "caml_binaryen_type_float64"
let float64 = float64 ()

external vec128 : unit -> t = "caml_binaryen_type_vec128"
let vec128 = vec128 ()

external funcref : unit -> t = "caml_binaryen_type_funcref"
let funcref = funcref ()

external externref : unit -> t = "caml_binaryen_type_externref"
let externref = externref ()

external nullref : unit -> t = "caml_binaryen_type_nullref"
let nullref = nullref ()

external exnref : unit -> t = "caml_binaryen_type_exnref"
let exnref = exnref ()

external unreachable : unit -> t = "caml_binaryen_type_unreachable"
let unreachable = unreachable ()

external auto : unit -> t = "caml_binaryen_type_auto"
let auto = auto ()

external create : t array -> t = "caml_binaryen_type_create"
