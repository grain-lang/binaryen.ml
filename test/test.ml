open Binaryen

(* Testing colors enable *)
let _ = assert (Settings.are_colors_enabled () == true)

let _ = Settings.set_colors_enabled false

let _ = assert (Settings.are_colors_enabled () == false)

let _ = Settings.set_colors_enabled true

(* Testing debug_info enable *)
let _ = assert (Settings.get_debug_info () == false)

let _ = Settings.set_debug_info true

let _ = assert (Settings.get_debug_info () == true)

let _ = Settings.set_debug_info false

(* Testing low_memory_unused enable *)
let _ = assert (Settings.get_low_memory_unused () == false)

let _ = Settings.set_low_memory_unused true

let _ = assert (Settings.get_low_memory_unused () == true)

let _ = Settings.set_low_memory_unused false

let wasm_mod = Module.create ()

let _ = Module.set_features wasm_mod [ Module.Feature.all ]

(* Create function type for i32 (i32, i32) *)
let params () = Type.create [| Type.int32; Type.int32 |]

let results = Type.int32

let x () = Expression.Local_get.make wasm_mod 0 Type.int32

let y () = Expression.Local_get.make wasm_mod 1 Type.int32

let load = Expression.Load.make wasm_mod 1 ~signed:true 0 0 Type.int32 (y ())

let select =
  Expression.Select.make wasm_mod
    (Expression.Const.make wasm_mod (Literal.int32 1l))
    (x ()) load

let bin = Expression.Binary.make wasm_mod Op.add_int32 select (y ())

let add =
  Expression.Block.make wasm_mod ~return_type:Type.int32 "add"
    [
      Expression.If.make wasm_mod
        (Expression.Const.make wasm_mod (Literal.int32 0l))
        (Expression.Unreachable.make wasm_mod)
        (Expression.Null.make ());
      bin;
    ]

(* Create the add function *)
let adder = Function.add_function wasm_mod "adder" (params ()) results [||] add

let call_adder =
  Expression.Call_indirect.make wasm_mod "table"
    (Expression.Const.make wasm_mod (Literal.int32 0l))
    [
      Expression.Const.make wasm_mod (Literal.int32 3l);
      Expression.Const.make wasm_mod (Literal.int32 5l);
    ]
    (params ()) Type.int32

let start =
  Function.add_function wasm_mod "start" Type.none Type.none [||]
    (Expression.Drop.make wasm_mod call_adder)

let _ = Export.add_function_export wasm_mod "adder" "adder"

let _ = Table.add_table wasm_mod "table" 1 1 Type.funcref

let _ =
  Global.add_global wasm_mod "max_int64" Type.int64 false
    (Expression.Const.make wasm_mod (Literal.int64 Int64.max_int))

let _ =
  Global.add_global wasm_mod "test_float64_bits" Type.float64 false
    (Expression.Const.make wasm_mod (Literal.float64_bits 0x3FF3AE147AE147AEL))

let _ =
  Table.add_active_element_segment wasm_mod "table" "elem" [ "adder" ]
    (Expression.Const.make wasm_mod (Literal.int32 0l))

let _ = Function.set_start wasm_mod start

let _ = Memory.set_memory wasm_mod 1 Memory.unlimited "memory" [] false

(* Create an imported "write" function i32 (externref, i32, i32) *)
(* Similar to the example here: https://bytecodealliance.org/articles/reference-types-in-wasmtime *)

let _ =
  Import.add_function_import wasm_mod "write" "future-wasi" "write"
    (Type.create [| Type.externref; Type.int32; Type.int32 |])
    Type.int32

(* Create a function that calls the imported write function *)
let _ =
  Function.add_function wasm_mod "hello" Type.externref Type.int32 [||]
    (Expression.Call.make wasm_mod "write"
       [
         Expression.Local_get.make wasm_mod 0 Type.externref;
         Expression.Const.make wasm_mod (Literal.int32 0l);
         Expression.Const.make wasm_mod (Literal.int32 1l);
       ]
       Type.int32)

let _ = Export.add_function_export wasm_mod "hello" "hello"

(* Shouldn't actually do anything since we aren't doing function renames *)
let _ = Module.update_maps wasm_mod

(* Finally, we print 3 versions of the module to be checked against test.expected *)

(* 1. Print the the module as-is *)

let _ = Module.print wasm_mod

(* 2. Optimize, then print the module *)

let _ = Module.optimize wasm_mod

let _ = Module.print wasm_mod

(* 3. Copy previous module bytes into new module, validate, and print *)

let byts, _ = Module.write wasm_mod None

let new_mod = Module.read byts

let _ =
  Module.set_features new_mod
    [
      Module.Feature.mvp;
      Module.Feature.atomics;
      Module.Feature.bulk_memory;
      Module.Feature.mutable_globals;
      Module.Feature.nontrapping_fp_to_int;
      Module.Feature.sign_ext;
      Module.Feature.simd128;
      Module.Feature.exception_handling;
      Module.Feature.tail_call;
      Module.Feature.reference_types;
      Module.Feature.multivalue;
      Module.Feature.gc;
      Module.Feature.memory64;
      Module.Feature.typed_function_references;
      Module.Feature.relaxed_simd;
      Module.Feature.all;
    ]

let _ = Module.validate new_mod

let _ = Module.print new_mod

(* Dispose the modules 👋 *)

let _ = Module.dispose wasm_mod

let _ = Module.dispose new_mod
