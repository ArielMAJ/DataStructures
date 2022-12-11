// Head Recursion

#include <stdio.h>

void fun(int n)
{
    if(n > 0) // Stopping condition is (n <= 0);
        {
            fun(n - 1); // Calls itself recursively first;
            printf("%d ", n); // Does something when comming back from the recursive calls;
        }
}

int main()
{
    int x = 3;
    
    fun(x); // It will make the calls in this order: f(3) -> f(2) -> f(1) -> f(0);
    // Calls itself in the same order as tail recursion; 
    // It will print: 1 2 3;
    // It will print when comming back up the stack:
    // The first print is in the f(1) call, then in the f(2) call and just then in the f(3);

    return 0;
}