#include <stdio.h>

#define CUSTOMER_COUNT 3

// 定義 customer 結構
struct customer {
    char lastName[15];       
    char firstName[15];      
    double payment;
    unsigned int customerNumber;
};

int main() {
    struct customer customers[CUSTOMER_COUNT];

    // 讀取會員資料
    for (int i = 0; i < CUSTOMER_COUNT; i++) {
        scanf("%s %s %lf %u", customers[i].firstName, customers[i].lastName, &customers[i].payment, &customers[i].customerNumber);
    }

    // 找到消費最高的會員
    int maxIndex = 0;
    for (int i = 1; i < CUSTOMER_COUNT; i++) {
        if (customers[i].payment > customers[maxIndex].payment) {
            maxIndex = i;
        }
    }

    printf("%s %s %.0f %u\n", customers[maxIndex].firstName, customers[maxIndex].lastName, customers[maxIndex].payment, customers[maxIndex].customerNumber);

    return 0;
}
