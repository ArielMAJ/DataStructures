#include "_LIST.h"

// Appends to the end of the List.
void List::Append(int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        A[length] = value;
        length++;
    }
}

// Inserts at position 0.
void List::Push(int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        for(int i = length; i > 0; i--)
            A[i] = A[i-1];
        A[0] = value;
        length++;
    }
}
