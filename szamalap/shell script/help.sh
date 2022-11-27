#!/bin/bash

# testfile sorainak feldolgozása
while read line
do
# line változóban mindig az aktuális sor van, ha a sorban vesszővel elválasztott
# értékek vannak, kinyerhetjük bárhányadik értéket a cut segítségével
# pl. minden sorból a 2. érték kivágása és megjelenítése:

echo $line | cut -f 2 -d ,

# Ha nem csak megjeleníteni szeretnénk, hanem tovább dolgozni egy értékkel,
# el is menthetjük változóba

valtozo=`echo $line | cut -f2 -d,`

echo A valtozo értéke is $valtozo

done < input1