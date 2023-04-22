#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bracket
{
    int (*match_bracket)(struct Bracket *, char);
    char type;
    int position;
} Bracket;

typedef struct BracketNode
{
    Bracket *bracket;
    struct BracketNode *next;
} BracketNode;

typedef struct BracketStack
{
    void (*push_bracket)(struct BracketStack *, Bracket *);
    Bracket *(*pop_bracket)(struct BracketStack *);
    Bracket *(*top_bracket)(struct BracketStack *);
    int (*isEmptyBracketStack)(struct BracketStack *);
    BracketNode *_top_node;
} BracketStack;

int match_bracket(Bracket *this, char match);
Bracket *New_Bracket(char type, int position);
void push_bracket(BracketStack *this, Bracket *bracket);
Bracket *pop_bracket(BracketStack *this);
Bracket *top_bracket(BracketStack *this);
int isEmptyBracketStack(BracketStack *this);
BracketStack *New_BracketStack();
char *read_string_input();
void free_bracket_stack(BracketStack *this);

int main(void)
{
    char *text = read_string_input();
    int text_length = strlen(text);

    BracketStack *opening_brackets_stack = New_BracketStack();
    for (int position = 0; position < text_length; ++position)
    {
        char curr_char = text[position];
        if (curr_char == '(' || curr_char == '[' || curr_char == '{')
        {
            opening_brackets_stack->push_bracket(opening_brackets_stack, New_Bracket(curr_char, position));
        }
        else if (curr_char == ')' || curr_char == ']' || curr_char == '}')
        {
            Bracket *bracket = opening_brackets_stack->pop_bracket(opening_brackets_stack);
            if (bracket == NULL || !bracket->match_bracket(bracket, curr_char))
            {
                printf("%d", position + 1);
                free(bracket);
                free_bracket_stack(opening_brackets_stack);
                free(text);
                return 0;
            }
            free(bracket);
        }
    }

    if (isEmptyBracketStack(opening_brackets_stack))
        printf("Success");
    else
        printf("%d", top_bracket(opening_brackets_stack)->position + 1);

    free_bracket_stack(opening_brackets_stack);
    free(text);
    return 0;
}

void free_bracket_stack(BracketStack *this)
{
    while (!this->isEmptyBracketStack(this))
    {
        Bracket *bracket = this->pop_bracket(this);
        free(bracket);
    }
    free(this);
}

int match_bracket(Bracket *this, char match)
{
    if (this->type == '(' && match == ')')
        return 1;
    if (this->type == '[' && match == ']')
        return 1;
    if (this->type == '{' && match == '}')
        return 1;
    return 0;
}

Bracket *New_Bracket(char type, int position)
{
    Bracket *this = (Bracket *)malloc(sizeof(struct Bracket));
    this->type = type;
    this->position = position;
    this->match_bracket = match_bracket;
    return this;
}

void push_bracket(BracketStack *this, Bracket *bracket)
{
    BracketNode *node = (BracketNode *)malloc(sizeof(BracketNode));
    node->bracket = bracket;
    node->next = this->_top_node;
    this->_top_node = node;
}

Bracket *pop_bracket(BracketStack *this)
{
    if (this->_top_node == NULL)
        return NULL;
    Bracket *bracket = this->_top_node->bracket;
    BracketNode *node = this->_top_node;
    this->_top_node = this->_top_node->next;
    free(node);
    return bracket;
}

Bracket *top_bracket(BracketStack *this)
{
    if (this->_top_node == NULL)
        return NULL;
    return this->_top_node->bracket;
}

int isEmptyBracketStack(BracketStack *this)
{
    return this->_top_node == NULL;
}

BracketStack *New_BracketStack()
{
    BracketStack *this = (BracketStack *)malloc(sizeof(struct BracketStack));
    this->_top_node = NULL;
    this->push_bracket = push_bracket;
    this->pop_bracket = pop_bracket;
    this->top_bracket = top_bracket;
    this->isEmptyBracketStack = isEmptyBracketStack;
    return this;
}

char *read_string_input()
{
#define CHUNK 128
    char *input = NULL;
    char buffer[CHUNK];
    size_t inputlen = 0, buffer_len = 0;
    do
    {
        fgets(buffer, CHUNK, stdin);
        buffer_len = strlen(buffer);
        input = realloc(input, inputlen + buffer_len + 1);
        strcpy(input + inputlen, buffer);
        inputlen += buffer_len;
    } while (buffer_len == CHUNK - 1 && buffer[CHUNK - 2] != '\n');
    return input;
}
