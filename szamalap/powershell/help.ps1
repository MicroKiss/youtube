# testfile sorainak feldolgozása
$lines = cat testfile;
foreach($line in $lines)
{
    # line változóban mindig az aktuális sor van, ha a sorban vesszővel elválasztott
    # értékek vannak, kinyerhetjük bárhányadik értéket a $line.Split(",") segítségével
    # pl. minden sorból a 2. érték kivágása és megjelenítése:
    $line.Split(",")[1]; #Figyeljünk az index-re. 2. érték indexe 1, mert 0-tól indexelünk

    # Ha nem csak megjeleníteni szeretnénk, hanem tovább dolgozni egy értékkel,
    # el is menthetjük változóba
    $valtozo=$line.Split(",")[1];

    echo "A valtozo értéke is $valtozo" 
    
    #Figyeljünk rá, hogy alapból szövegeket olvasunk be. Ha számként szeretnénk dolgozni egy változóval (pl. műveleteket végezni vele), akkor így kezelhetjük számként: [int]$valtozo  

}

#Ezen felül szükség lehet még elágazásra a beadandóban
#Elágazás powershell-ben:

$szam = 4;

if ($szam -eq 4) {
    echo "A szám 4";
} elseif ($szam -eq 5) {
    echo "A szám 5";
} else {
    echo "A szám nem 4 vagy 5.";
}