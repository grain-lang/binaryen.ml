type t

external add_function_export : Module.t -> string -> string -> t
  = "caml_binaryen_add_function_export"
(** Module, internal name, external name. *)

external add_table_export : Module.t -> string -> string -> t
  = "caml_binaryen_add_table_export"
(** Module, internal name, external name. *)

external add_memory_export : Module.t -> string -> string -> t
  = "caml_binaryen_add_memory_export"
(** Module, internal name, external name. *)

external add_global_export : Module.t -> string -> string -> t
  = "caml_binaryen_add_global_export"
(** Module, internal name, external name. *)

external remove_export : Module.t -> string -> unit
  = "caml_binaryen_remove_export"
(** Module, external name. *)
