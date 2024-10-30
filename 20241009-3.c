#include <stdio.h>
#include <math.h>

int main()
{
    int a,a2,a3,sum,t,c=1;
    while (1)
    {
        scanf("%d", &a);
        a3=a;
        if (a<=0)
        {
            break;
        }
        else if (a<10)
        {
            printf("Yes\n");
        }
        
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
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }          
        }
    }
    return 0;
}