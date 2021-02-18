open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

let none : t = global##.binaryen##.none

let int32 : t = global##.binaryen##.i32

let int64 : t = global##.binaryen##.i64

let float32 : t = global##.binaryen##.f32

let float64 : t = global##.binaryen##.f64

let vec128 : t = global##.binaryen##.v128

let funcref : t = global##.binaryen##.funcref

let externref : t = global##.binaryen##.externref

let unreachable : t = global##.binaryen##.unreachable

let auto : t = global##.binaryen##.auto

let create typs =
  meth_call global##.binaryen "createType" [| inject (array typs) |]
