#include <stdio.h>

int calc(int a)
{
    int i=1,sum=0;
    while (a>0)
    {
        sum += (a%10)*i;
        a /= 10;
        i *= 2;
    }
    return sum;
}

int main()
{
    int digit,i=1,sum=0;
    scanf("%d", &digit);
    while (digit != 0)
    {
        printf("%d\n", calc(digit));
        scanf("%d", &digit);
    }
    return 0;
}