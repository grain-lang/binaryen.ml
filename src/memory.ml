external set_memory :
  Module.t ->
  int ->
  int ->
  string ->
  string list ->
  bool list ->
  Expression.t list ->
  int list ->
  bool ->
  unit = "caml_binaryen_set_memory__bytecode" "caml_binaryen_set_memory"

type segment = {
  name : string;
  passive : bool;
  offset : Expression.t;
  size : int;
}

(** Module, initial size, maximum size, export name, segments, shared. *)
let set_memory wasm_mod initial maximum export_name (segments : segment list)
    shared =
  let split_segments segments =
    List.fold_right
      (fun { name; passive; offset; size }
           (segment_names, segment_passive, segment_offsets, segment_sizes) ->
        ( name :: segment_names,
          passive :: segment_passive,
          offset :: segment_offsets,
          size :: segment_sizes ))
      segments ([], [], [], [])
  in
  let segment_names, segment_passive, segment_offsets, segment_sizes =
    split_segments segments
  in
  set_memory wasm_mod initial maximum export_name segment_names segment_passive
    segment_offsets segment_sizes shared

let unlimited = -1
