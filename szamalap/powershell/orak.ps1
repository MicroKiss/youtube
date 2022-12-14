<#
3.
Készítsünk powershell szkriptet orak.ps1 néven amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
A szöveges fájlban a tanárok óráit jegyezzük fel. Soronként a tanár neve, és naponként az órái találhatóak, vesszővel elválasztva egymástól.
pl. Gipsz Jakab, H 1 3 4 5, K 1 2 3, Sz, Cs 3 4 5 6 7, P 1 2 3 4
a) Adjuk meg azt a tanár(oka)t, aki(k)nek nincs szerdán órája - ha mindenkinek van, írjuk ki "NINCS"
b) Adjuk meg tanáronként, hogy kinek hány órája van.
c) Olvassunk be egy napot és adjuk meg, kinek nincs aznap első órája.

Gipsz Jakab, H 1 3 4 5, K 1 2 3, Sz 1, Cs 3 4 5 6 7, P 1 2 3 4
Alma Máté, H 1 3 4 5, K 1 2 3, Sz, Cs, P 1 2 3 4
Körte Cicus, H 1 3 4 5, K 1 2 3, Sz 1 2 3 4, Cs 3 4 5 6 7, P 1 2 3 4
#>


$emptyWeds="";
$howMany="";
$noFirst="";

echo "milyen napra vagy kivancsi";
$day=Read-Host;
$inputCell=0;
if ($day -eq "H") {
    $inputCell=1;
} elseif ($day -eq "K") {
    $inputCell=2;
} elseif ($day -eq "Sz") {
    $inputCell=3;
} elseif ($day -eq "Cs") {
    $inputCell=4;
} elseif ($day -eq "P") {
    $inputCell=5;
}

$lines = cat $args[0];
foreach($line in $lines)
{
    $name=$line.Split(",")[0];
    $wed=$line.Split(",")[3];

    if ($wed -eq " Sz") {
        $emptyWeds+="$name,";
    }

    $totalLessons = ($line.ToCharArray() | Where-Object {$_ -match '[1-9]'} | Measure-Object).Count
    $howMany+="$name,$totalLessons,";

    $dayToFind=$line.Split(",")[$inputCell];
    if (!($dayToFind -match '.*1.*')) {
        $noFirst+="$name,";
    }

}

echo "a";
echo "$emptyWeds";
echo "b";
echo "$howMany";
echo "c";
echo "$noFirst";