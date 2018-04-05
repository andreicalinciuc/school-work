#!/bin/bash

#nohup ./autorefresher.sh > /dev/null 2>&1 &

URL="https://profs.info.uaic.ro/~vidrascu/SO/index_news.html"
user="so2018"
password="1+0=10"
mails="vladuz98@gmail.com"

while [ 1 ]
do
  mv new.html old.html
  wget -q --user "$user" --password "$password" "$URL" -O new.html
  if [[ -f old.html && -f new.html && $(cat old.html | wc -c) != 0 && $(cat new.html | wc -c) != 0 && $(diff new.html old.html -q | wc -c) != 0 ]]
  then
    echo "Pagina de la SO a fost modificată. Există posibilitatea să se fi afișat rezultatele!" | mail -s "[AutoRefresh] Pagina de la SO a fost modificată" "$mails"
    exit
  fi
  sleep 60
done

