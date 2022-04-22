#include "_LIST.h"

void List::RightShiftAll()
{
    RightShiftRange(0, length - 1);
}

void List::RightShiftRange(int start, int end)
{
    int tmp = A[end];
    for (int i = end; i > start; i--)
        A[i] = A[i - 1];
    A[start] = tmp;
}

void List::LeftShiftAll()
{
    LeftShiftRange(0, length - 1);
}

void List::LeftShiftRange(int start, int end)
{
    int tmp = A[start];
    for (int i = start; i < end; i++)
        A[i] = A[i + 1];
    A[end] = tmp;
}
