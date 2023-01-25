#include <stdio.h>
#include <stdlib.h>

int get_array_size_from_stdin();
int *get_array_from_stdin();

int get_number_of_inversions(int *array, int array_length);
int _get_number_of_inversions(int *array, int first_position, int final_position);
int merge_the_two_sections_of_the_array(int *array, int first_position, int middle_position, int final_position);
void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(int *first_array, int starting_position_in_first_array, int *second_array, int second_array_length);
int values_left_in_at_least_one_of_the_array_sections(int pos_first_array_half, int middle_position, int pos_second_array_half, int final_position);

int main()
{
    int array_length = get_array_size_from_stdin();
    int *array = get_array_from_stdin(array_length);

    int inversions = get_number_of_inversions(array, array_length);

    printf("%d\n", inversions);

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

int get_number_of_inversions(int *array, int array_length)
{
    if (array_length <= 0)
        return 0;

    return _get_number_of_inversions(array, 0, array_length - 1);
}

int _get_number_of_inversions(int *array, int first_position, int final_position)
{
    if (first_position >= final_position)
        return 0;

    int middle_position = first_position + (final_position - first_position) / 2;

    int inversions_on_the_left = _get_number_of_inversions(array, first_position, middle_position);
    int inversions_on_the_right = _get_number_of_inversions(array, middle_position + 1, final_position);

    int inversions_when_merging_arrays = merge_the_two_sections_of_the_array(array, first_position, middle_position, final_position);
    return inversions_on_the_left + inversions_when_merging_arrays + inversions_on_the_right;
}

int merge_the_two_sections_of_the_array(int *array, int first_position, int middle_position, int final_position)
{
    int pos_first_array_half = first_position;
    int pos_second_array_half = middle_position + 1;
    int auxiliar_array_length = final_position - first_position + 1;
    int auxiliar_array[auxiliar_array_length];
    int aux_pos = 0;
    int inversions_when_merging_arrays = 0;


    while (values_left_in_at_least_one_of_the_array_sections(pos_first_array_half, middle_position, pos_second_array_half, final_position))
    {
        if (pos_first_array_half <= middle_position)
        {
            if (array[pos_first_array_half] <= array[pos_second_array_half] || pos_second_array_half > final_position)
            {
                auxiliar_array[aux_pos++] = array[pos_first_array_half++];
            }
            else
            {
                auxiliar_array[aux_pos++] = array[pos_second_array_half++];
                inversions_when_merging_arrays += (middle_position + 1) - pos_first_array_half;
            }
        }
        else
            auxiliar_array[aux_pos++] = array[pos_second_array_half++];
    }
    copy_second_array_to_the_first_one_in_a_given_section_of_first_array(array, first_position, auxiliar_array, auxiliar_array_length);

    return inversions_when_merging_arrays;
}

int values_left_in_at_least_one_of_the_array_sections(int pos_first_array_half, int middle_position, int pos_second_array_half, int final_position)
{
    return pos_first_array_half <= middle_position || pos_second_array_half <= final_position;
}

void copy_second_array_to_the_first_one_in_a_given_section_of_first_array(int *first_array, int starting_position_in_first_array, int *second_array, int second_array_length)
{
    first_array += starting_position_in_first_array;
    for (int i = 0; i < second_array_length; ++i)
        *(first_array++) = *(second_array++);
}
