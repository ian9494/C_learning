#include <stdio.h>

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod; // 確保 base 在 mod 範圍內

    // 使用快速冪算法，將指數運算的時間複雜度從 O(exp) 降低到 O(log(exp))
    while (exp > 0) { 
        if (exp % 2 == 1) // 當 exp 是奇數時，將 base 累乘到結果中
            result = (result * base) % mod;
        base = (base * base) % mod; // 將 base 平方，減少指數
        exp /= 2; // 將指數減半
    }
    return result;
}

int main() {
    long long B, P, M;
    while (scanf("%lld", &B) != EOF) {
        scanf("%lld %lld", &P, &M);
        printf("%lld\n", mod_pow(B, P, M));
    }
    return 0;
}