## 23. Verwijder de werkbestanden tmp*.txt, indien die reeds zouden bestaan. Voer hiertoe het commando rm -f tmp*.txt uit. Voer daarna achtereenvolgens deze opdrachten uit:

```
• du /etc  
• du /var > tmp.txt  
• du /etc 1> tmp.txt  
• du /var >> tmp.txt  
• du /etc 1>> tmp.txt  
• > tmp.txt du /etc  
• du /var > tmp1.txt > tmp2.txt 

```

```
man du

du -> estimates file space usage, summarizes disk usage of the set of files, recursively for directories


du /var > tmp.txt

> wordt gebruikt om de ouput van het commando weg te schrijven in het bestand tmp.txt

du /etc 1> tmp.txt 

opnieuw gebruikt maken van > naar dezelfde file overschrijft de inhoud

du /var >> tmp.txt

>> append de ouput van het invoer commmando in het uitvoerbestand

> tmp.txt du /etc 

overschrijf de inhoud van tmp.txt met de uitvoer van het commando du /etc


du /var > tmp1.txt > tmp2.txt 

output van du /var wordt weggeschreven in tmp2.txt, tmp1.txt wordt aangemaakt maar leeg. bij output redirection wordt er enkel in de laatste file weggeschreven, de andere files worden ook aangemaakt, maar leeg


Specialleke output wegschrijven naar 2 verschillende files in 1 keer: 

cat /etc/passwd | tee temp > t.txt


```

## 24. Verwijder eerst het werkbestand tmp.txt. Voer daarna volgende opdrachten uit:

```
• set -o noclobber  
• echo test > tmp.txt  
• echo test > tmp.txt  
• echo test >| tmp.txt  
• set +o noclobber  
• echo test > tmp.txt  
• set -C  # hoofdletter verplicht!  
• echo test > tmp.txt
• echo test >| tmp.txt  
• set +C  
• echo test > tmp.txt

```


```
set -o noclobber == set -C

Gaat ervoor zorgen dat > niet meer gebruikt kan worden om bestaande files te overschrijven, wel aanmaken van nieuwe files. Om toch te kunnen overschrijven moet er gebruik gemaakt worden van >|
```

## 25. Foutmeldingen worden via een apart kanaal weergegeven, zodat er onderscheid gemaakt kan worden tussen gewone uitvoer en foutteksten. Voer achtereenvolgens volgende commando's uit en controleer de inhoud van het bestanden tmp*.txt:

```
• du /etc  
• du /etc 1>tmp.txt  
• du /etc 2>>tmp.txt  
• du /etc >tmp1.txt 2>tmp2.txt

de 2 optie wordt gebruikt om de errors weg te schrijven naar de file en de ouput wordt gewoon om het scherm weergegeven


du /etc >tmp1.txt 2>tmp2.txt

uitvoer wordt in het eerste bestand gestopt, errors in het 2de bestand
```


## 26. Je kunt ook omleiden naar de vuilnisbak (/dev/null). Verklaar de uitvoer bij uitvoering van volgende opdrachten: 

```
• du /etc > /dev/null  
• cat /dev/null  
```



```
du /proc                     |   2>&1                    |    >t.txt
                             |                           |
1 ->scherm(gebufferd)        |   1->scherm (gebufferd)   |     1->t.txt
2 ->scherm (niet gebufferd)  |   2->scherm (gebufferd)   |     2-> scherm(gebufferd)
                             |                           |


&1 betekend -> standaarduitvoer 1 en niet file met naam 1

Van niet gebufferde uitvoer kan gebufferde uitvoer gemaakt worden om door een pipe te suten met 2>&1 

Enkel gebufferde uitvoer kan door een pipe worden gehaald!

child1 | chfild2 | child3 .......

IPC dmv pipe |

Als je gebruik maakt van een pipe, maak je altijd 2 kind processen aan. 1 voor wat links van de verticale streep staat en 1 voor wat rechts staat. En de pipe dient voor interproces communicatie
```


### Opbouw van het /etc/passwd bestand:

```
user:x:uid:gid:GECOS:homedir:/bin/bash

->laatste is proces dat moet worden opgestart als een user inlogd, bij een interactieve user is dit dus een bash proces


/etc/group/ 

naam:x:gid:secundaire leden

/etc/shadow

->hierin wordt het geëncrypteerde wachtwoord van de gebruiker bijgehouden + extra data, wanneer is het ww het laatst gewijzigd? Hoe lang heb je nog om het te wijzigen? ... enz.

UPG: User Private Groups

```

### Vraag 43

```
Sorteer het passwd-bestand met behulp van het sort commando met het nummer van de primatire sleutel als groep:


sort -d -t: -k4,4 /etc/passwd > ~/passwd

Doe nu hetzelfde met het group bestand:

sort -d -t: -k3,3 /etc/group > ~/group

```

### Vraag 44


```
join -t: -1 4 -2 3 -o "1.3 1.1 2.1" passwd group

-t separator teken

-1 eerste bestand 4 de kolom
-2 tweede bestand 3de kolom

-o formaat "bestand.kolom, bestand.kolom, ..."


In 1 commando: next level:

join -t: -1 4 -2 3 -o "1.3 1.1 2.1" <(sort -d -t: -k4,4 /etc/passwd) <(sort -d -t: -k3,3 /etc/group)


```

### vraag 46

```
cut passwd -d ':' -f 1
```

### vraag 47

```
cat /etc/passwd | tee temp >> t.txt

```

### vraag 47

```
cut -d : -f1 passwd | tee -a test.txt
```

### vraag 48

```
find /etc -type f -name 'pass*'
```

### vraag 49

```
find -L /etc -name 'sh*'
```


### vraag 50

```
find /usr -size +1M -printf "%s %p\n"
```

## 51

```
find ~ -type f -mtime -14 -printf "%t %p \n" 
```


## 52

```
find / -type f -name "*.h" -printf "%h \n" | sort | uniq


find / -type d 2>&1> /dev/null | cut -d ‘ -f 2 | cut -d ’ -f 1
```

## 53

```
find / -type d 2>&1> /dev/null | cut -d ‘ -f 2 | cut -d ’ -f 1
```






