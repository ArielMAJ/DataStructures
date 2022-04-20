// Binary Search in Array

#include<stdio.h>

typedef struct Array
{
    int A[10];
    int size;
    int length;
} Array;

void Display(Array arr);
int BinarySearch(Array arr, int key);
int RBinSearch(int a[], int l, int h, int key);

int main()
{
    Array arr1 = {{1, 3, 5, 7, 8, 9, 10, 11, 13, 15}, 15, 10};
    Display(arr1);
    printf("\nFound \"8\" at position %d\n\n", BinarySearch(arr1, 8));
    return 0;
}

void Display(Array arr)
{
    printf("Array:\n");
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

// Iterative version: simpler sometimes can be better.
int BinarySearch(Array arr, int key)
{
    int low = 0;
    int high = arr.length - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

// Recursive version.
// Should be avoided because, as it is just a tail recursion,
// it can be easily translated into a loop. Thus, it is just consuming
// extra space on the stack without any addition in time complexity.
int RBinSearch(int array[], int low, int high, int key)
{
    int mid = 0;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == array[mid])
            return mid;
        else if (key < array[mid])
            return RBinSearch(array, low, mid - 1, key);
        else
            return RBinSearch(array, mid + 1, high, key);
    }
    return -1;
}