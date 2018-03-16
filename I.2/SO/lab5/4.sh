#!/bin/bash

directoare=0
fisiere_fifo=0

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
        let directoare++
        parcurge $1/$f
      elif [ -p $1/$f ]
      then
        let fisiere_fifo++
      fi
    done
}

parcurge $path

echo $directoare $fisiere_fifo
