module C = Configurator.V1

let () =
  C.main ~name:"link_flags" (fun c ->
      let link_flags =
        match C.ocaml_config_var c "system" with
        | None -> []
        | Some ("linux" | "macosx") -> []
        | Some "mingw64" -> [ "-cc"; "x86_64-w64-mingw32-g++" ]
        | Some unknown ->
            failwith ("We don't know how to build for platform: " ^ unknown)
      in

      C.Flags.write_sexp "link_flags.sexp" link_flags)
