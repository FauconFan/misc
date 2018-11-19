
open Base
open Graphics

class scene :
  Layer.layer array ->
  object
    method draw : unit -> unit
    method click : (coords * color option) -> unit
  end
