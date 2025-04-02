#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (!in || !out) {
        printf("File error!\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        int i = 0;
        while (line[i] != '\0' && line[i] != '\n') {
            int count = 0;

            // 讀數字（支援多位數）
            while (isdigit(line[i])) {
                count = count * 10 + (line[i] - '0');
                i++;
            }

            // 接下來是字母
            char ch = line[i++];

            // 印出 count 次
            for (int j = 0; j < count; j++) {
                fputc(ch, out);
            }
        }
        fputc('\n', out); // 每筆資料結束換行
    }

    fclose(in);
    fclose(out);
    return 0;
}
