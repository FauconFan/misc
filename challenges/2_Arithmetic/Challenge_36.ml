
let rec factors n =
	if n < 0 then (-1, 1) :: (factors (-n))
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

let test () =
	TestManager.startChallenge "36 - factors";
	TestManager.doTest "315" (factors 315 = [(3, 2); (5, 1); (7, 1)]);
	TestManager.doTest "49" (factors 49 = [(7, 2)]);
	TestManager.endChallenge ()
