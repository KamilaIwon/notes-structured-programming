#include <stdio.h>
#include <stdlib.h>

int main()
{
    char napis1[20]="Siem a12;";
    int i=0;
    int ile1=0, ile2=0, ile3=0;
    while(napis1[i]!=0)
    {
        if(napis1[i]>='a' && napis1[i]<='z') ile1++;
        if(napis1[i]>='A' && napis1[i]<='Z') ile2++;
        if(napis1[i]>='1' && napis1[i]<='9') ile3++;
        i++;
    }
    printf("%d",ile1+ile2+ile3);
    return 0;
}
