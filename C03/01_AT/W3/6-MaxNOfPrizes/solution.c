#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LList
{
    int length;
    Node *head;
} LList;

int read_int_from_stdin();

Node *new_node(int value);
LList *new_linked_list();
void print_linked_list(LList *list);
void free_linked_list(LList *list);

LList *optimal_summands(int input_integer);

int main()
{
    int input_integer = read_int_from_stdin();

    LList *summands = optimal_summands(input_integer);

    printf("%d\n", summands->length);
    print_linked_list(summands);


    if (summands != NULL)
        free_linked_list(summands);
    return 0;
}

LList *optimal_summands(int input_integer)
{
    LList *summands = new_linked_list();
    Node *aux = new_node(0);
    summands->head = aux;

    int current_summand = 1;

    while (input_integer > 0)
    {
        if (input_integer - current_summand > current_summand)
        {
            input_integer -= current_summand;
            aux->next = new_node(current_summand);
            current_summand++;
        }
        else
        {
            current_summand = input_integer;
            aux->next = new_node(current_summand);
            input_integer = 0;
        }
        aux = aux->next;

        summands->length++;
    }
    aux = summands->head;
    summands->head = summands->head->next;
    free(aux);

    return summands;
}

int read_int_from_stdin()
{
    int value;
    scanf("%d", &value);

    return value;
}

LList *new_linked_list()
{
    LList *list = (LList *) malloc(sizeof(LList));
    list->head = NULL;
    list->length = 0;

    return list;
}

Node *new_node(int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void print_linked_list(LList *list)
{
    Node *aux = list->head;
    while (aux != NULL)
    {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void free_linked_list(LList *list)
{
    if (list == NULL)
        return;
    if (list->head == NULL)
    {
        free(list);
        return;
    }
    if (list->head->next == NULL)
    {
        free(list->head);
        free(list);
        return;
    }

    Node *aux = list->head->next;
    Node *aux_prev = list->head;

    while (aux != NULL)
    {
        free(aux_prev);
        aux_prev = aux;
        aux = aux->next;
    }
    free(aux_prev);
    free(list);
}