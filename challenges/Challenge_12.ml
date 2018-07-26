
type 'a rle =
    | One of 'a
    | Many of int * 'a

let rec decode li = match li with
	| []				-> []
	| head :: tail		-> match head with
			| One a			-> a :: (decode tail)
			| Many (i, a)	->
				begin
					let rec init_custom i a =
						if i <= 1 then a :: (decode tail)
						else a :: (init_custom (i - 1) a)
					in
					init_custom i a
				end

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [One 2]) in
	let l3 = (true, "PairSame", [2; 2], [Many (2, 2)]) in
	let l4 = (true, "PairDiff", [2; 3], [One 2; One 3]) in
	let l5 = (false, "PairDiffFail", [2; 3], [One 3; One 2]) in
	let l6 = (true, "Ex", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [Many (4, 1); One 2; Many (2, 3); Many (2, 1); Many (2, 4);
 Many (4, 5)]) in
	let l7 = (false, "ExFail", [1; 1; 1; 1; 2; 3; 3; 1; 1; 4; 4; 5; 5; 5; 5], [Many (3, 1); One 2; Many (2, 3); Many (2, 1); Many (2, 4);
 Many (4, 5)]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, exp, l) -> TestManager.doTest n ((decode l = exp) = b)
	in

	TestManager.changeTitle "12 - decode";
	List.iter apply l
