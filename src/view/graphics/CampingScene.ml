open Graphics
open Base
open Background
open Button
open Cursor
open FrameBSP
open Popup
open Text


let defaultScene config =
  let frame = new frameBSP config (0, 0) in
  let layer = new SLAC.layer [frame] in
  new SLAC.scene [| layer |]

let menu config =
  let (w, h) = config.dims in
  let ex = (w + (w / 2), h + (h / 2)) in
  let tupple (a,b) f g = (f a, g b) in
  let beige = rgb 247 226 156 in
  let background = new background beige ex (0,0) in
  let button_test = new button (100,100) ["coucou"; "couc"] (tupple config.dims (fun a -> a/2) (fun a -> a/2)) (fun a -> print_endline "coucou"; GMessage.Nothing) in
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
  new SLAC.scene [| buttons; cursors; popups; text|] 