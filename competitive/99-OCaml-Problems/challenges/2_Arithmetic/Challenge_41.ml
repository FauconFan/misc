
let rev_list li =
	let rec core li res = match li with
		| []			-> res
		| head :: tail	-> core tail (head :: res) in
	core li []

let filter_list f li =
	let rec core f li res = match li with
		| []			-> rev_list res
		| head :: tail	->
			begin
				if f head then core f tail (head :: res)
				else core f tail res
			end in
	core f li []

let rec is_prime n =
	if n < 0 then is_prime (-n)
	else if n <= 1 then false
	else if n <= 2 then true
	else
		begin
			let rec loop n cand =
				if cand * cand > n then true
				else if n mod cand = 0 then false
				else loop n (cand + 1) in
			loop n 2
		end

let goldbach m =
	let rec loop m cand =
		if cand > m then (0, 0)
		else if is_prime cand && is_prime (m - cand) then (cand, m - cand)
		else loop m (cand + 1) in
	if m mod 2 = 1 || m <= 3 then (0, 0)
	else loop m 1

let goldbach_list n m =
	let even = if n mod 2 = 0 then n else n + 1 in
	let rec loop cand m res =
		if cand > m then rev_list res
		else loop (cand + 2) m ((cand, (goldbach cand)) :: res) in
	loop even m []

let goldbach_limit n m b =
	let li = goldbach_list n m in
	filter_list (fun (_, (x, y)) -> x > b && y > b) li

let test () =
	TestManager.startChallenge "41 - goldbach_list";
	TestManager.doTest "9 20" (goldbach_list 9 20 = [(10, (3, 7)); (12, (5, 7)); (14, (3, 11)); (16, (3, 13)); (18, (5, 13)); (20, (3, 17))]);
	TestManager.endChallenge ();
	TestManager.startChallenge "41 - goldbach_limit";
	TestManager.doTest "1 2000 50" (goldbach_limit 1 2000 50 = [(992, (73, 919)); (1382, (61, 1321)); (1856, (67, 1789)); (1928, (61, 1867))]);
	TestManager.endChallenge ()
