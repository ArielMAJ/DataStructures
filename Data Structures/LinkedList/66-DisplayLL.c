// Display a Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int A[], int n);
void Display(Node *p);
void RDisplay(Node *p);

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *first = create(A, 8);

    Display(first);
    RDisplay(first);

    return 0;
}


Node *create(int A[], int n)
{
    int i;
    Node *t, *last;
    Node *first = (Node *) malloc(sizeof(Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (Node *) malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}

void Display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void RDisplay(Node *p)
{
    if (p)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
        return;
    }
}
