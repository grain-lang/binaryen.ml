open Js_of_ocaml.Js.Unsafe

let mvp : int = global ##. binaryen ##. Features ##. MVP

let atomics : int = global ##. binaryen ##. Features ##. Atomics

let bulk_memory : int = global ##. binaryen ##. Features ##. BulkMemory

let mutable_globals : int = global ##. binaryen ##. Features ##. MutableGlobals

let nontrapping_fp_to_int : int =
  global ##. binaryen ##. Features ##. NontrappingFPToInt

let sign_ext : int = global ##. binaryen ##. Features ##. SignExt

let simd128 : int = global ##. binaryen ##. Features ##. SIMD128

let exception_handling : int =
  global ##. binaryen ##. Features ##. ExceptionHandling

let tail_call : int = global ##. binaryen ##. Features ##. TailCall

let reference_types : int = global ##. binaryen ##. Features ##. ReferenceTypes

let multivalue : int = global ##. binaryen ##. Features ##. Multivalue

let all : int = global ##. binaryen ##. Features ##. All
