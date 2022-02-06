open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

module Feature = struct
  type t = int

  let mvp : t = global ##. binaryen ##. Features ##. MVP

  let atomics : t = global ##. binaryen ##. Features ##. Atomics

  let bulk_memory : t = global ##. binaryen ##. Features ##. BulkMemory

  let mutable_globals : t = global ##. binaryen ##. Features ##. MutableGlobals

  let nontrapping_fp_to_int : t =
    global ##. binaryen ##. Features ##. NontrappingFPToInt

  let sign_ext : t = global ##. binaryen ##. Features ##. SignExt

  let simd128 : t = global ##. binaryen ##. Features ##. SIMD128

  let exception_handling : t =
    global ##. binaryen ##. Features ##. ExceptionHandling

  let tail_call : t = global ##. binaryen ##. Features ##. TailCall

  let reference_types : t = global ##. binaryen ##. Features ##. ReferenceTypes

  let multivalue : t = global ##. binaryen ##. Features ##. Multivalue

  let gc : t = global ##. binaryen ##. Features ##. GC

  let memory64 : t = global ##. binaryen ##. Features ##. Memory64

  let typed_function_references : t =
    global ##. binaryen ##. Features ##. TypedFunctionReferences

  let relaxed_simd : t = global ##. binaryen ##. Features ##. RelaxedSIMD

  let all : t = global ##. binaryen ##. Features ##. All
end

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

let get_features wasm_mod =
  let features_int = meth_call wasm_mod "getFeatures" [||] in
  let rec split_features = function
    | 0 -> []
    | feature when features_int land feature > 0 ->
        feature :: split_features (feature lsr 1)
    | feature -> split_features (feature lsr 1)
  in
  (* Support 32-bit OCaml where integers are 31 bits *)
  (* This supports up to 31 Binaryen features *)
  split_features 0x40000000

let set_features wasm_mod features =
  meth_call wasm_mod "setFeatures"
    [| inject (List.fold_left ( lor ) 0 features) |]

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

(* The JS version doesn't expose `update_maps` *)
let update_maps wasm_mod = ()
