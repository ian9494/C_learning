#include <stdio.h>

void printGrade(int *grade)
{
    printf("%d %d %d %d %d %d\n", grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);
}

void printAverage(int *grade)
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += grade[i];
    }
    printf("%.2f\n", (float)sum / 6);
}

void findMin(int *grade)
{
    int min = grade[0];
    for (int i = 1; i < 6; i++)
    {
        if (grade[i] < min)
        {
            min = grade[i];
        }
    }
    printf("%d\n", min);
}

void findMax(int *grade)
{
    int max = grade[0];
    for (int i = 1; i < 6; i++)
    {
        if (grade[i] > max)
        {
            max = grade[i];
        }
    }
    printf("%d\n", max);
}

void exitProgram(int *grade)
{
    return;
}


int main()
{
    int grade[6];
    int funcIndex = 0;

    void (*func[5])(int) = {printGrade, findMin, findMax, printAverage, exitProgram};

    while (1)
    {
        scanf("%d %d %d %d %d %d", &grade[0], &grade[1], &grade[2], &grade[3], &grade[4], &grade[5]);
        scanf("%d", &funcIndex);
        if (funcIndex >= 0 && funcIndex <= 4)
        {
            func[funcIndex](grade);
            if (funcIndex == 4)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}