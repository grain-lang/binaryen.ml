type t

external ext : unit -> t = "caml_binaryen_heap_type_ext"
external func : unit -> t = "caml_binaryen_heap_type_func"
external any : unit -> t = "caml_binaryen_heap_type_any"
external eq : unit -> t = "caml_binaryen_heap_type_eq"
external i31 : unit -> t = "caml_binaryen_heap_type_i31"
external struct_ : unit -> t = "caml_binaryen_heap_type_struct"
external array : unit -> t = "caml_binaryen_heap_type_array"
external string : unit -> t = "caml_binaryen_heap_type_string"
external stringview_wtf8 : unit -> t = "caml_binaryen_heap_type_stringview_wtf8"

external stringview_wtf16 : unit -> t
  = "caml_binaryen_heap_type_stringview_wtf16"

external stringview_iter : unit -> t = "caml_binaryen_heap_type_stringview_iter"
external none : unit -> t = "caml_binaryen_heap_type_none"
external noext : unit -> t = "caml_binaryen_heap_type_noext"
external nofunc : unit -> t = "caml_binaryen_heap_type_nofunc"
external is_basic : t -> bool = "caml_binaryen_heap_type_is_basic"
external is_signature : t -> bool = "caml_binaryen_heap_type_is_signature"
external is_struct : t -> bool = "caml_binaryen_heap_type_is_struct"
external is_array : t -> bool = "caml_binaryen_heap_type_is_array"
external is_bottom : t -> bool = "caml_binaryen_heap_type_is_bottom"
external get_bottom : t -> t = "caml_binaryen_heap_type_get_bottom"
external is_sub_type : t -> bool = "caml_binaryen_heap_type_is_sub_type"
