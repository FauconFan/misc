open Base
open Graphics

(**
   A text component for graphic's view
*)

class text :
  ?center:bool ->
  string list ->
  coords ->
  object
    inherit SLAC.acomponent

    (** content of the text box *)
    val mutable content : string list

    (** change content of text box *)
    method change_content : string list -> unit

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the frameBSP -> change color of a rectangle *)
    method subClick : uevent -> (SLAC.scene GMessage.t)

    (** Get strings which need to be drawn *)
    method getStrings : unit -> string_content list
  end
