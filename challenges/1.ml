
let rec last li = match li with
	| []			-> None
	| [head]		-> Some head
	| _ :: tail		-> last tail
