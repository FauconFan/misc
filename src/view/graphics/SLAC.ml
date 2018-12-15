
open Base
open Graphics

exception Wrong_Construct of string


class scene (layers_array : layer array) =
  object (self)

    method draw config : unit =
      Array.iter (fun lay -> lay#draw config) layers_array

    method click config c : (scene GMessage.t) list =
      let layers_messages = Array.map (fun lay -> (lay#click config c)) layers_array in
      List.flatten @@ Array.to_list layers_messages
  end

and layer (list_compo : acomponent list) =
  object (self)

    method draw config =
      List.iter (fun comp -> comp#draw config) list_compo

    method click config c =
      List.map (fun comp -> comp#click config c) list_compo
  end

and virtual acomponent (posx, posy) dim =
  object (self)

    val interline = 2

    method draw (config : config) : unit =
      let f_zoom x max1 max2 = (* x / max1 = x' / max2 *)
        let (x, max1, max2) = (float_of_int x, float_of_int max1, float_of_int max2) in
        int_of_float (x *. max2 /. max1)
      in
      let f_zoom_width x =
        f_zoom x (fst config.dims) (size_x ())
      in
      let f_zoom_height y =
        f_zoom y (snd config.dims) (size_y ())
      in
      let (fzw, fzh) = (f_zoom_width, f_zoom_height) in
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
      |> List.map (fun ((x, y), (w, h), c) -> ((fzw x, fzh y), (fzw w, fzh h), c))
      |> List.iter d_rect;
      lines
      |> List.map (fun ((x1, y1), (x2, y2), c, w) -> ((x1 + posx, y1 + posy), (x2 + posx, y2 + posy), c, w))
      |> List.map (fun ((x1, y1), (x2, y2), c, w) -> ((fzw x1, fzh y1), (fzw x2, fzh y2), c, w))
      |> List.iter d_line;
      strings
      |> List.map (fun s_con -> {s_con with coordinate = (fst s_con.coordinate + posx, snd s_con.coordinate + posy)})
      |> List.map (fun s_con -> {s_con with coordinate = (fzw (fst s_con.coordinate), fzh (snd s_con.coordinate))})
      |> List.iter d_string;

    method click (config : config) ((x, y), c) : (scene GMessage.t) =
      let f_zoom x max1 max2 = (* x / max1 = x' / max2 *)
        let (x, max1, max2) = (float_of_int x, float_of_int max1, float_of_int max2) in
        int_of_float (x *. max1 /. max2)
      in
      let f_zoom_width x =
        f_zoom x (fst config.dims) (size_x ())
      in
      let f_zoom_height y =
        f_zoom y (snd config.dims) (size_y ())
      in
      let (fzw, fzh) = (f_zoom_width, f_zoom_height) in
      let (x, y) = (fzw x, fzh y) in
      let new_d = (x - posx, y - posy) in
      if bounds new_d dim then self#subClick (new_d, c)
      else Nothing

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> scene GMessage.t
  end
