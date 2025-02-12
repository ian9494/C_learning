#include <stdio.h>
#include <string.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// 計算字母數值和
int getWordValue(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            sum += word[i] - 'a' + 1; // 小寫字母數值 1 ~ 26
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            sum += word[i] - 'A' + 27; // 大寫字母數值 27 ~ 52
        }
    }
    return sum;
}

int main() {
    char word[21];
    while (scanf("%s", word) != EOF) {
        int sum = getWordValue(word);
        if (isPrime(sum)) {
            printf("It is a prime word.\n");
        } else {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}
