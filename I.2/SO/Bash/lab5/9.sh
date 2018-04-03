#!/bin/bash

for f in `find $1 -type f`
do
  if [[ $f = *.c ]]
  then
    gcc $f -o $(basename $f .c)
  fi
  if [[ $f = *.txt ]]
  then
    cat $f
  fi
done
