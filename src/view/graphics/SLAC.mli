
open Base
open Graphics

exception Wrong_Construct of string

val id : int ref

class scene :
  layer array ->
  object
    val id_comp : int
    method getId : unit -> int
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t) list
  end

and layer :
  acomponent list ->
  object
    val id_comp : int
    method getId : unit -> int
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t) list
  end

and virtual acomponent :
  coords ->
  object
    val id_comp : int
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t)
    method getId : unit -> int

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> (scene GMessage.t)
  end
