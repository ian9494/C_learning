#include <stdio.h>

int main()
{
    int digit,i=1,sum=0;
    scanf("%d", &digit);
    while (digit != 0)
    {
        int i=1,sum=0;
        while (digit>0)
        {
            sum += (digit%10)*i;
            digit /= 10;
            i *= 2;
        }
        printf("%d\n", sum);
        scanf("%d", &digit);
    }
    
    return 0;
}