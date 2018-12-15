
(** SLAC Module. SLAC stands for Scene, Layer, and AComponent *)

(**
   This module handles all the magical utilities about the view.
   A scene is a container for layers.
   A layer is a container for acomponents.
   An acomponent can be a clickable, drawable, and / or readable object.
*)

open Base
open Graphics

exception Wrong_Construct of string

class scene :
  layer array ->
  object
    method draw : config -> unit
    method click : config -> (coords * color option) -> (scene GMessage.t) list
  end

and layer :
  acomponent list ->
  object
    method draw : config -> unit
    method click : config -> (coords * color option) -> (scene GMessage.t) list
  end

and virtual acomponent :
  coords ->
  dim ->
  object
    method draw : config -> unit
    method click : config -> (coords * color option) -> (scene GMessage.t)

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> (scene GMessage.t)
  end
