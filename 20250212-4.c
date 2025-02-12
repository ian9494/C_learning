#include <stdio.h>

void stringReverse(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }
    
}

int main()
{
    char str[100];
    while (fgets(str, sizeof(str), stdin) != '\0'){
        stringReverse(str);
        printf("\n");
    }
    return 0;
}