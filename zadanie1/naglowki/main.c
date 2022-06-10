#include <stdio.h>
#include <stdlib.h>

//1
int * foo(char *napis1, char *napis2)
{
    return NULL;
}

//2
void fun(int **tab, char * n, int m[])
{
    printf("\nabc");
}

void fun1 (int n, int(*wsk)(int a, int b))
{

}
int funkcja(int a, int b)
{
    return a+b;
}
int main()
{
    char *nap1 = "Kamila";
    char *nap2 = "Ola";
    int **tab = NULL;
    int tab1[]={1,2,3};
    printf("\nwynik1: %p", foo(nap1,nap2));
    fun(tab,nap1,tab1);
    fun1(5,funkcja);
    return 0;
}
