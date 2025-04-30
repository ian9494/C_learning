// printf 都是測試用的，不用理會

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

int main()
{
    int n;
    char str[100];

    printf("reading from input.dat\n");

    FILE *ifp = fopen("input.dat", "rb");
    if (ifp == NULL) {
        printf("File 'input' not found\n");
        return 0;
    }

    FILE *ofp = fopen("output.dat", "wb");
    if (ofp == NULL) {
        printf("File 'output.dat' not found\n");
        return 0;
    }

    // 先讀第一行的次數
    fgets(str, sizeof(str), ifp); // 讀取第一行，存入 str
    sscanf(str, "%d", &n);  // 從檔案的第一行讀取員工數量
    printf("n = %d\n", n);

    Employee employees[MAX_EMPLOYEES];

    // 載入資料
    for (int i = 0; i < n; i++)
    {
        fgets(str, sizeof(str), ifp);
        sscanf(str, "%d %s %lf", &employees[i].id, employees[i].name, &employees[i].salary);
        printf("loaded %d %s %.2lf\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    // 最後一行輸入是 要找的員工的ID
    fgets(str, sizeof(str), ifp);
    int id;
    sscanf(str, "%d", &id);
    printf("searching for %d\n", id);
    
    for (int i = 0; i < n; i++)
    {
        if (employees[i].id == id)
        {
            printf("%d %s %.2lf\n", employees[i].id, employees[i].name, employees[i].salary);
            
            fprintf(ofp, "%d %s %.2lf\n", employees[i].id, employees[i].name, employees[i].salary);
            break;
        }
        // 如果找不到
        if (i == n - 1)
        {
            printf("Employee not found\n");
            fprintf(ofp, "Employee not found\n");
        }
    }  
    
    // close files
    fclose(ofp);    
    fclose(ifp);
    return 0;
}