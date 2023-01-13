#include <stdio.h>
#include <stdlib.h>

void read_from_stdin(int *value);
void populate_array(int *values, int amount_of_values);
void alloc_space(int **values, int amount_of_values);
void pseudo_remove_front(int **array, int *array_size);

int compute_min_refills(int location, int *stops, int amout_of_stops, int miles_on_a_full_tank, int distance_between_cities);

int main()
{
    int distance_between_cities;
    read_from_stdin(&distance_between_cities);

    int miles_on_a_full_tank;
    read_from_stdin(&miles_on_a_full_tank);

    int amout_of_stops;
    read_from_stdin(&amout_of_stops);

    int *stops = NULL;
    alloc_space(&stops, amout_of_stops);
    populate_array(stops, amout_of_stops);

    int min_refills = compute_min_refills(0, stops, amout_of_stops, miles_on_a_full_tank, distance_between_cities);

    printf("%d\n", min_refills);

    if (stops != NULL)
        free(stops);
    return 0;
}


int compute_min_refills(int location, int *stops, int amout_of_stops, int miles_on_a_full_tank, int distance_between_cities)
{
    if (location + miles_on_a_full_tank >= distance_between_cities)
        return 0;
    if ((amout_of_stops == 0) || ((stops[0] - location) > miles_on_a_full_tank))
        return -1;

    int last_stop = location;
    while (amout_of_stops > 0 && ((stops[0] - location) <= miles_on_a_full_tank))
    {
        last_stop = stops[0];
        pseudo_remove_front(&stops, &amout_of_stops);
    }

    int additional_stops = compute_min_refills(last_stop, stops, amout_of_stops, miles_on_a_full_tank, distance_between_cities);
    if (additional_stops >= 0)
        return 1 + additional_stops;
    return -1;
}

void pseudo_remove_front(int **array, int *array_size)
{
    (*array)++;
    (*array_size)--;
}

void read_from_stdin(int *value)
{
    scanf("%d", value);
}

void populate_array(int *values, int amount_of_values)
{
    for (int i = 0; i < amount_of_values; i++)
        read_from_stdin(&values[i]);
}

void alloc_space(int **values, int amount_of_values)
{
    if (amount_of_values > 0)
    {
        *values = (int *) malloc(amount_of_values * sizeof(int));

        if (*values == NULL)
        {
            printf("Failed to alloc space.\n");
            exit(1);
        }
    }
}
