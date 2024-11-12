#include <stdio.h>

void Add(int a,int b)
{
    printf("%d + %d = %d",a,b,a+b);
}

void Multiply(int a,int b)
{
    printf("%d * %d = %d",a,b,a*b);
}

void Divide(int a,int b)
{
    if (b==0)
        printf("The denominator cannot be 0.");
    else
        printf("%d / %d = %d ...%d",a,b,a/b,a%b);

}

void Compare(int a,int b)
{
    if (a>b)
    {
        printf("The max is %d.", a);
    }
    else if (b>a)
    {
        printf("The max is %d.", b);
    }
    else
    {
        printf("%d and %d is equal.",a,b);
    }
    
}

int main()
{
    int a,b;
    scanf("%d %d", &a,&b);
    while (a>0 && b>0)
    {
        Add(a,b);
        Multiply(a,b);
        Divide(a,b);
        Compare(a,b);
        scanf("%d %d",&a,&b);
    }

}