#include <stdio.h>
#include <stdlib.h>

int get_search_value_from_stdin();
int get_array_size_from_stdin();
int *get_array_from_stdin();

int binary_search_recursive(int *array, int lower_bound, int upper_bound, int search_value);
int binary_search_iterative(int *array, int lower_bound, int upper_bound, int search_value);

int main()
{
    int search_value = get_search_value_from_stdin();
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    int recursive_result = binary_search_recursive(array, 0, array_length - 1, search_value);
    int iterative_result = binary_search_iterative(array, 0, array_length - 1, search_value);

    printf("Recursive output: %3d\n", recursive_result);
    printf("Iterative output: %3d\n", iterative_result);

    free(array);
    return 0;
}

int get_search_value_from_stdin()
{
    int search_value;
    scanf("%d", &search_value);

    return search_value;
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

int binary_search_recursive(int *array, int lower_bound, int upper_bound, int search_value)
{
    if (upper_bound < lower_bound)
        return lower_bound - 1;

    int middle = lower_bound + (upper_bound - lower_bound) / 2;

    if (array[middle] == search_value)
        return middle;

    if (array[middle] < search_value)
        return binary_search_recursive(array, middle + 1, upper_bound, search_value);
    return binary_search_recursive(array, lower_bound, middle - 1, search_value);
}

int binary_search_iterative(int *array, int lower_bound, int upper_bound, int search_value)
{
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
    return lower_bound - 1;
}
