#include "_LIST.h"

int List::LinearSearch(int value)
{
    for(int i = 0; i < length; i++)
    {
        if(value == A[i])
        {
            // This moves the searched item to the first spot. It makes little sense to me tbh.
            // Swap(&A[i], &A[0]);


            // This is called "transposition". A little better than the one above (to me).
            // The value is gonna be one spot nearer the beginning of the list.
            // if (i > 0)
            // {
            //     i--; // This is so we can return the correct position after the search.
            //     Swap(&A[i + 1], &A[i]);
            // }

            return i;
        }
    }
    return -1;
}