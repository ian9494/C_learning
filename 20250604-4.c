#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 55

int l, n;
int cuts[MAXN];
int dp[MAXN][MAXN];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    while (scanf("%d", &l) && l != 0) {
        scanf("%d", &n);
        cuts[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &cuts[i]);
        }
        cuts[n + 1] = l;
        n += 2; // 包含頭尾

        // 初始化 dp
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        printf("The minimum cutting is %d.\n", dp[0][n - 1]);
    }
    return 0;
}
