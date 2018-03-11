#!/bin/bash

string1=$(cat /etc/passwd | grep :$1: | cut -f 1 -d ':')
string2=$(id $string1 | cut -f 3 -d ' ' | cut -f 2 -d '=')
string1=$(echo $string1 | tr -s '.' ' ' | tr -s [:lower:] [:upper:])

echo $string1 $string2
