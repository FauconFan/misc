
let permutation li =
	let insert_random li elem size_li =
		if size_li <= 0 then [elem]
		else
			begin
				let rank = Random.int (size_li + 1) in
				let rec insert_elem_rec li elem remain =
					if remain <= 0 then elem :: li
					else match li with
					| []			-> [elem]
					| head :: tail 	-> head :: (insert_elem_rec tail elem (remain - 1))
				in
				insert_elem_rec li elem rank
			end
	in
	let rec rec_perm li res size_res = match li with
		| [] 			->	res
		| head :: tail 	->	rec_perm tail (insert_random res head size_res) (size_res + 1)
	in
	rec_perm li [] 0

let test () =
	let l1 = ("Triplet", [4; 8; 12]) in
	let l2 = ("Empty", []) in
	let l3 = ("Singleton", [5]) in
	let l = [l1; l2; l3] in
	let apply a = match a with
		| (n, arg1) ->
			begin
				let ans = permutation arg1 in
				let b = ref true in
				let rec is_in li elem = match li with
					| []			-> false
					| head :: tail	-> if head == elem then true
										else is_in tail elem in
				let f = (fun i -> if not (is_in arg1 i) then b := false) in
				List.iter f ans;
				if (List.length ans <> List.length arg1) then b := false;
				TestManager.doTest n !b
			end
	in

	TestManager.startChallenge "25 - permutation";
	List.iter apply l;
	TestManager.endChallenge ()
