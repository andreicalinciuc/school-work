#!/bin/bash

killall autorefresher.sh > /dev/null 2>&1
return_value1=$?
killall sleep > /dev/null 2>&1
return_value2=$?

if [[ $return_value1 -eq 0 && $return_value2 -eq 0 ]]
then
  echo "Script stopped successfully."
fi
