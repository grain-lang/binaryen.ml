external add_table :
  Module.t -> string -> int -> int -> string list -> Expression.t -> unit
  = "caml_binaryen_add_table__bytecode" "caml_binaryen_add_table"
(** Module, name, initial size, maximum size, function names, offset. *)
