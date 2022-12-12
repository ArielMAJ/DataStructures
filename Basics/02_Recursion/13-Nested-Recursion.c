// Nested Recursion 

#include <stdio.h>

int fun(int n)
{
    if(n > 100)
        return n - 10;
    return fun(fun(n + 11)); // Nested recursion are those that make two (or more?) nested calls.
    // The outer function call only occurs when the inner function call returns.
}

int main()
{
    int r;
    r = fun(95); // -> fun(106) -> fun(96) -> fun(107) -> fun(97) -> 
    // fun(108) -> fun(98) -> fun(109) -> fun(99) -> fun(110) -> fun(100) ->
    // fun(111) -> fun(101) -> 91
    printf("%d\n", r); // Prints 91.
    return 0;
}