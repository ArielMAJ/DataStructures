// Taylor Series using Static variables 

#include <stdio.h>

double e(int x, int n)
{
    static double p = 1, f = 1; // These will work the same as a global variable;
    double r;

    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main(void)
{
    printf("%lf \n", e(4, 15));
    return 0;
}