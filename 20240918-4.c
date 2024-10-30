#include <stdio.h>
int main()
{
    printf("     *\n"
           "    ***\n"
           "   *****\n"
           "  *******\n"
           "    ***\n"
           "   *****\n"
           "  *******\n"
           " *********\n"
           "***********\n"
           );
    for (int i = 0; i < 3; i++)
    {
        printf("    ****\n");
    }
    return 0;
}