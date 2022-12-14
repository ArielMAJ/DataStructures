// Get Set Max Min on Array

#include<stdio.h>

typedef struct Array
{
    int A[10];
    int size;
    int length;
} Array;

void Display(Array arr);
int Get(Array arr, int index);
void Set(Array *arr, int index, int x);
int Max(Array arr);
int Min(Array arr);
int Sum(Array arr);
float Avg(Array arr);


int main()
{
    Array arr1={{0, 1, 2, 3, 4, 5, 6, 10}, 10, 8};
    Display(arr1);
    printf("Pos 7: %d\n", Get(arr1, 7));
    printf("arr1[7] = 7:\n");
    Set(&arr1, 7, 7);
    Display(arr1);
    
    printf("Sum: %d\n", Sum(arr1));
    printf("Avg: %.2f\n", Avg(arr1));
    printf("Max: %d\n", Max(arr1));
    printf("Min: %d\n", Min(arr1));

    return 0;
}

// Function for printing array datastructure.
void Display(Array arr)
{
    printf("Array:\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        max = arr.A[i];
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(Array arr)
{
    return (float) Sum(arr) / arr.length;
}