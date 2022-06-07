#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};
//tworzymy liste z glowa
struct element * utworz()
{
    struct element * wskaznik = malloc(sizeof(struct element));
    wskaznik->next=NULL;
    return wskaznik;
};

//dodajemy do listy z glowa
void dodaj(struct element*Lista, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista->next;
    Lista->next=wsk;
};

//dodajemy na koniec listy
void dodajk(struct element*Lista, int a)
{
    struct element * wsk =  Lista;
    while(wsk->next!=NULL)
    {
        wsk=wsk->next;
    }
    wsk->next=malloc(sizeof(struct element));
    wsk=wsk->next;
    wsk->i=a;
    wsk->next=NULL;
};

//usuwamy wybrany element n
void usun(struct element* Lista, int a)
{
    struct element*wsk=Lista;
    struct element*wsk2;
    while((wsk->next!=NULL)&&(wsk->next->i!=a))
    {
        wsk=wsk->next;
    }
    if(wsk->next!=NULL)
    {
        wsk2=wsk->next;
        wsk->next=wsk2->next;
        free(wsk2);
    }
}

//usun ostatni element nieparzysty
void usuniepo(struct element* Lista)
{
    int niep;
    struct element*wsk=Lista;
    struct element*wsk1=Lista;
    struct element*wsk2;

    while(wsk->next!=NULL)
    {
        if(wsk->next->i % 2 != 0)
        {
            niep = wsk->next->i;
        }
        wsk=wsk->next;
    }
    while((wsk1->next!=NULL)&&(wsk1->next->i != niep))
    {
        wsk1=wsk1->next;
    }
    if(wsk1->next!=NULL)
    {
        wsk2=wsk1->next;
        wsk1->next=wsk2->next;
        free(wsk2);
    }
}


//usun pierwszy element nieparzysty
void usuniepp(struct element* Lista)
{

    struct element*wsk1=Lista;
    struct element*wsk2;


    while((wsk1->next!=NULL)&&(wsk1->next->i %2 == 0))
    {
        wsk1=wsk1->next;
    }
    if(wsk1->next!=NULL)
    {
        wsk2=wsk1->next;
        wsk1->next=wsk2->next;
        free(wsk2);
    }
}

//usun pierwszy element parzysty
void usunparzp(struct element* Lista)
{

    struct element*wsk1=Lista;
    struct element*wsk2;


    while((wsk1->next!=NULL)&&(wsk1->next->i %2 != 0))
    {
        wsk1=wsk1->next;
    }
    if(wsk1->next!=NULL)
    {
        wsk2=wsk1->next;
        wsk1->next=wsk2->next;
        free(wsk2);
    }
}


//czyscimy liste z glowa
void wyczysc(struct element * Lista)
{
    struct element * wsk=Lista->next;
    struct element * wsk2=Lista;
    Lista=wsk;
    while(Lista!=NULL)
    {
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
    wsk2->next=NULL; //tego brak w odpowiedziach
}

//wyswietlamy liste z glowa
void wyswietlListeZGlowa(struct element*Lista)
{
    struct element*temp=Lista->next;
    if(temp==NULL)
    {
        printf("Lista jest pusta\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->i);
        temp=temp->next;
    }
    printf("----\n");
}

//podaj najmniejszy element parzysty
int znajdzminimumparzyste(struct element*Lista)
{
    struct element*wsk=Lista;
    int minimum;
    while(wsk->next!=NULL)
    {
        if(wsk->next->i % 2 == 0)
        {
            minimum = wsk->next->i;
            break;
        }
        wsk=wsk->next;
    }
    while(wsk->next!=NULL)
    {
        if(wsk->next->i < minimum)
        {
            minimum = wsk->next->i;
        }
        wsk=wsk->next;
    }

    return minimum;
}

int rowneszesciany(struct element*Lista1, struct element*Lista2 )
{
    int suma1=0, suma2=0;
    struct element*wsk1=Lista1;
    struct element*wsk2=Lista2;
    while(wsk1->next!=NULL)
    {
        suma1 += (wsk1->next->i)*(wsk1->next->i)*(wsk1->next->i);
        wsk1=wsk1->next;
    }
    while(wsk2->next!=NULL)
    {
        suma2 += (wsk2->next->i)*(wsk2->next->i)*(wsk2->next->i);
        wsk2=wsk2->next;
    }
    if(suma1==suma2)
        return 1;
    return 0;
}

int main()
{
    struct element* l1 = utworz();
    dodaj(l1,6);
    dodaj(l1,-4);
    dodaj(l1,-8);
    dodaj(l1,-2);
    struct element * wsk = l1;
    //while(wsk->next!=NULL)
    //{
    //    wsk=wsk->next;
    //    printf("%d\n",wsk->i);
    //}

    wyswietlListeZGlowa(l1);
    usuniepo(l1);
    wyswietlListeZGlowa(l1);
    int wynik = znajdzminimumparzyste(l1);
    printf("\nminimum parzyste: %d", wynik);

    //tworzymy druga liste
    struct element* l2 = utworz();
    dodaj(l2,6);
    dodaj(l2,4);
    dodaj(l2,3);

    //tworzymy trzecia liste
    struct element* l3 = utworz();
    dodaj(l3,4);
    dodaj(l3,5);
    dodaj(l3,6);

    printf("\nczy rowne szesciany: %d", rowneszesciany(l3,l2));
    return 0;
}
