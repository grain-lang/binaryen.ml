external set_memory :
  Module.t ->
  int ->
  int ->
  string ->
  bytes list ->
  bool list ->
  Expression.t list ->
  int list ->
  bool ->
  bool ->
  string ->
  unit = "caml_binaryen_set_memory__bytecode" "caml_binaryen_set_memory"

type segment = { data : bytes; kind : segment_kind; size : int }
and segment_kind = Passive | Active of { offset : Expression.t }

(** Module, initial size, maximum size, export name, segments, shared, memory64, moduleName . *)
let set_memory wasm_mod initial maximum export_name (segments : segment list)
    shared memory64 moduleName =
  let split_segments segments =
    List.fold_right
      (fun { data; kind; size }
           (segment_data, segment_passive, segment_offsets, segment_sizes) ->
        match kind with
        | Active { offset } ->
            ( data :: segment_data,
              false :: segment_passive,
              offset :: segment_offsets,
              size :: segment_sizes )
        | Passive ->
            ( data :: segment_data,
              true :: segment_passive,
              Expression.Null.make () :: segment_offsets,
              size :: segment_sizes ))
      segments ([], [], [], [])
  in
  let segment_data, segment_passive, segment_offsets, segment_sizes =
    split_segments segments
  in
  set_memory wasm_mod initial maximum export_name segment_data segment_passive
    segment_offsets segment_sizes shared memory64 moduleName

external has_memory : Module.t -> bool = "caml_binaryen_has_memory"

external get_initial : Module.t -> string -> int
  = "caml_binaryen_memory_get_initial"

external has_max : Module.t -> string -> bool = "caml_binaryen_memory_has_max"
external get_max : Module.t -> string -> int = "caml_binaryen_memory_get_max"

external is_shared : Module.t -> string -> bool
  = "caml_binaryen_memory_is_shared"

external is_64 : Module.t -> string -> bool = "caml_binaryen_memory_is_64"

let unlimited = -1

external get_num_segments : Module.t -> int
  = "caml_binaryen_get_num_memory_segments"

external get_segment_byte_offset : Module.t -> int -> int
  = "caml_binaryen_get_memory_segment_byte_offset"

external get_segment_passive : Module.t -> int -> bool
  = "caml_binaryen_get_memory_segment_passive"

external get_segment_data : Module.t -> int -> bytes
  = "caml_binaryen_get_memory_segment_data"
