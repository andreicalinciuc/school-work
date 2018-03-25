#!/bin/bash

var1=$(cat /etc/passwd | grep studs | grep "^$1" | cut -f 1 -d ':')
n=$(echo $var1 | wc -w)

for ((i=1; i<=$n; i++))
do
  current=$(echo $var1 | cut -f $i -d ' ')
  if [ -r /fenrir/studs/$current/html/index.html -o -r /fenrir/studs/$current/html/index.htm -o -r /fenrir/studs/$current/html/index.php ]
  then
    echo $current
  fi
done
