#include <stdio.h>
#include <stdlib.h>

long long get_fibbonaci_position_to_calculate();
int calculate_fib_huge(long long fib_pos, int mod);
int get_mod();

int main()
{
    long long fib_pos = get_fibbonaci_position_to_calculate();
    int mod = get_mod();
    int result = calculate_fib_huge(fib_pos, mod);

    printf("%d\n", result);

    return 0;
}

long long get_fibbonaci_position_to_calculate()
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

int get_mod()
{
    int mod = 1;
    scanf("%d", &mod);

    if (mod < 1)
    {
        printf("Only mods above zero are accepted.\n");
        exit(1);
    }

    return mod;
}

int calculate_fib_huge(long long fib_pos, int mod)
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
        fib_saved_values[pos] = (fib_saved_values[pos - 1] + fib_saved_values[pos - 2]) % mod;

    return fib_saved_values[fib_pos];
}