// Inserting and Appending in a Array

#include<stdio.h>

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
    Array arr1 = {{0, 1, 2, 3}, 7, 4};
    
    Append(&arr1, 11);
    Insert(&arr1, 0, 11);
    Display(arr1);
    
    return 0;
}

void Display(Array arr)
{
    printf("\nElements are\n");   
    for(int i = 0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
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
