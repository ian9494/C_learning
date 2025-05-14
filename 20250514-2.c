// frog distance
#include <stdio.h>
#include <math.h>

#define MAX_N 200
#define INF 1e9

typedef struct {
    double x, y;
} Point;

double dist[MAX_N][MAX_N];
Point stones[MAX_N];

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n, scenario = 1;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &stones[i].x, &stones[i].y);
        }

        // 初始化距離矩陣
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = distance(stones[i], stones[j]);
            }
        }

        // Floyd-Warshall 演算法
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > fmax(dist[i][k], dist[k][j])) {
                        dist[i][j] = fmax(dist[i][k], dist[k][j]);
                    }
                }
            }
        }
        printf("Scenario #%d\n", scenario++);
        printf("Frog Distance = %.3f\n\n", dist[0][1]);
    }
    return 0;
}