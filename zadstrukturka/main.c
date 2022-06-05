#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba
{
    char imie[20];
    int wiek;
    float wzrost;
}osoba;

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

    return 0;
}
