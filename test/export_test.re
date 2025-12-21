open Binaryen;
open Frame_work;

suite("Export", () => {
  let create_test_func = (wasm_mod, name) => {
    Function.add_function(
      wasm_mod,
      name,
      Type.none,
      Type.none,
      [||],
      Expression.Nop.make(wasm_mod),
    );
  };
  test("AddFunctionExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let _ = create_test_func(wasm_mod, internal_name);
    let _ = Export.add_function_export(wasm_mod, internal_name, "funcExport");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("AddTableExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedTable";
    let _ = Table.add_table(wasm_mod, internal_name, 0, 1, Type.funcref);
    let _ = Export.add_table_export(wasm_mod, internal_name, "tableExport");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("AddMemoryExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedMemory";
    // Note: By default memories are exported
    let _ =
      Memory.set_memory(
        wasm_mod,
        1,
        Memory.unlimited,
        "DefaultMemoryExport",
        [],
        false,
        false,
        internal_name,
      );
    let _ = Export.add_memory_export(wasm_mod, internal_name, "memoryExport");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("AddGlobalExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedGlobal";
    let _ =
      Global.add_global(
        wasm_mod,
        internal_name,
        Type.int32,
        false,
        Expression.Const.make(wasm_mod, Literal.int32(1l)),
      );
    let _ = Export.add_global_export(wasm_mod, internal_name, "globalExport");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("GetNumExports", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let _ = create_test_func(wasm_mod, internal_name);
    assert(Export.get_num_exports(wasm_mod) == 0);
    let _ = Export.add_function_export(wasm_mod, internal_name, "funcExport");
    assert(Export.get_num_exports(wasm_mod) == 1);
    Module.dispose(wasm_mod);
  });
  test("RemoveExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let export_name = "funcExport";
    let _ = create_test_func(wasm_mod, internal_name);
    let _ = Export.add_function_export(wasm_mod, internal_name, export_name);
    assert(Export.get_num_exports(wasm_mod) == 1);
    Export.remove_export(wasm_mod, export_name);
    assert(Export.get_num_exports(wasm_mod) == 0);
    Module.dispose(wasm_mod);
  });
  test("GetName", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let export_name = "funcExport";
    let _ = create_test_func(wasm_mod, internal_name);
    let test_export =
      Export.add_function_export(wasm_mod, internal_name, export_name);
    assert(Export.get_name(test_export) == export_name);
    Module.dispose(wasm_mod);
  });
  test("GetExport", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let export_name = "funcExport";
    let _ = create_test_func(wasm_mod, internal_name);
    let _ = Export.add_function_export(wasm_mod, internal_name, export_name);
    let fetched_export = Export.get_export(wasm_mod, export_name);
    assert(Export.get_name(fetched_export) == export_name);
    Module.dispose(wasm_mod);
  });
  test("GetExportByIndex", () => {
    let wasm_mod = Module.create();
    let internal_name1 = "ExportedFunc";
    let export_name1 = "funcExport1";
    let internal_name2 = "ExportedFunc2";
    let export_name2 = "funcExport2";
    let _ = create_test_func(wasm_mod, internal_name1);
    let _ = create_test_func(wasm_mod, internal_name2);
    let _ =
      Export.add_function_export(wasm_mod, internal_name1, export_name1);
    let _ =
      Export.add_function_export(wasm_mod, internal_name2, export_name2);
    let fetched_export1 = Export.get_export_by_index(wasm_mod, 0);
    let fetched_export2 = Export.get_export_by_index(wasm_mod, 1);
    assert(Export.get_name(fetched_export1) == export_name1);
    assert(Export.get_name(fetched_export2) == export_name2);
    Module.dispose(wasm_mod);
  });
  test("GetValue", () => {
    let wasm_mod = Module.create();
    let internal_name = "ExportedFunc";
    let export_name = "funcExport";
    let _ = create_test_func(wasm_mod, internal_name);
    let test_export =
      Export.add_function_export(wasm_mod, internal_name, export_name);
    assert(Export.get_value(test_export) == internal_name);
    Module.dispose(wasm_mod);
  });
  test("GetKind", () => {
    let wasm_mod = Module.create();
    // Function Export
    let _ = create_test_func(wasm_mod, "ExportedFunc");
    let func_export =
      Export.add_function_export(wasm_mod, "ExportedFunc", "funcExport");
    assert(Export.export_get_kind(func_export) == Export.external_function);
    // Table Export
    let _ = Table.add_table(wasm_mod, "ExportedTable", 0, 1, Type.funcref);
    let table_export =
      Export.add_table_export(wasm_mod, "ExportedTable", "tableExport");
    assert(Export.export_get_kind(table_export) == Export.external_table);
    // Memory Export
    let _ =
      Memory.set_memory(
        wasm_mod,
        1,
        Memory.unlimited,
        "DefaultMemoryExport",
        [],
        false,
        false,
        "ExportedMemory",
      );
    let memory_export =
      Export.add_memory_export(wasm_mod, "ExportedMemory", "memoryExport");
    assert(Export.export_get_kind(memory_export) == Export.external_memory);
    // Global Export
    let _ =
      Global.add_global(
        wasm_mod,
        "ExportedGlobal",
        Type.int32,
        false,
        Expression.Const.make(wasm_mod, Literal.int32(1l)),
      );
    let global_export =
      Export.add_global_export(wasm_mod, "ExportedGlobal", "globalExport");
    assert(Export.export_get_kind(global_export) == Export.external_global);
    // TODO(#264): Can't test Tag export until tags are implemented
    Module.dispose(wasm_mod);
  });
});
