#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};

struct element* dodaj(struct element*Lista, int a)
{
    struct element * wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista;
    return wsk;
};

struct element * utworz()
{
    return NULL;
};

void wyswietlListeBezGlowy(struct element*Lista)
{
    struct element*temp=Lista;
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

int znajdzminimumparzyste(struct element*Lista)
{
    int minimum;
    struct element*temp=Lista;
    if(temp==NULL)
    {
        return -1;
    }
    while(temp->i %2!=0)
    {
        minimum = temp->i;
        temp=temp->next;
    }


    while(temp!=NULL)
    {
        if((temp->i) < minimum)
        {
            minimum = temp->i;
        }
        temp=temp->next;
    }
    printf("----\n");
    return minimum;
}

//czyszczenie listy
struct element* wyczysc(struct element *Lista)
{
    struct element * wsk=Lista;
    while(Lista!=NULL)
    {
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
    return NULL;
}
//dodawanie na koniec
struct element* dodajk(struct element*Lista, int a)
{
    struct element * wsk ;
    if(Lista==NULL)
    {
        wsk=malloc(sizeof(struct element));
        Lista=wsk;
    }
    else
    {
        wsk=Lista;
        while(wsk->next!=NULL)
        {
            wsk=wsk->next;
        }
        wsk->next=malloc(sizeof(struct element));
        wsk=wsk->next;
    }
    wsk->i=a;
    wsk->next=NULL;
    return Lista;
}
//usuwanie elementu a
struct element* usun(struct element* Lista, int a)
{
    if (Lista==NULL)
        return Lista;
    struct element*wsk,*wsk2;
    wsk=Lista;
    if (Lista->i==a)
    {
        Lista=Lista->next;
        free(wsk);
    }
    else
    {
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
    return Lista;
};

int main()
{
    struct element* l1 = utworz();
    l1 = dodaj(l1,-20);
    l1 = dodaj(l1,-14);
    l1 = dodaj(l1,-7);
    l1 = dodaj(l1,-31);
    struct element * wsk = l1;
    while(wsk!=NULL)
    {
        printf("%d\n",wsk->i);
        wsk=wsk->next;
    }
    printf("\n%d",znajdzminimumparzyste(l1));
    return 0;
}
