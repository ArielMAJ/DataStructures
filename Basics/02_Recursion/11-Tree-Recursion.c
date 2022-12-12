// Tree Recursion 

#include <stdio.h>

void fun(int n)
{
    if (n > 0) // It stops when (n <= 0);
    {
        printf("%d ", n); // "Tail recursion": It prints first then goes on to the recursion.
        fun(n - 1); // It recursively calls itself until it hits the stopping condition;
        fun(n - 1); // It recursively calls itself a second time;
    }
}

int main()
{
    fun(3); // It prints 3 first, then call f(2) twice.
    /* 
     * f(2) prints 2 then calls f(1) twice;
     * f(1) prints 1 and calls f(0) twice;
     * f(0) is the stop condition;
     * Basically it will call the functions in this order:
     * Starts -> prints and goes to the first stop condition -> goes back up
     * the stack and reaches the subsequent stopping conditions;
     * f(3) -> f(2) -> f(1) -> f(0) -> f(0) -> f(1) -> f(0) -> f(0) -> f(2) -> f(1) -> f(0) -> f(0) -> f(1) -> f(0) -> f(0) -> ends;
     * It prints: 3 2 1 1 2 1 1;
     */

    return 0;
}
