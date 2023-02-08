#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();
void selection_sort(int *array, int array_length);
void swap(int *first_value, int *second_value);
void printArray(int *array, int array_length);

int main()
{
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    selection_sort(array, array_length);

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

void selection_sort(int *array, int array_length)
{
    for (int i_left_pos = 0; i_left_pos < array_length; ++i_left_pos)
    {
        int min_index = i_left_pos;
        for (int j_right_pos = i_left_pos + 1; j_right_pos < array_length; ++j_right_pos)
            if (array[j_right_pos] < array[min_index])
                min_index = j_right_pos;
        swap(&array[i_left_pos], &array[min_index]);
    }
}

void swap(int *first_value, int *second_value)
{
    int temp_var = *first_value;
    *first_value = *second_value;
    *second_value = temp_var;
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
