
open Graphics
open Base

(*
  Initialisation de la fenêtre graphique et lancement du puzzle
*)
let init (config:config) : unit =
  let (w, h) = config.dims in
    open_graph (" " ^ (string_of_int w) ^ "x" ^ (string_of_int h));
    set_window_title "PF5_mondrian";
    auto_synchronize false

(*
  Fonction de cloture de l'interface graphic
*)
let close () : unit =
  close_graph ()

(*
  Fonction de dessin de tous les rectangles du bsp
*)
let rec fill_all_rect (rects : (rect * color option) list) : unit =
  match rects with
  | [] -> ()
  | (((x,y),(w,h)), c) :: rest ->
    set_color white;
    Option.may (set_color) c;
    fill_rect x y w h;
    set_color white;
    fill_all_rect rest

(*
  Fonction de dessin des lignes en fonction de leurs couleurs
*)
let rec draw_all_line (lines : (line * color option) list) : unit =
  match lines with
  | [] -> ()
  | (((x,y),(a,b)), c) :: rest ->
    let aux col line =
      col;
      set_line_width line;
      moveto x y;
      lineto a b
    in
    aux (white |> set_color) 5;
    aux (Option.map_default (set_color) (black |> set_color) c) 3;
    draw_all_line rest

(*
  Fonction de dessin du bsp courant et des lignes
*)
let draw_current_bsp config bsp =
  clear_graph();
  fill_all_rect (Translate.rectangles_from_bsp config bsp);
  draw_all_line (Translate.lines_from_bsp config bsp);
  synchronize ()

(*
  Lancement du puzzle et attente des interactions avec le joueur (cf manuel du module Translate pour la fonction interact)
*)
let launch (config : config) (bsp:bsp) : unit =
  let bsp = ref bsp in
  while true do
    draw_current_bsp config (!bsp);
    try bsp := Bsp.change_rectangle_color (Interact.interact ()) (!bsp)
    with Exit -> close (); exit 0
  done
