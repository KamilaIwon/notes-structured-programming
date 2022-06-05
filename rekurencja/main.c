#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

unsigned int task_6(unsigned int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else if (n % 2 == 0 && n > 0) {
    return task_6(n / 2) + 2;
  }
  return task_6(n - 1) - (n - 1) / 2;
}

int rekurecja1(int n)
{
    if(n==0) return 0;
    if(n==1) return 3;

    return (3 * (pow(10,(n-1))) + rekurecja1(n-1)) + rekurecja1(n-1);
}

void parzyste(int n)
{
    if(n==1) return;
    if(n%2==0) printf("\n%d", n);
    parzyste(n-1);

}

int main()
{
    printf("wynik: %d", rekurencja(0));
    printf("\nwynik: %d", rekurencja(3));
    printf("\nwynik: %d", task_6(3));
    printf("\nwynik: %d", rekurecja1(4));
    parzyste(10);
    return 0;
}
