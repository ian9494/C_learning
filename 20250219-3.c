#include <stdio.h>

void Add(double a, double b)
{
    printf("%.2lf\n", a + b);
}

void Subtract(double a, double b)
{
    printf("%.2lf\n", a - b);
}   

void Multiply(double a, double b)
{
    printf("%.2lf\n", a * b);
}

void Divide(double a, double b)
{
    printf("%.2lf\n", a / b);
}

void exitProgram(double a, double b)
{
    return;
}

int main()
{
    double a, b;
    int option;
    void (*func[5])(double, double) = {Add, Subtract, Multiply, Divide, exitProgram};

    while (1)
    {
        scanf("%d", &option);
        if (option >= 0 && option <= 4)
        {
            if (option == 4)
            {
                break;
            }
            scanf("%lf %lf", &a, &b);
            func[option](a, b);
            
        }
    }
    return 0;
}