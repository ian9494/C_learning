#include <stdio.h>

int main()
{
    int a;
    float b,c;
    scanf("%d", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    printf("Number:%d\n", a);
    printf("Height:%.1f\n", b);
    printf("Weight:%.2f\n", c);
    b = b/100;
    printf("BMI:%.1f", (c/(b*b)));
    
    return 0;
}