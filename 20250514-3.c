// team queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAMS 1000
#define MAX_ELEMENTS 1000000
#define MAX_TEAM_SIZE 1000
#define MAX_QUEUE_SIZE 200000

// 每個隊伍的隊列
int team_queue[MAX_TEAMS][MAX_TEAM_SIZE];
int team_front[MAX_TEAMS], team_back[MAX_TEAMS];

// 總隊列
int team_order[MAX_QUEUE_SIZE];
int team_order_front = 0, team_order_back = 0;

// 快速查找元素屬於哪個隊伍
int element_to_team[MAX_ELEMENTS];

// 標記某隊伍是否已在總隊列中
int team_in_queue[MAX_TEAMS];

// 初始化隊伍
void reset_team_queue(int team_count) {
    for (int i = 0; i < team_count; i++) {
        team_front[i] = 0;
        team_back[i] = 0;
        team_in_queue[i] = 0;
    }
    team_order_front = 0;
    team_order_back = 0;
}

// 入隊操作
void enqueue(int x) {
    int team_id = element_to_team[x];
    // 如果隊伍不在總隊列中，則加入
    if (!team_in_queue[team_id]) {
        team_in_queue[team_id] = 1;
        team_order[team_order_back++] = team_id;
    }
    // 將元素加入隊伍的隊列
    team_queue[team_id][team_back[team_id]++] = x;
}

void dequeue() {
    // 取出隊伍的隊列
    int team_id = team_order[team_order_front];
    // 取出隊伍的元素
    int x = team_queue[team_id][team_front[team_id]++];
    // 如果隊伍的隊列空了，則從總隊列中刪除
    if (team_front[team_id] == team_back[team_id]) {
        team_in_queue[team_id] = 0;
        team_order_front++;
    }
    printf("%d\n", x);
}

int main() {
    int scenario = 1;
    int t;
    while (scanf("%d", &t) && t != 0) {
        printf("Scenario #%d\n", scenario++);
        memset(element_to_team, -1, sizeof(element_to_team));
        reset_team_queue(t);

        // 建立元素 -> 隊伍的對應關係
        for (int i = 0; i < t; i++) {
            int count;
            scanf("%d", &count);
            for (int j = 0; j < count; j++) {
                int x;
                scanf("%d", &x);
                element_to_team[x] = i;
            }
        }

        char cmd[20];
        while (scanf("%s", cmd) && strcmp(cmd, "STOP") != 0) {
            if (strcmp(cmd, "ENQUEUE") == 0) {
                int x;
                scanf("%d", &x);
                enqueue(x);
            } else if (strcmp(cmd, "DEQUEUE") == 0) {
                dequeue();
            }
        }
        printf("\n");   
    }
    return 0;
}