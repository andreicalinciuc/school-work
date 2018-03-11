#!/bin/bash

n=$1
m=$2
res=0

for ((i=1; i<=$m; i++))
do
  res=$(($res+$n))
done

echo $res
