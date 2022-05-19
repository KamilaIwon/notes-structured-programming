#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void generuj(short[],int);
void wypisz(const short[],int);
void collatz(short[],int);
void zmien(short[],int);
void signum(short[],int);
void odwroc(short[],int,int);
int ileNieparzystych(const short [], int);
int ileParzystych(const short [], int);
int ileMaksymalnych(const short [], int);

int main()
{
    int tab[N], n, lewy, prawy, pom;
    srand(time(NULL));
    n=10;
    generuj(tab,n);
    wypisz(tab,n);
    printf("\n\n");
    collatz(tab,n);
    wypisz(tab,n);
    printf("\n\n");
    zmien(tab,n);
    wypisz(tab,n);
    printf("\n\n");
    signum(tab,n);
    wypisz(tab,n);
    printf("\n\n");
    lewy=rand()%n;
    prawy=rand()%n;
    if(lewy>prawy)
    {
        pom=lewy;
        lewy=prawy;
        prawy=pom;
    }
    printf("Lewy: %d  Prawy: %d ",lewy, prawy);
    printf("\n\n");
    odwroc(tab,lewy,prawy);
    wypisz(tab,n);
    printf("\n\n Ilosc elementow parzystych: %d", ileParzystych(tab,n));
    printf("\n\n Ilosc elementow nieparzystych: %d", ileNieparzystych(tab,n));
    printf("\n\n Ilosc elementow maksymalnych: %d", ileMaksymalnych(tab,n));
    return 0;
}
void generuj(short tab[], int n)
{
    srand(time(NULL));
    for(short *p = tab; p< tab +n; ++p)
        *p=rand()%100+1;
}
void wypisz(const short tab[],int n)
{
    for(const short *p = tab;p<tab + n; ++p)
        printf("%d ",*p);
}
void collatz(short tab[], int n)
{
    for (short *p = tab; p < tab + n; ++p) {
        if (*p <= 0) {
            continue;
        }
        if (*p % 2 == 1) {
            *p = 3 * *p + 1;
        } else {
            do {
                *p /= 2;
            } while (*p % 2 == 0);
        }
    }
}
void zmien(short tab[], int n)
{
    for(short *p = tab; p < tab + n; ++p)
    {
        if(*p %2!=0)
            *p *=2;
        else
            *p *=-1;
    }
}
void signum(short tab[],int n)
{
    for(short *p = tab; p < tab + n; ++p)
    {
        if(*p>0) *p=1;
        if(*p<0) *p=-1;
    }
}
void odwroc(short tab[], int lewy, int prawy)
{
    int tmp;
    for(short *p=tab+lewy;p<tab+prawy;p++)
    {
        short *j= tab +prawy;
        tmp=*p;
        *p=*j;
        *j=tmp;
        prawy--;
    }
}

int ileNieparzystych(const short tab[], int n)
{
    int np=0;
    for(const short *p = tab; p < tab + n; ++p)
    {
        if( *p %2!=0) np++;
    }
    return np;
}
int ileParzystych(const short tab[], int n)
{
    int parz=0;
    for(const short *p = tab; p < tab + n; ++p)
    {
        if(*p %2==0) parz++;
    }
    return parz;
}
int ileMaksymalnych(const short tab[], int n)
{
    int maks=0, ile=0;
    for(const short *p = tab; p < tab + n; ++p)
    {
        if(*p>maks)
        {
            maks=*p;
            ile=0;
        }
        if(*p==maks)ile++;
    }
    return ile;
}
