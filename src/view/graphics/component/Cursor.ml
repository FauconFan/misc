open Base
open Graphics
open GMessage

class cursor dim min max value coord coord_str =

  object (self)
    inherit SLAC.acomponent coord dim as super

    val mutable pos = 0

    val width_cursor = fst dim

    initializer value := Pervasives.min (Pervasives.max min !value) max; pos <-  (((!value - min) * (width_cursor - 2*GraphicsConstant.space_cursor)) / (max - min)) + GraphicsConstant.space_cursor

    method private update_value () =
      min + (((pos - GraphicsConstant.space_cursor) * (max - min)) / (width_cursor - 2*GraphicsConstant.space_cursor))

    method! getLines () : (coords * coords * color * int) list =
      let line = ((GraphicsConstant.space_cursor, snd dim / 2 - 1), (width_cursor - GraphicsConstant.space_cursor, snd dim / 2 - 1), black, GraphicsConstant.widthline) in
      [line]

    method! getRects () : (coords * dim * color) list =
      let dim_rect = GraphicsConstant.dim_cursor_rect in
      let coord_rect = (pos - (fst dim_rect / 2), snd dim / 2 - 1 - (snd dim_rect / 2))  in
      let rect = (coord_rect, dim_rect, blue) in
      [rect]

    method! getStrings () =
      let cont = construct_string_content coord_str GraphicsConstant.size_str [(string_of_int !value)] in
      [cont]

    method subClick uevent : (SLAC.scene GMessage.t) =
      let coords = getUEventCoords uevent in
      pos <- Pervasives.min (Pervasives.max (fst coords) GraphicsConstant.space_cursor) (width_cursor - GraphicsConstant.space_cursor);
      value := self#update_value ();
      Nothing


  end
