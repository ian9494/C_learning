#include <stdio.h>

void Coordinate(int x, int y)
{
    if (x==0 || y==0)
        printf("On Axis\n");
    else if (x>0 && y>0)
        printf("On 1\n");
    else if (x<0 && y>0)
        printf("On 2\n");
    else if (x<0 && y<0)
        printf("On 3\n");
    else if (x>0 && y<0)
        printf("On 4\n");  
}

int main()
{
    while (1)
    {
        int x,y;
        scanf("%d %d", &x,&y);
        if (x==0 && y==0)
            return 0;
        Coordinate(x,y);
    }
    
    return 0;
}