#include <stdio.h>
#include <string.h>

#define MAX_LEN 35

// 把二進位字串轉成十進位 long long
long long binary_to_ll(char *s) {
    long long result = 0;
    for (int i = 0; s[i]; i++) {
        result = result * 2 + (s[i] - '0');
    }
    return result;
}

// 計算兩個 long long 的 GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);
    char s1[MAX_LEN], s2[MAX_LEN];

    for (int i = 1; i <= t; i++) {
        scanf("%s %s", s1, s2);
        long long num1 = binary_to_ll(s1);
        long long num2 = binary_to_ll(s2);

        if (gcd(num1, num2) > 1)
            printf("Pair #%d: All you need is love!\n", i);
        else
            printf("Pair #%d: Love is not all you need!\n", i);
    }

    return 0;
}
