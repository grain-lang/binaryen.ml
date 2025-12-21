open Binaryen;
open Frame_work;

suite("Type", () => {
  // NOTE: Type.auto isn't tested as it is not a real type

  let create_test_func = (wasm_mod, name, param_type) => {
    Function.add_function(
      wasm_mod,
      name,
      param_type,
      Type.none,
      [||],
      Expression.Nop.make(wasm_mod),
    );
  };
  test("none", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "none_type_test", Type.none);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("create/expand", () => {
    let expanded = Type.expand(Type.int32);
    assert(Array.length(expanded) == 1);
    let typ = Type.create([|Type.int32, Type.int32|]);
    let expanded = Type.expand(typ);
    assert(Array.length(expanded) == 2);
  });
  test("basic types", () => {
    let wasm_mod = Module.create();
    let _ =
      create_test_func(
        wasm_mod,
        "basic_type_test",
        Type.create([|
          Type.int32,
          Type.int64,
          Type.float32,
          Type.float64,
          Type.vec128,
        |]),
      );
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("ref types", () => {
    let wasm_mod = Module.create();
    let _ =
      create_test_func(
        wasm_mod,
        "ref_type_test",
        Type.create([|
          Type.funcref,
          Type.anyref,
          Type.eqref,
          Type.i31ref,
          Type.structref,
          Type.arrayref,
          Type.stringref,
          Type.nullref,
          Type.null_externref,
          Type.null_funcref,
        |]),
      );
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("unreachable type", () => {
    let wasm_mod = Module.create();
    let _ =
      create_test_func(wasm_mod, "unreachable_type_test", Type.unreachable);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("is_nullable", () => {
    assert(Type.is_nullable(Type.anyref) == true);
    assert(Type.is_nullable(Type.int32) == false);
  });
  // TODO: Test from_heap_type
  // TODO: Test get_heap_type
});
