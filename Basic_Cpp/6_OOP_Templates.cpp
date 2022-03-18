#include <stdio.h>
#include <stdlib.h>

template <class T>
class Rectangle
{
private:
	T length;
	T width;
public:
	// Constructors:
	Rectangle(){} // Basic "clean" constructor.
	Rectangle(T length, T width); // "Complete" constructor.

	// Methods:
	T area();
	T perimeter();

	// Getters and setters:
	T getLength() { return length; }
	T getWidth() { return width; }
	void setLength(T length) { this->length=length; }
	void setWidth(T width) { this->width=width; }

	// Destructor:
	~Rectangle(){ printf("\n~A rectangle was destroyed just now.\n"); }
};

int main(void)
{
	system("cls");
	printf("******OOP Templates******\n\n");

	Rectangle<int> int_rect; // Default constructor.
	Rectangle<float> float_rect(0,0); // Using second constructor in which we can pass arguments.

	float width = 0, length = 0;
	
	// Int rectangle:
	{
		printf("What's the rectangle<int> width? ");
		scanf("%f", &width); // 10.11

		printf("What's the rectangle<int> length? ");
		scanf("%f", &length); // 10.11

		int_rect.setWidth((int)width); // Can only receive int, so we gotta typecast.
		int_rect.setLength((int)length); // Can only receive int, so we gotta typecast.


		int rect_area = int_rect.area(); // 100
		int rect_perimeter = int_rect.perimeter(); // 40
		printf("The area of this rectangle<int> is %i\n", rect_area); // 100
		printf("The perimeter of this rectangle<int> is %i\n", rect_perimeter); // 40
	}


	// Float rectangle:
	{
		printf("\nWhat's the rectangle<float> width? ");
		scanf("%f", &width); // 10.11

		printf("What's the rectangle<float> length? ");
		scanf("%f", &length); // 10.11

		float_rect.setWidth(width); // Can directly receive floats.
		float_rect.setLength(length); // Can directly receive floats.


		float rect_area = float_rect.area(); // 102.21
		float rect_perimeter = float_rect.perimeter(); // 40.44
		printf("The area of this rectangle is %.2f\n", rect_area); // 102.21
		printf("The perimeter of this rectangle is %.2f\n", rect_perimeter); // 40.44
	}
	return 0;
}

template <class T>
T Rectangle<T>::area(){ return (float)width*length; }

template <class T>
T Rectangle<T>::perimeter(){ return 2*((float)width+length); }

template <class T>
Rectangle<T>::Rectangle(T length, T width) // "Complete" constructor.
{
	// Needs to use arrow to access struct's attributes
	// using the "this" keyword to refer to the current object
	// (only when the argument has the same name as the property).
	this->length=length;
	this->width=width;
}
