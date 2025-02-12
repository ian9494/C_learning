#include <stdio.h>

void sort(int *a,int *b,int *c)
{
    int temp;
    if (*a>*b)  
    {
        temp = *b;
        *b = *a;
        *a = temp;
    }
    if (*b>*c)
    {
        temp = *c;
        *c = *b;
        *b = temp;
    }
    if (*a>*b)  
    {
        temp = *b;
        *b = *a;
        *a = temp;
    }
    printf("%d %d %d\n", *a,*b,*c);
    
}

int main()
{
    int a,b,c;
    while (1)
    {
        scanf("%d %d %d", &a,&b,&c);
        if (a==0 && b==0 && c==0)
            return 0;
        sort(&a,&b,&c);    
    }
    
}