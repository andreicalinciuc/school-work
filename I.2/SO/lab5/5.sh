lines=0
characters=0

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        parcurge $1/$f
      elif [ -f $1/$f ]
      then
        let lines+=$(cat $1/$f | wc -l)
        let characters+=$(cat $1/$f | wc -m)
      fi
    done
}

parcurge $path

echo $lines $characters
