open Base
open Graphics

class Button :
  dim ->
  string ->
  coords ->
  ((coords * color option) -> unit) ->
  object
    inherit SLAC.acomponent
    val mutable name : string
    
    (** We draw lines and rects of the button (call of super#draw) and print the content string centered inside the button*)
    method draw : unit -> unit

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the button *)
    method subClick : (coords * color option) -> (SLAC.scene GMessage.t)
  end