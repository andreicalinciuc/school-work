#!/bin/bash

./stop.sh

rm old* > /dev/null 2>&1
return_value1=$?
rm new* > /dev/null 2>&1
return_value2=$?

if [[ $return_value1 -eq 0 && $return_value2 -eq 0 ]]
then
  echo "Script cleaned successfully."
fi
