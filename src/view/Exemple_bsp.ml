open Base
open Graphics

let exemple_cours = 
  L (
    {coord = 545; colored = false},
    L(
      {coord = 760; colored = false},
        L(
          {coord = 200; colored = false},
          R None,
          R (Some(blue))
          ),
          L(
            {coord = 125; colored = false},
            R (Some(blue)),
            R None
          )
        ),
        L(
          {coord = 345; colored = false},
          L(
            {coord = 750; colored = false},
            R None,
            R None
          ),
          L(
            {coord = 600; colored = false},
            R None,
            L(
              {coord = 500; colored = false},
              R None,
              R None
            )
          )
        )
      )

let exemple1 = 
  L (
    {coord = 300; colored = false},
    L(
      {coord = 200; colored = false},
        L(
          {coord = 150; colored = false},
          R (Some(red)),
          R (Some(blue))
          ),
          L(
            {coord = 100; colored = false},
            R (Some(red)),
            R (Some(red))
          )
        ),
        L(
          {coord = 600; colored = false},
          L(
            {coord = 750; colored = false},
            R (Some(blue)),
            R (Some(blue))
          ),
          L(
            {coord = 500; colored = false},
            R None,
            L(
              {coord = 800; colored = false},
              R None,
              R None
            )
          )
        )
      )

let simple = 
  L (
    {coord = 500; colored = true},
    R None,
    R None
  )