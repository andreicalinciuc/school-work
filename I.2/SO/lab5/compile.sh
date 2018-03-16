#!/bin/bash

if [ $# -eq 0 ]
then
  read filename
else
  filename=$1
fi

ok=1

while [ $ok -eq 1 ]
do
  vim $filename
  echo "Compilare? y/n"
  read ans
  if [ $ans = "y" ]
  then
    gcc $filename -o $(basename $filename .c)
    if [ $? -eq 0 ]
    then
      echo "Rulare? y/n"
      read ans
      if [ $ans = "y" ]
      then
        ./$(basename $filename .c)
        ok=0
      else
        exit 0
      fi
    else
      echo "Apasa ENTER pentru a reveni la editor..."
      read pauza
    fi
  else
    ok=0
  fi
done
