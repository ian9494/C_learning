#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    while ((fgets(word, sizeof(word), stdin)) != NULL) {
        // 移除換行符號
        word[strcspn(word, "\n")] = '\0';

        int i = 0;
        char s1[100];
        int j = 0;

        // 將字母存入 s1
        for (i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                s1[j] = word[i];
                j++;
            }
        }
        s1[j] = '\0'; // 確保字串結尾

        // 如果有字母，反轉字串
        if (j > 0) {
            for (int k = 0; k < j / 2; k++) {
                char temp = s1[k];
                s1[k] = s1[j - k - 1];
                s1[j - k - 1] = temp;
            }
            printf("%s\n", s1); // 輸出結果
        } else {
            printf("No letters found.\n");
        }
    }
    return 0;
}