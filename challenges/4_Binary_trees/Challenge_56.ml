
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec is_mirror t1 t2 = match (t1, t2) with
	| (Empty, Empty)							-> true
	| (Node (_, tl1, tr1), Node (_, tl2, tr2))	->
			is_mirror tl1 tr2 && is_mirror tr1 tl2
	| _											-> false

let is_symmetric t = match t with
	| Empty				-> true
	| Node (_, l, r)	-> is_mirror l r

let test () =
	let t1 = Empty in
	let t2 = Node ('x', Empty, Empty) in
	let t3 = Node ('s', t2, t2) in
	let t4 = Node ('f', Node ('j', t2, Empty), Node ('k', Empty, t2)) in
	TestManager.startChallenge "56 - is_symmetric";
	TestManager.doTest "Empty" (is_symmetric t1);
	TestManager.doTest "Simple" (is_symmetric t2);
	TestManager.doTest "2height" (is_symmetric t3);
	TestManager.doTest "octopus" (is_symmetric t4);
	TestManager.endChallenge ()
