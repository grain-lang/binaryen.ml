type t

external ext : unit -> t = "caml_binaryen_heap_type_ext"
external func : unit -> t = "caml_binaryen_heap_type_func"
external any : unit -> t = "caml_binaryen_heap_type_any"
external eq : unit -> t = "caml_binaryen_heap_type_eq"
external i31 : unit -> t = "caml_binaryen_heap_type_i31"
external data : unit -> t = "caml_binaryen_heap_type_data"
external array : unit -> t = "caml_binaryen_heap_type_array"
external string : unit -> t = "caml_binaryen_heap_type_string"
external stringview_wtf8 : unit -> t = "caml_binaryen_heap_type_stringview_wtf8"

external stringview_wtf16 : unit -> t
  = "caml_binaryen_heap_type_stringview_wtf16"

external stringview_iter : unit -> t = "caml_binaryen_heap_type_stringview_iter"
external none : unit -> t = "caml_binaryen_heap_type_none"
external noext : unit -> t = "caml_binaryen_heap_type_noext"
external nofunc : unit -> t = "caml_binaryen_heap_type_nofunc"
