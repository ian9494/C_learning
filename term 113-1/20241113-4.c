#include <stdio.h>

int is_palindromic_sum(int a)
{
    int sum=0,reverse=0,reverse2=0,n=1,a2=a;
    while (a>=1)
    {
        reverse *=10;
        reverse += a%10;
        a/=10;
    }
    sum = a2 + reverse;
    
    while (sum >= 1) 
    {
        int digit = sum % 10;
        reverse2 = reverse2 * 10 + digit;
        sum /= 10;
    }

    return reverse2 == a2+reverse;
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n>=0)
    {
        if (is_palindromic_sum(n))
            printf("True\n");
        else
            printf("False\n");
        
        scanf("%d", &n); 
    }
    
    return 0; 
}