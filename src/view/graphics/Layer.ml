
class layer (list_compo : AComponent.acomponent list) =
  object (self)
    method private get_components =
      list_compo

    method draw =
      List.iter (fun comp -> comp#draw) self#get_components
  end
