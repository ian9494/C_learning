#include <stdio.h>

void exit_program()
{
    printf("Exiting program...\n");
}

void buildingCarbonFootprint()
{
    double electricity, gas, fuel;
    scanf("%lf %lf %lf", &electricity, &gas, &fuel);
    double total = electricity*0.5 + gas*2.3 + fuel*2.7;
    printf("Building: %.2f kg CO2/year\n", total);
}

void carCarbonFootprint()
{
    double fuel;
    scanf("%lf", &fuel);
    double total = fuel*2.3;
    printf("Car: %.2f kg CO2/year\n", total);
}

void bicycleCarbonFootprint()
{
    printf("Bicycles themselves do not produce a carbon footprint, but their production and maintenance still produce carbon emissions.\n"
           "Bicycle: 5 kg CO2/year\n");
}


int main()
{
    int option;
    void *(func[4]) = {exit_program, buildingCarbonFootprint, carCarbonFootprint, bicycleCarbonFootprint};
    
    while (1)
    {
        scanf("%d", &option);
        if (option >= 0 && option <= 3)
        {
            if (option == 0)
            {
                break;
            }
            ((void (*)())func[option])();
        }
    }
    return 0;
}