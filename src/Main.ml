
open Base
open Exemple_bsp

let () =
  (* let fnc = FNC.bsp_to_fnc exemple1 in
  Printf.printf "%d\n" (List.length fnc);
  List.map (fun l -> (List.map FNC.string_of_litt l)) fnc
  |> List.map (fun l -> List.fold_left (fun a b -> a ^ " " ^ b) "" l)
  |> List.fold_left (fun a b -> a ^ "\n" ^ b) ""
  |> print_endline; *)
  let config = CLIParser.cliparse () in

     Random.self_init ();

     (* let bsp = Generation.random_bsp_naive config in *)

     DUGraphics.init config;
     DUGraphics.launch config exemple1;
     DUGraphics.close ()
