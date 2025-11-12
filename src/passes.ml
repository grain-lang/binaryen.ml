type t = string

(** lower unaligned loads and stores to smaller aligned ones *)
let alignment_lowering = "alignment-lowering"

(** async/await style transform, allowing pausing and resuming *)
let asyncify = "asyncify"

(** Tries to avoid reinterpret operations via more loads *)
let avoid_reinterprets = "avoid-reinterprets"

(** removes arguments to calls in an lto-like manner *)
let dae = "dae"

(** removes arguments to calls in an lto-like manner, and optimizes where we
    removed *)
let dae_optimizing = "dae-optimizing"

(** refine and merge abstract (never-created) types *)
let abstract_type_refining = "abstract-type-refining"

(** reduce # of locals by coalescing *)
let coalesce_locals = "coalesce-locals"

(** reduce # of locals by coalescing and learning *)
let coalesce_locals_learning = "coalesce-locals-learning"

(** push code forward, potentially making it not always execute *)
let code_pushing = "code-pushing"

(** fold code, merging duplicates *)
let code_folding = "code-folding"

(** hoist repeated constants to a local *)
let const_hoisting = "const-hoisting"

(** propagate constant struct field values *)
let cfp = "cfp"

(** propagate constant struct field values, using ref.test *)
let cfp_reftest = "cfp-reftest"

(** removes unreachable code *)
let dce = "dce"

(** forces all loads and stores to have alignment 1 *)
let dealign = "dealign"

(** propagate debug location from parents or previous siblings to child nodes *)
let propagate_debug_locs = "propagate-debug-locs"

(** instrument the wasm to convert NaNs into 0 at runtime *)
let denan = "denan"

(** turns indirect calls into direct ones *)
let directize = "directize"

(** discards global effect info *)
let discard_global_effects = "discard-global-effects"

(** optimizes using the DataFlow SSA IR *)
let dfo = "dfo"

(** dump DWARF debug info sections from the read binary *)
let dwarfdump = "dwarfdump"

(** removes duplicate imports *)
let duplicate_import_elimination = "duplicate-import-elimination"

(** removes duplicate functions *)
let duplicate_function_elimination = "duplicate-function-elimination"

(** emit the target features section in the output *)
let emit_target_features = "emit-target-features"

(** modify the wasm (destructively) for closed-world *)
let enclose_world = "enclose-world"

(** leaves just one function (useful for debugging) *)
let extract_function = "extract-function"

(** leaves just one function selected by index *)
let extract_function_index = "extract-function-index"

(** flattens out code, removing nesting *)
let flatten = "flatten"

(** emulates function pointer casts, allowing incorrect indirect calls to
    (sometimes) work *)
let fpcast_emu = "fpcast-emu"

(** reports function metrics *)
let func_metrics = "func-metrics"

(** generate dynCall fuctions used by emscripten ABI *)
let generate_dyncalls = "generate-dyncalls"

(** generate dynCall functions used by emscripten ABI, but only for functions
    with i64 in their signature (which cannot be invoked via the wasm table
    without JavaScript BigInt support). *)
let generate_i64_dyncalls = "generate-i64-dyncalls"

(** generate global effect info (helps later passes) *)
let generate_global_effects = "generate-global-effects"

(** refine the types of globals *)
let global_refining = "global-refining"

(** globally optimize struct values *)
let gsi = "gsi"

(** globally optimize GC types *)
let gto = "gto"

(** Grand Unified Flow Analysis: optimize the entire program using information
    about what content can actually appear in each location *)
let gufa = "gufa"

(** GUFA plus add casts for all inferences *)
let gufa_cast_all = "gufa-cast-all"

(** GUFA plus local optimizations in functions we modified *)
let gufa_optimizing = "gufa-optimizing"

(** optimizes J2CL specific constructs. *)
let optimize_j2cl = "optimize-j2cl"

(** Merges itable structures into vtables to make types more compact *)
let merge_j2cl_itables = "merge-j2cl-itables"

(** apply more specific subtypes to type fields where possible *)
let type_refining = "type-refining"

(** apply more specific subtypes to type fields where possible (using GUFA) *)
let type_refining_gufa = "type-refining-gufa"

(** replace GC allocations with locals *)
let heap2local = "heap2local"

(** optimize heap (GC) stores *)
let heap_store_optimization = "heap-store-optimization"

(** inline __original_main into main *)
let inline_main = "inline-main"

(** inline functions (you probably want inlining-optimizing) *)
let inlining = "inlining"

(** inline functions and optimizes where we inlined *)
let inlining_optimizing = "inlining-optimizing"

(** lower away binaryen intrinsics *)
let intrinsic_lowering = "intrinsic-lowering"

(** wrap imports and exports for JavaScript promise integration *)
let jspi = "jspi"

(** legalizes i64 types on the import/export boundary *)
let legalize_js_interface = "legalize-js-interface"

(** legalizes the import/export boundary and prunes when needed *)
let legalize_and_prune_js_interface = "legalize-and-prune-js-interface"

(** common subexpression elimination inside basic blocks *)
let local_cse = "local-cse"

(** apply more specific subtypes to locals where possible *)
let local_subtyping = "local-subtyping"

(** instrument the build with logging of where execution goes *)
let log_execution = "log-execution"

(** lower all uses of i64s to use i32s instead *)
let i64_to_i32_lowering = "i64-to-i32-lowering"

(** instrument the build with code to intercept specific function calls *)
let trace_calls = "trace-calls"

(** instrument the build with code to intercept all loads and stores *)
let instrument_locals = "instrument-locals"

(** instrument the build with code to intercept all loads and stores *)
let instrument_memory = "instrument-memory"

(** loop invariant code motion *)
let licm = "licm"

(** attempt to merge segments to fit within web limits *)
let limit_segments = "limit-segments"

(** lower loads and stores to a 64-bit memory to instead use a 32-bit one *)
let memory64_lowering = "memory64-lowering"

(** alias for memory64-lowering *)
let table64_lowering = "table64-lowering"

(** Lower memory.copy and memory.fill to wasm mvp and disable the bulk-memory
    feature. *)
let llvm_memory_copy_fill_lowering = "llvm-memory-copy-fill-lowering"

(** packs memory into separate segments, skipping zeros *)
let memory_packing = "memory-packing"

(** merges blocks to their parents *)
let merge_blocks = "merge-blocks"

(** merges similar functions when benefical *)
let merge_similar_functions = "merge-similar-functions"

(** merges locals when beneficial *)
let merge_locals = "merge-locals"

(** reports metrics *)
let metrics = "metrics"

(** minifies import names (only those, and not export names), and emits a
    mapping to the minified ones *)
let minify_imports = "minify-imports"

(** minifies both import and export names, and emits a mapping to the minified
    ones *)
let minify_imports_and_exports = "minify-imports-and-exports"

(** minifies both import and export names, and emits a mapping to the minified
    ones, and minifies the modules as well *)
let minify_imports_and_exports_and_modules =
  "minify-imports-and-exports-and-modules"

(** Split types into minimal recursion groups *)
let minimize_rec_groups = "minimize-rec-groups"

(** apply the assumption that asyncify imports always unwind, and we never
    rewind *)
let mod_asyncify_always_and_only_unwind = "mod-asyncify-always-and-only-unwind"

(** apply the assumption that asyncify never unwinds *)
let mod_asyncify_never_unwind = "mod-asyncify-never-unwind"

(** creates specialized versions of functions *)
let monomorphize = "monomorphize"

(** creates specialized versions of functions (even if unhelpful) *)
let monomorphize_always = "monomorphize-always"

(** combines multiple memories into a single memory *)
let multi_memory_lowering = "multi-memory-lowering"

(** combines multiple memories into a single memory, trapping if the read or
    write is larger than the length of the memory's data *)
let multi_memory_lowering_with_bounds_checks =
  "multi-memory-lowering-with-bounds-checks"

(** name list *)
let nm = "nm"

(** (re)name all heap types *)
let name_types = "name-types"

(** mark functions as no-inline *)
let no_inline = "no-inline"

(** mark functions as no-inline (for full inlining only) *)
let no_full_inline = "no-full-inline"

(** mark functions as no-inline (for partial inlining only) *)
let no_partial_inline = "no-partial-inline"

(** lower nontrapping float-to-int operations to wasm mvp and disable the
    nontrapping fptoint feature *)
let llvm_nontrapping_fptoint_lowering = "llvm-nontrapping-fptoint-lowering"

(** reduces calls to code that only runs once *)
let once_reduction = "once-reduction"

(** optimizes added constants into load/store offsets *)
let optimize_added_constants = "optimize-added-constants"

(** optimizes added constants into load/store offsets, propagating them across
    locals too *)
let optimize_added_constants_propagate = "optimize-added-constants-propagate"

(** eliminate and reuse casts *)
let optimize_casts = "optimize-casts"

(** optimizes instruction combinations *)
let optimize_instructions = "optimize-instructions"

(** pick load signs based on their uses *)
let pick_load_signs = "pick-load-signs"

(** Tranform Binaryen IR into Poppy IR *)
let poppify = "poppify"

(** miscellaneous optimizations for Emscripten-generated code *)
let post_emscripten = "post-emscripten"

(** early optimize of the instruction combinations for js *)
let optimize_for_js = "optimize-for-js"

(** computes compile-time evaluatable expressions *)
let precompute = "precompute"

(** computes compile-time evaluatable expressions and propagates them through
    locals *)
let precompute_propagate = "precompute-propagate"

(** print in s-expression format *)
let print = "print"

(** print in minified s-expression format *)
let print_minified = "print-minified"

(** print options for enabled features *)
let print_features = "print-features"

(** print in full s-expression format *)
let print_full = "print-full"

(** print call graph *)
let print_call_graph = "print-call-graph"

(** print a map of function indexes to names *)
let print_function_map = "print-function-map"

(** alias for print_function_map *)
let symbolmap = "symbolmap"

(** removes operations incompatible with js *)
let remove_non_js_ops = "remove-non-js-ops"

(** removes imports and replaces them with nops *)
let remove_imports = "remove-imports"

(** removes memory initialization *)
let remove_memory_init = "remove-memory-init"

(** removes memory segments *)
let remove_memory = "remove-memory"

(** removes breaks from locations that are not needed *)
let remove_unused_brs = "remove-unused-brs"

(** removes unused module elements *)
let remove_unused_module_elements = "remove-unused-module-elements"

(** removes unused module elements that are not functions *)
let remove_unused_nonfunction_module_elements =
  "remove-unused-nonfunction-module-elements"

(** removes names from locations that are never branched to *)
let remove_unused_names = "remove-unused-names"

(** remove unused private GC types *)
let remove_unused_types = "remove-unused-types"

(** sorts functions by name (useful for debugging) *)
let reorder_functions_by_name = "reorder-functions-by-name"

(** sorts functions by access frequency *)
let reorder_functions = "reorder-functions"

(** sorts globals by access frequency *)
let reorder_globals = "reorder-globals"

(** sorts locals by access frequency *)
let reorder_locals = "reorder-locals"

(** re-optimize control flow using the relooper algorithm *)
let rereloop = "rereloop"

(** remove redundant local.sets *)
let rse = "rse"

(** write the module to binary, then read it *)
let roundtrip = "roundtrip"

(** instrument loads and stores to check for invalid behavior *)
let safe_heap = "safe-heap"

(** sets specified globals to specified values *)
let set_globals = "set-globals"

(** write data segments to a file and strip them from the module *)
let separate_data_segments = "separate-data-segments"

(** remove params from function signature types where possible *)
let signature_pruning = "signature-pruning"

(** apply more specific subtypes to signature types where possible *)
let signature_refining = "signature-refining"

(** lower sign-ext operations to wasm mvp and disable the sign extension feature
*)
let signext_lowering = "signext-lowering"

(** miscellaneous globals-related optimizations *)
let simplify_globals = "simplify-globals"

(** miscellaneous globals-related optimizations, and optimizes where we replaced
    global.gets with constants *)
let simplify_globals_optimizing = "simplify-globals-optimizing"

(** miscellaneous locals-related optimizations *)
let simplify_locals = "simplify-locals"

(** miscellaneous locals-related optimizations (no nesting at all; preserves
    flatness) *)
let simplify_locals_nonesting = "simplify-locals-nonesting"

(** miscellaneous locals-related optimizations (no tees) *)
let simplify_locals_notee = "simplify-locals-notee"

(** miscellaneous locals-related optimizations (no structure) *)
let simplify_locals_nostructure = "simplify-locals-nostructure"

(** miscellaneous locals-related optimizations (no tees or structure) *)
let simplify_locals_notee_nostructure = "simplify-locals-notee-nostructure"

(** emit Souper IR in text form *)
let souperify = "souperify"

(** emit Souper IR in text form (single-use nodes only) *)
let souperify_single_use = "souperify-single-use"

(** spill pointers to the C stack (useful for Boehm-style GC) *)
let spill_pointers = "spill-pointers"

(** stub out unsupported JS operations *)
let stub_unsupported_js = "stub-unsupported-js"

(** ssa-ify variables so that they have a single assignment *)
let ssa = "ssa"

(** ssa-ify variables so that they have a single assignment, ignoring merges *)
let ssa_nomerge = "ssa-nomerge"

(** gathers wasm strings to globals *)
let string_gathering = "string-gathering"

(** lift string imports to wasm strings *)
let string_lifting = "string-lifting"

(** lowers wasm strings and operations to imports *)
let string_lowering = "string-lowering"

(** same as string-lowering, but encodes well-formed strings as magic imports *)
let string_lowering_magic_imports = "string-lowering-magic-imports"

(** same as string-lowering-magic-imports, but raise a fatal error if there are
    invalid strings *)
let string_lowering_magic_imports_assert =
  "string-lowering-magic-imports-assert"

(** deprecated; same as strip-debug *)
let strip = "strip"

(** enforce limits on llvm's __stack_pointer global *)
let stack_check = "stack-check"

(** strip debug info (including the names section) *)
let strip_debug = "strip-debug"

(** strip dwarf debug info *)
let strip_dwarf = "strip-dwarf"

(** strip the wasm producers section *)
let strip_producers = "strip-producers"

(** strip EH instructions *)
let strip_eh = "strip-eh"

(** strip the wasm target features section *)
let strip_target_features = "strip-target-features"

(** translate old Phase 3 EH instructions to new ones with exnref *)
let translate_to_exnref = "translate-to-exnref"

(** replace trapping operations with clamping semantics *)
let trap_mode_clamp = "trap-mode-clamp"

(** replace trapping operations with js semantics *)
let trap_mode_js = "trap-mode-js"

(** optimize trivial tuples away *)
let tuple_optimization = "tuple-optimization"

(** mark all leaf types as final *)
let type_finalizing = "type-finalizing"

(** merge types to their supertypes where possible *)
let type_merging = "type-merging"

(** create new nominal types to help other optimizations *)
let type_ssa = "type-ssa"

(** mark all types as non-final (open) *)
let type_unfinalizing = "type-unfinalizing"

(** removes removes unnecessary subtyping relationships *)
let unsubtyping = "unsubtyping"

(** removes local.tees, replacing them with sets and gets *)
let untee = "untee"

(** removes obviously unneeded code *)
let vacuum = "vacuum"
