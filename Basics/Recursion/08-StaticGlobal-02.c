// Global Variables in Recursion 

// This code has exactly the same behavior and output as "08-StaticGlobal-01".

#include <stdio.h>

int x = 0; // A global variable

int fun(int n)
{
    if(n > 0) // Stopping condition is (n <= 0);
    {
        x++; // Every recursive call will increase x by one;
        return fun(n - 1) + x; // Returns what X is by the end of the recursion calls plus the recursive call result;
    }
    return 0; // Base condition returns 0 (when n <= 0);
}

int main()
{
    int r;
    r = fun(5); // The function calls itself recursively n=5 times;
    printf("%d\n", r); // x is incremented five times and returned. So it returns n * x = 5 * 5 = 25;

    r = fun(5); // The same as above happens again, but this time x is 5 and is incremented up until 10;
    printf("%d\n", r); // Returns n * x = 5 * 10 = 50;

    return 0;
}   