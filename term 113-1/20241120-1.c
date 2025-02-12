#include <stdio.h>

float Total(float x,int n)
{
    float x1=x,r=0;
    int n1=n;
    r += x1;
    for (n1; n1 > 1; n1--)
    {
        x1 /= 2;
        r += x1*2;
    }
    return r;
}

int main()
{
    int n;
    float x,r;
    while (1)
    {
        scanf("%f", &x);
        if (x==0)
            return 0;
        scanf("%d",&n);
        while (n < 1)
        {
            printf("The number of n needs big than 0\n");
            scanf("%d",&n);
        }
        r = Total(x,n);
        printf("The total meters of the  falling road after %d time falls down from %.2f meters is %.2f meters\n", n,x,r);
    }
    
    return 0;
}