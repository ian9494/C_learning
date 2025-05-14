#include <stdio.h>

int countDivisors(long long n) {
    int count = 1;
    for (long long i = 2; i * i <= n; i++) {
        int power = 0; // 計算質因數的次方
        while (n % i == 0) {
            power++;
            n /= i;
        }
        count *= (power + 1);
    }
    if (n > 1) count *= 2; // 自己是一個質數
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, u;
        scanf("%d %d", &l, &u);
        int maxDivisors = 0;
        int bestNumber = l;

        for (int i = l; i <= u; i++) {
            int divCount = countDivisors((long long)i);
            if (divCount > maxDivisors) {
                maxDivisors = divCount;
                bestNumber = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n",
               l, u, bestNumber, maxDivisors);
    }

    return 0;
}
