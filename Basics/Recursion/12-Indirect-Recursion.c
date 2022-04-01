// Indirect Recursion 

// "Function A" calls "function B" and "function B" calls "function A", thus
// making an indirect recursion.

#include <stdio.h>

void funB(int n);

void funA(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2); // Note this is an integer division, thus the number is truncated.
    }
}

int main()
{
    funA(20); // -> funB(19) -> funA(9) -> funB(8) -> funA(4) -> funB(3) -> funA(1) -> funB(0);
    // Prints: 20 19 9 8 4 3 1 
    return 0;
}