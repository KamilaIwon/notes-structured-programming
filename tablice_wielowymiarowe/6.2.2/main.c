#include <stdio.h>
#include <stdlib.h>

int *func(int n, int m);
int main()
{
    printf("%d",func(3,3));
    return 0;
}
int *func(int n, int m)
{
    return malloc(n*sizeof(int[m]));
}
