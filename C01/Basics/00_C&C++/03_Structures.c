// The next command should work both on Windows and WSL:
// gcc -Wall -Wextra -o a.exe ./03_Structures.c; ./a.exe; rm ./a.exe;
// The flag -Werror is also nice: it won't finish compiling upon finding errors.

#include <stdio.h>
#include <stdlib.h>
// #include <stdint.h>

// I didn't want to include <stdint.h>.
typedef unsigned char uint8_t;

// Adding typedef makes you able to not use the "struct" keyword when creating new structs;
typedef struct Rectangle
{
    int width;
    int height;
} Rectangle; // When you add typedef, you add the struct name here;

// Typedef isn't necessary. But then you'll need to use the keyword "struct" later on;
struct Card
{
    uint8_t face; // 1-13;
    uint8_t shape; // 0-3; clubs/spades/diamonds/hearts; ♣/♠/♦/♥;
    uint8_t color; // 0/1; black/red;
};

struct ExampleStruct
{
    char *value;
    char another_value;
} var1, var2; // You can create global "ExampleStruct" variables right after the struct definition;

void printHeapRectangle(Rectangle *rect);
void printRectangle(Rectangle rect);
void printCard(struct Card card);

int main(void)
{
    // Creating a structure.
    // Doing it with malloc as to remember how to use it.
    // Malloc requires that you specify the size of the malloc'ed space and
    // to cast the returned pointer to the correct type.
    Rectangle *rect0 = (Rectangle *) malloc(sizeof(Rectangle));

    printf("Size of Rectangle struct:\t%.2u\n", (unsigned) sizeof(Rectangle));
    printf("Size of (pointer to) Rectangle:\t%.2u\n", (unsigned) sizeof(rect0));
    printf("\t- Size of R.width:\t%.2u\n", (unsigned) sizeof(rect0->width));
    printf("\t- Size of R.height:\t%.2u\n", (unsigned) sizeof(rect0->height));
    printf("\nNon-initialized rect0:\n");
    printHeapRectangle(rect0);

    // Initializing values;
    rect0->width = 3;
    rect0->height = 5;
    printf("\nRect0:\n");
    printHeapRectangle(rect0);

    // Creating and initializing a structure directly.
    // Testing that you don't need to use "struct" here, but you can.
    struct Rectangle rect1 = {7, 8};
    printf("\nRect1:\n");
    printRectangle(rect1);

    // Sometimes a struct may use up more space than it needs because in some situations
    // it might be "easier" to use "N bytes" at a time. This is called padding.
    // If ExampleStruct only had the attribute "another_value" the struct as a whole use
    // up only sizeof(char) bytes instead.
    printf("\nSize of ExampleStruct:\t%.2u\n", (unsigned) sizeof(struct ExampleStruct));
    printf("Size of var1:\t%.2u\n", (unsigned) sizeof(var1));
    printf("\t- Size of var1.value:\t%.2u\n", (unsigned) sizeof(var1.value));
    printf("\t- Size of var1.another_value:\t%.2u\n", (unsigned) sizeof(var1.another_value));

    struct Card *test_card = (struct Card *) malloc(sizeof(struct Card));
    printf("\nSize of Card struct:\t\t%.2u\n", (unsigned) sizeof(struct Card));
    printf("Size of (pointer to) Card:\t%.2u\n", (unsigned) sizeof(rect0));

    printf("\nCard:\n");
    struct Card card = {1, 1, 0}; // Ace of spades;
    printCard(card);

    // Defining and initializing array of struct;
    struct Card deck[52] =
    {
        { 1, 0, 0},
        { 2, 0, 0},
        { 3, 0, 0},
        { 4, 0, 0},
        { 5, 0, 0},
        { 6, 0, 0},
        { 7, 0, 0},
        { 8, 0, 0},
        { 9, 0, 0},
        {10, 0, 0},
        {11, 0, 0},
        {12, 0, 0},
        {13, 0, 0},
        { 1, 1, 0},
        { 2, 1, 0},
        { 3, 1, 0},
        { 4, 1, 0},
        { 5, 1, 0},
        { 6, 1, 0},
        { 7, 1, 0},
        { 8, 1, 0},
        { 9, 1, 0},
        {10, 1, 0},
        {11, 1, 0},
        {12, 1, 0},
        {13, 1, 0},
        { 1, 2, 1},
        { 2, 2, 1},
        { 3, 2, 1},
        { 4, 2, 1},
        { 5, 2, 1},
        { 6, 2, 1},
        { 7, 2, 1},
        { 8, 2, 1},
        { 9, 2, 1},
        {10, 2, 1},
        {11, 2, 1},
        {12, 2, 1},
        {13, 2, 1},
        { 1, 3, 1},
        { 2, 3, 1},
        { 3, 3, 1},
        { 4, 3, 1},
        { 5, 3, 1},
        { 6, 3, 1},
        { 7, 3, 1},
        { 8, 3, 1},
        { 9, 3, 1},
        {10, 3, 1},
        {11, 3, 1},
        {12, 3, 1},
        {13, 3, 1},
    };

    printf("\nDeck card 0:\n");
    printCard(deck[0]);
    printf("Deck card 1:\n");
    printCard(deck[1]);
    printf("Deck card 2:\n");
    printCard(deck[2]);
    printf("Deck card 51:\n");
    printCard(deck[51]);


    // Remember to always free dinamically alloc'ed space.
    free(rect0);
    free(test_card);
    return 0;
}


void printRectangle(Rectangle rect)
{
    printf("\tWidth:\t%.2d\n", rect.width);
    printf("\tHeight:\t%.2d\n", rect.height);
}

void printHeapRectangle(Rectangle *rect)
{
    printf("\tWidth:\t%.2d\n", rect->width);
    printf("\tHeight:\t%.2d\n", rect->height);
}

void printCard(struct Card card)
{
    printf("\tFace:\t%.2d\n", card.face);
    printf("\tShape:\t%.2d\n", card.shape);
    printf("\tColor:\t%.2d\n", card.color);
}