#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 用於 strtol

int main()
{
    int n;
    char input[200], decode[200], temp[200];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        decode[0] = '\0'; //reset decode

        scanf("%s", input);

        for (int j = 0; input[j] != '\0';)
        {
            char letter = input[j]; // 讀取字母
            j++;

            // 讀取數字部分
            char numberStr[20] = {0};
            int k = 0;
            while (input[j] >= '0' && input[j] <= '9') {
                numberStr[k++] = input[j++];
            }
            numberStr[k] = '\0';

            // 轉換數字字串為整數
            int times = strtol(numberStr, NULL, 10);
 
            for (int k = 0; k < times; k++) {
                temp[k] = letter;
            }
            temp[times] = '\0'; // reset temp

            strcat(decode, temp);
        }

        printf("Case %d: %s\n", i + 1, decode);
    }
    
    return 0;
}
