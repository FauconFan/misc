
open Base

let rec random_bsp_empty depth (min_width, max_width) (min_height, max_height) even : bsp =
  if depth == 0 then R None
  else if even then
    begin
      let coord = Random.int (max_width - min_width) + min_width in
      let label = {coord = coord; colored = false} in
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
      let label = {coord = coord; colored = false} in
      let d_left = (min_height, coord)
      and d_right = (coord, max_height)
      and d_width = (min_width, max_width) in
      let left = random_bsp_empty (depth - 1) d_width d_left (not even)
      and right = random_bsp_empty (depth - 1) d_width d_right (not even) in
      L (label, left, right)
    end

let random_bsp_colored (_:bsp) : bsp = failwith "TODO"

let random_bsp_naive config =
  let (weight, height) = config.dims in
  let (width_d, height_d) = (0, weight), (0, height) in
  random_bsp_empty config.depth width_d height_d false
