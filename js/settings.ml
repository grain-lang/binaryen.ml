open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

let get_optimize_level () = meth_call global##.binaryen "getOptimizeLevel" [||]

let set_optimize_level level =
  meth_call global##.binaryen "setOptimizeLevel" [| inject level |]

let get_shrink_level () = meth_call global##.binaryen "getShrinkLevel" [||]

let set_shrink_level level =
  meth_call global##.binaryen "setShrinkLevel" [| inject level |]

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let get_debug_info () = meth_call global##.binaryen "_BinaryenGetDebugInfo" [||]

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let set_debug_info on =
  meth_call global##.binaryen "_BinaryenSetDebugInfo" [| inject on |]

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let get_low_memory_unused () =
  meth_call global##.binaryen "_BinaryenGetLowMemoryUnused" [||]

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let set_low_memory_unused on =
  meth_call global##.binaryen "_BinaryenSetLowMemoryUnused" [| inject on |]

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

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let set_colors_enabled enabled =
  meth_call global##.binaryen "_BinaryenSetColorsEnabled" [| inject enabled |]

(* Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO *)
let are_colors_enabled () =
  meth_call global##.binaryen "_BinaryenAreColorsEnabled" [||]
