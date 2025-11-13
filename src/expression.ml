type t

type kind =
  | Invalid
  | Nop
  | Block
  | If
  | Loop
  | Break
  | Switch
  | Call
  | CallIndirect
  | LocalGet
  | LocalSet
  | GlobalGet
  | GlobalSet
  | Load
  | Store
  | AtomicRMW
  | AtomicCmpxchg
  | AtomicWait
  | AtomicNotify
  | AtomicFence
  | SIMDExtract
  | SIMDReplace
  | SIMDShuffle
  | SIMDTernary
  | SIMDShift
  | SIMDLoad
  | SIMDLoadStoreLane
  | MemoryInit
  | DataDrop
  | MemoryCopy
  | MemoryFill
  | Const
  | Unary
  | Binary
  | Select
  | Drop
  | Return
  | MemorySize
  | MemoryGrow
  | Unreachable
  | Pop
  | RefNull
  | RefIs
  | RefFunc
  | RefEq
  | Try
  | Throw
  | Rethrow
  | TupleMake
  | TupleExtract
  | I31New
  | I31Get
  | CallRef
  | RefTest
  | RefCast
  | BrOn
  | StructNew
  | StructGet
  | StructSet
  | ArrayNew
  | ArrayGet
  | ArraySet
  | ArrayLen
  | RefAs

external get_id : t -> int = "caml_binaryen_expression_get_id"
external id_invalid : unit -> int = "caml_binaryen_expression_id_invalid"

let id_invalid = id_invalid ()

external id_nop : unit -> int = "caml_binaryen_expression_id_nop"

let id_nop = id_nop ()

external id_block : unit -> int = "caml_binaryen_expression_id_block"

let id_block = id_block ()

external id_if : unit -> int = "caml_binaryen_expression_id_if"

let id_if = id_if ()

external id_loop : unit -> int = "caml_binaryen_expression_id_loop"

let id_loop = id_loop ()

external id_break : unit -> int = "caml_binaryen_expression_id_break"

let id_break = id_break ()

external id_switch : unit -> int = "caml_binaryen_expression_id_switch"

let id_switch = id_switch ()

external id_call : unit -> int = "caml_binaryen_expression_id_call"

let id_call = id_call ()

external id_call_indirect : unit -> int
  = "caml_binaryen_expression_id_call_indirect"

let id_call_indirect = id_call_indirect ()

external id_local_get : unit -> int = "caml_binaryen_expression_id_local_get"

let id_local_get = id_local_get ()

external id_local_set : unit -> int = "caml_binaryen_expression_id_local_set"

let id_local_set = id_local_set ()

external id_global_get : unit -> int = "caml_binaryen_expression_id_global_get"

let id_global_get = id_global_get ()

external id_global_set : unit -> int = "caml_binaryen_expression_id_global_set"

let id_global_set = id_global_set ()

external id_load : unit -> int = "caml_binaryen_expression_id_load"

let id_load = id_load ()

external id_store : unit -> int = "caml_binaryen_expression_id_store"

let id_store = id_store ()

external id_atomic_rmw : unit -> int = "caml_binaryen_expression_id_atomic_rmw"

let id_atomic_rmw = id_atomic_rmw ()

external id_atomic_cmpxchg : unit -> int
  = "caml_binaryen_expression_id_atomic_cmpxchg"

let id_atomic_cmpxchg = id_atomic_cmpxchg ()

external id_atomic_wait : unit -> int
  = "caml_binaryen_expression_id_atomic_wait"

let id_atomic_wait = id_atomic_wait ()

external id_atomic_notify : unit -> int
  = "caml_binaryen_expression_id_atomic_notify"

let id_atomic_notify = id_atomic_notify ()

external id_atomic_fence : unit -> int
  = "caml_binaryen_expression_id_atomic_fence"

let id_atomic_fence = id_atomic_fence ()

external id_simd_extract : unit -> int
  = "caml_binaryen_expression_id_simd_extract"

let id_simd_extract = id_simd_extract ()

external id_simd_replace : unit -> int
  = "caml_binaryen_expression_id_simd_replace"

let id_simd_replace = id_simd_replace ()

external id_simd_shuffle : unit -> int
  = "caml_binaryen_expression_id_simd_shuffle"

let id_simd_shuffle = id_simd_shuffle ()

external id_simd_ternary : unit -> int
  = "caml_binaryen_expression_id_simd_ternary"

let id_simd_ternary = id_simd_ternary ()

external id_simd_shift : unit -> int = "caml_binaryen_expression_id_simd_shift"

let id_simd_shift = id_simd_shift ()

external id_simd_load : unit -> int = "caml_binaryen_expression_id_simd_load"

let id_simd_load = id_simd_load ()

external id_simd_load_store_lane : unit -> int
  = "caml_binaryen_expression_id_simd_load_store_lane"

let id_simd_load_store_lane = id_simd_load_store_lane ()

external id_memory_init : unit -> int
  = "caml_binaryen_expression_id_memory_init"

let id_memory_init = id_memory_init ()

external id_data_drop : unit -> int = "caml_binaryen_expression_id_data_drop"

let id_data_drop = id_data_drop ()

external id_memory_copy : unit -> int
  = "caml_binaryen_expression_id_memory_copy"

let id_memory_copy = id_memory_copy ()

external id_memory_fill : unit -> int
  = "caml_binaryen_expression_id_memory_fill"

let id_memory_fill = id_memory_fill ()

external id_const : unit -> int = "caml_binaryen_expression_id_const"

let id_const = id_const ()

external id_unary : unit -> int = "caml_binaryen_expression_id_unary"

let id_unary = id_unary ()

external id_binary : unit -> int = "caml_binaryen_expression_id_binary"

let id_binary = id_binary ()

external id_select : unit -> int = "caml_binaryen_expression_id_select"

let id_select = id_select ()

external id_drop : unit -> int = "caml_binaryen_expression_id_drop"

let id_drop = id_drop ()

external id_return : unit -> int = "caml_binaryen_expression_id_return"

let id_return = id_return ()

external id_memory_size : unit -> int
  = "caml_binaryen_expression_id_memory_size"

let id_memory_size = id_memory_size ()

external id_memory_grow : unit -> int
  = "caml_binaryen_expression_id_memory_grow"

let id_memory_grow = id_memory_grow ()

external id_unreachable : unit -> int
  = "caml_binaryen_expression_id_unreachable"

let id_unreachable = id_unreachable ()

external id_pop : unit -> int = "caml_binaryen_expression_id_pop"

let id_pop = id_pop ()

external id_ref_null : unit -> int = "caml_binaryen_expression_id_ref_null"

let id_ref_null = id_ref_null ()

external id_ref_is_null : unit -> int
  = "caml_binaryen_expression_id_ref_is_null"

let id_ref_is_null = id_ref_is_null ()

external id_ref_func : unit -> int = "caml_binaryen_expression_id_ref_func"

let id_ref_func = id_ref_func ()

external id_ref_eq : unit -> int = "caml_binaryen_expression_id_ref_eq"

let id_ref_eq = id_ref_eq ()

external id_try : unit -> int = "caml_binaryen_expression_id_try"

let id_try = id_try ()

external id_throw : unit -> int = "caml_binaryen_expression_id_throw"

let id_throw = id_throw ()

external id_rethrow : unit -> int = "caml_binaryen_expression_id_rethrow"

let id_rethrow = id_rethrow ()

external id_tuple_make : unit -> int = "caml_binaryen_expression_id_tuple_make"

let id_tuple_make = id_tuple_make ()

external id_tuple_extract : unit -> int
  = "caml_binaryen_expression_id_tuple_extract"

let id_tuple_extract = id_tuple_extract ()

external id_ref_i31 : unit -> int = "caml_binaryen_expression_id_ref_i31"

let id_ref_i31 = id_ref_i31 ()

external id_i31_get : unit -> int = "caml_binaryen_expression_id_i31_get"

let id_i31_get = id_i31_get ()

external id_call_ref : unit -> int = "caml_binaryen_expression_id_call_ref"

let id_call_ref = id_call_ref ()

external id_ref_test : unit -> int = "caml_binaryen_expression_id_ref_test"

let id_ref_test = id_ref_test ()

external id_ref_cast : unit -> int = "caml_binaryen_expression_id_ref_cast"

let id_ref_cast = id_ref_cast ()

external id_br_on : unit -> int = "caml_binaryen_expression_id_br_on"

let id_br_on = id_br_on ()

external id_struct_new : unit -> int = "caml_binaryen_expression_id_struct_new"

let id_struct_new = id_struct_new ()

external id_struct_get : unit -> int = "caml_binaryen_expression_id_struct_get"

let id_struct_get = id_struct_get ()

external id_struct_set : unit -> int = "caml_binaryen_expression_id_struct_set"

let id_struct_set = id_struct_set ()

external id_array_new : unit -> int = "caml_binaryen_expression_id_array_new"

let id_array_new = id_array_new ()

external id_array_get : unit -> int = "caml_binaryen_expression_id_array_get"

let id_array_get = id_array_get ()

external id_array_set : unit -> int = "caml_binaryen_expression_id_array_set"

let id_array_set = id_array_set ()

external id_array_len : unit -> int = "caml_binaryen_expression_id_array_len"

let id_array_len = id_array_len ()

external id_ref_as : unit -> int = "caml_binaryen_expression_id_ref_as"

let id_ref_as = id_ref_as ()

let get_kind expr =
  let id = get_id expr in
  match id with
  | n when n = id_invalid -> Invalid
  | n when n = id_nop -> Nop
  | n when n = id_block -> Block
  | n when n = id_if -> If
  | n when n = id_loop -> Loop
  | n when n = id_break -> Break
  | n when n = id_switch -> Switch
  | n when n = id_call -> Call
  | n when n = id_call_indirect -> CallIndirect
  | n when n = id_local_get -> LocalGet
  | n when n = id_local_set -> LocalSet
  | n when n = id_global_get -> GlobalGet
  | n when n = id_global_set -> GlobalSet
  | n when n = id_load -> Load
  | n when n = id_store -> Store
  | n when n = id_atomic_rmw -> AtomicRMW
  | n when n = id_atomic_cmpxchg -> AtomicCmpxchg
  | n when n = id_atomic_wait -> AtomicWait
  | n when n = id_atomic_notify -> AtomicNotify
  | n when n = id_atomic_fence -> AtomicFence
  | n when n = id_simd_extract -> SIMDExtract
  | n when n = id_simd_replace -> SIMDReplace
  | n when n = id_simd_shuffle -> SIMDShuffle
  | n when n = id_simd_ternary -> SIMDTernary
  | n when n = id_simd_shift -> SIMDShift
  | n when n = id_simd_load -> SIMDLoad
  | n when n = id_simd_load_store_lane -> SIMDLoadStoreLane
  | n when n = id_memory_init -> MemoryInit
  | n when n = id_data_drop -> DataDrop
  | n when n = id_memory_copy -> MemoryCopy
  | n when n = id_memory_fill -> MemoryFill
  | n when n = id_const -> Const
  | n when n = id_unary -> Unary
  | n when n = id_binary -> Binary
  | n when n = id_select -> Select
  | n when n = id_drop -> Drop
  | n when n = id_return -> Return
  | n when n = id_memory_size -> MemorySize
  | n when n = id_memory_grow -> MemoryGrow
  | n when n = id_unreachable -> Unreachable
  | n when n = id_pop -> Pop
  | n when n = id_ref_null -> RefNull
  | n when n = id_ref_is_null -> RefIs
  | n when n = id_ref_func -> RefFunc
  | n when n = id_ref_eq -> RefEq
  | n when n = id_try -> Try
  | n when n = id_throw -> Throw
  | n when n = id_rethrow -> Rethrow
  | n when n = id_tuple_make -> TupleMake
  | n when n = id_tuple_extract -> TupleExtract
  | n when n = id_ref_i31 -> I31New
  | n when n = id_i31_get -> I31Get
  | n when n = id_call_ref -> CallRef
  | n when n = id_ref_test -> RefTest
  | n when n = id_ref_cast -> RefCast
  | n when n = id_br_on -> BrOn
  | n when n = id_struct_new -> StructNew
  | n when n = id_struct_get -> StructGet
  | n when n = id_struct_set -> StructSet
  | n when n = id_array_new -> ArrayNew
  | n when n = id_array_get -> ArrayGet
  | n when n = id_array_set -> ArraySet
  | n when n = id_array_len -> ArrayLen
  | n when n = id_ref_as -> RefAs
  | _ -> failwith "unknown expression kind"

external print : t -> unit = "caml_binaryen_expression_print"
(** Print an expression to the console. *)

external finalize : t -> unit = "caml_binaryen_expression_finalize"
external copy : t -> Module.t -> t = "caml_binaryen_expression_copy"

(** Expression manipulation *)

module Block = struct
  external make : Module.t -> string -> t list -> Type.t -> t
    = "caml_binaryen_block"
  (** Module, block name, expression list. *)

  let make ?(return_type = Type.auto) wasm_mod name exprs =
    make wasm_mod name exprs return_type

  external get_name : t -> string option = "caml_binaryen_block_get_name"
  external set_name : t -> string -> unit = "caml_binaryen_block_set_name"
  external get_num_children : t -> int = "caml_binaryen_block_get_num_children"
  external get_child_at : t -> int -> t = "caml_binaryen_block_get_child_at"

  external set_child_at : t -> int -> t -> unit
    = "caml_binaryen_block_set_child_at"

  external append_child : t -> t -> int = "caml_binaryen_block_append_child"

  external insert_child_at : t -> int -> t -> unit
    = "caml_binaryen_block_insert_child_at"

  external remove_child_at : t -> int -> t
    = "caml_binaryen_block_remove_child_at"
end

module If = struct
  external make : Module.t -> t -> t -> t -> t = "caml_binaryen_if"
  (** Module, condition, true branch, false branch. False branch may be null. *)

  external get_condition : t -> t = "caml_binaryen_if_get_condition"
  external set_condition : t -> t -> unit = "caml_binaryen_if_set_condition"
  external get_if_true : t -> t = "caml_binaryen_if_get_if_true"
  external set_if_true : t -> t -> unit = "caml_binaryen_if_set_if_true"
  external get_if_false : t -> t option = "caml_binaryen_if_get_if_false"
  external set_if_false : t -> t -> unit = "caml_binaryen_if_set_if_false"
end

module Loop = struct
  external make : Module.t -> string -> t -> t = "caml_binaryen_loop"
  (** Module, loop name, body. *)

  external get_name : t -> string = "caml_binaryen_loop_get_name"
  external set_name : t -> string -> unit = "caml_binaryen_loop_set_name"
  external get_body : t -> t = "caml_binaryen_loop_get_body"
  external set_body : t -> t -> unit = "caml_binaryen_loop_set_body"
end

module Break = struct
  external make : Module.t -> string -> t -> t -> t = "caml_binaryen_break"
  (** Module, block name, condition, result. Value and condition may be null. *)

  external get_name : t -> string = "caml_binaryen_break_get_name"
  external set_name : t -> string -> unit = "caml_binaryen_break_set_name"
  external get_condition : t -> t option = "caml_binaryen_break_get_condition"
  external set_condition : t -> t -> unit = "caml_binaryen_break_set_condition"
  external get_value : t -> t option = "caml_binaryen_break_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_break_set_value"
end

module Switch = struct
  external make : Module.t -> string list -> string -> t -> t -> t
    = "caml_binaryen_switch"
  (** Module, branch names, default branch name, condition, value. Value may be
      null. *)

  external get_num_names : t -> int = "caml_binaryen_switch_get_num_names"
  external get_name_at : t -> int -> string = "caml_binaryen_switch_get_name_at"

  external set_name_at : t -> int -> string -> unit
    = "caml_binaryen_switch_set_name_at"

  external append_name : t -> string -> int = "caml_binaryen_switch_append_name"

  external insert_name_at : t -> int -> string -> unit
    = "caml_binaryen_switch_insert_name_at"

  external remove_name_at : t -> int -> string
    = "caml_binaryen_switch_remove_name_at"

  external get_default_name : t -> string option
    = "caml_binaryen_switch_get_default_name"

  external set_default_name : t -> string -> unit
    = "caml_binaryen_switch_set_default_name"

  external get_condition : t -> t = "caml_binaryen_switch_get_condition"
  external set_condition : t -> t -> unit = "caml_binaryen_switch_set_condition"
  external get_value : t -> t option = "caml_binaryen_switch_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_switch_set_value"
end

module Call = struct
  external make : Module.t -> string -> t list -> Type.t -> t
    = "caml_binaryen_call"
  (** Module, function name, params, return type. *)

  external make_return : Module.t -> string -> t list -> Type.t -> t
    = "caml_binaryen_return_call"
  (** Module, function name, params, return type. *)

  external get_target : t -> string = "caml_binaryen_call_get_target"
  external set_target : t -> string -> unit = "caml_binaryen_call_set_target"
  external get_num_operands : t -> int = "caml_binaryen_call_get_num_operands"
  external get_operand_at : t -> int -> t = "caml_binaryen_call_get_operand_at"

  external set_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_set_operand_at"

  external append_operand : t -> t -> int = "caml_binaryen_call_append_operand"

  external insert_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_insert_operand_at"

  external remove_operand_at : t -> int -> t
    = "caml_binaryen_call_remove_operand_at"

  external is_return : t -> bool = "caml_binaryen_call_is_return"
  external set_return : t -> bool -> unit = "caml_binaryen_call_set_return"
end

module Call_indirect = struct
  external make : Module.t -> string -> t -> t list -> Type.t -> Type.t -> t
    = "caml_binaryen_call_indirect__bytecode" "caml_binaryen_call_indirect"
  (** Module, table, function value, params, params type, return type. *)

  external make_return :
    Module.t -> string -> t -> t list -> Type.t -> Type.t -> t
    = "caml_binaryen_return_call_indirect__bytecode"
      "caml_binaryen_return_call_indirect"
  (** Module, table, function value, params, params type, return type. *)

  external get_target : t -> t = "caml_binaryen_call_indirect_get_target"

  external set_target : t -> t -> unit
    = "caml_binaryen_call_indirect_set_target"

  external get_table : t -> string = "caml_binaryen_call_indirect_get_table"

  external set_table : t -> string -> unit
    = "caml_binaryen_call_indirect_set_table"

  external get_num_operands : t -> int
    = "caml_binaryen_call_indirect_get_num_operands"

  external get_operand_at : t -> int -> t
    = "caml_binaryen_call_indirect_get_operand_at"

  external set_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_indirect_set_operand_at"

  external append_operand : t -> t -> int
    = "caml_binaryen_call_indirect_append_operand"

  external insert_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_indirect_insert_operand_at"

  external remove_operand_at : t -> int -> t
    = "caml_binaryen_call_indirect_remove_operand_at"

  external is_return : t -> bool = "caml_binaryen_call_indirect_is_return"

  external set_return : t -> bool -> unit
    = "caml_binaryen_call_indirect_set_return"
end

module Call_ref = struct
  external make : Module.t -> t -> t list -> Type.t -> bool -> t
    = "caml_binaryen_call_ref"
  (** Module, function value, params, type, is return. *)

  let make_return mod_ target params typ = make mod_ target params typ true
  let make mod_ target params typ = make mod_ target params typ false

  external get_target : t -> t = "caml_binaryen_call_ref_get_target"
  external set_target : t -> t -> unit = "caml_binaryen_call_ref_set_target"

  external get_num_operands : t -> int
    = "caml_binaryen_call_ref_get_num_operands"

  external get_operand_at : t -> int -> t
    = "caml_binaryen_call_ref_get_operand_at"

  external set_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_ref_set_operand_at"

  external append_operand : t -> t -> int
    = "caml_binaryen_call_ref_append_operand"

  external insert_operand_at : t -> int -> t -> unit
    = "caml_binaryen_call_ref_insert_operand_at"

  external remove_operand_at : t -> int -> t
    = "caml_binaryen_call_ref_remove_operand_at"

  external is_return : t -> bool = "caml_binaryen_call_ref_is_return"
  external set_return : t -> bool -> unit = "caml_binaryen_call_ref_set_return"
end

module Local_get = struct
  external make : Module.t -> int -> Type.t -> t = "caml_binaryen_local_get"
  (** Module, slot, type. *)
end

module Local_set = struct
  external make : Module.t -> int -> t -> t = "caml_binaryen_local_set"
  (** Module, slot, value. *)

  external get_value : t -> t = "caml_binaryen_local_set_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_local_set_set_value"
end

module Local_tee = struct
  external make : Module.t -> int -> t -> Type.t -> t
    = "caml_binaryen_local_tee"
  (** Module, slot, value, type. *)
end

module Global_get = struct
  external make : Module.t -> string -> Type.t -> t = "caml_binaryen_global_get"
  (** Module, name, type. *)

  external get_name : t -> string = "caml_binaryen_global_get_get_name"
  external set_name : t -> string -> unit = "caml_binaryen_global_get_set_name"
end

module Global_set = struct
  external make : Module.t -> string -> t -> t = "caml_binaryen_global_set"
  (** Module, name, value. *)

  external get_name : t -> string = "caml_binaryen_global_set_get_name"
  external set_name : t -> string -> unit = "caml_binaryen_global_set_set_name"
  external get_value : t -> t = "caml_binaryen_global_set_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_global_set_set_value"
end

module Load = struct
  external make :
    Module.t -> int -> bool -> int -> int -> Type.t -> t -> string -> t
    = "caml_binaryen_load__bytecode" "caml_binaryen_load"

  (** Module, num_bytes, ?signed, offset, align, type, ptr, memory_name *)
  let make wasm_mod bytes ?(signed = false) offset align ty ptr =
    make wasm_mod bytes signed offset align ty ptr

  external get_ptr : t -> t = "caml_binaryen_load_get_ptr"
  external set_ptr : t -> t -> unit = "caml_binaryen_load_set_ptr"
end

module Store = struct
  external make :
    Module.t -> int -> int -> int -> t -> t -> Type.t -> string -> t
    = "caml_binaryen_store__bytecode" "caml_binaryen_store"
  (** Module, num_bytes, offset, align, ptr, value, type, memory_name *)

  external get_ptr : t -> t = "caml_binaryen_store_get_ptr"
  external set_ptr : t -> t -> unit = "caml_binaryen_store_set_ptr"
  external get_value : t -> t = "caml_binaryen_store_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_store_set_value"
end

module Const = struct
  external make : Module.t -> Literal.t -> t = "caml_binaryen_const"
end

module Unary = struct
  external make : Module.t -> Op.t -> t -> t = "caml_binaryen_unary"
  external get_value : t -> t = "caml_binaryen_unary_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_unary_set_value"
end

module Binary = struct
  external make : Module.t -> Op.t -> t -> t -> t = "caml_binaryen_binary"
  external get_left : t -> t = "caml_binaryen_binary_get_left"
  external set_left : t -> t -> unit = "caml_binaryen_binary_set_left"
  external get_right : t -> t = "caml_binaryen_binary_get_right"
  external set_right : t -> t -> unit = "caml_binaryen_binary_set_right"
end

module Select = struct
  external make : Module.t -> t -> t -> t -> t = "caml_binaryen_select"

  (** Module, condition, true branch, false branch. *)
  let make wasm_mod cond tru fals = make wasm_mod cond tru fals

  external get_if_true : t -> t = "caml_binaryen_select_get_if_true"
  external set_if_true : t -> t -> unit = "caml_binaryen_select_set_if_true"
  external get_if_false : t -> t = "caml_binaryen_select_get_if_false"
  external set_if_false : t -> t -> unit = "caml_binaryen_select_set_if_false"
  external get_condition : t -> t = "caml_binaryen_select_get_condition"
  external set_condition : t -> t -> unit = "caml_binaryen_select_set_condition"
end

module Drop = struct
  external make : Module.t -> t -> t = "caml_binaryen_drop"
  external get_value : t -> t = "caml_binaryen_drop_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_drop_set_value"
end

module Return = struct
  external make : Module.t -> t -> t = "caml_binaryen_return"
  external get_value : t -> t option = "caml_binaryen_return_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_return_set_value"
end

module Memory_size = struct
  external make : Module.t -> string -> bool -> t = "caml_binaryen_memory_size"
  (** Module, memory_name, memory_is_64 *)
end

module Memory_grow = struct
  external make : Module.t -> t -> string -> bool -> t
    = "caml_binaryen_memory_grow"
  (** Module, delta, memory_name, memory_is_64 *)

  external get_delta : t -> t = "caml_binaryen_memory_grow_get_delta"
  external set_delta : t -> t -> unit = "caml_binaryen_memory_grow_set_delta"
end

module Memory_init = struct
  external make : Module.t -> string -> t -> t -> t -> string -> t
    = "caml_binaryen_memory_init__bytecode" "caml_binaryen_memory_init"

  external get_segment : t -> string = "caml_binaryen_memory_init_get_segment"
  (** Module, segment, destination, offset, size, memory_name *)

  external set_segment : t -> string -> unit
    = "caml_binaryen_memory_init_set_segment"

  external get_dest : t -> t = "caml_binaryen_memory_init_get_dest"
  external set_dest : t -> t -> unit = "caml_binaryen_memory_init_set_dest"
  external get_offset : t -> t = "caml_binaryen_memory_init_get_offset"
  external set_offset : t -> t -> unit = "caml_binaryen_memory_init_set_offset"
  external get_size : t -> t = "caml_binaryen_memory_init_get_size"
  external set_size : t -> t -> unit = "caml_binaryen_memory_init_set_size"
end

module Data_drop = struct
  external make : Module.t -> string -> t = "caml_binaryen_data_drop"

  external get_segment : t -> string = "caml_binaryen_data_drop_get_segment"
  (** Module, segment. *)

  external set_segment : t -> string -> unit
    = "caml_binaryen_data_drop_set_segment"
end

module Memory_copy = struct
  external make : Module.t -> t -> t -> t -> string -> string -> t
    = "caml_binaryen_memory_copy__bytecode" "caml_binaryen_memory_copy"
  (** Module, destination, source, size, dest_memory, source_memory *)

  external get_dest : t -> t = "caml_binaryen_memory_copy_get_dest"
  external set_dest : t -> t -> unit = "caml_binaryen_memory_copy_set_dest"
  external get_source : t -> t = "caml_binaryen_memory_copy_get_source"
  external set_source : t -> t -> unit = "caml_binaryen_memory_copy_set_source"
  external get_size : t -> t = "caml_binaryen_memory_copy_get_size"
  external set_size : t -> t -> unit = "caml_binaryen_memory_copy_set_size"
end

module Memory_fill = struct
  external make : Module.t -> t -> t -> t -> string -> t
    = "caml_binaryen_memory_fill"
  (** Module, destination, value, size, memory_name *)

  external get_dest : t -> t = "caml_binaryen_memory_fill_get_dest"
  external set_dest : t -> t -> unit = "caml_binaryen_memory_fill_set_dest"
  external get_value : t -> t = "caml_binaryen_memory_fill_get_value"
  external set_value : t -> t -> unit = "caml_binaryen_memory_fill_set_value"
  external get_size : t -> t = "caml_binaryen_memory_fill_get_size"
  external set_size : t -> t -> unit = "caml_binaryen_memory_fill_set_size"
end

module Tuple_make = struct
  external make : Module.t -> t list -> t = "caml_binaryen_tuple_make"
  (** Module, items *)

  external get_num_operands : t -> int
    = "caml_binaryen_tuple_make_get_num_operands"

  external get_operand_at : t -> int -> t
    = "caml_binaryen_tuple_make_get_operand_at"

  external set_operand_at : t -> int -> t -> unit
    = "caml_binaryen_tuple_make_set_operand_at"

  external append_operand : t -> t -> int
    = "caml_binaryen_tuple_make_append_operand"

  external insert_operand_at : t -> int -> t -> unit
    = "caml_binaryen_tuple_make_insert_operand_at"

  external remove_operand_at : t -> int -> t
    = "caml_binaryen_tuple_make_remove_operand_at"
end

module Tuple_extract = struct
  external make : Module.t -> t -> int -> t = "caml_binaryen_tuple_extract"
  (** Module, tuple, index *)

  external get_tuple : t -> t = "caml_binaryen_tuple_extract_get_tuple"
  external set_tuple : t -> t -> unit = "caml_binaryen_tuple_extract_set_tuple"
end

module Nop = struct
  external make : Module.t -> t = "caml_binaryen_nop"
end

module Unreachable = struct
  external make : Module.t -> t = "caml_binaryen_unreachable"
end

module Pop = struct
  external make : Module.t -> Type.t -> t = "caml_binaryen_pop"
  (** Module, type *)
end

module I31 = struct
  external make : Module.t -> t -> t = "caml_binaryen_ref_i31"
  (** Module, value *)

  external get : Module.t -> t -> bool -> t = "caml_binaryen_i31_get"
  (** Module, i31, is_signed *)
end

module Null = struct
  external make : unit -> t = "caml_binaryen_null_expression"
  (** A null reference. *)
end

module Ref = struct
  external null : Module.t -> Type.t -> t = "caml_binaryen_ref_null"
  (** Module, type *)

  external is_null : Module.t -> t -> t = "caml_binaryen_ref_is_null"
  (** Module, value *)

  external as_ : Module.t -> Op.t -> t -> t = "caml_binaryen_ref_as"
  (** Module, op, value *)

  external func : Module.t -> string -> Heap_type.t -> t
    = "caml_binaryen_ref_func"
  (** Module, func, type *)

  external eq : Module.t -> t -> t -> t = "caml_binaryen_ref_eq"
  (** Module, left, right *)

  external test : Module.t -> t -> Type.t -> t = "caml_binaryen_ref_test"
  (** Module, value, type *)

  external cast : Module.t -> t -> Type.t -> t = "caml_binaryen_ref_cast"
  (** Module, value, type *)
end

module BrOn = struct
  external make : Module.t -> Op.t -> string -> t -> Type.t -> t
    = "caml_binaryen_br_on"
  (** Module, op, label, value, type *)
end

module Struct = struct
  external new_ : Module.t -> t list option -> Heap_type.t -> t
    = "caml_binaryen_struct_new"
  (** Mdoule, operands, type *)

  external get : Module.t -> int -> t -> Type.t -> bool -> t
    = "caml_binaryen_struct_get"
  (** Module, index, struct, type, signed *)

  external set : Module.t -> int -> t -> t -> t = "caml_binaryen_struct_set"
  (** Module, index, struct, value *)
end

module Array = struct
  external new_ : Module.t -> Heap_type.t -> t -> t -> t
    = "caml_binaryen_array_new"
  (** Module, type, size, init *)

  external new_data : Module.t -> Heap_type.t -> string -> t -> t -> t
    = "caml_binaryen_array_new_data"
  (** Module, type, data name, offset, size *)

  external new_fixed : Module.t -> Heap_type.t -> t list -> t
    = "caml_binaryen_array_new_fixed"
  (** Module, type, values *)

  external get : Module.t -> t -> t -> Type.t -> bool -> t
    = "caml_binaryen_array_get"
  (** Module, array, index, type, signed *)

  external set : Module.t -> t -> t -> t -> t = "caml_binaryen_array_set"
  (** Module, array, index, value *)

  external len : Module.t -> t -> t = "caml_binaryen_array_len"
  (** Module, array *)

  external copy : Module.t -> t -> t -> t -> t -> t -> t
    = "caml_binaryen_array_copy__bytecode" "caml_binaryen_array_copy"
  (** Module, dest, dest index, src, src index, length *)
end

module Table = struct
  external get : Module.t -> string -> t -> Type.t -> t
    = "caml_binaryen_table_get"
  (** Module, name, index, type *)

  external set : Module.t -> string -> t -> t -> t = "caml_binaryen_table_set"
  (** Module, name, index, value *)

  external size : Module.t -> string -> t = "caml_binaryen_table_size"
  (** Module, name *)

  external grow : Module.t -> string -> t -> t -> t = "caml_binaryen_table_grow"
  (** Module, name, value, delta *)
end

module Table_get = struct
  external get_table : t -> string = "caml_binaryen_tableget_get_table"
  (** Gets the name of the table being accessed by a `Table.get` expression. *)

  external set_table : t -> string -> unit = "caml_binaryen_tableget_set_table"
  (** Gets the name of the table being accessed by a `Table.get` expression. *)

  external get_index : t -> t = "caml_binaryen_tableget_get_index"
  (** Gets the index expression of a `Table.get` expression. *)

  external set_index : t -> t -> unit = "caml_binaryen_tableget_set_index"
  (** Gets the index expression of a `Table.get` expression. *)
end

module Table_set = struct
  external get_table : t -> string = "caml_binaryen_tableset_get_table"
  (** Gets the name of the table being accessed by a `Table.set` expression. *)

  external set_table : t -> string -> unit = "caml_binaryen_tableset_set_table"
  (** Sets the name of the table being accessed by a `Table.set` expression. *)

  external get_index : t -> t = "caml_binaryen_tableset_get_index"
  (** Gets the index expression of a `Table.set` expression. *)

  external set_index : t -> t -> unit = "caml_binaryen_tableset_set_index"
  (** Sets the index expression of a `Table.set` expression. *)

  external get_value : t -> t = "caml_binaryen_tableset_get_value"
  (** Gets the value expression of a `Table.set` expression. *)

  external set_value : t -> t -> unit = "caml_binaryen_tableset_set_value"
  (** Sets the value expression of a `Table.set` expression. *)
end

module Table_size = struct
  external get_table : t -> string = "caml_binaryen_tablesize_get_table"
  (** Gets the name of the table being accessed by a `Table.size` expression. *)

  external set_table : t -> string -> unit = "caml_binaryen_tablesize_set_table"
  (** Sets the name of the table being accessed by a `Table.size` expression. *)
end

module Table_grow = struct
  external get_table : t -> string = "caml_binaryen_tablegrow_get_table"
  (** Gets the name of the table being accessed by a `Table.grow` expression. *)

  external set_table : t -> string -> unit = "caml_binaryen_tablegrow_set_table"
  (** Gets the name of the table being accessed by a `Table.grow` expression. *)

  external get_value : t -> t = "caml_binaryen_tablegrow_get_value"
  (** Gets the value expression of a `Table.grow` expression. *)

  external set_value : t -> t -> unit = "caml_binaryen_tablegrow_set_value"
  (** Sets the value expression of a `Table.grow` expression. *)

  external get_delta : t -> t = "caml_binaryen_tablegrow_get_delta"
  (** Gets the delta of a `Table.grow` expression. *)

  external set_delta : t -> t -> unit = "caml_binaryen_tablegrow_set_delta"
  (** Sets the delta of a `Table.grow` expression. *)
end
