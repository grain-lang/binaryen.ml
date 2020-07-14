type t
val none : t
val int32 : t
val int64 : t
val float32 : t
val float64 : t
val vec128 : t
val funcref : t
val externref : t
val nullref : t
val exnref : t
val unreachable : t
val auto : t
external create : t array -> t = "caml_binaryen_type_create"
