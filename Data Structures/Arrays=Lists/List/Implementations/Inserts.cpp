#include "_LIST.h"

// Inserts at a given position.
void List::Insert(int index, int value)
{
    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        for(int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = value;
        length++;
    }
}

// Inserts at a given position.
void List::SortedInsert(int value)
{    
//     if (!sorted)
//     {
//         cout << "The array must be sorted for this to work." << endl;
//         return;
//     }

    // We can only insert/append while the vector isn't at its max length.
    if(length < max_length)
    {
        int i;
        // if (sorted == 1)
        // {
        for (i = length; i > 0 && value < A[i - 1]; i--)
            A[i] = A[i-1];
        A[i] = value;
        // }
        // else if (sorted == -1)
        // {
        //     for (i = length; value > A[i] && i > 0; i--)
        //         A[i] = A[i-1];
        //     A[i] = value;
        // }
        length++;
    }
}
