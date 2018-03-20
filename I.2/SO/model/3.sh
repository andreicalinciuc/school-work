#!/bin/bash
A=$#; B=0;
for a in $(ls /bin/*)
do
  [ -f $a ] && let B++
done
echo $B, $A
