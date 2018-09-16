
let rec factors n =
	if n < 0 then (factors (-n))
	else if n = 0 then [(0, 1)]
	else if n = 1 then [(1, 1)]
	else
		begin
			let rec loop n cand occurency =
				if cand * cand > n then
					begin
						if occurency != 0 then
							begin
								if cand = n then [(n, occurency + 1)]
								else [(cand, occurency); (n, 1)]
							end
						else [(n, 1)]
					end
				else if n mod cand = 0 then loop (n / cand) cand (occurency + 1)
				else if occurency != 0 then (cand, occurency) :: loop n (cand + 1) 0
				else loop n (cand + 1) 0 in
			loop n 2 0
		end

let rec pow n m =
	if m = 0 then 1
	else if m = 1 then n
	else
		begin
			let half = pow n (m / 2) in
			if m mod 2 = 0 then half * half
			else half * half * n
		end

let phi_improved n =
	let fact = factors n in
	let rec loop li res_final = match li with
		| []			-> res_final
		| head :: tail	-> match head with
			| (p, m)		-> loop tail (res_final * (p - 1) * (pow p (m - 1))) in
	loop fact 1

let test () =
	TestManager.startChallenge "37 - phi_improved";
	TestManager.doTest "10" (phi_improved 10 = 4);
	TestManager.doTest "13" (phi_improved 13 = 12);
	TestManager.endChallenge ()
