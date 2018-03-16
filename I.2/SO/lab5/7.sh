#!/bin/bash

parcurge()
{
    for f in *.sh
    do
      echo $f
      echo $(cat $f | grep '#')
    done
}

parcurge $1
