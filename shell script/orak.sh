#!/bin/bash

<<comment
3.
Készítsünk shell szkriptet orak.sh néven amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
A szöveges fájlban a tanárok óráit jegyezzük fel. Soronként a tanár neve, és naponként az órái találhatóak, vesszővel elválasztva egymástól.
pl. Gipsz Jakab, H 1 3 4 5, K 1 2 3, Sz, Cs 3 4 5 6 7, P 1 2 3 4
a) Adjuk meg azt a tanár(oka)t, aki(k)nek nincs szerdán órája - ha mindenkinek van, írjuk ki "NINCS"
b) Adjuk meg tanáronként, hogy kinek hány órája van.
c) Olvassunk be egy napot és adjuk meg, kinek nincs aznap első órája.

Gipsz Jakab, H 1 3 4 5, K 1 2 3, Sz 1, Cs 3 4 5 6 7, P 1 2 3 4
Alma Máté, H 1 3 4 5, K 1 2 3, Sz, Cs, P 1 2 3 4
Körte Cicus, H 1 3 4 5, K 1 2 3, Sz 1 2 3 4, Cs 3 4 5 6 7, P 1 2 3 4

comment

emptyWed=""
howMany=""
inputCell=0
noFirst=""
read -p "nap: " input

if [ $input == "H" ]; then
    inputCell=2
elif [ $input == "K" ]; then
    inputCell=3
elif [ $input == "Sz" ]; then
    inputCell=4
elif [ $input == "Cs" ]; then
    inputCell=5
elif [ $input == "P" ]; then
    inputCell=6
fi


while read line
do
    name=`echo $line | cut -f 1 -d ,`
    wed=`echo $line | cut -f 4 -d ,`
    totalLessons=`echo $line | grep -o "[0-9]" | wc -l`
    if [[ ! $wed =~ [0-9] ]]; then
        emptyWed+="$name,"
    fi
    howMany+="$name:$totalLessons;"
    day=`echo $line | cut -f $inputCell -d ,`
    if [[ ! "$day" == *"1"* ]]; then
        noFirst+="$name,"
    fi
done < $1

echo "a:"
echo $emptyWed
echo "b:"
echo $howMany
echo "c:"
echo $noFirst