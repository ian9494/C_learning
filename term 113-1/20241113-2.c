#include <stdio.h>

int fibonacci(int a)
{
    int n1=0, n2=1, temp;
    for (int i = 0; i < a; i++)
    {
        temp = n2;
        n2 = n1+n2;
        n1 = temp;
    }

    return n1;
}

int main()
{
    int n;
    scanf("%d", &n); 
    
    while (n>=0)
    {
        printf("%d\n",fibonacci(n));
        scanf("%d", &n); 
    }
    
    return 0;
}