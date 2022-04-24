// Checking if Array is Sorted

#include<stdio.h>

typedef struct Array
{
    int A[10];
    int max_length;
    int length;
} Array;

void PrintArray(struct Array arr)
{
    printf("\nArray:\n");
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length-1 ;i++)
    {
        if( arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
int main()
{
    Array myArray = {{1, 2, 3, 4, 5, 6, 7}, 15, 7};

    printf("%d\n", isSorted(myArray));
    PrintArray(myArray);
    return 0;
}