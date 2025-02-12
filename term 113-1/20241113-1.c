#include <stdio.h>

int factorial(int a)
{
    int result=1;
    for (int i = 1; i <= a; i++)
        result *= i;
    
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n>=1 && n<10)
    {
        if (n==0)
            return 0;
        printf("%d!=%d\n", n, factorial(n));
        scanf("%d", &n); 
    }
    
    return 0;
}