type t

val alignment_lowering : t
(** lower unaligned loads and stores to smaller aligned ones *)

val asyncify : t
(** async/await style transform, allowing pausing and resuming *)

val avoid_reinterprets : t
(** Tries to avoid reinterpret operations via more loads *)

val dae : t
(** removes arguments to calls in an lto-like manner *)

val dae_optimizing : t
(** removes arguments to calls in an lto-like manner, and optimizes where we removed *)

val coalesce_locals : t
(** reduce # of locals by coalescing *)

val coalesce_locals_learning : t
(** reduce # of locals by coalescing and learning *)

val code_pushing : t
(** push code forward, potentially making it not always execute *)

val code_folding : t
(** fold code, merging duplicates *)

val const_hoisting : t
(** hoist repeated constants to a local *)

val cfp : t
(** propagate constant struct field values *)

val dce : t
(** removes unreachable code *)

val dealign : t
(** forces all loads and stores to have alignment 1 *)

val denan : t
(** instrument the wasm to convert NaNs into 0 at runtime *)

val directize : t
(** turns indirect calls into direct ones *)

val dfo : t
(** optimizes using the DataFlow SSA IR *)

val dwarfdump : t
(** dump DWARF debug info sections from the read binary *)

val duplicate_import_elimination : t
(** removes duplicate imports *)

val duplicate_function_elimination : t
(** removes duplicate functions *)

val emit_target_features : t
(** emit the target features section in the output *)

val extract_function : t
(** leaves just one function (useful for debugging) *)

val extract_function_index : t
(** leaves just one function selected by index *)

val flatten : t
(** flattens out code, removing nesting *)

val fpcast_emu : t
(** emulates function pointer casts, allowing incorrect indirect calls to (sometimes) work *)

val func_metrics : t
(** reports function metrics *)

val generate_dyncalls : t
(** generate dynCall fuctions used by emscripten ABI *)

val generate_i64_dyncalls : t
(** generate dynCall functions used by emscripten ABI, but only for functions with i64 in their signature (which cannot be invoked via the wasm table without JavaScript BigInt support). *)

val generate_stack_ir : t
(** generate Stack IR *)

val global_refining : t
(** refine the types of globals *)

val gto : t
(** globally optimize GC types *)

val type_refining : t
(** apply more specific subtypes to type fields where possible *)

val heap2local : t
(** replace GC allocations with locals *)

val inline_main : t
(** inline __original_main into main *)

val inlining : t
(** inline functions (you probably want inlining-optimizing) *)

val inlining_optimizing : t
(** inline functions and optimizes where we inlined *)

val intrinsic_lowering : t
(** lower away binaryen intrinsics *)

val legalize_js_interface : t
(** legalizes i64 types on the import/export boundary *)

val legalize_js_interface_minimally : t
(** legalizes i64 types on the import/export boundary in a minimal manner, only on things only JS will call *)

val local_cse : t
(** common subexpression elimination inside basic blocks *)

val local_subtyping : t
(** apply more specific subtypes to locals where possible *)

val log_execution : t
(** instrument the build with logging of where execution goes *)

val i64_to_i32_lowering : t
(** lower all uses of i64s to use i32s instead *)

val instrument_locals : t
(** instrument the build with code to intercept all loads and stores *)

val instrument_memory : t
(** instrument the build with code to intercept all loads and stores *)

val licm : t
(** loop invariant code motion *)

val limit_segments : t
(** attempt to merge segments to fit within web limits *)

val memory64_lowering : t
(** lower loads and stores to a 64-bit memory to instead use a 32-bit one *)

val memory_packing : t
(** packs memory into separate segments, skipping zeros *)

val merge_blocks : t
(** merges blocks to their parents *)

val merge_similar_functions : t
(** merges similar functions when benefical *)

val merge_locals : t
(** merges locals when beneficial *)

val metrics : t
(** reports metrics *)

val minify_imports : t
(** minifies import names (only those, and not export names), and emits a mapping to the minified ones *)

val minify_imports_and_exports : t
(** minifies both import and export names, and emits a mapping to the minified ones *)

val minify_imports_and_exports_and_modules : t
(** minifies both import and export names, and emits a mapping to the minified ones, and minifies the modules as well *)

val mod_asyncify_always_and_only_unwind : t
(** apply the assumption that asyncify imports always unwind, and we never rewind *)

val mod_asyncify_never_unwind : t
(** apply the assumption that asyncify never unwinds *)

val nm : t
(** name list *)

val name_types : t
(** (re)name all heap types *)

val once_reduction : t
(** reduces calls to code that only runs once *)

val optimize_added_constants : t
(** optimizes added constants into load/store offsets *)

val optimize_added_constants_propagate : t
(** optimizes added constants into load/store offsets, propagating them across locals too *)

val optimize_instructions : t
(** optimizes instruction combinations *)

val optimize_stack_ir : t
(** optimize Stack IR *)

val pick_load_signs : t
(** pick load signs based on their uses *)

val poppify : t
(** Tranform Binaryen IR into Poppy IR *)

val post_emscripten : t
(** miscellaneous optimizations for Emscripten-generated code *)

val optimize_for_js : t
(** early optimize of the instruction combinations for js *)

val precompute : t
(** computes compile-time evaluatable expressions *)

val precompute_propagate : t
(** computes compile-time evaluatable expressions and propagates them through locals *)

val print : t
(** print in s-expression format *)

val print_minified : t
(** print in minified s-expression format *)

val print_features : t
(** print options for enabled features *)

val print_full : t
(** print in full s-expression format *)

val print_call_graph : t
(** print call graph *)

val print_function_map : t
(** print a map of function indexes to names *)

val symbolmap : t
(** alias for print_function_map *)

val print_stack_ir : t
(** print out Stack IR (useful for internal debugging) *)

val remove_non_js_ops : t
(** removes operations incompatible with js *)

val remove_imports : t
(** removes imports and replaces them with nops *)

val remove_memory : t
(** removes memory segments *)

val remove_unused_brs : t
(** removes breaks from locations that are not needed *)

val remove_unused_module_elements : t
(** removes unused module elements *)

val remove_unused_nonfunction_module_elements : t
(** removes unused module elements that are not functions *)

val remove_unused_names : t
(** removes names from locations that are never branched to *)

val reorder_functions : t
(** sorts functions by access frequency *)

val reorder_locals : t
(** sorts locals by access frequency *)

val rereloop : t
(** re-optimize control flow using the relooper algorithm *)

val rse : t
(** remove redundant local.sets *)

val roundtrip : t
(** write the module to binary, then read it *)

val safe_heap : t
(** instrument loads and stores to check for invalid behavior *)

val set_globals : t
(** sets specified globals to specified values *)

val signature_refining : t
(** apply more specific subtypes to signature types where possible *)

val simplify_globals : t
(** miscellaneous globals-related optimizations *)

val simplify_globals_optimizing : t
(** miscellaneous globals-related optimizations, and optimizes where we replaced global.gets with constants *)

val simplify_locals : t
(** miscellaneous locals-related optimizations *)

val simplify_locals_nonesting : t
(** miscellaneous locals-related optimizations (no nesting at all; preserves flatness) *)

val simplify_locals_notee : t
(** miscellaneous locals-related optimizations (no tees) *)

val simplify_locals_nostructure : t
(** miscellaneous locals-related optimizations (no structure) *)

val simplify_locals_notee_nostructure : t
(** miscellaneous locals-related optimizations (no tees or structure) *)

val souperify : t
(** emit Souper IR in text form *)

val souperify_single_use : t
(** emit Souper IR in text form (single-use nodes only) *)

val stub_unsupported_js : t
(** stub out unsupported JS operations *)

val ssa : t
(** ssa-ify variables so that they have a single assignment *)

val ssa_nomerge : t
(** ssa-ify variables so that they have a single assignment, ignoring merges *)

val strip : t
(** deprecated; same as strip-debug *)

val stack_check : t
(** enforce limits on llvm's __stack_pointer global *)

val strip_debug : t
(** strip debug info (including the names section) *)

val strip_dwarf : t
(** strip dwarf debug info *)

val strip_producers : t
(** strip the wasm producers section *)

val strip_target_features : t
(** strip the wasm target features section *)

val trap_mode_clamp : t
(** replace trapping operations with clamping semantics *)

val trap_mode_js : t
(** replace trapping operations with js semantics *)

val untee : t
(** removes local.tees, replacing them with sets and gets *)

val vacuum : t
(** removes obviously unneeded code *)
