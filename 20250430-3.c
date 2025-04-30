#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];

    while (fgets(input, sizeof(input), stdin) != NULL){
        int i = 0;
        int count = 0;

        while (input[i] != '\0') {
            if (isdigit(input[i])) {
                // 計算重複次數
                count = count + (input[i] - '0');
            } else if (input[i] == 'b') {
                for (int j = 0; j < count; j++) putchar(' ');
                count = 0;
            } else if (input[i] == '!') {
                putchar('\n');
            } else if (input[i] == '\n') {
                break;
            } else { // 一般符號（T, *, 等）
                for (int j = 0; j < count; j++) putchar(input[i]);
                count = 0;
            }
            i++;
        }
        printf("\n"); // 每行結束後換行
    }

    return 0;
}
