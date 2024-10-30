#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a>30)   
    {
        printf("September has only 30 days.");
    }
    else if (a<1)
    {
        printf("The number of days can only be entered as positive integers.");
    }
    else
    {
        int b = a%7;
        if (b==1)
        {
            printf("Sunday");
        }
        else if (b==2)
        {
            printf("Monday");
        }
        else if (b==3)
        {
            printf("Tuesday");
        }
        else if (b==4)
        {
            printf("Wednesday");
        }
        else if (b==5)
        {
            printf("Thursday");
        }
        else if (b==6)
        {
            printf("Friday");
        }
        else if (b==0)
        {
            printf("Saturday");
        }
        

    }
    
    
    
    return 0;
}