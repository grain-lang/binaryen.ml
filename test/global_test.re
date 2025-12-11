open Binaryen;
open Frame_work;

suite("Global", () => {
  let create_test_global = (wasm_mod, name) => {
    Global.add_global(
      wasm_mod,
      name,
      Type.int32,
      false,
      Expression.Const.make(wasm_mod, Literal.int32(0l)),
    );
  };
  test("Add global", () => {
    let wasm_mod = Module.create();
    let _ = create_test_global(wasm_mod, "test_global");
    Printf.printf("%s\n", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Get Name", () => {
    let wasm_mod = Module.create();
    let name = "test_global";
    let test_global = create_test_global(wasm_mod, name);
    assert(Global.get_name(test_global) == name);
    Module.dispose(wasm_mod);
  });
  test("Get Type", () => {
    let wasm_mod = Module.create();
    let test_global = create_test_global(wasm_mod, "test_non_null");
    assert(!Type.is_nullable(Global.get_type(test_global)));
    let test_global =
      Global.add_global(
        wasm_mod,
        "test_null",
        Type.nullref,
        false,
        Expression.Null.make(),
      );
    assert(Type.is_nullable(Global.get_type(test_global)));
    Module.dispose(wasm_mod);
  });
  test("Get Global", () => {
    let wasm_mod = Module.create();
    let name = "test_global";
    let _ = create_test_global(wasm_mod, name);
    let test_global = Global.get_global(wasm_mod, name);
    assert(Global.get_name(test_global) == name);
    Module.dispose(wasm_mod);
  });
  test("Is Mutable", () => {
    let wasm_mod = Module.create();
    let test_global = create_test_global(wasm_mod, "test_global");
    assert(!Global.is_mutable(test_global));
    let mutable_global =
      Global.add_global(
        wasm_mod,
        "mutable_global",
        Type.int32,
        true,
        Expression.Const.make(wasm_mod, Literal.int32(42l)),
      );
    assert(Global.is_mutable(mutable_global));
    Module.dispose(wasm_mod);
  });
  test("Number of Globals", () => {
    let wasm_mod = Module.create();
    assert(Global.get_num_globals(wasm_mod) == 0);
    let _ = create_test_global(wasm_mod, "global1");
    let _ = create_test_global(wasm_mod, "global2");
    assert(Global.get_num_globals(wasm_mod) == 2);
    Module.dispose(wasm_mod);
  });
  test("Remove Global", () => {
    let wasm_mod = Module.create();
    let _ = create_test_global(wasm_mod, "global_to_remove");
    assert(Global.get_num_globals(wasm_mod) == 1);
    Global.remove_global(wasm_mod, "global_to_remove");
    assert(Global.get_num_globals(wasm_mod) == 0);
    Module.dispose(wasm_mod);
  });
  test("Get Global by Index", () => {
    let wasm_mod = Module.create();
    let name1 = "global1";
    let name2 = "global2";
    let _ = create_test_global(wasm_mod, name1);
    let _ = create_test_global(wasm_mod, name2);
    let global1 = Global.get_global_by_index(wasm_mod, 0);
    let global2 = Global.get_global_by_index(wasm_mod, 1);
    assert(Global.get_name(global1) == name1);
    assert(Global.get_name(global2) == name2);
    Module.dispose(wasm_mod);
  });
  test("Get Init Expr", () => {
    let wasm_mod = Module.create();
    let test_global = create_test_global(wasm_mod, "test_global");
    let init_expr = Global.get_init_expr(test_global);
    switch (Expression.get_kind(init_expr)) {
    | Expression.Const => assert(true)
    | _ => assert(false)
    };
    Module.dispose(wasm_mod);
  });
});
