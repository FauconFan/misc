
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

(* Copied from Challenge 56 *)

let rec is_mirror t1 t2 = match (t1, t2) with
	| (Empty, Empty)							-> true
	| (Node (_, tl1, tr1), Node (_, tl2, tr2))	->
			is_mirror tl1 tr2 && is_mirror tr1 tl2
	| _											-> false

let is_symmetric t = match t with
	| Empty				-> true
	| Node (_, l, r)	-> is_mirror l r

(* Content *)

let rec list_foldl f i li = match li with
	| []			-> i
	| head :: tail	-> list_foldl f (f i head) tail

let construct li =
	let rec build t elem = match t with
		| Empty				-> Node (elem, Empty, Empty)
		| Node (h, l, r)	->
			begin
				if h < elem then Node (h, build l elem, r)
				else Node (h, l, build r elem)
			end in
	list_foldl build Empty li

let test () =
	TestManager.startChallenge "57 - construct";
	TestManager.doTest "e1" (is_symmetric(construct [5;3;18;1;4;12;21]));
	TestManager.doTest "e2" (not(is_symmetric(construct [3;2;5;7;4])));
	TestManager.endChallenge ()
