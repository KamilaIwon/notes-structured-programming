#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//sprawdzamy czy suma elementow parzystych jest taka sama w kazdej tablicy
int takasamasumaparzystych(int n, int tablica1[n], int tablica2[n])
{
    int suma1=0, suma2=0;
    //sprawdzamy sume elementow
    for(int i=0;i<n;i++)
    {
        if(tablica1[i]%2 == 0) suma1+=tablica1[i];
        if(tablica2[i]%2 == 0) suma2+=tablica2[i];
    }
    if(suma1==suma2) return 1;
    return 0;
}

//wpisujemy do tablicy randomowe liczby od <0,100>
void generuj(short tab[], int n)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
        tab[i]=rand()%100+1;
}

//wypisujemy elementy tablicy
void wypisz(short tab[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",tab[i]);
}

// zamiana elementow - nieparzyste 3x+1, parzyste na najwiekszy nieparzysty dzielnik
void collatz(short tab[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i]<=0) continue;
        if(tab[i] % 2 == 1)
        {
            tab[i] = 3*tab[i] +1;
        }
        else
        {
            do
            {
                tab[i] /= 2;
            }while(tab[i] % 2 == 0);
        }
    }
}

// zamiana elementow - nieparzyste x*2, parzyste -x
void zmien(short tab[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(tab[i]%2!=0)
            tab[i]*=2;
        else
            tab[i]*=-1;
    }
}

//zamiana dodatnich na 1, ujemnych na -1
void signum(short tab[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(tab[i]>0) tab[i]=1;
        if(tab[i]<0) tab[i]=-1;
    }
}

//odwracanie elementow tablicy
void odwroc(short tab[], int lewy, int prawy)
{
    int tmp;
    for(int i=lewy,j=prawy;i<j;i++,j--)
    {
        tmp=tab[i];
        tab[i]=tab[j];
        tab[j]=tmp;
    }
}

//napisz ile jest nieparzystych
int ileNieparzystych(const short tab[], int n)
{
    int np=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]%2!=0) np++;
    }
    return np;
}

//napisz ile jest parzystych
int ileParzystych(const short tab[], int n)
{
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]%2==0) p++;
    }
    return p;
}

//ile jest liczb maksymalnych w tablicy
int ileMaksymalnych(const short tab[], int n)
{
    int maks=0, ile=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]>maks)
        {
            maks=tab[i];
            ile=0;
        }
        if(tab[i]==maks)ile++;
    }
    return ile;
}

//ile jest liczb == 0
int ileZerowych(const short tab[],int n)
{
    int ile=0;
    for(int i=0;i<n;i++)
    {
        if (tab[i]==0) ile++;
    }
    return ile;
}

//podaj sume elementow dodatnich
short sumaDodatnich(const short tab[],int n)
{
    short suma=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]>0)
            suma+=tab[i];
    }
    return suma;
}

//podaj sume elementow ujemnych
short sumaUjemnych(const short tab[],int n)
{
    short suma=0;
    for(int i=0;i<n;i++)
    {
        if(tab[i]<0)
            suma+=tab[i];
    }
    return suma;
}

//jaka jest dlugosc maksymalnego ciagu liczb dodatnich
int dlugoscMaksymalnegoCiaguDodatnich(const short tab[], int n)
{
    int dl=0, maks=0;
    for(int i=0;i<n;i++)\
    {
        if(tab[i]>0)
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
int main()
{
    short tab1[5]={1,5,3,4,5};
    wypisz(tab1,5);
    collatz(tab1,5);
    printf("\n");
    wypisz(tab1,5);

    return 0;
}
