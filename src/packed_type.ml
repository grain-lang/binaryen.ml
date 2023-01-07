type t = int

external not_packed : unit -> t = "caml_binaryen_packed_type_not_packed"

let not_packed = not_packed ()

external int8 : unit -> t = "caml_binaryen_packed_type_int8"

let int8 = int8 ()

external int16 : unit -> t = "caml_binaryen_packed_type_int16"

let int16 = int16 ()
