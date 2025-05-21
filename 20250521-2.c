#include <stdio.h>
#include <string.h>

#define MAX 105

int w, h;
int wolf[MAX][MAX];
unsigned long long dp[MAX][MAX];

int main() {
    while (1)
    {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;

        memset(wolf, 0, sizeof(wolf));
        memset(dp, 0, sizeof(dp));

        // 找到狼的位子
        int n;
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            int wx, wy;
            scanf("%d %d", &wx, &wy);
            wolf[wx][wy] = 1;
        }

        if (!wolf[0][0]) dp[0][0] = 1;

        for (int x = 0; x <= w; x++) {
            for (int y = 0; y <= h; y++) {
                if (wolf[x][y]) continue;
                if (x > 0) dp[x][y] += dp[x - 1][y];
                if (y > 0) dp[x][y] += dp[x][y - 1];
            }
        }

        if (dp[w][h] == 0) {
            printf("There is no path.\n");
        } else if (dp[w][h] == 1) {
            printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        } else {
            printf("There are %llu paths from Little Red Riding Hood's house to her grandmother's house.\n", dp[w][h]);
        }
    }
    
}