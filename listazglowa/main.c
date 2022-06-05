#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element * utworz()
{
    struct element * wskaznik = malloc(sizeof(struct element));
    wskaznik->next=NULL;
    return wskaznik;
};

void dodaj(struct element*Lista, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista->next;
    Lista->next=wsk;
};

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


int main()
{
    struct element* l1 = utworz();
    dodaj(l1,2);
    dodaj(l1,4);
    dodaj(l1,-8);
    dodaj(l1,-22);
    struct element * wsk = l1;
    while(wsk->next!=NULL)
    {
        wsk=wsk->next;
        printf("%d\n",wsk->i);
    }
    return 0;
}
