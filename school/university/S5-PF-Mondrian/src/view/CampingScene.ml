open Graphics
open Base
open Background
open Button
open ButtonColor
open Cursor
open FrameBSP
open Text


let rec param config_menu config_base =
  GraphicsManager.changeConfig config_menu;
  let (w, h) = config_menu.dims in
  let background_test = new background GraphicsConstant.beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let text_zone = new text ~center:true ["Vous etes dans la page de parametre,"; "vous pouvez modifier les constantes suivantes :"] (w/2, h - 200) in
  let text_random = new text ~center:true ["Coefficient random des rectangles :"] (w/2, 570) in
  let cursor_random = new cursor (300,20) 1 100 ModelConstant.random_pad (w/2 - 150, 515) (~- 50, 23) in
  let text_rect_size = new text ~center:true ["Dimension minimale d'un rectangle :"] (w/2, 455) in
  let cursor_rect_size = new cursor (300,20) 3 100 ModelConstant.min_size_rect (w/2 - 150, 400) (~- 50, 23) in
  let text_layer = new SLAC.layer [(text_zone :> SLAC.acomponent); (text_random :> SLAC.acomponent); (text_rect_size :> SLAC.acomponent)] in
  let cursor_layer = new SLAC.layer [cursor_rect_size; cursor_random] in
  let button_retour = new button (100,100) ["Retour"] (w/2 - 50, 200) (fun _ -> GMessage.Update (fun () -> menu config_menu config_base)) in
  let button_layer = new SLAC.layer [(button_retour :> SLAC.acomponent)] in
  new SLAC.scene [|background_layer; text_layer; cursor_layer; button_layer|]

and
  menu config_menu config_base =
  GraphicsManager.changeConfig config_menu;
  let (w, h) = config_menu.dims in
  let background_test = new background GraphicsConstant.beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let depth = ref config_base.depth in
  let width = ref (fst config_base.dims) in
  let height = ref (snd config_base.dims) in
  let button_launch = new button (200,70) ["Jouer"] (w/2 - 100, 800) (fun _ -> GMessage.Update (fun () -> play_game config_menu {dims = (!width ,!height); depth = !depth})) in
  let button_param = new button (200,70) ["Parametres"] (w/2 - 100, 650) (fun _ -> GMessage.Update (fun () -> param config_menu {dims = (!width ,!height); depth = !depth})) in
  let button_quit = new button (200,70) ["Quitter"] (w/2 - 100, 100) (fun _ -> GMessage.Update (fun () -> raise Exit)) in
  let button_layer = new SLAC.layer [(button_launch :> SLAC.acomponent); (button_param :> SLAC.acomponent); (button_quit :> SLAC.acomponent)] in
  let text_with = new text ["Largeur de la fenetre :"] (w/2 - 150, 570) in
  let cursor_width = new cursor (300,20) 200 1500 width (w/2 - 150, 530) (~- 50, 23) in
  let text_height = new text ["Hauteur de la fenetre :"] (w/2 - 150, 455) in
  let cursor_height = new cursor (300,20) 900 1100 height (w/2 - 150, 415) (~- 50, 23) in
  let text_depth = new text ["Profondeur du bsp :"] (w/2 - 150, 340) in
  let cursor_depth = new cursor (300,20) 1 50 depth (w/2 - 150, 300) (~- 50, 11) in
  let cursor_layer = new SLAC.layer [cursor_depth; cursor_height; cursor_width] in
  let text_layer = new SLAC.layer [(text_with :> SLAC.acomponent); (text_depth :> SLAC.acomponent); (text_height :> SLAC.acomponent)] in
  new SLAC.scene [|background_layer; button_layer; cursor_layer; text_layer|]

and
  credit config_menu config_base =
  GraphicsManager.changeConfig config_menu;
  let (w, h) = config_menu.dims in
  let background_test = new background GraphicsConstant.beige (w,h) (0,0) in
  let background_layer = new SLAC.layer [background_test] in
  let text_message = new text ~center:true ["Bravo !!"; "Vous avez reussi a finir le puzzle !!"] (w/2, h - 100) in
  let text_zone = new text ~center:true ["Credits :"; ""; "Directeurs en chef   : Joseph Priou et Xavier Durand"; "Designers en chef    : Un ours et un tigre          "; "Programmeurs en chef : Un grand gros et un petit fin"] (w/2, h - 250) in
  let text_layer = new SLAC.layer [(text_message :> SLAC.acomponent); (text_zone :> SLAC.acomponent)] in
  let button_reset = new button (180,60) ["Recommencer"] (w/2 - 90, 350) (fun _ -> GMessage.Update (fun () -> play_game config_menu config_base)) in
  let button_menu = new button (180,60) ["Menu"] (w/2 - 90, 250) (fun _ -> GMessage.Update (fun () -> menu config_menu config_base)) in
  let button_quit = new button (180,60) ["Quitter"] (w/2 - 90, 150) (fun _ -> GMessage.Update (fun () -> raise Exit)) in
  let button_layer = new SLAC.layer [(button_menu :> SLAC.acomponent); (button_reset :> SLAC.acomponent); (button_quit :> SLAC.acomponent)] in
  new SLAC.scene [|background_layer; text_layer; button_layer|]

and
  play_game config_menu config_base =
  let (w, h) = config_base.dims in
  let config = {config_base with dims = (w + GraphicsConstant.widthrb, h) } in
  GraphicsManager.changeConfig config;
  let (w, h) = config.dims in
  let text_check = new text ~center:true ["Informations"] (w - (GraphicsConstant.widthrb / 2), 100) in
  let frame = new frameBSP config_base (0, 0) in
  let fun_solve _ =
    text_check#change_content ["Calcul en cours"];
    let bsp = Check.solve (frame#get_bsp ()) in
    Option.map_default
      (fun a -> (["Vous avez"; "utiliser solve"] |> text_check#change_content; frame#change_bsp a) )
      ((["Solve : Il n'y"; "a pas de solution"; "possible"] |> text_check#change_content))
      bsp
  in
  let fun_check_solve _ =
    text_check#change_content ["Calcul en cours"];
    let b = Check.check_solve (frame#get_bsp ()) in
    if b then text_check#change_content ["Il existe ";"une solution"]
    else text_check#change_content ["Il n'y a pas" ; "de solution"; "possible"]
  in
  let fun_check _ =
    text_check#change_content ["Calcul en cours"];
    let b = Check.check_current (frame#get_bsp ()) in
    if b then text_check#change_content ["Le puzzle actuelle"; "est viable"]
    else text_check#change_content ["Le puzzle actuelle"; "n'est pas"; "correct"]
  in
  let fun_submit _ =
    text_check#change_content ["Calcul en cours"];
    let b = Check.check_current (frame#get_bsp ()) in
    if b then (text_check#change_content ["Le puzzle actuelle"; "est viable"]; true)
    else (text_check#change_content ["Le puzzle actuelle"; "n'est pas"; "correct"]; false)
  in
  let button_solve = new button (180,60) ["Solution"] (w - 230, 800) (fun _ -> GMessage.Apply fun_solve) in
  let button_check_solve = new button (85,60) ["Exist"] (w - 230, 700) (fun _ -> GMessage.Apply fun_check_solve) in
  let button_check = new button (85,60) ["Verif"] (w - 135, 700) (fun _ -> GMessage.Apply fun_check) in
  let button_submit = new button (180,60) ["Soumettre"] (w - 230, 600) (fun _ -> if fun_submit () then (GMessage.Update (fun () -> credit config_menu config_base)) else Nothing) in
  let button_reset = new button (180,60) ["Recommencer"] (w - 230, 500) (fun _ -> GMessage.Update (fun () -> play_game config_menu config_base)) in
  let button_menu = new button (180,60) ["Menu"] (w - 230, 400) (fun _ -> GMessage.Update (fun () -> menu config_menu config_base)) in
  let button_quit = new button (180,60) ["Quitter"] (w - 230, 300) (fun _ -> GMessage.Update (fun () -> raise Exit)) in
  let button_red = new button_color (Some red) 70 (w - 215, 200) in
  let button_blue = new button_color (Some blue) 70 (w - 135, 200) in
  let button_white = new button_color None 70 (w - 175, 120) in
  let button_layer = new SLAC.layer [(button_solve :> SLAC.acomponent); (button_check :> SLAC.acomponent); (button_check_solve :> SLAC.acomponent); (button_submit :> SLAC.acomponent); (button_menu :> SLAC.acomponent); (button_reset :> SLAC.acomponent); (button_quit :> SLAC.acomponent)] in
  let button_colors_layer = new SLAC.layer [(button_red :> SLAC.acomponent); (button_blue :> SLAC.acomponent); (button_white :> SLAC.acomponent)] in
  let bsp_layer = new SLAC.layer [(frame :> SLAC.acomponent)] in
  let text_layer = new SLAC.layer [(text_check :> SLAC.acomponent)] in
  new SLAC.scene [|bsp_layer; button_layer; button_colors_layer; text_layer|]
