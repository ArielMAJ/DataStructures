#include <stdio.h>
#include <stdlib.h>

double get_optimal_value(double capacity, int *weights, int *values, int amount_of_items);
int max_index(int *values, int *weights, int amount_of_items);
int min_value(int a, int b);
void remove_element(int elem_idx, int *weights, int *values, int amount_of_items);
void alloc_space(int **values, int **weights, int n);
void populate_arrays(int *values, int *weights, int *n);

int main()
{
    int n, capacity;
    scanf("%d %d", &n, &capacity);

    int *values = NULL;
    int *weights = NULL;
    alloc_space(&values, &weights, n);
    populate_arrays(values, weights, &n);

    double optimal_value = get_optimal_value((double) capacity, weights, values, n);

    printf("%.4lf\n", optimal_value);

    if (values != NULL)
        free(values);
    if (weights != NULL)
        free(weights);
    return 0;
}
void populate_arrays(int *values, int *weights, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        scanf("%d %d", &values[i], &weights[i]);
        if (values[i] == 0 || weights[i] <= 0)
        {
            i--;
            (*n)--;
        }
    }
}

double get_optimal_value(double capacity, int *weights, int *values, int amount_of_items)
{
    double value = 0.0;
    if (capacity <= 0.001 || weights == NULL || values == NULL || amount_of_items <= 0)
        return 0.0;
    int max_idx = max_index(values, weights, amount_of_items);
    double amount = min_value(weights[max_idx], capacity);
    value = 1.0 * values[max_idx] * amount / weights[max_idx];
    remove_element(max_idx, weights, values, amount_of_items);
    return value + get_optimal_value(capacity - amount, weights, values, amount_of_items - 1);
}

int max_index(int *values, int *weights, int amount_of_items)
{
    int max_idx = 0;
    for (int i = 1; i < amount_of_items; ++i)
    {
        if (1.0 * values[i] / weights[i] > 1.0 * values[max_idx] / weights[max_idx])
            max_idx = i;
    }
    return max_idx;
}

void remove_element(int elem_idx, int *weights, int *values, int amount_of_items)
{
    for (int i = elem_idx; i < amount_of_items - 1; ++i)
    {
        weights[i] = weights[i + 1];
        values[i] = values[i + 1];
    }
}

int min_value(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void alloc_space(int **values, int **weights, int n)
{
    if (n > 0)
    {
        *values = (int *) malloc(n * sizeof(int));
        *weights = (int *) malloc(n * sizeof(int));

        if (*values == NULL)
        {
            printf("Failed to alloc values' space.\n");
            exit(1);
        }
        if (*weights == NULL)
        {
            printf("Failed to alloc weights' space.\n");
            exit(2);
        }
    }
}
