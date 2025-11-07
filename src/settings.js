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
