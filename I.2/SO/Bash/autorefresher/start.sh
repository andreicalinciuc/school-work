#!/bin/bash

./clean.sh

ID="0"
mails="censored"
api_key="censored"

let ID++
URL="https://profs.info.uaic.ro/~vidrascu/SO/index_curs.html"
username="so2018"
password="1+0=10"
object="SO Curs"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://profs.info.uaic.ro/~vidrascu/SO/index_labs.html"
username="so2018"
password="1+0=10"
object="SO Laborator"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://sites.google.com/site/fiicoursepoo/cursuri-2018"
username=""
password=""
object="POO Curs"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object"> /dev/null 2>&1 &

let ID++
URL="https://sites.google.com/site/fiicoursepoo/laboratoare-2018"
username=""
password=""
object="POO Laborator"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object"> /dev/null 2>&1 &

let ID++
URL="https://sites.google.com/site/fiicoursepa/curriculum"
username=""
password=""
object="PA Curs"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://sites.google.com/site/fiicoursepa/seminarii"
username=""
password=""
object="PA Seminar"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://profs.info.uaic.ro/~olariu/curent/PS/PS.html"
username=""
password=""
object="PS Curs & Laborator"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://profs.info.uaic.ro/~olariu/curent/PS/files/"
username=""
password=""
object="PS files"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

let ID++
URL="https://profs.info.uaic.ro/~fltiplea/AFCS/AFCSCourseNotes.html"
username=""
password=""
object="FAI Curs"
nohup ./autorefresher.sh "$ID" "$URL" "$username" "$password" "$mails" "$api_key" "$object" > /dev/null 2>&1 &

echo "Script started successfully."
