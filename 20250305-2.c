#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_COUNT 26
#define MAX_ROW_LENGTH 100

int count[ALPHABET_COUNT];

// qsort 用的比較函數
int compare(const void *a, const void *b)
{
    int index1 = *(int *)a;
    int index2 = *(int *)b;

    if (count[index1] != count[index2])
    {
        return count[index2] - count[index1];
    }
    return index1 - index2;
}

int main()
{
    memset(count, 0, sizeof(count)); // 初始化 count 陣列
    int n;
    char line[MAX_ROW_LENGTH];
    int letters[ALPHABET_COUNT];

    // 初始化 letters 陣列
    for (int i = 0; i < ALPHABET_COUNT; i++)
    {
        letters[i] = i;
    }

    scanf("%d", &n);
    getchar(); // 把換行符號吃掉

    // 計算字母出現次數
    for (int i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);
        for (int j = 0; line[j] != '\0' ; j++)
        {
            if (isalpha(line[j]))
            {
                count[toupper(line[j]) - 'A']++;
            }
        }
    }

    // 依照出現次數排序
    qsort(letters, ALPHABET_COUNT, sizeof(int), compare);

    // 輸出結果
    for (int i = 0; i < ALPHABET_COUNT; i++)
    {
        if (count[letters[i]] > 0)
        {
            printf("%c %d\n", letters[i] + 'A', count[letters[i]]);
        }
    }
    return 0;   
}