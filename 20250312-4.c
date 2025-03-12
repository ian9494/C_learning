#include <stdio.h>
#include <string.h>

#define MAX_GRID 51  // 最大坐標範圍 0~50

// 方向索引對應：N=0, E=1, S=2, W=3
const char directions[] = "NESW";
const int dx[] = {0, 1, 0, -1};  // N=+y, E=+x, S=-y, W=-x
const int dy[] = {1, 0, -1, 0};

// 氣味標記
int scent[MAX_GRID][MAX_GRID] = {0};

int get_direction_index(char dir) {
    for (int i = 0; i < 4; i++) {
        if (directions[i] == dir) return i;
    }
    return -1;  // 不應該發生
}

int main() {
    int grid_x, grid_y;
    scanf("%d %d", &grid_x, &grid_y);

    int x, y;
    char dir;
    char instructions[101];

    while (scanf("%d %d %c", &x, &y, &dir) == 3) {
        scanf("%s", instructions);

        int lost = 0;
        int dir_index = get_direction_index(dir);

        for (int i = 0; instructions[i] != '\0'; i++) {
            if (instructions[i] == 'L') {
                dir_index = (dir_index + 3) % 4;  // 向左轉 90 度
            } else if (instructions[i] == 'R') {
                dir_index = (dir_index + 1) % 4;  // 向右轉 90 度
            } else if (instructions[i] == 'F') {
                int new_x = x + dx[dir_index];
                int new_y = y + dy[dir_index];

                // 檢查是否超出邊界
                if (new_x < 0 || new_x > grid_x || new_y < 0 || new_y > grid_y) {
                    // 若該位置已有氣味標記，則忽略掉落
                    if (scent[x][y]) continue;

                    // 若無氣味標記，則機器人掉落
                    lost = 1;
                    scent[x][y] = 1;  // 標記該位置有掉落過的機器人
                    break;
                }

                // 更新位置
                x = new_x;
                y = new_y;
            }
        }

        // 輸出結果
        printf("%d %d %c", x, y, directions[dir_index]);
        if (lost) printf(" LOST");
        printf("\n");
    }

    return 0;
}
