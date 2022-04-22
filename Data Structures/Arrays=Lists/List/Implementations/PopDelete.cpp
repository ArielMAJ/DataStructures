#include "_LIST.h"

// Pops (deletes and returns a value) at a given index/position.
int List::Pop(int index)
{
    if (index >= length || index < 0)
    {
        cout << "Invalid index, returning 0." << endl;
        return 0;
    }

    // Saving the popped value for returning it later.
    int popped_value = A[index];

    // The vector will be shorter.
    length--;

    // Moving values to the front to occupy the value we're deleting.
    for (int i = index; i < length; i++)
        A[i] = A[i+1];

    // Returning the popped value.
    return popped_value; 
}

// Deletes a specific value and returns it.
void List::Delete(int value)
{
    // int index = Find(value);
    int index = LinearSearch(value);
    if (index >= 0)
        Pop(index);
}