type t

(** Module, block name, expression list. *)
external block : Module.t -> string -> t list -> t = "caml_binaryen_block"

(** Module, condition, true branch, false branch. False branch may be null. *)
external if_ : Module.t -> t -> t -> t -> t = "caml_binaryen_if"

(** Module, loop name, body. *)
external loop : Module.t -> string -> t -> t = "caml_binaryen_loop"

(** Module, block name, condition, result. Value and condition may be null. *)
external break : Module.t -> string -> t -> t -> t = "caml_binaryen_break"

(** Module, branch names, default branch name, condition, value. Value may be null. *)
external switch : Module.t -> string list -> string -> t -> t -> t = "caml_binaryen_switch"

(** Module, function name, params, return type. *)
external call : Module.t -> string -> t list -> Type.t -> t = "caml_binaryen_call"

(** Module, function value, params, params type, return type. *)
external call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t = "caml_binaryen_call_indirect"

(** Module, function name, params, return type. *)
external return_call : Module.t -> string -> t list -> Type.t -> t = "caml_binaryen_return_call"

(** Module, function value, params, params type, return type. *)
external return_call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t = "caml_binaryen_return_call_indirect"

(** Module, slot, type. *)
external local_get : Module.t -> int -> Type.t -> t = "caml_binaryen_local_get"

(** Module, slot, value. *)
external local_set : Module.t -> int -> t -> t = "caml_binaryen_local_set"

(** Module, slot, value, type. *)
external local_tee : Module.t -> int -> t -> Type.t -> t = "caml_binaryen_local_tee"

(** Module, name, type. *)
external global_get : Module.t -> string -> Type.t -> t = "caml_binaryen_global_get"

(** Module, name, value. *)
external global_set : Module.t -> string -> t -> t = "caml_binaryen_global_set"

(** Module, num_bytes, offset, align, type, ptr. *)
external load : Module.t -> int -> int -> int -> Type.t -> t -> t = "caml_binaryen_load__bytecode" "caml_binaryen_load"

(** Module, num_bytes, offset, align, ptr, value, type. *)
external store : Module.t -> int -> int -> int -> t -> t -> Type.t -> t = "caml_binaryen_store__bytecode" "caml_binaryen_store"

external const : Module.t -> Literal.t -> t = "caml_binaryen_const"

external unary : Module.t -> Op.t -> t -> t = "caml_binaryen_unary"

external binary : Module.t -> Op.t -> t -> t -> t = "caml_binaryen_binary"

(** Module, condition, true branch, false branch. *)
external select : Module.t -> t -> t -> t -> t = "caml_binaryen_select"

external drop : Module.t -> t -> t = "caml_binaryen_drop"

external return : Module.t -> t -> t = "caml_binaryen_return"

external nop : Module.t -> t = "caml_binaryen_nop"

external unreachable : Module.t -> t = "caml_binaryen_unreachable"

(** Module, destination, source, size. *)
external memory_copy : Module.t -> t -> t -> t -> t = "caml_binaryen_memory_copy"

(** Module, destination, value, size. *)
external memory_fill : Module.t -> t -> t -> t -> t = "caml_binaryen_memory_fill"

(** Print an expression to the console. *)
external print : t -> unit = "caml_binaryen_expression_print"
