#include <stdio.h>
#include <stdlib.h>


int get_int();
int *create_heap_int_array(int array_length);
void populate_int_array_with_stdin(int *array, int array_length);
int *get_int_array(int array_length);
int ***create_heap_int_3D_array(int lines, int columns, int z_layers);
void free_heap_int_3D_array(int ***matrix, int lines, int columns);

int max(int m, int n);
int min(int m, int n);
int max_3(int a, int b, int c);

int longest_common_subseq_of_3_length(int *first_seq, int first_seq_length, int *second_seq, int second_seq_length, int *third_seq, int third_seq_length);

int main(void)
{
    int first_seq_length = get_int();
    int *first_seq = get_int_array(first_seq_length);

    int second_seq_length = get_int();
    int *second_seq = get_int_array(second_seq_length);

    int third_seq_length = get_int();
    int *third_seq = get_int_array(third_seq_length);

    printf("%d\n", longest_common_subseq_of_3_length(first_seq, first_seq_length, second_seq, second_seq_length, third_seq, third_seq_length));

    free(first_seq);
    free(second_seq);
    free(third_seq);
    return 0;
}

int longest_common_subseq_of_3_length(int *first_seq, int first_seq_length, int *second_seq, int second_seq_length, int *third_seq, int third_seq_length)
{
    int lines = first_seq_length + 1;
    int columns = second_seq_length + 1;
    int z_layers = third_seq_length + 1;

    int ***dist = create_heap_int_3D_array(lines, columns, z_layers);

    for (int i = 0; i < lines; ++i)
        for (int j = 0; j < columns; ++j)
            for (int k = 0; k < z_layers; ++k)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dist[i][j][k] = 0;
                    continue;
                }

                int indel_01 = dist[i - 1][j][k];
                int indel_02 = dist[i][j - 1][k];
                int indel_03 = dist[i][j][k - 1];
                int indel_04 = dist[i - 1][j - 1 ][k];
                int indel_05 = dist[i - 1][j][k - 1];
                int indel_06 = dist[i][j - 1][k - 1];
                int mismatch = dist[i - 1][j - 1][k - 1];
                int match = dist[i - 1][j - 1][k - 1] + 1;

                if (first_seq[i - 1] == second_seq[j - 1] && first_seq[i - 1] == third_seq[k - 1])
                    dist[i][j][k] = match;
                else
                    dist[i][j][k] = max_3(max_3(indel_01, indel_02, indel_03), max_3(indel_04, indel_05, indel_06), mismatch);
            }

    int result = dist[first_seq_length][second_seq_length][third_seq_length];

    free_heap_int_3D_array(dist, lines, columns);
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

int ***create_heap_int_3D_array(int lines, int columns, int z_layers)
{
    int ***mat = (int ***) malloc(lines * sizeof(int **));
    for (int i = 0; i < lines; ++i)
    {
        mat[i] = (int **) malloc(columns * sizeof(int *));
        for (int j = 0; j < columns; ++j)
            mat[i][j] = (int *) malloc(z_layers * sizeof(int));
    }

    return mat;
}

void free_heap_int_3D_array(int ***matrix, int lines, int columns)
{
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
            free(matrix[i][j]);
        free(matrix[i]);
    }
    free(matrix);
}
