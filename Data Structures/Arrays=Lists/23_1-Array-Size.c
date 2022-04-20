// Array Size

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;

    // In malloc we pass in the amount of bytes we need. It's best practice to just get the size of
    // the "object"/struct you want to create an array of (using sizeof(object_type)) and multiply
    // by the size you want your array to be:
    p = (int *) malloc(5 * sizeof(int)); // Int array of size 5
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    q = (int *) malloc(10 * sizeof(int)); // Int array of size 10

    for(int i = 0; i < 5; i++)
        q[i] = p[i]; // Here we're actually copying the values from one array to the other.

    free(p);

    p = q; // We can have multiple pointers pointing to the same array.
    q = NULL; // As long as there's at least one pointer to the array and we free
    // the array there won't be any memory leaks (in principle, considering every goes well).

    for(int i = 0; i < 5; i++)
        printf("%d \n", p[i]); // Now "p" points to an array of size 10 (but we're using only up until the 5th "slot").

    free(p);

    return 0;
}