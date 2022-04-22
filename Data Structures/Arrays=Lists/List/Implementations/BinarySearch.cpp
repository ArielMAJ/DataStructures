#include "_LIST.h"

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


// int List::Find(int value)
// {
//     if (sorted)
//         return BinarySearchLeftMost(value);
//     return LinearSearch(value);
// }