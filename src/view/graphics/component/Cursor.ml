open Base
open Graphics
open GMessage

class cursor dim min max coord =

  object (self)
  inherit SLAC.acomponent coord as super

    val mutable pos = min

    val space_cursor_text = 5

    val space_around = 5

    val mutable width_cursor = 0

    initializer set_font "-*-fixed-medium-r-semicondensed--50-*-*-*-*-*-iso8859-1";
    let dim_str = text_size (string_of_int max) in
    let res = (fst dim) - (fst dim_str) - space_cursor_text in
    if res <= 0 then raise (SLAC.Wrong_Construct "Wrong contruction of a cursor, too little dimension.")
    else width_cursor <- res


    method private get_middle () =
    (fst coord, snd coord + (snd dim / 2))

    method private draw_string () =
      let coord = self#get_middle () in
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--50-*-*-*-*-*-iso8859-1";
      let content = string_of_int (self#get_value()) in
      let dim_str = text_size content in
      let (str_x, middle_y) = (fst coord + width_cursor + space_cursor_text, snd coord - (snd dim_str / 2)) in
      moveto str_x middle_y;
      draw_string content;
      moveto cur_x cur_y
    
    method get_value () = 
      min + ((pos * (max - min)) / width_cursor)

    method! draw () : unit =
      super#draw ();
      self#draw_string ()

    method getLines () : (coords * coords * color * int) list =
      let coord = self#get_middle () in
      let line = (coord, (fst coord + width_cursor, snd coord), black, 2) in
      line :: []

    method getRects () : (coords * dim * color) list =
      let coord = self#get_middle () in
      let dim_rect = (6,6) in
      let coord_rect = (fst coord + pos - min - (fst dim_rect / 2), snd coord - (snd dim_rect / 2))  in
      let rect = (coord_rect, dim_rect, blue) in
      rect :: []

    method subClick (coords, color) : (SLAC.scene GMessage.t) =
      let coord = self#get_middle () in
      let change_mark (x1, y1) (x2, y2) = (x2-x1-space_around, y2-y1 - space_around) in
      if bounds (change_mark coord coords) (width_cursor + (space_around * 2), space_around * 2) then
        pos <- Pervasives.min (Pervasives.max (fst coords - fst coord) 0) width_cursor;
      Nothing

  end