#include <stdio.h>

void swap(int *first_value, int *second_value);
int partition(int *array, int left, int right);
void quicksort(int *array, int array_length, int left, int right);
int binary_search_left_most(int *array, int array_length, int search_value);

int found_a_majority_element(int *array, int array_length);

int main()
{
    int array_length;
    scanf("%d", &array_length);

    int array[array_length];
    for (int i = 0; i < array_length; i++)
        scanf("%d", &array[i]);

    printf("%d\n", found_a_majority_element(array, array_length));

    return 0;
}

int found_a_majority_element(int *array, int array_length)
{
    quicksort(array, array_length, 0, array_length - 1);

    int middle_element = ((-1 * array_length) / 2) * -1;

    int goes_through_left_side;
    int goes_through_right_side;

    if (array_length % 2 == 1)
    {
        goes_through_left_side = array[middle_element - 1] == array[middle_element];
        goes_through_right_side = array[middle_element] == array[middle_element + 1];
    }
    else
    {
        goes_through_left_side = array[middle_element - 1] == array[middle_element];
        goes_through_right_side = goes_through_left_side;
    }

    if (!goes_through_left_side && !goes_through_right_side)
        return 0;

    if (goes_through_left_side && !goes_through_right_side)
    {
        if (array[0] != array[middle_element])
            return 0;
        return 1;
    }
    if (!goes_through_left_side && goes_through_right_side)
    {
        if (array[middle_element] != array[array_length - 1])
            return 0;
        return 1;
    }

    int left_most_pos = binary_search_left_most(array, array_length, array[middle_element]);

    if (array[left_most_pos] == array[array_length / 2 + left_most_pos])
        return 1;
    return 0;
}

void quicksort(int *array, int array_length, int left, int right)
{
    while (left < right)
    {
        int middle = partition(array, left, right);
        if (middle - left < right - middle)
        {
            quicksort(array, array_length, left, middle - 1);
            left = middle + 1;
        }
        else
        {
            quicksort(array, array_length, middle + 1, right);
            right = middle - 1;
        }
    }
}

int partition(int *array, int left, int right)
{
    int pivot_position = left + (right - left) / 2;
    int pivot = array[pivot_position];
    swap(&array[left], &array[pivot_position]);

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

int binary_search_left_most(int *array, int array_length, int search_value)
{
    int lower_bound = 0;
    int upper_bound = array_length - 1;

    while (lower_bound <= upper_bound)
    {
        int middle = lower_bound + (upper_bound - lower_bound) / 2;

        if (array[middle] == search_value)
        {
            if (array[middle - 1] != search_value)
                return middle;
            upper_bound = middle - 1;
        }
        else if (array[middle] < search_value)
            lower_bound = middle + 1;
        else
            upper_bound = middle - 1;
    }
    return -1;
}
