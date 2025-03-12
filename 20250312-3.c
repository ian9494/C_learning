#include <stdio.h>
#include <string.h>
#include <math.h>  // 用於四捨五入

#define MAX_STUDENTS 100

// 成績結構
typedef struct {
    int Chinese_score;
    int English_score;
    int Math_score;
} ScoreType;

// 成績等級結構
typedef struct {
    char Chinese_grade;
    char English_grade;
    char Math_grade;
} GradeType;

// 學生結構
typedef struct {
    char name[50];  // 姓名可能有空格
    char id[10];
    float avg_score;
    ScoreType score;
    GradeType grade;
} Student;

// **函數: 將成績等級轉換為數值**
int grade_to_num(char grade) {
    switch (grade) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'F': return 0;
        default: return -1;  // 不應該發生
    }
}

// **函數: 將數值轉換回成績等級**
char num_to_grade(int num) {
    switch (num) {
        case 4: return 'A';
        case 3: return 'B';
        case 2: return 'C';
        case 1: return 'D';
        case 0: return 'F';
        default: return 'X';  // 不應該發生
    }
}

// **函數: 計算平均等級**
char get_average_grade(GradeType grade) {
    int sum = grade_to_num(grade.Chinese_grade) +
              grade_to_num(grade.English_grade) +
              grade_to_num(grade.Math_grade);
    int avg = round(sum / 3.0);  // **四捨五入取最接近的整數**
    return num_to_grade(avg);
}

int main() {
    int n;
    scanf("%d", &n);
    Student students[MAX_STUDENTS];

    // 讀取學生資料
    for (int i = 0; i < n; i++) {
        getchar();  // 清除換行符，避免 `fgets` 讀取錯誤
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // 移除換行符

        scanf("%s", students[i].id);
        scanf("%d", &students[i].score.Chinese_score);
        getchar(); // 跳過空格
        scanf("%c", &students[i].grade.Chinese_grade);
        scanf("%d", &students[i].score.English_score);
        getchar(); // 跳過空格
        scanf("%c", &students[i].grade.English_grade);
        scanf("%d", &students[i].score.Math_score);
        getchar(); // 跳過空格
        scanf("%c", &students[i].grade.Math_grade);

        // 計算平均分數
        students[i].avg_score = (students[i].score.Chinese_score + 
                                 students[i].score.English_score + 
                                 students[i].score.Math_score) / 3.0;
    }

    // **輸出結果**
    for (int i = 0; i < n; i++) {
        // **計算平均等級**
        char avg_grade = get_average_grade(students[i].grade);

        printf("%s %.1f %c\n", students[i].id, students[i].avg_score, avg_grade);
    }

    // **輸出第一個學生的姓名**
    printf("%s\n", students[0].name);

    return 0;
}
