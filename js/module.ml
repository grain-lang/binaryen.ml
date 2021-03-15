open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

external u8a_to_bytes : 'a -> bytes = "caml_bytes_of_array"

(* TODO: Verify this converts to bytes correctly? *)
external bytes_to_u8a : bytes -> 'a = "caml_array_of_bytes"

external string_to_u8a : string -> 'a = "caml_array_of_string"

type t

let create () = new_obj global ##. binaryen ##. Module [||]

let dispose wasm_mod = ignore (meth_call wasm_mod "dispose" [||])

(* TODO: Check the unit8Array conversion *)
let add_custom_section wasm_mod name contents =
  let contents = string_to_u8a contents in
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

let write wasm_mod sourcemap_url =
  match sourcemap_url with
  | Some url ->
      let obj = meth_call wasm_mod "emitBinary" [| inject url |] in
      let binary = get obj "binary" in
      let soucemap = get obj "soureMap" in
      (u8a_to_bytes binary, Some soucemap)
  | None ->
      let binary = meth_call wasm_mod "emitBinary" [||] in
      (u8a_to_bytes binary, None)

let write_text wasm_mod =
  let text = meth_call wasm_mod "emitText" [||] in
  to_string text

let read byts =
  let data = bytes_to_u8a byts in
  meth_call global##.binaryen "readBinary" [| inject data |]

let interpret wasm_mod = meth_call wasm_mod "interpret" [||]

let add_debug_info_filename wasm_mod filename =
  meth_call wasm_mod "addDebugInfoFileName" [| inject (string filename) |]

let get_debug_info_filename wasm_mod index =
  meth_call wasm_mod "getDebugInfoFileName" [| inject index |]
