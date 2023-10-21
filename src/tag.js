//Provides: caml_binaryen_add_tag
//Requires: caml_jsstring_of_string
function caml_binaryen_add_tag(wasm_mod, name, params, results) {
  return wasm_mod.addTag(
    caml_jsstring_of_string(name),
    params,
    results,
  );
}

//Provides: caml_binaryen_get_tag
//Requires: caml_jsstring_of_string
function caml_binaryen_get_tag(wasm_mod, name) {
  return wasm_mod.getTag(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_remove_tag
//Requires: caml_jsstring_of_string
function caml_binaryen_remove_tag(wasm_mod, name) {
  return wasm_mod.removeTag(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_tag_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tag_get_name(tag) {
  var tag_info = Binaryen.getTagInfo(tag);
  return caml_string_of_jsstring(tag_info.name);
}

//Provides: caml_binaryen_tag_get_params
//Requires: Binaryen
function caml_binaryen_tag_get_params(tag) {
  var tag_info = Binaryen.getTagInfo(tag);
  return tag_info.params;
}

//Provides: caml_binaryen_tag_get_results
//Requires: Binaryen
function caml_binaryen_tag_get_results(tag) {
  var tag_info = Binaryen.getTagInfo(tag);
  return tag_info.results;
}
