#include <stdio.h>
#include <stdlib.h>

//pokaz elementy
void showtable(int **tab, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ", *(*(tab+i)+j));
        }
        printf("\n");
    }
}
// liczy ile jest elementow parzystych w 2 tablicach
int ileparzwdwoch(int **tab1, int**tab2, int n, int m)
{
    int ile1=0, ile2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tab1[i][j]%2==0) ile1++;
            if(tab2[i][j]%2==0) ile2++;
        }
    }
    return ile1+ile2;
}

//liczy ile jest elementow parzystych ujemnych
int ileparzystychujemnych(int **tab, int n, int m)
{
    int ile=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(*(tab+i)+j)%2==0 && *(*(tab+i)+j)<0)
                ile++;
        }
    }
    return ile;
}
//stworz nowa tablice elementow
int **utworz(int n, int m)
{
    int **tab = (int**) malloc(sizeof(int*)*n);
    tab[0] = (int*)malloc(sizeof(int)*m); //przypisujemy pamiec
    tab[1] = (int*)malloc(sizeof(int)*m); //przypisujemy pamiec
    tab[2] = (int*)malloc(sizeof(int)*m); //przypisujemy pamiec
    tab[3] = (int*)malloc(sizeof(int)*m); //przypisujemy pamiec
    return tab;
}

//poteguj elementy tablicy w nieparzystych kolumnach
int ** potegujelementy(int **tab, int n, int m)
{
    int ** t = tab;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j%2!=0)
            {
                *(*(t+i)+j) *= *(*(t+i)+j);
            }
        }
    }
    return t;
}

//odwraca elementy w nieparzystych wierszach
void foo(int **tab, int n, int m)
{
    for(int i=1;i<n;i+=2)
    {
        for(int j=0;j<m/2;j++)
        {
            int temp = *(*(tab+i)+j);
            *(*(tab+i)+j) = *(*(tab+i)+m-1-j);
            *(*(tab+i)+m-1-j)=temp;
        }
    }
}

//odwraca elementy w nieparzystych kolumnach
//nie dziala na innych wymiarach, idk why
void foo2(int **tab, int n, int m)
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=1;j<m;j+=2)
        {
            int temp = *(*(tab+i)+j);
            *(*(tab+i)+j) = *(*(tab+i+n-1)+j);
            *(*(tab+i+n-1)+j)=temp;
        }
    }
}

//suma kwadratow elementow w nieparzystych wierszach
int sumakwadr(int **tab, int n, int m)
{
    int suma=0, kwadrat=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i%2!=0)
            {
                kwadrat = *(*(tab+i)+j) *  *(*(tab+i)+j);
                suma+=kwadrat;
            }
        }
    }
    return suma;
}
//suma indeksow elementu maksymalnego
int sumaind(int **tab, int n, int m)
{
    int suma=0;
    int maksymalny = *(*(tab+0)+0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(*(tab+i)+j) > maksymalny)
                maksymalny = *(*(tab+i)+j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(*(tab+i)+j) == maksymalny)
                suma = i + j;
        }
    }
    return suma;
}

//przestawia 1 i 2 wiersz
void przestaw(int **tab, int n, int m)
{
    if(n<2)
    {

    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                    int tmp = *(*(tab+i)+j);
                    *(*(tab+i)+j) = *(*(tab+1)+j);
                    *(*(tab+1)+j) = tmp;
                }
            }
        }
    }

}
int main()
{
    //tworzymy tablice tablic w main
    int **tab = (int**) malloc(sizeof(int*)*2);
    *tab = (int*)malloc(sizeof(int)*3); //przypisujemy pamiec
    *(tab+1) = (int*)malloc(sizeof(int)*3); //przypisujemy pamiec
    *(*(tab+0)+0) = 2;
    *(*(tab+0)+1) = 3;
    *(*(tab+0)+2) = -3;
    *(*(tab+1)+0) = 1;
    *(*(tab+1)+1) = 4;
    *(*(tab+1)+2) = 8;
    showtable(tab,2,3);


    int **tab4 = (int**) malloc(sizeof(int*)*2);
    *tab4 = (int*)malloc(sizeof(int)*3); //przypisujemy pamiec
    *(tab4+1) = (int*)malloc(sizeof(int)*3); //przypisujemy pamiec
    *(*(tab4+0)+0) = -3;
    *(*(tab4+0)+1) = 0;
    *(*(tab4+0)+2) = -2;
    *(*(tab4+1)+0) = 7;
    *(*(tab4+1)+1) = -4;
    *(*(tab4+1)+2) = 0;

    //tworzymy tablice tablic za pomoca funkcji
    int **tab2 = utworz(4,4);
    *(*(tab2+0)+0)= 2;
    *(*(tab2+0)+1)= 4;
    *(*(tab2+0)+2)= 5;
    *(*(tab2+0)+3)= 8;

    *(*(tab2+1)+0)= 5;
    *(*(tab2+1)+1)= 2;
    *(*(tab2+1)+2)= 1;
    *(*(tab2+1)+3)= 3;

    *(*(tab2+2)+0)= 1;
    *(*(tab2+2)+1)= 2;
    *(*(tab2+2)+2)= 3;
    *(*(tab2+2)+3)= 4;

    *(*(tab2+3)+0)= 9;
    *(*(tab2+3)+1)= 8;
    *(*(tab2+3)+2)= 7;
    *(*(tab2+3)+3)= 6;


    //int **potega = potegujelementy(tab,2,3);
    //showtable(potega,2,3);

    foo(tab,2,3);
    showtable(tab,2,3);

    foo2(tab,2,3);
    showtable(tab,2,3);

    printf("--------\n");
    showtable(tab,2,3);
    foo2(tab,2,3);
    printf("--------\n");
    showtable(tab,2,3);

    printf("\nsuma: %d", sumakwadr(tab,2,3));
    printf("\nsuma indeksow elementu maksymalnego: %d", sumaind(tab,2,3));

    //przestawiamy wiersze
    printf("\n--------\n");
    showtable(tab2,4,4);
    przestaw(tab2,4,4);
    printf("--------\n");
    showtable(tab2,4,4);

    //liczba el
    printf("--------\ntablica1:\n");
    showtable(tab,2,3);
    printf("--------\ntablica2:\n");
    showtable(tab4,2,3);
    printf("\nile jest razem parzystych elementow: %d", ileparzwdwoch(tab,tab4,2,3));
    printf("\nile jest razem elementow ujemnych parzystych: %d", ileparzystychujemnych(tab4,2,3));
    return 0;
}
