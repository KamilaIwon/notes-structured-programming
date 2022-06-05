#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct student{
    char imie[MAX_LEN];
    char nazwisko[MAX_LEN];
    char adres[MAX_LEN];
    int pesel;
    char kierunek[MAX_LEN];
    int nrlegitymacji;
}student;

student makestudent(const char* imie, const char* nazwisko, const char* adres, const char* kierunek, int nrlegitymacji,int pesel );

void init(student *student);

int main()
{
    student student1 = makestudent("Kamila","Iwon","Elblag","Informatyka",12345,12856);
    show(&student1);
    student student2;
    init(&student2);
    show(&student2);
    return 0;
}

student makestudent(const char* imie, const char* nazwisko, const char* adres, const char* kierunek, int nrlegitymacji,int pesel )
{
    student tmp;
    strcpy(tmp.imie,imie);
    strcpy(tmp.nazwisko,nazwisko);
    strcpy(tmp.adres,adres);
    tmp.pesel=pesel;
    strcpy(tmp.kierunek,kierunek);
    tmp.nrlegitymacji=nrlegitymacji;
    return tmp;
}
void show(const student *student)
{
    printf("\n%s ",student->imie);
    printf("\n%s ",student->nazwisko);
    printf("\n%s ",student->adres);
    printf("\n%d ",student->pesel);
    printf("\n%s ",student->kierunek);
    printf("\n%d ",student->nrlegitymacji);
}
void init(student *student)
{
    printf("\nPodaj imie:");
    scanf("%s", student->imie);

    printf("Podaj nazwisko:");
    scanf("%s", student->nazwisko);

    printf("Podaj adres:");
    scanf("%s", student->adres);

    printf("Podaj kierunek:");
    scanf("%s", student->kierunek);

    printf("Podaj pesel:");
    scanf("%d", &student->pesel);

    printf("Podaj nrleg:");
    scanf("%d", &student->nrlegitymacji);
}
