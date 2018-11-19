
open Base
open Graphics

class frameBSP :
  config ->
  int ->
  int ->
  object
    inherit AComponent.acomponent
    val mutable bsp : bsp

    method getLines : unit -> (coords * coords * color * int) list
    method getRects : unit -> (coords * dim * color) list
    method subClick : (coords * color option) -> unit
  end
