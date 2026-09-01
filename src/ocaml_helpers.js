//Provides: caml_ml_output_str_stdout
//Requires: caml_ml_std_channel_id
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_ml_output_str_stdout(text) {
  var chanid = caml_ml_std_channel_id[1]; // stdout
  
  const raw_string = caml_string_of_jsstring(text);
  const length = caml_ml_string_length(raw_string);
  caml_ml_output(chanid, raw_string, 0, length);
}