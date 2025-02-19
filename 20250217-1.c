#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *const numPtr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (numPtr[j] < numPtr[j + 1]) {
                swap(&numPtr[j], &numPtr[j + 1]);
            }
        }
    }
}

int main() {
    int numbers[3];

    printf("enter three integers\n>");
    scanf("%d %d %d", &numbers[0], &numbers[1], &numbers[2]);

    sort(numbers, 3);

    printf("results: %d %d %d\n", numbers[0], numbers[1], numbers[2]);

    return 0;
}
