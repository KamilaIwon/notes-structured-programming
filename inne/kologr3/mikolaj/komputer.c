#include <stdio.h>
#include <string.h>
#include "komputer.h"


Komputer makeKomputer(const char *nazwa, double cena, int ileMaLat, bool czyLaptop) {

    Komputer tmp;
    strcpy(tmp.nazwa,nazwa);
    tmp.cena = cena;
    tmp.ileMaLat = ileMaLat;
    tmp.czyLaptop = czyLaptop;
    return tmp;
}

Komputer makeKomputerCopy(const Komputer *komp) {
    Komputer tmp;
    strcpy(tmp.nazwa,komp->nazwa);
    tmp.cena = komp->cena;
    tmp.ileMaLat = komp->ileMaLat;
    tmp.czyLaptop = komp->czyLaptop;
    return tmp;
}

void show(const Komputer *komp) {
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
    printf("Nazwa komputera: %s\nCena: %.2lf\nIle ma lat: %d\n", komp->nazwa, komp->cena, komp->ileMaLat);
    if(komp->czyLaptop)
        printf("Laptop\n");
    else
        printf("Stacjonarny\n");
}

void postarz(Komputer *komp, int lata) {
    int tmp=komp->ileMaLat;
    komp->ileMaLat+=lata;
    if(1981+(komp->ileMaLat)>2022)
    {
        printf("Wartosc ta przekracza maksymalna liczbe lat! Wartosc nie zostala zmieniona.\n");
        komp->ileMaLat = tmp;
    }
}
//https://github.com/jednach/kolos
