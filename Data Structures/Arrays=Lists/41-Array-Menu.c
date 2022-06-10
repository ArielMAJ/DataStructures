// Array Menu using C

#include <stdio.h>
#include<stdlib.h>

typedef struct Array
{
    int *A;
    int size;
    int length;
} Array;

void Display(Array arr);
void Append(Array *arr, int x);
void Insert(Array *arr, int index, int x);
int Delete(Array *arr, int index);
void swap(int *x, int *y);
int LinearSearch(Array *arr, int key);
int BinarySearch(Array arr, int key);
int RBinSearch(int a[], int l, int h, int key);
int Get(Array arr, int index);
void Set(Array *arr, int index, int x);
int Max(Array arr);
int Min(Array arr);
int Sum(Array arr);
float Avg(Array arr);
void Reverse(Array *arr);
void Reverse2(Array *arr);
void InsertSort(Array *arr, int x);
int isSorted(Array arr);
void Rearrange(Array *arr);
Array *Merge(Array *arr1, Array *arr2);
Array *Union(Array *arr1, Array *arr2);
Array *Intersection(Array *arr1, Array *arr2);
Array *Difference(Array *arr1, Array *arr2);

int main()
{
    Array arr1;
    int ch;
    int x, index;

    printf("Enter Array Size: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *) malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\nMenu\n");
        printf("1. Insert;\n");
        printf("2. Delete;\n");
        printf("3. Search;\n");
        printf("4. Sum;\n");
        printf("5. Display;\n");
        printf("6. Exit;\n");

        printf("$: ");
        scanf("%d", &ch);

        system("cls");
        switch (ch)
        {
        case 1:
            printf("Enter element and index: ");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index: ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted element is %d.\n", x);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index %d.\n", index);
            break;
        case 4:
            printf("Sum is %d.\n", Sum(arr1));
            break;
        case 5:
            Display(arr1);

        }
    }
    while (ch < 6);
    return 0;
}

void Display(Array arr)
{
    int i;
    printf("[");
    for (i = 0; i < arr.length - 1; i++)
        printf("%d, ", arr.A[i]);

    if (arr.length > 0)
        printf("%d]\n", arr.A[i]);
    else
        printf("]\n");
}

void Append(Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;

}

void Insert(Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;

    }
}

int Delete(Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
        else
            return RBinSearch(a, mid + 1, h, key);
    }
    return -1;
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
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];

    return s;
}

float Avg(Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(Array *arr)
{
    int *B;
    int i, j;

    B = (int *) malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2(Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;

}

int isSorted(Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)i++;
        while (arr->A[j] >= 0)j--;
        if (i < j)swap(&arr->A[i], &arr->A[j]);
    }

}

Array *Merge(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = (Array *) malloc(sizeof(Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
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

Array *Intersection(Array *arr1, Array *arr2)
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
