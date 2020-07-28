type t

type bigstring = (char, Stdlib.Bigarray.int8_unsigned_elt, Stdlib.Bigarray.c_layout) Stdlib.Bigarray.Array1.t

val create : unit -> t

val dispose : t -> unit

val add_custom_section : t -> string -> bigstring -> unit

val parse : string -> t

val print : t -> unit

val print_asmjs : t -> unit

val validate : t -> int

val optimize : t -> unit

val set_features : t -> int list -> unit

val get_optimize_level : unit -> int

val set_optimize_level : int -> unit

val get_shrink_level : unit -> int

val set_shrink_level : int -> unit

val get_debug_info : unit -> int

val set_debug_info : int -> unit

val get_low_memory_unused : unit -> int

val set_low_memory_unused : int -> unit

val get_pass_argument : string -> string

val set_pass_argument : string -> string -> unit

val get_always_inline_max_size : unit -> int

val set_always_inline_max_size : int -> unit

val get_flexible_inline_max_size : unit -> int

val set_flexible_inline_max_size : int -> unit

val get_one_caller_inline_max_size : unit -> int

val set_one_caller_inline_max_size : int -> unit

val run_passes : t -> string list -> unit

val auto_drop : t -> unit

val write : t -> string option -> bigstring * string option

val write_text : t -> string

val read : bigstring -> t

val interpret : t -> unit

val add_debug_info_filename : t -> string -> int

val get_debug_info_filename : t -> int -> string
