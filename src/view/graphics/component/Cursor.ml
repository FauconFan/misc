open Base
open Graphics
open GMessage

class cursor dim min max value coord coord_str =

  object (self)
    inherit SLAC.acomponent coord dim as super

    val mutable pos = 0

    val space_around = 5

    val width_cursor = fst dim

    initializer value := Pervasives.min (Pervasives.max min !value) max; pos <-  (((!value - min) * (width_cursor - 2*space_around)) / (max - min)) + space_around

    method private update_value () =
      min + (((pos - space_around) * (max - min)) / (width_cursor - 2*space_around))

    method! getLines () : (coords * coords * color * int) list =
      let line = ((space_around, snd dim / 2 - 1), (width_cursor - space_around, snd dim / 2 - 1), black, 2) in
      [line]

    method! getRects () : (coords * dim * color) list =
      let dim_rect = (6,6) in
      let coord_rect = (pos - (fst dim_rect / 2), snd dim / 2 - 1 - (snd dim_rect / 2))  in
      let rect = (coord_rect, dim_rect, blue) in
      [rect]

    method! getStrings () =
      let cont = construct_string_content coord_str 30 [(string_of_int !value)] in
      [cont]

    method subClick uevent : (SLAC.scene GMessage.t) =
      let coords = getUEventCoords uevent in
      pos <- Pervasives.min (Pervasives.max (fst coords) space_around) (width_cursor - space_around);
      value := self#update_value ();
      Nothing


  end
