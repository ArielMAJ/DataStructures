// Searching in a Array

#include<stdio.h>

// Defining the array data type:
typedef struct Array
{
	int A[10];
	int size;
	int length;
} Array;

void Display(Array arr);
void swap(int *x, int *y);
int LinearSearch(Array *arr, int key);


int main()
{
	// Starting an array of size 6 and max size 8.
	Array array={{2, 11, 12, 13, 7, 3}, 8, 6};

	// Doing linear search for value 7 and printing its position.
	printf("Position of 7 in the array: %d\n", LinearSearch(&array, 7)); // It's at position 4.

	// Printing the whole array to confirm.
	Display(array);

	printf("Position of 7 in the array: %d\n", LinearSearch(&array, 7)); // It's at position 3 now.
	Display(array); // Proof it keeps getting nearer the beginning.

	// This doesn't make much sense though.
	// I think it should return the new position instead of the old one.
	// If we try to access it using the position returned, it won't be there...
	return 0;
}

// Function for printing array datastructure.
void Display(Array arr)
{
	printf("Elements are\n");
	for(int i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
	printf("\n");
}

// Simple swapping alg. using temporary variable.
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(Array *arr, int key)
{
	for(int i = 0; i < arr->length; i++)
	{
		if(key == arr->A[i]) // If we find the item in the list
		{
			// Every time we do linear search for a value
			if (i > 0) // If the value isn't at the beginning of the list
				swap(&arr->A[i], &arr->A[i-1]); // We bring it one step nearer the beginning of the list.
			return i; // Return the position of the item
		}
	}
	return -1; // Returning a non valid position in case we don't find the item.
}