
open Base
open Graphics

let check_current (bsp : bsp) =
  let rec aux bsp even =
    match bsp with
    | R c -> Option.is_some c
    | L (lab, bsp_g, bsp_d) ->
      if (not (aux bsp_g (not even)) || not (aux bsp_d (not even)))
      then false
      else Option.map_default (fun c -> (Bsp.color_of_line bsp_g bsp_d even) = c) true lab.color
  in aux bsp ModelConstant.first_line_vertical

module LittSolver = Sat_solver.Make(String)

let check_solve (bsp : bsp) : bool =
  try
    let fnc = FNC.bsp_to_fnc bsp in
    let res = Option.is_some (LittSolver.solve fnc) in
    res
  with FNC.Unsat -> false

let solve (bsp : bsp) : bsp option =
  try
    let fnc = FNC.bsp_to_fnc bsp in
    let fnd_opt = LittSolver.solve fnc in
    let apply_to_fnd (litt_list : (bool * string) list) =
      let litt_list =
        litt_list
        |> List.sort (fun (_, str1) (_, str2) -> Pervasives.compare str1 str2)
        |> List.rev_map (fun (b, _) -> if b then red else blue)
        |> List.rev
      in
      let rec parcours_prefix bsp litt_list = match bsp with
        | R _ ->
          begin
            let r = R (Some (List.hd litt_list)) in
            (r, List.tl litt_list)
          end
        | L (label, l, r) ->
          begin
            let (l, litt_list) = parcours_prefix l litt_list in
            let (r, litt_list) = parcours_prefix r litt_list in
            (L (label, l, r), litt_list)
          end
      in
      let (bsp, _) = parcours_prefix bsp litt_list in
      bsp
    in
    Option.map apply_to_fnd fnd_opt
  with FNC.Unsat -> None
