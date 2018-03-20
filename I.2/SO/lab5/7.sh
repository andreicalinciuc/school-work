#!/bin/bash

cd $1

for f in *.sh
do
  echo $f
  echo $(cat $f | grep '#' | grep -v '#!' | grep -v '$#')
done
