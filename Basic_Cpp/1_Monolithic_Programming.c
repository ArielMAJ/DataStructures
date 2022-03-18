// #include <iostream> // C++
// using namespace std; // C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("cls");
	printf("******Monolithic Programming******\n\n");
	int rectangle_width=0, rectangle_length=0;
	
	printf("What's the rectangle width? ");
	scanf("%i", &rectangle_width); // 10
	// cin>>rectangle_width; // 10 // C++
	printf("What's the rectangle length? ");
	scanf("%i", &rectangle_length); // 10
	// cin>>rectangle_length; // 10 // C++
	

	int area = rectangle_width * rectangle_length; // 100
	int perimeter = 2 * (rectangle_length + rectangle_width); // 40

	// cout<<"The area of this rectangle is "<<area<<endl; // 100 // C++
	printf("The area of this rectangle is %i\n", area); // 100
	printf("The perimeter of this rectangle is %i\n", perimeter); // 40

	printf("\nType a new width: ");
	scanf("%i", &rectangle_width); // 20
	printf("Type a new length: ");
	scanf("%i", &rectangle_length); // 20

	area = rectangle_width * rectangle_length; // 400
	perimeter = 2 * (rectangle_length + rectangle_width); // 80
	printf("The area of this rectangle is %i\n", area); // 400
	printf("The perimeter of this rectangle is %i\n\n", perimeter); // 80
	
	return 0;
}