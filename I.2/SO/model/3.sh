#shebang gresit: -bash: ./script.sh: /bin/noshell: bad interpreter: No such file or directory

#!/bin/bash
A=$#; B=0;
for a in $(ls /bin/*)
do
  [ -f $a ] && let B++
done
echo $B, $A
