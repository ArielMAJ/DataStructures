#include <stdio.h>
#include <stdlib.h>


int get_int();
int *create_heap_int_array(int array_length);
void populate_int_array_with_stdin(int *array, int array_length);
int *get_int_array(int array_length);
int **create_heap_int_matrix(int lines, int columns);
void print_matrix(int **matrix, int l, int c);
void free_heap_int_matrix(int **matrix, int lines);

int max(int m, int n);
int min(int m, int n);
int max_3(int a, int b, int c);

int longest_common_subsequence_length(int *first_sequence, int first_sequence_length, int *second_sequence, int second_sequence_length);

int main(void)
{
    int first_sequence_length = get_int();
    int *first_sequence = get_int_array(first_sequence_length);

    int second_sequence_length = get_int();
    int *second_sequence = get_int_array(second_sequence_length);

    printf("%d\n", longest_common_subsequence_length(first_sequence, first_sequence_length, second_sequence, second_sequence_length));

    free(first_sequence);
    free(second_sequence);
    return 0;
}

int longest_common_subsequence_length(int *first_sequence, int first_sequence_length, int *second_sequence, int second_sequence_length)
{
    int lines = first_sequence_length + 1;
    int columns = second_sequence_length + 1;
    int **dist = create_heap_int_matrix(lines, columns);

    for (int i = 0; i < lines; ++i)
        dist[i][0] = 0;
    for (int i = 0; i < columns; ++i)
        dist[0][i] = 0;
    for (int j = 1; j < columns; ++j)
    {
        for (int i = 1; i < lines; ++i)
        {
            int insertion = dist[i][j - 1];
            int deletion = dist[i - 1][j] ;
            int match = dist[i - 1][j - 1] + 1;
            int mismatch = dist[i - 1][j - 1];
            if (first_sequence[i - 1] == second_sequence[j - 1])
                dist[i][j] = max_3(insertion, deletion, match);
            else
                dist[i][j] = max_3(insertion, deletion, mismatch);
        }
    }
    // print_matrix(dist, lines, columns);

    int result = dist[first_sequence_length][second_sequence_length];

    free_heap_int_matrix(dist, lines);
    return result;
}

int max(int m, int n)
{
    return m > n ? m : n;
}

int min(int m, int n)
{
    return m < n ? m : n;
}

int max_3(int a, int b, int c)
{
    return max(max(a, b), c);
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
        mat[i] = (int *) malloc(columns * sizeof(int));

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
