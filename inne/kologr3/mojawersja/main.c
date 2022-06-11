#include <stdio.h>
#include "komputer.h"
#include <string.h>

bool czyPrawidlowaCena (double cena);
bool czyPrawidlowyWiek (int ileMaLat);

int main(int argc, char *argv[])
{
    // 1) Popro� u�ytkownika o wpisanie danych. Zabezpiecz dane! 1981 r. uznaje si� za pocz�tek ery komputer�w IBM PC - komputer�w osobistych. Zak�adamy, �e cena powinna by� z zakresu od 0 do 10000 z�. Napisz odpowiednie funkcje sprawdzaj�ce poprawno�� danych.
        char nazwa[MAX_LEN-1];
        int wiek;
        double cena;

        printf("Podaj nazwe: ");
        scanf("%s",&nazwa);

        printf("Podaj wiek: ");
        scanf("%d",&wiek);
        while(wiek<0 || wiek>41)
        {
            printf("nieprawidlowy wiek!! podaj jeszcze raz: ");
            scanf("%d",&wiek);
        }

        printf("Podaj cene: ");
        scanf("%lf",&cena);
        while(cena<0 || cena>10000)
        {
            printf("nieprawidlowa cena!! podaj jeszcze raz: ");
            scanf("%lf",&cena);
        }
        bool czyLaptop;
        unsigned int tmp;
        printf("Czy jest to laptop (jezeli tak napisz 1, jezeli nie - 0): ");
        scanf("%d",&tmp);
        while(tmp!=0 && tmp!=1)
        {
            printf("zly wynik, podaj jeszcze raz: ");
            scanf("%d",&tmp);
        }
        if(tmp==1)
            czyLaptop=true;
        if(tmp==0)
            czyLaptop=false;

    // 2) Zainicjalizuj struktur� o nazwie komp1 wprowadzonymi danymi.
        Komputer komp1 = makeKomputer(nazwa,cena,wiek,czyLaptop);

    // 3) Stw�rz struktur� o nazwie komp2 kopiuj�c obiekt komp1.
        Komputer komp2 = makeKomputerCopy(&komp1);

    // 4) Stw�rz struktur� o nazwie komp3 kopiuj�c obiekt komp1.
        Komputer komp3 = makeKomputerCopy(&komp1);

    // 5) Zmie� nazw� komputera komp1 na Dell
        strcpy(komp1.nazwa,"Dell");
    // 6) Zmie� nazw� komputera komp2 na Lenovo
        strcpy(komp2.nazwa,"Lenovo");
    // 7) Zmie� nazw� komputera komp3 na Asus
        strcpy(komp3.nazwa,"Asus");
    // 8) Zmie� wiek komputera komp2 na 22 lata
        komp2.ileMaLat = 22;
    // 9) Zmie� czyLaptop komputera komp3 na true
        komp3.czyLaptop = 1;
    // 10) Postarz komputer komp1 o 3 lata
        postarz(&komp1,3);
    // 11) Wypisz informacje o obiektach komp1, komp2, komp3
        show(&komp1);
        show(&komp2);
        show(&komp3);
    // 12) stw�rz tablic� o nazwie tab trzech komputer�w
        Komputer tab[2];
    // 13) W p�tli for do przechodzenia tablicy zamiast indeks�w nale�y u�y� wska�nik�w, a ka�dy operator indeksowania nale�y zastapi� operatorem dereferencji!!
    // Przejd� tablic� i wype�nij j� komputerami uzywaj�c odpowiedniej funkcji.
        printf("------------------------");
        for(int i =0;i<3;i++)
        {
            if(i==0)
                tab[i]=komp1;
            if(i==1)
                tab[i]=komp2;
            if(i==2)
                tab[i]=komp3;
        }

        printf("------------------------");
        for(Komputer *i=tab;i<tab+3;i++)
        {
            *i=makeKomputerCopy(&komp1);
        }

    // 14) W p�tli for do przechodzenia tablicy zamiast indeks�w nale�y u�y� wska�nik�w, a ka�dy operator indeksowania nale�y zastapi� operatorem dereferencji!!
    // Wypisz informacje o wszystkich obiektach typu Komputer znajduj�cych sie w tablicy tab
        for(int i =0;i<3;i++)
        {
            if(tab[i].czyLaptop==0)
                {
                    printf("\nnazwa komputera: %s", tab[i].nazwa);
                    printf("\ncena: %lf", tab[i].cena);
                    printf("\nile ma lat: %d", tab[i].ileMaLat);
                }
        }
        printf("------------------------");
        for(Komputer *i=tab;i<tab+3;i++)
        {
            show(i);
        }
    return 0;
}

