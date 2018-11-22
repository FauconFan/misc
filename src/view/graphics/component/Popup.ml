open Base
open Graphics

class Popup content button coord =
  object (self)
    inherit SLAC.acomponent coord as super

    method draw () : unit =

    method getLines () : (coords * coords * color * int) list =

    method getRects () : (coords * dim * color) list =

    method subClick (coords, color) : (SLAC.scene GMessage.t) =

  end