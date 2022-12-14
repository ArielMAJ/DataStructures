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