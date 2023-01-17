#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();

void printArray(int *array, int array_length);
void copy_array(int *dest, int *src, int length);

int find_maximum_value(int *array, int array_length);
int find_minimal_value(int *array, int array_length);
void counting_sort(int *array, int array_length);

int main()
{
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    counting_sort(array, array_length);
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

void counting_sort(int *array, int array_length)
{
    int minimal_value_in_array = find_minimal_value(array, array_length);
    int maximum_value_in_array = find_maximum_value(array, array_length);

    int number_range_in_input_array = maximum_value_in_array - minimal_value_in_array + 1;
    int *counter_of_occurrences_of_a_number = (int *) calloc(number_range_in_input_array, sizeof(int));

    for (int pos = 0; pos < array_length; ++pos)
        counter_of_occurrences_of_a_number[array[pos] - minimal_value_in_array]++;

    int *final_position = (int *) calloc(number_range_in_input_array, sizeof(int));
    for (int pos = 1; pos < number_range_in_input_array; ++pos)
        final_position[pos] = final_position[pos - 1] + counter_of_occurrences_of_a_number[pos - 1];

    int *new_array = (int *) calloc(array_length, sizeof(int));;
    for (int pos = 0; pos < array_length; ++pos)
        new_array[final_position[array[pos] - minimal_value_in_array]++] = array[pos];

    copy_array(array, new_array, array_length);
    free(counter_of_occurrences_of_a_number);
    free(final_position);
    free(new_array);
}

void copy_array(int *dest, int *src, int length)
{
    for (int i = 0; i < length; ++i)
        dest[i] = src[i];
}

int find_maximum_value(int *array, int array_length)
{
    int maximum_value_in_array = array[0];
    for (int position = 1; position < array_length; ++position)
    {
        if (array[position] > maximum_value_in_array)
            maximum_value_in_array = array[position];
    }
    return maximum_value_in_array;
}

int find_minimal_value(int *array, int array_length)
{
    int minimal_value_in_array = array[0];
    for (int position = 1; position < array_length; ++position)
    {
        if (array[position] < minimal_value_in_array)
            minimal_value_in_array = array[position];
    }
    return minimal_value_in_array;
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

    return;
}
