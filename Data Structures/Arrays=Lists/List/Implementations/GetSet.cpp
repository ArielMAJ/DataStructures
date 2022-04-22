#include "_LIST.h"

int List::Get(int index)
{
    if (index < length && index >= 0)
        return A[index];
    cout << "Invalid index, returning 0." << endl;
    return 0;
}

void List::Set(int index, int value)
{
    if (index < length && index >= 0)
        A[index] = value;
}
