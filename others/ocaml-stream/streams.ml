
module type InStream = sig
  type t
  type out

  val init : unit -> t
  val update : t -> (t * out)
end

module type Stream = sig
  type t
  type out

  val get : unit -> t
  val next : unit -> out
end

module type MAKESTREAM =
  functor (In : InStream) ->
    (Stream
     with type t = In.t
     with type out = In.out)

module MakeStream (In : InStream) : (Stream
                                     with type t = In.t
                                     with type out = In.out) =
struct
  type t = In.t
  type out = In.out

  let buff = ref (In.init ())

  let get () =
    !buff

  let next () =
    let (buff_tmp, ret) = In.update !buff in
    buff := buff_tmp;
    ret
end
