
type huffman_tree =
    | Simple of string * int
	| Node of huffman_tree * huffman_tree * int

let rev_list li =
	let rec core li res = match li with
		| []			-> res
		| head :: tail	-> core tail (head :: res) in
	core li []

let extract_value elem = match elem with
	| Simple (_, i)		-> i
	| Node (_, _, i)	-> i

let comp elem1 elem2 =
	let i1 = extract_value elem1 in
	let i2 = extract_value elem2 in
	i1 < i2

let extract_min li comp = match li with
	| []			-> failwith "SNH"
	| head :: tail	->
		begin
			let rec loop li cand rank rank_cand = match li with
				| []			-> (cand, rank_cand)
				| head :: tail	->
					begin
						if comp head cand then loop tail head (rank + 1) rank
						else loop tail cand (rank + 1) rank_cand
					end in
			let rec delete_n li rank = match li with
				| []			-> []
				| head :: tail	->
					begin
						if rank = 0 then tail
						else head :: (delete_n tail (rank - 1))
					end in
			let (min_cand, min_rank) = loop tail head 1 0 in
			let res_list = delete_n li min_rank in
			(min_cand, res_list)
		end

let build_leaves li =
	let rec core li res = match li with
		| []				-> rev_list res
		| (str, i) :: tail	-> core tail (Simple (str, i) :: res) in
	core li []

let huffman fs =
	let rec build_tree fs = match fs with
		| [] 			-> failwith "SNH"
		| [head]		-> head
		| _ 			->
			begin
				let (min1, fs2) = extract_min fs comp in
				let (min2, fs3) = extract_min fs2 comp in
				build_tree (Node (min1, min2, (extract_value min1 + extract_value min2)) :: fs3)
			end in
	let rec build_final tree str = match tree with
		| Simple (rep, _)		-> [(rep, str)]
		| Node (n1, n2, _)		-> (build_final n1 (str ^ "0")) @ (build_final n2 (str ^ "1")) in
	let tree = build_tree (build_leaves fs) in
	build_final tree ""

let test () =
	let f1 = [("a", 10); ("b", 15); ("c", 30); ("d", 16); ("e", 29)] in
	let f2 = [("a", 45); ("b", 13); ("c", 12); ("d", 16); ("e", 9); ("f", 5)] in
	let o1 = [("d", "00"); ("a", "010"); ("b", "011"); ("e", "10"); ("c", "11")] in
	let o2 = [("a", "0"); ("c", "100"); ("b", "101"); ("f", "1100"); ("e", "1101"); ("d", "111")] in
	TestManager.startChallenge "50 - huffman tree";
	TestManager.doTest "e1" (huffman f1 = o1);
	TestManager.doTest "e2" (huffman f2 = o2);
	TestManager.endChallenge ()
