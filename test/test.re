open Module_test;
open Function_test;
open Settings_test;
open Type_test;
// TODO: Type
// TODO: Table
// TODO: Struct_Type
// TODO: Signature_Type
// TODO: Passes
// TODO: Packed_Type
// TODO: OP
// TODO: Memory
// TODO: Literal
// TODO: Import
// TODO: Heap_Type
// TODO: Global
// TODO: Expression
// TODO: Export
// TODO: Element_Segment
// TODO: Array_Type

// let wasm_mod = Module.create ()
// let _ = Module.set_features wasm_mod [ Module.Feature.all ]
// let import_wasm_mod = Module.create ()

// (* Testing pass_argument *)
// let _ = assert (Settings.get_pass_argument "theKey" = None)
// let _ = Settings.set_pass_argument "theKey" "theValue"
// let _ = assert (Settings.get_pass_argument "theKey" = Some "theValue")
// let _ = Settings.set_pass_argument "theKey" "theValue2"
// let _ = assert (Settings.get_pass_argument "theKey" = Some "theValue2")

// let _ =
//   Import.add_memory_import import_wasm_mod "internal_name" "external_name"
//     "external_base_name" true

// let _ =
//   assert (
//     Import.memory_import_get_module import_wasm_mod "internal_name"
//     = "external_name")

// let _ =
//   assert (
//     Import.memory_import_get_base import_wasm_mod "internal_name"
//     = "external_base_name")

// let _ = assert (Memory.is_shared import_wasm_mod "internal_name" = true)
// let _ = assert (Memory.is_64 import_wasm_mod "internal_name" = false)

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

// let _ = Export.add_function_export wasm_mod "adder" "adder"
// let _ = Table.add_table wasm_mod "table" 1 1 Type.funcref

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

// let _ =
//   Global.add_global wasm_mod "max_int64" Type.int64 false
//     (Expression.Const.make wasm_mod (Literal.int64 Int64.max_int))

// let _ =
//   Global.add_global wasm_mod "max_int64_mut" Type.int64 true
//     (Expression.Const.make wasm_mod (Literal.int64 Int64.max_int))

// let _ =
//   Global.add_global wasm_mod "test_float64_bits" Type.float64 false
//     (Expression.Const.make wasm_mod (Literal.float64_bits 0x3FF3AE147AE147AEL))

// let _ =
//   Table.add_active_element_segment wasm_mod "table" "elem" [ "adder" ]
//     (Expression.Const.make wasm_mod (Literal.int32 0l))

// let _ = Function.set_start wasm_mod start
// let start_func = Function.get_start wasm_mod
// let _ = assert (Function.get_name start_func = "start")

// let segment : Binaryen.Memory.segment =
//   let data = Bytes.of_string "hello" in
//   let kind =
//     Binaryen.Memory.Active
//       { offset = Expression.Const.make wasm_mod (Literal.int32 0l) }
//   in
//   let size = Bytes.length data in
//   { name = "hello"; data; kind; size }

// let passive_segment : Binaryen.Memory.segment =
//   let data = Bytes.of_string "world" in
//   let kind = Binaryen.Memory.Passive in
//   let size = Bytes.length data in
//   { name = "world"; data; kind; size }

// let _ = assert (Memory.has_memory wasm_mod = false)

// let _ =
//   Memory.set_memory wasm_mod 1 Memory.unlimited "memory"
//     [ segment; passive_segment ]
//     false false "0"

// let _ = assert (Memory.has_memory wasm_mod = true)
// let _ = assert (Memory.get_initial wasm_mod "0" = 1)
// let _ = assert (Memory.has_max wasm_mod "0" = false)
// let _ = assert (Memory.get_max wasm_mod "0" = Memory.unlimited)
// let max_memory_wasm_mod = Module.create ()
// let _ = Memory.set_memory max_memory_wasm_mod 1 2 "memory" [] false false "0"
// let _ = assert (Memory.has_max max_memory_wasm_mod "0" = true)
// let _ = assert (Memory.get_max max_memory_wasm_mod "0" = 2)

// let _ =
//   assert (
//     Bytes.equal
//       (Memory.get_segment_data wasm_mod "world")
//       (Bytes.of_string "world"))

// (* Create an imported "write" function i32 (externref, i32, i32) *)
// (* Similar to the example here: https://bytecodealliance.org/articles/reference-types-in-wasmtime *)

// let _ =
//   Import.add_function_import wasm_mod "write" "future-wasi" "write"
//     (Type.create [| Type.anyref; Type.int32; Type.int32 |])
//     Type.int32

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

// let _ = Export.add_function_export wasm_mod "hello" "hello"
// let _ = Module.validate wasm_mod

// let new_mod = Module.read byts

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
