#include <stdio.h>
#include <stdlib.h>

class Rectangle
{
private:
	int length;
	int width;
public:
	// Constructors:
	Rectangle(){} // Basic "clean" constructor.
	Rectangle(int length, int width); // "Complete" constructor.

	// Methods:
	int area();
	int perimeter();

	// Getters and setters:
	int getLength() { return length; }
	int getWidth() { return width; }
	void setLength(int length) { this->length=length; }
	void setWidth(int width) { this->width=width; }

	// Destructor:
	~Rectangle(){ printf("\n~A rectangle was destroyed just now.\n\n"); }
};

int main(void)
{
	system("cls");
	printf("******OOP Basics******\n\n");

	
	int width = 0, length = 0;
	// struct Rectangle rect = {0, 0}; // Only works if created as struct;

	printf("What's the rectangle width? ");
	scanf("%i", &width); // 10
	printf("What's the rectangle length? ");
	scanf("%i", &length); // 10
	Rectangle rect(width,length);

	int rect_area = rect.area(); // 100
	int rect_perimeter = rect.perimeter(); // 40

	printf("The area of this rectangle is %i\n", rect_area); // 100
	printf("The perimeter of this rectangle is %i\n", rect_perimeter); // 40


	printf("\nType a new width: ");
	scanf("%i", &width); // 20
	printf("Type a new length: ");
	scanf("%i", &length); // 20
	rect.setWidth(width);
	rect.setLength(length);

	rect_area = rect.area(); // 400
	rect_perimeter = rect.perimeter(); // 80
	printf("The area of this rectangle is %i\n", rect_area); // 400
	printf("The perimeter of this rectangle is %i\n", rect_perimeter); // 80
	return 0;
}

int Rectangle::area()
{
	int area;
	area = 0;

	for (int i=0; i<width; i++)
		for (int j=0; j<length; j++, area++); // Multiplying weird just for the sake of it.

	return area;
}

int Rectangle::perimeter()
{
	int perimeter;
	perimeter = 0;

	for (int i=0; i<2; i++) // Doing sums weird just for the sake of it.
	{
		for (int j=0; j<length; j++, perimeter++);
		for (int j=0; j<width; j++, perimeter++);
	}

	return perimeter;
}

Rectangle::Rectangle(int length, int width) // "Complete" constructor.
{
	// Needs to use arrow to access struct's attributes
	// using the "this" keyword to refer to the current object
	// (only when the argument has the same name as the property).
	this->length=length;
	this->width=width;
}
