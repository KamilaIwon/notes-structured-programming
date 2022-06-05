#include <stdio.h>
#include "nauka.h"

char * strcpy(char * t, const char * s)
{
    char * p = t;
    while((*t++=*s++))
        ;
    return p;
}
size_t strlen(const char * s)
{
    size_t i=0;
    while(*s++)
        i++;
    return i;
}
char * strncpy(char * t, const char * s, size_t n)
{
    char * p = t;
    int i=0;
    while(*(s+i))
        i++;
    if(n>i)
        n=i;
    i=0;
    while(i<n)
    {
        *(t+i)=*(s+i);
        i++;
    }
    *(t+i)=0;
    return p;
}
char * strcat(char * t, const char * s)
{
    char * p = t;
    int i=0, j=0;
    while(*(t+j))
        j++;
    while(*(s+i))
    {
        *(t+j)=*(s+i);
        i++;
        j++;
    }
    *(t+j)=0;
    return p;
}
char * strncat(char * t, const char * s, size_t n)
{
    char * p = t;
    int i=0, j=0;
    while(*(t+j))
        j++;
    while(*(s+i))
        i++;
    if(n>i)
        n=i;
    i=0;
    while(i<n)
    {
        *(t+j)=*(s+i);
        i++;
        j++;
    }
    *(t+j)=0;
    return p;
}
int strend(const char * t, const char * s)
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
    int i=0, j=0, k=0, l;
    while(*(s+i))
        i++;
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
            if(i==k)
                return j;
            k=0;
        }
        j++;
    }
    return -1;
}
