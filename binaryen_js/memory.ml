open Js_of_ocaml
open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type segment = {
  name : string;
  passive : bool;
  offset : Expression.t;
  size : int;
}

(** Module, initial size, maximum size, export name, segments, shared. *)
let set_memory wasm_mod initial maximum export_name (segments : segment list)
    shared =
  let segs =
    List.map
      (fun { name; passive; offset; _ } ->
        let data =
          meth_call Typed_array.uint8Array "from" [| inject (string name) |]
        in
        obj
          [|
            ("data", data);
            ("passive", inject passive);
            ("offset", inject offset);
          |])
      segments
  in
  meth_call wasm_mod "setMemory"
    [|
      inject initial;
      inject maximum;
      inject (string export_name);
      inject (array (Array.of_list segs));
      inject undefined;
      inject (if shared then _true else _false);
    |]
