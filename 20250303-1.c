#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define STUDENT_COUNT 3

struct student {
    char name[MAX_NAME_LENGTH];
    int score;
}student;


int compare(const void *a, const void *b) {
    return ((struct student *)a)->score - ((struct student *)b)->score;
}

int main() {
    struct student students[STUDENT_COUNT] = {
        {"Marry Hu", 75},
        {"Tommy Chen", 68},
        {"Tomas Chu", 80}
    };

    qsort(students, STUDENT_COUNT, sizeof(struct student), compare);

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
    
    return 0;
}