# C & C++ Basics

## Structures

- A collection (group) of similar (related) data items under a name;
- They are used for defining new (user defined) data types;
- To access a structure attribute you use:
    - "." ("dot") when accessing without using a pointer (eg. normal variable in created in stack; "var.value;");
    - "->" ("arrow") when accessing through a pointer (eg. created in heap; "p->value;");
    - "." if you enclose a pointer in round brackets (eg. "(\*p).value;").
- In C you need to use "typedef" to create new structs without using the word "struct". In C++ you can directly use the struct name and ommit the "struct" keyword.

## Pointers

Pointers store the address of some piece of data and serve as a way to indirectly access them.
It's mostly used to access things that are "external to the program".
The character "\*" should be used at the definition of a pointer variable and when accessing the value in the address the pointer points to.
Pointer all have the same size in bytes regardless of their data type.

Main uses are:
- Acessing heap (dinamically allocated memory -> eg. malloc/alloc);
- Acessing resources (eg. files in hard disk);
- Passing parameters.

## References

- References type variables don't exist in C;
- References, in C++, are just another name for a same variable: an alias;
- It is closely related to a pointer, but it isn't one;
- It can be used as an alternative to a pointer;
- A reference must be initialized at declaration time;
- They are mostly used as function parameters.

## Functions

...