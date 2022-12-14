// Set Operations on Arrays
#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int A[10];
    int size;
    int length;
} Array;

void Display(Array arr);
Array *Union(Array *arr1, Array *arr2);
Array *Intersection(Array *arr1, Array *arr2);
Array *Difference(Array *arr1, Array *arr2);

int main()
{
    Array *aux;
    {
        Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
        Array arr2 = {{2, 3, 9, 18, 28}, 10, 5};
        aux = Union(&arr1, &arr2);
        Display(*aux);
        free(aux);
    }

    {
        Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
        Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
        aux = Intersection(&arr1, &arr2);
        Display(*aux);
        free(aux);
    }
    {
        Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
        Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
        aux = Difference(&arr1, &arr2);
        Display(*aux);
        free(aux);
    }
    return 0;
}

void Display(Array arr)
{
    int i;
    printf("\nArray: ");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
Array *Union(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = (Array *) malloc(sizeof(Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
Array *Intersection(Array *arr1, Array
                    *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = (Array *) malloc(sizeof(Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
Array *Difference(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = (Array *) malloc(sizeof(Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}