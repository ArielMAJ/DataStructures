#include <stdio.h>

void read_input_from_stdin(int *first_value, int *second_value);
int euclidean_greatest_common_divisor(int first_value, int second_value);

int main()
{
    int first_value, second_value;
    read_input_from_stdin(&first_value, &second_value);

    int result = euclidean_greatest_common_divisor(first_value, second_value);
    printf("%d\n", result);

    return 0;
}

void read_input_from_stdin(int *first_value, int *second_value)
{
    scanf("%d %d", first_value, second_value);
}


int euclidean_greatest_common_divisor(int first_value, int second_value)
{
    if (second_value==0)
        return first_value;

    int remainder_of_first_value_divided_by_second_value = first_value % second_value;

    return euclidean_greatest_common_divisor(second_value, remainder_of_first_value_divided_by_second_value);
}