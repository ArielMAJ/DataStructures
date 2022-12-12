// Fibonacci

#include <stdio.h>

// Iterative implementation of fibonacci series.
int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n <= 1) return n;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

// Recursive "simpler" implementation of the above.
int rfib(int n)
{
    if (n <= 1) return n;
    return rfib(n - 2) + rfib(n - 1);
}


// Recursive version using dynamic programming, resulting in increased efficiency.
#define size 30
int F[size]; // Array for saving the solutions to each recursive call
// so you don't calculate the same thing multiple times.
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    int i;

    for (i = 0; i < size; i++)
        F[i] = -1; // Initializing array so we have predictable behavior 

    printf("%d \n", rfib(size));
    return 0;
}