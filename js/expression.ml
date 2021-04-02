open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

let block ?(return_type = Type.auto) wasm_mod name children =
  meth_call wasm_mod "block"
    [|
      inject (string name);
      inject (array (Array.of_list children));
      inject return_type;
    |]

let if_ wasm_mod cond if_true if_false =
  meth_call wasm_mod "if" [| inject cond; inject if_true; inject if_false |]

let loop wasm_mod name body =
  meth_call wasm_mod "loop" [| inject (string name); inject body |]

let break wasm_mod name cond res =
  meth_call wasm_mod "br" [| inject (string name); inject cond; inject res |]

let switch wasm_mod names default_name cond value =
  meth_call wasm_mod "switch"
    [|
      inject (array (Array.of_list (List.map string names)));
      inject (string default_name);
      inject cond;
      inject value;
    |]

let call wasm_mod name params return_typ =
  meth_call wasm_mod "call"
    [|
      inject (string name);
      inject (array (Array.of_list params));
      inject return_typ;
    |]

let call_indirect wasm_mod table target params params_typ return_typ =
  meth_call wasm_mod "call_indirect"
    [|
      inject (string table);
      inject target;
      inject (array (Array.of_list params));
      inject params_typ;
      inject return_typ;
    |]

let return_call wasm_mod name params return_typ =
  meth_call wasm_mod "return_call"
    [|
      inject (string name);
      inject (array (Array.of_list params));
      inject return_typ;
    |]

let return_call_indirect wasm_mod table target params params_typ return_typ =
  meth_call wasm_mod "return_call_indirect"
    [|
      inject (string table);
      inject target;
      inject (array (Array.of_list params));
      inject params_typ;
      inject return_typ;
    |]

let local_get wasm_mod slot typ =
  let scope = get wasm_mod "local" in
  meth_call scope "get" [| inject slot; inject typ |]

let local_set wasm_mod slot value =
  let scope = get wasm_mod "local" in
  meth_call scope "set" [| inject slot; inject value |]

let local_tee wasm_mod slot value typ =
  let scope = get wasm_mod "local" in
  meth_call scope "tee" [| inject slot; inject value; inject typ |]

let global_get wasm_mod name typ =
  let scope = get wasm_mod "global" in
  meth_call scope "get" [| inject (string name); inject typ |]

let global_set wasm_mod name value =
  let scope = get wasm_mod "global" in
  meth_call scope "set" [| inject (string name); inject value |]

let load wasm_mod byts ?(signed = false) offset align typ ptr =
  meth_call global##.binaryen "_BinaryenLoad"
    [|
      inject wasm_mod;
      inject byts;
      inject signed;
      inject offset;
      inject align;
      inject typ;
      inject ptr;
    |]

let store wasm_mod byts offset align ptr value typ =
  meth_call global##.binaryen "_BinaryenStore"
    [|
      inject wasm_mod;
      inject byts;
      inject offset;
      inject align;
      inject ptr;
      inject value;
      inject typ;
    |]

let const wasm_mod lit =
  let lit_hack = Literal.to_jsoo lit in
  match lit_hack with
  | Int32 value ->
      let scope = get wasm_mod "i32" in
      meth_call scope "const" [| inject value |]
  | Int64 (low, high) ->
      let scope = get wasm_mod "i64" in
      meth_call scope "const" [| inject low; inject high |]
  | Float32Bits value ->
      let scope = get wasm_mod "f32" in
      meth_call scope "const_bits" [| inject value |]
  | Float64Bits (low, high) ->
      let scope = get wasm_mod "f64" in
      meth_call scope "const_bits" [| inject low; inject high |]
  | Float32 value ->
      let scope = get wasm_mod "f32" in
      meth_call scope "const" [| inject value |]
  | Float64 value ->
      let scope = get wasm_mod "f64" in
      meth_call scope "const" [| inject value |]

let unary wasm_mod op p =
  meth_call global##.binaryen "_BinaryenUnary"
    [| inject wasm_mod; inject op; inject p |]

let binary wasm_mod op a b =
  meth_call global##.binaryen "_BinaryenBinary"
    [| inject wasm_mod; inject op; inject a; inject b |]

let select wasm_mod cond if_true if_false =
  meth_call wasm_mod "select"
    [| inject cond; inject if_true; inject if_false; inject Type.auto |]

let drop wasm_mod value = meth_call wasm_mod "drop" [| inject value |]

let return wasm_mod value = meth_call wasm_mod "return" [| inject value |]

let memory_size wasm_mod =
  let scope = get wasm_mod "memory" in
  meth_call scope "size" [||]

let memory_grow wasm_mod value =
  let scope = get wasm_mod "memory" in
  meth_call scope "grow" [| inject value |]

let nop wasm_mod = meth_call wasm_mod "nop" [||]

let unreachable wasm_mod = meth_call wasm_mod "unreachable" [||]

let memory_copy wasm_mod dest source size =
  let scope = get wasm_mod "memory" in
  meth_call scope "copy" [| inject dest; inject source; inject size |]

let memory_fill wasm_mod dest value size =
  let scope = get wasm_mod "memory" in
  meth_call scope "fill" [| inject dest; inject value; inject size |]

let tuple_make wasm_mod operands =
  let scope = get wasm_mod "tuple" in
  meth_call scope "make" [| inject (array (Array.of_list operands)) |]

let tuple_extract wasm_mod tuple index =
  let scope = get wasm_mod "tuple" in
  meth_call scope "extract" [| inject tuple; inject index |]

let pop wasm_mod typ =
  meth_call global##.binaryen "_BinaryenPop" [| inject wasm_mod; inject typ |]

let null () = pure_js_expr "null"

let print expr =
  let text = meth_call global##.binaryen "emitText" [| inject expr |] in
  print_string (to_string text)
