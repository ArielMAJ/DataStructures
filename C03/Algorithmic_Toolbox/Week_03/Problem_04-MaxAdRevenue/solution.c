#include <stdio.h>
#include <stdlib.h>

void merge_sort(long long *array, int array_length);
void _merge_sort(long long *array, int first_position, int final_position);
void merge_the_two_sections_of_the_array(long long *array, int first_position, int middle_position, int final_position);
void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(long long *first_array, int starting_position_in_first_array, long long *second_array, int second_array_length);
int there_are_still_values_left_in_at_least_one_of_the_array_sections(int pos_first_array_half, int middle_position, int pos_second_array_half, int final_position);

void read_from_stdin(int *value);
void populate_array(long long *values, int amount_of_values);
void alloc_space(long long **values, int amount_of_values);

long long max_dot_product(long long *vect_01, long long *vect_02, int vect_size);

int main()
{

    int vect_size;
    read_from_stdin(&vect_size);

    long long *vect_01 = NULL;
    alloc_space(&vect_01, vect_size);
    populate_array(vect_01, vect_size);

    long long *vect_02 = NULL;
    alloc_space(&vect_02, vect_size);
    populate_array(vect_02, vect_size);

    long long dot_prod_result = max_dot_product(vect_01, vect_02, vect_size);

    printf("%lld\n", dot_prod_result);

    if (vect_01 != NULL)
        free(vect_01);
    if (vect_02 != NULL)
        free(vect_02);
    return 0;
}


long long max_dot_product(long long *vect_01, long long *vect_02, int vect_size)
{
    merge_sort(vect_01, vect_size);
    merge_sort(vect_02, vect_size);

    long long dot_prod_result = 0;

    for (int i = 0; i < vect_size; ++i)
        dot_prod_result += vect_01[i] * vect_02[i];
    return dot_prod_result;
}

void read_from_stdin(int *value)
{
    scanf("%d", value);
}

void populate_array(long long *values, int amount_of_values)
{
    for (int i = 0; i < amount_of_values; i++)
        scanf("%lld", &values[i]);
}

void alloc_space(long long **values, int amount_of_values)
{
    if (amount_of_values > 0)
    {
        *values = (long long *) malloc(amount_of_values * sizeof(long long));

        if (*values == NULL)
        {
            printf("Failed to alloc space.\n");
            exit(1);
        }
    }
}



void merge_sort(long long *array, int array_length)
{
    if (array_length <= 0)
        return;

    _merge_sort(array, 0, array_length - 1);
}

void _merge_sort(long long *array, int first_position, int final_position)
{
    if (first_position == final_position)
        return;
    int middle_position = first_position + (final_position - first_position) / 2;
    _merge_sort(array, first_position, middle_position);
    _merge_sort(array, middle_position + 1, final_position);

    merge_the_two_sections_of_the_array(array, first_position, middle_position, final_position);
    return;
}

void merge_the_two_sections_of_the_array(long long *array, int first_position, int middle_position, int final_position)
{
    int pos_first_array_half = first_position;
    int pos_second_array_half = middle_position + 1;
    int auxiliar_array_length = final_position - first_position + 1;
    long long auxiliar_array[auxiliar_array_length];
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

void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(long long *first_array, int starting_position_in_first_array, long long *second_array, int second_array_length)
{
    for (int current_position = 0; current_position < second_array_length; ++current_position)
        first_array[starting_position_in_first_array + current_position] = second_array[current_position];
}
