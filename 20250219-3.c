#include <stdio.h>

// 函數：加法運算並列印結果
void Add(double a, double b)
{
    printf("%.2lf\n", a + b);
}

// 函數：減法運算並列印結果
void Subtract(double a, double b)
{
    printf("%.2lf\n", a - b);
}   

// 函數：乘法運算並列印結果
void Multiply(double a, double b)
{
    printf("%.2lf\n", a * b);
}

// 函數：除法運算並列印結果
void Divide(double a, double b)
{
    printf("%.2lf\n", a / b);
}

// 函數：退出程式
void exitProgram(double a, double b)
{
    return;
}

int main()
{
    double a, b; // 存放兩個操作數的變數
    int option; // 存放使用者選擇的功能選項
    // 函數指標陣列，對應不同的功能
    void (*func[5])(double, double) = {Add, Subtract, Multiply, Divide, exitProgram};

    while (1)
    {
        // 從使用者輸入功能選項
        scanf("%d", &option);
        // 如果功能選項在有效範圍內，執行對應的函數
        if (option >= 0 && option <= 4)
        {
            // 如果選擇退出程式，跳出迴圈
            if (option == 4)
            {
                break;
            }
            // 從使用者輸入兩個操作數
            scanf("%lf %lf", &a, &b);
            // 執行對應的函數
            func[option](a, b);
        }
    }
    return 0;
}