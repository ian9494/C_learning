#include <stdio.h>

#define MAX_N 1000
#define MAX_T 10
#define INF 1000000000

int cowCount;
int cowCycle[MAX_N];
int cowMilk[MAX_N][MAX_T];
int cowAlive[MAX_N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        // 讀取每個測試案例的牛數量和牛的週期與牛奶量
        scanf("%d", &cowCount);
        for (int i = 0; i < cowCount; i++) {
            scanf("%d", &cowCycle[i]);
            for (int j = 0; j < cowCycle[i]; j++) {
                scanf("%d", &cowMilk[i][j]);
            }
            cowAlive[i] = 1;
        }

        int day = 0;
        int lastEatenDay = 0;
        int noEatDays = 0;

        while (noEatDays < 10000) { // 判斷沒吃掉任何牛的天數 太久就可以終止程式
            int minMilk = INF;
            int minCow = -1;
            int minCount = 0;

            for (int i = 0; i < cowCount; i++) {
                if (!cowAlive[i]) continue;
                int milk = cowMilk[i][day % cowCycle[i]];
                if (milk < minMilk) {
                    minMilk = milk;
                    minCow = i;
                    minCount = 1;
                } else if (milk == minMilk) {
                    minCount++;
                }
            }

            if (minCount == 1) {
                cowAlive[minCow] = 0;
                lastEatenDay = day + 1;  // 題目從第 1 天起算
                noEatDays = 0;           // 有吃 → 重置穩定天數
            } else {
                noEatDays++;
            }

            day++;
        }

        // 計算剩餘的牛數量
        int remaining = 0;
        for (int i = 0; i < cowCount; i++) {
            if (cowAlive[i]) remaining++;
        }

        printf("%d %d\n", remaining, lastEatenDay);
    }

    return 0;
}
