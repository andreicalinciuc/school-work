#!/bin/bash

res=0

for ((i=1; i<=$#; i++))
do
  res=$(($res+${!i}))
done

res=$(($res/$#))

echo $res
