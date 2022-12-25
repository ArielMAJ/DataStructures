#include <stdio.h>
#include <stdlib.h>

int *process_input_from_stdin_and_return_an_int_array(int *array_length);
int *array_from_stdin();
void decide_initial_values(int *array, int *selected_value, int *second_selected_value);
long long int pairwise_product(int first_value, int second_value);
long long int max_pairwise_product(int *array, int array_length, int amount_of_negative_values);
void find_global_max_and_second_max_values(int *array, int values_until_end_of_array, int *max_value, int *second_max_value);
void find_global_min_and_second_min_values(int *array, int values_until_end_of_array, int *min_value, int *second_min_value);
int count_amount_of_non_negative_values(int *array, int values_until_end_of_array);

int main()
{
    int array_length = 0;
    int *array = process_input_from_stdin_and_return_an_int_array(&array_length);
    int amount_of_negative_values = count_amount_of_non_negative_values(array, array_length);

    long long int result = max_pairwise_product(array, array_length, amount_of_negative_values);
    printf("%lld\n", result);

    free(array);
    return 0;
}

int *process_input_from_stdin_and_return_an_int_array(int *array_length)
{
    scanf("%d", array_length);

    if (*array_length < 2)
    {
        printf("Invalid array length. Must be at least 2.\n");
        exit(1);
    }

    return array_from_stdin(*array_length);
}

int *array_from_stdin(int steps_until_the_end_of_the_array)
{
    int *array = (int *) malloc(steps_until_the_end_of_the_array * sizeof(int));

    for (int *arr_pos = array; steps_until_the_end_of_the_array-- > 0; arr_pos++)
        scanf("%d", arr_pos);
    return array;
}

long long int max_pairwise_product(int *array, int array_length, int amount_of_negative_values)
{
    int max_positive_value;
    int second_max_positive_value;
    decide_initial_values(array, &max_positive_value, &second_max_positive_value);

    int min_negative_value = second_max_positive_value;
    int second_min_negative_value = max_positive_value;
    
    if (array_length > 2)
    {
        if (array_length - amount_of_negative_values > 1)
            find_global_max_and_second_max_values(array, array_length, &max_positive_value, &second_max_positive_value);
        if (amount_of_negative_values > 1)
            find_global_min_and_second_min_values(array, array_length, &min_negative_value, &second_min_negative_value);
    }
    
    long long int positive_pairwise_product = pairwise_product(max_positive_value, second_max_positive_value);
    long long int negative_pairwise_product = pairwise_product(min_negative_value, second_min_negative_value);

    if (positive_pairwise_product > negative_pairwise_product)
        return positive_pairwise_product;
    return negative_pairwise_product;
}

void decide_initial_values(int *array, int *selected_value, int *second_selected_value)
{
    if (array[0] > array[1])
    {
        *selected_value = array[0];
        *second_selected_value = array[1];
    }
    else
    {
        *selected_value = array[1];
        *second_selected_value = array[0];
    }

}

long long int pairwise_product(int first_value, int second_value)
{
    return (long long int) first_value * (long long int) second_value;
}

void find_global_max_and_second_max_values(int *array, int values_until_end_of_array, int *max_value, int *second_max_value)
{
    array += 2;
    values_until_end_of_array -= 2;

    while (values_until_end_of_array-- > 0)
    {
        if (*array > *max_value)
        {
            *second_max_value = *max_value;
            *max_value = *array;
        }
        else if (*array > *second_max_value)
            *second_max_value = *array;
        array++;
    }
}

void find_global_min_and_second_min_values(int *array, int values_until_end_of_array, int *min_value, int *second_min_value)
{    
    array += 2;
    values_until_end_of_array -= 2;

    while (values_until_end_of_array-- > 0)
    {
        if (*array < *min_value)
        {
            *second_min_value = *min_value;
            *min_value = *array;
        }
        else if (*array < *second_min_value)
            *second_min_value = *array;
        array++;
    }
}

int count_amount_of_non_negative_values(int *array, int values_until_end_of_array)
{
    int amount_of_negative_values = 0;
    while (values_until_end_of_array-- > 0)
    {
        if (*array < 0)
            amount_of_negative_values++;
        array++;
    }
    return amount_of_negative_values;
}
