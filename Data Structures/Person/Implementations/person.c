#include "_PERSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowData(Person *self)
{
    printf("Name: %s, Age: %d years, Height: %d cm\n", self->name, self->age, self->height);
}

void AgeRange(Person *self)
{
    if (self->age >= 60)
        printf("%s is an elder person.\n", self->name);
    else if (self->age >= 21)
        printf("%s is an adult.\n", self->name);
    else if (self->age > 12)
        printf("%s is a teenager.\n", self->name);
    else
        printf("%s is a child.\n", self->name);

}

void _Person_AssociatedFunctions(Person *person)
{
    person->data = &ShowData;
    person->age_range = &AgeRange;
}
// Person * NewPerson(char *name, uint8_t age, uint8_t height)
Person InitPerson(char *name, uint8_t age, uint8_t height)
{
    // Person *person = (Person *) malloc(sizeof(Person));
    Person person = {
        (char *) malloc(strlen(name) + 1),
        age,
        height,
        &ShowData,
        &AgeRange
    };
    strncpy(person.name, name, strlen(name) + 1);

    return person;
}

Person * NewPerson(char *name, uint8_t age, uint8_t height)
{
    Person *person = (Person *) malloc(sizeof(Person));

    person->name = (char *) malloc(strlen(name) + 1);
    strncpy(person->name, name, strlen(name) + 1);


    person->age = age;
    person->height = height;

    _Person_AssociatedFunctions(person);

    return person;
}