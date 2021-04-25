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

module If : sig
  val get_condition : t -> t

  val set_condition : t -> t -> unit

  val get_if_true : t -> t

  val set_if_true : t -> t -> unit

  val get_if_false : t -> t option

  val set_if_false : t -> t -> unit
end

module Loop : sig
  val get_name : t -> string

  val set_name : t -> string -> unit

  val get_body : t -> t

  val set_body : t -> t -> unit
end

module Break : sig
  val get_name : t -> string

  val set_name : t -> string -> unit

  val get_condition : t -> t option

  val set_condition : t -> t -> unit

  val get_value : t -> t option

  val set_value : t -> t -> unit
end

module Switch : sig
  val get_num_names : t -> int

  val get_name_at : t -> int -> string

  val set_name_at : t -> int -> string -> unit

  val append_name : t -> string -> int

  val insert_name_at : t -> int -> string -> unit

  val remove_name_at : t -> int -> string

  val get_default_name : t -> string option

  val set_default_name : t -> string -> unit

  val get_condition : t -> t

  val set_condition : t -> t -> unit

  val get_value : t -> t option

  val set_value : t -> t -> unit
end

module Call : sig
  val get_target : t -> string

  val set_target : t -> string -> unit

  val get_num_operands : t -> int

  val get_operand_at : t -> int -> t

  val set_operand_at : t -> int -> t -> unit

  val append_operand : t -> t -> int

  val insert_operand_at : t -> int -> t -> unit

  val remove_operand_at : t -> int -> t

  val is_return : t -> bool

  val set_return : t -> bool -> unit
end

module Call_indirect : sig
  val get_target : t -> t

  val set_target : t -> t -> unit

  val get_table : t -> string

  val set_table : t -> string -> unit

  val get_num_operands : t -> int

  val get_operand_at : t -> int -> t

  val set_operand_at : t -> int -> t -> unit

  val append_operand : t -> t -> int

  val insert_operand_at : t -> int -> t -> unit

  val remove_operand_at : t -> int -> t

  val is_return : t -> bool

  val set_return : t -> bool -> unit
end

module Local_set : sig
  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Global_get : sig
  val get_name : t -> string

  val set_name : t -> string -> unit
end

module Global_set : sig
  val get_name : t -> string

  val set_name : t -> string -> unit

  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Memory_grow : sig
  val get_delta : t -> t

  val set_delta : t -> t -> unit
end

module Load : sig
  val get_ptr : t -> t

  val set_ptr : t -> t -> unit
end

module Store : sig
  val get_ptr : t -> t

  val set_ptr : t -> t -> unit

  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Unary : sig
  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Binary : sig
  val get_left : t -> t

  val set_left : t -> t -> unit

  val get_right : t -> t

  val set_right : t -> t -> unit
end

module Select : sig
  val get_if_true : t -> t

  val set_if_true : t -> t -> unit

  val get_if_false : t -> t

  val set_if_false : t -> t -> unit

  val get_condition : t -> t

  val set_condition : t -> t -> unit
end

module Drop : sig
  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Return : sig
  val get_value : t -> t

  val set_value : t -> t -> unit
end

module Memory_copy : sig
  val get_dest : t -> t

  val set_dest : t -> t -> unit

  val get_source : t -> t

  val set_source : t -> t -> unit

  val get_size : t -> t

  val set_size : t -> t -> unit
end

module Memory_fill : sig
  val get_dest : t -> t

  val set_dest : t -> t -> unit

  val get_value : t -> t

  val set_value : t -> t -> unit

  val get_size : t -> t

  val set_size : t -> t -> unit
end

module Tuple_make : sig
  val get_num_operands : t -> int

  val get_operand_at : t -> int -> t

  val set_operand_at : t -> int -> t -> unit

  val append_operand : t -> t -> int

  val insert_operand_at : t -> int -> t -> unit

  val remove_operand_at : t -> int -> t
end

val tuple_extract_get_tuple : t -> t

val tuple_extract_set_tuple : t -> t -> unit
