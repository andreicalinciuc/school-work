#!/bin/bash

ID=$1
URL=$2
username=$3
password=$4
mails=$5
api_key=$6
object=$7
subject="[AutoRefresher] Pagina de la $object a fost modificata"
message="Pagina de la $object a fost modificata.\n$URL"
interval="300" #seconds

while [ 1 ]
do
  mv new$ID.html old$ID.html > /dev/null 2>&1
  wget -q --user "$username" --password "$password" "$URL" -O new$ID.html
  if [[ -f old$ID.html && -f new$ID.html ]]
  then
    if [[ $(cat old$ID.html | wc -c) -ne 0 && $(cat new$ID.html | wc -c) -ne 0 && $(diff old$ID.html new$ID.html -q | wc -c) -ne 0 ]]
    then
      echo -e "$message" | mail -s "$subject" "$mails"
      curl -X POST -H "Content-Type: application/json" -d '{ "api_key":"'"$api_key"'", "message":"'"$message"'"}' "https://www.nimrod-messenger.io/api/v1/message"
    fi
  fi
  sleep $interval
done
