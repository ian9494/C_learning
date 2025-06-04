/*Australian Ballot*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_BALLOTS 1000
#define MAX_NAME_LENGTH 85

char candidates[MAX_CANDIDATES][MAX_NAME_LENGTH]; //候選人名
int ballots[MAX_BALLOTS][MAX_CANDIDATES]; //投票表，行表示選民，列表示候選人
int eliminated[MAX_CANDIDATES]; //是否被淘汰，1表示淘汰，0表示未淘汰
int vote_count[MAX_CANDIDATES]; //每個候選人的得票數

int num_candidates = 0, num_ballots = 0; //候選人數和投票表數


void reset() { //重置所有數據
    memset(eliminated, 0, sizeof(eliminated));
    memset(ballots, 0, sizeof(ballots));
    memset(vote_count, 0, sizeof(vote_count));
    num_ballots = 0;
}

int get_first_valid_choice(int b) { //獲取選民b的第一個有效選擇
    for (int i = 0; i < num_candidates; i++) {
        int c = ballots[b][i];
        if (c > 0 && !eliminated[c - 1]) { //如果選擇的候選人未被淘汰
            return c - 1; //返回候選人索引
        }
    }
    return -1; //沒有有效選擇
}

int is_tie(int min_vote) { //檢查是否平局
    for (int i = 0; i < num_candidates; i++) {
        if (!eliminated[i] && vote_count[i] != min_vote) {
            return 0; //如果有候選人得票數不等於最小值，則不是平局
        }
    }
    return 1; //所有未淘汰候選人得票數都等於最小值，則是平局
}

void simulate() {
    while (1)
    {
        memset(vote_count, 0, sizeof(vote_count)); //清空得票數

        // 計算每個候選人的得票數
        for (int b = 0; b < num_ballots; b++) {
            int c = get_first_valid_choice(b); //獲取選民b的第一個有效選擇
            if (c != -1) { //如果有有效選擇
                vote_count[c]++; //增加該候選人的得票數
            }
        }

        // 檢查是否有候選人獲勝
        for (int i = 0; i < num_candidates; i++) {
            if (!eliminated[i] && vote_count[i] > num_ballots / 2) { //如果有候選人得票數超過半數
                printf("%s\n", candidates[i]); //輸出該候選人名
                return;
            }
        }

        // 找到最小得票數
        int min_vote = 1000;
        for (int i = 0; i < num_candidates; i++) {
            if (!eliminated[i] && vote_count[i] < min_vote) {
                min_vote = vote_count[i]; //更新最小得票數
            }
        }

        // 檢查是否平局
        if (is_tie(min_vote)) {
            for (int i = 0; i < num_candidates; i++) {
                if (!eliminated[i]) {
                    printf("%s\n", candidates[i]); //輸出所有未淘汰候選人名
                }
            }
            return;
        }

        // 淘汰得票數最少的候選人
        for (int i = 0; i < num_candidates; i++) {
            if (!eliminated[i] && vote_count[i] == min_vote) {
                eliminated[i] = 1; //將該候選人標記為淘汰
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T); //讀取測試用例數
    getchar(); //清除換行符
    getchar(); //清除空行
    while (T--) {
        reset(); //重置數據
        scanf("%d", &num_candidates); //讀取候選人數
        getchar(); //清除換行符

        for (int i = 0; i < num_candidates; i++) {
            fgets(candidates[i], MAX_NAME_LENGTH, stdin); //讀取候選人名
            candidates[i][strcspn(candidates[i], "\n")] = '\0'; //去除換行符
        }

        char line[1024];
        while (fgets(line, sizeof(line), stdin)) {
            if (line[0] == '\n') break; //如果是空行，則結束讀取投票表
            char *token = strtok(line, " "); //分割字符串
            int c_index = 0;

            while (token) {
                ballots[num_ballots][c_index++] = atoi(token); //將投票表中的候選人編號存入
                token = strtok(NULL, " "); //繼續分割下一個候選人編號
            }
            num_ballots++; //增加投票表數
        }
        simulate(); //模擬選舉

        if (T > 0) {
            printf("\n"); //如果還有測試用例，則輸出空行
        }
    }
    return 0; //返回0表示程序正常結束
}