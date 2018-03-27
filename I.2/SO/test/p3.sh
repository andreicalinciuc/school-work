#!/bin/bash

#######################################################################################################
# Enunt a treia problema:
#
# Sa se scrie un script bash care dat un director ca parametru, il parcurge recursiv si afiseaza
# acel subdirector care are cele mai multe fisiere de tip obisnuit (regular) goale.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
#######################################################################################################

dirnumber=0
maxi=-1

parcurge()
{
    let dirnumber++
    goale=0

    for f in `ls -A $1`
    do
      if [[ -f $1/$f && $(cat $1/$f | wc -c) -eq 0 ]]
      then
        let goale++
      fi
    done

    if [[ $goale -gt $maxi && $dirnumber -ne 1 ]] #enuntul spune doar pentru subdirectoare
    then
      maxi=$goale
      result=$1
    fi

    for f in `ls -A $1` #implementam functia prin doua bucle for pentru numarare corecta
    do
      if [ -d $1/$f ]
      then
      parcurge $1/$f
      fi
    done
}

parcurge $1

echo $result
