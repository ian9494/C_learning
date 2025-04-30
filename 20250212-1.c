#include <stdio.h>

// 輸入一個整數 n，然後輸入 n 個整數，最後輸出這 n 個整數的陣列形式
// 例如：輸入 5 1 2 3 4 5，則輸出 A[5]={1,2,3,4,5}
void output(int *arr, int size) {
    printf("A[%d]={", size);
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

int main() {
    int n = 1;
    while (scanf("%d", &n) && n != 0) { 
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        output(arr, n);
        free(arr);
    }
    return 0;
}
