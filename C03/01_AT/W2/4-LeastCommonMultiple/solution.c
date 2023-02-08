#include <stdio.h>

void read_input_from_stdin(int *first_value, int *second_value);
long long lcm(int a, int b);

int main()
{
    int first_value, second_value;
    read_input_from_stdin(&first_value, &second_value);

    long long result = lcm(first_value, second_value);
    printf("%lld\n", result);

    return 0;
}

void read_input_from_stdin(int *first_value, int *second_value)
{
    scanf("%d %d", first_value, second_value);
}


long long lcm(int a, int b)
{
    int largest, smallest;
    if (a > b)
    {
        largest = a;
        smallest = b;
    }
    else
    {
        largest = b;
        smallest = a;
    }
    for (long long cur_value = 0; cur_value < (long long) a * b;)
    {
        cur_value += largest;
        if (cur_value % smallest == 0)
            return cur_value;
    }
    return (long long) a * b;
}