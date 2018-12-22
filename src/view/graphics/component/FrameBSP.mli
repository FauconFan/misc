
open Base
open Graphics

(**
  A frame component for bsp for graphic's view
*)

class frameBSP :
  config ->
  coords ->
  object
    inherit SLAC.acomponent
    val mutable bsp : bsp

    method change_bsp : bsp -> unit

    method get_bsp : unit -> bsp



    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the frameBSP -> change color of a rectangle *)
    method subClick : uevent -> (SLAC.scene GMessage.t)

    (** Get strings which need to be drawn *)
    method getStrings : unit -> string_content list
  end
