
open Base
open Graphics

let rec random_bsp_empty depth (min_width, max_width) (min_height, max_height) even : bsp =
  if depth == 0 then R None
  else if even then
    begin
      let coord = Random.int (max_width - min_width) + min_width in
      let label = {coord = coord; color = None} in
      let d_left = (min_width, coord)
      and d_right = (coord, max_width)
      and d_height = (min_height, max_height) in
      let left = random_bsp_empty (depth - 1) d_left d_height (not even)
      and right = random_bsp_empty (depth - 1) d_right d_height (not even) in
      L (label, left, right)
    end
  else
    begin
      let coord = Random.int (max_height - min_height) + min_height in
      let label = {coord = coord; color = None} in
      let d_left = (min_height, coord)
      and d_right = (coord, max_height)
      and d_width = (min_width, max_width) in
      let left = random_bsp_empty (depth - 1) d_width d_left (not even)
      and right = random_bsp_empty (depth - 1) d_width d_right (not even) in
      L (label, left, right)
    end

(**
  On renvoie la couleur correspondant à la différence entre i et j :
  - i > j : blue
  - i < j : red
  - i = j : magenta
*)
let get_max_color i j =
  if i > j then blue
  else if i < j then red
  else magenta

(**
   Renvoie la couleur d'une ligne en fonction de :
   - ses bsp fils
   - ligne verticale (even = false) ou horizontale (even = true)
*)
let color_of_line bsp_g bsp_d even =
  let rec aux color bsp l =
    match bsp with
    | R c -> maybe (fun c -> if c = blue then color.(0) <- color.(0) + 1 else color.(1) <- color.(1) + 1) c ()
    | L (_, bsp_g, bsp_d) ->
      if (even && l) then aux color bsp_g (not l)
      else if even = (not l) then (aux color bsp_g (not l); aux color bsp_d (not l))
      else aux color bsp_d (not l)
  in
  let tab = [|0;0|] in
  aux tab bsp_g (not even);
  aux tab bsp_d (not even);
  get_max_color (tab.(0)) (tab.(1))

let random_bsp_colored (bsp:bsp) : bsp =
  let colors = Interact.getAllColors () in
  let len_colors = List.length colors in
  let rec fill_color bsp = match bsp with
    | R _ -> R (Some (List.nth colors (Random.int len_colors)))
    | L (la, l, r) -> L (la, (fill_color l), (fill_color r))
  in
  let rec hide_color bsp = match bsp with
    | R _ -> R None
    | L (la, l, r) -> L (la, (hide_color l), (hide_color r))
  in
  let rec fill_lines_color bsp even = match bsp with
    | R _ -> bsp
    | L (lab, l, r) ->
      begin
        let new_color =
          if Random.bool () then Some (Translate.color_of_line l r even)
          else None
        in
        let new_lab = {lab with color = new_color} in
        L (new_lab, (fill_lines_color l (not even)), (fill_lines_color r (not even)))
      end
  in
  let bsp = fill_color bsp in
  let bsp = fill_lines_color bsp false in
  let bsp = hide_color bsp in
  bsp

let random_bsp_naive config : bsp =
  let (weight, height) = config.dims in
  let (width_d, height_d) = (0, weight), (0, height) in
  let res = random_bsp_empty config.depth width_d height_d false in
  random_bsp_colored res
