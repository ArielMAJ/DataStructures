#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string_from_stdin();
void process_input(char *current_character);
char *find_max_position(char *position_in_string);
char *largest_concatenate(char *numbers);
void move_following_values_one_position_back_effectively_removing_the_current_character(char *position_in_string);

int main()
{
    char *stdin_input = get_string_from_stdin();
    process_input(stdin_input);
    char *result = largest_concatenate(stdin_input);
    printf("%s\n", result);

    free(stdin_input);
    free(result);
    return 0;
}

char *get_string_from_stdin()
{
    char *stdin_input = (char *) malloc(200 * sizeof(char));
    fgets(stdin_input, 200, stdin);

    return stdin_input;
}

void process_input(char *current_character)
{
    while (*current_character != '\0')
    {
        if (*current_character == ' ')
            move_following_values_one_position_back_effectively_removing_the_current_character(current_character);
        current_character++;
    }
}

char *largest_concatenate(char *numbers)
{
    int str_len = strlen(numbers);
    char *result = (char *) malloc((str_len + 1) * sizeof(char));
    int pos = 0;
    while (str_len-- != 0)
    {
        char *max_position = find_max_position(numbers);
        result[pos++] = *max_position;
        move_following_values_one_position_back_effectively_removing_the_current_character(max_position);
    }
    result[pos] = '\0';

    return result;
}

void move_following_values_one_position_back_effectively_removing_the_current_character(char *position_in_string)
{
    while (*position_in_string != '\0')
    {
        *position_in_string = *(position_in_string + 1);
        position_in_string++;
    }
}

char *find_max_position(char *position_in_string)
{
    char *max_position = position_in_string;
    while (*(++position_in_string) != '\0')
    {
        if (*position_in_string > *max_position)
            max_position = position_in_string;
    }
    return max_position;
}
