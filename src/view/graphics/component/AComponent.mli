
open Base
open Graphics

class virtual acomponent :
  int ->
  int ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> unit

    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> unit
  end
