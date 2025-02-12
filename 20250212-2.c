#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) && (a != 0 || b != 0))
    {
        swap(&a, &b);
        printf("%d %d\n", a, b);
    }
    return 0;
}