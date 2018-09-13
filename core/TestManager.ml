
module Out = ANSITerminal

let noTitle = "No Title"

let titleTest = ref None
let nb_tests = ref 0
let tests_succeed = ref 0
let tests_failed = ref 0
let li_test_failed = ref []

let startChallenge t =
	titleTest := (Some t);
	nb_tests := 0;
	tests_succeed := 0;
	tests_failed := 0;
	li_test_failed := []

let doTest (str:string) (b:bool) =
	incr nb_tests;
	if b then incr tests_succeed
	else
		begin
			incr tests_failed;
			li_test_failed := str :: !li_test_failed
		end

let info (str:string) =
	let prefix = match !titleTest with
	| None			-> noTitle
	| Some title	-> title
	in

	Out.printf [Out.Foreground Out.Magenta; Out.Bold] "INFO";
	Out.printf [Out.Foreground Out.Cyan; Out.Bold] " %s " prefix;
	print_string str;
	print_newline ()


let endChallenge () =
	let prefix = match !titleTest with
	| None			-> noTitle
	| Some title	-> title
	in
	titleTest := None;

	Out.printf [Out.Foreground Out.Cyan; Out.Bold] "==== %-35s ==== " prefix;
	if !tests_failed = 0
	then
		begin
			let test_word = if !nb_tests <= 1 then "test" else "tests" in
			Out.printf [Out.Foreground Out.Green; Out.Bold] " OK (%-2d %s)" !nb_tests test_word;
			print_newline ()
		end
	else
		begin
			let def_error = [Out.Foreground Out.Red; Out.Bold; Out.Blink] in
			Out.printf def_error " Failed";	print_newline ();
			List.iter (fun str -> Out.printf def_error "\t=> %s\n" str) !li_test_failed
		end
