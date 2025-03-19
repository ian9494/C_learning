// cola!!

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // every three bottles can exchange for one bottle of cola
        // also you can borrow one bottle of cola from the shopkeeper
        // but you have to return it after you drink the cola
        int total = n;
        while (n >= 3)
        {
            total += n / 3;
            n = n / 3 + n % 3;
        }
        if (n == 2)
        {
            total++;
        }
        printf("%d\n\n", total);

    }
    
}