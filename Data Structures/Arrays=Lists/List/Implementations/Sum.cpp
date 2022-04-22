#include "_LIST.h"

int List::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}
