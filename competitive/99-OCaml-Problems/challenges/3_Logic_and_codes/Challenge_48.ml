
type bool_expr =
    | Var of string
    | Not of bool_expr
    | And of bool_expr * bool_expr
    | Or of bool_expr * bool_expr

let rev_list li =
	let rec core li res = match li with
		| []			-> res
		| head :: tail	-> core tail (head :: res) in
	core li []

let rec map_list li f = match li with
	| []			-> []
	| head :: tail	-> (f head) :: (map_list tail f)

let table li expr =
	let rec eval li_values expr = match expr with
		| Var x ->
			begin
				let rec get_value li x = match li with
				| []			-> false
				| head :: tail	-> match head with
					| (str, res)	-> if str = x then res else get_value tail x in
				get_value li_values x
			end
		| Not e -> eval li_values e
		| And (f, g) -> eval li_values f && eval li_values g
		| Or (f, g) -> eval li_values f || eval li_values g in
	let rec build_values li res = match li with
		| []			-> map_list res rev_list
		| head :: tail	->
			begin
				let rec build_values2 res_tmp str res = match res_tmp with
					| []				-> res
					| head2 :: tail2	-> build_values2 tail2 str (((str, true) :: head2) :: ((str, false) :: head2) :: res) in
				if res = [] then build_values tail [[(head, true)]; [(head, false)]]
				else build_values tail (build_values2 (rev_list res) head [])
			end in
	let rec core li_values expr res = match li_values with
		| []			-> rev_list res
		| head :: tail	-> core tail expr ((head, eval head expr) :: res) in
	core (build_values li []) expr []

let test () =
	let a = Var "a" and b = Var "b" and c = Var "c" in
	let expr = Or(And(a, Or(b,c)), Or(And(Not(Not(a)),b), And(a,c))) in
	let out = [([("a", true); ("b", true); ("c", true)], true); ([("a", true); ("b", true); ("c", false)], true); ([("a", true); ("b", false); ("c", true)], true); ([("a", true); ("b", false); ("c", false)], false); ([("a", false); ("b", true); ("c", true)], false); ([("a", false); ("b", true); ("c", false)], false); ([("a", false); ("b", false); ("c", true)], false); ([("a", false); ("b", false); ("c", false)], false)] in
	TestManager.startChallenge "48 - table";
	TestManager.doTest "example" (table ["a"; "b"; "c"] expr = out);
	TestManager.endChallenge ()
