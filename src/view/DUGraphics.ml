
open Graphics
open Base

let init (dim:dim) : unit =
  let (w, h) = dim in
  open_graph (" " ^ (string_of_int w) ^ "x" ^ (string_of_int h));
  set_window_title "PF5_mondrian";
  auto_synchronize false

let close () : unit =
  close_graph ()

let draw_rect (_:bsp) : bsp = failwith "TODO"

let interact () : coords * color option =
  let table = [('r', red); ('b', blue)] in
  let findtable ch =
    begin
      let f = List.find_opt (fun (c, _) -> c == ch) table in
      match f with
      | None -> None
      | Some tuple -> Some (snd tuple)
    end
  in
  let ch = read_key () in
  ((mouse_pos ()), findtable ch)

let draw_current_bsp config _ _ : unit =
  let (wm, hm) = config.dims in

  init config.dims;

  set_color red;
  set_line_width 5;
  moveto 0 (hm / 2);
  lineto wm (hm / 2);

  synchronize ();
  ignore (wait_next_event [Button_down]);

  close ();
