#include <stdio.h>
#include <string.h>

#define MAX 110

int A[MAX], B[MAX];
int dp[MAX][MAX];

int max(int a, int b) {
    return (a > b) ? a : b;
}   

int lcs(int n1, int n2) { // 計算兩個序列的最長公共子序列長度
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // 初始化邊界條件
            } else if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 如果元素相等，則長度加1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 否則取最大值
            }
        }
    }
    return dp[n1][n2]; // 返回LCS的長度
}

int main() {
    int n1, n2, case_num = 1;
    while (scanf("%d %d", &n1, &n2) && (n1 || n2)) {
        for (int i = 0; i < n1; i++) scanf("%d", &A[i]); // 讀取第一個序列
        for (int i = 0; i < n2; i++) scanf("%d", &B[i]); // 讀取第二個序列
        
        int result = lcs(n1, n2); // 計算LCS長度

        printf("Twin Towers #%d\n", case_num++);
        printf("Number of Tiles : %d\n\n", result); // 輸出結果
    }

    return 0; // 返回0表示程序正常結束
}
