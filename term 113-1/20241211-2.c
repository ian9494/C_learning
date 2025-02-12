#include <stdio.h>
#include <ctype.h> // 使用 isalpha 函數

int main()
{
    char n[1000000];

    while (fgets(n, sizeof(n), stdin) != NULL)
    {
        int count = 0;
        int in_word = 0;

        for (int i = 0; n[i] != '\0'; i++)
        {
            if (isalpha(n[i])) // check alphabet
            {
                if (!in_word) // check if new word
                {
                    count++;
                    in_word = 1;
                }
            }
            else // cancel if not alphabet
            {
                in_word = 0;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
