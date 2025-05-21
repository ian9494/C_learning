#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// 計算數字的位數和
int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// 判斷是否為質數
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// 計算質因數的位數和
int factor_digit_sum(int n) {
    int sum = 0;
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) { // 因為質數會被先消去 所以後面判定的因數也一定是質數
            sum += digit_sum(i);
            n /= i;
        }
        i++;
    }
    if (n > 1) {
        sum += digit_sum(n);
    }
    return sum;
}

// 找到下一個史密斯數
int find_smith(int start) {
    int n = start + 1;
    while (1) {
        if (!is_prime(n) && digit_sum(n) == factor_digit_sum(n)) {
            return n;
        }
        n++;
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", find_smith(n));
    }
    return 0;
}
