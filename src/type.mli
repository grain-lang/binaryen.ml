type t

val none : t
val int32 : t
val int64 : t
val float32 : t
val float64 : t
val vec128 : t
val funcref : t
val anyref : t
val eqref : t
val i31ref : t
val dataref : t
val stringref : t
val stringview_wtf8 : t
val stringview_wtf16 : t
val stringview_iter : t
val unreachable : t
val auto : t
val create : t array -> t
val expand : t -> t array
val is_nullable : t -> bool
val from_heap_type : Heap_type.t -> t
val get_heap_type : t -> Heap_type.t
