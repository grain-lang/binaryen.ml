type t

type element_segment

external add_table : Module.t -> string -> int -> int -> t
  = "caml_binaryen_add_table"
(** Module, name, initial size, maximum size. *)

external add_active_element_segment :
  Module.t -> string -> string -> string list -> Expression.t -> element_segment
  = "caml_binaryen_add_active_element_segment"
(** Module, table, name, function names, offset. *)
