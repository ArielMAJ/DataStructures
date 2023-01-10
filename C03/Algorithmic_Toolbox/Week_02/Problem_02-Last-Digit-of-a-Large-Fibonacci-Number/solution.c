#include <stdio.h>
#include <stdlib.h>

int get_fibbonaci_position_to_calculate();
int calculate_fib_last_number(int fib_pos);

int main()
{
    int fib_pos = get_fibbonaci_position_to_calculate();
    int result = calculate_fib_last_number(fib_pos);

    printf("%d\n", result);

    return 0;
}


int get_fibbonaci_position_to_calculate()
{
    int fib_pos = 0;
    scanf("%d", &fib_pos);

    if (fib_pos < 0)
    {
        printf("Only numbers equal or above zero are accepted.\n");
        exit(1);
    }

    return fib_pos;
}

int calculate_fib_last_number(int fib_pos)
{
    static int *fib_saved_values = NULL;
    if (!fib_saved_values)
    {
        // This calloc expects that this function will never be called with a
        // fib_pos higher than the first ever call this function receives per
        // time this program in run.
        fib_saved_values = (int *) calloc(fib_pos + 1, sizeof(int));
        fib_saved_values[0] = 0;
        fib_saved_values[1] = 1;
    }

    if (fib_saved_values[fib_pos] != 0 || fib_pos == 0)
        return fib_saved_values[fib_pos];

    int pos;
    for (pos = fib_pos - 1; pos > 1; --pos)
    {
        if (fib_saved_values[pos])
            break;
    }
    pos++;

    for (; pos <= fib_pos; ++pos)
        fib_saved_values[pos] = (fib_saved_values[pos - 1] + fib_saved_values[pos - 2]) % 10;

    return fib_saved_values[fib_pos];
}