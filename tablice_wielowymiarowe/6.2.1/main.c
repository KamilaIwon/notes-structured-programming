#include <stdio.h>
#include <stdlib.h>

int **func1(int, int);

int main()
{
    printf("%d ", func1(3,3));
    return 0;
}
int **func1(int n, int m)
{
    int ** wsk= malloc(n*sizeof(int*));
    for(int i=0;i<m;i++)
    {
        wsk[i]=malloc(m*sizeof(int));
    }
    return wsk;
}
