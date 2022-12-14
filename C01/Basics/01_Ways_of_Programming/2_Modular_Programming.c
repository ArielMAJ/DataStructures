// #include <iostream> // C++
// using namespace std; // C++
#include <stdio.h>
#include <stdlib.h>

int area(int l, int w);
int perimeter(int l, int w);

int main(void)
{
	system("cls");
	printf("******Modular Programming******\n\n");

	int rectangle_width = 0, rectangle_length = 0;
	
	printf("What's the rectangle width? ");
	scanf("%i", &rectangle_width); // 10
	// cin>>rectangle_width; // 10 // C++

	printf("What's the rectangle length? ");
	scanf("%i", &rectangle_length); // 10
	// cin>>rectangle_length; // 10 // C++
	

	int rectangle_area = area(rectangle_length, rectangle_width); // 100
	int peri = perimeter(rectangle_length, rectangle_width); // 40

	// cout<<"\nThe area of this rectangle is "<<rectangle_area<<endl; // 100 // C++
	printf("The area of this rectangle is %i\n", rectangle_area); // 100
	printf("The perimeter of this rectangle is %i\n", peri); // 40


	printf("\nType a new width: ");
	scanf("%i", &rectangle_width); // 20
	printf("Type a new length: ");
	scanf("%i", &rectangle_length); // 20

	rectangle_area = area(rectangle_length, rectangle_width); // 400
	peri = perimeter(rectangle_length, rectangle_width); // 80
	printf("The area of this rectangle is %i\n", rectangle_area); // 400
	printf("The perimeter of this rectangle is %i\n\n", peri); // 80
	return 0;
}

int area(int l, int w)
{
	int area;
	area = 0;

	for (int i=0; i<w; i++)
		for (int j=0; j<l; j++, area++); // Multiplying weird just for the sake of it.

	return area;
}

int perimeter(int l, int w)
{
	int perimeter;
	perimeter = 0;

	for (int i=0; i<2; i++) // Doing sums weird just for the sake of it.
	{
		for (int j=0; j<l; j++, perimeter++);
		for (int j=0; j<w; j++, perimeter++);
	}

	return perimeter;
}