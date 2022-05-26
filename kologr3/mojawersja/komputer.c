#include <stdio.h>
#include <string.h>
#include "komputer.h"


Komputer makeKomputer(const char *nazwa, double cena, int ileMaLat, bool czyLaptop) {
    Komputer tmp;
    strcpy(tmp.nazwa,nazwa);
    tmp.cena=cena;
    tmp.ileMaLat=ileMaLat;
    tmp.czyLaptop=czyLaptop;
    return tmp;
}

Komputer makeKomputerCopy(const Komputer *komp) {
    Komputer kopia;
    strcpy(kopia.nazwa,komp->nazwa);
    kopia.cena=komp->cena;
    kopia.ileMaLat=komp->ileMaLat;
    kopia.czyLaptop=komp->czyLaptop;
    return kopia;
}

void show(const Komputer *komp) {

    printf("\nnazwa komputera: %s", komp->nazwa);
    printf("\ncena: %lf", komp->cena);
    printf("\nile ma lat: %d", komp->ileMaLat);
    if(komp->czyLaptop)
        printf("\nLaptop");
    else
        printf("\nStacjonarny");
/* Funkcja powinna wyswietlac dane w nastepujacy sposob

  Nazwa komputera: Dell.
  Cena: 1234.000000.
  Ile ma lat: 23
  Laptop.

  lub gdy nie jest to laptop:

  Nazwa komputera: Dell.
  Cena: 1234.000000.
  Ile ma lat: 23
  Stacjonarny.
*/
}

void zmiennazwe(Komputer *komp, const char *nazw)
{
    strcpy(komp->nazwa,nazw);
}

void postarz(Komputer *komp, int lata) {

    komp->ileMaLat=komp->ileMaLat+lata;
}


