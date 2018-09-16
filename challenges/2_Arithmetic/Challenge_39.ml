
let gen_all_primes ma =
	if ma <= 2 then [2]
	else
		begin
			let rec loop_builder li cand ma =
				let rec no_divisor li cand = match li with
					| []			-> true
					| head :: tail	-> if cand mod head = 0 then false
									   else no_divisor tail cand in
				if cand > ma then li
				else
					begin
						let next_li = if no_divisor li cand then (li @ [cand])
									  else li in
						loop_builder next_li (cand + 2) ma
					end in
			loop_builder [2] 3 ma
		end

let all_primes mi ma =
	if mi < 0 || ma < 0 || mi > ma then []
	else
		begin
			let primes_ma = gen_all_primes ma in
			let rec sub_mi li mi = match li with
				| []			-> []
				| head :: tail	-> if head >= mi then li
								   else sub_mi tail mi in
			sub_mi primes_ma mi
		end

let test () =
	let rec len_list li = match li with
		| []			-> 0
		| _ :: tail		-> 1 + len_list tail in
	TestManager.startChallenge "39 - all_primes";
	TestManager.doTest "2 7920" (len_list (all_primes 2 7920) = 1000);
	TestManager.doTest "2 100" (len_list (all_primes 2 100) = 25);
	TestManager.endChallenge ()
