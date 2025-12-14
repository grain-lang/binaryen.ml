open Binaryen;
open Frame_work;

suite("Module", () => {
  let create_test_func = wasm_mod => {
    let _ =
      Function.add_function(
        wasm_mod,
        "test_func",
        Type.none,
        Type.none,
        [||],
        Expression.Nop.make(wasm_mod),
      );
    ();
  };
  test("create and dispose", () => {
    let wasm_mod = Module.create();
    Module.dispose(wasm_mod);
  });
  test("add custom section", () => {
    let wasm_mod = Module.create();
    Module.add_custom_section(wasm_mod, "test_section", "test_data");
    Module.dispose(wasm_mod);
  });
  test("write", () => {
    let wasm_mod = Module.create();
    let (bytes, source_map) = Module.write(wasm_mod, None);
    assert(source_map == None);
    assert(bytes == Bytes.of_string("\000asm\001\000\000\000"));
    let (_, source_map) = Module.write(wasm_mod, Some(""));
    switch (source_map) {
    | Some(map) => Printf.printf("Source map: %s\n", map)
    | None => Printf.printf("No source map\n")
    };
    // assert(
    //   source_map
    //   == Some({|{"version":3,"sources":[],"names":[],"mappings":""}|}),
    // );
    Module.dispose(wasm_mod);
  });
  test("write_text", () => {
    let wasm_mod = Module.create();
    create_test_func(wasm_mod);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("write_stack_ir", () => {
    let wasm_mod = Module.create();
    create_test_func(wasm_mod);
    Printf.printf("%s", Module.write_stack_ir(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("parse", () => {
    let wasm_bytes = Bytes.of_string("(module (func))");
    let wasm_mod = Module.parse(Bytes.to_string(wasm_bytes));
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });

  // Note: Print tests will output to stdout directly.
  test("print", () => {
    let wasm_mod = Module.create();
    Module.print(wasm_mod);
    Module.dispose(wasm_mod);
  });
  test("print_asmjs", () => {
    let wasm_mod = Module.create();
    create_test_func(wasm_mod);
    Module.print_asmjs(wasm_mod);
    Module.dispose(wasm_mod);
  });
  test("print_stack_ir", () => {
    let wasm_mod = Module.create();
    create_test_func(wasm_mod);
    Module.print_stack_ir(wasm_mod);
    Module.dispose(wasm_mod);
  });

  test("validate", () => {
    let wasm_mod = Module.create();
    let result = Module.validate(wasm_mod);
    assert(result == 1);
    Module.dispose(wasm_mod);
  });
  test("optimize", () => {
    let wasm_mod = Module.create();
    Module.optimize(wasm_mod);
    Module.dispose(wasm_mod);
  });
  test("get and set features", () => {
    let wasm_mod = Module.create();
    assert(Module.get_features(wasm_mod) == []);
    Module.set_features(
      wasm_mod,
      [
        Module.Feature.mvp,
        Module.Feature.atomics,
        Module.Feature.mutable_globals,
        Module.Feature.nontrapping_fp_to_int,
        Module.Feature.simd128,
        Module.Feature.bulk_memory,
        Module.Feature.sign_ext,
        Module.Feature.exception_handling,
        Module.Feature.tail_call,
        Module.Feature.reference_types,
        Module.Feature.multivalue,
        Module.Feature.gc,
        Module.Feature.memory64,
        Module.Feature.relaxed_simd,
        Module.Feature.extended_const,
        Module.Feature.strings,
        Module.Feature.multi_memory,
        Module.Feature.stack_switching,
        Module.Feature.shared_everything,
        Module.Feature.fp16,
        Module.Feature.bulk_memory_opt,
        Module.Feature.call_indirect_overlong,
        Module.Feature.all,
      ],
    );
    assert(List.length(Module.get_features(wasm_mod)) == 22);
    Module.dispose(wasm_mod);
  });
  test("run_empty_passes", () => {
    let wasm_mod = Module.create();
    Module.run_passes(wasm_mod, []);
    Module.dispose(wasm_mod);
  });
  test("read", () => {
    let wasm_mod = Module.create();
    create_test_func(wasm_mod);
    let (bytes, _) = Module.write(wasm_mod, None);
    Module.dispose(wasm_mod);
    let wasm_mod = Module.read(bytes);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
    let wasm_bytes = Bytes.of_string("\000asm\001\000\000\000");
    let wasm_mod = Module.read(wasm_bytes);
    Module.dispose(wasm_mod);
  });
  test("interpret", () => {
    let wasm_mod = Module.create();
    Module.interpret(wasm_mod);
    Module.dispose(wasm_mod);
  });
  test("debug info filename management", () => {
    let wasm_mod = Module.create();
    let index = Module.add_debug_info_filename(wasm_mod, "debug_file.wasm");
    let filename = Module.get_debug_info_filename(wasm_mod, index);
    assert(filename == "debug_file.wasm");
    Module.dispose(wasm_mod);
  });
  test("update maps", () => {
    let wasm_mod = Module.create();
    Module.update_maps(wasm_mod);
    Module.dispose(wasm_mod);
  });
});
