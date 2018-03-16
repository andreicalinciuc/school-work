parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        for ((i=1; i<=$2; i++))
        do
          echo -n -----
        done
        echo $f
        parcurge $1/$f $(($2+1))
      elif [ -f $1/$f ]
      then
        for ((i=1; i<=$2; i++))
        do
          echo -n -----
        done
        echo $f
      fi
    done
}

parcurge ~ 0
