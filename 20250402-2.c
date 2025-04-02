#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int id;
    char name[20];
    float score1, score2, score3;
    float average;
} Student;

// 尋找特定ID的學生資料
void printSearchInfo(Student *students, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("ID: %d, Name: %s, Score: %.0f, %.0f, %.0f, Avg: %.2f\n",
                   students[i].id, students[i].name,
                   students[i].score1, students[i].score2, students[i].score3, students[i].average);
                   printf("\n");
            return;
        }
    }
    printf("Student not found.\n\n");
}

// 輸出所有學生資料
void printAllInfo(Student *students, int count) {
    printf("Information of all students:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Score: %.0f, %.0f, %.0f, Avg: %.2f\n",
               students[i].id, students[i].name,
               students[i].score1, students[i].score2, students[i].score3, students[i].average);
    }
    printf("\n");
}

// 根據平均分數排序並輸出
void printSortByAverage(Student *students, int count) {
    // 建立一個臨時的排序過struct陣列
    Student *sortedStudents = malloc(count * sizeof(Student));
    // 複製原始陣列到排序陣列
    for (int i = 0; i < count; i++) {
        sortedStudents[i] = students[i];
    }

    // 根據平均分數排序
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sortedStudents[j].average > sortedStudents[j + 1].average) {
                Student temp = sortedStudents[j];
                sortedStudents[j] = sortedStudents[j + 1];
                sortedStudents[j + 1] = temp;
            }
        }
    }

    printf("Sorted information of students:\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("ID: %d, Name: %s, Score: %.0f, %.0f, %.0f, Avg: %.2f\n",
               sortedStudents[i].id, sortedStudents[i].name,
               sortedStudents[i].score1, sortedStudents[i].score2, sortedStudents[i].score3, sortedStudents[i].average);
    }
    free(sortedStudents);
    printf("\n");
}

// 輸出平均分數最高的學生資料
void printTopAverage(Student *students, int count) {
    // 計算最高平均分數
    float maxAverage = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].average > maxAverage) {
            maxAverage = students[i].average;
        }
    }
    
    printf("No.1 student:\n");
    for (int i = 0; i < count; i++) {
        if (students[i].average == maxAverage) {
            printf("ID: %d, Name: %s, Score: %.0f, %.0f, %.0f, Avg: %.2f\n",
                   students[i].id, students[i].name,
                   students[i].score1, students[i].score2, students[i].score3, students[i].average);
        }
    }
    printf("\n");
}

// 計算所有學生的平均分數
void AverageScore(Student *students, int count) {
    float totalScore = 0;
    for (int i = 0; i < count; i++) {
        totalScore += students[i].average;
    }
    float averageScore = totalScore / count;
    printf("Average score of students: %.2f\n\n", averageScore);
}

void quit(){
    exit(0);
}

int main() {
    int count = 0;
    Student students[100];
    int id;
    char name[20];
    float score1, score2, score3;


    // 讀取學生數量
    scanf("%d", &count);
    // 讀取學生資料
    for (int i = 0; i < count; i++) {
        scanf("%d %s %f %f %f", &students[i].id, students[i].name, &students[i].score1, &students[i].score2, &students[i].score3);
        students[i].average = (students[i].score1 + students[i].score2 + students[i].score3) / 3;
    }

    while (1)
    {
        int option;
        scanf("%d", &option); 
        switch (option) {
            case 1:
                scanf("%d", &id);
                printSearchInfo(students, count, id);
                break;
            case 2:
                printAllInfo(students, count);
                break;
            case 3:
                printSortByAverage(students, count);
                break;
            case 4:
                printTopAverage(students, count);
                break;
            case 5:
                AverageScore(students, count);
                break;
            case 0:
                quit();
                break;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}