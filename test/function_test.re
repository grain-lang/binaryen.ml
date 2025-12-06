open Binaryen;
open Frame_work;

suite("Function", () => {
  let create_test_func = (wasm_mod, name) =>
    Function.add_function(
      wasm_mod,
      name,
      Type.none,
      Type.none,
      [||],
      Expression.Nop.make(wasm_mod),
    );
  test("Add Function", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "test_func");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("get name", () => {
    let wasm_mod = Module.create();
    let func_name = "my_function";
    let func = create_test_func(wasm_mod, func_name);
    assert(Function.get_name(func) == func_name);
    Module.dispose(wasm_mod);
  });
  test("get params and results", () => {
    let wasm_mod = Module.create();
    let func =
      Function.add_function(
        wasm_mod,
        "param_result_func",
        Type.create([|Type.int32, Type.int32|]),
        Type.int32,
        [||],
        Expression.Block.make(
          wasm_mod,
          ~return_type=Type.int32,
          "body",
          [Expression.Const.make(wasm_mod, Literal.int32(0l))],
        ),
      );
    let params = Type.expand(Function.get_params(func));
    assert(Array.length(params) == 2);
    let results = Type.expand(Function.get_results(func));
    assert(Array.length(results) == 1);
    Module.dispose(wasm_mod);
  });
  test("get num vars", () => {
    let wasm_mod = Module.create();
    let func =
      Function.add_function(
        wasm_mod,
        "var_func",
        Type.none,
        Type.none,
        [|Type.int32, Type.int64|],
        Expression.Block.make(
          wasm_mod,
          ~return_type=Type.none,
          "body",
          [
            Expression.Drop.make(
              wasm_mod,
              Expression.Const.make(wasm_mod, Literal.int32(0l)),
            ),
          ],
        ),
      );
    let num_vars = Function.get_num_vars(func);
    assert(num_vars == 2);
    Module.dispose(wasm_mod);
  });
  test("get var", () => {
    let wasm_mod = Module.create();
    let func =
      Function.add_function(
        wasm_mod,
        "var_func",
        Type.none,
        Type.none,
        [|Type.create([|Type.int32, Type.int32|])|],
        Expression.Block.make(
          wasm_mod,
          ~return_type=Type.none,
          "body",
          [
            Expression.Drop.make(
              wasm_mod,
              Expression.Const.make(wasm_mod, Literal.int32(0l)),
            ),
          ],
        ),
      );
    let var0_type = Type.expand(Function.get_var(func, 0));
    assert(Array.length(var0_type) == 2);
    Module.dispose(wasm_mod);
  });
  test("get/set start", () => {
    let wasm_mod = Module.create();
    let func_name = "start_func";
    let func = create_test_func(wasm_mod, func_name);
    Function.set_start(wasm_mod, func);
    let retrieved_start = Function.get_start(wasm_mod);
    assert(Function.get_name(retrieved_start) == func_name);
    Module.dispose(wasm_mod);
  });
  test("function count", () => {
    let wasm_mod = Module.create();
    let _ = create_test_func(wasm_mod, "func1");
    let _ = create_test_func(wasm_mod, "func2");
    let count = Function.get_num_functions(wasm_mod);
    assert(count == 2);
    Module.dispose(wasm_mod);
  });
  test("get func & get func by index", () => {
    let wasm_mod = Module.create();
    let func_name = "retrieve_func";
    let _ = create_test_func(wasm_mod, func_name);
    let _ = create_test_func(wasm_mod, "another_func");
    let retrieved_func = Function.get_function(wasm_mod, func_name);

    assert(Function.get_name(retrieved_func) == func_name);

    let retrieved_by_index = Function.get_function_by_index(wasm_mod, 0);
    assert(Function.get_name(retrieved_by_index) == func_name);

    Module.dispose(wasm_mod);
  });
  test("remove_function", () => {
    let wasm_mod = Module.create();
    let func_name = "removable_func";
    let _ = create_test_func(wasm_mod, func_name);
    Function.remove_function(wasm_mod, func_name);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("get/set body", () => {
    let wasm_mod = Module.create();
    let func = create_test_func(wasm_mod, "body_func");
    let func2 =
      Function.add_function(
        wasm_mod,
        "new_body_func",
        Type.none,
        Type.none,
        [||],
        Expression.Drop.make(
          wasm_mod,
          Expression.Const.make(wasm_mod, Literal.int32(42l)),
        ),
      );
    let body = Function.get_body(func);
    Function.set_body(func2, body); // Swap bodies for test side effect
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("set_debug_location", () => {
    let wasm_mod = Module.create();
    let exp = Expression.Nop.make(wasm_mod);
    let func =
      Function.add_function(
        wasm_mod,
        "debug_loc_func",
        Type.none,
        Type.none,
        [||],
        exp,
      );
    Function.set_debug_location(func, exp, 0, 10, 20);
    let source_map =
      switch (Module.write(wasm_mod, Some("file"))) {
      | (_, Some(sm)) => sm
      | _ => assert(false)
      };
    Printf.printf("%s", source_map);
    Module.dispose(wasm_mod);
  });
});
