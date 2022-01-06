
let rec factors n =
	if n < 0 then (-1) :: (factors (-n))
	else if n = 0 then [0]
	else if n = 1 then [1]
	else
		begin
			let rec loop n cand =
				if cand * cand > n then [n]
				else if n mod cand = 0 then cand :: (factors (n / cand))
				else loop n (cand + 1) in
			loop n 2
		end

let test () =
	TestManager.startChallenge "35 - factors";
	TestManager.doTest "315" (factors 315 = [3; 3; 5; 7]);
	TestManager.endChallenge ()
