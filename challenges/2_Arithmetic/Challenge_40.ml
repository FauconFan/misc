
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
	else loop m 2

let test () =
	TestManager.startChallenge "40 - goldbach";
	TestManager.doTest "28" (goldbach 28 = (5, 23));
	TestManager.endChallenge ()
