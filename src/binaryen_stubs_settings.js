//Provides: caml_binaryen_get_optimize_level
//Requires: binaryen
function caml_binaryen_get_optimize_level() {
  return binaryen.getOptimizeLevel();
}

//Provides: caml_binaryen_set_optimize_level
//Requires: binaryen
function caml_binaryen_set_optimize_level(level) {
  return binaryen.setOptimizeLevel(level);
}

//Provides: caml_binaryen_get_shrink_level
//Requires: binaryen
function caml_binaryen_get_shrink_level() {
  return binaryen.getShrinkLevel();
}

//Provides: caml_binaryen_set_shrink_level
//Requires: binaryen
function caml_binaryen_set_shrink_level(level) {
  return binaryen.setShrinkLevel(level);
}

//Provides: caml_binaryen_get_debug_info
//Requires: binaryen
function caml_binaryen_get_debug_info() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenGetDebugInfo();
}

//Provides: caml_binaryen_set_debug_info
//Requires: binaryen
function caml_binaryen_set_debug_info(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenSetDebugInfo(on);
}

//Provides: caml_binaryen_get_low_memory_unused
//Requires: binaryen
function caml_binaryen_get_low_memory_unused() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenGetLowMemoryUnused();
}

//Provides: caml_binaryen_set_low_memory_unused
//Requires: binaryen
function caml_binaryen_set_low_memory_unused(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenSetLowMemoryUnused(on);
}

//Provides: caml_binaryen_get_pass_argument
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_get_pass_argument(name) {
  return binaryen.getPassArgument(
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_set_pass_argument
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_set_pass_argument(name, value) {
  return binaryen.setPassArgument(
    caml_jsstring_of_string(name),
    caml_jsstring_of_string(value)
  );
}

//Provides: caml_binaryen_get_always_inline_max_size
//Requires: binaryen
function caml_binaryen_get_always_inline_max_size() {
  return binaryen.getAlwaysInlineMaxSize();
}

//Provides: caml_binaryen_set_always_inline_max_size
//Requires: binaryen
function caml_binaryen_set_always_inline_max_size(size) {
  return binaryen.setAlwaysInlineMaxSize(size);
}

//Provides: caml_binaryen_get_flexible_inline_max_size
//Requires: binaryen
function caml_binaryen_get_flexible_inline_max_size() {
  return binaryen.getFlexibleInlineMaxSize();
}

//Provides: caml_binaryen_set_flexible_inline_max_size
//Requires: binaryen
function caml_binaryen_set_flexible_inline_max_size(size) {
  return binaryen.setFlexibleInlineMaxSize(size);
}

//Provides: caml_binaryen_get_one_caller_inline_max_size
//Requires: binaryen
function caml_binaryen_get_one_caller_inline_max_size() {
  return binaryen.getOneCallerInlineMaxSize();
}

//Provides: caml_binaryen_set_one_caller_inline_max_size
//Requires: binaryen
function caml_binaryen_set_one_caller_inline_max_size(size) {
  return binaryen.setOneCallerInlineMaxSize(size);
}

//Provides: caml_binaryen_set_colors_enabled
//Requires: binaryen
function caml_binaryen_set_colors_enabled(on) {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenSetColorsEnabled(on);
}

//Provides: caml_binaryen_are_colors_enabled
//Requires: binaryen
function caml_binaryen_are_colors_enabled() {
  // Uses the `_Binaryen` function because then we are working with ints which are also booleans to JSOO
  return binaryen._BinaryenAreColorsEnabled();
}
