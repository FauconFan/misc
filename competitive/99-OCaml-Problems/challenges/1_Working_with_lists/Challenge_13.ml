
type 'a rle =
    | One of 'a
    | Many of int * 'a

let encode li = match li with
	| []			-> []
	| head :: tail	->
		let rec rev_tail_recu li res = match li with
			| []				-> res
			| head :: tail		-> rev_tail_recu tail (head :: res)
		in
		let build_elem size cand =
			if size <= 1 then One cand
			else Many (size, cand)
		in
		let rec rec_encode_tail li cand size res = match li with
			| []			-> (build_elem size cand) :: res
			| head :: tail	-> if cand = head then rec_encode_tail tail head (size + 1) res (* Counting here *)
								else rec_encode_tail tail head 1 ((build_elem size cand) :: res)
		in
		rev_tail_recu (rec_encode_tail tail head 1 []) []

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [One 2]) in
	let l3 = (true, "PairSame", [2; 2], [Many (2, 2)]) in
	let l4 = (true, "PairDiff", [2; 3], [One 2; One 3]) in
	let l5 = (false, "PairDiffFail", [2; 3], [One 3; One 2]) in
	let l6 = (true, "Ex", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [Many (4, 1); One 2; Many (2, 3); Many (2, 1); Many (2, 4);
 Many (4, 5)]) in
	let l7 = (false, "ExFail", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [Many (3, 1); One 2; Many (2, 3); Many (2, 1); Many (2, 4);
 Many (4, 5)]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((encode l = exp) = b)
	in

	TestManager.startChallenge "13 - encode (modified) directly";
	List.iter apply l;
	TestManager.endChallenge ()
