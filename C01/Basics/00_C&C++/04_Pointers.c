#include <stdio.h>
#include <stdlib.h>

void printArray(int Array[], int length);

int main()
{
    int arraySize = 5;
    int *heapArray = (int *) calloc(arraySize, sizeof(int));
    printf("Created a zero populated array:\n\t");
    printArray(heapArray, arraySize);

    heapArray[2] = 2;
    printf("Assignment and usage of heap arrays work the same as normal stack arrays:\n\t");
    printArray(heapArray, arraySize);

    printf("\nPopulating array with a for loop:\n");
    for (int pos = 0; pos < arraySize; ++pos)
    {
        printf("\tPosition %d receiving value %d\n\t", pos, pos * 2);
        heapArray[pos] = pos * 2;
        printArray(heapArray, arraySize);
    }

    // There are different ways of accessing arrays with pointers too:
    *heapArray = 1; // Same as "heapArray[0] = 1;"
    *(heapArray + 1) = 0; // Same as "heapArray[1] = 0"

    printf("\nShowing result of accessing pointers in different ways:\n\t");
    printArray(heapArray, arraySize);
    return 0;
}


void printArray(int Array[], int length)
// Prints array of given length.
{
    printf("[");
    for (int pos = 0; pos < length; ++pos)
    {
        printf("%d", Array[pos]);
        if (pos != length - 1)
            printf(", ");
    }
    printf("]\n");

    return;
}
