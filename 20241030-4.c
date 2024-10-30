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

int get_prime(int a)
{
    int first, second;
    //第一個數字
    while (1)
    {
        for (int i=1; i < a; i++)
        {
            if (isPrime(i))
            {
                first = i;
                second = a-first;
                if (isPrime(second))
                {
                    printf("%d %d\n", first, second);
                    return 0;
                }
                else
                    continue;
            }   
        }
    } 
}

int main()
{
    int digit, f_prime;
    scanf("%d", &digit);
    while (digit != 0)
    {
        if (digit==2 || digit%2!=0)
            printf("No answer!\n");
        else if (digit>10000)
            printf("Out of scope!\n");
        else
            get_prime(digit);
            
        scanf("%d", &digit);
    }
    return 0;
}