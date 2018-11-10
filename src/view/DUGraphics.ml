
open Exemple_bsp
open Graphics
open Base

(**
  Initialisation de la fenêtre graphique et lancement du puzzle
*)
let init (config:config) : unit =
  let (w, h) = config.dims in
    open_graph (" " ^ (string_of_int w) ^ "x" ^ (string_of_int h));
    set_window_title "PF5_mondrian";
    auto_synchronize false

(**
  Fonction de cloture de l'interface graphic
*)
let close () : unit =
  close_graph ()

(**
  Fonction de dessin de tous les rectangles du bsp
*)
let rec fill_all_rect (rects : (rect * color option) list) : unit =
  match rects with
  | [] -> ()
  | (((x,y),(w,h)), c) :: rest ->
    set_color white;
    maybe (set_color) c ();
    fill_rect x y w h;
    set_color white;
    fill_all_rect rest

(**
  Fonction de dessin des lignes en fonction de leurs couleurs
*)
let rec draw_all_line (lines : (line * color option) list) : unit =
  match lines with
  | [] -> ()
  | (((x,y),(a,b)), c) :: rest ->
    set_line_width 3;
    if c == None then set_color black;
    maybe (set_color) c ();
    moveto x y;
    lineto a b;
    maybe (set_color) (Some(white)) ();
    draw_all_line rest

(**
  Fonction de dessin du bsp courant et des lignes
*)
let draw_current_bsp config bsp_fc bsp_cu =
  clear_graph();
  fill_all_rect (Translate.rectangles_from_bsp config bsp_cu);
  draw_all_line (Translate.lines_from_bsp config bsp_fc);
  synchronize ()

(**
  Lancement du puzzle et attente des interactions avec le joueur (cf manuel du module Translate pour la fonction interact)
*)
let launch (config : config) : unit =
  let bsp_fc = exemple_cours
  and bsp_cu = ref exemple_cours in
  while true do
    draw_current_bsp config bsp_fc (!bsp_cu);
    try bsp_cu := change_rectangle_color (Interact.interact ()) (!bsp_cu)
    with Exit -> close (); exit 0
  done
