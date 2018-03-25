#!/bin/bash
PATH=/usr/bin:/bin

s=0
echo > tokilari.txt

if [[ $(who | grep vlad.bujoreanu | wc -c) != 0 ]]
then echo Vlad Bujoreanu >> tokilari.txt; let s++
fi

if [[ $(who | grep viorel.iordache | wc -c) != 0 ]]
then echo Viorel Iordache >> tokilari.txt; let s++
fi

if [[ $(who | grep florin.asavoaie | wc -c) != 0 ]]
then echo Florin Asavoaie >> tokilari.txt; let s++
fi

if [[ $(who | grep alexandra.birzu | wc -c) != 0 ]]
then echo Alexandra Birzu >> tokilari.txt; let s++
fi

if [[ $(who | grep teodora.calarasu | wc -c) != 0 ]]
then echo Teodora Calarasu >> tokilari.txt; let s++
fi

if [[ $(who | grep laura.velicescu | wc -c) != 0 ]]
then echo Laura Velicescu >> tokilari.txt; let s++
fi

if [[ $(who | grep dan.blanaru | wc -c) != 0 ]]
then echo Dan Blanaru >> tokilari.txt; let s++
fi

if [[ $(who | grep teodor.paduraru | wc -c) != 0 ]]
then echo Teodor Paduraru >> tokilari.txt; let s++
fi

if [[ $(who | grep dragos.ursu | wc -c) != 0 ]]
then echo Dragos Ursu >> tokilari.txt; let s++
fi

if [[ $(who | grep gabriel.pantiru | wc -c) != 0 ]]
then echo Gabriel Pantiru >> tokilari.txt; let s++
fi

if [[ $(who | grep andrei.tocu | wc -c) != 0 ]]
then echo Andrei Paul Tocu >> tokilari.txt; let s++
fi

if [[ $(who | grep vlad.cirstean | wc -c) != 0 ]]
then echo Vlad Bogdan Cirstean >> tokilari.txt; let s++
fi

if [[ $(who | grep marian.cretu | wc -c) != 0 ]]
then echo Marian Codrin Cretu >> tokilari.txt; let s++
fi

if [[ $(who | grep george.popa | wc -c) != 0 ]]
then echo George Popa >> tokilari.txt; let s++
fi

if [[ $(who | grep rares.munteanu | wc -c) != 0 ]]
then echo Rares Munteanu >> tokilari.txt; let s++
fi

if [[ $(who | grep petru.gorea | wc -c) != 0 ]]
then echo Adrian Gorea >> tokilari.txt; let s++
fi

if [[ $(who | grep andra.paduraru | wc -c) != 0 ]]
then echo Andra Elena Paduraru >> tokilari.txt; let s++
fi

if [[ $(who | grep andrei.gafita | wc -c) != 0 ]]
then echo Andrei Gafita >> tokilari.txt; let s++
fi

if [[ $(who | grep alexandru.teodorescu | wc -c) != 0 ]]
then echo Alexandru Teodorescu >> tokilari.txt; let s++
fi

if [[ $(who | grep cristian.asoltanei | wc -c) != 0 ]]
then echo Cristian Asoltanei >> tokilari.txt; let s++
fi

if [[ $(who | grep cristina.tesu | wc -c) != 0 ]]
then echo Cristina Tesu >> tokilari.txt; let s++
fi

if [[ $(who | grep iulian.guraliuc | wc -c) != 0 ]]
then echo Iulian Guraliuc >> tokilari.txt; let s++
fi

if [[ $(who | grep maria.balan | wc -c) != 0 ]]
then echo Maria Balan >> tokilari.txt; let s++
fi

if [[ $(who | grep gheorghita.dascalita | wc -c) != 0 ]]
then echo Gheorghita Dascalita >> tokilari.txt; let s++
fi

if [[ $(who | grep felix.hugeanu | wc -c) != 0 ]]
then echo Felix Hugeanu >> tokilari.txt; let s++
fi

if [[ $(who | grep radu.zbant | wc -c) != 0 ]]
then echo Radu Andrei Zbant >> tokilari.txt; let s++
fi

if [[ $(who | grep alexandru.denis.chiparus | wc -c) != 0 ]]
then echo Alexandru Denis Chiparus >> tokilari.txt; let s++
fi

if [[ $(who | grep tudor.manoleasa | wc -c) != 0 ]]
then echo Tudor Manoleasa >> tokilari.txt; let s++
fi

if [[ $(who | grep cristian.corban | wc -c) != 0 ]]
then echo Cristian Corban >> tokilari.txt; let s++
fi

if [[ $(who | grep rares.vlaiduc | wc -c) != 0 ]]
then echo Rares Vlaiduc >> tokilari.txt; let s++
fi

if [[ $(who | grep emilian.aboaice | wc -c) != 0 ]]
then echo Emilian Aboaice >> tokilari.txt; let s++
fi

sort tokilari.txt -o tokilari.txt

echo $s colleagues are suffering right now:
cat tokilari.txt
