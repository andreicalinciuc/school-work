#!/bin/bash

if [ $# -eq 0 ]
then
  path=~
else
  path=$1
fi

if [ ! -d ~/html ]
then
  mkdir ~/html
fi

if [ ! -d ~/html/muzica ]
then
  mkdir ~/html/muzica
fi

echo > ~/html/muzica.html

for f in `find $path -name "*.mp3" | grep -v ~/html/muzica | tr -s ' ' '#'`
do
  f=$(echo $f | tr -s '#' ' ')
  ln -s "$f" ~/html/muzica/"$(basename "$f")"
  echo "<a href=\"muzica/$(basename "$f")\">$(basename "$f" .mp3)</a><br>" >> ~/html/muzica.html
done

chmod 775 ~
chmod 775 ~/html
chmod 775 ~/html/muzica
chmod 774 ~/html/muzica.html
