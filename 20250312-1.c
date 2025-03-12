#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char id[10];
    char name[10];
    int score1, score2, score3;
} Student;

void printStudent(Student s) {
    printf("%s %s %d %d %d\n", s.id, s.name, s.score1, s.score2, s.score3);
}

void printStudentAvg(Student s) {
    printf("%s Avg: %d\n", s.id, (int)((s.score1 + s.score2 + s.score3) / 3.0 + 0.5));
}

int main() {
    int n;
    scanf("%d", &n);
    
    Student students[MAX_STUDENTS];
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", students[i].id, students[i].name, 
              &students[i].score1, &students[i].score2, &students[i].score3);
    }

    int command;
    while (scanf("%d", &command) != EOF) {
        if (command == 4) {
            printf("quit\n");
            break;
        } else if (command == 3) {
            // 依平均值排序 (降序)
            for (int i = 0; i < n - 1; i++) {
                int maxIndex = i;
                for (int j = i + 1; j < n; j++) {
                    int avg_max = (students[maxIndex].score1 + students[maxIndex].score2 + students[maxIndex].score3) / 3.0 + 0.5;
                    int avg_j = (students[j].score1 + students[j].score2 + students[j].score3) / 3.0 + 0.5;
                    if (avg_j > avg_max) {
                        maxIndex = j;
                    }
                }
                if (maxIndex != i) {
                    Student temp = students[i];
                    students[i] = students[maxIndex];
                    students[maxIndex] = temp;
                }
            }
            for (int i = 0; i < n; i++) {
                printStudentAvg(students[i]);
            }
        } else if (command == 2) {
            // 顯示所有學生資料
            for (int i = 0; i < n; i++) {
                printStudent(students[i]);
            }
        } else if (command == 1) {
            // 查詢特定學號的學生
            char query_id[10];
            scanf("%s", query_id);
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(students[i].id, query_id) == 0) {
                    printStudent(students[i]);
                    found = 1;
                }
            }
            if (!found) {
                printf("Student not found.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}
