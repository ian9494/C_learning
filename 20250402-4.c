// 用指標交換兩個字串的內容 並轉換為大寫 直到EOF
// 字串以空格分開

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    char *p1 = str1, *p2 = str2;
    while (scanf("%s %s", p1, p2) != EOF) {
        // 交換字串內容
        char temp[100];
        strcpy(temp, p1);
        strcpy(p1, p2);
        strcpy(p2, temp);

        // 轉換為大寫
        for (int i = 0; p1[i] != '\0'; i++) {
            p1[i] = toupper(p1[i]);
        }
        for (int i = 0; p2[i] != '\0'; i++) {
            p2[i] = toupper(p2[i]);
        }

        printf("%s %s\n", p1, p2);
    }
    return 0;
}