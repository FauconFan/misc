
open Base
open Graphics

class layer :
  AComponent.acomponent list ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> unit
  end
