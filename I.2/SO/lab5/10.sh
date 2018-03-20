#!/bin/bash

for f in `find $1 -type f`
do
  if [[ $f = *.txt ]]
  then
    path=$(dirname $f)
    mv $f $path/$(basename $f .txt).ascii
  fi
done
