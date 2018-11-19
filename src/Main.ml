
open Base

let () =
  let config = CLIParser.cliparse () in

  Random.self_init ();
  GraphicsManager.init config;
  GraphicsManager.run ();
  GraphicsManager.close ()

  (* let bsp = Generation.random_bsp_naive config in

  DUGraphics.init config;
  DUGraphics.launch config bsp;
  DUGraphics.close () *)
