
open Graphics
open GMessage
open Base

let fps_objective = 60.

let scene = ref None
let config = ref None

let init (conf : config) (sce : SLAC.scene) : unit =
  let (w, h) = conf.dims in
  let (wr, hr) = (w, h) in
  open_graph (" " ^ (string_of_int wr) ^ "x" ^ (string_of_int hr));
  set_window_title "PF5_mondrian";
  auto_synchronize false;
  scene := Some sce;
  config := Some conf

let changeConfig (conf : config) : unit =
  config := Some conf

let close () : unit =
  close_graph ();
  scene := None

let changeScene (sce : SLAC.scene) =
  scene := Some sce;
  let (w, h) = (Option.get !config).dims in
  resize_window w h

let run () : unit =
  let running = ref true in
  let fps = ref 0 in
  let second = ref @@ Unix.gettimeofday () in
  let core () =
    try
      begin
        let use_gmsg gmsg = match gmsg with
          | Nothing -> ()
          | Apply f -> f (Option.get !scene)
          | Update f -> changeScene (f ())
        in
        let event = Interact.interact () in
        let li_gmsg = Option.map2_default (fun s e -> s#click e) [] !scene event in
        List.iter use_gmsg li_gmsg;
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
