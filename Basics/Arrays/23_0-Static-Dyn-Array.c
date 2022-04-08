// Static vs Dynamic Arrays

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = { 2, 4, 6, 8, 10 }; // Static array: will always have exactly the predefined size of 5.
    int *p; // A pointer. It can point to anything, including an array (which is what it's gonna be used for).

    int space_needed_for_array = 5;
    p = (int *) malloc(space_needed_for_array * sizeof(int)); // Malloc dynamically allocates memory in the ammount asked.
    // We should be careful to ask exactly as much memory as we need. Not more (because it would be a waste),
    // and certainly not less.
    // Malloc returns a void type pointer which points to the created array. Thus we gotta type cast that returned pointer
    // to the pointer type needed (int in this case) and save it to a pointer variable so we can access the array.

    // Initializing variables:
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    // If we used "p = (int *) calloc(space_needed_for_array, sizeof(int));" instead, everything would be
    // initialized to 0.

    for (int i = 0; i < 5; i++)
        printf("%d ", A[i]); // Printing static array.

    printf("\n");
    
    for (int i = 0; i < 5; i++)
        printf("%d ", p[i]); // Printing dynamic array.

    // Note that both array types work exactly the same. In reality, BOTH are pointers to the beginning of the array. 
    // The difference is that static arrays point to arrays in the stack (which are popped out once we're out of their scope)
    // while dynamic ones point to arrays in heap (which persist throughout scopes).
    // Another thing about dynamic arrays and dynamic memory allocation is that we gotta free the allocated memory once we're
    // done with them:

    free(p);
    
    return 0;
}