#include <stdio.h>

int main()
{
    // open files
    FILE *ifp = fopen("input.txt", "r"); // input file path
    if (ifp == NULL) {
        printf("File 'input' not found\n");
        return 0;
    }

    FILE *ofp = fopen("output.txt", "w");
    if (ofp == NULL) {
        printf("File 'output' not found\n");
        return 0;
    }

    char str[100]; // 緩衝區
    for (int i = 0; i < 2; i++)
    {
        rewind(ifp);
        while (fgets(str, sizeof(str), ifp) != NULL)
        {
            // copy to output.txt twice
            fprintf(ofp, "%s", str);
        }
            printf("print once\n");
        fprintf(ofp, "\n");
    }
    
    // close files
    fclose(ofp);    
    fclose(ifp);
    return 0;
}