#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int count;
    struct Node *next;
} Node;

typedef struct LList
{
    int length;
    int majority_cand;
    int *majority_count;
    Node *head;
    Node *tail;
} LList;


Node *new_node(int value);
LList *new_linked_list();
void print_linked_list(LList *list);
void free_linkedF_list(LList *list);

void search_linked_list(LList *list, int value);

int majority_element(int *array, int array_length);

int main()
{
    int array_length;
    scanf("%d", &array_length);

    int array[array_length];
    for (int i = 0; i < array_length; i++)
        scanf("%d", &array[i]);

    printf("%d\n", majority_element(array, array_length));


    return 0;
}

int majority_element(int *array, int array_length)
{
    // LList *hash_map[100];
    LList *list = new_linked_list();

    list->head = new_node(array[0]);
    list->tail = list->head;
    list->majority_cand = array[0];
    list->majority_count= &(list->head->count);

    for (int i = 1; i < array_length; ++i)
        search_linked_list(list, array[i]);
    if (*(list->majority_count) > array_length/2)
        return 1;
    return 0;
}

LList *new_linked_list()
{
    LList *list = (LList *) malloc(sizeof(LList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

Node *new_node(int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->count = 1;
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

void search_linked_list(LList *list, int value)
{

    Node *aux = list->head;

    while (aux != NULL)
    {
        if (aux->value == value)
        {
            (aux->count)++;
            if (aux->value != list->majority_cand && aux->count > *(list->majority_count))
                list->majority_count = &(aux->count);
            return;
        }
        aux = aux->next;
    }
    list->tail->next = new_node(value);
    list->tail = list->tail->next;
}