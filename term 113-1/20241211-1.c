#include <stdio.h>
#include <string.h>

int main()
{
    char n[1000];
    int count[123]; // 用於計算 ASCII 字元頻率
    int max, max_index;

    while (fgets(n, sizeof(n), stdin) != NULL)
    {
        // 1. 重置 count 和 max
        for (int i = 0; i < 123; i++) {
            count[i] = 0;
        }
        max = 0;

        // 2. 計算字元出現次數
        for (int i = 0; n[i] != '\0'; i++)
        {
            char j = n[i];
            if (j >= 65 && j < 123) { // 只計算英文字母
                count[j]++;
            }
        }

        // 3. 找到最大次數
        for (int i = 65; i < 123; i++)
        {
            if (count[i] > max)
            {
                max = count[i];
            }
        }

        // 4. 輸出出現次數等於 max 的字元
        for (int i = 65; i < 123; i++)
        {
            if (count[i] == max)
            {
                printf("%c", i);
            }
        }
        printf(" %d\n", max);
    }

    return 0;
}
