#include <stdio.h>

void perfection(int a)
{
    int sum=0;
    for (int i = 1; i < a; i++)
    {
        if (a%i==0)
            sum += i;
    }
    if (a==sum)
        printf("PERFECT\n");
    else if (a<sum)
        printf("ABUNDANT\n");
    else if (a>sum)
        printf("DEFICIENT\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n!=0)
    {
        perfection(n);
        scanf("%d", &n); 
    }
    
    return 0;
}