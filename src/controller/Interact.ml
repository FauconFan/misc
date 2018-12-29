
open Base
open Graphics

(* Contains the set of colors used in the program *)
let table_of_color = [('r', red); ('b', blue)]

(* Key to exit the program *)
let key_quit = 'q'

let getAllColors () =
  table_of_color
  |> List.rev_map (fun (_, c) -> c)

(* Current drawing color *)
let actual_color = ref None

let getColorOpt () =
  !actual_color

(* Change the current color and returns it *)
let changeColor c =
  let col_tmp = List.find_opt (fun (ch, _) -> c = ch) table_of_color in
  let col = match col_tmp with
    | None -> None
    | Some (_, c) -> Some c
  in
  actual_color := col

let changeColorOpt copt =
  match copt with
  | None -> actual_color := None
  | Some c ->
    begin
      if List.exists (fun (_, col) -> c = col) table_of_color then actual_color := copt
    end

let last_button_pressed = ref false

(*
   Fonction d'interaction avec l'utilisateur :
   - 'q' pour quitter le jeu
   - 'r'/ 'b' pour mettre en couleur
   - 'n' pour enlever la couleur
*)
let interact () : uevent option =
  let check_key_pressed () =
    let event =
      let list_events =
        if key_pressed () then [Key_pressed]
        else [Key_pressed; Poll]
      in
      wait_next_event list_events
    in
    if event.keypressed then
      begin
        match event.key with
        | k when k = key_quit -> raise Exit
        | k -> changeColor k
      end
    else ()
  in
  let check_button_pressed () =
    let event =
      wait_next_event [Button_down; Poll]
    in
    let mouse = (event.mouse_x, event.mouse_y) in
    let bounds_screen =
      let screen = (size_x (), size_y ()) in
      bounds mouse screen
    in
    if not bounds_screen || not event.button then
      begin
        if not event.button then last_button_pressed := false;
        None
      end
    else if not !last_button_pressed then
      begin
        last_button_pressed := true;
        Some (Click (mouse, !actual_color))
      end
    else Some (Motion (mouse, !actual_color))
  in
  check_key_pressed ();
  check_button_pressed ()
