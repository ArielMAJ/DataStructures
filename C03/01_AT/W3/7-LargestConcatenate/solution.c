#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int read_int_value();
void populate_array(int *array, int array_size);
int *create_heap_array(int array_size);
int *read_int_array(int array_size);
void printConcatenatedArray(int *array, int array_size);

bool is_worse(int first_value, int second_value);
void swap(int *first_value, int *second_value);

void reorder_to_largest_concatenate(int *array, int array_size);

int main()
{
    int array_size = read_int_value();
    int *array = read_int_array(array_size);

    reorder_to_largest_concatenate(array, array_size);
    printConcatenatedArray(array, array_size);

    free(array);
    return 0;
}

void reorder_to_largest_concatenate(int *array, int array_size)
{
    for (int i = 0; i < array_size - 1; ++i)
        for (int j = i + 1; j < array_size; ++j)
            if (is_worse(array[i], array[j]))
                swap(&array[i], &array[j]);
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

void swap(int *first_value, int *second_value)
{
    int temp_var = *first_value;
    *first_value = *second_value;
    *second_value = temp_var;
}

bool is_worse(int first_value, int second_value)
{
    char buff_01[50];
    char buff_02[50];

    sprintf(buff_01, "%d", first_value);
    sprintf(buff_02, "%d", second_value);

    char str_value_01[100];
    char str_value_02[100];

    str_value_01[0] = '\0';
    str_value_02[0] = '\0';

    strcat(str_value_01, buff_01);
    strcat(str_value_01, buff_02);

    strcat(str_value_02, buff_02);
    strcat(str_value_02, buff_01);

    int pos = 0;
    while (true)
    {
        if (str_value_01[pos] == '\0' && str_value_02[pos] == '\0')
            return false;
        if (str_value_01[pos] < str_value_02[pos])
            return true;
        if (str_value_01[pos] > str_value_02[pos])
            return false;
        pos++;
    }
}

void printConcatenatedArray(int *array, int array_size)
{
    for (int i = 0; i < array_size; ++i)
        printf("%d", array[i]);
    printf("\n");
}