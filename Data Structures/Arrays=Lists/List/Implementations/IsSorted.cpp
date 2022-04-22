#include "_LIST.h"

bool List::IsSorted()
{
    for (int i = 1; i < length; i++)
    {
        if (A[i] < A[i - 1])
            return false;
    }
    return true;
}