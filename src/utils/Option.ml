(*
  Exception soulevée à l'appel de get None.
*)
exception No_value

(*
  On applique f à x si x est différent de None, sinon on ne fait rien
*)
let may f x = match x with
  | None -> ()
  | Some v -> f v

(*
  On applique f à x et y  si x et y sont différents de None, sinon on ne fait rien
*)
let may2 f x y = match x with
  | None -> ()
  | Some vx ->
    begin
      match y with
      | None -> ()
      | Some vy -> f vx vy
    end

(*
  Si x est None, on retourne None, sinon on retourne Some (f x)
*)
let map f x = match x with
  | None -> None
  | Some v -> Some (f v)

(*
  Si x est None, on retourne a, sinon on retourne la valeur de x (on retourne v pour x = Some(v))
*)
let default a x = match x with
  | None -> a
  | Some v -> v

(*
  map_default f x (Some v) retourne f v et map_default f x None retourne x.
*)
let map_default f a x = match x with
  | None -> a
  | Some v -> f v

(*
  map2_default f x (Some v) (Some w) retourne f v w et retourne x autrement..
*)
let map2_default f a x y = match x with
  | None -> a
  | Some vx ->
    begin
      match y with
      | None -> a
      | Some vy -> f vx vy
    end

(*
  is_none None retourne true sinon il retourne false.
*)
let is_none x = match x with
  | None -> true
  | Some _ -> false

(*
  is_some (Some x) retourne true sinon il retourne false.
*)
let is_some x = match x with
  | None -> false
  | Some _ -> true

(*
  get (Some x) retourne x et get None soulève l'exception No_value.
*)
let get x = match x with
  | None -> raise No_value
  | Some v -> v

(*
  equal None None f returns true, equal (Some x) (Some y) f returns f x y, false otherwise
*)
let equal cx cy eq = match (cx, cy) with
  | (Some x, Some y) -> eq x y
  | (None, None) -> true
  | _ -> false
