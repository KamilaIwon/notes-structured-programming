#include <stdio.h>
#include <stdlib.h>
int zad3(int *, int*);
int *zad4(int *, int*);
void zad5(int*,int*);
void zad6(int *, int*);
int zad7(int *, int*);
void zad8(int, int*);
int main()
{
    int a = 36;
    int b=10;

    printf("liczba a: %d, liczba b: %d\n",a,b);
    printf("mniejsza z liczb: %d", zad3(&a,&b));
    printf("\n---------------");
    zad3(&a,&b);
    printf("\n po wskazniku:  %d", zad4(&a,&b));
    printf("\nb: %p", &b);
    printf("\n---------------");
    zad5(&a,&b);
    printf("\nliczby  a:%d, b: %d", a,b);
    printf("\n---------------");
    zad6(&a,&b);
    printf("\nliczby: a:%d, b: %d", a,b);
    printf("\n---------------");
    printf("\nsuma tych liczb: %d",zad7(&a,&b));
    printf("\n---------------");
    printf("\n liczba a przed: %d", a);
    zad8(888,&a);
    printf("\n liczba a po: %d", a);
    return 0;
}
int zad3(int *liczba1, int*liczba2)
{
    if(*liczba1<*liczba2) return *liczba1;
    else return *liczba2;
}
int *zad4(int *liczba1, int *liczba2)
{
    int *wsk;
    if(*liczba1>*liczba2)
        {wsk = &liczba2;
        //wsk = *liczba2;
        }
    else
        {wsk = &liczba1;
        //wsk = *liczba1;
        }

    return wsk;
}
void zad5(int *liczba1, int* liczba2)
{
    int tmp;
    tmp=*liczba1;
    *liczba1=*liczba2;
    *liczba2=tmp;
}
void zad6(int *liczba1, int* liczba2)
{
    if(*liczba2<*liczba1)
    {
        int tmp;
        tmp=*liczba1;
        *liczba1=*liczba2;
        *liczba2=tmp;
    }
}
int zad7(int *liczba1,int *liczba2)
{
    return *liczba1 + *liczba2;
}
void zad8(int n, int*w)
{
    *w = n;
}
