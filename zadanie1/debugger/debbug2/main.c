#include <stdio.h>
#include <stdlib.h>

int foo(int*a,int*b)
{
    return *a-*b;
}

int main()
{
    int tab[] = {5,5,0,2,-3,0,9,3,4};
    int *wsk=tab-1;
    int b = *(wsk+=4); //b=2
    int c = b+2; // b=2  , c=4
    int d = foo(&b,&c); // b=2  , c=4  , d=-2
    int e = (wsk+=-1)[3]; // b= 2 , c=4  , d=-2  , e=0
    e = (d -= 2) + (c += 2); // b=2  , c=6  , d=-4  , e=2
    c = d + (b+=4); // b=6  , c=2  , d=-4  , e=2
    b = *wsk + e; // b=2  , c=2  , d= -4 , e=2
    b= (--c)-(d++);  // b=5  , c=1  , d=-3  , e=2
    return 0;
}
