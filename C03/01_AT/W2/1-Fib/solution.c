#include <stdio.h>
#include <stdlib.h>

int get_fibbonaci_position_to_calculate();
long long int calculate_fib_number(int fib_number);

int main()
{
    int fib_number = get_fibbonaci_position_to_calculate();
    long long int result = calculate_fib_number(fib_number);

    printf("%lld\n", result);

    return 0;
}


int get_fibbonaci_position_to_calculate()
{
    int fib_number = 0;
    scanf("%d", &fib_number);

    if (fib_number < 0)
    {
        printf("Only numbers equal or above zero are accepted.\n");
        exit(1);
    }
    if (fib_number > 55)
    {
        printf("Numbers above 55 will take too long. Halting program.\n");
        exit(55);
    }

    return fib_number;
}

long long int calculate_fib_number(int fib_number)
{
    static long long int *fib_numbers = NULL;
    if (!fib_numbers)
    {
        fib_numbers = (long long int *) calloc(56, sizeof(long long int));
        fib_numbers[0] = 0;
        fib_numbers[1] = 1;
    }

    if (fib_numbers[fib_number] != 0 || fib_number == 0)
        return fib_numbers[fib_number];

    int pos;
    for (pos = fib_number - 1; pos > 1; --pos)
    {
        if (fib_numbers[pos])
            break;
    }
    pos++;

    for (; pos <= fib_number; ++pos)
        fib_numbers[pos] = fib_numbers[pos - 1] + fib_numbers[pos - 2];

    return fib_numbers[fib_number];
}