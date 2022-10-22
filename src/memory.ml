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
  unit = "caml_binaryen_set_memory__bytecode" "caml_binaryen_set_memory"

type segment = { data : bytes; kind : segment_kind; size : int }
and segment_kind = Passive | Active of { offset : Expression.t }

(** Module, initial size, maximum size, export name, segments, shared. *)
let set_memory wasm_mod initial maximum export_name (segments : segment list)
    shared =
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
    segment_offsets segment_sizes shared

external has_memory : Module.t -> bool = "caml_binaryen_has_memory"

external get_initial : Module.t -> int = "caml_binaryen_memory_get_initial"

external has_max : Module.t -> bool = "caml_binaryen_memory_has_max"

external get_max : Module.t -> int = "caml_binaryen_memory_get_max"

external is_shared : Module.t -> bool = "caml_binaryen_memory_is_shared"

let unlimited = -1
