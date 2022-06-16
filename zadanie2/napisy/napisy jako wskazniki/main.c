#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char * strcpy(char *, const char *);
size_t strlen(const char *);
char * strncpy(char *, const char *, size_t);
char * strcat(char *, const char *);
char * strncat(char *, const char *, size_t);
bool strend(const char *,const char *);
int strindex(const char *, const char *);
int main()
{
    char *napis1 = "kama";
    char *napis = "siemano";
    char *napis2 = calloc(strlen(napis1)+1, sizeof(char));
    printf("napis1: %s", napis1);
    printf("\nnapis2: %s", napis2);
    strcpy(napis2,napis1);
    printf("\nnapis1: %s", napis1);
    printf("\nnapis2: %s", napis2);
    printf("\ndlugosc napisu pierwszego %d",strlen(napis1));
    char * r = calloc(100, sizeof(char));
    char * k = calloc(100, sizeof(char));
    *(r+0) = 'j';
    *(r+1) = 'a';
    *(r+2) = 'k';
    *(r+3) = 't';
    *(r+4) = 'o';
    printf("\nnapis po strncpy: %s", strncpy(k,napis,5));
    //printf("\nnapisy po strcat: %s", strcat(k,napis2));
    printf("\nnapisy po strncat: %s", strncat(k,napis2,3));
    char *napis3 = "ma";
    char *napis4 = "Ala ma kotama";
    printf("\nnapis: %s, napis: %s", napis3,napis4);
    printf("\nczy napis 1 jest na koncu napisu 2: %d", strend(napis4,napis3));
    printf("\nczy zawiera w indeksie: %d", strindex(napis4,napis3));
    free(napis2);
    return 0;
}
char * strcpy(char * t, const char * s)
{
    char * p = t;
    while((*t++ = *s++));
    return p;
}
size_t strlen(const char * s)
{
    size_t i = 0;
    while(*s++)
    {
        i++;
    }
    return i;
}
char * strncpy(char * t, const char * s, size_t n)
{
    char * p = t;
    int i = 0;
    while(*(s+i)!=0 && i<n)
    {
        *(t+i)=*(s+i);
        i++;
    }
    *(t+i)=0;
    return p;
}
char * strcat(char * t, const char * s)
{
    char *p= t;
    int i = 0, j=0;
    while(*(t+i)) i++;
    while(*(s+j))
    {
        *(t+i)=*(s+j);
        i++;
        j++;
    }
    *(t+i)=0;
    return p;
}
char * strncat(char * t, const char * s, size_t n)
{
    char *p = t;
    int i=0, j=0;
    while(*(t+i))i++;
    while(*(s+j)!=0 && j<n)
    {
        *(t+i)=*(s+j);
        i++;
        j++;
    }
    *(t+i)=0;
    return p;
}
bool strend(const char * t, const char * s)
{
    int i=0, j=0;
    while(*(t+i))
    {
        if(*(t+i)==*(s+j))
            j++;
        else
            j=0;
        i++;
    }
    i=0;
    while(*(s+i))
        i++;
    if(i!=j)
        return 0;
    return 1;
}
int strindex(const char * t, const char * s)
{
    int i =0, j=0, k=0, l;
    while(*(s+i))i++;
    while(*(t+j))
    {
        if(*(t+j)==*(s+k))
        {
            l=j;
            while(*(t+l)==*(s+k))
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
