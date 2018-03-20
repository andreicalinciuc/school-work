#!/bin/bash

if [ $# -eq 0 ]
then
  read n
else
  n=$1
fi

ni=0
cn=$n

while [ $n != 0 ]
do
  d=$((n%10))
  let n/=10
  let s+=d
  let ni=ni*10+d
done

echo $s

if [ $ni = $cn ]
then
  echo palindrome
else
  echo not palindrome
fi
