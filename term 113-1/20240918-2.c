#include <stdio.h>

int main()
{
    float a,b;
    printf("Enter 2 numbers.\n");
    printf("A:");
    scanf("%d", &a);
    printf("B:");
    scanf("%d", &b);
    // float c=a, d=b;
    printf("%.3f", a/b);
    return 0;
}