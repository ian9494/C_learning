#include <stdio.h>
#include <math.h>

int main()
{
    int input,n=0,input2;
    scanf("%d", &input);
    input2 = input;
    while (input2>=1)
    {
        input2/=10;
        n++;
    }
    n-=1;
    while (n>0)
    {
        int t=input/pow(10,n);
        printf("%d   ", t%10);
        n--;
    }
    printf("%d", input%10);
    
    
    return 0;
}