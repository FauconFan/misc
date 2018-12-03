
open Base
open Graphics

exception Wrong_Construct of string

class scene :
  layer array ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t) list
  end

and layer :
  acomponent list ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t) list
  end

and virtual acomponent :
  coords ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> (scene GMessage.t)

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> (scene GMessage.t)
  end
