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

external anyref : unit -> t = "caml_binaryen_type_anyref"

let anyref = anyref ()

external eqref : unit -> t = "caml_binaryen_type_eqref"

let eqref = eqref ()

external i31ref : unit -> t = "caml_binaryen_type_i31ref"

let i31ref = i31ref ()

external dataref : unit -> t = "caml_binaryen_type_dataref"

let dataref = dataref ()

external arrayref : unit -> t = "caml_binaryen_type_arrayref"

let arrayref = arrayref ()

external stringref : unit -> t = "caml_binaryen_type_stringref"

let stringref = stringref ()

external stringview_wtf8 : unit -> t = "caml_binaryen_type_stringview_wtf8"

let stringview_wtf8 = stringview_wtf8 ()

external stringview_wtf16 : unit -> t = "caml_binaryen_type_stringview_wtf16"

let stringview_wtf16 = stringview_wtf16 ()

external stringview_iter : unit -> t = "caml_binaryen_type_stringview_iter"

let stringview_iter = stringview_iter ()

external nullref : unit -> t = "caml_binaryen_type_nullref"

let nullref = nullref ()

external null_externref : unit -> t = "caml_binaryen_type_null_externref"

let null_externref = null_externref ()

external null_funcref : unit -> t = "caml_binaryen_type_null_funcref"

let null_funcref = null_funcref ()

external unreachable : unit -> t = "caml_binaryen_type_unreachable"

let unreachable = unreachable ()

external auto : unit -> t = "caml_binaryen_type_auto"

let auto = auto ()

external create : t array -> t = "caml_binaryen_type_create"
external expand : t -> t array = "caml_binaryen_type_expand"
external is_nullable : t -> bool = "caml_binaryen_type_is_nullable"
external from_heap_type : Heap_type.t -> t = "caml_binaryen_type_from_heap_type"
external get_heap_type : t -> Heap_type.t = "caml_binaryen_type_get_heap_type"
