type t

external block : Module.t -> string -> t list -> Type.t -> t = "caml_binaryen_block"
let block ?(return_type=Type.auto) wasm_mod name exprs =
  block wasm_mod name exprs return_type
(** Module, block name, expression list. *)

external if_ : Module.t -> t -> t -> t -> t = "caml_binaryen_if"
(** Module, condition, true branch, false branch. False branch may be null. *)

external loop : Module.t -> string -> t -> t = "caml_binaryen_loop"
(** Module, loop name, body. *)

external break : Module.t -> string -> t -> t -> t = "caml_binaryen_break"
(** Module, block name, condition, result. Value and condition may be null. *)

external switch : Module.t -> string list -> string -> t -> t -> t
  = "caml_binaryen_switch"
(** Module, branch names, default branch name, condition, value. Value may be null. *)

external call : Module.t -> string -> t list -> Type.t -> t
  = "caml_binaryen_call"
(** Module, function name, params, return type. *)

external call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t
  = "caml_binaryen_call_indirect"
(** Module, function value, params, params type, return type. *)

external return_call : Module.t -> string -> t list -> Type.t -> t
  = "caml_binaryen_return_call"
(** Module, function name, params, return type. *)

external return_call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t
  = "caml_binaryen_return_call_indirect"
(** Module, function value, params, params type, return type. *)

external local_get : Module.t -> int -> Type.t -> t = "caml_binaryen_local_get"
(** Module, slot, type. *)

external local_set : Module.t -> int -> t -> t = "caml_binaryen_local_set"
(** Module, slot, value. *)

external local_tee : Module.t -> int -> t -> Type.t -> t
  = "caml_binaryen_local_tee"
(** Module, slot, value, type. *)

external global_get : Module.t -> string -> Type.t -> t
  = "caml_binaryen_global_get"
(** Module, name, type. *)

external global_set : Module.t -> string -> t -> t = "caml_binaryen_global_set"
(** Module, name, value. *)

external load : Module.t -> int -> bool -> int -> int -> Type.t -> t -> t
  = "caml_binaryen_load__bytecode" "caml_binaryen_load"
let load wasm_mod bytes ?(signed=false) offset align ty ptr =
  load wasm_mod bytes signed offset align ty ptr
(** Module, num_bytes, ?signed, offset, align, type, ptr. *)

external store : Module.t -> int -> int -> int -> t -> t -> Type.t -> t
  = "caml_binaryen_store__bytecode" "caml_binaryen_store"
(** Module, num_bytes, offset, align, ptr, value, type. *)

external const : Module.t -> Literal.t -> t = "caml_binaryen_const"

external unary : Module.t -> Op.t -> t -> t = "caml_binaryen_unary"

external binary : Module.t -> Op.t -> t -> t -> t = "caml_binaryen_binary"

external select : Module.t -> t -> t -> t -> Type.t -> t = "caml_binaryen_select"
let select wasm_mod cond tru fals =
  select wasm_mod cond tru fals Type.auto
(** Module, condition, true branch, false branch. *)

external drop : Module.t -> t -> t = "caml_binaryen_drop"

external return : Module.t -> t -> t = "caml_binaryen_return"

external memory_size : Module.t -> t = "caml_binaryen_memory_size"

external memory_grow : Module.t -> t -> t = "caml_binaryen_memory_grow"

external nop : Module.t -> t = "caml_binaryen_nop"

external unreachable : Module.t -> t = "caml_binaryen_unreachable"

external memory_copy : Module.t -> t -> t -> t -> t
  = "caml_binaryen_memory_copy"
(** Module, destination, source, size. *)

external memory_fill : Module.t -> t -> t -> t -> t
  = "caml_binaryen_memory_fill"
(** Module, destination, value, size. *)

external tuple_make : Module.t -> t list -> t = "caml_binaryen_tuple_make"
(** Module, items *)

external tuple_extract : Module.t -> t -> int -> t
  = "caml_binaryen_tuple_extract"
(** Module, tuple, index *)

external pop : Module.t -> Type.t -> t = "caml_binaryen_pop"
(** Module, type *)

external null : unit -> t = "caml_binaryen_null_expression"
(** A null reference. *)

external print : t -> unit = "caml_binaryen_expression_print"
(** Print an expression to the console. *)
