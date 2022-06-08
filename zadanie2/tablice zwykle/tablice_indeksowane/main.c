#include <stdio.h>
#include <stdlib.h>

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
int main()
{
    int tab1[5]={1,2,3,4,5};
    int tab2[5]={6,7,8,9,10};
    int tab3[5]={1,4,1,2,1};
    printf("\nczy suma parzystych taka sama: %d", takasamasumaparzystych(5,tab1,tab2));
    printf("\nczy suma parzystych taka sama: %d", takasamasumaparzystych(5,tab1,tab3));
    return 0;
}
