open Module_test; // TODO: Document
open Literal_test; // TODO: Document
open Function_test; // TODO: Document
open Settings_test; // TODO: Document
open Type_test;
// TODO: Heap_Type (quick) (Blocked on gc)
// TODO: Array_Type (quick) (Blocked on gc)
// TODO: Struct_Type (quick) (Blocked on gc)
// TODO: Signature_Type (quick) (Blocked on gc)
// TODO: Packed_Type (quick) (Blocked on gc)
open Global_test; // TODO: Document
open Memory_test; // TODO: Document
open Table_test; // TODO: Document
open Element_segment_test; // TODO: Document
open Export_test; // TODO: Document
open Import_test; // TODO: Document
// TODO: Passes (Hard)
open Expression_test; // TODO: Document
// TODO: OP (Medium)

// (* Testing Return.get_value *)
// let _ =
//   assert (
//     Option.is_some
//       (Expression.Return.get_value
//          (Expression.Return.make wasm_mod
//             (Expression.Const.make wasm_mod (Literal.int32 0l)))))

// let _ =
//   assert (
//     Option.is_none
//       (Expression.Return.get_value
//          (Expression.Return.make wasm_mod (Expression.Null.make ()))))

// (* Create function type for i32 (i32, i32) *)
// let params () = Type.create [| Type.int32; Type.int32 |]
// let results = Type.int32
// let x () = Expression.Local_get.make wasm_mod 0 Type.int32
// let y () = Expression.Local_get.make wasm_mod 1 Type.int32

// let load =
//   Expression.Load.make wasm_mod 4 ~signed:false 0 0 Type.int32 (y ()) "0"

// let select =
//   Expression.Select.make wasm_mod
//     (Expression.Const.make wasm_mod (Literal.int32 1l))
//     (x ()) load

// let bin = Expression.Binary.make wasm_mod Op.add_int32 select (y ())

// let if_ =
//   Expression.If.make wasm_mod
//     (Expression.Const.make wasm_mod (Literal.int32 0l))
//     (Expression.Unreachable.make wasm_mod)
//     (Expression.Null.make ())

// let _ = assert (Expression.If.get_if_false if_ = None)

// let add =
//   Expression.Block.make wasm_mod ~return_type:Type.int32 "add" [ if_; bin ]

// let _ = assert (Expression.Block.get_name add = Some "add")

// (* Create the add function *)
// let _adder = Function.add_function wasm_mod "adder" (params ()) results [||] add

// let call_adder =
//   Expression.Call_indirect.make wasm_mod "table"
//     (Expression.Const.make wasm_mod (Literal.int32 0l))
//     [
//       Expression.Const.make wasm_mod (Literal.int32 3l);
//       Expression.Const.make wasm_mod (Literal.int32 5l);
//     ]
//     (params ()) Type.int32

// let start =
//   Function.add_function wasm_mod "start" Type.none Type.none [||]
//     (Expression.Block.make wasm_mod ~return_type:Type.none "start"
//        [
//          Expression.Memory_init.make wasm_mod "world"
//            (Expression.Const.make wasm_mod (Literal.int32 2048l))
//            (Expression.Const.make wasm_mod (Literal.int32 0l))
//            (Expression.Const.make wasm_mod (Literal.int32 5l))
//            "0";
//          Expression.Drop.make wasm_mod call_adder;
//        ])

// (* TODO(#240): Re-enable after type-builder api is merged *)
// (* let funcref_expr1 = Expression.Ref.func wasm_mod "adder" (Heap_type.func ())

// let _ =
//   Expression.Table.set wasm_mod "table"
//     (Expression.Const.make wasm_mod (Literal.int32 0l))
//     funcref_expr1 *)

// let funcref_expr2 =
//   Expression.Table.get wasm_mod "table"
//     (Expression.Const.make wasm_mod (Literal.int32 0l))
//     Type.funcref

// let _ = Expression.print funcref_expr2
// let table_size = Expression.Table.size wasm_mod "table"
// let _ = Expression.print table_size
// let table_name = Expression.Table_size.get_table table_size
// let _ = Expression.Table_size.set_table table_size table_name
// let null_ref = Expression.Ref.null wasm_mod Type.funcref

// let table_grow =
//   Expression.Table.grow wasm_mod "table" null_ref
//     (Expression.Const.make wasm_mod (Literal.int32 0l))

// let _ = Expression.print table_grow

// (* Create an imported "write" function i32 (externref, i32, i32) *)
// (* Similar to the example here: https://bytecodealliance.org/articles/reference-types-in-wasmtime *)

// (* Create a function that calls the imported write function *)
// let _ =
//   Function.add_function wasm_mod "hello" Type.anyref Type.int32 [||]
//     (Expression.Call.make wasm_mod "write"
//        [
//          Expression.Local_get.make wasm_mod 0 Type.anyref;
//          Expression.Const.make wasm_mod (Literal.int32 0l);
//          Expression.Const.make wasm_mod (Literal.int32 1l);
//        ]
//        Type.int32)

// let _ =
//   Module.run_passes new_mod
//     [
//       Passes.generate_global_effects;
//       Passes.name_types;
//       Passes.merge_similar_functions;
//       Passes.spill_pointers;
//       Passes.gufa;
//       Passes.gufa_optimizing;
//       Passes.reorder_globals;
//       Passes.optimize_casts;
//       Passes.multi_memory_lowering;
//       Passes.monomorphize;
//       Passes.signext_lowering;
//       Passes.discard_global_effects;
//       Passes.strip_eh;
//     ]
