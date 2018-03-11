#!/bin/bash

res1=1
res2=1
res3=1
n=$1
k=$2

for ((i=1; i<=$n; i++))
do
  res1=$(($res1*$i))
done

for ((i=1; i<=$k; i++))
do
  res2=$(($res2*$i))
done

for ((i=1; i<=$(($n-$k)); i++))
do
  res3=$(($res3*$i))
done

res4=$(($res1/$res2))
res4=$(($res4/$res3))

echo $res4
