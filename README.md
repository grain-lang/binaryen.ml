# Binaryen.ml

![Binaryen.ml CI Workflow](https://github.com/grain-lang/binaryen.ml/workflows/Binaryen.ml%20CI%20Workflow/badge.svg)

OCaml bindings for [Binaryen](https://github.com/WebAssembly/binaryen).

Binaryen is a compiler and toolchain infrastructure for WebAssembly. It makes compilation to WebAssembly pretty darn easy.

Here's Binaryen's [hello world test](https://github.com/WebAssembly/binaryen/blob/master/test/example/c-api-hello-world.c) in OCaml form:

```ocaml
open Binaryen

let wasm_mod = Module.create ()

(* Create function type for i32 (i32, i32) *)
let params = Type.create [| Type.int32; Type.int32 |]
let results = Type.int32

(* Get arguments 0 and 1, add them *)
let x = Expression.local_get wasm_mod 0 Type.int32
let y = Expression.local_get wasm_mod 1 Type.int32
let add = Expression.binary wasm_mod Op.add_int32 x y

(* Create the add function *)
(* Note: no additional local variables *)
let adder = Function.add_function wasm_mod "adder" params results [||] add

let _ = Module.print wasm_mod
let _ = Module.dispose wasm_mod
```

## Feature Parity

This project aims to provide full feature parity with the [Binaryen C API](https://github.com/WebAssembly/binaryen/blob/master/src/binaryen-c.h). It's fairly complete, but a few things still need bindings:

- SIMD instructions
- Events
- Atomics
- Query operations on expressions
- Query operations on functions

None of these are particularly challenging to create bindings for—they just haven't been written yet. If you need anything that's missing, feel free to open a PR.

## Static Linking

If you are planning to create portable binaries for Windows, it will try to find Cygwin/MinGW locations in your `PATH`. To avoid this, you probably want to add this to your `(executable)` stanzas:

```diff
 (executable
  (name example)
  (public_name example)
  (package example)
+ (flags (:standard -ccopt -- -ccopt -static))
  (modules example)
  (libraries binaryen))
```

These flags might not work on other operating systems (like MacOS), so you'll probably need to use `dune-configurator` to vary the flags per platform.

## Contributing

You'll need Node.js and [`esy`](https://esy.sh/docs/en/getting-started.html#install-esy) to build this project.

`dune` will take care of compiling the C stubs, so to build the project you'll only need to run:

```bash
esy
```

This will take a while. Once it's done, you can run the tests:

```bash
esy test
```
