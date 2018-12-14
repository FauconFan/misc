open Graphics
open GMessage
open Base

class text content coord =
  object (self)
    inherit SLAC.acomponent coord (0, 0) as super (* No hitbox *)

    method getLines () : (coords * coords * color * int) list =
      []

    method getRects () : (coords * dim * color) list =
      []

    method subClick c =
      Nothing

    method getStrings () =
      let construct_string_content coord c font s content =
        {
          coordinate = coord;
          color = c;
          font = font;
          size = s;
          content = content;
        }
      in
      let padding = 10 in
      let font = "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1" in
      let apply_tuple (a,b) f = (f a, f b) in
      let coord = apply_tuple coord (fun a -> padding) in
      let cont = construct_string_content coord black font 30 content in
      [cont]
  end
