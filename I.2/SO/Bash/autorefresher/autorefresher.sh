#!/bin/bash

URL="https://profs.info.uaic.ro/~vidrascu/SO/index_news.html"
username="so2018"
password="1+0=10"
mails="vladuz98@gmail.com vlad.bujoreanu@info.uaic.ro"
subject="[AutoRefresher] Pagina de la SO a fost modificată"
message="Pagina de la SO a fost modificată. Există posibilitatea să se fi afișat rezultatele!"
interval="60" #seconds

while [ 1 ]
do
  mv new.html old.html
  wget -q --user "$username" --password "$password" "$URL" -O new.html
  if [[ -f old.html && -f new.html && $(cat old.html | wc -c) -ne 0 && $(cat new.html | wc -c) -ne 0 && $(diff old.html new.html -q | wc -c) -ne 0 ]]
  then
    echo "$message" | mail -s "$subject" "$mails"
    exit
  fi
  sleep $interval
done

#nohup ./autorefresher.sh > /dev/null 2>&1 &
