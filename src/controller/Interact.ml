
open Base
open Graphics

(* Contains the set of colors used in the program *)
let table_of_color = [('r', red); ('b', blue)]

(* Key to exit the program *)
let key_quit = 'q'

let getAllColors () =
  table_of_color
  |> List.map (fun (_, c) -> c)

(* Current drawing color *)
let actual_color = ref None


(* Change the current color and returns it *)
let changeColor c =
  let col_tmp = List.find_opt (fun (ch, _) -> c = ch) table_of_color in
  let col = match col_tmp with
    | None -> None
    | Some (_, c) -> Some c
  in
  Option.map_default set_color (white |> set_color) col;
  actual_color := col

(*
   Fonction d'interaction avec l'utilisateur :
   - 'q' pour quitter le jeu
   - 'r'/ 'b' pour mettre en couleur
   - 'n' pour enlever la couleur
*)
let rec interact () : coords * color option =
  let even = wait_next_event([Key_pressed; Button_down])
  in
  if even.keypressed then
    (match even.key with
     | k when k = key_quit -> raise Exit
     | k -> changeColor k);
  if even.button then
    let mouse = (even.mouse_x, even.mouse_y)
    and screen = (size_x (), size_y ()) in
    if bounds mouse screen
    then (mouse, ! actual_color)
    else interact ()
  else interact ()
