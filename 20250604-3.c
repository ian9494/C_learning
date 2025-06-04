#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 32768

// 判斷質數
int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    return 1;
}

// 生成前幾個質數
int primes[MAX], prime_count = 0;
void generate_primes() {
    for (int i = 2; i < MAX; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }
}

// 質因數分解，結果儲存在 result 陣列，回傳個數
int factorize(int n, int result[][2]) {
    int cnt = 0;
    for (int i = 0; i < prime_count && primes[i] <= n; i++) {
        int p = primes[i];
        if (n % p == 0) {
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                exp++;
            }
            result[cnt][0] = p;
            result[cnt][1] = exp;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    generate_primes();
    char line[256];

    while (fgets(line, sizeof(line), stdin)) {
        int nums[128], n = 0;
        char *ptr = line;
        if (line[0] == '0') break;

        // 讀入 prime base 整數序列
        while (sscanf(ptr, "%d", &nums[n]) == 1) {
            while (*ptr != ' ' && *ptr != '\0') ptr++;
            while (*ptr == ' ') ptr++;
            n++;
        }

        // 計算整數值
        int value = 1;
        for (int i = 0; i < n; i += 2) {
            int base = nums[i], exp = nums[i + 1];
            for (int j = 0; j < exp; j++) {
                value *= base;
            }
        }

        value--;  // 做減一運算

        // 質因數分解
        int result[64][2];
        int cnt = factorize(value, result);

        // 反向輸出
        for (int i = cnt - 1; i >= 0; i--) {
            printf("%d %d", result[i][0], result[i][1]);
            if (i > 0) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
