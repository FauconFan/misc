open Graphics
open Base
open Background
open Button
open Cursor
open FrameBSP
open Popup
open Text


let beige = rgb 247 226 156 

let defaultScene config =
  let frame = new frameBSP config (0, 0) in
  let layer = new SLAC.layer [frame] in
  new SLAC.scene [| layer |]

(* let menu config =
  let (w, h) = config.dims in
  let ex = (w + (w / 2), h + (h / 2)) in
  let tupple (a,b) f g = (f a, g b) in
  let beige = rgb 247 226 156 in
  let background = new background beige ex (0,0) in
  let button_test = new button (100,100) ["coucou"; "couc"] (tupple config.dims (fun a -> a/3) (fun a -> a/3)) (fun a -> print_endline "coucou"; GMessage.Nothing) in
  let button_test2 = new button (100,100) ["coucou"] (0,0) (fun a -> print_endline "coucou2"; GMessage.Nothing) in
  let x = ref 20 in
  let cursor_test = new cursor (300,20) 50 100 x (tupple config.dims (fun a -> a/4) (fun a -> a/4)) (~- 50, 17) in
  let text_test =  new text ["test1"; "test2"; "test3"] (600,200) in
  let popup = new popup ["coucou, je test"; "Kkk"; "lol"] [button_test2] (300,200) (500,500) in
  let popups = new SLAC.layer [popup] in
  let cursors = new SLAC.layer [cursor_test] in
  let background = new SLAC.layer [background] in
  let buttons = new SLAC.layer [button_test] in
  let text = new SLAC.layer [text_test] in
  new SLAC.scene [| background; buttons; cursors; popups; text|]  *)

let rec param config = 
  let (w, h) = config.dims in
  let background_test = new background beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let text_zone = new text ["Vous etes tombes dans une page troll"; "Oulah oulah"; "Retourner au menu en appuyant sur le bouton retour."] (w/2 - 400, h/2 + 100) in
  let text_layer = new SLAC.layer [text_zone] in
  let button_retour = new button (100,100) ["Retour"] (w/2 - 100, 200) (fun a -> GMessage.Update (fun () -> menu config)) in
  let button_layer = new SLAC.layer [button_retour] in
  new SLAC.scene [|background_layer; text_layer; button_layer|]

and
menu config = 
  let (w, h) = config.dims in
  let background_test = new background beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let depth = ref 0 in
  let width = ref 0 in
  let height = ref 0 in
  let button_launch = new button (200,70) ["Jouer"] (w/2 - 100, 800) (fun a -> GMessage.Update (fun () -> play_game {dims = (!width ,!height); depth = !depth})) in
  let button_param = new button (200,70) ["Parametres"] (w/2 - 100, 650) (fun a -> GMessage.Update (fun () -> param config)) in
  let button_quit = new button (200,70) ["Quitter"] (w/2 - 100, 100) (fun a -> GMessage.Update (fun () -> raise Exit)) in  
  let button_layer = new SLAC.layer [button_launch; button_param; button_quit] in
  let text_with = new text ["Largeur de la fenetre :"] (w/2 - 150, 570) in
  let cursor_width = new cursor (300,20) 200 1920 width (w/2 - 150, 530) (~- 50, 23) in
  let text_height = new text ["Hauteur de la fenetre :"] (w/2 - 150, 455) in
  let cursor_height = new cursor (300,20) 200 1920 height (w/2 - 150, 415) (~- 50, 23) in
  let text_depth = new text ["Profondeur du bsp :"] (w/2 - 150, 340) in
  let cursor_depth = new cursor (300,20) 1 50 depth (w/2 - 150, 300) (~- 50, 11) in
  let cursor_layer = new SLAC.layer [cursor_depth; cursor_height; cursor_width] in
  let text_layer = new SLAC.layer [text_with; text_depth; text_height] in
  new SLAC.scene [|background_layer; button_layer; cursor_layer; text_layer|]

and 
play_game config = 
  let (w, h) = config.dims in
  let text_check = new text ["zone de texte"] (100,100) in
  let frame = new frameBSP config (0, 0) in
  let button_solve = new button (100,100) ["solve"] (w/2 - 50, 800) (fun a -> GMessage.Apply (fun a -> print_endline "solve")) in
  let button_check = new button (100,100) ["check"] (w/2 - 50, 600) (fun a -> GMessage.Apply (fun a -> print_endline "check_current")) in
  let button_check_solve = new button (100,100) ["check solve"] (w/2 - 50, 600) (fun a -> GMessage.Apply (fun a -> print_endline "check_solve")) in
  let button_reset = new button (100,100) ["Reset"; "Game"] (w/2 - 50, 800) (fun a -> GMessage.Update (fun () -> play_game config)) in
  let button_menu = new button (100,100) ["Menu"] (w/2 - 50, 600) (fun a -> GMessage.Update (fun () -> menu config)) in
  let button_quit = new button (100,100) ["Quit"] (w/2 - 50, 600) (fun a -> GMessage.Update (fun () -> raise Exit)) in
  let button_layer = new SLAC.layer [button_solve; button_check; button_check_solve; button_menu; button_reset; button_quit] in
  let bsp_layer = new SLAC.layer [frame] in
  let text_layer = new SLAC.layer [text_check] in
  new SLAC.scene [|bsp_layer; button_layer; text_layer|]
