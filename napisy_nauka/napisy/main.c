#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* strcpy(char t[], const char s[]);
size_t strlen(const char []);
char* strncpy(char t[], const char s[], size_t n);
char* strcat(char t[], const char s[]);
char* strncat(char t[], const char s[], size_t n);
bool strend(const char s[], const char t[]);
int strindex(const char s[], const char t[]);
int main()
{
    char napis1[20];
    char napis2[] = "Siemano";
    //scanf("%s", napis1);
    gets(napis1);
    printf("napis: %s\n",napis1);
    printf("dlugosc napisu: %d", strlen(napis1));
    //strcpy(napis1,napis2);
    printf("\nnapis po strcpy: %s", strcpy(napis1,napis2));
    printf("\nnapis po strncpy: %s", strncpy(napis1,napis2,5));
    printf("\nnapisy po strcat: %s", strcat(napis1,napis2));
    printf("\nnapisy po strncat: %s", strncat(napis1,napis2,5));
    char napis3[] = "ma";
    char napis4[] = "Ala ma kotama";
    printf("\nnapis: %s, napis: %s", napis3,napis4);
    printf("\nczy napis 1 jest na koncu napisu 2: %d", strend(napis4,napis3));
    printf("\nczy zawiera w indeksie: %d", strindex(napis3,napis4));

    return 0;
}
char * strcpy(char t[], const char s[])
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
size_t strlen(const char s[])
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
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
bool strend(const char s[], const char t [])
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
