#ifndef KOMPUTER_H
#define KOMPUTER_H
#define MAX_LEN 50
#include <stdbool.h>

/*
Zdefiniuj stałą MAX_LEN równą 50, a następnie zdefiniuj C-strukturę Komputer o polach nazwa typu char[MAX_LEN-1], cena typu double, ileMaLat typu int oraz czyLaptop typu bool. Zdefiniuj następujące funkcje:
*/
typedef struct student{
    char nazwa[MAX_LEN-1];
    double cena;
    int ileMaLat;
    bool czyLaptop
}student;
// Tworzy strukturę Komputer
Komputer makeKomputer(const char *nazwa, double cena, int ileMaLat, bool czyLaptop);

// Tworzy kopię komputera
Komputer makeKomputerCopy(const Komputer *komp);

// Postarza dany komputer o zadaną liczbę lat
void postarz(Komputer *komp, int lata);

// Wyświetla dane komputera
void show(const Komputer *komp);

#endif
