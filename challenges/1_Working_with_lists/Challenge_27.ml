
let group li groups =
	let rec len_list li = match li with
		| []			->	0
		| _ :: tail		->	1 + (len_list tail) in
	let rev_list li =
		let rec loop li res = match li with
			| []			->	res
			| head :: tail	->	loop tail (head :: res) in
		loop li [] in
	let extract_n_remain n l =
		if n <= 0 then []
		else
			begin
				let rec loop n li len res_final res_tmp remain_tmp =
					if n == 0 then ((rev_list res_tmp), (rev_list remain_tmp) @ li) :: res_final
					else if len <= 0 || n > len then res_final
					else
						match li with
							| []			->  failwith "SNH"
							| head :: tail	->
								let res_with = loop (n - 1) tail (len - 1) res_final (head :: res_tmp) remain_tmp in
								loop n tail (len - 1) res_with res_tmp (head :: remain_tmp)
				in
				let rev_res = loop n l (len_list l) [] [] [] in
				rev_list rev_res
			end in
	let rec sum_list li = match li with
		| []				-> 0
		| head :: tail		-> head + (sum_list tail) in
	let rec loop groups res_final =
		let rec build_answer li = match li with
			| []			-> []
			| head :: tail	-> (rev_list (fst head)) :: (build_answer tail) in
		match groups with
			| []			-> build_answer res_final
			| head :: tail	->
				begin
					let rec loop_loop li extract_n res_tmp_final =
						match li with
							| []			-> res_tmp_final
							| head :: tail	->
								begin
									let extracted = extract_n_remain extract_n (snd head) in
									let build_next_head old_head new_head =
										match old_head with
											| []			-> [new_head]
											| head :: tail	-> new_head :: (head :: tail) in
									let rec loop_loop_loop lhs new_extracted =
										match new_extracted with
											| []			-> []
											| head :: tail	-> ((build_next_head lhs (fst head)), (snd head)) :: (loop_loop_loop lhs tail) in
									loop_loop tail extract_n (res_tmp_final @ (loop_loop_loop (fst head) extracted))
								end in
					loop tail (loop_loop res_final head [])
				end
	in
	if groups = [] || sum_list groups > len_list li then []
	else
		loop groups [([], li)]

let test () =
	let out = [[["a"; "b"]; ["c"]]; [["a"; "b"]; ["d"]]; [["a"; "c"]; ["b"]];
 [["a"; "c"]; ["d"]]; [["a"; "d"]; ["b"]]; [["a"; "d"]; ["c"]];
 [["b"; "c"]; ["a"]]; [["b"; "c"]; ["d"]]; [["b"; "d"]; ["a"]];
 [["b"; "d"]; ["c"]]; [["c"; "d"]; ["a"]]; [["c"; "d"]; ["b"]]] in
	TestManager.startChallenge "27 - groups";
	TestManager.doTest "Simple" ((group ["a"; "b"; "c"; "d"] [2; 1]) = out);
	TestManager.endChallenge ()
