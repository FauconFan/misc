
module InPrimeStream =
struct
  type t = int array
  type out = int

  let init () = [|2|]

  let update (li: int array) =
    let ma = Array.fold_left max 0 li in

    let rec search_prime ?i:(i = 0) cand =
      if (i >= (Array.length li)) then cand
      else if ((cand mod li.(i)) == 0) then search_prime (cand + 1)
      else search_prime ~i:(i + 1) cand
    in
    let next_prime = search_prime (ma + 1) in
    ((Array.append li [| next_prime |]), next_prime)
end

module PrimeStream = Streams.MakeStream(InPrimeStream)

let () =
  print_endline "PrimeStream";
  let ppint i = print_int i; print_char ' ' in
  for i = 1 to 24 do ignore(PrimeStream.next ()) done;
  Array.iter ppint (PrimeStream.get ());
  print_char '\n'
