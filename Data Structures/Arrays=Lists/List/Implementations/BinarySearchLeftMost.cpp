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
