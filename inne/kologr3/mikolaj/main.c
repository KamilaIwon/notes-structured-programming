#include <stdio.h>
#include "komputer.h"
#include <string.h>

bool czyPrawidlowaCena (double cena);
bool czyPrawidlowyWiek (int ileMaLat);

int main(int argc, char *argv[])
{
    // 1) Poproœ u¿ytkownika o wpisanie danych. Zabezpiecz dane! 1981 r. uznaje siê za pocz¹tek ery komputerów IBM PC - komputerów osobistych. Zak³adamy, ¿e cena powinna byæ z zakresu od 0 do 10000 z³. Napisz odpowiednie funkcje sprawdzaj¹ce poprawnoœæ danych.

    char nazwa[MAX_LEN-1];
    printf("Podaj nazwe:\n");
    scanf(" %49[^\n]", nazwa);
    double cena;
    printf("Podaj cene:\n");
    scanf("%lf", &cena);
    if(cena<0 || cena>10000)
            printf("Zla wartosc!\n");
    while(cena<0 || cena>10000)
    {
        printf("Podaj cene:\n");
        scanf("%lf", &cena);
        if(cena<0 || cena>10000)
            printf("Zla wartosc!\n");
    }
    int ileMaLat;
    printf("Podaj ile lat ma komputer:\n");
    scanf("%u", &ileMaLat);
    if(1981+ileMaLat>2022 || ileMaLat<0)
    {
        printf("Zla wartosc!\n");
    }
    while(1981+ileMaLat>2022 || ileMaLat<0)
    {
        printf("Podaj ile lat ma komputer:\n");
        scanf("%u", &ileMaLat);
        if(1981+ileMaLat>2022 || ileMaLat<0)
            printf("Zla wartosc!\n");
    }
    bool czyLaptop;
    unsigned int tmp;
    printf("Podaj 1 jesli to laptop, podaj 0 jesli to komputer stacjonarny\n");
    scanf("%u", &tmp);
    if(tmp<0 || tmp>1)
        printf("Zla wartosc!\n");
    while(tmp<0 || tmp>1)
    {
        printf("Podaj 1 jesli to laptop, podaj 0 jesli to komputer stacjonarny\n");
        scanf("%u", &tmp);
        if(tmp<0 || tmp>1)
            printf("Zla wartosc!\n");
    }
    if(tmp)
        czyLaptop = true;
    else
        czyLaptop = false;

    // 2) Zainicjalizuj strukturê o nazwie komp1 wprowadzonymi danymi.
    Komputer komp1 = makeKomputer(nazwa,cena,ileMaLat,czyLaptop);
    show(&komp1);


    // 3) Stwórz strukturê o nazwie komp2 kopiuj¹c obiekt komp1.
    Komputer komp2 = makeKomputerCopy(&komp1);
    show(&komp2);


    // 4) Stwórz strukturê o nazwie komp3 kopiuj¹c obiekt komp1.
    Komputer komp3 = makeKomputerCopy(&komp1);
    show(&komp3);

    // 5) Zmieñ nazwê komputera komp1 na Dell
    strcpy(komp1.nazwa,"Dell");

    // 6) Zmieñ nazwê komputera komp2 na Lenovo
    strcpy(komp2.nazwa,"Lenovo");

    // 7) Zmieñ nazwê komputera komp3 na Asus
    strcpy(komp3.nazwa,"Asus");

    // 8) Zmieñ wiek komputera komp2 na 22 lata
    komp2.ileMaLat=22;

    // 9) Zmieñ czyLaptop komputera komp3 na true
    komp3.czyLaptop = true;

    // 10) Postarz komputer komp1 o 3 lata
    postarz(&komp1, 3);


    // 11) Wypisz informacje o obiektach komp1, komp2, komp3
    show(&komp1);
    show(&komp2);
    show(&komp3);

    // 12) stwórz tablicê o nazwie tab trzech komputerów

    // 13) W pêtli for do przechodzenia tablicy zamiast indeksów nale¿y u¿yæ wskaŸników, a ka¿dy operator indeksowania nale¿y zastapiæ operatorem dereferencji!!
    // PrzejdŸ tablicê i wype³nij j¹ komputerami uzywaj¹c odpowiedniej funkcji.

    // 14) W pêtli for do przechodzenia tablicy zamiast indeksów nale¿y u¿yæ wskaŸników, a ka¿dy operator indeksowania nale¿y zastapiæ operatorem dereferencji!!
    // Wypisz informacje o wszystkich obiektach typu Komputer znajduj¹cych sie w tablicy tab
    Komputer tab[3];
    for(Komputer *i=tab;i<tab+3;i++)
    {
        *i=makeKomputerCopy(&komp1);
        show(i);
    }


//https://github.com/jednach/kolos


    return 0;
}
