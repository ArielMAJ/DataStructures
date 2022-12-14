// The next command should work both on Windows and WSL:
// gcc -Wall -Wextra -o a.exe 02_Arrays.c; ./a.exe; rm ./a.exe;
// The flag -Werror is also nice: it won't finish compiling upon finding errors.

#include <stdio.h>

void print(int Array[], int length);

int main()
{
    // Declare array and assign values in one line:
    int A[5] = {1, 2, 3, 4, 5};  // Array size 5; All values initialized;
    print(A, 5);
    printf("Size of A: %lu\n", (long unsigned) sizeof(A));

    int B[5] = {1, 2, 3};  // Array size 5; Unitialized values will be initialized to 0;
    print(B, 5);
    printf("Size of B: %lu\n", (long unsigned) sizeof(B));

    int C[5] = {0};  // Array size 5; Unitialized values will be initialized to 0;
    print(C, 5);
    printf("Size of C: %lu\n", (long unsigned) sizeof(C));

    int D[] = {1, 2, 3};  // Array size 3; No unitialized values;
    print(D, 3);
    printf("Size of D: %lu\n", (long unsigned) sizeof(D));

    int E[] = {11};  // Array size 1; No unitialized values;
    print(E, 1);
    printf("Size of E: %lu\n", (long unsigned) sizeof(E));

    int F[] = {11, 12};  // Array size 2; No unitialized values;
    print(F, 2);
    printf("Size of F: %lu\n", (long unsigned) sizeof(F));

    // A, B, C, D, E and F are basically the same thing as a pointer with the location in memory of the first value of the array.
    int *G = D;  // D is the location in memory of the first value of the array {D[0], D[1], D[2]}.
    print(G, 3);
    printf("Size of G: %lu\n", (long unsigned) sizeof(G));  // Returns the size of the pointer instead of the array.

    int *H = &G[0];  // &G[0] is the location in memory of the first value of the array {D[0], D[1], D[2]}.
    print(H, 3);
    printf("Size of E: %lu\n", (long unsigned) sizeof(H));


    // Variable size arrays can't be initialized as per above (some compiler may give out an error, others may run but
    // not work properly);
    printf("\nEnter size of new array: ");
    int size;
    scanf("%d", &size);
    int I[size];
    I[0] = 11;
    print(I, size);

    return 0;
}

void print(int Array[], int length)
// Prints array of given length.
{
    printf("[");
    for (int pos = 0; pos < length; ++pos)
    {
        printf("%d", Array[pos]);
        if (pos != length - 1)
            printf(", ");
    }
    printf("]\n");

    return;
}
