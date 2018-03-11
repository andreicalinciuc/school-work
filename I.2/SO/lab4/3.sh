#!/bin/bash

cd $1
n=$(find . -maxdepth 1 -type f -name "*.cpp" | wc -l)
for ((i=1; i<=$n; i++))
do
  this=$(find . -maxdepth 1 -type f -name "*.cpp" | tail -n +$i | head -n 1)
  this=$(basename $this .cpp)
  g++ $this.cpp -o $this
done
