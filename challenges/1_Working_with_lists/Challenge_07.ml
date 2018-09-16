
type 'a node =
    | One of 'a
    | Many of 'a node list

let rec flatten li_node = match li_node with
	| []			-> []
	| head :: tail	->
		begin
			let sub n = match n with
				| One a		-> [a]
				| Many li2	-> flatten li2
			in
			(sub head) @ (flatten tail)
		end

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [One 2], [2]) in
	let l3 = (true, "Pair1", [One 2; One 3], [2;3]) in
	let l4 = (true, "Pair2", [Many [Many [One 2; One 3]]], [2; 3]) in
	let l5 = (false, "Pair3", [Many [Many [One 2; One 3]]], [3; 2]) in
	let l6 = (true, "Complicated", [One 1; Many [One 2; Many [One 3; One 4]; One 5]], [1; 2; 3; 4; 5]) in
	let l7 = (false, "ComplicatedFail", [One 1; Many [One 2; Many [One 3; One 4]; One 5]], [1; 3; 2; 4; 5]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((flatten l = exp) = b)
	in

	TestManager.startChallenge "07 - flatten";
	List.iter apply l;
	TestManager.endChallenge ()
