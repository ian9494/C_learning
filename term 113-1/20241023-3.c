#include <stdio.h>

int main()
{
    float a;
    while (1)
    {
        float sum=0;
        for (int i = 1; i < 6; i++)
        {
            scanf("%f", &a);
            switch (i)
            {
                case 1:
                    a *= 2.98;
                    break;
                case 2:
                    a *= 4.50;
                    break;
                case 3:
                    a *= 9.98;
                    break;
                case 4:
                    a *= 4.49;
                    break;
                case 5:
                    a *= 6.87;
                    break;
                
                default:
                    break;
            }
            sum += a;      
        }
        if (sum == 0)
            return 0;

        else
            printf("%.2f\n", sum);
    }
    
    return 0;
}