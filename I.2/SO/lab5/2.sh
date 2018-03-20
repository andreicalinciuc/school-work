#!/bin/bash

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        parcurge $1/$f
      elif [[ -f $1/$f && $(file $1/$f | grep "ASCII text" | wc -c) != 0 ]]
      then
        echo -n "$f: "
        echo -n "$(cat $1/$f | wc -w) "
        echo "$(cat $1/$f | wc -L) "
      fi
     done
}

parcurge $path
