#include <stdio.h>
#include <stdlib.h>

long long int get_fibbonaci_position_to_calculate();
int calculate_fib_part_sum_huge(long long int fib_pos_start, long long int fib_pos_end);

int main()
{
    long long int fib_pos_start = get_fibbonaci_position_to_calculate();
    long long int fib_pos_end = get_fibbonaci_position_to_calculate();
    int result = calculate_fib_part_sum_huge(fib_pos_start, fib_pos_end);

    printf("%d\n", result);

    return 0;
}

long long int get_fibbonaci_position_to_calculate()
{
    double fib_pos_double = 0;
    scanf("%lf", &fib_pos_double);
    long long int fib_pos = (long long int) fib_pos_double;
    if (fib_pos < 0)
    {
        printf("Only numbers equal or above zero are accepted.\n");
        exit(1);
    }

    return fib_pos;
}

int calculate_fib_part_sum_huge(long long int fib_pos_start, long long int fib_pos_end)
{
    int pisano_period_10 = 60;
    int pisano_list[60] =
    {
        0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1,
    };

    int pisano_start = fib_pos_start % pisano_period_10;
    int pisano_end = fib_pos_end % pisano_period_10;

    int sum = 0;
    if (pisano_start < pisano_end)
        for (int i = pisano_start; i <= pisano_end; ++i)
            sum += pisano_list[i];
    else
    {
        for (int i = pisano_start; i < 60; ++i)
            sum += pisano_list[i];
        for (int i = 0; i <= pisano_end; ++i)
            sum += pisano_list[i];
    }

    return sum % 10;
}
