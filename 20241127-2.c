#include <stdio.h>

int birth(int n)
{
    if (n <= 1)
        return 1;
    return birth(n-1) + birth(n-2);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("f[%d]:%d\n", n, birth(n));
    }
    return 0;
}