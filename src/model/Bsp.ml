
open Base
open Graphics

(*
  Change la couleur du rectangle contenant le point coords
*)
let change_rectangle_color (coords, color) bsp =
  let construct_apply_condition bol f label bsp_g bsp_d =
    L (
      label,
      (if bol then f bsp_g else bsp_g),
      (if not bol then f bsp_d else bsp_d)
    )
  in
  let rec parcours line (x,y) bsp =
    match bsp with
    | R _ -> R color
    | L (label, bsp_g, bsp_d) ->
      construct_apply_condition
        ((if line then y else x) < label.coord)
        (parcours (not line) (x,y))
        label
        bsp_g
        bsp_d
  in parcours false coords bsp

(*
  On renvoie la couleur correspondant à la différence entre i et j :
  - i > j : blue
  - i < j : red
  - i = j : magenta
*)
let get_max_color i j =
  if i > j then blue
  else if i < j then red
  else magenta

(*
  Renvoie les stats relatifs à une ligne, sous la forme d'un tuple.
  Le premier membre du tuple est un array de taille qui contient :
  (0) -> le nombre de rectangles bleus.
  (1) -> le nombre de rectangles rouges.
  (2) -> le nombre de rectangle au total.
  Le second membre est une liste optionnelle d'identifiants et de couleurs désignant les rectangles.
  Le second membre est None si et seulement si le prefix est None.
  Sinon le second membre est de la forme [("ll", None); ("lr", Some red)]
*)
let stats_of_line
    (bsp_g : bsp) (bsp_d : bsp) (even : bool) (prefix : string option)
  : (int array * (string * color option) list option) =
  let stats = [|0; 0; 0|] in
  let list_rect = ref [] in
  let apply_on_R c stats id_rect =
    let f c =
      if c = blue then stats.(0) <- stats.(0) + 1
      else if c = red then stats.(1) <- stats.(1) + 1
    in
    Option.may f c;
    stats.(2) <- stats.(2) + 1;
    if Option.is_some id_rect then
      begin
        list_rect := (Option.get id_rect, c) :: !list_rect
      end
  in
  let rec aux stats bsp l prefix_actu =
    match bsp with
    | R c -> apply_on_R c stats prefix_actu
    | L (_, bsp_g, bsp_d) ->
      begin
        let recall is_left =
          let g_prefix_f p = p ^ "l" in
          let d_prefix_f p = p ^ "r" in
          if is_left
          then aux stats bsp_g (not l) (Option.map g_prefix_f prefix_actu)
          else aux stats bsp_d (not l) (Option.map d_prefix_f prefix_actu)
        in
        if (even && l) then recall true
        else if even = (not l) then (recall true; recall false)
        else recall false
      end
  in
  aux stats bsp_g (not even) prefix;
  aux stats bsp_d (not even) prefix;
  if Option.is_none prefix then (stats, None)
  else (stats, Some (!list_rect))

(*
   Renvoie la couleur d'une ligne en fonction de :
   - ses bsp fils
   - ligne verticale (even = false) ou horizontale (even = true)
*)
let color_of_line bsp_g bsp_d even =
  let (stats, _) = stats_of_line bsp_g bsp_d even None in
  get_max_color stats.(0) stats.(1)

let lines_from_bsp (config : config) (bsp:bsp) : (line * color option) list =
  let rec aux l even bsp max_dim min_dim =
    match bsp with
    | R _ -> l
    | L (label, bsp_g, bsp_d) ->
      begin
        let line_dim =
          if even then ((fst min_dim, label.coord), (fst max_dim, label.coord))
          else ((label.coord, snd min_dim), (label.coord, snd max_dim))
        and line_color = label.color
        in
        let line = (line_dim, line_color) in
        let dim_max_left = if even then (fst max_dim, label.coord) else (label.coord, snd max_dim) in
        let dim_min_right = if even then (fst min_dim, label.coord) else (label.coord, snd min_dim) in
        let l_left = aux (line :: l) (not even) bsp_g dim_max_left min_dim in
        aux l_left (not even) bsp_d max_dim dim_min_right
      end
  in aux [] false bsp config.dims (0,0)

let rectangles_from_bsp (config : config) (bsp : bsp) : (rect * color option) list =
  let rec aux res even bsp max_dim min_dim =
    match bsp with
    | R c -> ((min_dim, diff_dim min_dim max_dim), c) :: res
    | L (label, bsp_g, bsp_d) ->
      begin
        let dim_max_left = if even then (fst max_dim, label.coord) else (label.coord, snd max_dim) in
        let dim_min_right = if even then (fst min_dim, label.coord) else (label.coord, snd min_dim) in
        let l_left = aux res (not even) bsp_g dim_max_left min_dim in
        aux l_left (not even) bsp_d max_dim dim_min_right
      end
  in aux [] false bsp config.dims (0,0)


(* let bsp_to_prop (bsp : bsp) : FNC.prop =
   let hash_rect = Hashtbl.create 13 in
   let res = ref None in
   let add_in_res prop =
    let f prop1 prop2 = FNC.And (prop1, prop2) in
    res := Some (Option.map_default (f prop) prop !res)
   in
   let bsp_to_prop_recu bsp even =
    let core bsp_g bsp_d
    in
    bsp_to_prop_recu bsp false *)
