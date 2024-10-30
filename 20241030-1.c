#include <stdio.h>

void grade(int a)
{
    if (a > 100)
        printf("Score can only be entered between 0 and 100.\n");
    else if (a >= 90)
        printf("The grade is: A\n");
    else if (a >= 80)
        printf("The grade is: B\n");
    else if (a >= 70)
        printf("The grade is: C\n");
    else if (a >= 60)
        printf("The grade is: D\n");
    else
        printf("The grade is: E\n");
}

int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        if (a<1)
            return 0;
        else
            grade(a);   
    }
    return 0;
}