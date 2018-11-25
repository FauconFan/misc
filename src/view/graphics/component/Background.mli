open Base
open Graphics

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

    (** action when we click on the Background *)
    method subClick : (coords * color option) -> (SLAC.scene GMessage.t)
  end