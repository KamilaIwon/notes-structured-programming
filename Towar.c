#include "Towar.h"
#include <string.h>
#include <stdio.h>

Towar makeTowar(const char *nazwa, double cenaBrutto, float stawkaVAT)
{
    Towar tmp;
    strcpy(tmp.nazwa, nazwa);
    tmp.cenaBrutto = cenaBrutto;
    tmp.stawkaVAT = stawkaVAT;
    return tmp;
}

Towar makeTowar1(const Towar * towar)
{
    Towar kopia;
    //do poprawy
    //memcpy(&kopia,&towar, sizeof towar);
    return kopia;
}

void show(const Towar *towar)
{
    printf("nazwa: %s   cena Brutto: %lf   VAT: %lf \n", towar->nazwa,towar->cenaBrutto,towar->stawkaVAT);
}

double cenaNetto(const Towar *towar)
{
    double VAT = (towar->stawkaVAT * towar->cenaBrutto)/100;
    return (double)(towar->cenaBrutto - VAT);
}
double kwotaVAT(const Towar *towar)
{
    return (double)((towar->stawkaVAT * towar->cenaBrutto)/100);
}
