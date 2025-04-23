#include <stdio.h>

#define TARGE_PRIME 131071

int main() {
    char c;
    int mod = 0;

    while ((c = getchar()) != EOF) {
        if (c == '#') {
            if (mod == 0)
                printf("YES\n");
            else
                printf("NO\n");
            mod = 0; // reset for next binary number
        } else if (c == '0' || c == '1') {
            mod = (mod * 2 + (c - '0')) % TARGE_PRIME;
        }
    }

    return 0;
}
