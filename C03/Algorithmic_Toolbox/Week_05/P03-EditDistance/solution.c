#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100


char *read_string();

// int edit_distance(char *str1, char *str2);

int main(void)
{
    char *word_01 = read_string();
    char *word_02 = read_string();

    printf("%s\n", word_01);
    printf("%s\n", word_02);

    free(word_01);
    free(word_02);
    return 0;
}

// int edit_distance(char *str1, char *str2)
// {
//     return 0;
// }

char *read_string()
{
    char *str = (char *) malloc((MAX_INPUT_LENGTH + 1) * sizeof(char));
    fgets(str, MAX_INPUT_LENGTH + 1, stdin);

    int len_str = strlen(str);
    if (len_str == MAX_INPUT_LENGTH)
    {
        char tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF) {}
    }
    else if (str[len_str - 1] == '\n')
        str[len_str - 1] = '\0';

    return str;
}
