
open Base

let () =
  let config = CLIParser.cliparse () in

  Random.self_init ();

  try 
    GraphicsManager.init config (CampingScene.menu config config);
    GraphicsManager.run ();
  with Graphics.Graphic_failure _ -> GraphicsManager.close ();
    GraphicsManager.close ()
