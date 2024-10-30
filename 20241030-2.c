#include <stdio.h>
#include <math.h>

void check(int a)
{
    int a2, a3, sum, c=1, t;
    a2 = a;
    a3 = a;
    if (a<10)
        printf("Yes\n");
    else
        {
            a2=a;
            c=1;
            while (a2>10)
            {
                a2=a2/10;
                c++;
            }
            sum=0;
            while (a>0)
            {
                t=a%10;
                a=a/10;
                sum = sum+(pow(t,c));
            }
            if (sum==a3)
                printf("Yes\n");
            
            else
                printf("No\n");
                      
        }
}

int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        if (a<0)
            break;

        else
            check(a);       
    }
    return 0;
}