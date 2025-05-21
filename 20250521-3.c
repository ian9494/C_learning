#include <stdio.h>
#include <stdbool.h>

#define MAX_N 3500
#define PRIME_LIMIT 40000

int primes[MAX_N];

void generate_primes() {
    bool is_prime[PRIME_LIMIT];
    for (int i = 0; i < PRIME_LIMIT; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    int count = 0;
    for (int i = 2; count < MAX_N && i < PRIME_LIMIT; i++) {
        if (is_prime[i]) {
            primes[count++] = i;
            for (int j = i * 2; j < PRIME_LIMIT; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    generate_primes();
    int n;
    while (scanf("%d", &n) && n != 0) {
        int circle[MAX_N], size = n;
        for (int i = 0; i < n; i++) circle[i] = i + 1;

        int index = 0;
        for (int round = 0; size > 1; round++) {
            int step = primes[round];
            index = (index + step - 1) % size;

            // 刪掉 index
            for (int j = index; j < size - 1; j++) {
                circle[j] = circle[j + 1];
            }
            size--;

            if (index == size) index = 0;
        }

        printf("%d\n", circle[0]);
    }
    return 0;
}
