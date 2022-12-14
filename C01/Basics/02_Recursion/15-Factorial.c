// Factorial of N 

#include <stdio.h>

int fact(int n) // Recursive
{
    if(n == 0)
        return 1;
    return fact(n - 1) * n;
}

int Ifact(int n) // Iterative
{
    int f = 1, i;
    for(i = 1; i <= n; i++)
        f = f * i;
    return f;
}

int main()
{
    printf("%d %d", Ifact(5), fact(5)); // Both functions do the same thing.
    return 0;
}
