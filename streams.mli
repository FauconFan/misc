
module type InStream =
sig
  type t
  type out
  val init : unit -> t
  val update : t -> t * out
end

module type Stream =
sig
  type t
  type out
  val get : unit -> t
  val next : unit -> out
end

module type MAKESTREAM = functor (In : InStream) -> (Stream
                                                     with type t = In.t
                                                     with type out = In.out)
module MakeStream : MAKESTREAM
