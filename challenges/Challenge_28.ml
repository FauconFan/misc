
let rec list_length li =
 	match li with
		| []		-> 0
		| _ :: tail -> 1 + (list_length tail)

let rev_list li =
	let rec loop li res = match li with
		| []			->	res
		| head :: tail	->	loop tail (head :: res) in
	loop li []

let qsort_on_snd li =
	let rec partition li pivot = match li with
		| []			-> ([], [])
		| head :: tail	->
			begin
				let (l1, l2) = partition tail pivot in
				if ((snd head) < pivot) then (head :: l1, l2)
				else (l1, head :: l2)
			end in
	let rec core li =
		match li with
			| []			-> []
			| head :: tail	->
				begin
					let (l1, l2) = partition tail (snd head) in
						(core l1) @ (head :: (core l2))
				end in
	let pre_res = core li in
	let rec loop_post li = match li with
		| []			-> []
		| head :: tail	-> (fst head) :: (loop_post tail) in
	loop_post pre_res

let rec calculate_len_store_in_snd li = match li with
	| []			-> []
	| head :: tail	-> (head, (list_length head)) :: (calculate_len_store_in_snd tail)

let length_sort tab_li =
	let pre_build = calculate_len_store_in_snd tab_li in
	qsort_on_snd pre_build

let frequency_sort tab_li =
	let pre_pre_build = calculate_len_store_in_snd tab_li in
	let rec pre_build_f li res_final cand =
		let rec count_occurency li n = match li with
			| []			-> 0
			| head :: tail	->
				begin
					match head with
					| (_, n_cand)	->
						begin
							let next = count_occurency tail n in
							if n = n_cand then 1 + next else next
						end
				end in
		match cand with
		| []			-> res_final
		| head :: tail	-> match head with
			| (sub_l, len_l)	->
				begin
					let new_res_final = (sub_l, (count_occurency li len_l)) :: res_final in
					pre_build_f li new_res_final tail
				end in
	let pre_build = pre_build_f pre_pre_build [] pre_pre_build in

	qsort_on_snd (rev_list pre_build)

let test () =
	let in_lsort = [["a"; "b"; "c"]; ["d"; "e"]; ["f"; "g"; "h"]; ["d"; "e"]; ["i"; "j"; "k"; "l"]; ["m"; "n"]; ["o"]] in
	let out_lsort = [["o"]; ["d"; "e"]; ["d"; "e"]; ["m"; "n"]; ["a"; "b"; "c"]; ["f"; "g"; "h"]; ["i"; "j"; "k"; "l"]] in
	let in_fsort = [["a"; "b"; "c"]; ["d"; "e"]; ["f"; "g"; "h"]; ["d"; "e"]; ["i"; "j"; "k"; "l"]; ["m"; "n"]; ["o"]] in
	let out_fsort = [["i"; "j"; "k"; "l"]; ["o"]; ["a"; "b"; "c"]; ["f"; "g"; "h"]; ["d"; "e"]; ["d"; "e"]; ["m"; "n"]] in
	TestManager.startChallenge "28 - length_sort";
	TestManager.doTest "Simple length_sort" ((length_sort in_lsort) = out_lsort);
	TestManager.endChallenge ();
	TestManager.startChallenge "28 - frequency_sort";
	TestManager.doTest "Simple frequency_sort" ((frequency_sort in_fsort) = out_fsort);
	TestManager.endChallenge ()
