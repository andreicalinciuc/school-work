#!/bin/bash

if [ ! -d ~/html ]
then
  mkdir ~/html
fi

echo > ~/html/imagini.html

for f in `find ~/html \( -name "*.jpg" -or -name "*.gif" -or -name "*.png" \) -printf "%p:%t\n" | sort -k 2 -t ':' | cut -f 1 -d ':'`
do
  echo "<a href="${f#/fenrir/studs/vlad.bujoreanu/html/}">$(basename $f)</a><br>" >> ~/html/imagini.html
done

chmod 774 ~/html/imagini.html
