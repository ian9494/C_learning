#include <stdio.h>

int main() {
    int c;
    int quote_open = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (quote_open == 0) {
                printf("``");
                quote_open = 1;
            } else {
                printf("''");
                quote_open = 0;
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
