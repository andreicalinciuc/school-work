#!/bin/bash
#######################################################################################################
# Enunt a doua problema:
#
# Scrieti comanda inlantuita ce va scrie, in fisierul users5.txt, doar numele de utilizatori din ultimele 
# 5 linii ale fisierului /etc/passwd, numele celor 5 utilizatori fiind afisate in ordine descrescatoare.
#
# NOTA: pastrati enuntul in acest comentariu si scrieti rezolvarea mai jos.
#######################################################################################################

cat /etc/passwd | tail -n 5 | cut -f 1 -d ':' | sort -r > users5.txt
