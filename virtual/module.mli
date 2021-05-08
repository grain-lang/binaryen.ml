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

val run_passes : t -> string list -> unit

val auto_drop : t -> unit

val write : t -> string option -> bytes * string option

val write_text : t -> string

val read : bytes -> t

val interpret : t -> unit

val add_debug_info_filename : t -> string -> int

val get_debug_info_filename : t -> int -> string
