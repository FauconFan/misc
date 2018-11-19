
class layer (list_compo : AComponent.acomponent list) =
  object (self)
    method draw () =
      List.iter (fun comp -> comp#draw ()) list_compo

    method click c =
      List.iter (fun comp -> comp#click c) list_compo
  end
