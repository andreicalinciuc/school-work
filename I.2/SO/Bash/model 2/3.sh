#!/bin/bash

################################################################################
#
# Sa se scrie un script bash care primeste ca parametri numele unui director
# si un cuvant w, parcurge RECURSIV toate subdirectoarele acestuia si
# calculeaza numarul total de linii ce contin macar o aparitie exacta a
# cuvantului w in toate fisierele obisnuite pentru care utilizatorul ce
# lanseaza in executie scriptul are drept de citire.
#
# Numele directorului si cuvantul w vor fi dati ca parametri la linia de
# comanda sau se vor citi prin comanda read in caz contrar.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
# VLAD BUJOREANU
###############################################################################$

if [ $# -eq 0 ]
then
  read path
  read w
else
  path=$1
  w=$2
fi

n=0

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        parcurge $1/$f
      elif [[ -f $1/$f && -r $1/$f ]]
      then
        let n+=$(cat $1/$f | grep -w $w | wc -l)
      fi
    done
}

parcurge $path

echo $n
