# drijfvuil_labeler
(basis) Qt applicatie om drijfvuilfotos te genereren en labelen

# werkwijze

## Genereren van drijfvuilfotos uit de videos
Om van de videos afbeeldingen te maken kun je het script get_images_from_video.sh runnen in de directory waar de videos staan. Dit roept per mp4 bestand het volgende commando aan;

ffmpeg -i \<video-bestand\> -r 1 -f image2 \<format_uitvoerbestand\>.png

waardoor (globaal) per seconde een frame omgezet wordt in een png bestand.

Plaats deze afbeeldingen vervolgens in een centrale map.

## Labelen van de afbeeldingen
Stel in de broncode (in mainwindows.cpp) van drijfvuil_labeler de juiste waarde in voor de constanten;

* AFEELDINGSMAP de locatie waar de originele afbeeldingen staan
* LABEL_DRIJFVUIL_MAP de locatie waar de als drijfvuil geclassificeerde bestanden heen moeten
* LABEL_GEENDRIJFVUIL_MAP de locatie de als NIET drijfvuil geclassificeerde bestanden heen moeten
* IMAGE_WIDTH de breedte van de image die je wilt genereren (200px is nu standaard)
* IMAGE_HEIGHT de hoogte van de image die je wilt genereren (200px is nu standaard)

Bouw en run de applicatie en vermaak je met het invoeren van een aantal labels om het Nautonomous project verder te helpen.

## Who do I talk to

Rob van Putten, rob.van.putten@waternet.nl, breinbaasnl@gmail.com

