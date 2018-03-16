#!/bin/bash

while read user
do
  ok=$(last -w | grep "^$user " | head -n 3 | wc -c)
  if [[ $ok = 0 ]]
  then
    echo "Utilizatorul $user nu s-a conectat niciodata!"
  else
    last -w | grep "^$user " | head -n 3
  fi
done
