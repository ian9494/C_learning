#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    
    do
    {
        if (abs(a+b)>c && abs(b+c)>a && abs(a+c)>b && abs(a-b)<c && abs(b-c)<a && abs(a-c)<b)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d %d %d", &a,&b,&c);
    } while (a != 0 || b!= 0 || c != 0);
    return 0;
}
