
open Base
open Graphics

(**
   Génére un bsp random de profondeur depth où seuls les coordonnées sont définis.7
   Les couleurs sont à None pour les rectangles et pour les lignes.
   *)

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
   Prend un bsp et renvoie le même bsp avec les couleurs des lignes, quand il y en a.
   *)
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
          if Random.bool () then color_of_line l r even
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

(**
   Génére un bsp naïvement, où il peut y avoir plusieurs solutions.
   *)
let random_bsp_naive config : bsp =
  let (weight, height) = config.dims in
  let (width_d, height_d) = (0, weight), (0, height) in
  let res = random_bsp_empty config.depth width_d height_d false in
  random_bsp_colored res
