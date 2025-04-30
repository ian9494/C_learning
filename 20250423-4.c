#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B;
    while (scanf("%d %d", &A, &B) == 2 && (A || B)) {
        int alice[10000], betty[10000];

        for (int i = 0; i < A; i++) scanf("%d", &alice[i]);
        for (int i = 0; i < B; i++) scanf("%d", &betty[i]);

        // 用存在陣列模擬 set
        int aliceMark[100001] = {0};
        int bettyMark[100001] = {0};

        for (int i = 0; i < A; i++) aliceMark[alice[i]] = 1;
        for (int i = 0; i < B; i++) bettyMark[betty[i]] = 1;

        int aliceUnique = 0, bettyUnique = 0;

        for (int i = 0; i <= 100000; i++) {
            if (aliceMark[i] && !bettyMark[i]) aliceUnique++;
            if (bettyMark[i] && !aliceMark[i]) bettyUnique++;
        }

        printf("%d\n", aliceUnique < bettyUnique ? aliceUnique : bettyUnique);
    }

    return 0;
}
