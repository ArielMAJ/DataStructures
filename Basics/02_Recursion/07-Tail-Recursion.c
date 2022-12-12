// Tail Recursion

#include <stdio.h>

void fun(int n)
{
    if(n > 0) // Stopping condition is (n <= 0);
        {
            printf("%d ", n); // Does something before going into the next recursive call;
            fun(n - 1); // Calls itself recursively at the end of the function;
        }
}

int main()
{
    int x = 3;
    
    fun(x); // It will make the calls in this order: f(3)-> f(2) -> f(1) -> f(0);
    // Calls itself in the same order as head recursion; 
    // It will print: 3 2 1;
    // It will print before going down the stack:
    // The first print is in the f(3) call, then in the f(2) call and just then in the f(1);

    // Tail recursion works in a pretty similar way to how a for loop works;
    return 0;
}