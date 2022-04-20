// Deleting from Array

#include<stdio.h>

typedef struct Array {
    int A[10];
    int size;
    int length;
} Array;

void Display(Array arr);
int Delete(Array *arr, int index);


int main()
{
    Array arr1={{10, 11, 12, 13}, 10, 4};

    Display(arr1);
    printf("\nDeleted: %d\n", Delete(&arr1, 0));
    Display(arr1);
    
    return 0;
}

void Display(Array arr)
{
    printf("\nElements are\n");
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int Delete(Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;

        return x;
    }
    
    return 0;
}