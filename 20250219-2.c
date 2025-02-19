#include <stdio.h>

void calculateCircumference(float radius)
{
    printf("%.2f\n", 2 * 3.14 * radius);
}

void calculateArea(float radius)
{
    printf("%.2f\n", 3.14 * radius * radius);
}

void calculateVolume(float radius)
{
    printf("%.2f\n", 4.0 / 3.0 * 3.14 * radius * radius * radius);
}

void exitProgram(float radius)
{
    return;
}

int main()
{
    float radius;
    int option;

    void (*funcPtr[4])(float) = {calculateCircumference, calculateArea, calculateVolume, exitProgram};
    
    while (1)
    {
        scanf("%d", &option);
        if (option >= 0 && option <= 3)
        {
            if (option == 3)
            {
                break;
            }
            scanf("%f", &radius);
            funcPtr[option](radius);
            
        }
        else
        {
            break;
        }
    }
    
    
    return 0;
}