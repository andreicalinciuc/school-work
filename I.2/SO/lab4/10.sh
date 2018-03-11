#!/bin/bash

if [ $# -eq 0 ]
then
  read n
  for ((i=1; i<=$n; i++))
  do
    read i
    sum=$(($sum+$i))
  done
  echo $sum
else
  n=$1
  k=$(( ($#-1)/$n ))
  p=$(( ($#-1)%$n ))

  for ((i=0; i<$k; i++))
  do
    sum=0
    for ((j=1; j<=$n; j++))
    do
      position=$((1+(i*n)+j))
      sum=$(( $sum+${!position} ))
    done
    echo $sum
    echo $sum >> output.txt 
  done

  if [ $p -ne 0 ]
  then
    sum=0
    for ((i=1; i<=$p; i++))
    do
      position=$((position+1))
      sum=$(( $sum+${!position} ))
    done
    echo $sum
    echo $sum >> output.txt
  fi
fi
