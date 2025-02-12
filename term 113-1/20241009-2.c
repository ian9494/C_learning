#include <stdio.h>

int main()
{
    int a,n=0,max=0;
    while (n<10)
    {
        scanf("%d", &a);
        if (max<a)
        {
            max=a;
        }
        n++;
    }
    printf("%d", max);
    
    return 0;
}