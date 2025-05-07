#include <stdio.h>

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
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