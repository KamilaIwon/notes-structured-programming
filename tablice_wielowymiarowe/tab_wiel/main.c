#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showtable(int tab[][3], int n,int m);
void zmien(int tab[][3], int n,int m);
void zmienwiersze(int tab[][3], int w1, int w2, int m);
int sumaelementow(int tab[][3], int n,int m);
double sredniawwierszu(int tab[][3], int n,int m);
void zmienwiersze2(int tab[][3], int w1, int w2, int w3, int m);
void showtablekw(int tab[][2], int n,int m);
void sumamacierzy(int tab[][2],int tab2[][2], int n,int m);
void losuj(int tab[][2], int n,int m);
int main()
{
    int tab[3][3] = {{4,5,6},{1,2,3},{7,8,9}};
    int tab2[2][2] = {{1,2},{3,4}};
    int tab3[2][2] = {{3,6},{8,1}};
    printf("Tablica przed:\n");
    showtable(tab,3,3);
    printf("Tablica po:\n");
    zmienwiersze(tab,0,1,3);
    showtable(tab,3,3);
    printf("\n suma elementow: %d",sumaelementow(tab,3,3));
    printf("\n najwieksza srednia w wierszu: %lf",sredniawwierszu(tab,3,3));
    printf("\nTablica po:\n");
    zmienwiersze2(tab,0,1,2,3);
    showtable(tab,3,3);
    printf("\n\n\n");
    showtablekw(tab2,2,2);
    showtablekw(tab3,2,2);
    sumamacierzy(tab2,tab3,2,2);
    losuj(tab2,2,2);
    return 0;
}
void showtable(int tab[][3], int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}
void zmienwiersze(int tab[][3], int w1, int w2, int m)
{
    for(int i =0;i<m;i++)
    {
        int t = tab[w1][i];
        tab[w1][i] = tab[w2][i];
        tab[w2][i] = t;
    }
}
void zmienwiersze2(int tab[][3], int w1, int w2, int w3, int m)
{
    int t, k;
    for(int i =0;i<m;i++)
    {
        t = tab[w1][i];

        tab[w1][i] = tab[w2][i];
        tab[w2][i] = tab[w3][i];
        tab[w3][i] = t;
    }
}
void zmien(int tab[][3], int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tab[i][j]%2==0)
            {
                tab[i][j]=0;
            }
            else
            {
                tab[i][j]=1;
            }
        }
    }
}
int sumaelementow(int tab[][3], int n,int m)
{
    int suma = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            suma += tab[i][j];
        }
    }
    return suma;
}
double sredniawwierszu(int tab[][3], int n,int m)
{
    int s1=0,s2=0,s3=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0) s1+= tab[i][j];
            if(i==1) s2+= tab[i][j];
            if(i==2) s3+= tab[i][j];
        }
    }
    s1 /= 3;
    s2 /= 3;
    s3 /= 3;

    if(s1>s2)
    {
        if(s1>s3) return s1;
        else
        {
            if(s3<s1) return s3;
        }
    }
    if(s2>s1)
    {
        if(s2>s3) return s2;
        else
        {
            if(s3>s2) return s3;
        }
    }
    if(s3>s1)
    {
        if(s3>s2) return s3;
        else
        {
            if(s2>s3) return s2;
        }
    }
}
void showtablekw(int tab[][2], int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void sumamacierzy(int tab[][2],int tab2[][2], int n,int m)
{
    int macierz[2][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            macierz[i][j]= tab[i][j] + tab2[i][j];
            printf("%d ",macierz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void losuj(int tab[][2], int n,int m)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            tab[i][j] = rand()%101;
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
