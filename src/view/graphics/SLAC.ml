
open Base
open Graphics

exception Wrong_Construct of string


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

and virtual acomponent (posx, posy) dim =
  object (self)

    val interline = 2

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
      let d_string { coordinate = (coordx, coordy); color = c; font = font; size = s; content = content} =
        set_color c;
        set_font font;
        set_text_size s;
        List.iteri (fun i a ->
        moveto coordx (coordy - (i + 1) * ((snd (text_size a)) + if(i = 0) then 0 else interline));
        draw_string a) content
      in
      let rects = self#getRects ()
      and lines = self#getLines ()
      and strings = self#getStrings ()
      in
      rects
      |> List.map (fun ((x, y), (w, h), c) -> ((x + posx, y + posy), (w, h), c))
      |> List.iter d_rect;
      lines
      |> List.map (fun ((x1, y1), (x2, y2), c, w) -> ((x1 + posx, y1 + posy), (x2 + posx, y2 + posy), c, w))
      |> List.iter d_line;
      strings
      |> List.map (fun s_con -> {s_con with coordinate = (fst s_con.coordinate + posx, snd s_con.coordinate + posy)})
      |> List.iter d_string;

    method click ((x, y), c) : (scene GMessage.t) =
      let new_d = (x - posx, y - posy) in
      if bounds new_d dim then self#subClick (new_d, c)
      else Nothing

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> scene GMessage.t
  end
