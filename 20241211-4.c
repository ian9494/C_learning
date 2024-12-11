#include <stdio.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; t++) {
        char input[200];
        int a = 0, b = 0;
        char calc = '\0';
        int is_b = 0; // 標記當前是否在讀取 b

        scanf("%s", input);

        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i])) {
                // 如果是數字，累積到對應的數值
                if (is_b) {
                    b = b * 10 + (input[i] - '0');
                } else {
                    a = a * 10 + (input[i] - '0');
                }
            } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%') {
                // 如果遇到運算符，就要進入 b 的讀取階段
                calc = input[i];
                is_b = 1;
            }
        }

        int result = 0;
        switch (calc) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            case '%': result = a % b; break;
        }

        printf("%d\n", result);
    }

    return 0;
}
