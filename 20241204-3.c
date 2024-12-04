#include <stdio.h>
#include <string.h>

int main()
{
    int n, count[256]={0}; //256隨便設的 ASCII碼不超過就好
    while (scanf("%d", &n) != EOF && n!=0)
    {
        char a[101];
        fgets(a, sizeof(a), stdin);
        //count letter
        for (int i = 0; a[i]!='\0'; i++)
        {
            char j = tolower(a[i]); //確保用小寫算
            count[j]++;
        }
        //print result
        for (int i = 97; i < 123; i++) //這個範圍是ASCII碼小寫英文字母範圍
        {
            if (count[i]>0)
            {
                printf("%c: %d\n", i, count[i]);
            }
        }

        //clear counts
        for (int i = 0; i < 256; i++)
            count[i]=0;
    }
    
}