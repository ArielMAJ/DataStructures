#include "_LIST.h"

float List::Avg()
{
    return 1.0 * Sum() / length;
}

int List::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

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

bool List::IsSorted()
{
    for (int i = 1; i < length; i++)
    {
        if (A[i] < A[i - 1])
            return false;
    }
    return true;
}