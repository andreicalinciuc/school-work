#!/bin/bash

for f in `find $1 -type f`
do
  if [[ -r $f && -x $f ]]
  then
    cat $f | head -n $2
  fi
done
