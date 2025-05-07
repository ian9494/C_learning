#include <stdio.h>

int main() {
    int year;
    int first = 1; // 控制是否需要印空行

    while (scanf("%d", &year) != EOF) {
        if (!first) printf("\n");
        first = 0;

        int isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int isHuluculu = (year % 15 == 0);
        int isBulukulu = (year % 55 == 0 && isLeap);

        if (isLeap) printf("This is leap year.\n");
        if (isHuluculu) printf("This is huluculu festival year.\n");
        if (isBulukulu) printf("This is bulukulu festival year.\n");

        if (!isLeap && !isHuluculu && !isBulukulu)
            printf("This is an ordinary year.\n");
    }

    return 0;
}
