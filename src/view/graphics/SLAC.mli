
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
    method draw : unit -> unit
    method click : uevent -> (scene GMessage.t) list
  end

and layer :
  acomponent list ->
  object
    method draw : unit -> unit
    method click : uevent -> (scene GMessage.t) list
  end

and virtual acomponent :
  coords ->
  dim ->
  object
    method draw : unit -> unit
    method click : uevent -> (scene GMessage.t)

    method getStrings : unit -> string_content list
    method getLines : unit -> (coords * coords * color * int) list
    method getRects : unit -> (coords * dim * color) list

    method virtual subClick : uevent -> (scene GMessage.t)
  end
