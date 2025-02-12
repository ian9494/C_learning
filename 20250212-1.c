#include <stdio.h>

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
