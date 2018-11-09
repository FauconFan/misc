
open Graphics
open Base

let init (dim:dim) : unit =
  let (w, h) = dim in
  open_graph (" " ^ (string_of_int w) ^ "x" ^ (string_of_int h));
  set_window_title "PF5_mondrian"

let close () : unit =
  close_graph ()

let draw_rect (_:bsp) : bsp = failwith "TODO"

let interact () : coords * color option = failwith "TODO"

let draw_current_bsp config _ _ : unit =
  let (wm, hm) = config.dims in

  init config.dims;

  set_color red;
  set_line_width 5;
  moveto 0 (hm / 2);
  lineto wm (hm / 2);

  ignore (wait_next_event [Button_down]);

  close ();
