
type bool_expr =
    | Var of string
    | Not of bool_expr
    | And of bool_expr * bool_expr
    | Or of bool_expr * bool_expr

let table2 a b expr =
	let rec eval a b a_val b_val expr = match expr with
		| Var x ->
			begin
				if x = a then a_val
				else if x = b then b_val
				else false
			end
		| Not e -> eval a b a_val b_val e
		| And (f, g) -> eval a b a_val b_val f && eval a b a_val b_val g
		| Or (f, g) -> eval a b a_val b_val f || eval a b a_val b_val g in
	let build_expr a b expr a_val b_val =
		(a_val, b_val, eval a b a_val b_val expr) in
	let tt = build_expr a b expr true true in
	let tf = build_expr a b expr true false in
	let ft = build_expr a b expr false true in
	let ff = build_expr a b expr false false in
	[tt ; tf ; ft; ff]

let test () =
	let expr = And(Var "a", Or(Var "a", Not (Var "b"))) in
	let out = [(true, true, true); (true, false, true); (false, true, false); (false, false, false)] in
	TestManager.startChallenge "46 & 47 - table2";
	TestManager.doTest "example" (table2 "a" "b" expr = out);
	TestManager.endChallenge ()
