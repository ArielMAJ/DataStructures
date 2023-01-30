#include <stdio.h>
#include <stdlib.h>


typedef struct Vector
{
    int *elements;
    int length;
    int capacity;
    void (*append)(struct Vector *, int);
    void (*print_reversed)(struct Vector *);
} Vector;

int get_int();
int *create_heap_int_array(int capacity);

Vector *new_vector(int capacity);
void increase_vector_capacity(Vector *this);
void append_to_vector(Vector *this, int value);
void print_reversed_vector(Vector *this);
void free_vector(Vector *vect);

int minimal_steps_to_this_position(Vector *dynamic_programming_vect, int i);
int shortest_path_previous_position(Vector *vect, int number);
Vector *primitive_calculator(int value);

int main(void)
{
    int input_integer = get_int();

    Vector *vect = primitive_calculator(input_integer);

    printf("%d\n", vect->length - 1);
    vect->print_reversed(vect);

    free_vector(vect);
    return 0;
}

Vector *primitive_calculator(int value)
{
    Vector *dynamic_programming_vect = new_vector(value + 2);

    dynamic_programming_vect->append(dynamic_programming_vect, 0);
    for (int i = 1; i < value; ++i)
        dynamic_programming_vect->append(
            dynamic_programming_vect,
            minimal_steps_to_this_position(dynamic_programming_vect, i)
        );

    Vector *output_vect = new_vector(dynamic_programming_vect->elements[value] + 2);

    while (value >= 1)
    {
        output_vect->append(output_vect, value);
        value = shortest_path_previous_position(dynamic_programming_vect, value);
    }

    free_vector(dynamic_programming_vect);
    return output_vect;
}

int minimal_steps_to_this_position(Vector * dynamic_programming_vect, int i)
{
    int previous_position = shortest_path_previous_position(dynamic_programming_vect, i);
    int minimal_steps = dynamic_programming_vect->elements[previous_position] + 1;

    return minimal_steps;
}

int shortest_path_previous_position(Vector *vect, int number)
{
    if ( number % 3 == 0 && vect->elements[number / 3] <= vect->elements[number / 2])
        if (vect->elements[number / 3] < vect->elements[number - 1])
            return number / 3;
        else
            return number - 1;
    else if ( number % 2 == 0 && vect->elements[number / 2] <= vect->elements[number - 1])
        return number / 2;
    else
        return number - 1;
}

int get_int()
{
    int value;
    scanf("%d", &value);

    return value;
}

Vector *new_vector(int capacity)
{
    Vector *vect = (Vector *) malloc(sizeof(Vector));

    vect->elements = create_heap_int_array(capacity);
    vect->capacity = capacity;
    vect->length = 0;
    vect->append = append_to_vector;
    vect->print_reversed = print_reversed_vector;

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
    this->capacity *= 2;
    this->elements = (int *) realloc(this->elements, this->capacity * sizeof(int));
}

void print_reversed_vector(Vector *this)
{
    for (int i = this->length - 1; i > 0 ; --i)
        printf("%d ", this->elements[i]);
    printf("%d\n", this->elements[0]);
}

void free_vector(Vector *vect)
{
    free(vect->elements);
    free(vect);
}
