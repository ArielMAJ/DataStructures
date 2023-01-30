#include <stdio.h>
#include <stdlib.h>


typedef struct Vector
{
    int *elements;
    int length;
    int capacity;
    void (*append)(struct Vector *, int);
    void (*print)(struct Vector *);
} Vector;

int get_int();
int *create_heap_int_array(int capacity);

Vector *new_vector();
void increase_vector_capacity(Vector *this);
void append_to_vector(Vector *this, int value);
void print_vector(Vector *this);
void free_vector(Vector *vect);

// Vector *primitive_calculator(int value);

int main(void)
{
    int input_integer = get_int();

    Vector *vect = new_vector();

    for (int i = 0; i < input_integer; ++i)
        vect->append(vect, i);
    vect->print(vect);

    free_vector(vect);
    return 0;
}

// Vector *primitive_calculator(int value)
// {

// }

int get_int()
{
    int value;
    scanf("%d", &value);

    return value;
}

Vector *new_vector()
{
    int capacity = 50;

    Vector *vect = (Vector *) malloc(sizeof(Vector));

    vect->elements = create_heap_int_array(capacity);
    vect->capacity = capacity;
    vect->length = 0;
    vect->append = append_to_vector;
    vect->print = print_vector;

    return vect;
}

void append_to_vector(Vector *this, int value)
{
    if (this->length == this->capacity)
        increase_vector_capacity(this);

    this->elements[this->length++] = value;
}

int *create_heap_int_array(int capacity)
{
    return (int *) malloc(capacity * sizeof(int));
}

void increase_vector_capacity(Vector *this)
{
    this->capacity *= 4;
    this->elements = (int *) realloc(this->elements, this->capacity * sizeof(int));
}

void print_vector(Vector *this)
{
    for (int i = 0; i < this->length; ++i)
        printf("%d ", this->elements[i]);
    printf("\n");
}

void free_vector(Vector *vect)
{
    free(vect->elements);
    free(vect);
}
