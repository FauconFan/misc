
let rec is_prime n =
	if n < 0 then is_prime (-n)
	else if n = 0 then false
	else if n <= 2 then true
	else
		begin
			let rec loop n cand =
				if cand * cand > n then true
				else if n mod cand = 0 then false
				else loop n (cand + 1) in
			loop n 2
		end

let test () =
	TestManager.startChallenge "30 - is_prime";
	TestManager.doTest "1" (is_prime 1 = true);
	TestManager.doTest "2" (is_prime 2 = true);
	TestManager.doTest "7" (is_prime 7 = true);
	TestManager.doTest "3" (is_prime 3 = true);
	TestManager.doTest "4" (is_prime 4 = false);
	TestManager.doTest "10" (is_prime 10 = false);
	TestManager.doTest "8" (is_prime 8 = false);
	TestManager.doTest "9" (is_prime 9 = false);
	TestManager.doTest "12" (is_prime 12 = false);
	TestManager.endChallenge ()
