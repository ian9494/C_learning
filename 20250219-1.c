#include <stdio.h>

// 函數：列印所有成績
void printGrade(int *grade)
{
    // 列印六個成績
    printf("%d %d %d %d %d %d\n", grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);
}

// 函數：計算並列印平均成績
void printAverage(int *grade)
{
    int sum = 0;
    // 計算六個成績的總和
    for (int i = 0; i < 6; i++)
    {
        sum += grade[i];
    }
    // 列印平均成績，保留兩位小數
    printf("%.2f\n", (float)sum / 6);
}

// 函數：找出並列印最低成績
void findMin(int *grade)
{
    int min = grade[0];
    // 找出最小的成績
    for (int i = 1; i < 6; i++)
    {
        if (grade[i] < min)
        {
            min = grade[i];
        }
    }
    // 列印最低成績
    printf("%d\n", min);
}

// 函數：找出並列印最高成績
void findMax(int *grade)
{
    int max = grade[0];
    // 找出最大的成績
    for (int i = 1; i < 6; i++)
    {
        if (grade[i] > max)
        {
            max = grade[i];
        }
    }
    // 列印最高成績
    printf("%d\n", max);
}

// 函數：退出程式
void exitProgram(int *grade)
{
    return;
}

int main()
{
    int grade[6]; // 存放六個成績的陣列
    int funcIndex = 0; // 存放使用者選擇的功能索引

    // 函數指標陣列，對應不同的功能
    void (*func[5])(int *) = {printGrade, findMin, findMax, printAverage, exitProgram};

    while (1)
    {
        // 從使用者輸入六個成績
        scanf("%d %d %d %d %d %d", &grade[0], &grade[1], &grade[2], &grade[3], &grade[4], &grade[5]);
        // 從使用者輸入功能索引
        scanf("%d", &funcIndex);
        // 如果功能索引在有效範圍內，執行對應的函數
        if (funcIndex >= 0 && funcIndex <= 4)
        {
            func[funcIndex](grade);
            // 如果選擇退出程式，跳出迴圈
            if (funcIndex == 4)
            {
                break;
            }
        }
        else
        {
            // 如果功能索引無效，跳出迴圈
            break;
        }
    }
    
    return 0;
}