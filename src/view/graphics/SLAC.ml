
open Base
open Graphics

exception Wrong_Construct of string

let minRatio = 0.5
let maxRatio = 2.

let getRatios config : float * float =
  let ratW = (float_of_int (size_x ())) /. (float_of_int (fst config.dims))
  and ratH = (float_of_int (size_y ())) /. (float_of_int (snd config.dims)) in
  let minS = Pervasives.min ratW ratH
  and maxS = Pervasives.max ratW ratH
  in
  (minS, maxS)

let isCritical config : bool * bool =
  let (minS, maxS) = getRatios config in
  (minS < minRatio, maxS > maxRatio)

let getMinRatio config =
  fst @@ getRatios config

let getMaxRatio config =
  snd @@ getRatios config

class scene (layers_array : layer array) =
  object (self)

    method draw config : unit =
      let draw_problem str =
        let (dimx, dimy) = (Graphics.size_x (), Graphics.size_y ()) in
        moveto (dimx / 2-20) (dimy / 2);
        draw_string str
      in
      match isCritical config with
      | (true, _) -> draw_problem "Too small"
      | (_, true) ->  draw_problem "Too big"
      | (false, false) -> Array.iter (fun lay -> lay#draw config) layers_array

    method click config c : (scene GMessage.t) list =
      match isCritical config with
      | (false, false) ->
        begin
          let layers_messages = Array.map (fun lay -> (lay#click config c)) layers_array in
          List.flatten @@ Array.to_list layers_messages
        end
      | (_, _) -> []
  end

and layer (list_compo : acomponent list) =
  object (self)

    method draw config =
      List.iter (fun comp -> comp#draw config) list_compo

    method click config c =
      List.rev_map (fun comp -> comp#click config c) list_compo
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
      let d_string { coordinate = (coordx, coordy); color = c; size = s; center = y; content = content} =
        let s = int_of_float @@ ((float_of_int s) *. (getMinRatio config)) in
        set_color c;
        set_font (construct_font s);
        List.iteri (fun i a ->
            let coordy = (coordy - (i + 1) * ((snd (text_size a)) + if (i = 0) then 0 else interline)) in
            let coordx = if y then (coordx - (fst (text_size a)) / 2) else coordx in
            moveto coordx coordy;
            draw_string a) content
      in
      let rects = self#getRects ()
      and lines = self#getLines ()
      and strings = self#getStrings ()
      in
      rects
      |> List.rev_map (fun ((x, y), (w, h), c) -> ((x + posx, y + posy), (w, h), c))
      |> List.rev_map (fun ((x, y), (w, h), c) -> ((fzw x, fzh y), (fzw w, fzh h), c))
      |> List.iter d_rect;
      lines
      |> List.rev_map (fun ((x1, y1), (x2, y2), c, w) -> ((x1 + posx, y1 + posy), (x2 + posx, y2 + posy), c, w))
      |> List.rev_map (fun ((x1, y1), (x2, y2), c, w) -> ((fzw x1, fzh y1), (fzw x2, fzh y2), c, w))
      |> List.iter d_line;
      strings
      |> List.rev_map (fun s_con -> {s_con with coordinate = (fst s_con.coordinate + posx, snd s_con.coordinate + posy)})
      |> List.rev_map (fun s_con -> {s_con with coordinate = (fzw (fst s_con.coordinate), fzh (snd s_con.coordinate))})
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
