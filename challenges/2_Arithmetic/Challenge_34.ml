
(*
	Use the two properties that:
		phi(m) = m - 1 if m is prime
		phi(a * b) = phi(a) * phi(b)
*)

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

let test () =
	TestManager.startChallenge "34 - phi";
	TestManager.doTest "10" (phi 10 = 4);
	TestManager.doTest "13" (phi 13 = 12);
	TestManager.endChallenge ()
