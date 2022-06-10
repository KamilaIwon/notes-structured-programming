#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba
{
    char imie[20];
    int wiek;
    float wzrost;
}osoba;

typedef struct ksiazka
{
    char autor[20];
    int rok;
    float ocena;
}ksiazka;


void wiekszy(int n, osoba tab[n])
{
    float najw = 0;
    int naj=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i].wzrost>najw)
        {
            naj=i;
            najw=tab[i].wzrost;
        }
    }
    printf("%s",tab[naj].imie);
}

char * wiekszy1(int n, ksiazka tab[n])
{
    int zapamietaj;
    float najocena = tab[0].ocena;
    for(int i=0;i<n;i++)
    {
        if(tab[i].ocena > najocena)
        {
            zapamietaj = i;
            najocena = tab[i].ocena;
        }
    }
    return tab[zapamietaj].autor;
}

int main()
{
    osoba tab[2];
    strcpy(tab[0].imie,"Ola");
    tab[0].wiek=8;
    tab[0].wzrost=1.77;
    strcpy(tab[1].imie,"Ala");
    tab[1].wiek=10;
    tab[1].wzrost=1.66;
    wiekszy(2,tab);

    ksiazka k1 = {"Jan Kowal", 1996, 5.56};
    ksiazka k2 = {"Ania Kot", 2001, 7.39};
    ksiazka tab2[2] = {k1, k2};
    printf("\nautor najlepiej ocenianej ksiazki: %s", wiekszy1(2,tab2));
    return 0;
}
