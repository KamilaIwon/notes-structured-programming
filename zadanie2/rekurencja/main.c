#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//wz�r
int rekurencja(unsigned int a)
{
    if(a==0 || a==1)
    {
        return 1;
    }
    else if(a%2==0)
    {
        return rekurencja(a/2)+2;
    }
    return rekurencja(a-1) - (a-1)/2;
}

//zadanie dodatkowe
unsigned int task_6(unsigned int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else if (n % 2 == 0 && n > 0) {
    return task_6(n / 2) + 2;
  }
  return task_6(n - 1) - (n - 1) / 2;
}

//wyswietla liczby parzyste od 1 do n
void parzyste(unsigned int n)
{
    if(n==1) return;
    if(n%2==0) printf("\n%d", n);
    parzyste(n-1);

}
//podaj wynik: 1^3 + 2^3 + ... + n^3
int szescian(int n)
{
    if(n>0) return n*n*n + szescian(n-1);
    return 0;

}

// podaj sume liczb podzielnych przez 5 i 7 z przedzialu <1,n>
int sumapodzprzez6i7(unsigned int n)
{
    if(n==0) return 0;
    if(n%5==0 || n%7==0) return n + sumapodzprzez6i7(n-1);
    return sumapodzprzez6i7(n-1);

}
//jakis tam wzor
int rek5( unsigned int n)
{
    if(n==0 || n==1) return 1;
    if(n%2==0)
    {
        return rek5(n/2) + 1;
    }
    return rek5(n-1) + (n-1)/2;
}

//wypisz liczby parzyste z przedzialu <0,n>
void podamnieparzyste(unsigned int n)
{
    if(n==0) return;
    if(n%2!=0) printf("\n%d",n);
    podamnieparzyste(n-1);
}

//jakis tam wzor
int rekurencja1(unsigned int n)
{
    if(n==0) return 1;
    if(n==1) return 2;
    if(n%2==0) return rekurencja1(n-1) + 2;
    return rekurencja1(n-2)*3;
}
//suma 3 + 33 + 333 ...
int foo(int n){
    if(n==1){
        return 3;
    }
    return foo(n-1)*10+3;
}
int fooo(int n){
    int suma = 0;
    for(int i=1;i<n+1;i++){
        suma += foo(i);
    }
    return suma;
}

//zadanie z zerowki
int zerowka(int n, float x)
{
    if(n==1) return 1;
    if(n>1) return (pow(-1,n))*(pow(x,n)/n) + zerowka(n-1,x);
    return 0;
}


int main()
{
    printf("wynik: %d", rekurencja(0));
    printf("\nwynik: %d", rekurencja(3));
    printf("\nwynik: %d", task_6(3));
    parzyste(10);
    printf("\nszescian: %d", szescian(4));
    printf("\nsuma podzielnych przez 6 i 7: %d", sumapodzprzez6i7(10));
    printf("\nrekurencja 5: %d", rek5(3));
    //unsigned int liczba;
    //printf("\npodaj liczbe nieujemna wieksza od 1: ");
    //scanf("%d", &liczba);
    //podamnieparzyste(liczba);
    printf("\n%d",fooo(3));
    printf("\nrekurencja1: %d", rekurencja1(5));
    printf("\nzerowka: %d", zerowka(1,2));
    return 0;
}
