#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a>100 || a<0)
    {
        printf("Score can only be entered between 0 and 100.");
    }
    
    else if (a>=90)
    {
        printf("The grade is: A");
    }
    else if (a>=80)
    {
        printf("The grade is: B");
    }
    else if (a>=70)
    {
        printf("The grade is: C");
    }
    else if (a>=60)
    {
        printf("The grade is: D");
    }
    else
    {
        printf("The grade is: E");
    }
    return 0;
}