#!/bin/bash

<<comment
1.
Készítsünk shell szkriptet munkahely.sh néven, amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
A szöveges fájlban az munkahelyi erőszakkal kapcsolatban tárolunk adatokat. Soronként az munkahely neve, címe, az egy évben előforduló erőszakos cselekmények száma, biztonsági őrök száma - vesszővel elválasztva.
pl. Fűzfa fütyülő kft, 1111 Budapest Ökör utca 6, 5, 3
a) Adjuk meg azokat az munkahelyeket, ahol egyetlen erőszakos cselekedetet se jelentettek, ha nincs ilyen, írjuk ki, hogy "NINCS"
b) Számoljuk össze, hány biztonsági őr van összesen a megadott adatfájl szerint!
c) Hol található a legtöbb erőszakot jelentő munkahely, adjuk meg a nevét/nevüket és címét/címüket!

Fűzfa fütyülő kft, 1111 Budapest Ökör utca 6, 5, 3
Mogyoró morzsoló1 kft, 1111 Budapest Ököl utca 2, 200, 3
Mogyoró morzsoló2 kft, 1111 Budapest Ököl utca 2, 200, 3
Cipőfűző gyár kft, 1111 Budapest Öröm utca 4, 0, 0
Cipőfűző gyár2 kft, 1111 Budapest Öröm utca 4, 0, 0

comment

noAssaults=""
guards=0
maxAssults=""
max=0

while read line
do
    name=`echo $line | cut -f 1 -d ,`
    address=`echo $line | cut -f 2 -d ,`
    count=`echo $line | cut -f 3 -d ,`
    guard=`echo $line | cut -f 4 -d ,`
    if [[ $count == " 0" ]] ; then
        noAssaults+="$name,"
    fi
    guards=$(($guards + $guard))

    if [ $count -gt $max ]; then
        max=$count
        maxAssults="$name:$address"
    elif [ $count -eq $max ]; then
        maxAssults+=";$name:$address"
    fi

done < $1

echo "a:"
if [ -z "$noAssaults" ] ; then
    echo "NINCS"
else
    echo "${noAssaults::-1}"
fi
echo "b:"
echo $guards
echo "c:"
echo $maxAssults
