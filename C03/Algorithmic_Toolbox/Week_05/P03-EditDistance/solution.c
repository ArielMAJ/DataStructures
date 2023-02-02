#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT_LENGTH 100

char *read_string();
int min_3(int, int, int);
int **heap_int_matrix(int lines, int columns);
void print_matrix(int **matrix, int l, int c);
void free_heap_int_matrix(int **matrix, int lines);

int edit_distance(char *str1, char *str2);

int main(void)
{
    char *word_01 = read_string();
    char *word_02 = read_string();

    printf("%d\n", edit_distance(word_01, word_02));

    free(word_01);
    free(word_02);
    return 0;
}

int edit_distance(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    int lines = len_str1 + 1;
    int columns = len_str2 + 1;

    int **dist = heap_int_matrix(lines, columns);

    for (int i = 0; i < lines; ++i)
        dist[i][0] = i;
    for (int i = 0; i < columns; ++i)
        dist[0][i] = i;
    for (int j = 1; j < columns; ++j)
    {
        for (int i = 1; i < lines; ++i)
        {
            int insertion = dist[i][j - 1] + 1;
            int deletion = dist[i - 1][j] + 1;
            int match = dist[i - 1][j - 1];
            int mismatch = dist[i - 1][j - 1] + 1;
            if (str1[i - 1] == str2[j - 1])
                dist[i][j] = min_3(insertion, deletion, match);
            else
                dist[i][j] = min_3(insertion, deletion, mismatch);
        }
    }

    int result = dist[len_str1][len_str2];

    free_heap_int_matrix(dist, lines);
    return result;
}

char *read_string()
{
    char *str = (char *) malloc((MAX_INPUT_LENGTH + 1) * sizeof(char));
    fgets(str, MAX_INPUT_LENGTH + 1, stdin);

    int len_str = strlen(str);

    if (len_str == MAX_INPUT_LENGTH && str[len_str - 1] != '\r' && str[len_str - 1] != '\n')
    {
        char tmp;
        while ((tmp = getchar()) != '\n' && tmp != '\r' && tmp != EOF) {}
    }
    while (str[--len_str] == '\n' || str[len_str] == '\r')
        str[len_str] = '\0';

    return str;
}

int min_3(int a, int b, int c)
{
    int min(int m, int n)
    {
        return m < n ? m : n;
    }

    return min(min(a, b), c);
}

int **heap_int_matrix(int lines, int columns)
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
