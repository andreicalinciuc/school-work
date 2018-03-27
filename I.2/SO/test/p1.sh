#!/bin/bash

#######################################################################################################
# Enunt prima problema:
#
# a) Cum se numeste comanda folosita pentru a numara linii, cuvinte, sau bytes pentru un anumite fisier
#    si care este optiunea ce specifica numararea liniilor (cate caractere newline sunt in fisier)?
# b) Sa se scrie linia de comanda pentru a afisa doar numarul de linii din fisierul /etc/passwd.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
#######################################################################################################

a)
wc
wc -l


b)
cat /etc/passwd | wc -l
