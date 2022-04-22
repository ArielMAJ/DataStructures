#include "_LIST.h"

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
 

