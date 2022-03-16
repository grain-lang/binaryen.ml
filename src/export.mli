type t

val add_function_export : Module.t -> string -> string -> t
val add_table_export : Module.t -> string -> string -> t
val add_memory_export : Module.t -> string -> string -> t
val add_global_export : Module.t -> string -> string -> t
val get_export : Module.t -> string -> t
val remove_export : Module.t -> string -> unit
val get_num_exports : Module.t -> int
val get_export_by_index : Module.t -> int -> t
val get_name : t -> string
val get_value : t -> string
val external_function : int
val external_table : int
val external_memory : int
val external_global : int
val external_tag : int
val export_get_kind : t -> int
