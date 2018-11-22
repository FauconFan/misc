
open Base
open Graphics

class scene (layers_array : layer array) =
  object (self)
    method draw () : unit =
      Array.iter (fun lay -> lay#draw ()) layers_array

    method click c : (scene GMessage.t) list =
      let layers_messages = Array.map (fun lay -> (lay#click c)) layers_array in
      List.flatten @@ Array.to_list layers_messages
  end

and layer (list_compo : acomponent list) =
  object (self)
    method draw () =
      List.iter (fun comp -> comp#draw ()) list_compo

    method click c =
      List.map (fun comp -> comp#click c) list_compo
  end

and virtual acomponent (posx, posy) =
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

    method click ((x, y), c) : (scene GMessage.t) =
      self#subClick ((x - posx, y - posy), c)

    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> scene GMessage.t
  end
