
class scene (layers_array : Layer.layer array) =
  object (self)
    method draw () : unit =
      Array.iter (fun lay -> lay#draw ()) layers_array

    method click c : unit =
      Array.iter (fun lay -> lay#click c) layers_array
  end
