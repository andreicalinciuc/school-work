#!/bin/bash

calculeaza()
{
    n=$1
    if (($n >= 2))
    then
      echo $((3*$(calculeaza $(($n-1)))-2*$(calculeaza $(($n-2)))))
    elif (($n == 1))
    then
      echo 1
    elif (($n == 0))
    then
      echo 0
    fi
}

calculeaza $1
