#include <stdio.h>
#include <string.h>

#define MAX_N 10

// 互換矩陣的第 a 列與第 b 列
void row_a_b(int matrix[MAX_N][MAX_N], int N, int a, int b) {
    for (int j = 0; j < N; j++) {
        int temp = matrix[a][j];
        matrix[a][j] = matrix[b][j];
        matrix[b][j] = temp;
    }
}

// 互換矩陣的第 a 行與第 b 行
void col_a_b(int matrix[MAX_N][MAX_N], int N, int a, int b) {
    for (int i = 0; i < N; i++) {
        int temp = matrix[i][a];
        matrix[i][a] = matrix[i][b];
        matrix[i][b] = temp;
    }
}

// 矩陣中的每個數字加 1
void inc(int matrix[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (matrix[i][j] + 1) % 10;  // 10 變成 0
        }
    }
}

// 矩陣中的每個數字減 1
void dec(int matrix[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (matrix[i][j] - 1 + 10) % 10;  // -1 變成 9
        }
    }
}

// 矩陣轉置
void transpose(int matrix[MAX_N][MAX_N], int N) {
    int temp[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = matrix[j][i];
        }
    }
    // 複製回原矩陣
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        scanf("%d", &N);

        int matrix[MAX_N][MAX_N];

        // 讀取矩陣
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf(" %1d", &matrix[i][j]);
            }
        }

        int M;
        scanf("%d", &M);

        // 逐一讀取指令並執行
        for (int i = 0; i < M; i++) {
            char command[20];
            scanf("%s", command);

            if (strcmp(command, "row") == 0) {
                int a, b;
                scanf("%d %d", &a, &b);
                row_a_b(matrix, N, a - 1, b - 1); // 因為index是從0算起
            } else if (strcmp(command, "col") == 0) {
                int a, b;
                scanf("%d %d", &a, &b);
                col_a_b(matrix, N, a - 1, b - 1);
            } else if (strcmp(command, "inc") == 0) {
                inc(matrix, N);
            } else if (strcmp(command, "dec") == 0) {
                dec(matrix, N);
            } else if (strcmp(command, "transpose") == 0) {
                transpose(matrix, N);
            }
        }

        // 輸出結果
        printf("Case #%d\n", caseNum);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
