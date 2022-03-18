#include <stdio.h>
#include <stdlib.h>

int area(struct Rectangle rect);
int perimeter(struct Rectangle rect);
void setWidth(struct Rectangle *rect, int length);
void setLength(struct Rectangle *rect, int width);

struct Rectangle
{
	int length;
	int width;
};

int main(void)
{
	system("cls");
	printf("******Structures & Functions******\n\n");

	
	struct Rectangle rect = {0, 0};

	printf("What's the rectangle width? ");
	scanf("%i", &rect.width); // 10
	printf("What's the rectangle length? ");
	scanf("%i", &rect.length); // 10
	

	int rect_area = area(rect); // 100
	int rect_perimeter = perimeter(rect); // 40

	printf("The area of this rectangle is %i\n", rect_area); // 100
	printf("The perimeter of this rectangle is %i\n", rect_perimeter); // 40


	int width = 0, length = 0;
	printf("\nType a new width: ");
	scanf("%i", &width); // 20
	printf("Type a new length: ");
	scanf("%i", &length); // 20
	setWidth(&rect, width);
	setLength(&rect, length);

	rect_area = area(rect); // 400
	rect_perimeter = perimeter(rect); // 80
	printf("The area of this rectangle is %i\n", rect_area); // 400
	printf("The perimeter of this rectangle is %i\n\n", rect_perimeter); // 80
	return 0;
}

int area(struct Rectangle rect)
{
	int area;
	area = 0;

	for (int i=0; i<rect.width; i++)
		for (int j=0; j<rect.length; j++, area++); // Multiplying weird just for the sake of it.

	return area;
}

int perimeter(struct Rectangle rect)
{
	int perimeter;
	perimeter = 0;

	for (int i=0; i<2; i++) // Doing sums weird just for the sake of it.
	{
		for (int j=0; j<rect.length; j++, perimeter++);
		for (int j=0; j<rect.width; j++, perimeter++);
	}

	return perimeter;
}

void setLength(struct Rectangle *rect, int length)
{
	// Needs to use arrow to access struct's attributes
	// when they're passed in as a pointer:
	rect->length=length;
}

void setWidth(struct Rectangle *rect, int width)
{
	rect->width=width;
}