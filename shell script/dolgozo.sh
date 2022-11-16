#!/bin/bash

<<comment
2.
Készítsünk shell szkriptet dolgozo.sh néven amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
A szöveges fájlban a dolgozók feladatait jegyezzük fel. Soronként a dolgozó neve, besorolása, munkaköre(i)található
pl. Gipsz Jakab, Pultos, éjszakás, 4 órás ügyelet 
Csupa Fül, mesterszakács, menü tervezés, konyha irányítás, főzés
a) Adjuk meg azokat a dolgozókat,akik Pultos besorolásban vannak (csak a neveket), ha nincs ilyen, írjuk ki "NINCS"
b) Kiknek van legalább 3 munkaköre van? (neveket)
c) Olvassunk be egy besorolást és adjuk meg hányan vannak ebben a pozícióban.

Gipsz Jakab, Pultos, éjszakás, 4 órás ügyelet
Gipsz Jakab2, Pultos, éjszakás, 4 órás ügyelet
Csupa Fül1, mesterszakács, menü tervezés, konyha irányítás, főzés
Csupa Fül2, mesterszakács, menü tervezés, konyha irányítás, főzés
Csupa Fül3, mesterszakács, menü tervezés, konyha irányítás, főzés, takarítás
Almási Péter, haszonleső, cigiszünetre járás, hűtő nyitogatás, kontroller tesztelés, álmodozás
comment

bartenders=""
atLeast3=""
inputFound=0
read -p "Keresett besorolás: " input


while read line
do
    name=`echo $line | cut -f 1 -d ,`
    title=`echo $line | cut -f 2 -d ,`
    thirdR=`echo $line | cut -f 5 -d ,`

    if [[ $title == " Pultos" ]]; then
        bartenders+="$name,"
    fi

    if [ ! -z "$thirdR" ] ; then
        atLeast3+=$name,
    fi

    if [[ $title == " $input" ]]; then
        inputFound=$(($inputFound + 1))
    fi


done < $1

echo "a:"
if [ -z "$bartenders" ] ; then
    echo "NINCS"
else
    echo "${bartenders::-1}"
fi
echo "b:"
echo $atLeast3
echo "c:"
echo $inputFound