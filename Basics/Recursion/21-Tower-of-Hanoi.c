// Tower of Hanoi

// "n" discs are stacked on tower A and all should be moved
// to tower C following a given set of rules:
// 1. Only one disc should be moved at a time;
// 2. A larger disc should never go on top of a smaller one;

#include <stdio.h>

// Recursive solution to the Tower of Hanoi problem.
// Prints the sequence of movements to solve the TH problem
// with 3 towers and arbitrary "n" stacked discs.
void TOH(int n, int A, int B, int C)
{
    if(n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("(%d,%d)\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(7, 1, 2, 3);
    return 0;
}