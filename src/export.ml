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

external get_export : Module.t -> string -> t = "caml_binaryen_get_export"

external remove_export : Module.t -> string -> unit
  = "caml_binaryen_remove_export"
(** Module, external name. *)

external get_num_exports : Module.t -> int = "caml_binaryen_get_num_exports"

external get_export_by_index : Module.t -> int -> t
  = "caml_binaryen_get_export_by_index"

external get_name : t -> string = "caml_binaryen_export_get_name"

external get_value : t -> string = "caml_binaryen_export_get_value"

external get_name : t -> string = "caml_binaryen_export_get_name"

external get_value : t -> string = "caml_binaryen_export_get_value"
