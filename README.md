# Ocaml_stream

This project is just for training.

The goal was to implement a stream structure to have a kind of infinite list.

[Wikipedia Stream (Processing)](https://en.wikipedia.org/wiki/Stream_processing)  
[Stream and Data Flow](http://www.jonathanbeard.io/blog/2015/09/19/streaming-and-dataflow.html)

The implementation is using a functor, taking a type, an init function and a update function, and returning a module of type Stream.

```Ocaml
module type InStream =
sig
  type t

  val init : unit -> t
  val update : t -> t
end

module type Stream = sig
  type t
  val get : unit -> t
  val next : unit -> t
end

module type MAKESTREAM = functor (In : InStream) -> (Stream with type t = In.t)
module MakeStream : MAKESTREAM
```
