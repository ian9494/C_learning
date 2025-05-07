#include <stdio.h>
#include <string.h>

#define MAX_CITY 1000
#define MAX_NAME_LENGTH 32

char cityNames[MAX_CITY][MAX_NAME_LENGTH];
int cityCount = 0;

int visited[MAX_CITY];
int parent[MAX_CITY];

int graph[MAX_CITY][MAX_CITY];
int adjCount[MAX_CITY];

int getCityID(const char* name) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cityNames[i], name) == 0)
            return i;
    }
    strcpy(cityNames[cityCount], name);
    return cityCount++;
}

int findCityID(const char* name) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cityNames[i], name) == 0)
            return i;
    }
    return -1;
}

// 改為雙向圖版本
void addEdge(int from, int to) {
    graph[from][adjCount[from]++] = to;
    graph[to][adjCount[to]++] = from;
}

int bfs(int start, int end) {
    int queue[MAX_CITY], front = 0, rear = 0;

    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];

        if (current == end) return 1;

        for (int i = 0; i < adjCount[current]; i++) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                parent[neighbor] = current;
                queue[rear++] = neighbor;
            }
        }
    }

    return 0;
}

void printPath(int start, int end) {
    char path[MAX_CITY];
    int idx = 0;

    int current = end;
    while (current != -1) {
        path[idx++] = cityNames[current][0]; // 存首字母
        current = parent[current];
    }

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

        for (int i = 0; i < m; i++) {
            scanf("%s %s", city1, city2);
            int id1 = getCityID(city1);
            int id2 = getCityID(city2);
            addEdge(id1, id2);
        }

        for (int i = 0; i < n; i++) {
            scanf("%s %s", city1, city2);
            int id1 = findCityID(city1);
            int id2 = findCityID(city2);

            if (id1 == -1 || id2 == -1) {
                printf("Invalid city name\n");
                continue;
            }

            if (bfs(id1, id2)) {
                printPath(id1, id2);
            } else {
                printf("No path\n");
            }
        }
    }

    return 0;
}
