#include <stdio.h>

// 函數：計算並列印圓周長
void calculateCircumference(float radius)
{
    // 圓周長公式：2 * π * 半徑
    printf("%.2f\n", 2 * 3.14 * radius);
}

// 函數：計算並列印圓面積
void calculateArea(float radius)
{
    // 圓面積公式：π * 半徑 * 半徑
    printf("%.2f\n", 3.14 * radius * radius);
}

// 函數：計算並列印球體積
void calculateVolume(float radius)
{
    // 球體積公式：4/3 * π * 半徑^3
    printf("%.2f\n", 4.0 / 3.0 * 3.14 * radius * radius * radius);
}

// 函數：退出程式
void exitProgram(float radius)
{
    return;
}

int main()
{
    float radius; // 存放半徑的變數
    int option; // 存放使用者選擇的功能選項

    // 函數指標陣列，對應不同的功能
    void (*funcPtr[4])(float) = {calculateCircumference, calculateArea, calculateVolume, exitProgram};
    
    while (1)
    {
        // 從使用者輸入功能選項
        scanf("%d", &option);
        // 如果功能選項在有效範圍內，執行對應的函數
        if (option >= 0 && option <= 3)
        {
            // 如果選擇退出程式，跳出迴圈
            if (option == 3)
            {
                break;
            }
            // 從使用者輸入半徑
            scanf("%f", &radius);
            // 執行對應的函數
            funcPtr[option](radius);
        }
        else
        {
            // 如果功能選項無效，跳出迴圈
            break;
        }
    }
    
    return 0;
}