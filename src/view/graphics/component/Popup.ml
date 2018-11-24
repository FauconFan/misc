open Base
open Graphics
open GMessage

class popup content button dim coord =
  object (self)
    inherit SLAC.acomponent coord as super

    method draw () : unit =
      super#draw();
      self#draw_string ()

    method getLines () : (coords * coords * color * int) list =
      let buttons = List.fold_left (fun a b -> a @ (b#getLines())) [] button in
      List.map (fun ((cx, cy), d, col, w) -> ((fst coord + cx, snd coord + cy), d, col, w)) buttons

    method getRects () : (coords * dim * color) list =
      let buttons = List.fold_left (fun a b -> a @ (b#getRects())) [] button in
      let changed_buttons = List.map (fun ((cx, cy), d, col) -> ((fst coord + cx, snd coord + cy), d, col)) buttons in
      let gray = rgb 105 109 110 in
      let beige = rgb 247 226 156 in
      let padding = 2 in
      let contour = (coord, dim, gray) in
      let content = ((fst coord + padding, snd coord + padding), (fst dim - (padding * 2), snd dim - (padding * 2)), beige) in
      contour :: content :: changed_buttons

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

    method private draw_string () =
      let padding = 2 in
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--50-*-*-*-*-*-iso8859-1";
      let (x, y) = (fst coord + padding, snd coord + snd dim - padding) in
      moveto x y;
      draw_string content;
      moveto cur_x cur_y

  end