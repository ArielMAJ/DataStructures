#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 30

typedef struct MinMax
{
    long long min;
    long long max;
} MinMax;

char *read_string();

long long **create_heap_int_matrix(int lines, int columns);
void free_heap_int_matrix(long long **matrix, int lines);

int count_operations(char *math_expression, int string_len);
char *get_string_of_operations(char *math_expression, int string_len, int amount_of_operations);
long long *get_array_of_numbers_to_operate(char *math_expression, int string_len, int amount_of_operations);

long long calculate(long long a, char operation, long long b);
long long min5(long long a, long long b, long long c, long long d, long long e);
long long max5(long long a, long long b, long long c, long long d, long long e);

long long max_expression_value(long long *numbers, int amount_of_operations, char *operations);

int main(void)
{
    char *math_expression = read_string();
    int string_len = strlen(math_expression);

    int amount_of_operations = count_operations(math_expression, string_len);
    char *operations = get_string_of_operations(math_expression, string_len, amount_of_operations);

    long long *numbers = get_array_of_numbers_to_operate(math_expression, string_len, amount_of_operations);

    printf("%lld\n", max_expression_value(numbers, amount_of_operations, operations));

    free(math_expression);
    free(operations);
    free(numbers);

    return 0;
}

long long max_expression_value(long long *numbers, int amount_of_operations, char *operations)
{
    long long **max_mat = create_heap_int_matrix(amount_of_operations, amount_of_operations);
    long long **min_mat = create_heap_int_matrix(amount_of_operations, amount_of_operations);

    MinMax _MinAndMax(int i, int j, long long *_numbers, char *_operations)
    {
        if (i == j)
        {
            MinMax stop_cond = {_numbers[i], _numbers[j]};
            return stop_cond;
        }

        long long min = LLONG_MAX;
        long long max = LLONG_MIN;

        for (int k = i; k < j; ++k)
        {
            MinMax i_k;
            MinMax kpp_j;
            if (max_mat[i][k] != 0 && min_mat[i][k] != 0 && max_mat[k + 1][j] != 0 && min_mat[k + 1][j] != 0)
            {
                i_k.max = max_mat[i][k];
                i_k.min = min_mat[i][k];
                kpp_j.max = max_mat[k + 1][j];
                kpp_j.min = min_mat[k + 1][j];
            }
            else
            {
                i_k = _MinAndMax(i, k, _numbers, _operations);
                kpp_j = _MinAndMax(k + 1, j, _numbers, _operations);
            }

            long long a = calculate(i_k.max, _operations[k], kpp_j.max);
            long long b = calculate(i_k.max, _operations[k], kpp_j.min);
            long long c = calculate(i_k.min, _operations[k], kpp_j.max);
            long long d = calculate(i_k.min, _operations[k], kpp_j.min);

            min = min5(min, a, b, c, d);
            max = max5(max, a, b, c, d);
        }
        MinMax minmax = {min, max};
        return minmax;
    }

    long long max = _MinAndMax(0, amount_of_operations, numbers, operations).max;
    free_heap_int_matrix(max_mat, amount_of_operations);
    free_heap_int_matrix(min_mat, amount_of_operations);
    return max;
}

long long min5(long long a, long long b, long long c, long long d, long long e)
{
    long long min(long long _a, long long _b)
    {
        if (_a < _b)
            return _a;
        return _b;
    }
    return min(min(min(a, b), min(c, d)), e);
}

long long max5(long long a, long long b, long long c, long long d, long long e)
{
    long long max(long long _a, long long _b)
    {
        if (_a > _b)
            return _a;
        return _b;
    }
    return max(max(max(a, b), max(c, d)), e);
}

long long calculate(long long a, char operation, long long b)
{
    if (operation == '+')
        return a + b;
    if (operation == '-')
        return a - b;
    return a * b;
}

long long *get_array_of_numbers_to_operate(char *math_expression, int string_len, int amount_of_operations)
{
    long long *numbers = (long long *) malloc((amount_of_operations + 1) * sizeof(long long));
    for (int i = string_len - 1; i >= 0 ; --i)
        if (math_expression[i] >= 48)
            numbers[amount_of_operations--] = math_expression[i] - 48;
    return numbers;
}

char *get_string_of_operations(char *math_expression, int string_len, int amount_of_operations)
{
    char *operations = (char *) malloc((amount_of_operations + 1) * sizeof(char));
    operations[amount_of_operations--] = '\0';

    for (int i = string_len - 1; i >= 0; --i)
        if (math_expression[i] < 48)
            operations[amount_of_operations--] = math_expression[i];
    return operations;
}

int count_operations(char *math_expression, int string_len)
{
    int count = 0;

    for (int i = 0; i < string_len; ++i)
        if (math_expression[i] < 48)
            count++;
    return count;
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

long long **create_heap_int_matrix(int lines, int columns)
{
    long long **mat = (long long **) malloc(lines * sizeof(long long *));
    for (int i = 0; i < lines; ++i)
        mat[i] = (long long *) calloc(columns, sizeof(long long));

    return mat;
}

void free_heap_int_matrix(long long **matrix, int lines)
{
    for (int i = 0; i < lines; ++i)
        free(matrix[i]);
    free(matrix);
}
