
let compress li = match li with
	| []				->	[]
	| head :: tail		->
		begin
			let rec rec_compress li cand res = match li with
				| []			-> res
				| head :: tail	->
					if head = cand then rec_compress tail cand res
					else rec_compress tail head (head :: res)
			in
			let rec rev_tail_recu li res = match li with
				| []				-> res
				| head :: tail		-> rev_tail_recu tail (head :: res)
			in rev_tail_recu (rec_compress tail head [head]) []
		end

let test () =
	let f = (fun i -> i / 4) in
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [2]) in
	let l3 = (true, "L1", (List.init 8 f), [0; 1]) in
	let l4 = (true, "L2", (List.init 16 f), [0; 1; 2; 3]) in
	let l5 = (true, "L3", (List.init 9 f), [0; 1; 2]) in
	let l6 = (true, "L4", (List.init 25 f), [0; 1; 2; 3; 4; 5; 6]) in
	let l7 = (false, "L4Fail", (List.init 25 f), [0; 1; 2; 3; 4; 6]) in
	let l8 = (true, "L5", (List.init 1000 f), (List.init 250 (fun i -> i))) in
	let l9 = (true, "Ex", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 5; 5; 5; 5], [1; 2; 3; 1; 4; 5]) in
	let l10 = (false, "ExFail", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 5; 5; 5; 5], [1; 2; 3; 1; 5]) in
	let l = [l1; l2; l3; l4; l5; l6; l7; l8; l9; l10] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((compress l = exp) = b)
	in

	TestManager.startChallenge "08 - compress";
	List.iter apply l;
	TestManager.endChallenge ()
