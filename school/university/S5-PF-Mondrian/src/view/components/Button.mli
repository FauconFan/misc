
(**
   A button component for graphic's view
*)

open Base
open Graphics

class button :
  ?color_font:color ->
  ?default_padding:int ->
  dim ->
  string list ->
  coords ->
  ((coords * color option) -> SLAC.scene GMessage.t) ->
  object
    inherit SLAC.acomponent

    val mutable padding : int

    (** Get rects which need to be drawn *)
    method getRects : unit -> (coords * dim * color) list

    (** action when we click on the button *)
    method subClick : uevent -> (SLAC.scene GMessage.t)

    (** Get strings which need to be drawn *)
    method getStrings : unit -> string_content list

    (** Reset the padding according to the default padding *)
    method resetPadding : unit -> unit

    (** Set padding *)
    method setPadding : int -> unit
  end
