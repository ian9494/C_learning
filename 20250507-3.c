#include <stdio.h>
#include <string.h>

#define MAX_CITY 1000
#define MAX_NAME_LENGTH 32

// 定義城市數量和名稱長度
char cityNames[MAX_CITY][MAX_NAME_LENGTH]; // 儲存城市名稱
int cityCount = 0;

int visited[MAX_CITY]; // 記錄城市是否被訪問過
int parent[MAX_CITY]; // 記錄每個城市的父節點（用於回溯路徑）

int graph[MAX_CITY][MAX_CITY]; // 儲存圖的鄰接矩陣
int adjCount[MAX_CITY]; // 儲存每個城市的鄰接城市數量

// 獲取城市ID，若不存在則新增城市
// 返回城市ID，並將城市名稱存入 cityNames 陣列
int getCityID(const char* name) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cityNames[i], name) == 0)
            return i;
    }
    strcpy(cityNames[cityCount], name);
    return cityCount++;
}

// 根據城市名稱查找城市ID
int findCityID(const char* name) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cityNames[i], name) == 0)
            return i;
    }
    return -1;
}

// 添加邊到圖中
// 這裡使用無向(雙向)圖，從 from 到 to 和 from 從 to 都添加邊
void addEdge(int from, int to) {
    graph[from][adjCount[from]++] = to;
    graph[to][adjCount[to]++] = from;
}

// 廣度優先搜索 (BFS) 用於尋找最短路徑
// 返回 1 表示找到路徑，0 表示未找到路徑
int bfs(int start, int end) {
    int queue[MAX_CITY], front = 0, rear = 0; // 定義隊列，front 指向隊列頭，rear 指向隊列尾

    // 初始化 visited 陣列為 0，表示所有城市尚未被訪問
    // 初始化 parent 陣列為 -1，表示所有城市尚無父節點
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    // 將起始城市加入隊列，並標記為已訪問
    queue[rear++] = start;
    visited[start] = 1;

    // 當隊列不為空時，繼續搜索
    while (front < rear) {
        int current = queue[front++]; // 取出隊列頭部的城市

        // 如果當前城市是目標城市，則返回 1 表示找到路徑
        if (current == end) return 1;

        // 遍歷當前城市的所有鄰接城市
        for (int i = 0; i < adjCount[current]; i++) {
            int neighbor = graph[current][i]; // 獲取鄰接城市的 ID

            // 如果鄰接城市尚未被訪問
            if (!visited[neighbor]) {
                visited[neighbor] = 1; // 標記鄰接城市為已訪問
                parent[neighbor] = current; // 設置鄰接城市的父節點為當前城市
                queue[rear++] = neighbor; // 將鄰接城市加入隊列
            }
        }
    }

    // 如果隊列處理完畢仍未找到目標城市，返回 0 表示未找到路徑
    return 0;
}

// 打印從起點到終點的路徑
void printPath(int start, int end) {
    char path[MAX_CITY];
    int idx = 0;

    // 從終點開始回溯路徑，直到回到起點
    // 使用 parent 陣列來獲取每個城市的父節點
    int current = end;
    while (current != -1) {
        path[idx++] = cityNames[current][0]; // 存首字母
        current = parent[current];
    }

    // 反轉路徑，從終點到起點
    // 因為我們是從終點開始回溯的，所以需要反轉路徑
    for (int i = idx - 1; i >= 0; i--) {
        putchar(path[i]);
    }
    putchar('\n');
}

int main() {
    int T;
    scanf("%d", &T);

    int firstCase = 1;

    while (T--) {
        // 每個測試案例之間印空行
        // 但不在第一個測試案例之前印空行
        if (!firstCase) {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            putchar('\n');
        }
        firstCase = 0;

        int m, n;
        scanf("%d %d", &m, &n);

        cityCount = 0;
        memset(adjCount, 0, sizeof(adjCount));
        memset(graph, 0, sizeof(graph));

        char city1[MAX_NAME_LENGTH], city2[MAX_NAME_LENGTH];

        // 讀取城市名稱並建立圖的邊
        for (int i = 0; i < m; i++) {
            scanf("%s %s", city1, city2);
            int id1 = getCityID(city1);
            int id2 = getCityID(city2);
            addEdge(id1, id2);
        }

        // 讀取查詢的城市對並尋找路徑
        for (int i = 0; i < n; i++) {
            scanf("%s %s", city1, city2);
            int id1 = findCityID(city1);
            int id2 = findCityID(city2);

            // 如果城市名稱不存在，則 id1 或 id2 為 -1
            // 這裡不需要檢查 cityNames 陣列的大小，因為我們在 getCityID 函數中已經確保了不會超出範圍
            if (id1 == -1 || id2 == -1) {
                printf("Invalid city name\n");
                continue;
            }

            // 如果 id1 和 id2 相同，則直接輸出城市名稱
            if (bfs(id1, id2)) {
                printPath(id1, id2);
            } else {
                printf("No path\n");
            }
        }
    }

    return 0;
}
