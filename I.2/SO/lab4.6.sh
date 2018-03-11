#!/bin/bash

maxi=$1
mini=$1

for ((i=1; i<=$#; i++))
do

  if ((${!i}>maxi))
  then
    maxi=${!i}
  fi

  if ((${!i}<mini))
  then
    mini=${!i}
  fi

done

echo $mini $maxi
