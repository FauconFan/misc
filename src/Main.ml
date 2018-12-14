
open Base

let () =
  let config = CLIParser.cliparse () in

  Random.self_init ();
  GraphicsManager.init config (CampingScene.menu config);
  GraphicsManager.run ();
  GraphicsManager.close ()
