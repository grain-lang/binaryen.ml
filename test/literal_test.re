open Binaryen;
open Frame_work;

suite("Literal", () => {
  let create_test_func = (wasm_mod, name, lit) => {
    Function.add_function(
      wasm_mod,
      name,
      Type.none,
      Type.none,
      [||],
      Expression.Drop.make(wasm_mod, Expression.Const.make(wasm_mod, lit)),
    );
  };
  test("int32", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "int32_test", Literal.int32(42l));
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("int64", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "int64_test", Literal.int64(-35L));
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("float32_bits", () => {
    let wasm_mod = Module.create();
    let _ =
      create_test_func(
        wasm_mod,
        "float32_bits_test",
        Literal.float32_bits(0x40900000l),
      ); // 4.5
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("float64_bits", () => {
    let wasm_mod = Module.create();
    let _ =
      create_test_func(
        wasm_mod,
        "float64_bits_test",
        Literal.float64_bits(0x4012000000000000L),
      ); // 4.5
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("float32", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "float32_test", Literal.float32(3.5));
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("float64", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "float64_test", Literal.float64(5.5));
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
});
