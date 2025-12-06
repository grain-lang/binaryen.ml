type t
(** Represents a Binaryen wasm type. *)

val none : t
(** The none type, e.g., [void.] *)

val int32 : t
(** The 32-bit integer type. *)

val int64 : t
(** The 64-bit integer type. *)

val float32 : t
(** The 32-bit float type. *)

val float64 : t
(** The 64-bit float type. *)

val vec128 : t
(** The 128-bit vector type. *)

val funcref : t
(** The function reference type. *)

val anyref : t
(** The any reference type. *)

val eqref : t
(** The eq reference type. *)

val i31ref : t
(** The i31 reference type. *)

val structref : t
(** The struct reference type. *)

val arrayref : t
(** The array reference type. *)

val stringref : t
(** The string reference type. *)

val nullref : t
(** The null reference type. *)

val null_externref : t
(** The null external reference type. *)

val null_funcref : t
(** The null function reference type. *)

val unreachable : t
(** A special type indicating unreachable code when obtaining information about
    an expression. *)

val auto : t
(** A special type used in [Expression.Block] exclusively. Lets the API figure
    out a block's result type automatically. *)

val create : t array -> t
(** Creates a multi-value type from an array of types.
    @param Types The array of types
    @return The multi-value type *)

val expand : t -> t array
(** Expands a multi-value type to an array of types.
    @param type The multi-value type
    @return The types in the multi-value type *)

val is_nullable : t -> bool
(** Weather the given type is nullable.
    @param type The type to check
    @return [true] if the type is nullable, [false] otherwise *)

val from_heap_type : Heap_type.t -> t
(** Produces a regular type from the given heap type.
    @param heap_type The heap type
    @return The corresponding type *)

val get_heap_type : t -> Heap_type.t
(** Gets the heap type of the given type.
    @param type The type
    @return The corresponding heap type *)
