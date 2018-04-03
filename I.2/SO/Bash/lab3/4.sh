#!/bin/bash

for ((i=1; i<=$#; i++))
do
  echo "param_$i = ${!i}"
done
