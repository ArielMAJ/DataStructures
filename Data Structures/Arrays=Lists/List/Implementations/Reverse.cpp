#include "_LIST.h"

void List::Reverse()
{
    for (int start = 0, end = length - 1; start < end; start++, end--)
        Swap(&A[start], &A[end]);
    // if (sorted)
    //     sorted *= -1;
}