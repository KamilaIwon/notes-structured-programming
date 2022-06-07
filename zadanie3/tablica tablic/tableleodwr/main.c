#include <stdio.h>
#include <stdlib.h>

void foo(int n, int tab[][n])
{
    for(int i=1;i<n;i+=2)
    {
        for(int j=0;j<n/2;j++)
        {
            int temp = tab[i][j];
            tab[i][j] = tab[i][n-1-j];
            tab[i][n-1-j]=temp;
        }
    }
}

void wyswietl(int n, int tab[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("[%d,%d]=%3d, ",i,j,tab[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}

int main()
{
    int tab[4][4] = {{2,3,-3,1},{1,4,7,2},{-3,-6,11,3},{-2,8,23,4}};
    wyswietl(4,tab);
    foo(4,tab);
    wyswietl(4,tab);
    return 0;
}
