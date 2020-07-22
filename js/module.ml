open Js_of_ocaml
open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t

let create () = new_obj global ##. binaryen ##. Module [||]

let dispose wasm_mod = ignore (meth_call wasm_mod "dispose" [||])

(* TODO: Check the unit8Array conversion *)
let add_custom_section wasm_mod name contents =
  let contents =
    meth_call Typed_array.uint8Array "from" [| inject (string contents) |]
  in
  ignore
    (meth_call wasm_mod "addCustomSection"
       [| inject (string name); inject contents |])

let parse text =
  meth_call global##.binaryen "parseText" [| inject (string text) |]

let print wasm_mod =
  let text = meth_call wasm_mod "emitText" [||] in
  print_string (to_string text)

let print_asmjs wasm_mod =
  let asm = meth_call wasm_mod "emitAsmjs" [||] in
  print_string (to_string asm)

let validate wasm_mod = meth_call wasm_mod "validate" [||]

let optimize wasm_mod = meth_call wasm_mod "optimize" [||]

let set_features wasm_mod features =
  meth_call wasm_mod "setFeatures"
    [| inject (List.fold_left ( lor ) 0 features) |]

let get_optimize_level () = meth_call global##.binaryen "getOptimizeLevel" [||]

let set_optimize_level level =
  meth_call global##.binaryen "setOptimizeLevel" [| inject level |]

let get_shrink_level () = meth_call global##.binaryen "getShrinkLevel" [||]

let set_shrink_level level =
  meth_call global##.binaryen "setShrinkLevel" [| inject level |]

let get_debug_info () = meth_call global##.binaryen "getDebugInfo" [||]

let set_debug_info on =
  meth_call global##.binaryen "setDebugInfo" [| inject on |]

let get_low_memory_unused () =
  meth_call global##.binaryen "getLowMemoryUnused" [||]

let set_low_memory_unused on =
  meth_call global##.binaryen "setLowMemoryUnused" [| inject on |]

let get_pass_argument key =
  meth_call global##.binaryen "getPassArgument" [| inject (string key) |]

let set_pass_argument key value =
  meth_call global##.binaryen "setPassArgument"
    [| inject (string key); inject (string value) |]

let get_always_inline_max_size () =
  meth_call global##.binaryen "getAlwaysInlineMaxSize" [||]

let set_always_inline_max_size size =
  meth_call global##.binaryen "setAlwaysInlineMaxSize" [| inject size |]

let get_flexible_inline_max_size () =
  meth_call global##.binaryen "getFlexibleInlineMaxSize" [||]

let set_flexible_inline_max_size size =
  meth_call global##.binaryen "setFlexibleInlineMaxSize" [| inject size |]

let get_one_caller_inline_max_size () =
  meth_call global##.binaryen "getOneCallerInlineMaxSize" [||]

let set_one_caller_inline_max_size size =
  meth_call global##.binaryen "setOneCallerInlineMaxSize" [| inject size |]

let run_passes wasm_mod passes =
  meth_call wasm_mod "runPasses"
    [| inject (array (Array.of_list (List.map string passes))) |]

let auto_drop wasm_mod = meth_call wasm_mod "autoDrop" [||]

let uint8array_to_bytes u8a =
  Bytes.of_string (Typed_array.String.of_uint8Array u8a)

let bytes_to_uint8array byts =
  meth_call Typed_array.uint8Array "from"
    [| inject (string (Bytes.to_string byts)) |]

(* TODO: This returns the wrong type, need to convert from `Uint8Array` to `bytes` *)
let write wasm_mod sourcemap_url =
  match sourcemap_url with
  | Some url ->
      let obj = meth_call wasm_mod "emitBinary" [| inject url |] in
      let binary = get obj "binary" in
      let soucemap = get obj "soureMap" in
      (uint8array_to_bytes binary, Some soucemap)
  | None ->
      let binary = meth_call wasm_mod "emitBinary" [||] in
      (uint8array_to_bytes binary, None)

let write_text wasm_mod =
  let text = meth_call wasm_mod "emitText" [||] in
  to_string text

(* TODO: This doesn't handle `bytes` correctly *)
let read byts =
  let data = bytes_to_uint8array byts in
  meth_call global##.binaryen "readBinary" [| inject data |]

let interpret wasm_mod = meth_call wasm_mod "interpret" [||]

let add_debug_info_filename wasm_mod filename =
  meth_call wasm_mod "addDebugInfoFileName" [| inject (string filename) |]

let get_debug_info_filename wasm_mod index =
  meth_call wasm_mod "getDebugInfoFileName" [| inject index |]
