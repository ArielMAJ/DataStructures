#include <stdio.h>
#include <stdlib.h>

int get_int();
int *create_heap_int_array(int array_length);
void populate_int_array_with_stdin(int *array, int array_length);
int *get_int_array(int array_length);
int sum_array(int *array, int array_length);

int partition3(int *loot_values_array, int amount_of_loot);
int _partition3(int *loot_values_array, int amount_of_loot, int w__backpack_max_weight);

int main(void)
{
    int amount_of_loot = get_int();
    int *loot_values_array = get_int_array(amount_of_loot);

    int result = partition3(loot_values_array, amount_of_loot);

    printf("%d\n", result);

    free(loot_values_array);
    return 0;
}

int partition3(int *loot_values_array, int amount_of_loot)
{
    if (amount_of_loot < 3)
        return 0;

    int total_loot_value = sum_array(loot_values_array, amount_of_loot);

    if (total_loot_value % 3 != 0)
        return 0;

    int w__backpack_max_weight = total_loot_value / 3;

    return _partition3(loot_values_array, amount_of_loot, w__backpack_max_weight);
}

int _partition3(int *loot_values_array, int amount_of_loot, int w__backpack_max_weight)
{
    int __partition3(int *loot_values_array, int amount_of_loot, int w__backpack_max_weight, int backpack_curr_weight, int *taken, int max_index, int backpack_count)
    {
        if (backpack_curr_weight == w__backpack_max_weight)
        {
            if (backpack_count == 2)
                return 1;
            return __partition3(loot_values_array, amount_of_loot, w__backpack_max_weight, 0, taken, amount_of_loot - 1, backpack_count + 1);
        }

        for (int i = max_index; i >= 0; i--)
        {
            if (taken[i])
                continue;
            int tmp = backpack_curr_weight + loot_values_array[i];

            if (tmp <= w__backpack_max_weight)
            {
                taken[i] = 1;
                backpack_curr_weight += loot_values_array[i];
                
                int is_possible_to_partition = __partition3(loot_values_array, amount_of_loot, w__backpack_max_weight, backpack_curr_weight, taken, i - 1, backpack_count);
                if (is_possible_to_partition)
                    return is_possible_to_partition;

                taken[i] = 0;
                backpack_curr_weight -= loot_values_array[i];
            }
        }
        return 0;
    }

    int *taken = (int *) calloc(amount_of_loot, sizeof(int));
    int result = __partition3(loot_values_array, amount_of_loot, w__backpack_max_weight, 0, taken, amount_of_loot - 1, 1);
    free(taken);
    return result;
}

int sum_array(int *array, int array_length)
{
    int sum = 0;
    while (array_length-- > 0)
        sum += *(array++);
    return sum;
}

int get_int()
{
    int value;
    scanf("%d", &value);

    return value;
}

int *create_heap_int_array(int array_length)
{
    return (int *) malloc(array_length * sizeof(int));
}

void populate_int_array_with_stdin(int *array, int array_length)
{
    for (int i = 0; i < array_length; ++i)
        scanf("%d", array++);
}

int *get_int_array(int array_length)
{
    int *array = create_heap_int_array(array_length);
    populate_int_array_with_stdin(array, array_length);

    return array;
}
