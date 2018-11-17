
open Graphics
open Base

let fps_objective = 60.

let defaultScene =
  let frame = new Frame.frame in
  let layer = new Layer.layer [frame] in
  new Scene.scene [| layer |]

let scene = ref None

let init (config : config) : unit =
  let (w, h) = config.dims in
  open_graph (" " ^ (string_of_int w) ^ "x" ^ (string_of_int h));
  set_window_title "PF5_mondrian";
  auto_synchronize false;
  scene := Some defaultScene

let close () : unit =
  close_graph ();
  scene := None

let run () : unit =
  let running = ref true in
  let fps = ref 0 in
  let second = ref @@ Unix.gettimeofday () in
  while !running do
    let begin_turn = Unix.gettimeofday () in
    clear_graph ();
    !scene
    |> Option.may (fun a -> a#draw);
    synchronize ();
    let end_turn = Unix.gettimeofday () in
    let ecart = end_turn -. begin_turn in
    Unix.sleepf ((1. /. fps_objective) -. ecart);
    incr fps;
    if Unix.gettimeofday () -. !second >= 1. then
      begin
        print_endline @@ Printf.sprintf "FPS : %d" !fps;
        fps := 0;
        second := !second +. 1.;
      end
  done
