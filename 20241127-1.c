#include <stdio.h>

void move(int n,char from, char temp, char target)
{
    if (n == 1)
        {
            printf("Move ring 1 from %c to %c\n", from, target);
            return;
        }

    move(n-1, from, target, temp);
    printf("Move ring %d from %c to %c\n",n, from, target);
    move(n-1, temp, from, target);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        move(n,'A','B','C');
        printf("\n");
    }   
    return 0;
}