// Count and Sum Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node * create(int A[], int n);
int count(Node *p);
int Rcount(Node *p);
int sum(Node *p);
int Rsum(Node *p);


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};

    Node *first = create(A, 8);
    printf("Count %d\n", count(first));
    printf("Sum %d==%d\n", sum(first), 8 * (8 + 1) / 2);

    return 0;
}


Node * create(int A[], int n)
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

int count(Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}

int sum(Node *p)
{
    int s = 0;

    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}
