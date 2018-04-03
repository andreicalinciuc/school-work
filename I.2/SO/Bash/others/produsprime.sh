#!/bin/bash

if [ $# -eq 0 ]
then
  read n
else
  n=$1
fi

prim()
{
    n=$1
    if [ $n -eq 0 ]
    then
      echo 1
    else
      c=$((n%10))
      if [ $c -eq 2 -o $c -eq 3 -o $c -eq 5 -o $c -eq 7 ]
      then
        echo $(( c * $(prim $((n/10))) ))
      else
        echo $(prim $((n/10)))
      fi
    fi
}

prim $n
