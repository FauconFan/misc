open Base
open Graphics
open GMessage

class cursor dim min max value coord coord_str =

  object (self)
  inherit SLAC.acomponent coord as super
    
    val mutable pos = 0

    val space_around = 10

    val width_cursor = fst dim

    initializer value := Pervasives.min (Pervasives.max min !value) max; pos <-  ((!value - min) * width_cursor) / (max - min)
    
    method private get_value () = 
      min + ((pos * (max - min)) / width_cursor)

    method getLines () : (coords * coords * color * int) list =
      let line = ((0,0), (width_cursor, 0), black, 2) in
      [line]

    method getRects () : (coords * dim * color) list =
      let dim_rect = (6,6) in
      let coord_rect = (pos - (fst dim_rect / 2), - (snd dim_rect / 2))  in
      let rect = (coord_rect, dim_rect, blue) in
      [rect]

    method subClick (coords, color) : (SLAC.scene GMessage.t) =
      let coords = (fst coords + space_around, snd coords + space_around) in 
      if bounds coords (width_cursor + (space_around * 2), space_around * 2) then
        begin
        pos <- Pervasives.min (Pervasives.max (fst coords - space_around) 0) width_cursor;
        value := self#get_value()
        end;
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
      let font = "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1" in
      let cont = construct_string_content coord_str black font 30 [(string_of_int !value)] in
      [cont]
      

  end