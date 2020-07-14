type t
external block : Module.t -> string -> t list -> t
  = "caml_binaryen_block"
external if_ : Module.t -> t -> t -> t -> t = "caml_binaryen_if"
external loop : Module.t -> string -> t -> t = "caml_binaryen_loop"
external break : Module.t -> string -> t -> t -> t
  = "caml_binaryen_break"
external switch : Module.t -> string list -> string -> t -> t -> t
  = "caml_binaryen_switch"
external call : Module.t -> string -> t list -> Type.t -> t
  = "caml_binaryen_call"
external call_indirect :
  Module.t -> t -> t list -> Type.t -> Type.t -> t
  = "caml_binaryen_call_indirect"
external return_call :
  Module.t -> string -> t list -> Type.t -> t
  = "caml_binaryen_return_call"
external return_call_indirect :
  Module.t -> t -> t list -> Type.t -> Type.t -> t
  = "caml_binaryen_return_call_indirect"
external local_get : Module.t -> int -> Type.t -> t
  = "caml_binaryen_local_get"
external local_set : Module.t -> int -> t -> t
  = "caml_binaryen_local_set"
external local_tee : Module.t -> int -> t -> Type.t -> t
  = "caml_binaryen_local_tee"
external global_get : Module.t -> string -> Type.t -> t
  = "caml_binaryen_global_get"
external global_set : Module.t -> string -> t -> t
  = "caml_binaryen_global_set"
external load :
  Module.t -> int -> int -> int -> Type.t -> t -> t
  = "caml_binaryen_load__bytecode" "caml_binaryen_load"
external store :
  Module.t -> int -> int -> int -> t -> t -> Type.t -> t
  = "caml_binaryen_store__bytecode" "caml_binaryen_store"
external const : Module.t -> Literal.t -> t
  = "caml_binaryen_const"
external unary : Module.t -> Op.t -> t -> t
  = "caml_binaryen_unary"
external binary : Module.t -> Op.t -> t -> t -> t
  = "caml_binaryen_binary"
external select : Module.t -> t -> t -> t -> t
  = "caml_binaryen_select"
external drop : Module.t -> t -> t = "caml_binaryen_drop"
external return : Module.t -> t -> t = "caml_binaryen_return"
external nop : Module.t -> t = "caml_binaryen_nop"
external unreachable : Module.t -> t = "caml_binaryen_unreachable"
external memory_copy : Module.t -> t -> t -> t -> t
  = "caml_binaryen_memory_copy"
external memory_fill : Module.t -> t -> t -> t -> t
  = "caml_binaryen_memory_fill"
external tuple_make : Module.t -> t list -> t
  = "caml_binaryen_tuple_make"
external tuple_extract : Module.t -> t -> int -> t
  = "caml_binaryen_tuple_extract"
external pop : Module.t -> Type.t -> t
  = "caml_binaryen_pop"
external null : unit -> t = "caml_binaryen_null_expression"
external print : t -> unit = "caml_binaryen_expression_print"
