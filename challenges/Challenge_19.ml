
let rotate li n =
	if n = 0 then li
	else
		let rec length li = match li with
			| []			-> 0
			| _ :: tail		-> 1 + (length tail)
		in
		let len = length li in
		if len = 0 then []
		else
			let split li n =
				let rec rev_tail_recu li res = match li with
					| []				-> res
					| head :: tail		-> rev_tail_recu tail (head :: res)
				in
				let rec rec_split le ri n =
					if n <= 0 then (le, ri)
					else match ri with
						| []				-> (le, ri)
						| head :: tail		-> rec_split (head :: le) tail (n - 1)
				in
				let buf = rec_split [] li n in
				((rev_tail_recu (fst buf) []), snd buf)
			in
			let n = (n mod len) in
			let n = if n < 0 then n + len else n in
			let (a, b) = split li n in
			b @ a


let test () =
	let l1 = (true, "Empty", 3, [], []) in
	let l2 = (true, "Singleton", 1, [2], [2]) in
	let l3 = (true, "One", 1, [1; 2; 3; 4], [2; 3; 4; 1]) in
	let l4 = (true, "Two", (-1), [1; 2; 3; 4], [4; 1; 2; 3]) in
	let l5 = (true, "Five", 2, [1; 2; 3; 4], [3; 4; 1; 2]) in
	let l = [l1; l2; l3; l4; l5] in
	let apply a = match a with
		| (b, n, arg1, l, exp) -> TestManager.doTest n ((rotate l arg1 = exp) = b)
	in

	TestManager.startChallenge "19 - rotate";
	List.iter apply l;
	TestManager.endChallenge ()
