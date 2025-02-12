#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    while (a!=0)
    {
        int sum = 0;
        if (a%2 == 0)
        {
            printf("Not an odd number\n");
            scanf("%d", &a);
            continue;
        }
        for (int i = 1; i <= a; i=i+2)
            sum += i;
        printf("%d\n", sum);
        scanf("%d", &a);
    }
    

    return 0;
}