#!/bin/bash
PATH=/usr/bin:/bin

s=0
echo > logged.txt

who | cut -f 1 -d ' ' | grep -v so | sort | uniq | tr '.' ' ' | tr [:lower:] [:upper:] >> logged.txt

s=$(cat logged.txt | wc -l)

echo $s students are suffering right now:
cat logged.txt
