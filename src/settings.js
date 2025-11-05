//Provides: caml_binaryen_get_optimize_level
//Requires: Binaryen
function caml_binaryen_get_optimize_level() {
  return Binaryen.getOptimizeLevel();
}

//Provides: caml_binaryen_set_optimize_level
//Requires: Binaryen
function caml_binaryen_set_optimize_level(level) {
  return Binaryen.setOptimizeLevel(level);
}

//Provides: caml_binaryen_get_shrink_level
//Requires: Binaryen
function caml_binaryen_get_shrink_level() {
  return Binaryen.getShrinkLevel();
}

//Provides: caml_binaryen_set_shrink_level
//Requires: Binaryen
function caml_binaryen_set_shrink_level(level) {
  return Binaryen.setShrinkLevel(level);
}

//Provides: caml_binaryen_get_debug_info
//Requires: Binaryen
function caml_binaryen_get_debug_info() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetDebugInfo();
}

//Provides: caml_binaryen_set_debug_info
//Requires: Binaryen
function caml_binaryen_set_debug_info(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetDebugInfo(on);
}

//Provides: caml_binaryen_get_traps_never_happen
//Requires: Binaryen
function caml_binaryen_get_traps_never_happen() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetTrapsNeverHappen();
}

//Provides: caml_binaryen_set_traps_never_happen
//Requires: Binaryen
function caml_binaryen_set_traps_never_happen(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetTrapsNeverHappen(on);
}

//Provides: caml_binaryen_get_closed_world
//Requires: Binaryen
function caml_binaryen_get_closed_world() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetClosedWorld();
}

//Provides: caml_binaryen_set_closed_world
//Requires: Binaryen
function caml_binaryen_set_closed_world(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetClosedWorld(on);
}

//Provides: caml_binaryen_get_low_memory_unused
//Requires: Binaryen
function caml_binaryen_get_low_memory_unused() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetLowMemoryUnused();
}

//Provides: caml_binaryen_set_low_memory_unused
//Requires: Binaryen
function caml_binaryen_set_low_memory_unused(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetLowMemoryUnused(on);
}

//Provides: caml_binaryen_get_zero_filled_memory
//Requires: Binaryen
function caml_binaryen_get_zero_filled_memory() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetZeroFilledMemory();
}

//Provides: caml_binaryen_set_zero_filled_memory
//Requires: Binaryen
function caml_binaryen_set_zero_filled_memory(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetZeroFilledMemory(on);
}

//Provides: caml_binaryen_get_fast_math
//Requires: Binaryen
function caml_binaryen_get_fast_math() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetFastMath();
}

//Provides: caml_binaryen_set_fast_math
//Requires: Binaryen
function caml_binaryen_set_fast_math(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetFastMath(on);
}

//Provides: caml_binaryen_get_generate_stack_ir
//Requires: Binaryen
function caml_binaryen_get_generate_stack_ir() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetGenerateStackIR();
}

//Provides: caml_binaryen_set_generate_stack_ir
//Requires: Binaryen
function caml_binaryen_set_generate_stack_ir(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetGenerateStackIR(on);
}

//Provides: caml_binaryen_get_optimize_stack_ir
//Requires: Binaryen
function caml_binaryen_get_optimize_stack_ir() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetOptimizeStackIR();
}

//Provides: caml_binaryen_set_optimize_stack_ir
//Requires: Binaryen
function caml_binaryen_set_optimize_stack_ir(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetOptimizeStackIR(on);
}

//Provides: caml_binaryen_get_pass_argument
//Requires: Binaryen
//Requires: caml_jsstring_of_string
//Requires: to_option
function caml_binaryen_get_pass_argument(name) {
  var val = Binaryen.getPassArgument(caml_jsstring_of_string(name));
  var str = name != null ? val : null;
  return to_option(str);
}

//Provides: caml_binaryen_set_pass_argument
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_set_pass_argument(name, value) {
  return Binaryen.setPassArgument(
    caml_jsstring_of_string(name),
    caml_jsstring_of_string(value)
  );
}

//Provides: caml_binaryen_get_always_inline_max_size
//Requires: Binaryen
function caml_binaryen_get_always_inline_max_size() {
  return Binaryen.getAlwaysInlineMaxSize();
}

//Provides: caml_binaryen_set_always_inline_max_size
//Requires: Binaryen
function caml_binaryen_set_always_inline_max_size(size) {
  return Binaryen.setAlwaysInlineMaxSize(size);
}

//Provides: caml_binaryen_get_flexible_inline_max_size
//Requires: Binaryen
function caml_binaryen_get_flexible_inline_max_size() {
  return Binaryen.getFlexibleInlineMaxSize();
}

//Provides: caml_binaryen_set_flexible_inline_max_size
//Requires: Binaryen
function caml_binaryen_set_flexible_inline_max_size(size) {
  return Binaryen.setFlexibleInlineMaxSize(size);
}

//Provides: caml_binaryen_get_one_caller_inline_max_size
//Requires: Binaryen
function caml_binaryen_get_one_caller_inline_max_size() {
  return Binaryen.getOneCallerInlineMaxSize();
}

//Provides: caml_binaryen_set_one_caller_inline_max_size
//Requires: Binaryen
function caml_binaryen_set_one_caller_inline_max_size(size) {
  return Binaryen.setOneCallerInlineMaxSize(size);
}

//Provides: caml_binaryen_get_allow_inlining_functions_with_loops
//Requires: Binaryen
function caml_binaryen_get_allow_inlining_functions_with_loops() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenGetAllowInliningFunctionsWithLoops();
}

//Provides: caml_binaryen_set_allow_inlining_functions_with_loops
//Requires: Binaryen
function caml_binaryen_set_allow_inlining_functions_with_loops(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetAllowInliningFunctionsWithLoops(on);
}

//Provides: caml_binaryen_set_colors_enabled
//Requires: Binaryen
function caml_binaryen_set_colors_enabled(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenSetColorsEnabled(on);
}

//Provides: caml_binaryen_are_colors_enabled
//Requires: Binaryen
function caml_binaryen_are_colors_enabled() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return Binaryen._BinaryenAreColorsEnabled();
}
