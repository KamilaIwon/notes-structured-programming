#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void wyczysc(char *napis)
{
    napis[0]=0;
}
int dlugosc(char *napis)
{
    int i=0;
    while(napis[i]!=0)
        i++;
    return i;
}
int porownaj(char *nap1, char *nap2)
{
    int i=0, j=0;
    while(nap1[i]!=0)
        i++;
    while(nap2[j]!=0)
        j++;
    if(i!=j)
        return 0;
    i=0;
    while(nap1[i]!=0)
    {
        if(nap1[i]!=nap2[i])
            return 0;
        i++;
    }
    return 1;
}
void przepisz(const char *nap1, char *nap2)
{
    int i=0;
    while(nap1[i]!=0)
    {
        nap2[i]=nap1[i];
        i++;
    }
    nap2[i]=0;
}
void kopiujn(const char *nap1, char *nap2, int n)
{
    int i=0;
    while(i!=n)
    {
        nap2[i]=nap1[i];
        i++;
    }
    nap2[i]=0;
}
void sklej(const char *nap1, const char *nap2, char *nap3)
{
    int i=0, j=0;
    while(nap1[i]!=0)
    {
        nap3[i]=nap1[i];
        i++;
    }
    while(nap2[j]!=0)
    {
        nap3[i]=nap2[j];
        i++;
        j++;
    }
    nap3[i]=0;
}
void malenaduze(char *napis)
{
    int i=0;
    while(napis[i]!=0)
    {
        if(napis[i]>='a' && napis[i]<='z')
            napis[i]-=('a'-'A');
        i++;
    }
}
void duzenamale(char *napis)
{
    int i=0;
    while(napis[i]!=0)
    {
        if(napis[i]>='A' && napis[i]<='Z')
            napis[i]+=('a'-'A');
        i++;
    }
}
void wytnij1(char *napis, int n, int m)
{
    int dl;
    for(dl=0;napis[dl]!=0;dl++);
    if(dl+1>m)
    {
        for(int i=0;i+m<dl;i++)
            napis[n+i]=napis[i+m+1];
    }
    else
        if((n<dl) && (dl+1<=m))
            napis[n]=0;
}
void kopiuj(char *napis1, char napis2[])
{
    int i=0;
    while(napis1[i]!=0)
    {
        napis2[i]=napis1[i];
        i++;
    }
    napis2[i]=0;
}
void wypisz(char *napis)
{
    printf("%s\n",napis);
}
void wczytaj(char napis[])
{
    scanf("%20[^\n]", napis);
}
int len(char *napis)
{
    int i=0;
    while(napis[i]!=0)
        i++;
    return i;
}
char * pierwszy(char**tab, int n)
{
    char *first;
    int j;
    first=malloc(50*sizeof(char));
    for(int i=0;i<n;i++)
        if(len(tab[i])==0)
            return tab[i];
    strcpy(first,tab[0]);
    for(int i=1;i<n;i++)
    {
        j=0;
        while(tab[i][j]!=0)
        {
            if(first[j]<tab[i][j])
                break;
            if(first[j]>tab[i][j])
            {
                strcpy(first,tab[i]);
                break;
            }
            j++;
            if((tab[i][j]==0)&&(len(first)>len(tab[i])))
            {
                strcpy(first,tab[i]);
                break;
            }
        }
    }
    return first;
}
char * godzina(int g, int m, int s)
{
    char *result;
    result=malloc(8*sizeof(char));
    sprintf(result,"%02d:%02d:%02d",g,m,s);
    return result;
}
char * sklej2(char *nap1, char *nap2, char *nap3)
{
    char * result;
    result=malloc((strlen(nap1)+strlen(nap2)+strlen(nap3))*sizeof(char));
    strcpy(result,nap1);
    strcat(result,nap2);
    strcat(result,nap3);
    return result;
}
void kopiuj2(char *napis, char**wsk)
{
    char *tab;
    tab=malloc(strlen(napis)*sizeof(char));
    strcpy(tab,napis);
    *wsk=tab;
}
void zamiana1(char *napis)
{
    int i=0;
    while(napis[i]!=0)
    {
        if((napis[i]>='a') && (napis[i]<='z'))
            napis[i]-=('a'-'A');
        i++;
    }
}
void zamiana2(char *napis)
{
    int i=0;
    while(napis[i]!=0)
    {
        napis[i]=toupper(napis[i]);
        i++;
    }
}
int main()
{
    char *tab[4]={"kamila","Aleksandra","hahahahha","z"}, nap[]="siemano";
    printf("%s\n",pierwszy(tab,4));
    printf("%s\n",godzina(20,9,33));
    printf("%s\n", sklej2("ala"," ma"," kota"));
    char *wsk;
    kopiuj2("abcdgshdmsjgc",&wsk);
    printf("%s\n",wsk);
    printf("%s\n",nap);
    zamiana2(nap);
    printf("%s\n",nap);
    return 0;
}
