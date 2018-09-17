
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec list_foldl f i li = match li with
	| []			-> i
	| head :: tail	-> list_foldl f (f i head) tail

let rec list_filter f li = match li with
	| []			-> []
	| head :: tail	->
		if f head then head :: (list_filter f tail)
		else list_filter f tail

let rec list_map f li = match li with
	| []			-> []
	| head :: tail	-> (f head) :: (list_map f tail)

let rec list_range n m =
	if n > m then []
	else n :: (list_range (n + 1) m)

let list_length li =
	list_foldl (fun i _ -> i + 1) 0 li

let rec cbal_tree n =
	let build_subtrees left right all =
		let build2 all l =
			list_foldl (fun a r -> Node ('x', l, r) :: a) all right in
		list_foldl build2 all left in
	if n <= 0 then [Empty]
	else if n mod 2 = 1 then
		begin
			let t = cbal_tree (n / 2) in
			build_subtrees t t []
		end
	else
		begin
			let t1 = cbal_tree (n / 2 - 1) in
			let t2 = cbal_tree (n / 2) in
			build_subtrees t1 t2 (build_subtrees t2 t1 [])
		end

let rec is_mirror t1 t2 = match (t1, t2) with
	| (Empty, Empty)							-> true
	| (Node (_, tl1, tr1), Node (_, tl2, tr2))	->
			is_mirror tl1 tr2 && is_mirror tr1 tl2
	| _											-> false

let is_symmetric t = match t with
	| Empty				-> true
	| Node (_, l, r)	-> is_mirror l r

let sym_cbal_trees n =
	list_filter is_symmetric (cbal_tree n)

let test () =
	let o5 = [Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)), Node ('x', Node ('x', Empty, Empty), Empty))] in
	let omap = [(10, 0); (11, 4); (12, 0); (13, 4); (14, 0); (15, 1); (16, 0); (17, 8); (18, 0); (19, 16); (20, 0)] in
	TestManager.startChallenge "58 - sym_cbal_trees";
	TestManager.doTest "5" (sym_cbal_trees 5 = o5);
	TestManager.doTest "len 57" (list_length (sym_cbal_trees 57) = 256);
	TestManager.doTest "10 - 20" ((list_map (fun n -> (n, list_length (sym_cbal_trees n))) (list_range 10 20)) = omap);
	TestManager.endChallenge ()
