
let encode li = match li with
	| []			-> []
	| head :: tail	->
		let rec rev_tail_recu li res = match li with
			| []				-> res
			| head :: tail		-> rev_tail_recu tail (head :: res)
		in
		let rec rec_encode_tail li cand size res = match li with
			| []			-> (size, cand) :: res
			| head :: tail	-> if cand = head then rec_encode_tail tail head (size + 1) res
								else rec_encode_tail tail head 1 ((size, cand) :: res)
		in
		rev_tail_recu (rec_encode_tail tail head 1 []) []

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [(1, 2)]) in
	let l3 = (true, "PairSame", [2; 2], [(2, 2)]) in
	let l4 = (true, "PairDiff", [2; 3], [(1, 2); (1, 3)]) in
	let l5 = (false, "PairDiffFail", [2; 3], [(1, 3); (1, 2)]) in
	let l6 = (true, "Ex", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [(4, 1); (1, 2); (2, 3); (2, 1); (2, 4);
 (4, 5)]) in
	let l7 = (false, "ExFail", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [(3, 1); (1, 2); (2, 3); (2, 1); (2, 4);
 (4, 5)]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((encode l = exp) = b)
	in

	TestManager.changeTitle "10 - encode";
	List.iter apply l
