
let pack li = match li with
	| []			-> []
	| head :: tail	->
		let rec rev_tail_recu li res = match li with
			| []				-> res
			| head :: tail		-> rev_tail_recu tail (head :: res)
		in
		let rec rec_pack_tail li cand actu_res res = match li with
			| []			-> actu_res :: res
			| head :: tail	-> if cand = head then rec_pack_tail tail head (head :: actu_res) res
								else rec_pack_tail tail head [head] (actu_res :: res)
		in
		rev_tail_recu (rec_pack_tail tail head [head] []) []

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [[2]]) in
	let l3 = (true, "PairSame", [2; 2], [[2; 2]]) in
	let l4 = (true, "PairDiff", [2; 3], [[2]; [3]]) in
	let l5 = (false, "PairDiffFail", [2; 3], [[3]; [2]]) in
	let l6 = (true, "Ex", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [[1; 1; 1; 1]; [2]; [3; 3]; [1; 1]; [4; 4];
 [5; 5; 5; 5]]) in
	let l7 = (false, "ExFail", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [[1; 1; 1]; [2]; [3; 3]; [1; 1]; [4; 4];
[5; 5; 5; 5]]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((pack l = exp) = b)
	in

	TestManager.startChallenge "09 - pack";
	List.iter apply l;
	TestManager.endChallenge ()
