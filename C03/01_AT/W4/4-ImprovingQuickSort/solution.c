#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();

void printArray(int *array, int array_length);

void swap(int *first_value, int *second_value);
int *partition3(int *array, int left, int right);
void quicksort(int *array, int array_length);
void _quicksort(int *array, int array_length, int left, int right);

int LEFT_MOST = 0;
int RIGHT_MOST = 1;

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

void _quicksort(int *array, int array_length, int left, int right)
{
    while (left < right)
    {
        int *middle = partition3(array, left, right);
        if (middle[LEFT_MOST] - left < right - middle[RIGHT_MOST])
        {
            _quicksort(array, array_length, left, middle[LEFT_MOST] - 1);
            left = middle[RIGHT_MOST] + 1;
        }
        else
        {
            _quicksort(array, array_length, middle[RIGHT_MOST] + 1, right);
            right = middle[LEFT_MOST] - 1;
        }
        free(middle);
    }
}

int *partition3(int *array, int left, int right)
{
    int pivot_position = left + (right - left) / 2;
    int pivot = array[pivot_position];
    swap(&array[left], &array[pivot_position]);

    int *middle = (int *) malloc(2 * sizeof(int));

    middle[LEFT_MOST] = left;
    middle[RIGHT_MOST] = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (array[i] == pivot)
        {
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
        }
        if (array[i] < pivot)
        {
            middle[LEFT_MOST]++;
            middle[RIGHT_MOST]++;
            swap(&array[middle[RIGHT_MOST]], &array[i]);
            swap(&array[middle[LEFT_MOST]], &array[middle[RIGHT_MOST]]);
        }
    }
    swap(&array[left], &array[middle[LEFT_MOST]]);
    return middle;
}

void swap(int *first_value, int *second_value)
{
    int tmp_value = *first_value;
    *first_value = *second_value;
    *second_value = tmp_value;
}

void printArray(int *array, int array_length)
{
    for (int pos = 0; pos < array_length; ++pos)
        printf("%d ", array[pos]);
    printf("\n");
}
