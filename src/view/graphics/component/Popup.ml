open Base
open Graphics
open GMessage

class popup content button dim coord =
  object (self)
    inherit SLAC.acomponent coord as super

    method getLines () : (coords * coords * color * int) list =
      List.fold_left (fun a b -> a @  (b#getLines())) [] button

    method getRects () : (coords * dim * color) list =
      let buttons = List.fold_left (fun a b -> a @ (b#getRects())) [] button in
      let gray = rgb 105 109 110 in
      let beige = rgb 245 246 245 in
      let padding = 2 in
      let contour = ((0,0), dim, gray) in
      let content = ((padding, padding), (fst dim - (padding * 2), snd dim - (padding * 2)), beige) in
      contour :: content :: buttons

    method subClick ((coords, color) as click) : (SLAC.scene GMessage.t) =
      let rec aux l =
        match l with
        | [] -> Nothing
        | h :: q -> 
          let message = h#subClick click in
          if message = Nothing then aux q
          else message
      in
      aux button

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
      let buttons_str = List.fold_left (fun a b -> a @ (b#getStrings())) [] button in
      let font = "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1" in
      let cont = construct_string_content (padding, snd dim) black font 30 content in
      cont :: buttons_str
        
    
    (*method private draw_string () =
      let padding = 10 in
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1";
      let dim_str = text_size content in
      let (x, y) = (fst coord + padding, snd coord + snd dim - padding - (snd dim_str)) in
      moveto x y;
      draw_string content;
      moveto cur_x cur_y*)

  end