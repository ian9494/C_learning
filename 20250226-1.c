#include <stdio.h>

int main()
{
    int m, n, k;

    while (1)
    {
        scanf("%d %d %d", &m, &n, &k);
        if (m == 0 && n == 0 && k == 0)
            break;
        
            int *array = (int *)malloc(m * n * sizeof(int));
            int *a_ptr = array;
            int count = 0;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    scanf("%d", a_ptr + i * n + j);
                }
            }

            for (int i = 0; i < m*n; i++)
            {
                if ((*(a_ptr + i)) == k)
                {
                    count++;
                }
            }

            printf("%d\n", count);
    }
    
    return 0;
}