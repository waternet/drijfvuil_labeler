# drijfvuil_labeler
(basis) Qt applicatie om drijfvuilfotos te genereren en labelen

![alt tag](https://github.com/waternet/drijfvuil_labeler/blob/master/qdrijfvuil.png)

# werkwijze

## Genereren van drijfvuilfotos uit de videos
Om van de videos afbeeldingen te maken kun je het script get_images_from_video.sh runnen in de directory waar de videos staan. Dit roept per mp4 bestand het volgende commando aan;

ffmpeg -i \<video-bestand\> -r 1 -f image2 \<format_uitvoerbestand\>.png

waardoor (globaal) per seconde een frame omgezet wordt in een png bestand.

Plaats deze afbeeldingen vervolgens in een centrale map.

## Labelen van de afbeeldingen
Als je de applicatie voor het eerst uitvoert kun je via het menu Opties | Instellingen de paden naar de juiste mappen instellen. Let op de volgende logica

* Locatie ruwe bestanden verwijst naar de plek waar de uit de videomateriaal gegenereerde afbeeldingen staan
* Locatie drijfvuil foto's verwijst naar de plek waar de als drijfvuil geclassificeerde foto's opgeslagen worden
* Locatie NIET-drijfvuil foto's verwijst naar de plek waar de als NIET drijfvuil geclassificeerde foto's opgeslagen worden

**NB** je kunt toetsen 1 (wel drijfvuil), 2 (niet bruikbaar) en 3 (geen drijfvuil) als sneltoetsen gebruiken.. wel zo handig.

**NB** heb je iets fout gelabeled haal m dan snel weg uit de map waar ie ingekomen is

**NB** de verhouding wel drijfvuil / geen drijfvuil is al snel 1 op de 50.. don't worry, later worden de classes gebalanceerd dus gewoon doorgaan!

## Who do I talk to

Rob van Putten, rob.van.putten@waternet.nl, breinbaasnl@gmail.com

