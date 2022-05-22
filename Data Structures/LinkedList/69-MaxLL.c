// Max element from Linked List

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int *, int );
int Max(Node *);
int RMax(Node *);

int main()
{

    int A[] = {1, 2, 3, 10, 4, 5, 6, 7, 8};
    Node *first = create(A, 8);

    printf("Max %d==%d\n", Max(first), RMax(first));

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

int Max(Node *p)
{
    int max = p->data;
    p = p->next;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;

}

int RMax(Node *p)
{
    int x;

    if (!p->next)
        return p->data;

    x = RMax(p->next);

    if (x > p->data)
        return x;
    else
        return p->data;
}