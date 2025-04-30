#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int T;
    while (scanf("%d", &T) == 1) {
        while (T--) {
            int r;
            scanf("%d", &r);
            int s[500];

            for (int i = 0; i < r; i++) {
                scanf("%d", &s[i]);
            }

            qsort(s, r, sizeof(int), compare);
            int median;
            if (r % 2 == 0) {
                median = (s[r / 2 - 1] + s[r / 2]) / 2;
            } else {
                median = s[r / 2];
            }

            int total = 0;
            for (int i = 0; i < r; i++) {
                total += abs(s[i] - median);
            }

            printf("%d\n", total);
        }
    }
    return 0;
}
