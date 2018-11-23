

let defaultScene config =
  let frame = new FrameBSP.frameBSP config (0, 0) in
  let layer = new SLAC.layer [frame] in
  new SLAC.scene [| layer |]
