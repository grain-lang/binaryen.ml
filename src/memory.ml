(** Module, initial size, maximum size, export name, segment names, segment passive, segment offsets, segment sizes, shared. *)
external set_memory : Module.t -> int -> int -> string -> string list -> bool list -> Expression.t list -> int list -> bool -> unit =
  "caml_binaryen_set_memory__bytecode" "caml_binaryen_set_memory"
