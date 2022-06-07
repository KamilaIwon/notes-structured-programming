#include <stdio.h>
#include <stdlib.h>

void func(int n, int m, int **tab);
int main()
{
    int **tab=(int**)malloc(sizeof(int*)*2);
    tab[0]=(int*)malloc(sizeof(int)*3);
    tab[1]=(int*)malloc(sizeof(int)*3);
    printf("Hello world!\n");
    return 0;
}
void func(int n, int m, int **tab)
{
    for(int i=0;i<n;i++)
    {
        free(tab[i]);
    }
    free(tab);
}
