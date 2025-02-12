#include <stdio.h>
#include <string.h>

int main()
{
    char key[]={"qwertyuiop[]asdfghjkl;'zxcvbnm,.QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>"}; //用來對照左邊兩格是什麼
    int n;
    scanf("%d", &n);
    while (getchar() != '\n'); //清空輸入緩衝區 不然會被fgets吃到

    //設定動態儲存大小字串
    char *input;  
    char *buffer;
    int input_size; // `input` 總大小
    int buffer_size = 1000; // 單行最大長度（可調整） 

    input_size = (n * buffer_size); // 根據行數和假設每行最大長度計算
    input = (char *)calloc(input_size, sizeof(char)); // 初始化為全零
    buffer = (char *)malloc(buffer_size * sizeof(char)); 

    //input
    for (int i = 0; i < n; i++)
    {
        fgets(buffer, buffer_size, stdin);
        strcat(input, buffer);
    }    

    //print out
    for (int i = 0; i < strlen(input); i++)
        {
            //遇到空白要直接輸出空白
            if (input[i]== 32) //32為'空白'ASCII碼
                printf(" ");
            //遇到換行要直接輸出換行
            if (input[i]== 10) //10為'換行'ASCII碼
                printf("\n");
            for (int j = 0; j < strlen(key); j++)
            {
                //decode and print
                if (key[j+2] == (input[i]))
                {
                    printf("%c", tolower(key[j])); //雖然題目沒寫但要求輸出只有小寫 點點點
                    break;
                }
            }
        }
    return 0;
}