type segment = {
  name : string;
  passive : bool;
  offset : Expression.t;
  size : int;
}

val set_memory :
  Module.t -> int -> int -> string -> segment list -> bool -> unit
