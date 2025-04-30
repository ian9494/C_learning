#include <stdio.h>

typedef struct piece{
    int head, tail;
}piece;


int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        piece p[50];
        int count = 0;
        char a,b;

        while (1) {
            a = getchar();
            if (a == '\n' || a == EOF) break;
            if (a == ' ') continue;

            b = getchar();
            // 將每條鐵軌建立物件判斷頭尾
            p[count].head = (a=='M') ? 1:0;
            p[count].tail = (b=='M') ? 1:0;
            count++;
        }

        // 計算頭尾是否對稱
        int m=0, f=0;
        for (int j = 0; j < count; j++) {
            if (p[j].head == 1) m++;
            else f++;
            if (p[j].tail == 1) m++;
            else f++;
        }

        if (m==f && count>=2)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
        

    }
    return 0;
}