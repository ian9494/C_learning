#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d", &a);
    b=a%4;
    c=a%100;
    d=a%400;

    if (d==0)
    {
        printf("%d is a leap year.", a);
    }
    else if (c!=0)
    {
        if (b==0)
        {
            printf("%d is a leap year.", a);
        }
        else
        {
            printf("%d is not a leap year.", a);
        }
        
    }
    else if (c==0 && a<1500)
    {
        printf("%d is a leap year.", a);
    }
    
    else
    {
        printf("%d is not a leap year.", a);
    }
    return 0;
}