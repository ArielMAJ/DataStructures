// Inserting and Appending in a Array

#include<stdio.h>

// Defining the array data type:
typedef struct Array {
    int A[10];
    int size;
    int length;
} Array;

void Display(Array arr);
void Append(Array *arr, int x);
void Insert(Array *arr, int index, int x);


int main()
{
    // Starting an array of size 4 and max size 7.
    Array arr1 = {{0, 1, 2, 3}, 7, 4};

    // Appending "12" to the end of the array.
    Append(&arr1, 12);
    Display(arr1);

    // Inserting "11" to the start of the array.
    Insert(&arr1, 0, 11);
    Display(arr1);
    
    return 0;
}

// Function for printing array datastructure.
void Display(Array arr)
{
    printf("Elements are\n");   
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}


void Append(Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}
