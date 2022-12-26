// This solution is O(n^2) as it uses the "find_max" function (which is O(n)) n times.
// It could be O(nlogn) by using an efficient (reverse) sorting algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_input_from_stdin();
int *process_input(char *stdin_input);
int *find_max_position(int *position_in_array);
char *largest_concatenate(int *numbers_array);
void move_following_values_one_position_back_effectively_removing_the_current_character(int *position_in_array);
// void pop_value_from_string(char * position_in_string, char value);
// char * find_value_position_in_string(char * position_in_string, char value);

int main()
{
    char *stdin_input = get_input_from_stdin();
    int *array = process_input(stdin_input);
    char *result = largest_concatenate(array);
    printf("%s\n", result);

    free(stdin_input);
    free(result);
    return 0;
}

char *get_input_from_stdin()
{
    char *stdin_input = (char *) malloc(200 * sizeof(char));
    fgets(stdin_input, 200, stdin);

    return stdin_input;
}

int *process_input(char *stdin_input)
{
    char *current_number = stdin_input;
    char *end_of_number = stdin_input;
    int *array = (int *) malloc(200 * sizeof(int));
    int pos = 0;
    while (*end_of_number != '\0')
    {
        if (*end_of_number == ' ')
        {
            *end_of_number = '\0';
            array[pos++] = atoi(current_number);
            current_number = end_of_number + 1;
        }
        end_of_number++;
    }
    array[pos++] = atoi(current_number);
    array[pos] = -1;

    return array;
}

char *largest_concatenate(int *numbers_array)
{
    char *result = (char *) malloc(200 * sizeof(char));
    result[0] = '\0';

    int pos = 0;
    while (numbers_array[pos] != -1)
    {
        int *max_position = find_max_position(numbers_array);
        char buffer[100];
        buffer[0] = '\0';
        sprintf(buffer, "%d", *max_position);
        strcat(result, buffer);
        move_following_values_one_position_back_effectively_removing_the_current_character(max_position);
    }

    return result;
}

void move_following_values_one_position_back_effectively_removing_the_current_character(int *position_in_array)
{
    while (*position_in_array != -1)
    {
        *position_in_array = *(position_in_array + 1);
        position_in_array++;
    }
}

int *find_max_position(int *position_in_array)
{
    int *max_position = position_in_array;
    while (*(++position_in_array) != -1)
    {
        if (*position_in_array > *max_position)
            max_position = position_in_array;
    }
    return max_position;
}

// void pop_value_from_string(char * position_in_string, char value)
// {
//     position_in_string = find_value_position_in_string(position_in_string, value);
//     move_following_values_one_position_back_effectively_removing_the_current_character(position_in_string);
// }

// char * find_value_position_in_string(char * position_in_string, char value)
// {
//     while (*position_in_string != value)
//         position_in_string++;
//     return position_in_string;
// }
