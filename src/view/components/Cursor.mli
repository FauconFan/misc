
(**
   A cursor component for graphic's view
*)

open Base
open Graphics

class cursor :
  dim ->
  int -> (* min possible *)
  int -> (* max possible *)
  int ref ->
  coords ->
  coords ->
  object
    inherit SLAC.acomponent
    val mutable pos : int
    val width_cursor : int

    (** update the value *)
    method private update_value : unit -> int

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the cursor *)
    method subClick : uevent -> (SLAC.scene GMessage.t)

    (** Get strings which need to be drawn *)
    method getStrings : unit -> string_content list

  end
