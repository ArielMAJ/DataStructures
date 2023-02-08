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
    Node *head;
    Node *tail;
} LList;

int *MAJORITY_COUNT;
int HASH_SIZE = 100;

Node *new_node(int value);
LList *new_linked_list();
void free_linked_list(LList *list);

int hash(int value);
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

    MAJORITY_COUNT = NULL;
    return 0;
}

int majority_element(int *array, int array_length)
{
    LList **hash_map = (LList **) malloc(HASH_SIZE * sizeof(LList *));
    for (int i = 0; i < HASH_SIZE; ++i)
        hash_map[i] = new_linked_list();


    for (int i = 0; i < array_length; ++i)
        search_linked_list(hash_map[hash(array[i])], array[i]);

    int theres_a_majority_elem = 0;
    if (*MAJORITY_COUNT > array_length / 2)
        theres_a_majority_elem = 1;

    for (int i = 0; i < HASH_SIZE; ++i)
        free_linked_list(hash_map[i]);
    free(hash_map);
    return theres_a_majority_elem;
}

LList *new_linked_list()
{
    LList *list = (LList *) malloc(sizeof(LList));
    list->head = NULL;
    list->tail = NULL;

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
    if (list->head == NULL)
    {
        list->head = new_node(value);
        list->tail = list->head;
        if (MAJORITY_COUNT == NULL)
            MAJORITY_COUNT = &(list->head->count);
        return;
    }
    Node *aux = list->head;

    while (aux != NULL)
    {
        if (aux->value == value)
        {
            (aux->count)++;
            if (aux->count > *MAJORITY_COUNT)
                MAJORITY_COUNT = &(aux->count);
            return;
        }
        aux = aux->next;
    }
    list->tail->next = new_node(value);
    list->tail = list->tail->next;
}

int hash(int value)
{
    return value % HASH_SIZE;
}
