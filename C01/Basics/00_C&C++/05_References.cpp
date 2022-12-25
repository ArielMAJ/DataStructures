#include <stdio.h>

void swap_copies(int a, int b);
void swap_refs(int &a, int &b);
void swap_pointers(int *a, int *b);

int main(void)
{
    int a = 10;
    int b = 11;

    int &r = a;
    // "r" is a reference to "a". Meaning "r" and "a" are different names to the same
    // thing. They're, basically, the same variable (but with different names).
    // A reference must be initialized at declaration time. References are a C++ thing,
    // They are mostly used with function parameters.

    // "a" and "r" have the same address.
    printf("Address of a: %p;\n", &a);
    printf("Address of r: %p;\n", &r);
    printf("Address of b: %p;\n", &b);

    // Their values are the same and change together:
    printf("\nInitial values:\n");
    printf("a: %2d, r: %2d;\n\n", a, r);

    printf("r++:\n");
    r++;
    printf("a: %2d, r: %2d;\n\n", a, r);

    printf("r = 5:\n");
    r = 5;
    printf("a: %2d, r: %2d;\n\n", a, r);

    printf("a = 7:\n");
    a = 7;
    printf("a: %2d, r: %2d;\n\n", a, r);

    // They have the same address, and it doesn't change throughout the program.
    printf("Address of a: %p;\n", &a);
    printf("Address of r: %p;\n", &r);
    printf("Address of b: %p;\n", &b);

    // Functions swap_pointers and swap_refs show the difference between
    // pointers and references. They are similar, but not the same.
    printf("\nInitial values:\n");
    printf("a: %2d, b: %2d;\n\n", a, b);

    swap_pointers(&a, &b);
    printf("swap_pointers:\n");
    printf("a: %2d, b: %2d;\n\n", a, b);

    swap_refs(a, b);
    printf("swap_refs:\n");
    printf("a: %2d, b: %2d;\n\n", a, b);

    swap_copies(a, b);
    printf("swap_copies (does no changes to outer scope):\n");
    printf("a: %2d, b: %2d;\n\n", a, b);

    return 0;
}

void swap_pointers(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void swap_refs(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

void swap_copies(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}