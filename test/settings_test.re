open Binaryen;
open Frame_work;

suite("Settings", () => {
  test("optimize_level", () => {
    let default_level = Settings.get_optimize_level();
    assert(Settings.get_optimize_level() != 3);
    Settings.set_optimize_level(3);
    assert(Settings.get_optimize_level() == 3);
    Settings.set_optimize_level(default_level);
  });
  test("shrink_level", () => {
    let default_level = Settings.get_shrink_level();
    assert(Settings.get_shrink_level() != 2);
    Settings.set_shrink_level(2);
    assert(Settings.get_shrink_level() == 2);
    Settings.set_shrink_level(default_level);
  });
  test("debug_info", () => {
    assert(Settings.get_debug_info() == false);
    Settings.set_debug_info(true);
    assert(Settings.get_debug_info() == true);
    Settings.set_debug_info(false);
  });
  test("traps_never_happen", () => {
    assert(Settings.get_traps_never_happen() == false);
    Settings.set_traps_never_happen(true);
    assert(Settings.get_traps_never_happen() == true);
    Settings.set_traps_never_happen(false);
  });
  test("closed_world", () => {
    assert(Settings.get_closed_world() == false);
    Settings.set_closed_world(true);
    assert(Settings.get_closed_world() == true);
    Settings.set_closed_world(false);
  });
  test("low_memory_unused", () => {
    assert(Settings.get_low_memory_unused() == false);
    Settings.set_low_memory_unused(true);
    assert(Settings.get_low_memory_unused() == true);
    Settings.set_low_memory_unused(false);
  });
  test("zero_filled_memory", () => {
    assert(Settings.get_zero_filled_memory() == false);
    Settings.set_zero_filled_memory(true);
    assert(Settings.get_zero_filled_memory() == true);
    Settings.set_zero_filled_memory(false);
  });
  test("fast_math", () => {
    assert(Settings.get_fast_math() == false);
    Settings.set_fast_math(true);
    assert(Settings.get_fast_math() == true);
    Settings.set_fast_math(false);
  });
  test("generate_stack_ir", () => {
    assert(Settings.get_generate_stack_ir() == false);
    Settings.set_generate_stack_ir(true);
    assert(Settings.get_generate_stack_ir() == true);
    Settings.set_generate_stack_ir(false);
  });
  test("optimize_stack_ir", () => {
    assert(Settings.get_optimize_stack_ir() == false);
    Settings.set_optimize_stack_ir(true);
    assert(Settings.get_optimize_stack_ir() == true);
    Settings.set_optimize_stack_ir(false);
  });
  test("pass_argument", () => {
    assert(Settings.get_pass_argument("theKey") == None);
    Settings.set_pass_argument("theKey", "theValue");
    assert(Settings.get_pass_argument("theKey") == Some("theValue"));
    Settings.set_pass_argument("theKey", "theValue2");
    assert(Settings.get_pass_argument("theKey") == Some("theValue2"));
    Settings.clear_pass_arguments();
    assert(Settings.get_pass_argument("theKey") == None);
  });
  test("skip_pass", () => {
    assert(Settings.has_pass_to_skip("thePass") == false);
    Settings.add_pass_to_skip("thePass");
    assert(Settings.has_pass_to_skip("thePass") == true);
    Settings.clear_passes_to_skip();
    assert(Settings.has_pass_to_skip("thePass") == false);
  });
  test("always inline max size", () => {
    let default_size = Settings.get_always_inline_max_size();
    assert(Settings.get_always_inline_max_size() != 1);
    Settings.set_always_inline_max_size(1);
    assert(Settings.get_always_inline_max_size() == 1);
    Settings.set_always_inline_max_size(default_size);
  });
  test("flexible inline max size", () => {
    let default_size = Settings.get_flexible_inline_max_size();
    assert(Settings.get_flexible_inline_max_size() != 1);
    Settings.set_flexible_inline_max_size(1);
    assert(Settings.get_flexible_inline_max_size() == 1);
    Settings.set_flexible_inline_max_size(default_size);
  });
  test("one caller inline max size", () => {
    let default_size = Settings.get_one_caller_inline_max_size();
    assert(Settings.get_one_caller_inline_max_size() != 1);
    Settings.set_one_caller_inline_max_size(1);
    assert(Settings.get_one_caller_inline_max_size() == 1);
    Settings.set_one_caller_inline_max_size(default_size);
  });
  test("allow inlining functions with loops", () => {
    assert(Settings.get_allow_inlining_functions_with_loops() == false);
    Settings.set_allow_inlining_functions_with_loops(true);
    assert(Settings.get_allow_inlining_functions_with_loops() == true);
    Settings.set_allow_inlining_functions_with_loops(false);
  });
  test("colors enabled", () => {
    assert(Settings.are_colors_enabled() == true);
    Settings.set_colors_enabled(false);
    assert(Settings.are_colors_enabled() == false);
    Settings.set_colors_enabled(true);
  });
});
