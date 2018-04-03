#!/bin/bash

voturi=0
candidat=0

for ((i=1; i<=$#; i++))
do
  array[${!i}]=$((${array[${!i}]}+1))
  if ((${!i}>maxi))
  then
    maxi=${!i}
  fi
done

for ((i=1; i<=$#; i++))
do
  if ((${array[${!i}]}>$voturi))
  then
    voturi=$((${array[${!i}]}))
    candidat=${!i}
  fi
done

echo $candidat $voturi
