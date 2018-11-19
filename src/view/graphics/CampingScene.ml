

let defaultScene config =
  let frame = new FrameBSP.frameBSP config 0 0 in
  let layer = new Layer.layer [frame] in
  new Scene.scene [| layer |]
