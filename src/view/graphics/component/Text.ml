open Graphics
open GMessage
open Base

class text ?center:(center = false) content coord =
  object (self)
    inherit SLAC.acomponent coord (0, 0) as super (* No hitbox *)

    val mutable content = content

    method change_content (cont : string list) : unit =
      content <- cont

    method! getStrings () =
      let padding = 10 in
      let coord = (padding, padding) in
      let cont = construct_string_content ~center:center coord 30 content in
      [cont]

    method subClick c =
      Nothing
  end
