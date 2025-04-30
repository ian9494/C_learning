#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, R;
    int *ptr_N = &N, *ptr_R = &R;

    while (scanf("%d %d", ptr_N, ptr_R) != EOF) {
        int arr[N + 1];       // 用來記錄哪些人有回報（1~N）
        int *ptr_arr = arr;

        for (int i = 1; i <= N; i++) {
            *(ptr_arr + i) = 0;  // 未回報
        }

        for (int i = 0; i < R; i++) {
            int x;
            scanf("%d", &x);
            *(ptr_arr + x) = 1;  // 標記有回報
        }

        int hasMissing = 0;

        for (int i = 1; i <= N; i++) {
            if (*(ptr_arr + i) == 0) {
                printf("%d ", i);
                hasMissing = 1;
            }
        }

        if (!hasMissing) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
