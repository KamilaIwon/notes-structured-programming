#include <stdio.h>
#include <stdlib.h>
#include "Towar.h"

int main()
{
    Towar krzeslo = makeTowar("krzeslo",400,30);
    show(&krzeslo);
    printf("Cena netto: %lf\n",cenaNetto(&krzeslo));
    printf("Kwota VAT: %lf\n",kwotaVAT(&krzeslo));
    return 0;
}
