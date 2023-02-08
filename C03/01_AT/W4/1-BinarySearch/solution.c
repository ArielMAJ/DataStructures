#include <stdio.h>
#include <stdlib.h>

int read_int_value();
void populate_array(int *array, int array_size);
int *create_heap_array(int array_size);
int *read_int_array(int array_size);
void printArray(int *array, int array_size);

int binary_search_iter(int *array, int array_length, int search_value);
int *problem_solution(int *sorted_array, int sorted_array_length, int *values_to_search, int search_values_length);

int main()
{
    int sorted_array_length = read_int_value();
    int *sorted_array = read_int_array(sorted_array_length);

    int search_values_length = read_int_value();
    int *values_to_search = read_int_array(search_values_length);

    int *values_positions = problem_solution(sorted_array, sorted_array_length, values_to_search, search_values_length);

    printArray(values_positions, search_values_length);

    free(sorted_array);
    free(values_to_search);
    free(values_positions);

    return 0;
}

int *problem_solution(int *sorted_array, int sorted_array_length, int *values_to_search, int search_values_length)
{
    int *values_positions = create_heap_array(search_values_length);

    for (int i = 0; i < search_values_length; ++i)
        values_positions[i] = binary_search_iter(sorted_array, sorted_array_length, values_to_search[i]);

    return values_positions;
}

int binary_search_iter(int *array, int array_length, int search_value)
{
    int lower_bound = 0;
    int upper_bound = array_length - 1;

    while (lower_bound <= upper_bound)
    {
        int middle = lower_bound + (upper_bound - lower_bound) / 2;

        if (array[middle] == search_value)
            return middle;

        if (array[middle] < search_value)
            lower_bound = middle + 1;
        else
            upper_bound = middle - 1;
    }
    return -1;
}


void populate_array(int *array, int array_size)
{
    for (int i = 0; i < array_size; i++)
        array[i] = read_int_value();
}

int *create_heap_array(int array_size)
{
    int *array = NULL;
    if (array_size > 0)
    {
        array = (int *) malloc(array_size * sizeof(int));

        if (array == NULL)
        {
            printf("Failed to alloc space.\n");
            exit(1);
        }
    }
    return array;
}

int read_int_value()
{
    int value;
    scanf("%d", &value);

    return value;
}

int *read_int_array(int array_size)
{

    int *array = create_heap_array(array_size);
    populate_array(array, array_size);

    return array;
}

void printArray(int *array, int array_size)
{
    for (int i = 0; i < array_size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
