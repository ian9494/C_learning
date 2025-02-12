#include <stdio.h>

int main()
{
    int a, largest=0;
    scanf("%d", &a);
    while (a!=0)
    {
        for (int i = 1; i <= a; i++)
        {
            for (int j = 2; j <= i; j++)
            {
                if (i%j==0 && (j!=i))
                    break;
                else if (i==j)
                    largest = i;           
            }
        }
    printf("%d\n", largest);
    scanf("%d", &a);
    }        
    return 0;
}