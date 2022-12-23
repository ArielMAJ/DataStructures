#include <stdio.h>
#include <stdlib.h>

void printArray(int Array[], int length);

int main()
{
    int arraySize = 5;

    // Pointers are created with "*". They store the address of variables.
    int *examplePointer = &arraySize;

    // The address of a variable can be accessed with & (ampersand).
    // A value can be stored/accessed directly by using the variable name.
    printf("01 (Address, Value): (%d, %d) <-> Variable pointed to\n", &arraySize, arraySize);

    // You can get the address of a pointer with & too, but that usually doesn't make much sense.
    // You can store/acces an address in the pointer variable directly with its variable name (similar)
    // to how you save values in normal variables.
    // You can get the value stored in the pointed address by using "*".
    printf("02 (Address, Value): (%d, %d) <-> Pointer\n\n", examplePointer, *examplePointer);

    // Creating an array in heap (dinamically allocated memory).
    // "(int *) malloc(arraySize * sizeof(int));" and "(int *) calloc(arraySize, sizeof(int));" do the same.
    // The first one will return an unitialized array, the second one will be an array initialized with zeros.
    // Both malloc and calloc return a void type pointer, so it is needed to type cast to the correct pointer
    // type (in this case, an int pointer).
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

    // An array variable is basically a pointer to the first value of the array:
    int stackArray[] = {0, 11, 22, 33, 44, 55, 66, 77};
    // When assigning a pointer the memory address of an array (in stack or heap)
    // it will have the same behavior as a "common stack array".
    examplePointer = stackArray;
    printf("\nStack Array:\n\t");
    printArray(stackArray, 8);
    printf("Pointer to stack array:\n\t");
    printArray(examplePointer, 8);

    // Always remember to free dinamically allocated memory.
    free(heapArray);
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
