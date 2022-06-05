#include <stdio.h>
#include <stdlib.h>

int *foo(char *napis1 , char *napis2)
{
    int a = 5;
    int *wsk = &a;
    return wsk;
}

int main()
{
    char napis1[50]="kamatoja";
    char napis2[50]="olatoja";
    printf("wynik: %d", foo(napis1,napis2));
    return 0;
}
