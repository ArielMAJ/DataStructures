#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode *parent;
    struct TreeNode **children;
    int amount_of_children;
} TreeNode;

typedef struct QueueNode
{
    TreeNode *node;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
    void (*enqueue)(struct Queue *this, TreeNode *node);
    TreeNode *(*dequeue)(struct Queue *this);
} Queue;

// Get input:
void get_nodes_and_root_pos_from_input(TreeNode **nodes, int *amout_of_nodes, int *root_pos);

// Solution:
int max_depth(TreeNode *tree_node);

// Tree methods:
void append_child(TreeNode *this, TreeNode *child);
void setParent(TreeNode *this, TreeNode *parent);
void free_tree(TreeNode *this, int amout_of_nodes);

// Queue methods, for tree traversal:
Queue *new_queue();
void enqueue(Queue *this, TreeNode *node);
TreeNode *dequeue(Queue *this);

int main()
{
    int amout_of_nodes, root_pos;
    TreeNode *nodes;
    get_nodes_and_root_pos_from_input(&nodes, &amout_of_nodes, &root_pos);

    printf("%d\n", max_depth(&nodes[root_pos]));

    free_tree(nodes, amout_of_nodes);
    return 0;
}

// Get input:
void get_nodes_and_root_pos_from_input(TreeNode **nodes, int *amout_of_nodes, int *root_pos)
{
    scanf("%d", amout_of_nodes);
    *nodes = (TreeNode *)calloc(*amout_of_nodes, sizeof(TreeNode));
    for (int child_index = 0; child_index < *amout_of_nodes; child_index++)
    {
        int parent_index;
        scanf("%d", &parent_index);
        if (parent_index >= 0)
            setParent(&(*nodes)[child_index], &(*nodes)[parent_index]);
        else if (parent_index == -1)
            *root_pos = child_index;
        (*nodes)[child_index].key = child_index;
    }
}

// Problem solution:
int max_depth(TreeNode *tree_node)
{
    if (tree_node == NULL)
        return 0;
    Queue *queue = new_queue();
    queue->enqueue(queue, tree_node);
    int depth = 0;
    while (1)
    {
        if (queue->head == NULL)
        {
            free(queue);
            return depth;
        }

        depth++;
        TreeNode *last = queue->tail->node;
        TreeNode *node;
        do
        {
            node = queue->dequeue(queue);
            for (int i = 0; i < node->amount_of_children; i++)
                queue->enqueue(queue, node->children[i]);
        } while (node != last);
    }
}

// Tree methods:
void append_child(TreeNode *this, TreeNode *child)
{
    this->children = (TreeNode **)realloc(this->children, (++(this->amount_of_children)) * sizeof(TreeNode *));
    this->children[this->amount_of_children - 1] = child;
}

void setParent(TreeNode *this, TreeNode *parent)
{
    this->parent = parent;
    append_child(parent, this);
}

void free_tree(TreeNode *this, int amout_of_nodes)
{
    for (int i = 0; i < amout_of_nodes; i++)
        free(this[i].children);
    free(this);
}

// Queue methods, for tree traversal:
Queue *new_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->enqueue = enqueue;
    queue->dequeue = dequeue;
    return queue;
}

void enqueue(Queue *this, TreeNode *node)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->node = node;
    new_node->next = NULL;
    if (this->head == NULL)
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        this->tail->next = new_node;
        this->tail = new_node;
    }
}

TreeNode *dequeue(Queue *this)
{
    if (this->head == NULL)
        return NULL;
    TreeNode *node = this->head->node;
    QueueNode *temp = this->head;
    this->head = this->head->next;
    free(temp);
    return node;
}
