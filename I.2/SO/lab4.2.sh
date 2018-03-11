#!/bin/bash

fact()
{
    n=$1
    if (($n > 1))
    then
      echo $(($n * $(fact $(($n - 1)))))
    else
      echo 1
    fi
}

fact $1
