#!/bin/bash

###############################################################################$
# Enunt a doua problema:
#
# Sa se scrie comanda inlantuita care afiseaza numele si UID-ul pentru utilizat$
# in top10 al celor mai mari UID-uri din sistem.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
# VLAD BUJOREANU
###############################################################################$

cat /etc/passwd | cut -f 1,3 -d ':' | sort -n -r -k 2 -t ':' | head -n 10 | tr ':' ' ' | tr '.' ' ' | tr [:lower:] [:upper:]
