#include <stdio.h>

int main()
{
    float interest,principal,rate,days;
    scanf("%f %f %f",&principal, &rate, &days);  
    if (principal != 0)
    {
        do
        {
            interest = (principal*(rate*0.01)*days)/365;
            printf("%.2f\n", interest);
            scanf("%f %f %f",&principal, &rate, &days);
        } while (principal != 0);
    }
    
    
    
    return 0;
}