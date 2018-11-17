
class scene (layers_array : Layer.layer array) =
  object (self)
    method private get_layers =
      layers_array

    method draw : unit =
      Array.iter (fun lay -> lay#draw) self#get_layers
  end
