
module InRotcharStream =
struct
  type t = string
  type out = char

  let init () = "abcdefghijklmnopqrstuvwxyz"

  let update (str: string) =
    let c = String.get str 0 in
    let rotate i =
      if i == ((String.length str) - 1) then String.get str 0
      else String.get str (i + 1)
    in
    let next_str = String.init (String.length str) rotate in
    (next_str, c)
end

module RotcharStream = Streams.MakeStream(InRotcharStream)

let () =
  print_endline "RotcharStream";
  for i = 0 to 51 do print_char (RotcharStream.next ()) done;
  print_char '\n'
