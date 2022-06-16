#include <stdio.h>
#include <stdlib.h>

//tworzymy blok pamieci dla 2 zmiennych typu double
// i przypisujemy im odpowiednie wartosci
double *alokuj()
{
    double *p = (double*)(malloc(2*sizeof(double)));
    *p = 3.4;
    *(p+1) = -2.8;
    return p;
}

int main()
{
    //wyswietlamy 2 elementy bloku pamieci
    printf("pierwszy: %lf", *(alokuj()));
    printf("\ndrugi: %lf", *(alokuj()+1));
    return 0;
}
