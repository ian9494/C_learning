// 辨認回文 忽略空格及標點符號

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 利用遞迴測試是否回文
int testPalindrome(char str[], int left, int right) {
    // 如果左邊大於右邊，表示已經比對完畢
    if (left >= right) {
        return 1;
    }

    // 如果首尾字元不相等，則不是回文
    if (str[left] != str[right]) {
        return 0;
    }
    return testPalindrome(str, left + 1, right - 1);   
}

int main()
{
    char input[1000];
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        // 過濾非字母字元
        char filtered[1000];
        int j = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (isalpha(input[i]))
            {
                filtered[j++] = tolower(input[i]);
            }
        }
        filtered[j] = '\0';

        // 如果過濾後的字串為空，輸出0
        if (j == 0) {
            printf("0\n");
        } else {
            printf("%d\n", testPalindrome(filtered, 0, j - 1));
        }
    }
    
    return 0;
}