#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void generuj(short[], int, short, short);
void wypisz(short [],int);
int ileDodatnich(const short[],int);
int ileUjemnych(const short[],int);
int ileZerowych(const short[],int);
short sumaDodatnich(const short[],int);
short sumaUjemnych(const short[],int);
int dlugoscMaksymalnegoCiaguDodatnich(const short[],int);

int main()
{
    int tab[N], n=10, minWartosc=-99, maxWartosc=99;
    generuj(tab,n,minWartosc,maxWartosc);
    wypisz(tab,n);
    printf("\nIlosc elementow dodatnich: %d ", ileDodatnich(tab,n));
    printf("\nIlosc elementow ujemnych: %d ", ileUjemnych(tab,n));
    printf("\nIlosc elementow zerowych: %d ", ileZerowych(tab,n));
    printf("\nSuma dodatnich elementow: %d ", sumaDodatnich(tab,n));
    printf("\nSuma ujemnych elementow: %d ", sumaUjemnych(tab,n));
    printf("\nDlugosc maksymalnego ciagu elementow dodatnich: %d ", dlugoscMaksymalnegoCiaguDodatnich(tab,n));
    return 0;
}
void generuj(short tab[],int n, short minWartosc, short maxWartosc)
{
    srand(time(NULL));
    for(short *p=tab;p<n+tab;++p)
        *p=rand()%(maxWartosc-minWartosc+1)+minWartosc;
}
void wypisz(short tab[], int n)
{
    for(short *p=tab;p<tab+n;p++) printf("%d ", *p);
}
int ileDodatnich(const short tab[],int n)
{
    int ile=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if ((*p)>0) ile++;
    }
    return ile;
}
int ileUjemnych(const short tab[],int n)
{
    int ile=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if ((*p)<0) ile++;
    }
    return ile;
}
int ileZerowych(const short tab[],int n)
{
    int ile=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if ((*p)==0) ile++;
    }
    return ile;
}
short sumaDodatnich(const short tab[],int n)
{
    short suma=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if((*p)>0)
            suma+=(*p);
    }
    return suma;
}
short sumaUjemnych(const short tab[],int n)
{
    short suma=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if((*p)<0)
            suma+=(*p);
    }
    return suma;
}
int dlugoscMaksymalnegoCiaguDodatnich(const short tab[], int n)
{
    int dl=0, maks=0;
    for(short *p=tab;p<n+tab;p++)
    {
        if((*p)>0)
            dl++;
        else
        {
            if(dl>maks)
                maks=dl;
            dl=0;
        }

    }
    if(dl>maks) maks = dl;

    return maks;
}
