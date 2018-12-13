open Base
open Graphics

(**
  A popup component for graphic's view
*)

class popup :
  string list ->
  Button.button list ->
  dim ->
  coords ->
  object
    inherit SLAC.acomponent

    (** Get lines which need to be drawn *)
    method getLines : unit -> (coords * coords * color * int) list

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the popup -> distrub it on button *)
    method subClick : (coords * color option) -> (SLAC.scene GMessage.t)

    (** Get strings which need to be drawn *)    
    method getStrings : unit -> string_content list
  end