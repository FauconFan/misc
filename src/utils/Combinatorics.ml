

let rec shift p v i =
  if i < Array.length p then begin
    p.(i) <- v; shift p (v + 1) (i + 1) end

let rec moveLast (p : int array) (s : int) (i : int) =
  let size_p = Array.length p in
  if i < 0 then false
  else if p.(i) >= (s - 1) then moveLast p s (i-1)
  else if i >= (size_p - 1) then begin p.(i) <- p.(i) + 1; true end
  else if p.(i + 1) = p.(i) + 1 then moveLast p s (i - 1)
  else begin shift p (p.(i) + 1) i; true end

let add_sol ens p res =
  let list_init n f =
    let rec add_el i l =
      if(i < 0 || i >= n) then l
      else add_el (i-1) ((f i) :: l)
    in
    add_el (n-1) []
  in
  res := (list_init (Array.length p) (fun a -> ens.(p.(a)))) :: (!res)

let k_combinaison k ens =
  let ens = Array.of_list ens in
  let n = Array.length ens in
  if k <= 0 || k > n  then []
  else
    let res = ref [] in
    let p = Array.init k (fun a -> a) in
    let rec aux () =
      begin
        add_sol ens p res;
        if(moveLast p (Array.length ens) (Array.length p - 1)) then aux ()
        else !res
      end
    in
    aux ()
