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
  | SIMDWiden
  | Prefetch
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
  | RttCanon
  | RttSub
  | StructNew
  | StructGet
  | StructSet
  | ArrayNew
  | ArrayGet
  | ArraySet
  | ArrayLen
  | RefAs

val block : ?return_type:Type.t -> Module.t -> string -> t list -> t

val if_ : Module.t -> t -> t -> t -> t

val loop : Module.t -> string -> t -> t

val break : Module.t -> string -> t -> t -> t

val switch : Module.t -> string list -> string -> t -> t -> t

val call : Module.t -> string -> t list -> Type.t -> t

val call_indirect : Module.t -> string -> t -> t list -> Type.t -> Type.t -> t

val return_call : Module.t -> string -> t list -> Type.t -> t

val return_call_indirect :
  Module.t -> string -> t -> t list -> Type.t -> Type.t -> t

val local_get : Module.t -> int -> Type.t -> t

val local_set : Module.t -> int -> t -> t

val local_tee : Module.t -> int -> t -> Type.t -> t

val global_get : Module.t -> string -> Type.t -> t

val global_set : Module.t -> string -> t -> t

val load : Module.t -> int -> ?signed:bool -> int -> int -> Type.t -> t -> t

val store : Module.t -> int -> int -> int -> t -> t -> Type.t -> t

val const : Module.t -> Literal.t -> t

val unary : Module.t -> Op.t -> t -> t

val binary : Module.t -> Op.t -> t -> t -> t

val select : Module.t -> t -> t -> t -> t

val drop : Module.t -> t -> t

val return : Module.t -> t -> t

val memory_size : Module.t -> t

val memory_grow : Module.t -> t -> t

val nop : Module.t -> t

val unreachable : Module.t -> t

val memory_copy : Module.t -> t -> t -> t -> t

val memory_fill : Module.t -> t -> t -> t -> t

val tuple_make : Module.t -> t list -> t

val tuple_extract : Module.t -> t -> int -> t

val pop : Module.t -> Type.t -> t

val null : unit -> t

val get_kind : t -> kind

(* Expression operations *)

val expression_print : t -> unit

val expression_finalize : t -> unit

val expression_copy : t -> Module.t -> t

module Block : sig
  val get_name : t -> string option

  val set_name : t -> string -> unit

  val get_num_children : t -> int

  val get_child_at : t -> int -> t

  val set_child_at : t -> int -> t -> unit

  val append_child : t -> t -> int

  val insert_child_at : t -> int -> t -> unit

  val remove_child_at : t -> int -> t
end

val if_get_condition : t -> t

val if_set_condition : t -> t -> unit

val if_get_if_true : t -> t

val if_set_if_true : t -> t -> unit

val if_get_if_false : t -> t option

val if_set_if_false : t -> t -> unit

val loop_get_name : t -> string

val loop_set_name : t -> string -> unit

val loop_get_body : t -> t

val loop_set_body : t -> t -> unit

val break_get_name : t -> string

val break_set_name : t -> string -> unit

val break_get_condition : t -> t option

val break_set_condition : t -> t -> unit

val break_get_value : t -> t option

val break_set_value : t -> t -> unit

val switch_get_num_names : t -> int

val switch_get_name_at : t -> int -> string

val switch_set_name_at : t -> int -> string -> unit

val switch_append_name : t -> string -> int

val switch_insert_name_at : t -> int -> string -> unit

val switch_remove_name_at : t -> int -> string

val switch_get_default_name : t -> string option

val switch_set_default_name : t -> string -> unit

val switch_get_condition : t -> t

val switch_set_condition : t -> t -> unit

val switch_get_value : t -> t option

val switch_set_value : t -> t -> unit

val call_get_target : t -> string

val call_set_target : t -> string -> unit

val call_get_num_operands : t -> int

val call_get_operand_at : t -> int -> t

val call_set_operand_at : t -> int -> t -> unit

val call_append_operand : t -> t -> int

val call_insert_operand_at : t -> int -> t -> unit

val call_remove_operand_at : t -> int -> t

val call_is_return : t -> bool

val call_set_return : t -> bool -> unit

val call_indirect_get_target : t -> t

val call_indirect_set_target : t -> t -> unit

val call_indirect_get_table : t -> string

val call_indirect_set_table : t -> string -> unit

val call_indirect_get_num_operands : t -> int

val call_indirect_get_operand_at : t -> int -> t

val call_indirect_set_operand_at : t -> int -> t -> unit

val call_indirect_append_operand : t -> t -> int

val call_indirect_insert_operand_at : t -> int -> t -> unit

val call_indirect_remove_operand_at : t -> int -> t

val call_indirect_is_return : t -> bool

val call_indirect_set_return : t -> bool -> unit

val local_set_get_value : t -> t

val local_set_set_value : t -> t -> unit

val global_get_get_name : t -> string

val global_get_set_name : t -> string -> unit

val global_set_get_name : t -> string

val global_set_set_name : t -> string -> unit

val global_set_get_value : t -> t

val global_set_set_value : t -> t -> unit

val memory_grow_get_delta : t -> t

val memory_grow_set_delta : t -> t -> unit

val load_get_ptr : t -> t

val load_set_ptr : t -> t -> unit

val store_get_ptr : t -> t

val store_set_ptr : t -> t -> unit

val store_get_value : t -> t

val store_set_value : t -> t -> unit

val unary_get_value : t -> t

val unary_set_value : t -> t -> unit

val binary_get_left : t -> t

val binary_set_left : t -> t -> unit

val binary_get_right : t -> t

val binary_set_right : t -> t -> unit

val select_get_if_true : t -> t

val select_set_if_true : t -> t -> unit

val select_get_if_false : t -> t

val select_set_if_false : t -> t -> unit

val select_get_condition : t -> t

val select_set_condition : t -> t -> unit

val drop_get_value : t -> t

val drop_set_value : t -> t -> unit

val return_get_value : t -> t

val return_set_value : t -> t -> unit

val memory_copy_get_dest : t -> t

val memory_copy_set_dest : t -> t -> unit

val memory_copy_get_source : t -> t

val memory_copy_set_source : t -> t -> unit

val memory_copy_get_size : t -> t

val memory_copy_set_size : t -> t -> unit

val memory_fill_get_dest : t -> t

val memory_fill_set_dest : t -> t -> unit

val memory_fill_get_value : t -> t

val memory_fill_set_value : t -> t -> unit

val memory_fill_get_size : t -> t

val memory_fill_set_size : t -> t -> unit

val tuple_make_get_num_operands : t -> int

val tuple_make_get_operand_at : t -> int -> t

val tuple_make_set_operand_at : t -> int -> t -> unit

val tuple_make_append_operand : t -> t -> int

val tuple_make_insert_operand_at : t -> int -> t -> unit

val tuple_make_remove_operand_at : t -> int -> t

val tuple_extract_get_tuple : t -> t

val tuple_extract_set_tuple : t -> t -> unit
