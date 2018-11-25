open Graphics
open Base
open Background
open Button
open Cursor
open FrameBSP
open Popup


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
  let button_test = new button (100,20) "coucou" (tupple config.dims (fun a -> a/2) (fun a -> a/2)) (fun a b -> print_endline "coucou") in
  let background = new SLAC.layer [background] in
  let buttons = new SLAC.layer [button_test] in
  new SLAC.scene [|background; buttons|] 