// Power Function 

#include <stdio.h>

// "Naive" solution.
double power(double m, int n)
{
    if(n == 0) // Base case: m^0=1.
        return 1;
    return power(m, n - 1) * m; // It solves by doing m*m^(n-1).
    // Recursively solving for m^(n-1), m^(n-2)... it translates into doing the simple multiplication
    // of "m*m*m*..." "n times".
}

// "Naive solution" but as a loop instead of implemented recursively.
// This actually should work better than its recursive version as it shouldn't
// run into the "stack overflow" problem.
double power_loop(double m, int n)
{
    double result = 1.0;

    for (int i = 0; i < n; i++)
    {
        result *= m;
    }

    return result;
}


// A more efficient solution.
double power1(double m, int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return power1(m * m, n / 2); // This is "m^n = (m*m)^(n/2)" -> e.g. 2^10 == 4^5
    return m * power1(m * m, (n - 1) / 2); // This is "m^n = m * (m * m)^((n-1)/2)" -> e.g. 4^5 == 4 * 16^2
}

int main()
{
    printf("%f\n", power1(1.0000042424242, 424242)); // This one runs and returns "instantly" (in my computer);
    printf("%f\n", power_loop(1.0000042424242, 424242)); // This one runs and returns "instantly" (in my computer);
    printf("%f\n", power(1.0000042424242, 424242)); // This one breaks (stack overflow? idk) with n>=44000 (in my computer);
    return 0;
}