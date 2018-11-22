open Base
open Graphics

class Cursor dim min max coord =

  object (self)
  inherit SLAC.acomponent coord as super
    val mutable pos : int

    method draw () : unit =

    method getLines () : (coords * coords * color * int) list =

    method getRects () : (coords * dim * color) list =

    method subClick (coords, color) : (SLAC.scene GMessage.t) =
    
  end