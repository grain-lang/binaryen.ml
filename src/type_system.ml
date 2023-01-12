type t = int

external equirecursive : unit -> t = "caml_binaryen_type_system_equirecursive"
external nominal : unit -> t = "caml_binaryen_type_system_nominal"
external isorecursive : unit -> t = "caml_binaryen_type_system_isorecursive"
external get_type_system : unit -> t = "caml_binaryen_get_type_system"
external set_type_system : t -> unit = "caml_binaryen_set_type_system"
