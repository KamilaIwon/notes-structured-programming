#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//podaj z ilu w sumie liter i cyfr sklada sie napis

int foo(const char napis[])
{
    int i = 0, ile1=0, ile2=0, ile3=0;
    while(napis[i]!=0)
    {
        if(napis[i]>='a' && napis[i]<='z') ile1++;
        if(napis[i]>='A' && napis[i]<='Z') ile2++;
        if(napis[i]>='1' && napis[i]<='9') ile3++;
        i++;
    }
    return ile1 + ile2 + ile3;
}

//kopiuje napis s do napisu t
char* strcpy(char t[], const char s[])
{
    char * p = t;
    int i = 0;
    while(s[i])
    {
        t[i]=s[i];
        i++;
    }
    t[i]=0;
    return p;
}

//podaj dlugosc napisu
size_t strlen(const char s[])
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
//kopiuje n liter napisu s do napisu t
char* strncpy(char t[], const char s[], size_t n)
{
    char * p = t;
    int i = 0;
    while(s[i]!=0 && i<n)
    {
        t[i]=s[i];
        i++;
    }
    t[i]=0;
    return p;
}

//³¹czy napis s z napisem t
char* strcat(char t[], const char s[])
{
    char *p= t;
    int i = 0, j=0;
    while(t[i]) i++;
    while(s[j])
    {
        t[i]=s[j];
        i++;
        j++;
    }
    t[i]=0;
    return p;
}
//³¹czy n liter napisu s z napisem t
char* strncat(char t[], const char s[], size_t n)
{
    char *p = t;
    int i=0, j=0;
    while(t[i])i++;
    while(s[j]!=0 && j<n)
    {
        t[i]=s[j];
        i++;
        j++;
    }
    t[i]=0;
    return p;
}

//czy napis s jest na koncu napisu t
bool strend(const char s[], const char t[])
{
    int i =0, j=0;
    while(s[i])i++;
    while(t[j])j++;
    for(int p =0; p<j;p++)
    {
        if(t[j-p-1]!=s[i-p-1])
            return false;
    }
    return true;
}

//zwraca pozycje wystapienia napisu s w napisie t
int strindex(const char s[], const char t[])
{
    int i =0, j=0, k=0, l;
    while(s[i])i++;
    while(t[j])
    {
        if(t[j]==s[k])
        {
            l=j;
            while(t[l]==s[k])
            {
                l++;
                k++;
            }
            if(i==k) return j;
            else
                k = 0;
        }
        j++;
    }
    return -1;
}

int main()
{
    char napis1[20];
    char napis2[] = "Siemano";
    char napis3[] = "ma";
    char napis4[] = "Ala ma kota";
    //pobieramy od uzykownika napis (2 sposoby)
    printf("podaj napis: ");
    //scanf("%s", napis1);
    gets(napis1);
    printf("napis: %s\n",napis1);
    //strlen
    printf("dlugosc napisu: %d", strlen(napis1));

    //strcpy
    printf("\nnapis po strcpy: %s", strcpy(napis1,napis2));

    //strncpy
    printf("\nnapis po strncpy: %s", strncpy(napis1,napis2,5));

    //strcat
    printf("\nnapisy po strcat: %s", strcat(napis1,napis2));

    //strncat
    printf("\nnapisy po strncat: %s", strncat(napis1,napis2,5));

    //strend
    printf("\nczy napis 1 jest na koncu napisu 2: %d", strend(napis4,napis3));

    //strindex
    printf("\nczy zawiera w indeksie: %d", strindex(napis3,napis4));

    //foo
    printf("\nile zawiera liter i cyfr: %d", foo(napis3));

    return 0;
}

