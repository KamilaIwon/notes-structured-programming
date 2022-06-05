#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
void generuj(short tab[], int n)
{
    short lim = 100;
    for(short *p=tab;p<tab+ n;p++)
        {
        *p=rand()% lim + 1;
        }
}
void wypisz(short tab[],int n)
{
    for(short *p = tab ;p< n+tab;p++)
        {
            printf("%d ", *p);
        }
}
void zamien_a(short tab[], int n)
{
    for(short *p=tab;p<n+tab;p++)
    {
        if (*p % 2 != 0)
        {
            *p = 3 * (*p) + 1;
        }
        else
        {
            if(*p%2==0)
            {
                do{
                    *p/=2;
                }while(*p%2==0);
            }
        }

    }
}
void zamien_b(short tab[],int n)
{
    for(short *p=tab;p<n+tab;p++)
    {
        if(*p%2!=0)
        {
            *p=2* (*p);
        }
        else
        {
            *p=-(*p);
        }
        printf("%d ", *p);
    }
    printf("\n");
    for(short *p=tab;p<n+tab;p++)
    {
        if(*p>0)
        {
            *p=1;
        }
        else
        {
            *p=-1;
        }
        printf("%d ", *p);
    }
}
void odwroc(short tab[], int lewy, int prawy, int n)
{

    for(short *i=tab+lewy,*j=tab+n-1-prawy;i<n,j>lewy;i++,j--)
    {
        int tmp;
        tmp=*i;
        *i=*j;
        *j=tmp;
        if(*i==*j || j==i+1)break;
    }
}
int ileNieparzystych(const short tab[], int n);
int ileParzystych(const short tab[], int n);
int ileMaksymalnych(const short tab[], int n);


int main()
{
    int n;
    short tab[N];
    short tab1[10]={1,2,3,4,5,6,7,8,8,8};
    srand(time(NULL));
    printf("Podaj n: \n");
    scanf("%d", &n);
    while (n<1 || n>N)
    {
        printf("Nieprawidlowa liczba, podaj jeszcze raz\n");
        scanf("%d",&n);
    }
    generuj(tab,n);
    wypisz(tab,n);
    zamien_a(tab,n);
    printf("\n");
    wypisz(tab,n);
    printf("\n");
    //zamien_b(tab,n);
    printf("\n");
    int lewy, prawy;
    printf("Podaj lewy: ");
    scanf("%d", &lewy );
    while (lewy<0 || lewy >= n)
    {
        printf("Nieprawidlowa liczba, podaj jeszcze raz\n");
        scanf("%d",&lewy);
    }
    printf("Podaj prawy: ");
    scanf("%d", &prawy );
    while (prawy<0 || prawy >= n)
    {
        printf("Nieprawidlowa liczba, podaj jeszcze raz\n");
        scanf("%d",&prawy);
    }
    printf("_______________\n");
    odwroc(tab,lewy,prawy,n);
    wypisz(tab,n);
    printf("\n");
    printf("Liczba elementow nieparzystych: %d",ileNieparzystych(tab,n));
    printf("\nLiczba elementow parzystych: %d",ileParzystych(tab,n));
    printf("\nLiczba elementow maksymalnych: %d",ileMaksymalnych(tab,n));
        printf("\nLiczba elementow maksymalnych: %d",ileMaksymalnych(tab1,n));
    return 0;
}
int ileNieparzystych(const short tab[], int n)
{
    int ile=0;
    for(const short *p=tab;p<tab+n;p++)
    {
        if((*p)%2!=0)ile++;
    }
    return ile;
}
int ileParzystych(const short tab[], int n)
{
    int ile=0;
    for(const short *p=tab;p<n+tab;++p)
    {
        if((*p)%2==0)ile++;
    }
    return ile;
}
int ileMaksymalnych(const short tab[], int n)
{
    int maks=0, ile=0;
    for(const short *p=tab;p<n+tab;++p)
    {
        if((*p)>maks)
            maks=(*p);
    }
    for(const short *p=tab;p<n+tab;p++)
    {
        if((*p)==maks)ile++;
    }
    return ile;
}
