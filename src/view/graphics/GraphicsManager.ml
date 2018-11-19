
open Graphics
open Base

let fps_objective = 60.

let scene = ref None

let init (config : config) : unit =
  let (w, h) = config.dims in
  let (wr, hr) = (w + (w / 2), h + (h / 2)) in
  open_graph (" " ^ (string_of_int wr) ^ "x" ^ (string_of_int hr));
  set_window_title "PF5_mondrian";
  auto_synchronize false;
  scene := Some (CampingScene.defaultScene config)

let close () : unit =
  close_graph ();
  scene := None

let run () : unit =
  let running = ref true in
  let fps = ref 0 in
  let second = ref @@ Unix.gettimeofday () in
  let core () =
    try
      begin
        let event = Interact.interact () in
        Option.may2 (fun s e -> s#click e) !scene event;
        Option.may (fun s -> s#draw ()) !scene;
      end
    with Exit -> running := false
  in
  while !running do
    let begin_turn = Unix.gettimeofday () in
    clear_graph ();
    core ();
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
