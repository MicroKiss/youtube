<#
1.
Készítsünk powershell szkriptet munkahely.ps1 néven, amely egy argumentumban megadott szöveges adatfájlt dolgoz fel és választ ad a megadott kérdésekre!
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
#>


$noAssaults="";
$guards=0;
$max=0;
$maxAssaults="";

$lines = cat $args[0];
foreach($line in $lines)
{
    $name=$line.Split(",")[0];
    $address=$line.Split(",")[1];
    $count=[int]$line.Split(",")[2];
    $guard=[int]$line.Split(",")[3];

    if ($count -eq 0){
        $noAssaults+= "$name,";
    }
    $guards+=$guard;

    if ($count -gt $max){
        $max = $count;
        $maxAssaults="$name,$address,"
    } elseif ($count -eq $max) {
        $maxAssaults+="$name,$address,"
    }

}
echo "a";
if ($noAssaults) {
    echo $noAssaults;
} else {
    echo "NINCS";
}
echo "b";
echo $guards;
echo "c";
echo $maxAssaults;