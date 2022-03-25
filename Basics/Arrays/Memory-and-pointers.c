#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	int array[5] = {0}; // Array of zeros;
	printf("****** int array (4 bytes) ******\n\n");
	printf("array:\t\t\t%p\n", array);
	printf("&array[0]:\t\t%p\n", &array[0]);
	printf("array+1:\t\t%p\n", array+1);
	printf("&array[1]:\t\t%p\n", &array[1]);


	printf("\n(int)array:\t\t%d\n", (int)array);
	printf("(int)&array[0]:\t\t%d\n", (int)&array[0]);
	printf("(int)&array[1]:\t\t%d\n", (int)&array[1]);
	printf("(int)(array+1):\t\t%d\n", (int)(array+1));

	array[0] = 1;
	printf("\n\narray[0]:\t\t%d\n", array[0]);
	*array += 2;
	printf("array[0]:\t\t%d\n", array[0]);

	
	array[1] = 10;
	printf("\narray[1]:\t\t%d\n", array[1]);
	*(array + 1) += 20;
	printf("array[1]:\t\t%d\n", array[1]);
	printf("*(array + 1):\t\t%d\n", *(array + 1));


	int8_t array8[5] = {0};
	printf("\n\n\n****** 8bit (1byte) array ******\n\n");
	printf("array8:\t\t\t%p\n", array8);
	printf("&array8[0]:\t\t%p\n", &array8[0]);
	printf("array8+1:\t\t%p\n", array8+1);
	printf("&array8[1]:\t\t%p\n", &array8[1]);


	printf("\n(int)array8:\t\t%d\n", (int)array8);
	printf("(int)&array8[0]:\t%d\n", (int)&array8[0]);
	printf("(int)&array8[1]:\t%d\n", (int)&array8[1]);
	printf("(int)(array8+1):\t%d\n", (int)(array8+1));

	array8[0] = 1;
	printf("\n\narray8[0]:\t\t%d\n", array8[0]);
	*array8 += 2;
	printf("array8[0]:\t\t%d\n", array8[0]);

	
	array8[1] = 10;
	printf("\narray8[1]:\t\t%d\n", array8[1]);
	*(array8 + 1) += 20;
	printf("array8[1]:\t\t%d\n", array8[1]);
	printf("*(array8 + 1):\t\t%d\n", *(array8 + 1));

	return 0;
}