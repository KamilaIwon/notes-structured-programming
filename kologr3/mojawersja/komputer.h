#ifndef KOMPUTER_H
#define KOMPUTER_H
#define MAX_LEN 50
#include <stdbool.h>

/*
Zdefiniuj sta³¹ MAX_LEN równ¹ 50, a nastêpnie zdefiniuj C-strukturê Komputer o polach nazwa typu char[MAX_LEN-1], cena typu double, ileMaLat typu int oraz czyLaptop typu bool. Zdefiniuj nastêpuj¹ce funkcje:
*/
typedef struct Komputer{
    char nazwa[MAX_LEN-1];
    double cena;
    int ileMaLat;
    bool czyLaptop;
}Komputer;

// Tworzy strukturê Komputer
Komputer makeKomputer(const char *nazwa, double cena, int ileMaLat, bool czyLaptop);

// Tworzy kopiê komputera
Komputer makeKomputerCopy(const Komputer *komp);

void zmiennazwe(Komputer *komp, const char *nazw);

// Postarza dany komputer o zadan¹ liczbê lat
void postarz(Komputer *komp, int lata);

// Wyœwietla dane komputera
void show(const Komputer *komp);

#endif


