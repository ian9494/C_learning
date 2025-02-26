#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000  // 設定最大輸入長度

int main() {
    char line[MAX_LENGTH];

    // 讀取多行輸入直到 EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // 使用 strtok() 來分割單字，考慮標點符號
        char *word = strtok(line, " ',.!?\n");

        while (word != NULL) {
            // 檢查是否以 "Th" 開頭
            if (strlen(word) >= 2 && strncmp(word, "Th", 2) == 0) {
                printf("%s\n", word);
            }

            // 取得下一個單字
            word = strtok(NULL, " ,.!?\n");
        }
    }

    return 0;
}
