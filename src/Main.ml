
open Base

let () =
  let config = CLIParser.cliparse () in

  Random.self_init ();

  let bsp_random = Generation.random_bsp_naive config in

  DUGraphics.init config;
  DUGraphics.launch config bsp_random;
  DUGraphics.close ()
