open Base
open Graphics

(**
  A background component for graphic's view
*)

class background :
  color ->
  dim ->
  coords ->
  object
    inherit SLAC.acomponent

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** Get strings which need to be drawn *)
    method getStrings : unit -> string_content list

    (** action when we click on the popup -> distrub it on button *)
    method subClick : uevent -> (SLAC.scene GMessage.t)
  end
