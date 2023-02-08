#include <stdio.h>
#include <stdlib.h>


int get_int();

int *create_heap_int_array(int array_length);
void populate_int_array_with_stdin(int *array, int array_length);
int *get_int_array(int array_length);

int **create_heap_int_matrix(int lines, int columns);
void print_matrix(int **matrix, int l, int c);
void free_heap_int_matrix(int **matrix, int lines);


int optimal_weight(int *gold_bar_weights, int n__number_of_gold_bars, int w__backpack_weight);

int main(void)
{
    int w__backpack_weight = get_int();
    int n__number_of_gold_bars = get_int();
    int *gold_bar_weights = get_int_array(n__number_of_gold_bars);

    printf("%d\n", optimal_weight(gold_bar_weights, n__number_of_gold_bars, w__backpack_weight));

    free(gold_bar_weights);
    return 0;
}

int optimal_weight(int *gold_bar_weights, int n__number_of_gold_bars, int w__backpack_weight)
{
    int **values_matrix = create_heap_int_matrix(w__backpack_weight + 1, n__number_of_gold_bars + 1);

    for (int i = 0; i < n__number_of_gold_bars + 1; ++i)
    {
        for (int w = 0; w < w__backpack_weight + 1; ++w)
        {
            if (i == 0 || w == 0)
            {
                values_matrix[w][i] = 0;
                continue;
            }

            values_matrix[w][i] = values_matrix[w][i - 1];

            if (gold_bar_weights[i - 1] <= w)
            {
                int val = values_matrix[w - gold_bar_weights[i - 1]][i - 1] + gold_bar_weights[i - 1];
                if (values_matrix[w][i] < val)
                    values_matrix[w][i] = val;
            }
        }
    }
    int result = values_matrix[w__backpack_weight][n__number_of_gold_bars];

    // print_matrix(values_matrix, w__backpack_weight + 1, n__number_of_gold_bars + 1);
    free_heap_int_matrix(values_matrix, w__backpack_weight + 1);
    return result;
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

int **create_heap_int_matrix(int lines, int columns)
{
    int **mat = (int **) malloc(lines * sizeof(int *));
    for (int i = 0; i < lines; ++i)
        mat[i] = create_heap_int_array(columns);

    return mat;
}

void print_matrix(int **matrix, int l, int c)
{
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < c; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void free_heap_int_matrix(int **matrix, int lines)
{
    for (int i = 0; i < lines; ++i)
        free(matrix[i]);
    free(matrix);
}
