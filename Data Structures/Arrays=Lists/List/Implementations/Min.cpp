#include "_LIST.h"

int List::Min()
{
    int min_pos = 0;

    for (int i = 1; i < length; i++)
    {
        if (A[i] < A[min_pos])
            min_pos = i;
    }
    return min_pos;
}