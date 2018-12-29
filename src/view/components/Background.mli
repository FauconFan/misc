
(**
  A background component for graphic's view
*)

open Base
open Graphics

class background :
  color ->
  dim ->
  coords ->
  object
    inherit SLAC.acomponent

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the popup -> distrub it on button *)
    method subClick : uevent -> (SLAC.scene GMessage.t)
  end
