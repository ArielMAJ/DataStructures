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

    printf("Size of Rectangle:\t%.2u\n", (unsigned) sizeof(rect0));
    printf("Size of R.width:\t%.2u\n", (unsigned) sizeof(rect0->width));
    printf("Size of R.height:\t%.2u\n", (unsigned) sizeof(rect0->height));
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

    printf("\nCard:\n");
    struct Card card = {1, 1, 0}; // Ace of spades;
    printCard(card);

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