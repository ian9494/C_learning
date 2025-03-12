#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    char name[20];
    char type;
    union {
        float salary;         
        float hourlyRate;     
        int contractDuration; 
    } payment;
} Employee;
    
int main() {
    Employee employees[MAX_EMPLOYEES];
    int f_count = 0, p_count = 0, c_count = 0;
    float f_total = 0, p_total = 0, c_total = 0;

    char name[20];
    char type;
    float value;

    int n = 0;
    while (scanf("%s", name) == 1 && strcmp(name, "END") != 0) {
        scanf(" %c %f", &type, &value);
        employees[n].type = type;
        strcpy(employees[n].name, name);

        if (type == 'F') {
            employees[n].payment.salary = value;
            f_total += value;
            f_count++;
        } else if (type == 'P') {
            employees[n].payment.hourlyRate = value;
            p_total += value;
            p_count++;
        } else if (type == 'C') {
            employees[n].payment.contractDuration = (int)value;
            c_total += value;
            c_count++;
        }
        n++;
    }

    printf("---------------------------------------------\n");
    printf("Full-time Employees: %d\n", f_count);
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (employees[i].type == 'F') {
            printf("%s: $%.2f\n", employees[i].name, employees[i].payment.salary);
        }
    }
    if (f_count > 0) {
        printf("Average Monthly Salary: $%.2f\n", f_total / f_count);
    }

    printf("---------------------------------------------\n");
    printf("Part-time Employees: %d\n", p_count);
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (employees[i].type == 'P') {
            printf("%s: $%.2f/hr\n", employees[i].name, employees[i].payment.hourlyRate);
        }
    }
    if (p_count > 0) {
        printf("Average Hourly Rate: $%.2f\n", p_total / p_count);
    }

    printf("---------------------------------------------\n");
    printf("Contract Employees: %d\n", c_count);
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (employees[i].type == 'C') {
            printf("%s: %d months\n", employees[i].name, employees[i].payment.contractDuration);
        }
    }
    if (c_count > 0) {
        printf("Average Contract Duration: %.2f months\n", c_total / c_count);
    }

    return 0;
}