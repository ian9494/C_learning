#include <stdio.h>

int main()
{
    int a,b;
    float c=800.00, d=1000.00,e;
    scanf("%d %d", &a,&b);
    if (a==1 || a==2)
    {
        if (b==1)
        {
            if (a==1)
                printf("Discounts are available for groups of two or more.\nThe regular price for the selected time slot is %.2f", c);
            else
                printf("Discounts are available for groups of two or more.\nThe regular price for the selected time slot is %.2f", d);
            
        }
        else if (b>1)
        {
            if (b==2)
                e=0.9;
            
            else if (b==3)
                e=0.85;
            
            else if (b==4)
                e=0.75;
            
            else
                e=0.7;
                       
            if (a==1)
                printf("The discounted price for %d people is %.2f", b, c*e);

            else
                printf("The discounted price for %d people is %.2f", b, d*e);
            
        }    
    }
    else
        printf("Only time slots 1 and 2 are available.");
    return 0;
}