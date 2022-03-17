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
let x = Expression.Local_get.make wasm_mod 0 Type.int32
let y = Expression.Local_get.make wasm_mod 1 Type.int32
let add = Expression.Binary.make wasm_mod Op.add_int32 x y

(* Create the add function *)
(* Note: no additional local variables *)
let adder = Function.add_function wasm_mod "adder" params results [||] add

let _ = Module.print wasm_mod
let _ = Module.dispose wasm_mod
```

## Feature Parity

This project aims to provide full feature parity with the [Binaryen C API](https://github.com/WebAssembly/binaryen/blob/master/src/binaryen-c.h). It's fairly complete, but a few things still need bindings:

- SIMD instructions
- Tags
- Atomics
- Query operations on expressions
- Query operations on functions

None of these are particularly challenging to create bindings for—they just haven't been written yet. If you need anything that's missing, feel free to open a PR.

## MacOS C++ Compiler

When including this library in your `dune` MacOS executables, you'll need to specify `-cc clang++` in your `(ocamlopt_flags)` stanza. This is required because Binaryen will throw errors for itself to catch and using `clang++` is the only way to handle them correctly. You can find more info on this [ocaml issue](https://github.com/ocaml/ocaml/issues/10423).

Your stanza could look something like this:

```diff
 (executable
  (name example)
  (public_name example)
  (package example)
+ (ocamlopt_flags -cc clang++)
  (modules example)
  (libraries binaryen))
```

These flags likely won't work on other operating systems, so you'll probably need to use `dune-configurator` to vary the flags per platform. You can see an example of this in our [tests/](./tests/dune).

## MacOS DWARF & Compact unwind

When including this library in your `dune` MacOS executables, you might want to specify `-cclib -Wl,-keep_dwarf_unwind -cclib -Wl,-no_compact_unwind` in your `(ocamlopt_flags)` stanza. If you don't include them, you'll probably see warnings like:

```log
ld: warning: could not create compact unwind for _caml_start_program: dwarf uses DW_CFA_same_value
ld: warning: could not create compact unwind for _caml_raise_exn: stack subq instruction is too different from dwarf stack size
ld: warning: could not create compact unwind for _caml_raise_exception: stack subq instruction is too different from dwarf stack size
```

Your stanza could look something like this:

```diff
 (executable
  (name example)
  (public_name example)
  (package example)
+ (ocamlopt_flags -cclib -Wl,-keep_dwarf_unwind -cclib -Wl,-no_compact_unwind)
  (modules example)
  (libraries binaryen))
```

These flags likely won't work on other operating systems, so you'll probably need to use `dune-configurator` to vary the flags per platform. You can see an example of this in our [tests/](./tests/dune).

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

## JavaScript

When compiling to JavaScript with `js_of_ocaml`, you'll need to add the `--disable share` flag. This is needed until we can depend on the bug fix from [ocsigen/js_of_ocaml#1249](https://github.com/ocsigen/js_of_ocaml/pull/1249). In the meantime, you can change your dune file:

```diff
 (executable
  (name example)
  (public_name example)
  (modes
   (byte js))
+ (js_of_ocaml
+  (flags --disable share))
  (modules example)
  (libraries binaryen))
```

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
