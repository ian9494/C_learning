#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void Odd_Even(int n)
{
    if (n%2==0)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
}

void Prime_number(int n)
{
    if (isPrime(n)==false)
        {
            printf("%d is not a Prime number\n", n);
            for (int i = n; i > 0; i--)
            {
                if (isPrime(i))
                {
                    printf("The nearest Prime number less than %d is %d\n",n,i);
                    break;`
                }
            }
            
        }
    else if (isPrime(n))
        printf("%d is a Prime number\n", n);   
}

int main()
{
    int n;
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            return 0;
        if (n<0)
        {
            printf("Need to big than 0.\n");
            continue;
        }
        Odd_Even(n);
        Prime_number(n);
    }
    
    return 0;
}