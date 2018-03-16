directoare=0
fisiere_ascunse=0
symlinks=0

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
        let directoare++
        parcurge $1/$f
      elif [[ -f $1/$f && $f = .* ]]
      then
        let fisiere_ascunse++
      elif [ -L $1/$f ]
      then
        let symlinks++
      fi
    done
}

parcurge $path

echo $directoare $fisiere_ascunse $symlinks
