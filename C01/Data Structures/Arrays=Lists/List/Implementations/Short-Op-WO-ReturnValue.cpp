#include "_LIST.h"

// Constructor
List::List(int initial_size)
{
    // We will assume the array won't be sorted after populated.
    // sorted = 1;
    // The current length is 0. The List is "empty".
    length = 0;
    // Saving the max length.
    max_length = initial_size;
    // allocating space for the vector.
    A = new int [initial_size];
}

// This "properly creates" the List.
void List::Create()
{
    cout << "List length: ";
    cin >> length;
    cout << endl << "Elements:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << "Position " << i << ": ";
        cin >> A[i];
    }
}

List::~List()
{
    // We allocated space for the List. So we need to make sure to free it too.
    delete [] A;
}

// Displays the List.
void List::Display()
{
    for(int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void List::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}