#include <stdio.h>
#include <stdlib.h>
#include "nauka.h"
int main()
{
    char *s = "ala ma koty";
    char *p = calloc(strlen(s) + 1, sizeof(char));
    strcpy(p,s);
    printf("%s\n", s);
    printf("%s\n", p);
    strncpy(p,s,11);
    printf("%s\n", s);
    printf("%s\n", p);
    char * r = calloc(100, sizeof(char));
    *(r+0) = 'j';
    *(r+1) = 'a';
    *(r+2) = 'k';
    *(r+3) = 'i';
    *(r+4) = 'e';
    *(r+5) = 's';
    *(r+6) = ' ';
    *(r+7) = 's';
    *(r+8) = 'l';
    *(r+9) = 'o';
    *(r+10) = 'w';
    *(r+11) = 'o';
    *(r+12) = 0;
    strcat(r,s);
    printf("%s\n", s);
    printf("%s\n", r);
    strncat(r,s,12);
    printf("%s\n", s);
    printf("%s\n", r);
    printf("%d\n",strend(r,s));
    printf("%d\n",strindex(r,s));
    free(p);
    free(r);
    return 0;
}
