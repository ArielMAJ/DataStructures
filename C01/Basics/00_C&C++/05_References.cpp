#include <stdio.h>

int main(void)
{
    int a = 10;
    int &r = a;
    // "r" is a reference to "a". Meaning "r" and "a" are different names to the same
    // thing. They're, basically, the same variable (but with different names).
    // A reference must be initialized at declaration time. References are a C++ thing,
    // They are mostly used with function parameters.

    // They have the same address.
    printf("Adrees of a: %p, Address of r: %p;\n", &a, &r);

    // Their values are the same and change together:
    printf("a: %2d, r: %2d;\n", a, r);
    r++;
    printf("a: %2d, r: %2d;\n", a, r);
    r = 5;
    printf("a: %2d, r: %2d;\n", a, r);
    a = 7;
    printf("a: %2d, r: %2d;\n", a, r);

    // They have the same address, and it doesn't change throughout the program.
    printf("Adrees of a: %p, Address of r: %p;\n", &a, &r);

    return 0;
}
