
open Base

let check_current (bsp : bsp) =
  let rec aux bsp even =
    match bsp with
    | R _ -> true
    | L (lab, bsp_g, bsp_d) ->
      if((aux bsp_g (not even)) = false || aux bsp_d (not even))
        then false
      else maybe (fun c -> (color_of_line bsp_g bsp_d even) = Some(c)) lab.color true
  in aux bsp false