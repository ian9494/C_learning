#include <stdio.h>

int main()
{
    int t,n,h,last_h;
    int *ptr=NULL;
    ptr=&last_h;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int high_j=0, low_j=0; *ptr=0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &h);
            if (*ptr==0)
                *ptr=h;
            
            else if (h>*ptr)
            {
                high_j++;
                *ptr=h;
            }
            else if (h<*ptr)
            {
                low_j++;
                *ptr=h;
            }
            else if (h==*ptr)
                *ptr=h;
        }
        printf("Case %d: %d %d\n", i+1,high_j,low_j);
    }
    
}