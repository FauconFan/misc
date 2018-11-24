open Base
open Graphics

class popup :
  string ->
  button list ->
  dim ->
  coords ->
  object
    inherit SLAC.acomponent
    (** We draw lines and rects of the popup (call of super#draw) and print the content string above*)
    method draw : unit -> unit

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the popup -> distrub it on button *)
    method subClick : (coords * color option) -> (SLAC.scene GMessage.t)
  end