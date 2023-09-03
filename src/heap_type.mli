type t

val ext : unit -> t
val func : unit -> t
val any : unit -> t
val eq : unit -> t
val i31 : unit -> t
val struct_ : unit -> t
val array : unit -> t
val string : unit -> t
val stringview_wtf8 : unit -> t
val stringview_wtf16 : unit -> t
val stringview_iter : unit -> t
val none : unit -> t
val noext : unit -> t
val nofunc : unit -> t
val is_basic : t -> bool
val is_signature : t -> bool
val is_struct : t -> bool
val is_array : t -> bool
val is_bottom : t -> bool
val get_bottom : t -> t
val is_sub_type : t -> bool
