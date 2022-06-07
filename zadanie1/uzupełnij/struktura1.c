#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

struct Telefon
{
    char * marka;
    int cena;
};

int foo(struct Telefon tab[], int n)
{
    int cenaN = tab[0].cena;
    for(int i=1;i<n;i++)
    {
        if (cenaN < tab[i].cena)
        {
            cenaN=tab[i].cena;
        }
    }
    return cenaN;
}

int main()
{
    struct Telefon t1 = {"Iphone",7000};
    struct Telefon t2 = {"Samsung",5000};
    struct Telefon t3 = {"Sony",1000};
    struct Telefon tab[3]={t1,t2,t3};
    printf("wynik: %d\n", foo(tab,9));
    return 0;
}
