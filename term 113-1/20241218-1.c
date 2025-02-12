#include <stdio.h>

void swap(int *num1, int *num2)
{
     int temp;
     temp = *num1;
     *num1 = *num2;
     *num2 = temp;
}

int main()
{
    int a;
    int b;
    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a==0 && b==0)
            return 0;
        swap(&a, &b);
        printf("%d %d\n", a, b);

    }
    

    
    return 0;
}