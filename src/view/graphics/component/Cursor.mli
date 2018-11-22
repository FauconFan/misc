open Base
open Graphics

class Cursor :
  dim ->
  int -> (* min possible *)
  int -> (* max possible *)
  coords ->
  object
    inherit SLAC.acomponent
    val mutable pos : int

    (** We draw lines and rects of the cursor (call of super#draw) and print the position int on the right*)
    method draw : unit -> unit

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the cursor *)
    method subClick : (coords * color option) -> (SLAC.scene GMessage.t)
  end