open Binaryen;
open Frame_work;

suite("Import", () => {
  test("Add Import", () => {
    let wasm_mod = Module.create();
    let external_module_name = "ext_module";
    let external_base_name = "ext_base";
    // Import Function
    Import.add_function_import(
      wasm_mod,
      "ext_func",
      external_module_name,
      external_base_name,
      Type.none,
      Type.none,
    );
    // Import Table
    Import.add_table_import(
      wasm_mod,
      "ext_table",
      external_module_name,
      external_base_name,
    );
    // Import Memory
    Import.add_memory_import(
      wasm_mod,
      "ext_memory",
      external_module_name,
      external_base_name,
      false,
    );
    // Import Global
    Import.add_global_import(
      wasm_mod,
      "ext_global",
      external_module_name,
      external_base_name,
      Type.int32,
      false,
    );
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Get Module", () => {
    let wasm_mod = Module.create();
    let external_module_name = "ext_module";
    let external_base_name = "ext_base";
    // Import Function
    let func_name = "ext_func";
    Import.add_function_import(
      wasm_mod,
      func_name,
      external_module_name,
      external_base_name,
      Type.none,
      Type.none,
    );
    // Import Memory
    Import.add_memory_import(
      wasm_mod,
      "ext_memory",
      external_module_name,
      external_base_name,
      false,
    );
    // Import Global
    Import.add_global_import(
      wasm_mod,
      "ext_global",
      external_module_name,
      external_base_name,
      Type.int32,
      false,
    );

    assert(
      Import.function_import_get_module(
        Function.get_function(wasm_mod, func_name),
      )
      == external_module_name,
    );
    assert(
      Import.memory_import_get_module(wasm_mod, "ext_memory")
      == external_module_name,
    );
    assert(
      Import.global_import_get_module(
        Global.get_global(wasm_mod, "ext_global"),
      )
      == external_module_name,
    );

    Module.dispose(wasm_mod);
  });
  test("Get Base", () => {
    let wasm_mod = Module.create();
    let external_module_name = "ext_module";
    let external_base_name = "ext_base";
    // Import Function
    let func_name = "ext_func";
    Import.add_function_import(
      wasm_mod,
      func_name,
      external_module_name,
      external_base_name,
      Type.none,
      Type.none,
    );
    // Import Memory
    Import.add_memory_import(
      wasm_mod,
      "ext_memory",
      external_module_name,
      external_base_name,
      false,
    );
    // Import Global
    Import.add_global_import(
      wasm_mod,
      "ext_global",
      external_module_name,
      external_base_name,
      Type.int32,
      false,
    );

    assert(
      Import.function_import_get_base(
        Function.get_function(wasm_mod, func_name),
      )
      == external_base_name,
    );
    assert(
      Import.memory_import_get_base(wasm_mod, "ext_memory")
      == external_base_name,
    );
    assert(
      Import.global_import_get_base(
        Global.get_global(wasm_mod, "ext_global"),
      )
      == external_base_name,
    );

    Module.dispose(wasm_mod);
  });
});
