
exception No_value

let may f x = match x with
  | None -> ()
  | Some v -> f v

let map f x = match x with
  | None -> None
  | Some v -> Some (f v)

let default a x = match x with
  | None -> a
  | Some v -> v

let map_default f a x = match x with
  | None -> a
  | Some v -> f v

let is_none x = match x with
  | None -> true
  | Some _ -> false

let is_some x = match x with
  | None -> false
  | Some _ -> true

let get x = match x with
  | None -> raise No_value
  | Some v -> v
