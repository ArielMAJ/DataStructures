#include <stdio.h>
#include <stdlib.h>

long long int get_fibbonaci_position_to_calculate();
int calculate_fib_huge(long long int fib_pos, int mod);
int get_pisano_period(int mod);
int get_mod();

int main()
{
    long long int fib_pos = get_fibbonaci_position_to_calculate();
    int mod = get_mod();
    int result = calculate_fib_huge(fib_pos, mod);

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

int get_pisano_period(int mod)
{
    int prev = 0;
    int curr = 1;
    int res = 0;
    for(int i = 0; i < mod * mod; i++)
    {
        int temp = 0;
        temp = curr;
        curr = (prev + curr) % mod;
        prev = temp;
 
        if (prev == 0 && curr == 1)
        {
            res = i + 1;
            break;
        }
    }
    return res;
}

int calculate_fib_huge(long long int fib_pos, int mod)
{
    int two_values_bfr = 0;
    int one_value_bfr = 1;
    int current_value;
    int pisano = get_pisano_period(mod);
    int equivalent_fib_pos = fib_pos % pisano;

    if (equivalent_fib_pos == 0)
        return two_values_bfr % mod;
    if (equivalent_fib_pos == 1)
        return one_value_bfr % mod;

    long long int pos = 2;
    for (; pos <= equivalent_fib_pos; ++pos)
    {
        current_value = (one_value_bfr + two_values_bfr) % mod;
        two_values_bfr = one_value_bfr;
        one_value_bfr = current_value;
    }

    return current_value;
}