// Sum of N natural numbers 

#include <stdio.h>

// Basically anything that can be done recursively, can be done iteratively.
// The thing about recursion is that it directly translates as mathematical equations.
// So, if we can write a mathematical equation to solve a problem, we can somehwat easily
// write it as a recursive function.

int sum(int n) // Recursive
{
    if(n == 0)
        return 0;
    return sum(n - 1) + n;
}

int Isum(int n) // Iterative
{
    int s = 0, i;
    for(i = 1; i <= n; i++)
        s = s + i;
    return s;
}

int main()
{
    printf("r: %d; i: %d", sum(5), Isum(5));
    return 0;
}