#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

typedef struct komp{
    char nazwa[MAX_LEN];
    char opis[MAX_LEN];
    int wiek;
    int cena;
}komp;

komp makekomp(const char* nazwa, const char* opis, int wiek,int cena );
komp makekopia(const komp *komp);

void init(komp *komp);

int main()
{
    //student student1 = makestudent("Kamila","Iwon","Elblag","Informatyka",12345,12856);
    //show(&student1);
    //student student2;
    //init(&student2);
    //show(&student2);
    return 0;
}

komp makekomp(const char* nazwa, const char* opis, int wiek,int cena )
{
    komp tmp;
    strcpy(tmp.nazwa,nazwa);
    strcpy(tmp.opis,opis);
    tmp.wiek=wiek;
    tmp.cena=cena;
    return tmp;
}

komp makekopia(const komp *komputer )
{
    komp tmp;
    strcpy(tmp.nazwa,nazwa);
    strcpy(tmp.opis,opis);
    tmp.wiek=wiek;
    tmp.cena=cena;
    return tmp;
}


void show(const komp *komp)
{
    printf("\n%s ",komp->nazwa);
    printf("\n%s ",komp->opis);
    printf("\n%d ",komp->wiek);
    printf("\n%d ",komp->cena);
}

void init(komp *komp)
{
    printf("\nPodaj nazwe:");
    scanf("%s", komp->nazwa);

    printf("Podaj opis:");
    scanf("%s", komp->opis);

    printf("Podaj wiek:");
    scanf("%d", &komp->wiek);

    printf("Podaj cene:");
    scanf("%d", &komp->cena);
}


