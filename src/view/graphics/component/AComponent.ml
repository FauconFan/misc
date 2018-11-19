
open Base
open Graphics

class virtual acomponent posx posy =
  object (self)
    method draw () : unit =
      let d_rect ((x, y), (w, h), c) =
        set_color c;
        fill_rect x y w h
      in
      let d_line ((x1, y1), (x2, y2), c, w) =
        set_color c;
        set_line_width w;
        moveto x1 y1;
        lineto x2 y2;
      in
      let rects = self#getRects ()
      and lines = self#getLines ()
      in
      rects
      |> List.map (fun ((x, y), (w, h), c) -> ((x + posx, y + posy), (w, h), c))
      |> List.iter d_rect;
      lines
      |> List.map (fun ((x1, y1), (x2, y2), c, w) -> ((x1 + posx, y1 + posy), (x2 + posx, y2 + posy), c, w))
      |> List.iter d_line;

    method click ((x, y), c) =
      self#subClick ((x - posx, y - posy), c)

    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> unit
  end
