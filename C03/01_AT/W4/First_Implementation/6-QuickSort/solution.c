#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();

void printArray(int *array, int array_length);

void swap(int *first_value, int *second_value);
int partition(int *array, int left, int right);
void quicksort(int *array, int array_length);
void _quicksort(int *array, int array_length, int left, int right);

int main()
{
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    quicksort(array, array_length);
    printArray(array, array_length);

    free(array);
    return 0;
}

int get_array_size_from_stdin()
{
    int array_length;
    scanf("%d", &array_length);

    return array_length;
}

int *get_array_from_stdin(int array_length)
{
    int *array = (int *) malloc (array_length * sizeof(int));
    for (int pos = 0; pos < array_length; ++pos)
        scanf("%d", array + pos);
    return array;
}

void quicksort(int *array, int array_length)
{
    _quicksort(array, array_length, 0, array_length - 1);
}

// "Simpler" quicksort
// void _quicksort(int *array, int array_length, int left, int right)
// {
//     if (left > right)
//         return;

//     int middle = partition(array, left, right);

//     _quicksort(array, array_length, left, middle - 1);
//     _quicksort(array, array_length, middle + 1, right);
// }

// This version is nlog n is space consumed.
void _quicksort(int *array, int array_length, int left, int right)
{
    while (left < right)
    {
        int middle = partition(array, left, right);
        if (middle - left < right - middle)
        {
            _quicksort(array, array_length, left, middle - 1);
            left = middle + 1;
        }
        else
        {
            _quicksort(array, array_length, middle + 1, right);
            right = middle - 1;
        }
    }
}

int partition(int *array, int left, int right)
{    
    int pivot_position = left + (right - left) / 2;
    int pivot = array[pivot_position];
    swap(&array[left], &array[pivot_position]);

    // The 3 lines (heuristics) above could be reduced to this one.
    // int pivot = array[left];

    int j = left;
    for (int i = left + 1; i <= right; ++i)
    {
        if (array[i] <= pivot)
        {
            j++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[left], &array[j]);
    return j;
}

void swap(int *first_value, int *second_value)
{
    int tmp_value = *first_value;
    *first_value = *second_value;
    *second_value = tmp_value;
}

void printArray(int *array, int array_length)
{
    printf("[");
    for (int pos = 0; pos < array_length; ++pos)
    {
        printf("%d", array[pos]);
        if (pos != array_length - 1)
            printf(", ");
    }
    printf("]\n");
}
