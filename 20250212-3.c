#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[14];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        char *area, *num1, *num2;

        area = strtok(input, "()");
        if (area == NULL) continue;

        num1 = strtok(NULL, "-");  
        num2 = strtok(NULL, "\n"); 

        if (num1 == NULL || num2 == NULL) continue;

        long num3    = atol(num1) * 10000 + atol(num2);

        printf("%s - %ld\n", area, num3);
    }
    return 0;
}
