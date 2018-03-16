#!/bin/bash

if [ $# = 0 ]
then
  read file
else
  file=$1
fi

echo > $file

op=0

until [[ $op = "q" ]]
do
  read x
  read y
  read op
  let nr++
  echo -n "$nr: $x $op $y = " >> $file

  if [[ $op = "+" ]]
  then
    echo $((x+y)) >> $file
  elif [[ $op = "-" ]]
  then
    echo $((x-y)) >> $file
  elif [[ $op = "*" ]]
  then
    echo $((x*y)) >> $file
  elif [[ $op = "/" ]]
  then
    echo $((x/y)) >> $file
  fi
done
