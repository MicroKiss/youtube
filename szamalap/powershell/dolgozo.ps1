<#
2.
Készítsünk powershell szkriptet dolgozo.ps1 néven amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
A szöveges fájlban a dolgozók feladatait jegyezzük fel. Soronként a dolgozó neve, besorolása, munkaköre(i)található
pl. Gipsz Jakab, Pultos, éjszakás, 4 órás ügyelet 
Csupa Fül, mesterszakács, menü tervezés, konyha irányítás, főzés
a) Adjuk meg azokat a dolgozókat,akik Pultos besorolásban vannak (csak a neveket), ha nincs ilyen, írjuk ki "NINCS"
b) Kiknek van legalább 3 munkaköre van? (neveket)
c) Olvassunk be egy besorolást és adjuk meg hányan vannak ebben a pozícióban.

Gipsz Jakab, Pultos, éjszakás, 4 órás ügyelet
Gipsz Jakab2, Pultos, éjszakás, 4 órás ügyelet
Csupa Fül1, mesterszakacs, menü tervezés, konyha irányítás, főzés
Csupa Fül2, mesterszakacs, menü tervezés, konyha irányítás, főzés
Csupa Fül3, mesterszakacs, menü tervezés, konyha irányítás, főzés, takarítás
Almási Péter, haszonleso, cigiszünetre járás, hűtő nyitogatás, kontroller tesztelés, álmodozás
#>


$bartenders="";
$atLeastThree="";

echo "milyen besoloralt szamoljunk meg";
$titleToSearch=Read-Host;
$inputFound=0;

$lines = cat $args[0];
foreach($line in $lines)
{
    $name=$line.Split(",")[0];
    $title=$line.Split(",")[1];
    $thirdR=$line.Split(",")[4];

    if ($title -eq " Pultos") {
        $bartenders+="$name,";
    }

    if ($thirdR) {
        $atLeastThree+="$name,"
    }

    if ($title -eq " $titleToSearch") {
        $inputFound++;
    }
}

echo "a";
if ($bartenders) {
    echo  $bartenders;
} else {
    echo "NINCS";
}
echo "b";
echo "$atLeastThree";
echo "c";
echo "$inputFound";