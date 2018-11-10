
open Base

let () =
  let config = CLIParser.cliparse () in

  DUGraphics.init config;
  DUGraphics.launch config;
  DUGraphics.close ()
