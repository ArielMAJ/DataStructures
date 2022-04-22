#include "_LIST.h"

int List::Max()
{
    int max_pos = 0;

    for (int i = 1; i < length; i++)
    {
        if (A[i] > A[max_pos])
            max_pos = i;
    }
    return max_pos;
}
