#include <stdio.h>

int main()
{
    int A[5];
    A[0]=12;
    A[1]=15;
    A[2]=25;

    printf("Size of A:\t\t%d\n", sizeof(A));
    printf("Size of A[0]:\t%02d\n", sizeof(A[0]));
    printf("Value in A[0]:\t%d\n", A[0]);
    printf("Value in A[1]:\t%d\n", A[1]);
    printf("Value in A[2]:\t%d\n", A[2]);
    return 0;
}