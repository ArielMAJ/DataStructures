#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();
void merge_sort(int *array, int array_length);
void _merge_sort(int *array, int first_position, int final_position);
void merge_the_two_sections_of_the_array(int *array, int first_position, int middle_position, int final_position);
void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(int *first_array, int starting_position_in_first_array, int *second_array, int second_array_length);
int there_are_still_values_left_in_at_least_one_of_the_array_sections(int pos_first_array_half, int middle_position, int pos_second_array_half, int final_position);
void printArray(int *array, int array_length);

int main()
{
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    merge_sort(array, array_length);

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

void merge_sort(int *array, int array_length)
{
    if (array_length <= 0)
        return;

    _merge_sort(array, 0, array_length - 1);
}

void _merge_sort(int *array, int first_position, int final_position)
{
    if (first_position == final_position)
        return;
    int middle_position = first_position + (final_position - first_position) / 2;
    _merge_sort(array, first_position, middle_position);
    _merge_sort(array, middle_position + 1, final_position);

    merge_the_two_sections_of_the_array(array, first_position, middle_position, final_position);
    return;
}

void merge_the_two_sections_of_the_array(int *array, int first_position, int middle_position, int final_position)
{
    int pos_first_array_half = first_position;
    int pos_second_array_half = middle_position + 1;
    int auxiliar_array_length = final_position - first_position + 1;
    int auxiliar_array[auxiliar_array_length];
    int aux_pos = 0;

    while (there_are_still_values_left_in_at_least_one_of_the_array_sections(pos_first_array_half, middle_position, pos_second_array_half, final_position))
    {
        if (pos_first_array_half <= middle_position && array[pos_first_array_half] <= array[pos_second_array_half])
            auxiliar_array[aux_pos++] = array[pos_first_array_half++];
        else
            auxiliar_array[aux_pos++] = array[pos_second_array_half++];
    }
    while (pos_first_array_half != (middle_position + 1))
        auxiliar_array[aux_pos++] = array[pos_first_array_half++];
    while (pos_second_array_half != (final_position + 1))
        auxiliar_array[aux_pos++] = array[pos_second_array_half++];
    copy_second_array_to_the_first_one_in_a_given_section_of_first_array(array, first_position, auxiliar_array, auxiliar_array_length);
}

int there_are_still_values_left_in_at_least_one_of_the_array_sections(int pos_first_array_half, int middle_position, int pos_second_array_half, int final_position)
{
    return pos_first_array_half != (middle_position + 1) && pos_second_array_half != (final_position + 1);
}

void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(int *first_array, int starting_position_in_first_array, int *second_array, int second_array_length)
{
    printf("Aux array len: %d\n", second_array_length);
    for (int current_position = 0; current_position < second_array_length; ++current_position)
        first_array[starting_position_in_first_array + current_position] = second_array[current_position];
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
