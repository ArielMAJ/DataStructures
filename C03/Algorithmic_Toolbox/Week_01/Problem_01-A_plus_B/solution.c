#include <stdio.h>
#include <stdlib.h>

int *read_values_A_and_B_from_stdin_and_return_them_in_an_array();
int sum_of_A_and_B(int first_value_A, int second_value_B);

int main(void)
{
    int *A_and_B = read_values_A_and_B_from_stdin_and_return_them_in_an_array();
    int result = sum_of_A_and_B(A_and_B[0], A_and_B[1]);

    printf("%d\n", result);

    free(A_and_B);
    return 0;
}

int *read_values_A_and_B_from_stdin_and_return_them_in_an_array()
{
    int first_value_A;
    int second_value_B;
    scanf("%d %d", &first_value_A, &second_value_B);

    int *return_values_A_and_B = (int *) malloc(2 * sizeof(int));
    return_values_A_and_B[0] = first_value_A;
    return_values_A_and_B[1] = second_value_B;
    return return_values_A_and_B;
}

int sum_of_A_and_B(int first_value_A, int second_value_B)
{
    return first_value_A + second_value_B;
}