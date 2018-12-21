open Graphics
open Base
open Background
open Button
open ButtonColor
open Cursor
open FrameBSP
open Popup
open Text


let beige = rgb 247 226 156

let defaultScene config =
  let frame = new frameBSP config (0, 0) in
  let layer = new SLAC.layer [frame] in
  new SLAC.scene [| layer |]

let rec param config =
  GraphicsManager.changeConfig config;
  let (w, h) = config.dims in
  let background_test = new background beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let text_zone = new text ["Vous etes tombes dans une page troll"; "Oulah oulah"; "Retourner au menu en appuyant sur le bouton retour."] (w/2 - 400, h/2 + 100) in
  let text_layer = new SLAC.layer [text_zone] in
  let button_retour = new button (100,100) ["Retour"] (w/2 - 100, 200) (fun _ -> GMessage.Update (fun () -> menu config)) in
  let button_layer = new SLAC.layer [(button_retour :> SLAC.acomponent)] in
  new SLAC.scene [|background_layer; text_layer; button_layer|]

and
  menu config =
  GraphicsManager.changeConfig config;
  let (w, h) = config.dims in
  let background_test = new background beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let depth = ref config.depth in
  let width = ref w in
  let height = ref h in
  let button_launch = new button (200,70) ["Jouer"] (w/2 - 100, 800) (fun _ -> GMessage.Update (fun () -> play_game {dims = (!width ,!height); depth = !depth})) in
  let button_param = new button (200,70) ["Parametres"] (w/2 - 100, 650) (fun _ -> GMessage.Update (fun () -> param config)) in
  let button_quit = new button (200,70) ["Quitter"] (w/2 - 100, 100) (fun _ -> GMessage.Update (fun () -> raise Exit)) in
  let button_layer = new SLAC.layer [(button_launch :> SLAC.acomponent); (button_param :> SLAC.acomponent); (button_quit :> SLAC.acomponent)] in
  let text_with = new text ["Largeur de la fenetre :"] (w/2 - 150, 570) in
  let cursor_width = new cursor (300,20) 200 1500 width (w/2 - 150, 530) (~- 50, 23) in
  let text_height = new text ["Hauteur de la fenetre :"] (w/2 - 150, 455) in
  let cursor_height = new cursor (300,20) 200 1000 height (w/2 - 150, 415) (~- 50, 23) in
  let text_depth = new text ["Profondeur du bsp :"] (w/2 - 150, 340) in
  let cursor_depth = new cursor (300,20) 1 50 depth (w/2 - 150, 300) (~- 50, 11) in
  let cursor_layer = new SLAC.layer [cursor_depth; cursor_height; cursor_width] in
  let text_layer = new SLAC.layer [text_with; text_depth; text_height] in
  new SLAC.scene [|background_layer; button_layer; cursor_layer; text_layer|]

and
  play_game config_base =
  let (w, h) = config_base.dims in
  let config = {config_base with dims = (w + 300, h) } in
  GraphicsManager.changeConfig config;
  let (w, h) = config.dims in
  let text_check = new text ~center:true ["zone de texte"] (w - 150, 70) in
  let frame = new frameBSP config_base (0, 0) in
  let button_solve = new button (180,60) ["Solve"] (w - 230, 800) (fun _ -> GMessage.Apply (fun _ -> print_endline "solve")) in
  let button_check_solve = new button (180,60) ["Check_solve"] (w - 230, 700) (fun _ -> GMessage.Apply (fun _ -> print_endline "check_solve")) in
  let button_check = new button (180,60) ["Check"] (w - 230, 600) (fun _ -> GMessage.Apply (fun _ -> print_endline "check_current")) in
  let button_reset = new button (180,60) ["Reset Game"] (w - 230, 500) (fun _ -> GMessage.Update (fun () -> play_game config_base)) in
  let button_menu = new button (180,60) ["Menu"] (w - 230, 400) (fun _ -> GMessage.Update (fun () -> menu config_base)) in
  let button_quit = new button (180,60) ["Quit"] (w - 230, 300) (fun _ -> GMessage.Update (fun () -> raise Exit)) in
  let button_red = new button_color (Some red) 70 (w - 215, 200) in
  let button_blue = new button_color (Some blue) 70 (w - 135, 200) in
  let button_white = new button_color None 70 (w - 175, 120) in
  let button_layer = new SLAC.layer [(button_solve :> SLAC.acomponent); (button_check :> SLAC.acomponent); (button_check_solve :> SLAC.acomponent); (button_menu :> SLAC.acomponent); (button_reset :> SLAC.acomponent); (button_quit :> SLAC.acomponent)] in
  let button_colors_layer = new SLAC.layer [(button_red :> SLAC.acomponent); (button_blue :> SLAC.acomponent); (button_white :> SLAC.acomponent)] in
  let bsp_layer = new SLAC.layer [frame] in
  let text_layer = new SLAC.layer [text_check] in
  new SLAC.scene [|bsp_layer; button_layer; button_colors_layer; text_layer|]
