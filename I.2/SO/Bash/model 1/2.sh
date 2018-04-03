#!/bin/bash

###############################################################################$
# Enunt a doua problema:
#
# Sa se scrie comanda inlantuita care, printr-o parcurgere recursiva incepand d$
# utilizatorului curent, scrie in fisierul info_fisiere.txt cate o linie separa$
# dimensiunea in octeti, permisiunile in octal, momentul ultimei modificari si $
# al directorului) intalnit in urma parcurgerii.
# Afisarea se va face sortat crescator dupa dimensiunea fisierelor.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
# VLAD BUJOREANU
###############################################################################$

find . -type f -printf "%p;%s;%m;%t\n" | sort -n -k 2 -t ';' | tr ';' ' ' > info_fisiere.txt
