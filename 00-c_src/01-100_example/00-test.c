#include <stdio.h>
#include <stdlib.h>
#define N 15
int main()
{
    int i;
    int j;
    int a[N][N];
    for(i=0;i<N;i++)
    {
        a[i][0]=1;
        a[i][i]=1; 
    }
    for(i=2;i<N;i++)
    {
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
            printf("%5d ",a[i][j]);
        printf("\n");


    }

}
