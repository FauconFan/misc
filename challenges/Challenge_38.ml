
(* Copied phi and phi_improved functions *)

let rec phi n =
	if n <= 0 then 0
	else if n = 1 then 1
	else
		begin
			let rec loop n cand =
				if cand * cand > n then n - 1
				else if n mod cand = 0 then (phi cand) * (phi (n / cand))
				else loop n (cand + 1) in
			loop n 2
		end

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

(* Naive [timeit] function.  It requires the [Unix] module to be loaded. *)

let timeit f a =
	let t0 = Unix.gettimeofday() in
	ignore(f a);
	let t1 = Unix.gettimeofday() in
	t1 -. t0

let test () =
	let cand = 10090 in
	let time_phi = timeit phi cand in
	let time_phi_imp = timeit phi_improved cand in
	TestManager.startChallenge "38 - timeit";
	TestManager.info ("phi " ^ (string_of_float time_phi));
	TestManager.info ("phi_improved " ^ (string_of_float time_phi_imp));
	TestManager.doTest "timeit 10" (time_phi_imp < 1.);
	TestManager.endChallenge ()
