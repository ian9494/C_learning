#include <stdio.h>

int main()
{
    int digit,count=0,sum=0;
    float average=0;
    scanf("%d", &digit);
    while (digit != 0)
    {
        int count=0,sum=0;
        for (int i = 1; i <= 100; i++)
        {
            if ((i%digit)==0)
            {
                sum += i;
                count++;
            }    
        }
        average = (float)sum/(float)count;
        printf("%d %.2f\n", sum, average);
        scanf("%d", &digit);

    }
    return 0;
}