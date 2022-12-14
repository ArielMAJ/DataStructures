#include "./Implementations/_PERSON.h"
#include <string.h>

int main(void)
{
    char name[5] = "Luke";
    Person stack_person = InitPerson(name, 61, 175);
    stack_person.data(&stack_person);
    stack_person.age_range(&stack_person);

    strncpy(name, "Ringo", 5);
    Person * heap_person = NewPerson(name, 22, 165);
    heap_person->data(heap_person);
    heap_person->age_range(heap_person);

    return 0;
}