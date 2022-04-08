// 2D Array 

#include <stdio.h>
#include <stdlib.h>

// For static matrixes at least the second dimension should be hardcoded for reasons I don't yet understand.
// I have some guesses, but I'd be just rambling on here if I were to write them out.
void print_static_array(int (*array)[4]); // It could also be "void print_static_array(int array[3][4]);"
void print_dynamic_array(int **array); // This one HAS to be "**array".

int main()
{
    // Satic 2D array
    int A[3][4] = {
        {1, 2, 3, 4},
        {2, 4, 6, 8},
        {1, 3, 5, 7}
    };

    int *B[3]; // An array of pointers. It will have static row size but can be allocated with any column size.
    int **C; // Also an array of pointers. But this one is completely dynamically allocated.
    // Meaning it's necessary to allocate space for the array of pointers in addition to the arrays which will
    // contain the data.

    // Usual allocation, but for each slot in the array.
    B[0] = (int *) calloc(4, sizeof(int)); // Note each "slot" is receiving a pointer to an array in heap.
    B[1] = (int *) calloc(4, sizeof(int));
    B[2] = (int *) calloc(4, sizeof(int));

    
    // Note we're casting to "(int **)" and using the size of an int pointer "sizeof(int *)" and not sizeof(int).
    C = (int **) calloc(3, sizeof(int *));
    // Then we allocate the same way as with a static array of pointers.
    C[0] = (int *) calloc(4, sizeof(int));
    C[1] = (int *) calloc(4, sizeof(int));
    C[2] = (int *) calloc(4, sizeof(int));

    print_static_array(A);
    print_dynamic_array(B); // Initialized to 0's through calloc.
    print_dynamic_array(C); // Initialized to 0's through calloc.

    for (int i = 0; i < 3; i++)
    {
        free(B[i]); // We have to iterate over the array and free each allocation.
        free(C[i]);
    }

    free(C); // For this kind of array we also have to free the array of pointers.

    return 0;
}

void print_static_array(int (*array)[4])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_dynamic_array(int **array)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}