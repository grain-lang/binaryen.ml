type t

module Feature : sig
  type t

  val mvp : t

  val atomics : t

  val bulk_memory : t

  val mutable_globals : t

  val nontrapping_fp_to_int : t

  val sign_ext : t

  val simd128 : t

  val exception_handling : t

  val tail_call : t

  val reference_types : t

  val multivalue : t

  val all : t
end

val create : unit -> t

val dispose : t -> unit

val add_custom_section : t -> string -> string -> unit

val parse : string -> t

val print : t -> unit

val print_asmjs : t -> unit

val validate : t -> int

val optimize : t -> unit

val get_features : t -> Feature.t list

val set_features : t -> Feature.t list -> unit

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

val write : t -> string option -> bytes * string option

val write_text : t -> string

val read : bytes -> t

val interpret : t -> unit

val add_debug_info_filename : t -> string -> int

val get_debug_info_filename : t -> int -> string
