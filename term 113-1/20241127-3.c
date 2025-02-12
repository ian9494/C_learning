#include <stdio.h>

int GCD(int i, int j)
{
    while (j != 0)
    {
        int temp = j;
        j = i % j;
        i = temp;
    }
    return i;
}

int main()
{
    int n;
    long G;
    while (scanf("%d", &n)==1 && n!=0)
    {
        G=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                G += GCD(i,j);
            }
        }
        printf("%ld\n", G);
    }
    
    return 0;
}