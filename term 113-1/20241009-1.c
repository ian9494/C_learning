#include <stdio.h>

int main()
{
    while (1)
    {
        int a,n=0,sum=0,t;
        float average;
        scanf("%d", &a);
        if (a<1)
        {
            printf("Out of range.\n");
        }
        else
        {
            while (n<a)
            {
            scanf("%d", &t);
            sum = sum+t;
            n++;
            }
        
            average = sum/a;
            printf("%d\n%.2f", sum, average);

            return 0;
        }
        
        
    }
    
    
}