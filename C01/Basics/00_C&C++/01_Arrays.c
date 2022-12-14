// The next command should work both on Windows and WSL:
// gcc -Wall -Wextra -o a.exe 01_Arrays.c; ./a.exe; rm ./a.exe;
// The flag -Werror is also nice: it won't finish compiling upon finding errors.

#include <stdio.h>

int main()
{
    // Declare an array:
    int A[5];
    // Assign values:
    A[0] = 12;
    A[1] = 15;
    // A[2] = 25;
    // A[3] = 25;
    A[4] = 25;

    // Type casting to "long unsigned" so there are no (or less) error
    // messages in both Windows and WSL.
    printf("Size of A: %8.2lu\n", (long unsigned) sizeof(A));
    printf("\n");
    printf("Size of A[0]:\t%8.2lu\n", (long unsigned) sizeof(A[0]));
    printf("Size of A[1]:\t%8.2lu\n", (long unsigned) sizeof(A[1]));
    printf("Size of A[2]:\t%8.2lu\n", (long unsigned) sizeof(A[2]));
    printf("Size of A[3]:\t%8.2lu\n", (long unsigned) sizeof(A[3]));
    printf("Size of A[4]:\t%8.2lu\n", (long unsigned) sizeof(A[4]));
    printf("\n");
    printf("Value in A[0]:\t%8.2d\n", A[0]);
    printf("Value in A[1]:\t%8.2d\n", A[1]);

    // Non-initiallized positions might either be 0 or some
    // other value that was already in that memory location.
    printf("Value in A[2]:\t%8.2d\n", A[2]);
    printf("Value in A[3]:\t%8.2d\n", A[3]);

    // You can initialize some positions and not initialize others.
    printf("Value in A[4]:\t%8.2d\n", A[4]);

    // Positions past array size limit might have unexpected behavior.
    // printf("Value in A[5]:\t%8.2d\n", A[5]);
    return 0;
}
