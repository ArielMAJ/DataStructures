#include "_LIST.h"

// The difference here is that this one is \Theta(log n) while the normal
// one is \omega(1) in the best case scenario.
// This one will try to find the left most value in the case of repeating
// numbers in the list.
int List::BinarySearchLeftMost(int value)
{
//     if (!sorted)
//     {
//         cout << "The array must be sorted for binary search to work." << endl;
//         return -1;
//     }

    int left = 0;
    int right = length - 1;
    int mid;
    int pos = -1;

    // If sorted
    // This will return the left most ocurrence.
    // if (sorted == 1)
    // {
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (value == A[mid])
        {
            if (A[mid] != A[mid - 1])
                return mid;
            pos = mid;
        }

        if (value > A[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    // }
    // If sorted backwards
    // This will return the right most ocurrence (which would be the left most if sorted normally)
    // else if (sorted == -1)
    // {
    //     while (left <= right)
    //     {
    //         mid = (left + right) / 2;

    //         if (value == A[mid])
    //         {
    //             if (A[mid] != A[mid + 1])
    //                 return mid;
    //             pos = mid;
    //         }

    //         if (value > A[mid])
    //             right = mid - 1;
    //         else
    //             left = mid + 1;
    //     }
    // }
    return pos;
}

int List::BinarySearch(int value)
{
//     if (!sorted)
//     {
//         cout << "The array must be sorted for binary search to work." << endl;
//         return -1;
//     }

    int left = 0;
    int right = length - 1;

    int mid;
    
    // If sorted
    // if (sorted == 1)
    // {
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (value == A[mid]) return mid;

        if (value > A[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    // }
    // If sorted backwards
    // else if (sorted == -1)
    // {
    //     while (left <= right)
    //     {
    //         mid = (left + right) / 2;

    //         if (value == A[mid]) return mid;

    //         if (value < A[mid])
    //             left = mid + 1;
    //         else
    //             right = mid - 1;
    //     }
    // }
    return -1;
}



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

// int List::Find(int value)
// {
//     if (sorted)
//         return BinarySearchLeftMost(value);
//     return LinearSearch(value);
// }
