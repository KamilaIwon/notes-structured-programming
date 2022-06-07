#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Auto
{
    char *model;
    int liczba_silnikow;
};

struct Auto foo(int n, struct Auto tab[])
{
    float najwiecej_zn=0;
    int index_najw=0;
    for(int i=1; i<n; i++){
        if(strlen(tab[i].model) > najwiecej_zn){
            index_najw = i;
        }
    }
    return tab[index_najw];
}

int main()
{
    struct Auto a1 = {"bmw",4};
    struct Auto a2 = {"Mercedes",6};
    struct Auto a3 = {"Porsche",3};
    struct Auto tab[3]={a1,a2,a3};
    struct Auto wynik = foo(5,tab);
    printf("Hello world!\n");
    return 0;
}
