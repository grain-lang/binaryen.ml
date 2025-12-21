open Binaryen;
open Frame_work;

suite("Expression", () => {
  test("Simple Get Kind", () => {
    let wasm_mod = Module.create();
    assert(
      Expression.get_kind(Expression.Nop.make(wasm_mod)) == Expression.Nop,
    );
    Module.dispose(wasm_mod);
  });
  // Note: Print tests will output to stdout directly, so they are disabled by default.
  // test("Print", () => {
  //   let wasm_mod = Module.create();
  //   // Note: This uses c's stdout directly, so the output may not be in order.
  //   Expression.print(Expression.Nop.make(wasm_mod));
  //   Module.dispose(wasm_mod);
  // });
  test("Finalize", () => {
    let wasm_mod = Module.create();
    let expr = Expression.Nop.make(wasm_mod);
    Expression.finalize(expr);
    Module.dispose(wasm_mod);
  });
  test("Copy", () => {
    let wasm_mod1 = Module.create();
    let wasm_mod2 = Module.create();
    let expr1 = Expression.Nop.make(wasm_mod1);
    let expr2 = Expression.copy(expr1, wasm_mod2);
    assert(Expression.get_kind(expr2) == Expression.Nop);
    Module.dispose(wasm_mod1);
    Module.dispose(wasm_mod2);
  });
  test("Nop", () => {
    let wasm_mod = Module.create();
    let nop_expr = Expression.Nop.make(wasm_mod);
    assert(Expression.get_kind(nop_expr) == Expression.Nop);
    Module.dispose(wasm_mod);
  });
  test("Block", () => {
    let wasm_mod = Module.create();
    // Make
    let block =
      Expression.Block.make(
        wasm_mod,
        "my_block",
        [Expression.Nop.make(wasm_mod)],
      );
    assert(Expression.get_kind(block) == Expression.Block);
    // get_name/set_name
    assert(Expression.Block.get_name(block) == Some("my_block"));
    Expression.Block.set_name(block, "new_block");
    assert(Expression.Block.get_name(block) == Some("new_block"));
    // get_num_children
    assert(Expression.Block.get_num_children(block) == 1);
    // get_child_at
    assert(
      Expression.get_kind(Expression.Block.get_child_at(block, 0))
      == Expression.Nop,
    );
    // set_child_at
    Expression.Block.set_child_at(
      block,
      0,
      Expression.Unreachable.make(wasm_mod),
    );
    assert(
      Expression.get_kind(Expression.Block.get_child_at(block, 0))
      == Expression.Unreachable,
    );
    // append_child
    let _ =
      Expression.Block.append_child(block, Expression.Nop.make(wasm_mod));
    assert(Expression.Block.get_num_children(block) == 2);
    // insert_child_at
    assert(Expression.Block.get_num_children(block) == 2);
    Expression.Block.insert_child_at(
      block,
      1,
      Expression.Nop.make(wasm_mod),
    );
    assert(Expression.Block.get_num_children(block) == 3);
    // remove_child_at
    assert(Expression.Block.get_num_children(block) == 3);
    let _ = Expression.Block.remove_child_at(block, 0);
    assert(Expression.Block.get_num_children(block) == 2);
    Module.dispose(wasm_mod);
  });

  test("If", () => {
    let wasm_mod = Module.create();
    // Make
    let if_expr =
      Expression.If.make(
        wasm_mod,
        Expression.Const.make(wasm_mod, Literal.int32(1l)),
        Expression.Nop.make(wasm_mod),
        Expression.Unreachable.make(wasm_mod),
      );
    // get_condition/set_condition
    assert(
      Expression.get_kind(Expression.If.get_condition(if_expr))
      == Expression.Const,
    );
    Expression.If.set_condition(if_expr, Expression.Nop.make(wasm_mod));
    // get_if_true/set_if_true
    assert(
      Expression.get_kind(Expression.If.get_if_true(if_expr))
      == Expression.Nop,
    );
    Expression.If.set_if_true(
      if_expr,
      Expression.Unreachable.make(wasm_mod),
    );
    // get_if_false/set_if_false
    assert(
      Expression.get_kind(Option.get(Expression.If.get_if_false(if_expr)))
      == Expression.Unreachable,
    );
    Expression.If.set_if_false(if_expr, Expression.Nop.make(wasm_mod));

    Module.dispose(wasm_mod);
  });
});

// TODO:

// module Loop : sig
//   val make : Module.t -> string -> t -> t
//   val get_name : t -> string
//   val set_name : t -> string -> unit
//   val get_body : t -> t
//   val set_body : t -> t -> unit
// end

// module Break : sig
//   val make : Module.t -> string -> t -> t -> t
//   val get_name : t -> string
//   val set_name : t -> string -> unit
//   val get_condition : t -> t option
//   val set_condition : t -> t -> unit
//   val get_value : t -> t option
//   val set_value : t -> t -> unit
// end

// module Switch : sig
//   val make : Module.t -> string list -> string -> t -> t -> t
//   val get_num_names : t -> int
//   val get_name_at : t -> int -> string
//   val set_name_at : t -> int -> string -> unit
//   val append_name : t -> string -> int
//   val insert_name_at : t -> int -> string -> unit
//   val remove_name_at : t -> int -> string
//   val get_default_name : t -> string option
//   val set_default_name : t -> string -> unit
//   val get_condition : t -> t
//   val set_condition : t -> t -> unit
//   val get_value : t -> t option
//   val set_value : t -> t -> unit
// end

// module Call : sig
//   val make : Module.t -> string -> t list -> Type.t -> t
//   val make_return : Module.t -> string -> t list -> Type.t -> t
//   val get_target : t -> string
//   val set_target : t -> string -> unit
//   val get_num_operands : t -> int
//   val get_operand_at : t -> int -> t
//   val set_operand_at : t -> int -> t -> unit
//   val append_operand : t -> t -> int
//   val insert_operand_at : t -> int -> t -> unit
//   val remove_operand_at : t -> int -> t
//   val is_return : t -> bool
//   val set_return : t -> bool -> unit
// end

// module Call_indirect : sig
//   val make : Module.t -> string -> t -> t list -> Type.t -> Type.t -> t
//   val make_return : Module.t -> string -> t -> t list -> Type.t -> Type.t -> t
//   val get_target : t -> t
//   val set_target : t -> t -> unit
//   val get_table : t -> string
//   val set_table : t -> string -> unit
//   val get_num_operands : t -> int
//   val get_operand_at : t -> int -> t
//   val set_operand_at : t -> int -> t -> unit
//   val append_operand : t -> t -> int
//   val insert_operand_at : t -> int -> t -> unit
//   val remove_operand_at : t -> int -> t
//   val is_return : t -> bool
//   val set_return : t -> bool -> unit
// end

// module Local_get : sig
//   val make : Module.t -> int -> Type.t -> t
// end

// module Local_set : sig
//   val make : Module.t -> int -> t -> t
//   val get_value : t -> t
//   val set_value : t -> t -> unit
// end

// module Local_tee : sig
//   val make : Module.t -> int -> t -> Type.t -> t
// end

// module Global_get : sig
//   val make : Module.t -> string -> Type.t -> t
//   val get_name : t -> string
//   val set_name : t -> string -> unit
// end

// module Global_set : sig
//   val make : Module.t -> string -> t -> t
//   val get_name : t -> string
//   val set_name : t -> string -> unit
//   val get_value : t -> t
//   val set_value : t -> t -> unit
// end

// module Load : sig
//   val make :
//     Module.t -> int -> ?signed:bool -> int -> int -> Type.t -> t -> string -> t

//   val get_ptr : t -> t
//   val set_ptr : t -> t -> unit
// end

// module Store : sig
//   val make : Module.t -> int -> int -> int -> t -> t -> Type.t -> string -> t
//   val get_ptr : t -> t
//   val set_ptr : t -> t -> unit
//   val get_value : t -> t
//   val set_value : t -> t -> unit
// end

// module Const : sig
//   val make : Module.t -> Literal.t -> t
// end

// module Unary : sig
//   val make : Module.t -> Op.t -> t -> t
//   val get_value : t -> t
//   val set_value : t -> t -> unit
// end

// module Binary : sig
//   val make : Module.t -> Op.t -> t -> t -> t
//   val get_left : t -> t
//   val set_left : t -> t -> unit
//   val get_right : t -> t
//   val set_right : t -> t -> unit
// end

// module Select : sig
//   val make : Module.t -> t -> t -> t -> t
//   val get_if_true : t -> t
//   val set_if_true : t -> t -> unit
//   val get_if_false : t -> t
//   val set_if_false : t -> t -> unit
//   val get_condition : t -> t
//   val set_condition : t -> t -> unit
// end

// module Drop : sig
//   val make : Module.t -> t -> t
//   val get_value : t -> t
//   val set_value : t -> t -> unit
// end

// module Return : sig
//   val make : Module.t -> t -> t
//   val get_value : t -> t option
//   val set_value : t -> t -> unit
// end

// module Memory_size : sig
//   val make : Module.t -> string -> bool -> t
// end

// module Memory_grow : sig
//   val make : Module.t -> t -> string -> bool -> t
//   val get_delta : t -> t
//   val set_delta : t -> t -> unit
// end

// module Memory_init : sig
//   val make : Module.t -> string -> t -> t -> t -> string -> t
//   val get_segment : t -> string
//   val set_segment : t -> string -> unit
//   val get_dest : t -> t
//   val set_dest : t -> t -> unit
//   val get_offset : t -> t
//   val set_offset : t -> t -> unit
//   val get_size : t -> t
//   val set_size : t -> t -> unit
// end

// module Data_drop : sig
//   val make : Module.t -> string -> t
//   val get_segment : t -> string
//   val set_segment : t -> string -> unit
// end

// module Memory_copy : sig
//   val make : Module.t -> t -> t -> t -> string -> string -> t
//   val get_dest : t -> t
//   val set_dest : t -> t -> unit
//   val get_source : t -> t
//   val set_source : t -> t -> unit
//   val get_size : t -> t
//   val set_size : t -> t -> unit
// end

// module Memory_fill : sig
//   val make : Module.t -> t -> t -> t -> string -> t
//   val get_dest : t -> t
//   val set_dest : t -> t -> unit
//   val get_value : t -> t
//   val set_value : t -> t -> unit
//   val get_size : t -> t
//   val set_size : t -> t -> unit
// end

// module Tuple_make : sig
//   val make : Module.t -> t list -> t
//   val get_num_operands : t -> int
//   val get_operand_at : t -> int -> t
//   val set_operand_at : t -> int -> t -> unit
//   val append_operand : t -> t -> int
//   val insert_operand_at : t -> int -> t -> unit
//   val remove_operand_at : t -> int -> t
// end

// module Tuple_extract : sig
//   val make : Module.t -> t -> int -> t
//   val get_tuple : t -> t
//   val set_tuple : t -> t -> unit
// end

// module Unreachable : sig
//   val make : Module.t -> t
// end

// module Pop : sig
//   val make : Module.t -> Type.t -> t
// end

// module I31 : sig
//   val make : Module.t -> t -> t
//   (** Module, value *)

//   val get : Module.t -> t -> bool -> t
//   (** Module, i31, is_signed *)
// end

// module Null : sig
//   val make : unit -> t
// end

// module Ref : sig
//   val null : Module.t -> Type.t -> t
//   (** Module, type *)

//   val is_null : Module.t -> t -> t
//   (** Module, value *)

//   val as_ : Module.t -> Op.t -> t -> t
//   (** Module, op, value *)

//   val func : Module.t -> string -> Heap_type.t -> t
//   (** Module, func, type *)

//   val eq : Module.t -> t -> t -> t
//   (** Module, left, right *)
// end

// module Table : sig
//   val get : Module.t -> string -> t -> Type.t -> t
//   (** Module, name, index, type *)

//   val set : Module.t -> string -> t -> t -> t
//   (** Module, name, index, value *)

//   val size : Module.t -> string -> t
//   (** Module, name *)

//   val grow : Module.t -> string -> t -> t -> t
//   (** Module, name, value, delta *)
// end

// module Table_get : sig
//   val get_table : t -> string
//   (** Gets the name of the table being accessed by a `Table.get` expression. *)

//   val set_table : t -> string -> unit
//   (** Gets the name of the table being accessed by a `Table.get` expression. *)

//   val get_index : t -> t
//   (** Gets the index expression of a `Table.get` expression. *)

//   val set_index : t -> t -> unit
//   (** Gets the index expression of a `Table.get` expression. *)
// end

// module Table_set : sig
//   val get_table : t -> string
//   (** Gets the name of the table being accessed by a `Table.set` expression. *)

//   val set_table : t -> string -> unit
//   (** Sets the name of the table being accessed by a `Table.set` expression. *)

//   val get_index : t -> t
//   (** Gets the index expression of a `Table.set` expression. *)

//   val set_index : t -> t -> unit
//   (** Sets the index expression of a `Table.set` expression. *)

//   val get_value : t -> t
//   (** Gets the value expression of a `Table.set` expression. *)

//   val set_value : t -> t -> unit
//   (** Sets the value expression of a `Table.set` expression. *)
// end

// module Table_size : sig
//   val get_table : t -> string
//   (** Gets the name of the table being accessed by a `Table.size` expression. *)

//   val set_table : t -> string -> unit
//   (** Sets the name of the table being accessed by a `Table.size` expression. *)
// end

// module Table_grow : sig
//   val get_table : t -> string
//   (** Gets the name of the table being accessed by a `Table.grow` expression. *)

//   val set_table : t -> string -> unit
//   (** Gets the name of the table being accessed by a `Table.grow` expression. *)

//   val get_value : t -> t
//   (** Gets the value expression of a `Table.grow` expression. *)

//   val set_value : t -> t -> unit
//   (** Sets the value expression of a `Table.grow` expression. *)

//   val get_delta : t -> t
//   (** Gets the delta of a `Table.grow` expression. *)

//   val set_delta : t -> t -> unit
//   (** Sets the delta of a `Table.grow` expression. *)
// end
