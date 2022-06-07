#include <stdio.h>
#include <stdlib.h>


double *alokuj()
{
    double *p = (double*)(malloc(2*sizeof(double)));
    *p = 3.4;
    *(p+1) = -2.8;
    return p;
}

int main()
{
    printf("pierwszy: %lf", *(alokuj()));
    printf("\ndrugi: %lf", *(alokuj()+1));
    return 0;
}
