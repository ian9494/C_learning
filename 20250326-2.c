#include <stdio.h>
#include <stdlib.h>

// 比較用的函式（遞增排序）
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int numbers[15];
    int count = 0;

    // 依序讀取 15 個數
    while (count < 15) {
        scanf("%d", &numbers[count]);
        count++;

        // 每 3 個數輸入完畢就印出排序後的結果
        if (count % 3 == 0) {
            int temp[15];
            for (int i = 0; i < count; i++) {
                temp[i] = numbers[i];
            }

            qsort(temp, count, sizeof(int), compare);

            for (int i = 0; i < count; i++) {
                printf("%d", temp[i]);
                if (i < count - 1) printf(" ");
            }
            printf("\n");
        }
    }

    // 計算總和與平均
    int sum = 0;
    for (int i = 0; i < 15; i++) {
        sum += numbers[i];
    }

    double avg = (double)sum / 15.0;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}
