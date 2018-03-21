#!/bin/bash

###############################################################################$
# Enunt a treia problema:
#
# Sa se scrie un script bash care primeste ca parametri doua valori n si x, num$
# si calculeaza RECURSIV termenul Y(n) al sirului {Y(m)}m>=0, definit prin:
# Y(0)=x-1, Y(1)=x, Y(2)=x+1
# si Y(m) = (m-1) * Y(m-1) - (m-2) * Y(m-2) + Y(m-3) , pentru orice m>=3.
#
# La final se va afisa valoarea termenului cerut, Y(n).
#
# Valorile parametrilor n si x se vor prelua ca argumente din linia de comanda,
# sau se vor citi utilizand comanda read, in caz ca lipsesc in linia de comanda.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
# VLAD BUJOREANU
###############################################################################$

if [ $# -eq 0 ]
then
  read n
  read x
else
  n=$1
  x=$2
fi

calculeaza()
{
    m=$1
    if [ $m -eq 0 ]
    then
      echo $((x-1))
    elif [ $m -eq 1 ]
    then
      echo $x
    elif [ $m -eq 2 ]
    then
      echo $((x+1))
    elif [ $m -ge 3 ]
    then
      echo $(( (m-1) * $(calculeaza $((m-1))) - (m-2) * $(calculeaza $((m-2))) + $(calculeaza $((m-3))) ))
          #sau varianta desfasurata:
          #t1=$(calculeaza $((m-1)))
          #t2=$(calculeaza $((m-2)))
          #t3=$(calculeaza $((m-3)))
          #echo $(( (m-1) * $t1 - (m-2) * $t2 + $t3 ))
    fi
}

calculeaza $n
