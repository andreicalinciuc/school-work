#!/bin/bash

v1=1
v2=1

for ((i=3; i<=$1; i++))
do
  v3=$(($v1+$v2))
  v1=$v2
  v2=$v3
done

echo $v3
