#include <stdio.h>

int main()
{
    int n, a[100];

    while (scanf("%d", &n) != EOF && n!=0)
    {
        if (n<0 || n>100)
        {
            printf("Need to small than 100.\n");
            continue;
        }
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        
        //original
        printf("Original: ");
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        //sort
        for (int i=0; i < n-1; i++) {
            for (int j=0; j < n-i-1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        //odd&even
        printf("Odd: ");
        for (int i = 0; i < n; i++)
        {
            if (a[i]%2==1)
                printf("%d ", a[i]);
        }
        printf("\n");

        printf("Even: ");
        for (int i = 0; i < n; i++)
        {
            if (a[i]%2==0)
                printf("%d ", a[i]);
        }
        printf("\n");
        }   

    return 0;
}