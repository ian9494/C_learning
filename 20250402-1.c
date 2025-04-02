// 判斷小、中、大括弧是否完整配對
// 這個程式會讀取一行字元，並判斷小括弧、中括弧、大括弧是否完整配對

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int stack[100], top = -1;
    int i, len, balanced = 1;

    while (fgets(str, sizeof(str), stdin) != NULL) {
        len = strlen(str);
        balanced = 1; // 重置平衡狀態

        for (i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                stack[++top] = str[i]; // 將開括弧推入堆疊
            } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
                if (top == -1) {
                    balanced = 0; // 堆疊為空，表示不平衡
                    break;
                }
                char open_bracket = stack[top--]; // 彈出堆疊頂部的開括弧
                if ((open_bracket == '(' && str[i] != ')') ||
                    (open_bracket == '[' && str[i] != ']') ||
                    (open_bracket == '{' && str[i] != '}')) {
                    balanced = 0; // 括弧不匹配
                    break;
                }
            }
        }

        if (balanced && top == -1) {
            printf("Yes\n"); // 完全平衡
        } else {
            printf("No\n"); // 不平衡或有剩餘的開括弧
        }
    }
}