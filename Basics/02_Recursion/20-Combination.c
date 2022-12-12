// Combination Formula

#include <stdio.h>

int fact(int n)
{
    if(n == 0) return 1;
    return fact(n - 1) * n;
}

// num = n!
// den = r! * (n - r)!
// nCr = num / den
// As fact(n) is O(n), nCr(n,r) also is O(n).
int nCr(int n, int r)
{
    int num, den;

    num = fact(n);
    den = fact(r) * fact(n - r);

    return num / den;
}

// Solution using "Pascal's Triangle" for its logic.
int NCR(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main(void)
{
    printf("%d\n%d\n", nCr(10,3), NCR(10, 3));
    return 0;
}