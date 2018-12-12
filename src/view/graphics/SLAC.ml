
open Base
open Graphics

exception Wrong_Construct of string

let id = ref 0

class scene (layers_array : layer array) =
  object (self)

    val id_comp = incr id; !id

    method getId () = id_comp

    method draw () : unit =
      Array.iter (fun lay -> lay#draw ()) layers_array

    method click c : (scene GMessage.t) list =
      let layers_messages = Array.map (fun lay -> (lay#click c)) layers_array in
      List.flatten @@ Array.to_list layers_messages
  end

and layer (list_compo : acomponent list) =
  object (self)

    val id_comp = incr id; !id

    method getId () = id_comp

    method draw () =
      List.iter (fun comp -> comp#draw ()) list_compo

    method click c =
      List.map (fun comp -> comp#click c) list_compo
  end

and virtual acomponent (posx, posy) =
  object (self)

    val id_comp = incr id; !id

    method getId () = id_comp

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
        let interline = 2 in
        let move_coord = (List.fold_left (fun a b -> (snd (text_size b)) + a + interline) 0 content) in
        List.iteri (fun i a -> 
        moveto coordx (coordy + move_coord - i * ((snd (text_size a)) + interline));
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
      self#subClick ((x - posx, y - posy), c)

    method virtual getStrings : unit -> string_content list
    method virtual getLines : unit -> (coords * coords * color * int) list
    method virtual getRects : unit -> (coords * dim * color) list
    method virtual subClick : (coords * color option) -> scene GMessage.t
  end
