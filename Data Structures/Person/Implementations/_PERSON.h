#ifndef PERSON_H
#define PERSON_H

#pragma once

#include <inttypes.h>

#define MyClass typedef struct

MyClass Person
{
    char *name;
    uint8_t age;
    uint8_t height;
    void (*data)(struct Person *);
    void (*age_range)(struct Person *);
} Person;

Person InitPerson(char *name, uint8_t age, uint8_t height);
Person * NewPerson(char *name, uint8_t age, uint8_t height);
void _Person_AssociatedFunctions(Person *person);
void ShowData(Person *self);
void AgeRange(Person *self);


#endif